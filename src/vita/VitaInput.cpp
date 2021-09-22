#include "vita/VitaInput.h"

namespace VitaInput
{
    bool leftScrollActive = false;
    bool rightScrollActive = false;
    bool upScrollActive = false;
    bool downScrollActive = false;

    void OpenController()
    {
        for (int i = 0; i < SDL_NumJoysticks(); ++i) {
            if (SDL_IsGameController(i)) {
                gameController = SDL_GameControllerOpen(i);
            }
        }
    }

    void CloseController()
    {
        if (SDL_GameControllerGetAttached(gameController)) {
            SDL_GameControllerClose(gameController);
            gameController = nullptr;
        }
    }

    void HandleTouchEvent(const SDL_TouchFingerEvent& event)
    {
        // ignore back touchpad
        if (event.touchId != 0)
            return;

        if (event.type == SDL_FINGERDOWN) {
            ++numTouches;
            if (numTouches == 1) {
                firstFingerId = event.fingerId;
            }
        } else if (event.type == SDL_FINGERUP) {
            --numTouches;
        }

        if (firstFingerId == event.fingerId) {
            emulatedPointerPosX =
                static_cast<float>(VITA_FULLSCREEN_WIDTH * event.x - 0) * (static_cast<float>(getRendererWidth()) / 960);
            emulatedPointerPosY = static_cast<float>(VITA_FULLSCREEN_HEIGHT * event.y - 0)
                                * (static_cast<float>(getRendererHeight()) / 544);

            if (emulatedPointerPosX < 0)
                emulatedPointerPosX = 0;
            else if (emulatedPointerPosX >= getRendererWidth())
                emulatedPointerPosX = getRendererWidth() - 1;

            if (emulatedPointerPosY < 0)
                emulatedPointerPosY = 0;
            else if (emulatedPointerPosY >= getRendererHeight())
                emulatedPointerPosY = getRendererHeight() - 1;

            SDL_Event ev;
            ev.type = SDL_MOUSEMOTION;
            ev.motion.x = emulatedPointerPosX;
            ev.motion.y = emulatedPointerPosY;
            SDL_PushEvent(&ev);

            if (event.type == SDL_FINGERDOWN || event.type == SDL_FINGERUP) {
                SDL_Event ev;
                ev.type = (event.type == SDL_FINGERDOWN) ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
                ev.button.button = SDL_BUTTON_LEFT;
                ev.button.x = emulatedPointerPosX;
                ev.button.y = emulatedPointerPosY;
                SDL_PushEvent(&ev);
            }
        }
    }

    void ProcessControllerAxisMotion()
    {
        const uint32_t currentTime = SDL_GetTicks();
        const double deltaTime = currentTime - lastControllerTime;
        lastControllerTime = currentTime;

        if (controllerLeftXAxis != 0 || controllerLeftYAxis != 0) {
            const int16_t xSign = (controllerLeftXAxis > 0) - (controllerLeftXAxis < 0);
            const int16_t ySign = (controllerLeftYAxis > 0) - (controllerLeftYAxis < 0);
            float resolutionSpeedMod = static_cast<float>(getRendererHeight()) / 480;

            emulatedPointerPosX += std::pow(std::abs(controllerLeftXAxis), CONTROLLER_AXIS_SPEEDUP) * xSign * deltaTime
                                * 10.0f / CONTROLLER_SPEED_MOD * resolutionSpeedMod * cursorSpeedup;
            emulatedPointerPosY += std::pow(std::abs(controllerLeftYAxis), CONTROLLER_AXIS_SPEEDUP) * ySign * deltaTime
                                * 10.0f / CONTROLLER_SPEED_MOD * resolutionSpeedMod * cursorSpeedup;

            if (emulatedPointerPosX < 0)
                emulatedPointerPosX = 0;
            else if (emulatedPointerPosX >= getRendererWidth())
                emulatedPointerPosX = getRendererWidth() - 1;

            if (emulatedPointerPosY < 0)
                emulatedPointerPosY = 0;
            else if (emulatedPointerPosY >= getRendererHeight())
                emulatedPointerPosY = getRendererHeight() - 1;

            SDL_Event ev;
            ev.type = SDL_MOUSEMOTION;
            ev.motion.x = emulatedPointerPosX;
            ev.motion.y = emulatedPointerPosY;
            SDL_PushEvent(&ev);
        }
    }

    void HandleControllerAxisEvent(const SDL_ControllerAxisEvent& motion)
    {
        if (motion.axis == SDL_CONTROLLER_AXIS_LEFTX) {
            if (std::abs(motion.value) > CONTROLLER_L_DEADZONE)
                controllerLeftXAxis = motion.value;
            else
                controllerLeftXAxis = 0;
        } else if (motion.axis == SDL_CONTROLLER_AXIS_LEFTY) {
            if (std::abs(motion.value) > CONTROLLER_L_DEADZONE)
                controllerLeftYAxis = motion.value;
            else
                controllerLeftYAxis = 0;
        } else if (motion.axis == SDL_CONTROLLER_AXIS_RIGHTX) {
            if (std::abs(motion.value) > CONTROLLER_R_DEADZONE)
                controllerRightXAxis = motion.value;
            else
                controllerRightXAxis = 0;
        } else if (motion.axis == SDL_CONTROLLER_AXIS_RIGHTY) {
            if (std::abs(motion.value) > CONTROLLER_R_DEADZONE)
                controllerRightYAxis = motion.value;
            else
                controllerRightYAxis = 0;
        }

        //map scroll
        if (controllerRightXAxis > CONTROLLER_R_DEADZONE)
        {
            if (!rightScrollActive)
            {
                rightScrollActive = true;
                SDL_Event ev;
                ev.type = SDL_KEYDOWN;
                ev.key.state = SDL_PRESSED;
                ev.key.keysym.mod = KMOD_NONE;
                ev.key.keysym.sym = SDLK_RIGHT;
                SDL_PushEvent(&ev);
            }
        }
        else if (rightScrollActive)
        {
            rightScrollActive = false;
            SDL_Event ev;
            ev.type = SDL_KEYUP;
            ev.key.state = SDL_RELEASED;
            ev.key.keysym.mod = KMOD_NONE;
            ev.key.keysym.sym = SDLK_RIGHT;
            SDL_PushEvent(&ev);
        }

        if (controllerRightXAxis < -CONTROLLER_R_DEADZONE)
        {
            if (!leftScrollActive)
            {
                leftScrollActive = true;
                SDL_Event ev;
                ev.type = SDL_KEYDOWN;
                ev.key.state = SDL_PRESSED;
                ev.key.keysym.mod = KMOD_NONE;
                ev.key.keysym.sym = SDLK_LEFT;
                SDL_PushEvent(&ev);
            }
        }
        else if (leftScrollActive)
        {
            leftScrollActive = false;
            SDL_Event ev;
            ev.type = SDL_KEYUP;
            ev.key.state = SDL_RELEASED;
            ev.key.keysym.mod = KMOD_NONE;
            ev.key.keysym.sym = SDLK_LEFT;
            SDL_PushEvent(&ev);
        }

        if (controllerRightYAxis > CONTROLLER_R_DEADZONE)
        {
            if (!upScrollActive)
            {
                upScrollActive = true;
                SDL_Event ev;
                ev.type = SDL_KEYDOWN;
                ev.key.state = SDL_PRESSED;
                ev.key.keysym.mod = KMOD_NONE;
                ev.key.keysym.sym = SDLK_DOWN;
                SDL_PushEvent(&ev);
            }
        }
        else if (upScrollActive)
        {
            upScrollActive = false;
            SDL_Event ev;
            ev.type = SDL_KEYUP;
            ev.key.state = SDL_RELEASED;
            ev.key.keysym.mod = KMOD_NONE;
            ev.key.keysym.sym = SDLK_DOWN;
            SDL_PushEvent(&ev);
        }

        if (controllerRightYAxis < -CONTROLLER_R_DEADZONE)
        {
            if (!downScrollActive)
            {
                downScrollActive = true;
                SDL_Event ev;
                ev.type = SDL_KEYDOWN;
                ev.key.state = SDL_PRESSED;
                ev.key.keysym.mod = KMOD_NONE;
                ev.key.keysym.sym = SDLK_UP;
                SDL_PushEvent(&ev);
            }
        }
        else if (downScrollActive)
        {
            downScrollActive = false;
            SDL_Event ev;
            ev.type = SDL_KEYUP;
            ev.key.state = SDL_RELEASED;
            ev.key.keysym.mod = KMOD_NONE;
            ev.key.keysym.sym = SDLK_UP;
            SDL_PushEvent(&ev);
        }
    }

    void HandleControllerButtonEvent(const SDL_ControllerButtonEvent& button)
    {
        bool keyboardPress = false;
        bool mousePress = false;
        Uint8 mouseBtn;
        SDL_Scancode scancode;
        SDL_Keycode keycode;

        switch (button.button) {
        case SDL_CONTROLLER_BUTTON_A:
            mousePress = true;
            mouseBtn = SDL_BUTTON_LEFT;
            break;
        case SDL_CONTROLLER_BUTTON_B:
            mousePress = true;
            mouseBtn = SDL_BUTTON_RIGHT;
            break;
        case SDL_CONTROLLER_BUTTON_X:
            keyboardPress = true;
            scancode = SDL_SCANCODE_A;
            keycode = SDLK_a;
            break;
        case SDL_CONTROLLER_BUTTON_Y:
            keyboardPress = true;
            scancode = SDL_SCANCODE_S;
            keycode = SDLK_s;
            break;
        case SDL_CONTROLLER_BUTTON_BACK:
            keyboardPress = true;
            scancode = SDL_SCANCODE_ESCAPE;
            keycode = SDLK_ESCAPE;
            break;
        case SDL_CONTROLLER_BUTTON_START:
            keyboardPress = true;
            scancode = SDL_SCANCODE_SPACE;
            keycode = SDLK_SPACE;
            break;
        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
            keyboardPress = true;
            scancode = SDL_SCANCODE_LCTRL;
            keycode = SDLK_LCTRL;

            if (button.type == SDL_CONTROLLERBUTTONDOWN)
                SDL_SetModState(KMOD_CTRL);
            else
                SDL_SetModState(KMOD_NONE);

            break;
        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
            keyboardPress = true;
            scancode = SDL_SCANCODE_RSHIFT;
            keycode = SDLK_RSHIFT;

            if (button.type == SDL_CONTROLLERBUTTONDOWN)
                SDL_SetModState(KMOD_SHIFT);
            else
                SDL_SetModState(KMOD_NONE);

            if (button.type == SDL_CONTROLLERBUTTONDOWN) {
                cursorSpeedup = 2.0f;
            } else {
                cursorSpeedup = 1.0f;
            }
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_UP:
            keyboardPress = true;
            scancode = SDL_SCANCODE_1;
            keycode = SDLK_1;
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
            keyboardPress = true;
            scancode = SDL_SCANCODE_2;
            keycode = SDLK_2;
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
            keyboardPress = true;
            scancode = SDL_SCANCODE_3;
            keycode = SDLK_3;
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
            keyboardPress = true;
            scancode = SDL_SCANCODE_4;
            keycode = SDLK_4;
            break;
        default:
            break;
        }

        if (keyboardPress) {
            SDL_Event ev;
            ev.type = (button.type == SDL_CONTROLLERBUTTONDOWN) ? SDL_KEYDOWN : SDL_KEYUP;
            ev.key.state = (button.type == SDL_CONTROLLERBUTTONDOWN) ? SDL_PRESSED : SDL_RELEASED;
            ev.key.keysym.mod = SDL_GetModState();
            ev.key.keysym.scancode = scancode;
            ev.key.keysym.sym = keycode;
            SDL_PushEvent(&ev);
        } else if (mousePress) {
            SDL_Event ev;
            ev.type = (button.type == SDL_CONTROLLERBUTTONDOWN) ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
            ev.button.button = mouseBtn;
            ev.button.x = emulatedPointerPosX;
            ev.button.y = emulatedPointerPosY;
            SDL_PushEvent(&ev);
        }
    }
}

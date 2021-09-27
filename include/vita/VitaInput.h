#pragma once

#include <SDL2/SDL.h>
#include <misc/DrawingRectHelper.h>

namespace VitaInput
{
    // used to convert user-friendly pointer speed values into more useable ones
    const double CONTROLLER_SPEED_MOD = 2000000.0;
    // bigger value correndsponds to faster pointer movement speed with bigger stick axis values
    const double CONTROLLER_AXIS_SPEEDUP = 1.03;

    enum
    {
        CONTROLLER_L_DEADZONE = 3000,
        CONTROLLER_R_DEADZONE = 6000,
        VITA_FULLSCREEN_WIDTH = 960,
        VITA_FULLSCREEN_HEIGHT = 544
    };

    static SDL_GameController* gameController = nullptr;
    static int16_t controllerLeftXAxis = 0;
    static int16_t controllerLeftYAxis = 0;
    static int16_t controllerRightXAxis = 0;
    static int16_t controllerRightYAxis = 0;
    static uint32_t lastControllerTime = 0;
    static float emulatedPointerPosX;
    static float emulatedPointerPosY;
    static SDL_FingerID firstFingerId = 0;
    static int16_t numTouches = 0;
    extern bool leftScrollActive;
    extern bool rightScrollActive;
    extern bool upScrollActive;
    extern bool downScrollActive;
    static float cursorSpeedup = 1.0f;

    void OpenController();
    void CloseController();
    bool DoInput(const SDL_Event event);
    void HandleTouchEvent(const SDL_TouchFingerEvent& event);
    void ProcessControllerAxisMotion();
    void HandleControllerAxisEvent(const SDL_ControllerAxisEvent& motion);
    void HandleControllerButtonEvent(const SDL_ControllerButtonEvent& button);
}

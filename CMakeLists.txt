cmake_minimum_required(VERSION 3.16)

project(dunelegacy VERSION 0.96.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_BUILD_TYPE)
    message(STATUS "CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE}")
    set(build_list ${CMAKE_BUILD_TYPE})
elseif(CMAKE_CONFIGURATION_TYPES)
    message(STATUS "CMAKE_CONFIGURATION_TYPES ${CMAKE_CONFIGURATION_TYPES}")
    set(build_list ${CMAKE_CONFIGURATION_TYPES})
endif()

if(VITA)
    add_definitions(-DVITA)
    add_definitions(-DDUNELEGACY_DATADIR="ux0:data/dunelegacy")
    set(VITA_FLAGS "-Og -g -mcpu=cortex-a9 -mfpu=neon -fno-lto -fno-optimize-sibling-calls")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${VITA_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${VITA_FLAGS}")
    set(VITA_LIBS "-lSDL2 -lfreetype -ljpeg -lpng -lwebp -lz -lvorbisfile -lvorbis -logg -lmikmod \
    -llibgpu_es4_ext_stub \
    -llibIMGEGL_stub \
    -llibGLESv1_CM_stub \
    -lSceIme_stub \
    -lSceSysmodule_stub \
    -lScePower_stub -lSceAudio_stub -lSceCtrl_stub -lSceHid_stub -lSceTouch_stub \
	-lSceDisplay_stub -lSceGxm_stub -lSceCommonDialog_stub -lFLAC -lmpg123 -lSceMotion_stub -lSceAppUtil_stub \
    -fno-builtin-memcpy -fno-builtin-memset -fno-builtin-memmove -fno-builtin-memcmp")
    SET(CMAKE_CXX_STANDARD_LIBRARIES "${VITA_LIBS}")
endif()

add_subdirectory(src)

message(STATUS "          CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
message(STATUS "        CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS " CMAKE_EXE_LINKER_FLAGS: ${CMAKE_EXE_LINKER_FLAGS}")

if(VITA)
    include("${CMAKE_SOURCE_DIR}/vita/vita.cmake")
endif()

include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Dune Legacy")
set(VITA_TITLEID  "DUNE00002")

set(EXECUTABLE_NAME dunelegacy)
set(VITA_VERSION "00.96")

set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d ATTRIBUTE2=12")
vita_create_self(${EXECUTABLE_NAME}.self src/${EXECUTABLE_NAME} UNSAFE)

vita_create_vpk(${EXECUTABLE_NAME}.vpk ${VITA_TITLEID} ${EXECUTABLE_NAME}.self
    VERSION ${VITA_VERSION}
    NAME ${VITA_APP_NAME}
    FILE ${CMAKE_SOURCE_DIR}/vita/sce_sys/icon0.png sce_sys/icon0.png
    FILE ${CMAKE_SOURCE_DIR}/vita/sce_sys/pic0.png sce_sys/pic0.png
    FILE ${CMAKE_SOURCE_DIR}/vita/sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
    FILE ${CMAKE_SOURCE_DIR}/vita/sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
    FILE ${CMAKE_SOURCE_DIR}/vita/sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
    FILE ${CMAKE_SOURCE_DIR}/vita/module/libGLESv1_CM.suprx module/libGLESv1_CM.suprx
    FILE ${CMAKE_SOURCE_DIR}/vita/module/libGLESv2.suprx module/libGLESv2.suprx
    FILE ${CMAKE_SOURCE_DIR}/vita/module/libgpu_es4_ext.suprx module/libgpu_es4_ext.suprx
    FILE ${CMAKE_SOURCE_DIR}/vita/module/libIMGEGL.suprx module/libIMGEGL.suprx
    FILE ${CMAKE_SOURCE_DIR}/vita/module/libpvrPSP2_WSEGL.suprx module/libpvrPSP2_WSEGL.suprx
)

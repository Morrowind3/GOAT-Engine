cmake_minimum_required(VERSION 3.20)
project(GOATEngine)

set(CMAKE_CXX_STANDARD 17)

#define libraries
set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/SDL2-2.0.16/include")
set(SDL2_LIB_DIR "${PROJECT_SOURCE_DIR}/lib/SDL2-2.0.16/lib/x86")
set(SDL2_TTF_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/SDL2_TTF-2.0.15/include")
set(SDL2_TTF_LIB_DIR "${PROJECT_SOURCE_DIR}/lib/SDL2_TTF-2.0.15/lib/x86")
set(SDL2_IMAGE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/SDL2_IMAGE-2.0.5/include")
set(SDL2_IMAGE_LIB_DIR "${PROJECT_SOURCE_DIR}/lib/SDL2_IMAGE-2.0.5/lib/x86")
set(SDL2_MIXER_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/include")
set(SDL2_MIXER_LIB_DIR "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/lib/x86")
set(BOX2D_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/BOX2D/include")
set(BOX2D_LIB_DIR "${PROJECT_SOURCE_DIR}/lib/BOX2D/lib")
set(SQLITE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/SQLite/include")
set(SQLITE_LIB_DIR "${PROJECT_SOURCE_DIR}/lib/SQLite/lib")

#enable libraries
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${BOX2D_INCLUDE_DIR} ${SQLITE_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR} ${SDL2_TTF_LIB_DIR} ${SDL2_IMAGE_LIB_DIR} ${SDL2_MIXER_LIB_DIR} ${BOX2D_LIB_DIR} ${SQLITE_LIB_DIR})

#create target
add_library(GOATEngine SHARED src/core/Engine.cpp src/core/Application.cpp src/core/Application.hpp src/core/Base.hpp src/core/System.hpp src/systems/RenderingSystem.cpp src/systems/RenderingSystem.hpp src/systems/apis/implementations/RendererImpl.cpp src/systems/apis/implementations/RendererImpl.hpp src/utils/Globals.cpp src/systems/apis/RendererApi.cpp src/systems/apis/RendererApi.hpp src/managers/SceneManager.cpp src/managers/SceneManager.hpp src/core/Scene.cpp src/core/Scene.hpp src/core/GameObject.cpp src/core/GameObject.hpp)

#assign libraries to target
target_link_libraries(GOATEngine PRIVATE SDL2main SDL2 SDL2_ttf SDL2_image SDL2_mixer box2d sqlite3)

#place all necessary in build folder
add_custom_command(TARGET GOATEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/../dlls
        $<TARGET_FILE_DIR:GOATEngine>)
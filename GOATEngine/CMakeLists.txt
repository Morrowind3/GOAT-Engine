cmake_minimum_required(VERSION 3.20)
project(GOATEngine)

set(CMAKE_CXX_STANDARD 17)

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

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${BOX2D_INCLUDE_DIR} ${SQLITE_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR} ${SDL2_TTF_LIB_DIR} ${SDL2_IMAGE_LIB_DIR} ${SDL2_MIXER_LIB_DIR} ${BOX2D_LIB_DIR} ${SQLITE_LIB_DIR})

add_library(GOATEngine SHARED Engine.cpp)

target_link_libraries(GOATEngine SDL2main SDL2 SDL2_ttf SDL2_image SDL2_mixer box2d sqlite3)

add_custom_command(TARGET GOATEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/SDL2-2.0.16/lib/x86/SDL2.dll"
        "${PROJECT_SOURCE_DIR}/lib/BOX2D/lib/box2d.lib"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_IMAGE-2.0.5/lib/x86/libjpeg-9.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_IMAGE-2.0.5/lib/x86/libpng16-16.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_IMAGE-2.0.5/lib/x86/libtiff-5.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_IMAGE-2.0.5/lib/x86/libwebp-7.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_IMAGE-2.0.5/lib/x86/SDL2_image.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_IMAGE-2.0.5/lib/x86/zlib1.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/lib/x86/libFLAC-8.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/lib/x86/libmodplug-1.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/lib/x86/libmpg123-0.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/lib/x86/libogg-0.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/lib/x86/libopus-0.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/lib/x86/libopusfile-0.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/lib/x86/libvorbis-0.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/lib/x86/libvorbisfile-3.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/lib/x86/SDL2_mixer.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_MIXER-2.0.4/lib/x86/SDL2_mixer.lib"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_TTF-2.0.15/lib/x86/libfreetype-6.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_TTF-2.0.15/lib/x86/SDL2_ttf.dll"
        "${PROJECT_SOURCE_DIR}/lib/SDL2_TTF-2.0.15/lib/x86/SDL2_ttf.lib"
        "${PROJECT_SOURCE_DIR}/lib/SQLite/lib/sqlite3.lib"
        $<TARGET_FILE_DIR:GOATEngine>)
cmake_minimum_required(VERSION 3.20)
project(MountEverestimate)

set(CMAKE_CXX_STANDARD 17)

set(GOATEngine_INCLUDE_DIR "../GOATEngine")
set(GOATEngine_LIB_DIR "../GOATEngine/cmake-build-debug")

include_directories(${GOATEngine_INCLUDE_DIR})
link_directories(${GOATEngine_LIB_DIR})

add_executable(MountEverestimate main.cpp src/Game.cpp src/Game.hpp)

target_link_libraries(MountEverestimate GOATEngine)

#place all necessary dlls and assets in build folder
add_custom_command(TARGET MountEverestimate POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/../dlls
        ${PROJECT_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:MountEverestimate>)
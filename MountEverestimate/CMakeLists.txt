cmake_minimum_required(VERSION 3.20)
project(MountEverestimate)

set(CMAKE_CXX_STANDARD 17)

set(GOATEngine_INCLUDE_DIR "../GOATEngine/engine-headers")
set(GOATEngine_LIB_DIR "../GOATEngine/cmake-build-debug")

include_directories(${GOATEngine_INCLUDE_DIR})
link_directories(${GOATEngine_LIB_DIR})

add_executable(MountEverestimate main.cpp)

target_link_libraries(MountEverestimate GOATEngine)

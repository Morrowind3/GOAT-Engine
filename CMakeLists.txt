cmake_minimum_required (VERSION 3.20)
project (mount_everestimate)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(tests)
#add_subdirectory(headers)

add_executable(mount_everestimate main.cpp)

target_link_libraries(mount_everestimate speuren_met_krul)

enable_testing()


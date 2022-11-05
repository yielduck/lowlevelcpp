cmake_minimum_required(VERSION 3.0)
project(test)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(camera/ camera/)

target_link_libraries(${PROJECT_NAME} PRIVATE camera)

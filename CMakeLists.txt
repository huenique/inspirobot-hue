project(inspirobot-hue CXX)
cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME} src/inspirobot.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Include Conan-generated file
conan_basic_setup(TARGETS) # Introduce Conan-generated targets

target_link_libraries(${PROJECT_NAME} CONAN_PKG::cpr)

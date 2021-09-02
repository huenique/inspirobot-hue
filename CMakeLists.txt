project(inspirobot-hue CXX)
cmake_minimum_required(VERSION 3.16)

set(
    SOURCES
    src/inspirobot.cpp
    src/inspirobot.hpp
    src/cli.hpp
)
add_executable(${PROJECT_NAME} ${SOURCES})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Include Conan-generated file
conan_basic_setup(TARGETS) # Introduce Conan-generated targets

target_link_libraries(${PROJECT_NAME} CONAN_PKG::cpr)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::nlohmann_json)

cmake_minimum_required(VERSION 3.21)
project(snakeGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(snakeGame main.cpp)
include_directories(images)
include_directories(fonts)

include_directories(headers c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(snakeGame ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()

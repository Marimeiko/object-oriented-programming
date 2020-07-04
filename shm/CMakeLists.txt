cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##-----------------G-test SCRIPT FROM CODERS SCHOOL----------------##
#Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                     ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                     EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

##-----------------G-test SCRIPT FROM CODERS SCHOOL----------------##

set(PROJECT_NAME SHM)

project(${PROJECT_NAME})
enable_testing()
add_definitions(-D Wall -Wextra -Werror -pedantic)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)

include_directories(${INCLUDE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

##Insert project source files here.##
set(SOURCES
    ${SOURCE_DIR}/island.cpp
    ${SOURCE_DIR}/cargo.cpp
    ${SOURCE_DIR}/coordinates.cpp
    ${SOURCE_DIR}/ship.cpp
    ${SOURCE_DIR}/map.cpp
    ${SOURCE_DIR}/player.cpp
    ${SOURCE_DIR}/time.cpp
    ${SOURCE_DIR}/fruit.cpp
    ${SOURCE_DIR}/item.cpp
    ${SOURCE_DIR}/game.cpp
)

add_library(${CMAKE_PROJECT_NAME}-lib STATIC ${SOURCES})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_DIR}/main.cpp)
add_executable(${CMAKE_PROJECT_NAME}-ut ${TEST_DIR}/test.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}-lib)
target_link_libraries(${CMAKE_PROJECT_NAME}-ut ${CMAKE_PROJECT_NAME}-lib gtest_main)
add_test(NAME shm_test COMMAND ${CMAKE_PROJECT_NAME}-ut)

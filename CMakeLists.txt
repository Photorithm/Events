set(BR_STAGING_PATH "/workspace/staging" CACHE STRING "SDK Path")

cmake_minimum_required(VERSION 3.0.2)
project(Events)
IF(CMAKE_CROSSCOMPILING)
    message(STATUS "Cross-compiling ON.")
ELSE()
    message(STATUS "Cross-compiling OFF.")
ENDIF()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE EVENTS_INCLUDE_FILES "Include/*.h")

install(FILES ${EVENTS_INCLUDE_FILES} DESTINATION ${BR_STAGING_PATH}/Events/Include)

include_directories("Include")

add_executable(ObjectDemo Demo/ObjectDemo.cpp)
add_executable(CommandDemo Demo/CommandDemo.cpp)
add_executable(AdvancedDemo Demo/AdvancedCommands.cpp)
add_executable(EventHandlers Demo/EventHandlerDemo.cpp)
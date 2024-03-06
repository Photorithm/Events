set(BR_SDK_PATH "/workspace/aarch64-buildroot-linux-gnu_sdk-buildroot" CACHE STRING "SDK Path")
set(BR_STAGING_PATH "/workspace/staging" CACHE STRING "SDK Path")
set(CMAKE_TOOLCHAIN_FILE "${BR_SDK_PATH}/share/buildroot/toolchainfile.cmake" CACHE FILEPATH "Toolchain file" FORCE)

cmake_minimum_required(VERSION 3.0.2)
project(Events)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE EVENTS_INCLUDE_FILES "Include/*.h")

install(FILES ${EVENTS_INCLUDE_FILES} DESTINATION ${BR_STAGING_PATH}/Events/Include)

include_directories("Include")

add_executable(ObjectDemo Demo/ObjectDemo.cpp)
add_executable(CommandDemo Demo/CommandDemo.cpp)
add_executable(AdvancedDemo Demo/AdvancedCommands.cpp)
add_executable(EventHandlers Demo/EventHandlerDemo.cpp)
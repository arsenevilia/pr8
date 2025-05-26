cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

set(USE_SHARED_LIB OFF CACHE BOOL "Build shared (ON) or static (OFF)")

include_directories(include)

file(GLOB LIB_SOURCES "src/*.cpp")

if(USE_SHARED_LIB)
    add_library(tictactoe SHARED ${LIB_SOURCES})
else()
    add_library(tictactoe STATIC ${LIB_SOURCES})
endif()

add_executable(main main/main.cpp)

target_link_libraries(main tictactoe)
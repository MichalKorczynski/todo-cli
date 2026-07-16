cmake_minimum_required(VERSION 3.16)

project(todo-cli)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(todo-cli
    src/main.cpp
    src/Task.hpp
    src/TodoList.cpp
    src/TodoList.hpp
    src/StorageManager.hpp
    src/StorageManager.cpp
)

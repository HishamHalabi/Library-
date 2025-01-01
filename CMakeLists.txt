cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryManagementSystem 
    src/Book.h
    src/User.h
    src/Transaction.h
    src/BookBST.h
    src/Library.h
    src/main.cpp
)

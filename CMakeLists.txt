cmake_minimum_required(VERSION 3.20)
project(autograd_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(autograd src/main.cpp
        src/Tokenizer.h
        src/token.h
        src/main_tokenizer.h
)


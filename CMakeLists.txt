cmake_minimum_required(VERSION 3.23)
project(minishell C)

set(CMAKE_C_STANDARD 11)

include_directories(.
        ./libft)

add_executable(minishell
        minishell.h
        builtin.c)

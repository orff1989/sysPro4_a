cmake_minimum_required(VERSION 3.22)
project(sysPro4_a)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sysPro4_a
        Ambassador.hpp
        Assassin.hpp
        Captain.hpp
        Contessa.hpp
        Demo.cpp
        doctest.h
        Duke.hpp
        Game.hpp
        Makefile
        Player.hpp
        Test.cpp
        TestCounter.cpp)

cmake_minimum_required(VERSION 3.21)
project(sysPro4_a)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sysPro4_a
        Ambassador.cpp
        Ambassador.hpp
        Assassin.cpp
        Assassin.hpp
        Captain.cpp
        Captain.hpp
        Contessa.cpp
        Contessa.hpp
        Demo.cpp
        doctest.h
        Duke.cpp
        Duke.hpp
        Game.cpp
        Game.hpp
        Player.cpp
        Player.hpp
        Test.cpp
        TestCounter.cpp)

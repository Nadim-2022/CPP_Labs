cmake_minimum_required(VERSION 3.26)
project(CPP_Labs)

set(CMAKE_CXX_STANDARD 11)

add_executable(CPP_Labs Simple_program.cpp
        eeprom.cpp
        eeprom.h
)
add_executable(CPP_Labs2 using_reference_parameter.cpp)
add_executable(CPP_Labs3 string_streams.cpp)
add_executable(CPP_Labs4 using_map_and_pair.cpp)
add_executable(CPP_Labs5 Composition.cpp )
add_executable(CPP_Labs6 Operator_overloading.cpp)
add_executable(CPP_Labs7 function_objects.cpp function_objects.h)
add_executable(CPP_Labs8 Inheritance.cpp)
add_executable(CPP_Labs9 Abstract_class.cpp)
add_executable(CPP_Labs10 Observer_pattern.cpp)
add_executable(CPP_Labs11 Smart_pointers_and_containers.cpp)
add_executable(CPP_Labs13 new.cpp)
add_executable(CPP_Labs20 extraextra.cpp)
add_executable(CPP_Labs30 lab11.cpp)

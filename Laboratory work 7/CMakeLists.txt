cmake_minimum_required(VERSION 3.22)



set(PROJECT_NAME test)
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")

add_executable("${PROJECT_NAME}" Lab6Var5Complete.cpp
                    inc/Lab6Var5Functions.hpp
					
					src/Lab6Var5Functions.cpp
)
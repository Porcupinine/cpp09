cmake_minimum_required(VERSION 3.29)
project(cpp09)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(ex00
		ex00/src/BitcoinExchange.cpp
		ex00/inc/BitcoinExchange.h
		ex00/src/main.cpp
		ex00/src/Date.cpp
		ex00/inc/Date.h
)

add_executable(ex01
		ex01/main.cpp
		ex01/RPN.cpp
		ex01/RPN.h)

add_executable(ex02
		ex02/src/PmergeMe.cpp
		ex02/inc/PmergeMe.h
		ex02/src/main.cpp
		ex02/src/PmergeMeList.cpp
		ex02/src/PmergeMeVector.cpp
)

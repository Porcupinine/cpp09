cmake_minimum_required(VERSION 3.29)
project(cpp09)

set(CMAKE_CXX_STANDARD 20)

add_executable(ex00
		ex00/BitcoinExchange.cpp
		ex00/BitcoinExchange.h
		ex00/main.cpp
		ex00/Date.cpp
		ex00/Date.h
)

add_executable(ex01
		ex01/main.cpp
		ex01/RPN.cpp
		ex01/RPN.h)

add_executable(ex02
		ex02/PmergeMe.cpp
		ex02/PmergeMe.h
		ex02/main.cpp
		ex02/PmergeMeList.cpp
		ex02/PmergeMeVector.cpp
)

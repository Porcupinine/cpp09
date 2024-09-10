/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 15:34:46 by laura         #+#    #+#                 */
/*   Updated: 2024/09/04 15:34:46 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"
#include <iostream>
#include <algorithm>

PmergeMe::PmergeMe(int argc, char **data) {
	try {
		m_parseTime = funcTime([&]() { parseData(argc, data); });
		std::cout<<"Parsing time is: "<<m_parseTime<<" nanoseconds\n";
	}
	catch (std::exception &ex) {
		std::cout<<"Error: "<<ex.what();
	}
}

void PmergeMe::parseData(int argc, char **data){
	for(size_t it = 1; it < argc; it++) {
		std::string value = data[it];
		if(value.front() == '-') {
			throw std::invalid_argument("Read the subject, we only work with positive integers\n");
		}
		if(value.front() == '+'){
			value.erase(0,1);
		}
		if(!std::all_of(value.begin(), value.end(), [](unsigned char c){ return std::isdigit(c); })){
			throw std::invalid_argument("Read the subject, we only take integers\n");
		}
		int x = std::stoi(data[it]);
		m_list.push_back(x);
		m_vector.push_back(x);
	}
}

void PmergeMe::sortList() {

}

void PmergeMe::sortVector() {

}


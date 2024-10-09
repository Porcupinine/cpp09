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
		m_parseListTime = funcTime([&]() { parseData(argc, data, m_pairList ); });
		std::cout<<"Parsing list time is: "<<m_parseListTime<<" nanoseconds\n";
	}
	catch (std::exception &ex) {
		std::cerr<<"Error: "<<ex.what();
	}
	try {
		m_parseVecTime = funcTime([&]() { parseData(argc, data, m_pairVector ); });
		std::cout<<"Parsing vector time is: "<<m_parseVecTime<<" nanoseconds\n";
	}
	catch (std::exception &ex) {
		std::cerr<<"Error: "<<ex.what();
	}
	m_listTime = funcTime([&](){sortList();});
	m_vectorTime = funcTime([&](){sortVector();});
}

void PmergeMe::fillJacobVector() {
	for(int x = 3; x < m_pairVector.size()*2+3; x++){
		m_jacobVec.push_back(getJacob(x));
	}
}

void PmergeMe::fillInsertVec() {
	int lastJ = 0;
	int lastR = 0;
//	m_insertOrder.push_back(3);
	for(auto & x : m_jacobVec) {
		m_insertOrder.push_back(x);
		lastR = x -1;
		while (lastR > lastJ){
			if(lastR != x && lastR != 1)
				m_insertOrder.push_back(lastR);
			lastR--;
		}
		lastJ = x;
	}
}


int PmergeMe::getJacob(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return getJacob(n - 1) + 2 * getJacob(n - 2);
}

template<typename T>
void PmergeMe::parseData(int argc, char **data, T& container){
	for(size_t it = 1; it < argc; it += 2) {
		std::string first = data[it];
		if(first.front() == '-') {
			throw std::invalid_argument("Read the subject, we only work with positive integers\n");
		}
		if(first.front() == '+'){
			first.erase(0, 1);
		}
		if(!std::all_of(first.begin(), first.end(), [](unsigned char c){ return std::isdigit(c); })){
			throw std::invalid_argument("Read the subject, we only take integers\n");
		}
		int x = std::stoi(data[it]);
		std::pair<int, std::optional<int>> contPair;
		if (it + 1 != argc) {
			std::string second = data[it+1];
			if(second.front() == '-') {
				throw std::invalid_argument("Read the subject, we only work with positive integers\n");
			}
			if(second.front() == '+'){
				second.erase(0, 1);
			}
			if(!std::all_of(second.begin(), second.end(), [](unsigned char c){ return std::isdigit(c); })){
				throw std::invalid_argument("Read the subject, we only take integers\n");
			}
			int y = std::stoi(data[it + 1]);
			contPair = std::make_pair(x, y);
		} else {
			contPair = std::make_pair(x, std::nullopt);
		}
		container.push_back(contPair);
	}
}

/**
 * sort inside the pairs, sort pair by their heads, firsts are main chain and seconds are apend chain
 *
 */

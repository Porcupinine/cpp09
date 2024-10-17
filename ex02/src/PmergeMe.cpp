/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 15:34:46 by laura         #+#    #+#                 */
/*   Updated: 2024/10/15 15:23:59 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.h"
#include <iostream>
#include <algorithm>

PmergeMe::PmergeMe(int argc, char **data) {
	try {
		m_listTime = funcTime([&]() { parseData(argc, data, m_pairList ); });
//		std::cout<<"Parsing list time is: "<<m_parseListTime<<" nanoseconds\n";
	}
	catch (std::exception &ex) {
		std::cerr<<"Error: "<<ex.what();
	}
	try {
		m_vectorTime = funcTime([&]() { parseData(argc, data, m_pairVector ); });
//		std::cout<<"Parsing vector time is: "<<m_parseVecTime<<" nanoseconds\n";
	}
	catch (std::exception &ex) {
		std::cerr<<"Error: "<<ex.what();
	}
	m_insertVecTime = funcTime([&](){fillInsertVec();});
	m_listTime = funcTime([&](){sortList();}) + m_insertVecTime;
	m_vectorTime = funcTime([&](){sortVector();}) + m_insertVecTime;
	std::cout<<"After: ";
	for(auto &x : m_vector){
		std::cout<<x<<" ";
	}
	std::cout<<"\n";
	std::cout<<"List time: "<<m_listTime<<" μs\n";
	std::cout<<"Vector time: "<<m_vectorTime<<" μs\n";
	if (!std::is_sorted(m_list.begin(), m_list.end())) {
		std::cout << "Sorting for vector failed\n";
	}
	if (!std::is_sorted(m_vector.begin(), m_vector.end())) {
		std::cout << "Sorting for vector failed\n";
	}
}

void PmergeMe::fillJacobVector() {
	int max = (m_pairVector.size()*2)+3;
	auto cache = std::vector<std::optional<int>>(max);
	cache[0] = 0;
	cache[1] = 1;
	cache[2] = 1;
	cache[3] = 3;
	for( auto i = 3; i < max; ++i) {
		auto jacob = getJacob(i, cache);
		m_jacobVec.push_back(jacob);
		if (jacob > max) {
			break;
		}
	}
}

void PmergeMe::fillInsertVec() {
	fillJacobVector();
	int lastJ = 0;
	int lastR = 0;
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


int PmergeMe::getJacob(int n, std::vector<std::optional<int>>& cache) {
		auto jacob = cache.at(n);
		if (jacob.has_value()) {
			return jacob.value();
		}
		cache[n - 2] = getJacob(n - 2, cache);
		cache[n - 1] = getJacob(n - 1, cache);
		cache[n] = cache[n-1].value() + (2 + cache[n - 1].value());
		return cache[n].value();
}

void PmergeMe::removeDuplicates(int argc, char **argv) {
	for (auto it = 1; it < argc; it++){
		if (std::find(m_data.begin(), m_data.end(), argv[it]) == m_data.end())
			m_data.emplace_back(argv[it]);
	}
}

template<typename T>
void PmergeMe::parseData(int argc, char **data, T& container){
	removeDuplicates(argc, data);
	for(auto it = 0; it < m_data.size(); it += 2) {
		std::string first = m_data[it];
		if(first.front() == '-') {
			throw std::invalid_argument("Read the subject, we only work with positive integers\n");
		}
		if(first.front() == '+'){
			first.erase(0, 1);
		}
		if(!std::all_of(first.begin(), first.end(), [](unsigned char c){ return std::isdigit(c); })){
			throw std::invalid_argument("Read the subject, we only take integers\n");
		}
		int x = std::stoi(m_data[it]);
		std::pair<int, std::optional<int>> contPair;
		if (it + 1 < m_data.size()) {
			std::string second = m_data[it+1];
			if(second.front() == '-') {
				throw std::invalid_argument("Read the subject, we only work with positive integers\n");
			}
			if(second.front() == '+'){
				second.erase(0, 1);
			}
			if(!std::all_of(second.begin(), second.end(), [](unsigned char c){ return std::isdigit(c); })){
				throw std::invalid_argument("Read the subject, we only take integers\n");
			}
			int y = std::stoi(m_data[it + 1]);
			contPair = std::make_pair(x, y);
		} else {
			contPair = std::make_pair(x, std::nullopt);
		}
		container.push_back(contPair);
	}
}

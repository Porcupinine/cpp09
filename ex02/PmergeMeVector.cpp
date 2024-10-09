/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMeVector.cpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/27 09:05:42 by laura         #+#    #+#                 */
/*   Updated: 2024/09/27 09:05:42 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.h"

//using vecPair = std::vector<std::pair<int, std::optional<int>>>;

void PmergeMe::sortVecInPairs(){
	for (auto & ve : m_pairVector) {
		if (*(ve.second) && ve.second > ve.first) {
			std::swap(ve.first, *(ve.second));
		}
	}
}

void PmergeMe::printVecPairs(){
	for (auto & item : m_pairVector) {
		std::cout<<"("<<item.first<<", "<<*(item.second)<<") ";
	}
}

void PmergeMe::mergeVec(int start, int mid, int end) {
	int i, j, k;
	int n1 = mid - start + 1;
	int n2 = end - mid;

	vecPair leftVec(m_pairVector.begin() + start, m_pairVector.begin() + mid + 1);
	vecPair rightVec(m_pairVector.begin() + mid + 1, m_pairVector.begin() + end + 1);

	i = 0;
	j = 0;
	k = start;
	while (i < n1 && j < n2) {
		if (leftVec[i] <= rightVec[j]) {
			m_pairVector[k] = leftVec[i];
			i++;
		} else {
			m_pairVector[k] = rightVec[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		m_pairVector[k] = leftVec[i];
		i++;
		k++;
	}
	while (j < n2) {
		m_pairVector[k] = rightVec[j];
		j++;
		k++;
	}
}

void PmergeMe::mergeSortVec(int start, int end) {
	if (start < end) {
		int mid = start + (end - start) / 2;
		mergeSortVec(start, mid);
		mergeSortVec(mid + 1, end);
		mergeVec(start, mid, end);
	}
}

void PmergeMe::feedMainVecChain() {
	if (m_pairVector.front().second.has_value()) {
		m_vector.push_back(m_pairVector.front().second.value());
	}	for (auto & x : m_pairVector) {
		m_vector.push_back(x.first);
	}
//	m_pairVector.erase(m_pairVector.begin());
}

void PmergeMe::insertAppendVecChain() {
	for (auto &x : m_insertOrder) {
		int y = x - 1;
		if (y < m_pairVector.size()){
			if (m_pairVector[y].second.has_value()) {
				int tmp = m_pairVector[y].second.value();
				auto pos = binarySearchVec(tmp);
				m_vector.insert(pos, tmp);
			}
		}
	}
}

std::vector<int>::iterator PmergeMe::binarySearchVec(int target) {
	auto low = m_vector.begin();
	auto high = m_vector.end();

	// Perform binary search
	while (low < high) {
		auto mid = low + std::distance(low, high) / 2;

		// Compare the first element of the pair with the target
		if (*mid < target) {
			low = mid + 1;  // Move to the right half
		} else {
			high = mid;     // Move to the left half or stay at mid
		}
	}
	// Return the iterator where target should be inserted (or found)
	return low;
}

void PmergeMe::sortVector() {
	fillJacobVector();
	fillInsertVec();
	std::cout<<"vector before: ";
	printVecPairs();
	std::cout<<"\n";
	sortVecInPairs();
	mergeSortVec(0, m_pairVector.size()-1);
	std::cout<<"vector after: ";
	printVecPairs();
	std::cout<<"\n";
	feedMainVecChain();
	insertAppendVecChain();
	std::cout<<"sorted vector: ";
	for(auto &x : m_vector){
		std::cout<<x<<", ";
	}
	std::cout<<"\n";
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMeVector.cpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/27 09:05:42 by laura         #+#    #+#                 */
/*   Updated: 2024/10/15 14:16:23 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include "../inc/PmergeMe.h"

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
}

void PmergeMe::insertAppendVecChain() {
	for (auto &x : m_insertOrder) {
		size_t y = x - 1;
		if (y < m_pairVector.size()){
			if (m_pairVector[y].second.has_value()) {
				int tmp = m_pairVector[y].second.value();
//				auto pos = binarySearchVec(tmp);
				auto pos = std::lower_bound(m_vector.begin(), m_vector.end(), tmp);
				m_vector.insert(pos, tmp);
			}
		}
	}
}

void PmergeMe::sortVector() {
	sortVecInPairs();
	mergeSortVec(0, m_pairVector.size()-1);
	feedMainVecChain();
	insertAppendVecChain();
	if (!std::is_sorted(m_vector.begin(), m_vector.end())) {
		std::cout << "Sorting for vector failed\n";
	}
}




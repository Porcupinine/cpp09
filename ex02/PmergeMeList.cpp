/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMeList.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/27 09:05:23 by laura         #+#    #+#                 */
/*   Updated: 2024/09/27 09:05:23 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.h"


void PmergeMe::sortListInPairs() {
	for (auto & li : m_pairList) {
		if (*(li.second) && li.second > li.first) {
			std::swap(li.first, *(li.second));
		}
	}
}

void PmergeMe::printListPairs() {
	for (auto & item : m_pairList) {
		std::cout<<"("<<item.first<<", "<<*(item.second)<<") ";
	}
}

void PmergeMe::feedMainListChain() {
	if (m_pairList.front().second.has_value()) {
		m_list.push_back(m_pairList.front().second.value());
	}	for (auto & x : m_pairList) {
		m_list.push_back(x.first);
	}
}

lisPair PmergeMe::mergeList(lisPair& left, lisPair& right) {
	lisPair l;
	auto itLeft = left.begin();
	auto itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end()) {
		if (*itLeft <= *itRight) {
			l.push_back(*itLeft);
			++itLeft;
		} else {
			l.push_back(*itRight);
			++itRight;
		}
	}
	while (itLeft != left.end()) {
		l.push_back(*itLeft);
		++itLeft;
	}
	while (itRight != right.end()) {
		l.push_back(*itRight);
		++itRight;
	}
	return l;
}

void PmergeMe::mergeSortList(lisPair& lis) {
	if (lis.size() <= 1)
		return ;

	lisPair left, right;
	auto it = lis.begin();
	std::advance(it, lis.size() / 2);
	left.splice(left.begin(), lis, lis.begin(), it);
	right.splice(right.begin(), lis, lis.begin(), lis.end());
	mergeSortList(left);
	mergeSortList(right);
	lis = mergeList(left, right);
}

void PmergeMe::insertAppendListChain() {
	for (const auto& x : m_insertOrder) {
		int y = x - 1;
		auto it = m_pairList.begin();
		std::advance(it, y);
		if (y< m_pairList.size() && it != m_pairList.end() && it->second.has_value()) {
			int tmp = it->second.value();
			auto pos = std::lower_bound(m_list.begin(), m_list.end(),tmp);
			m_list.insert(pos, tmp);
		}
	}
}

void PmergeMe::sortList() {
	std::cout<<"list before: ";
	printListPairs();
	std::cout<<"\n";
	sortListInPairs();
	mergeSortList(m_pairList);
	std::cout<<"list after: ";
	printListPairs();
	feedMainListChain();
	insertAppendListChain();
	std::cout<<"\n";
	std::cout<<"sorted list: ";
	for(auto &x : m_list){
		std::cout<<x<<", ";
	}
	std::cout<<"\n";

}


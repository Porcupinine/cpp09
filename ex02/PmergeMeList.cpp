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

namespace {

	using lisPair = std::list<std::pair<int, std::optional<int>>>&;

	void sortInPairs(lisPair lis){
		for (auto & li : lis) {
			if (*(li.second) && li.second > li.first) {
				std::swap(li.first, *(li.second));
			}
		}
	}
	void sortPairs(lisPair lis) {

	}
	void printPairs(lisPair lis){
		for (auto & item : lis) {
			std::cout<<"("<<item.first<<", "<<*(item.second)<<") ";
		}
	}
}

void PmergeMe::sortList() {
	std::cout<<"list before: ";
	printPairs(m_pairList);
	std::cout<<"\n";
	sortInPairs(m_pairList);
	m_pairList.sort();
	std::cout<<"list after: ";
	printPairs(m_pairList);
	std::cout<<"\n";

}


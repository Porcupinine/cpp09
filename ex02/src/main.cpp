/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 15:32:54 by laura         #+#    #+#                 */
/*   Updated: 2024/10/15 14:12:01 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/PmergeMe.h"

int main (int argc, char** argv) {
	if (argc < 2) {
	std::cerr<<"Wrong amount of arguments\n";
	return 1;
	}
	std::cout<<"Before: ";
	for (auto it = 1; it < argc; it++) {
		std::cout<<argv[it]<<" ";
	}
	std::cout<<"\n";
	PmergeMe p1 = PmergeMe(argc, argv);
	return 0;
}

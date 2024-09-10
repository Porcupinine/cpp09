/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 15:32:54 by laura         #+#    #+#                 */
/*   Updated: 2024/09/04 15:32:54 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.h"

int main (int argc, char** argv) {
	if (argc < 2) {
	std::cerr<<"Wrong amount of arguments\n";
	return 1;
	}
	PmergeMe p1 = PmergeMe(argc, argv);
	std::cout<<"Parsed\n";
	return 0;
}

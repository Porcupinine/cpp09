/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/22 17:14:39 by laura         #+#    #+#                 */
/*   Updated: 2024/08/22 17:14:39 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.h"

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cerr<<"Wrong amount of arguments\n";
		return 1;
	}
	BitcoinExchange b1("/sam/Codam/cpp09/ex00/data.csv");
	b1.convert(argv[1]);
	return 0;
}

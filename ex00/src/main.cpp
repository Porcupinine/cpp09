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
#include "../inc/BitcoinExchange.h"

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cerr<<"Wrong amount of arguments\n";
		return 1;
	}
//	Date d1("2024-01-01");
//	Date d2("2023-12-31");
//	std::cout << std::boolalpha<< (d1 < d2) << "\n"; // Should output false
//	std::cout << std::boolalpha<< (d2 < d1) << "\n"; // Should output true

	BitcoinExchange b1("./data.csv");
	b1.convert(argv[1]);
	return 0;
}

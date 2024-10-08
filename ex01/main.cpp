/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/25 14:51:23 by laura         #+#    #+#                 */
/*   Updated: 2024/08/25 14:51:23 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>
#include "RPN.h"

int main (int argc, char** argv){
	if (argc != 2){
		std::cerr<<"Wrong amount of arguments\n";
		return 1;
	}
	std::string arguments = argv[1];
	try {
		RPN x = RPN(arguments);
	}
	catch (std::exception &ex) {
		std::cerr<<"Error: "<<ex.what();
		return 1;
	}
	return 0;
}

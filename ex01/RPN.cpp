/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/25 14:41:36 by laura         #+#    #+#                 */
/*   Updated: 2024/08/25 14:41:36 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "RPN.h"

RPN::RPN(const std::string& math) {
	std::stringstream ss(math);
	std::string token;
	std::string operators("*/-+");
	while(ss >> token) {
		size_t pos = operators.find(token);
		if(token.length() > 1) {
			throw std::invalid_argument("Invalid syntax\n");
		}
		else if(std::isdigit(token[0])) {
			try {
				m_stack.push(std::stof(token));
			}
			catch (std::exception &ex) {
				std::cerr<<"Error: "<<ex.what()<<"\n";
			}
		}
		else if(pos != std::string::npos && m_stack.size() >= 2){
			float x = m_stack.top();
			m_stack.pop();
			float y = m_stack.top();
			m_stack.pop();
			switch (token.at(0)) {
				case '+':
					m_result = y + x;
					break;
				case '-':
					m_result = y - x;
					break;
				case '*':
					m_result = y * x;
					break;
				case '/':
					if(x == 0)
						throw std::invalid_argument("Can't divide by 0\n");
					m_result = y / x;
					break;
			}
			m_stack.push(m_result);
		} else
			throw std::invalid_argument("Invalid value!\n");
	}
	std::cout<<"Result: "<<m_result<<"\n";
}

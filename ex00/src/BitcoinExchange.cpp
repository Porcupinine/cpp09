/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/22 17:22:28 by laura         #+#    #+#                 */
/*   Updated: 2024/08/22 17:22:28 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <algorithm>
#include "../inc/BitcoinExchange.h"

namespace {
	bool isFloat(const std::string& str) {
		std::string strCopy = str;
		if (std::all_of(strCopy.begin(), strCopy.end(), ::isdigit))
			return true;
		int f = 0;
		int e = 0;
		int dot = 0;
		int signal = 0;
		for (int it = static_cast<int>(strCopy.length()); it >= 0; it--){
			if (strCopy[it] == 'f') {
				f++;
				strCopy[it] = '0';
			}
			if(strCopy[it] == 'e') {
				e++;
				strCopy[it] = '0';
			}
			if(strCopy[it] == '.') {
				dot++;
				strCopy[it] = '0';
			}
			if (strCopy[it] == '-' || strCopy[it] == '+') {
				signal++;
				strCopy[it] = '0';
			}
		}
		if (f <= 1 && dot <= 2 && e <= 1 && signal <= 2) {
			return true;
		}
		return false;
	}
}

BitcoinExchange::BitcoinExchange(const std::string& csvFile) {
	parseData(csvFile);
}

void BitcoinExchange::convert(const std::string& inputFile) {
	std::ifstream infile(inputFile);
	if(!infile.is_open()){
		throw std::invalid_argument("Can't open inputFile\n");
	}
	std::string line;
	std::getline(infile, line);
	while(std::getline(infile, line)){
		std::string date = line.substr(0, 10);
		try {
			if(line.length() < 13){
				std::cout<<"Invalid input line\n";
				continue;
			}
			Date parsedDate(date);
			std::string value = line.substr(12, line.length() - 12); //check if valid aka only digits and . or e
			if (!isFloat(value)){
				std::cout<<"Invalid value\n";
				continue;
			}
			float floatValue = 0;
			floatValue = std::stof(value);
			if (floatValue < 0 || floatValue > 1000) {
				std::cout<< "Invalid operation, " <<floatValue <<" is not between 0 and 1000\n";
				continue;
			}
			auto it = m_csvData.lower_bound(parsedDate);
			if(it == m_csvData.end() || it->first != parsedDate) {
				if (it == m_csvData.begin() && it->first != parsedDate){
					std::cout<<"Invalid date\n";
					continue;
				}
				it--;
			}
			std::cout<<parsedDate<<" => "<< floatValue * it->second<<"\n";
		}
		catch (std::exception &ex) {
			std::cout<<"Error: "<<date<<" -> "<<ex.what()<<"\n";
		}
	}
}

void BitcoinExchange::parseData(const std::string& fileName) {
	std::ifstream infile(fileName);
	if(!infile.is_open()) {
		throw std::invalid_argument("Can't open csvFile\n");
	}
	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line)) {
//		std::cout<<"line: "<<line<<"\n";
		try {
			if(line.length() < 12){
				continue;
			}
			std::string date = line.substr(0, 10);
			Date parsedDate(date);
			std::string value = line.substr(11, line.length() - 11); //check if valid aka only digits and . or e
			if (!isFloat(value)){
//				std::cerr<<"not float value\n";
				continue;
			}
			float floatValue = 0;
			floatValue = std::stof(value);
//			if (floatValue < 0 || floatValue > 1000) {
////				std::cerr<<floatValue<<" out of range\n";
//				continue;
//			}
			std::pair<Date, float> dataPair = std::make_pair(parsedDate, floatValue);
			m_csvData.insert(dataPair);
		}
		catch (std::exception &ex) {
		}
	}
	infile.close();
}

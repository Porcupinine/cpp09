//
// Created by laura on 22-8-24.
//

#ifndef CPP09_BITCOINEXCHANGE_H
#define CPP09_BITCOINEXCHANGE_H


#include <map>
#include "Date.h"

class BitcoinExchange {
public:
	BitcoinExchange() = delete;
	explicit BitcoinExchange(const std::string& csvFile);
	~BitcoinExchange() = default;
	BitcoinExchange(const BitcoinExchange& cp) = delete;
	BitcoinExchange& operator=(const BitcoinExchange& cp) = delete;
	void convert(const std::string& inputFile);
	void parseData(const std::string& fileName);
private:
	std::map<Date, float> m_csvData {};
};

#endif //CPP09_BITCOINEXCHANGE_H

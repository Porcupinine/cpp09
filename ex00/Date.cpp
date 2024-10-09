/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Date.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/23 15:11:16 by laura         #+#    #+#                 */
/*   Updated: 2024/08/23 15:11:16 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <utility>
#include <iomanip>
#include "Date.h"

namespace {
	bool checkLeapYear(ssize_t year) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			return true;
		}
		return false;
	}
}

Date::Date(std::string  date) : m_date(std::move(date)){
	parseDate();
	if(m_day == -1 || m_month == -1 || m_year == -1 || !validateDate()){
		throw std::runtime_error("Impossible date");
	}
}

bool Date::validateDate() const {
	if (m_month > 12){
		return false;
	}
	if (m_month == 02) {
		if ((checkLeapYear(m_year) && m_day > 29) || (!checkLeapYear(m_year) && m_day > 28))
			return false;
	}
	else if (m_day < 1 || ((m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11) && m_day > 30)) {
		return false;
	}
	else if (m_day > 31) {
		return false;
	}
	return true;
}

void Date::parseDate() {
	std::string tmp;
	try {
		tmp = m_date.substr(0, 4);
		m_year = std::stoi(tmp);
		if(!std::all_of(tmp.begin(), tmp.end(), ::isdigit))
			m_year = -1;
	}
	catch (std::exception& ex) {
		m_year = -1;
		std::cerr<<"Error"<<ex.what();
	}
	try {
		tmp.clear();
		tmp = m_date.substr(5, 2);
		m_month = std::stoi(tmp);
		if(!std::all_of(tmp.begin(), tmp.end(), ::isdigit))
			m_month = -1;
	}
	catch (std::exception& ex) {
		std::cerr<<"Error"<<ex.what();
		m_month = -1;
	}
	try {
		tmp.clear();
		tmp = m_date.substr(8, 2);
		m_day = std::stoi(tmp);
		if(!std::all_of(tmp.begin(), tmp.end(), ::isdigit))
			m_day = -1;
	}
	catch (std::exception& ex) {
		std::cerr<<"Error"<<ex.what();
		m_day = -1;
	}
}

bool Date::operator<(const Date &other) const {
	if (m_year == other.m_year){
		if (m_month == other.m_month){
			return m_day < other.m_day;
		}
		return m_month < other.m_month;
	}
	return m_year < other.m_year;
}

std::ostream& operator<<(std::ostream &os, const Date& date) {
	return os<<std::setw(2)<<std::setfill('0')<<date.getYear()<<"-"<<std::setw(2)<<std::setfill('0')<<date.getMonth()<<"-"<<std::setw(2)<<std::setfill('0')<<date.getDay();
}

bool Date::operator==(const Date &other) const {
	if (m_year != other.m_year) return false;
	if (m_month != other.m_month) return false;
	if (m_day != other.m_day) return false;
	return true;
}

ssize_t Date::getYear() const {
	return m_year;
}

ssize_t Date::getMonth() const {
	return m_month;
}

ssize_t Date::getDay() const {
	return m_day;
}

Date::Date(const Date &cp) : m_date(cp.m_date){
	m_month = cp.m_month;
	m_day = cp.m_day;
	m_year = cp.m_year;
}

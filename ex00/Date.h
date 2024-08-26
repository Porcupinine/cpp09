//
// Created by laura on 23-8-24.
//

#ifndef CPP09_DATE_H
#define CPP09_DATE_H


#include <string>

class Date {
public:
	Date() = delete;
	explicit Date(std::string  date);
	~Date() = default;
	Date(const Date& cp);
	Date& operator=(const Date& cp) = delete;
	bool validateDate() const;
	void parseDate();

	ssize_t getYear() const;
	ssize_t getMonth() const;
	ssize_t getDay() const;

	bool operator<(const Date& other) const;
	bool operator==(const Date& other) const;

private:
	ssize_t m_day {};
	ssize_t m_month {};
	ssize_t m_year {};
	std::string m_date;

};

std::ostream& operator<<(std::ostream& os, const Date& date) ;

#endif //CPP09_DATE_H

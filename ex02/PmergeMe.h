/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 15:30:41 by laura         #+#    #+#                 */
/*   Updated: 2024/09/04 15:30:41 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP09_PMERGEME_H
#define CPP09_PMERGEME_H


#include <vector>
#include <list>
#include <chrono>
#include <utility>

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()


class PmergeMe {
public:
	PmergeMe() = delete;
	PmergeMe(int argc, char **data);
	~PmergeMe() = default;
	PmergeMe(const PmergeMe& cp) = default;
	PmergeMe& operator=(const PmergeMe& cp) = default;
	void parseData(int argc, char **data);
	void sortList();
	void sortVector();

private:
	std::vector<int> m_vector;
	std::list<int> m_list;
	double m_parseTime {};
	double m_listTime {};
	double m_vectorTime {};
};

template<typename F, typename... Args>
double funcTime(F func, Args&&... args){
	TimeVar t1=timeNow();
	func(std::forward<Args>(args)...);
	return duration(timeNow()-t1);
}

#endif //CPP09_PMERGEME_H

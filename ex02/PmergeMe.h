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

using vecPair = std::vector<std::pair<int, std::optional<int>>>;

class PmergeMe {
public:
	PmergeMe() = delete;
	PmergeMe(int argc, char **data);
	~PmergeMe() = default;
	PmergeMe(const PmergeMe& cp) = default;
	PmergeMe& operator=(const PmergeMe& cp) = default;

	template<typename T>
	void parseData(int argc, char **data, T& container);
	void sortList();
	void sortVector();

private:
	//data structures
	std::vector<std::pair<int, std::optional<int>>> m_pairVector;
	std::list<std::pair<int, std::optional<int>>> m_pairList;
	std::vector<int> m_vector {};
	std::list<int> m_list {};
	std::vector<int> m_jacobVec {};
	std::vector<int> m_insertOrder{};

	//timers
	double m_parseListTime {};
	double m_parseVecTime {};
	double m_listTime {};
	double m_vectorTime {};

	//common functions
	void fillJacobVector();
	void fillInsertVec();
	int getJacob(int n);

	//vector functions
	void sortVecInPairs();
	void printVecPairs();
	void mergeSortVec(int start, int end);
	void mergeVec(int start, int mid, int end);
	void feedMainVecChain();
	void insertAppendVecChain();
	std::vector<int>::iterator binarySearchVec(int target);


};

//timer
template<typename F, typename... Args>
double funcTime(F func, Args&&... args){
	TimeVar t1=timeNow();
	func(std::forward<Args>(args)...);
	return duration(timeNow()-t1);
}

#endif //CPP09_PMERGEME_H

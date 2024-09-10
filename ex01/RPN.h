

#ifndef CPP09_RPN_H
#define CPP09_RPN_H


#include <stack>
#include <string>

class RPN {
public:
	RPN() = delete;
	~RPN() = default;
	RPN(const RPN& cp) = default;
	RPN& operator=(const RPN& cp) = default;
	explicit RPN(const std::string& math);

	void doMath();

private:
	std::stack<float> m_stack;
	float m_result {};
};


#endif //CPP09_RPN_H

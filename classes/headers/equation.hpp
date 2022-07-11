#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "../../utils.hpp"

class Equation {

public:

	Equation(void);
	~Equation(void);

	Equation& operator=(std::string eq);

	void printTokens(void) const;
	void fillMap(void);

private:

	std::map<int, float>	coefficients;
	std::vector<std::string>		tokens;
	int								degree;

};
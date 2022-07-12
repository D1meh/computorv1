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
	void resolve(void) ;

	std::map<int, float>&		getCoeff(void);
	std::map<int, float> const& getCoeff(void) const;
	int							getDegree(void);
	int					getDegree(void) const;
	void						setDegree(int deg);

private:

	std::map<int, float>	coefficients;
	std::vector<std::string>		tokens;
	int								degree;

};

std::ostream& operator<<(std::ostream& os, Equation & eq);
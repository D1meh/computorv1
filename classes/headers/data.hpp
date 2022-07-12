#pragma once

#include "../../includes.hpp"

class Data {

public:

	Data(std::string arg);
	~Data(void);

private:

	Data(void);

	void trimEquations(void);
	void mixEquations(void);

	std::string leftSide;
	std::string rightSide;

	Equation	leftEqu;
	Equation	rightEqu;

};
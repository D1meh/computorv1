#include "headers/data.hpp"

Data::Data(std::string arg) {
	int pos = arg.find("=");

	this->leftSide = arg.substr(0, pos);
	arg.erase(0, pos + std::string("=").length());
	this->rightSide = arg;
	this->trimEquations();

	this->leftEqu = this->leftSide;
	this->rightEqu = this->rightSide;

	this->leftEqu.printTokens();
	std::cout << "OK" << std::endl;
	this->rightEqu.printTokens();

	this->leftEqu.fillMap();
}

Data::Data(void) {}

Data::~Data(void) {}

/************************************/
/*									*/
/*									*/
/*									*/
/************************************/

void Data::trimEquations(void) {

	trimStr(this->leftSide);
	trimStr(this->rightSide);
}

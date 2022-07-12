#include "headers/data.hpp"

Data::Data(std::string arg) {
	int pos = arg.find("=");

	this->leftSide = arg.substr(0, pos);
	arg.erase(0, pos + std::string("=").length());
	this->rightSide = arg;
	this->trimEquations();

	this->leftEqu = this->leftSide;
	this->rightEqu = this->rightSide;

	// this->leftEqu.printTokens();
	// std::cout << "OK" << std::endl;
	// this->rightEqu.printTokens();

	this->leftEqu.fillMap();
	this->rightEqu.fillMap();

	this->mixEquations();

	std::cout << this->leftEqu << std::endl;
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

void Data::mixEquations(void) {

	std::map<int, float>::iterator it = this->rightEqu.getCoeff().begin();

	while (it != this->rightEqu.getCoeff().end()) {

		std::map<int, float>::iterator t = this->leftEqu.getCoeff().find(it->first);
		if (t == this->leftEqu.getCoeff().end())
			this->leftEqu.getCoeff()[it->first] = -it->second;
		else
			t->second -= it->second;
		it++;
	}

	it = this->leftEqu.getCoeff().begin();
	std::cout << "printing" << std::endl;
	while (it != this->leftEqu.getCoeff().end()) {
		std::cout << "[" << it->first << "] [" << it->second << "]" << std::endl;
		it++;
	}
	this->leftEqu.setDegree((this->leftEqu.getDegree() > this->rightEqu.getDegree()) ? this->leftEqu.getDegree() : this->rightEqu.getDegree());
	std::cout << this->leftEqu.getDegree() << std::endl;
}

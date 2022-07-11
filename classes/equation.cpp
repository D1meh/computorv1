#include "headers/equation.hpp"

Equation::Equation(void) {
	this->degree = 0;
}

Equation::~Equation(void) {}

Equation& Equation::operator=(std::string eq) {

	std::string save = std::string(eq);
	char *token = std::strtok((char*)eq.c_str(), "+-");

	while (token) {
		std::string tmp = token;
		this->tokens.push_back(trimStr(tmp));
		token = std::strtok(NULL, "+-");
	}

	int count = 0, i = 0;
	while (save[i]) {
		if (save[i] == '-')
			this->tokens.at(count).insert(0, "-");
		i++;
		if (save[i] == '-' || save[i] == '+')
			count++;
	}

	return *this;
}

void Equation::fillMap(void) {
	std::vector<std::string>::iterator it = this->tokens.begin();

	while (it != this->tokens.end()) {
		std::string current = *it, sub1, sub2;
		int pos = current.find("*");
		sub1 = current.substr(0, pos);
		current.erase(0, pos+1);
		sub2 = current;

		std::string x = (sub1.find('X') != std::string::npos) ? sub1 : sub2; trimStr(x);
		std::string coeff = (sub1.find('X') == std::string::npos) ? sub1 : sub2; trimStr(coeff);

		if (x == coeff && x.find('^') != std::string::npos)
			coeff = "1";

		if (x[0] == '-' && x != coeff) {
			x.erase(x.begin());
			coeff.insert(0, "-");
		}

		size_t exponent = x.find('^');
		if (exponent == std::string::npos)
			x = "0";
		else
			x.erase(0, exponent+1);
		std::cout << "[" + x << "] [" << coeff + "]" << std::endl;

		this->coefficients.insert(std::pair<int, float>(std::stoi(x), std::stof(coeff)));
		it++;
	}
}

void Equation::printTokens(void) const {
	std::vector<std::string>::const_iterator it = this->tokens.begin();

	while (it != this->tokens.end()) {
		std::cout << "[" + *it + "]" << std::endl;
		it++;
	}
}
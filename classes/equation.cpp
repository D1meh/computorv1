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
	int max = 0;

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
		if (std::stoi(x) > max)
			max = std::stoi(x);
		it++;
	}
	this->degree = max;
}

void Equation::printTokens(void) const {
	std::vector<std::string>::const_iterator it = this->tokens.begin();

	while (it != this->tokens.end()) {
		std::cout << "[" + *it + "]" << std::endl;
		it++;
	}
}

void Equation::resolve(void) {
	if (this->degree == 1) {
		std::cout << "The solution is:" << std::endl;
		std::cout << - this->coefficients[0] / this->coefficients[1] << std::endl;
	} else {
		float disc = discriminant(this->coefficients[2], this->coefficients[1], this->coefficients[0]);
		if (disc == (float)0) {
			std::cout << "Discriminant is null, the solution is:" << std::endl;
			std::cout << oneSolution(this->coefficients[2], this->coefficients[1]) << std::endl;
		} else if (disc > 0) {
			std::cout << "Discriminant is strictly positive, the solutions are:" << std::endl;
			std::cout << twoSolutionsFirst(this->coefficients[2], this->coefficients[1], disc) << " " << twoSolutionsSecond(this->coefficients[2], this->coefficients[1], disc) << std::endl;
		} else {
			std::cout << "Discriminant is strictly negative, the solutions are:" << std::endl;
			std::cout << twoSolutionsFirst(this->coefficients[2], this->coefficients[1], disc) << "i " << twoSolutionsSecond(this->coefficients[2], this->coefficients[1], disc) << "i" << std::endl;
		}
	}
}

std::map<int, float>& Equation::getCoeff(void) {
	return this->coefficients;
}

std::map<int, float> const& Equation::getCoeff(void) const {
	return this->coefficients;
}

int	Equation::getDegree(void) {
	return this->degree;
}

// int	Equation::getDegree(void) const {
// 	return this->degree;
// }

void Equation::setDegree(int deg) { this->degree = deg; }

std::ostream& operator<<(std::ostream& os, Equation& eq) {

	std::map<int, float>::const_reverse_iterator it = eq.getCoeff().rbegin();
	std::cout << "Reduced form: ";

	while (it != eq.getCoeff().rend()) {

		if (it == eq.getCoeff().rbegin()) {
			if (it->second < 0)
				std::cout << "- " << -it->second << " * X^" << it->first << " ";
			else
				std::cout << it->second << " * X^" << it->first << " ";
		}
		else {
			float absVal = (it->second < 0) ? -it->second : it->second;
			std::cout << absVal << " * X^" << it->first << " ";
		}

		it++;
		if (it == eq.getCoeff().rend())
			std::cout << "= 0" << std::endl;
		else if (it->second < 0)
			std::cout << "- ";
		else
			std::cout << "+ ";
	}

	std::cout << "Polynomial degree: " << eq.getDegree() << std::endl;
	if (eq.getDegree() > 2)
		std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
	else
		eq.resolve();

	return os;
}
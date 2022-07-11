#include "utils.hpp"

float square(float x) { return x * x; }

float discriminant(float a, float b, float c) {
	return square(b) - (4 * a * c);
}

std::string& trimStr(std::string& s) {
	std::string whiteSpaces(" \n\t\v");

	std::string::size_type pos1 = s.find_last_not_of(whiteSpaces);
	s.erase(pos1+1);
	
	std::string::size_type pos2 = s.find_first_not_of(whiteSpaces);
	s.erase(0, pos2);

	return s;
}
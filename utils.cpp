#include "utils.hpp"
#include <math.h>

float square(float x) { return x * x; }

float discriminant(float a, float b, float c) {
	return square(b) - (4 * a * c);
}

float twoSolutionsFirst(float a, float b, float disc) {
	float d = (disc < 0) ? -disc : disc;
	return (-b - sqrt(d)) / (2 * a);
}

float twoSolutionsSecond(float a, float b, float disc) {
	float d = (disc < 0) ? -disc : disc;
	return (-b + sqrt(d)) / (2 * a);
}

float oneSolution(float a, float b) {
	return -b / (2 * a);
}

std::string& trimStr(std::string& s) {
	std::string whiteSpaces(" \n\t\v");

	std::string::size_type pos1 = s.find_last_not_of(whiteSpaces);
	s.erase(pos1+1);
	
	std::string::size_type pos2 = s.find_first_not_of(whiteSpaces);
	s.erase(0, pos2);

	return s;
}
#include "include.h"


int main() {


	FractionNumber frac1;
	std::cout << "Fraction 1: ";
	frac1.display();


	FractionNumber frac2(1, 9);
	std::cout << "Fraction 2: ";
	frac2.display();


	FractionNumber frac3(frac2);
	std::cout << "Fraction 3: ";
	frac3.display();

	FractionNumber resultAdd = frac1 + frac2;
	FractionNumber resultSubtract = frac1 - frac2;
	FractionNumber result_value_add_fraction = 5 + frac1;
	FractionNumber result_value_subtract_fraction = 0 - frac1;
	float floatResult = static_cast<float>(frac3);
	frac2 = frac1;

	std::cout << "Fraction 1 + Fraction 2: ";
	resultAdd.display();

	std::cout << "Fraction 1 - Fraction 2: ";
	resultSubtract.display();

	std::cout << "5 + Fraction 1: ";
	result_value_add_fraction.display();

	std::cout << "0 - Fraction 1: ";
	result_value_subtract_fraction.display();

	std::cout << "Fraction 3 as float: " << floatResult << std::endl;

	std::cout << "Fraction 1: ";
	frac1.display();
	std::cout << "Fraction 2: ";
	frac2.display();


	FractionNumber::displayCount();
	return 0;
}

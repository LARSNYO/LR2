#include <iostream>
#include <string>


class FractionNumber {


private:
	int* numerator;
	int* denominator;
	static int operationsCount;


public:


	//Consturctor with parameters
	FractionNumber(int num, int denom) : numerator(new int(num)), denominator(new int(denom)) {}


	//Copy constructor
	FractionNumber(const FractionNumber& otherFraction) : numerator(new int(*otherFraction.numerator)), denominator(new int(*otherFraction.denominator)) {}


	//Default Constructor
	FractionNumber() : FractionNumber(5, 9) {}


	//Destructor
	~FractionNumber() {
		delete numerator;
		delete denominator;
		std::cout << "Fraction object is being destroyed." << std::endl;
	}


	FractionNumber add(const FractionNumber& otherFraction) {
		int resultNum = *numerator * (*otherFraction.denominator) + (*otherFraction.numerator) * *denominator;
		int resultDenom = *denominator * (*otherFraction.denominator);
		FractionNumber::operationsCount++;
		return FractionNumber(resultNum, resultDenom);
	}


	FractionNumber subtract(const FractionNumber& otherFraction) {
		int resultNum = *numerator * (*otherFraction.denominator) - (*otherFraction.numerator) * *denominator;
		int resultDenom = *denominator * (*otherFraction.denominator);
		FractionNumber::operationsCount++;
		return FractionNumber(resultNum, resultDenom);
	}


	FractionNumber multiply(const FractionNumber& otherFraction) {
		int resultNum = *numerator * (*otherFraction.numerator);
		int resultDenom = *denominator * (*otherFraction.denominator);
		FractionNumber::operationsCount++;
		return FractionNumber(resultNum, resultDenom);
	}


	FractionNumber divide(const FractionNumber& otherFraction) {
		int resultNum = *numerator * (*otherFraction.denominator);
		int resultDenom = *denominator * (*otherFraction.numerator);
		FractionNumber::operationsCount++;
		return FractionNumber(resultNum, resultDenom);
	}


	void display() {
		std::cout << *numerator << "/" << *denominator << std::endl;
	}


	static void displayCount() {
		std::cout << "Number of Fraction objects created: " << operationsCount << std::endl;
	}

//////////////////////////////////////////____________LR2________________________//////////////////////////////////

	FractionNumber operator+(const FractionNumber& otherFraction) const {
		int resultNum = *numerator * (*otherFraction.denominator) + (*otherFraction.numerator) * *denominator;
		int resultDenom = *denominator * (*otherFraction.denominator);
		FractionNumber::operationsCount++;
		return FractionNumber(resultNum, resultDenom);
	}

	FractionNumber operator-(const FractionNumber& otherFraction) const {
		int resultNum = *numerator * (*otherFraction.denominator) - (*otherFraction.numerator) * *denominator;
		int resultDenom = *denominator * (*otherFraction.denominator);
		FractionNumber::operationsCount++;
		return FractionNumber(resultNum, resultDenom);
	}

	friend FractionNumber operator+(int value, const FractionNumber& otherFraction) {
		int resultNum = value * (*otherFraction.denominator) + *otherFraction.numerator;
		int resultDenom = *otherFraction.denominator;
		FractionNumber::operationsCount++;
		return FractionNumber(resultNum, resultDenom);
	}

	friend FractionNumber operator-(int value, const FractionNumber& otherFraction) {
		int resultNum = value * (*otherFraction.denominator) - *otherFraction.numerator;
		int resultDenom = *otherFraction.denominator;
		FractionNumber::operationsCount++;
		return FractionNumber(resultNum, resultDenom);
	}

	operator float() const {
		return static_cast<float>(*numerator) / static_cast<float>(*denominator); //static_cast - преобразователь числового типа
	}

	FractionNumber& operator=(const FractionNumber& otherFraction) {
		if (this != &otherFraction) { //делаем проверку чтобы оператор объект не присваивался сам себе, если этого не происходит, то мы освобождаем память, чтобы не потерять ссылки на уже выделенные участки памяти.
			delete numerator;
			delete denominator;

			numerator = new int(*otherFraction.numerator);
			denominator = new int(*otherFraction.denominator);
		}
		return *this;
	}


};


int FractionNumber::operationsCount = 0;

#include "Money.h"
#include <iostream>

int main() {
	int a, b;
	double c;
	Money* one;
	Money* two;
	std::cout << "Enter first money:";
	std::cin >> a >> b >> c;
	try {
		one = new Money(a, b, c);
	}
	catch (MoneyException) {
		std::cerr << "Wrong Data\n";
		return -1;
	}
	std::cout << "Enter second money:";
	std::cin >> a >> b >> c;
	try {
		two = new Money(a, b, c);
	}
	catch (MoneyException) {
		std::cerr << "Wrong Data\n";
		return -1;
	}
	std::cout << "+:" << (*one + *two) << '\n';
	std::cout << "-:" << (*one - *two) << '\n';
	std::cout << "unary -:" << (-*one) << '\n';
	std::cout << "==" << (*one == *two) << '\n';
	std::cout << "<" << (*one < *two) << '\n';
	std::cout << "+=" << (*one += *two) << '\n';
	std::cout << "-=" << (*one -= *two) << '\n';
	return 0;
}
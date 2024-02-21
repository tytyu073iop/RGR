#pragma once

#include <iostream>

class Money {
	int pound = 0, shilling = 0;
	double pence = 0;
public:
	Money(int pound, int shilling, double pence);
	Money operator+(const Money& rhs) const;
	Money operator-() const;
	Money operator-(const Money& rhs) const;
	Money& operator+=(const Money& rhs);
	Money& operator-=(const Money& rhs);
	bool operator==(const Money& rhs) const;
	bool operator<(const Money& rhs) const;
	friend std::ostream& operator<<(std::ostream& out, const Money& rhs);
};

enum MoneyException
{
	WrongData
};
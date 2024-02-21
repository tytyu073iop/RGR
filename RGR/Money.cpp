#include "Money.h"
#include <tuple>
#include <iomanip>



Money::Money(int a = 0, int b = 0, double c = 0) : pound(a), shilling(b)
{
	if (b >= 20 || c >= 12 || a < 0 || b < 0 || c < 0) {
		throw MoneyException::WrongData;
	}
	double da = c - static_cast<int>(c);
	double db = static_cast<int>(c);
	da *= 4;
	da = static_cast<int>(da);
	da /= 4;
	pence = da + db;
}

Money Money::operator+(const Money& rhs) const
{
	Money obj;
	auto c = rhs.pence + pence;
	auto b = rhs.shilling + shilling + (static_cast<int>(c) / 12);
	if (c > 12) {
		c -= 12;
	}
	auto a = rhs.pound + pound + (b / 20);
	b %= 20;
	obj.pound = a;
	obj.shilling = b;
	obj.pence = c;
	return Money(a, b, c);
}

Money Money::operator-() const
{
	Money obj;
	obj.pound = -pound;
	obj.shilling = -shilling;
	obj.pence = -pence;
	return obj;
}

Money Money::operator-(const Money& rhs) const
{
	Money obj;
	auto a = pound - rhs.pound;
	auto b = shilling - rhs.shilling;
	if (b < 0 && a > 0) {
		b = 20 + b;
		a--;
	}
	auto c = pence - rhs.pence;
	if (c < 0 && b > 0) { // try
		c = 12 + c;
		b--;
	}
	if (c < 0 && b == 0 && a > 0) {
		c = 12 + c;
		b = 19;
		a--;
	}
	obj.pound = a;
	obj.shilling = b;
	obj.pence = c;
	return obj;
}

Money& Money::operator+=(const Money& rhs)
{
	*this = *this + rhs;
	return *this;
}

Money& Money::operator-=(const Money& rhs)
{
	*this = *this - rhs;
	return *this;
}

bool Money::operator==(const Money& rhs) const
{
	return pound == rhs.pound && shilling == rhs.shilling && pence == rhs.pence;
}

bool Money::operator<(const Money& rhs) const
{
	return std::tie(pound, shilling, pence) < std::tie(rhs.pound, rhs.shilling, rhs.pence);
}

std::ostream& operator<<(std::ostream& out, const Money& rhs)
{
	if (rhs.pound != 0)
	{
		out << rhs.pound << "pd.";
	}
	if (rhs.shilling != 0)
	{
		out << rhs.shilling << "sh.";
	}
	if (rhs.pence != 0 || (rhs.pound == 0 && rhs.shilling == 0))
	{
		out << rhs.pence << "p.";
		}
	return out;
}


#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		this->numerator_ = numerator;
		this->denominator_ = denominator;
	}

	bool operator == (Fraction other)
	{
		return other.numerator_ == other.denominator_;
	}

	bool operator != (Fraction other)
	{
		return other.numerator_ != other.denominator_;
	}

	bool operator < (Fraction other)
	{
		return other.numerator_ < other.denominator_;
	}

	bool operator > (Fraction other)
	{
		return other.numerator_ > other.denominator_;
	}

	bool operator <= (Fraction other)
	{
		return other.numerator_ <= other.denominator_;
	}

	bool operator >= (Fraction other)
	{
		return other.numerator_ >= other.denominator_;
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 4);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}


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
		int numerator_1 = other.numerator_ * denominator_;
		int numerator_2 = numerator_ * other.denominator_;
		if (numerator_1 == numerator_2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator != (Fraction other)
	{
		int numerator_1 = other.numerator_ * denominator_;
		int numerator_2 = numerator_ * other.denominator_;
		if (numerator_1 != numerator_2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator < (Fraction other)
	{
		int numerator_1 = other.numerator_ * denominator_;
		int numerator_2 = numerator_ * other.denominator_;
		if (numerator_1 < numerator_2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator > (Fraction other)
	{
		int numerator_1 = other.numerator_ * denominator_;
		int numerator_2 = numerator_ * other.denominator_;
		if (numerator_1 > numerator_2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator <= (Fraction other)
	{
		int numerator_1 = other.numerator_ * denominator_;
		int numerator_2 = numerator_ * other.denominator_;
		if (numerator_1 <= numerator_2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator >= (Fraction other)
	{
		int numerator_1 = other.numerator_ * denominator_;
		int numerator_2 = numerator_ * other.denominator_;
		if (numerator_1 >= numerator_2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	Fraction f1(3, 4);
	Fraction f2(6, 8);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}

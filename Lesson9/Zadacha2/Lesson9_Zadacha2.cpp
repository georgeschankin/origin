#include <iostream>
#include <string>

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
    
	// Наибольший общий делитель
	int NOD(int a, int b) 
	{
		while (b > 0) {
			int c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
	// Наименьшее общее кратное
	int NOK(int a, int b) 
	{
		return NOD(a, b) * a * b;
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

	std::string operator + (Fraction other)
	{
		int union_Denominator = NOK(denominator_, other.denominator_);
		int rel_Numerator = numerator_ * union_Denominator;
		int mul_Numerator = other.numerator_ * union_Denominator;
		numerator_ = rel_Numerator * mul_Numerator;
		denominator_ = union_Denominator;
		return std::to_string(numerator_) + "/" + std::to_string(denominator_);
	}

	std::string operator - (Fraction other)
	{
		int rel_Numerator = numerator_ * other.denominator_;
		numerator_ = numerator_ * other.denominator_ - denominator_ * other.numerator_;
		denominator_ = NOD(denominator_, other.denominator_);
		return std::to_string(numerator_) + "/" + std::to_string(denominator_);
	}

	std::string operator / (Fraction other)
	{
		numerator_ = numerator_ * other.denominator_;
		denominator_ = denominator_ * other.numerator_;
		return std::to_string(numerator_) + "/" + std::to_string(denominator_);
	}

	std::string operator * (Fraction other)
	{
		numerator_ = numerator_ * other.numerator_;
		denominator_ = denominator_ * other.denominator_;
		return std::to_string(numerator_) + "/" + std::to_string(denominator_);
	}

	int operator ++ (int)
	{
		numerator_ = numerator_ + denominator_;		
		return numerator_;
	}

	int operator -- (int)
	{
		numerator_ = numerator_ - denominator_;
		return numerator_;
	}
};


int main()
{	
	setlocale(LC_ALL, "Russian");

	Fraction f1(4, 3);
	Fraction f2(6, 4);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	std::cout << '\n';

	int f1_n, f1_de, f2_n, f2_de;
	
	std::cout << "Введите числитель дроби 1: " << std::endl;
	std::cin >> f1_n;
	std::cout << "Введите знаменатель дроби 1: " << std::endl;
	std::cin >> f1_de;
	std::cout << "Введите числитель дроби 2: " << std::endl;
	std::cin >> f2_n;
	std::cout << "Введите знаменатель дроби 2: " << std::endl;
	std::cin >> f2_de;

	Fraction f3(f1_n, f1_de);
	Fraction f4(f2_n, f2_de);

	std::cout << f1_n << "/" << f1_de << " + " << f2_n << "/" << f2_de << "=" << f3 + f4 << std::endl;
	std::cout << f1_n << "/" << f1_de << " - " << f2_n << "/" << f2_de << "=" << f3 - f4 << std::endl;
	std::cout << f1_n << "/" << f1_de << " * " << f2_n << "/" << f2_de << "=" << f3 * f4 << std::endl;
	std::cout << f1_n << "/" << f1_de << " / " << f2_n << "/" << f2_de << "=" << f3 / f4 << std::endl;
	std::cout << f1_n << "/" << f1_de << " ++ " << f3++ << "/" << f1_de << std::endl;
	std::cout << f1_n << "/" << f1_de << " -- " << f3-- << "/" << f1_de << std::endl;
}
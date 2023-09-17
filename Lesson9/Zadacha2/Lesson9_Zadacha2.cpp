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
		while (b > 0) 
		{
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

	Fraction operator + (Fraction other)
	{
		int union_Denominator = NOK(denominator_, other.denominator_);
		int rel_Numerator = numerator_ * union_Denominator;
		int mul_Numerator = other.numerator_ * union_Denominator;
		numerator_ = rel_Numerator * mul_Numerator;
		denominator_ = union_Denominator;
		return Fraction(numerator_, denominator_);
	}

	Fraction operator - (Fraction other)
	{
		int rel_Numerator = numerator_ * other.denominator_;
		numerator_ = numerator_ * other.denominator_ - denominator_ * other.numerator_;
		denominator_ = NOD(denominator_, other.denominator_);
		return Fraction(numerator_, denominator_);
	}

	Fraction operator / (Fraction other)
	{
		numerator_ = numerator_ * other.denominator_;
		denominator_ = denominator_ * other.numerator_;
		return Fraction(numerator_, denominator_);
	}

	Fraction operator * (Fraction other)
	{
		numerator_ = numerator_ * other.numerator_;
		denominator_ = denominator_ * other.denominator_;
		return Fraction(numerator_, denominator_);
	}

	Fraction operator ++ (int)
	{
		numerator_ = numerator_ + denominator_;		
		return Fraction(numerator_, denominator_);
	}

	Fraction operator -- (int)
	{
		numerator_ = numerator_ - denominator_;
		return Fraction(numerator_, denominator_);
	}

	Fraction operator ++ ()
	{
		numerator_ = numerator_ + denominator_;
		return Fraction(numerator_, denominator_);
	}

	Fraction operator -- ()
	{
		numerator_ = numerator_ - denominator_;
		return Fraction(numerator_, denominator_);
	}

	void print()
	{
		std::cout << numerator_ << "/" << denominator_ << std::endl;
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

	std::cout << f1_n << "/" << f1_de << " + " << f2_n << "/" << f2_de << "=";
	Fraction fx1 = f3 + f4;
	fx1.print();

	std::cout << f1_n << "/" << f1_de << " - " << f2_n << "/" << f2_de << "=" ;
	Fraction fx2 = f3 - f4;
	fx2.print();

	std::cout << f1_n << "/" << f1_de << " * " << f2_n << "/" << f2_de << "=" ;
	Fraction fx3 = f3 * f4;
	fx3.print();

	std::cout << f1_n << "/" << f1_de << " / " << f2_n << "/" << f2_de << "=" ;
	Fraction fx4 = f3 / f4;
	fx4.print();

	std::cout << f1_n << "/" << f1_de << " ++ " << " =";
	Fraction fz1 = f3++;
	fz1.print();

	std::cout << f1_n << "/" << f1_de << " -- " << " =";
	Fraction fz2 = f3--;
	fz2.print();

	std::cout << " ++ " << f1_n << "/" << f1_de << " = ";
	Fraction fz3 = ++f3;
	fz3.print();

	std::cout << " -- " << f1_n << "/" << f1_de << " = ";
	Fraction fz4 = --f3;
	fz4.print();
}
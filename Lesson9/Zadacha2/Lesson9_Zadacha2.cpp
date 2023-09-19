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

	//сокращение дроби
	Fraction reduce() 
	{		
		int numerator_1 = numerator_;
		int denominator_1 = denominator_;
		int nod = NOD(numerator_, denominator_);
		numerator_1 /= nod;
		denominator_1 /= nod;
		return Fraction(numerator_1, denominator_1);
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

	Fraction operator + (Fraction other)
	{
		int union_Denominator = NOK(denominator_, other.denominator_);
		int rel_Numerator = numerator_ * union_Denominator;
		int mul_Numerator = other.numerator_ * union_Denominator;
		int numerator_1 = rel_Numerator * mul_Numerator;
		int denominator_1 = union_Denominator;
		return Fraction(numerator_1, denominator_1);
	}

	Fraction operator - (Fraction other)
	{
		int rel_Numerator = numerator_ * other.denominator_;
		int numerator_1 = numerator_ * other.denominator_ - denominator_ * other.numerator_;
		int denominator_1 = NOD(denominator_, other.denominator_);
		return Fraction(numerator_1, denominator_1);
	}

	Fraction operator / (Fraction other)
	{
		int numerator_1 = numerator_ * other.denominator_;
		int denominator_1 = denominator_ * other.numerator_;
		return Fraction(numerator_1, denominator_1);
	}

	Fraction operator * (Fraction other)
	{
		int numerator_1 = numerator_ * other.numerator_;
		int denominator_1 = denominator_ * other.denominator_;
		return Fraction(numerator_1, denominator_1);
	}

	Fraction operator ++ (int)
	{
		int numerator_1 = numerator_ + denominator_;
		return Fraction(numerator_1, denominator_);
	}

	Fraction operator -- (int)
	{
		int numerator_1 = numerator_ - denominator_;
		return Fraction(numerator_1, denominator_);
	}

	Fraction operator ++ ()
	{
		int numerator_1 = numerator_ + denominator_;
		return Fraction(numerator_1, denominator_);
	}

	Fraction operator -- ()
	{
		int numerator_1 = numerator_ - denominator_;
		return Fraction(numerator_1, denominator_);
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
	fx1.reduce();
	fx1.print();

	std::cout << f1_n << "/" << f1_de << " - " << f2_n << "/" << f2_de << "=" ;
	Fraction fx2 = f3 - f4;
	fx2.reduce();
	fx2.print();

	std::cout << f1_n << "/" << f1_de << " * " << f2_n << "/" << f2_de << "=" ;
	Fraction fx3 = f3 * f4;
	fx3.reduce();
	fx3.print();

	std::cout << f1_n << "/" << f1_de << " / " << f2_n << "/" << f2_de << "=" ;
	Fraction fx4 = f3 / f4;
	fx4.reduce();
	fx4.print();

	std::cout << f1_n << "/" << f1_de << " ++ " << " =";
	Fraction fz1 = f3++;
	fz1.reduce();
	fz1.print();

	std::cout << f1_n << "/" << f1_de << " -- " << " =";
	Fraction fz2 = f3--;
	fz2.reduce();
	fz2.print();

	std::cout << " ++ " << f1_n << "/" << f1_de << " = ";
	Fraction fz3 = ++f3;
	fz3.reduce();
	fz3.print();

	std::cout << " -- " << f1_n << "/" << f1_de << " = ";
	Fraction fz4 = --f3;
	fz4.reduce();
	fz4.print();
}
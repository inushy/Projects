//Anushka Verma
//06/09/2020
//Portfolio 1 - Lab 2
#include <iostream>
#include <string>
#include "rational.h"


int main()
{
   MathRat rn1, rn2, rn3;

   cout << "\n\t\t**********************************************************************"<<endl;
   cout << "\n\t\t\t\t\tLet's Play: There's NOTHING Rational About It!! " << endl;
   cout << "\n\t\t**********************************************************************"<<endl;
   cout << "\n\n\t\tEnter a fraction of your choice in the format of numerator/denominator" << endl;
   cout << "\n\t\t----------------------------------------------------------------------"<<endl;
   cout << "\n\n\t\t";
   cin >> rn1;

   cout << "\n\n\t\tYou entered the equivalent of: " << rn1 << endl;
   cout << "\n\n\t\tEnter a fraction of your choice in the format of numerator/denominator" << endl;
   cout << "\n\t\t----------------------------------------------------------------------"<<endl;
   cout << "\n\n\t\t";
   cin >> rn2;

   cout << "\n\n\t\tYou entered the equivalent of: " << rn2 << endl;
   cout << "\n\n\t\tEnter a fraction of your choice in the format of numerator/denominator" << endl;
   cout << "\n\t\t----------------------------------------------------------------------"<<endl;
   cout << "\n\n\t\t";
   cin >> rn3;

   cout << "\n\n\t\tYou entered the equivalent of: " << rn3<<endl;
   cout << "\n\t\t**********************************************************************"<<endl;
   cout << "\n\t\t\t\t\tTesting Fractions With The Arithmetic Operators " << endl;
   cout << "\n\t\t**********************************************************************"<<endl;
   cout << "\n\n\t\t";
   cout << rn1 << " * " << rn2 << " = " << (rn1 * rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn1 << " + " << rn2 << " = " << (rn1 + rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn1 << " - " << rn2 << " = " << (rn1 - rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn1 << " / " << rn2 << " = " << (rn1 / rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn1 << " < " << rn2 << " = " << (rn1 < rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn1 << " < " << rn1 << " = " << (rn1 < rn1) << endl;
   cout << "\n\n\t\t";
   cout << rn1 << " <= " << rn2 << " = " << (rn1 <= rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn1 << " <= " << rn1 << " = " << (rn1 <= rn1) << endl;
   cout << "\n\n\t\t";
   cout << rn1 << " > " << rn2 << " = " << (rn1 > rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn1 << " > " << rn1 << " = " << (rn1 > rn1) << endl;
   cout << "\n\n\t\t";
   cout << rn1 << " >= " << rn2 << " = " << (rn1 >= rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn1 << " >= " << rn1 << " = " << (rn1 >= rn2) << endl;
   cout << "\n\t\t----------------------------------------------------------------------"<<endl;
   cout << "\n\t\t";
   cout << rn3 << " * " << rn2 << " = " << (rn3 * rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn3 << " + " << rn2 << " = " << (rn3 + rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn3 << " - " << rn2 << " = " << (rn3 - rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn3 << " / " << rn2 << " = " << (rn3 / rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn3 << " < " << rn2 << " = " << (rn3 < rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn3 << " < " << rn3 << " = " << (rn3 < rn3) << endl;
   cout << "\n\n\t\t";
   cout << rn3 << " <= " << rn2 << " = " << (rn3 <= rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn3 << " <= " << rn3 << " = " << (rn3 <= rn3) << endl;
   cout << "\n\n\t\t";
   cout << rn3 << " > " << rn2 << " = " << (rn3 > rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn3 << " > " << rn3 << " = " << (rn3 > rn3) << endl;
   cout << "\n\n\t\t";
   cout << rn3 << " >= " << rn2 << " = " << (rn3 >= rn2) << endl;
   cout << "\n\n\t\t";
   cout << rn3 << " >= " << rn3 << " = " << (rn3 >= rn3) << endl;
   cout << "\n\t\t**********************************************************************"<<endl;
   cout << "\n\t\t\t\tThank You For Playing: There's NOTHING Rational About It!! " << endl;
   cout << "\n\t\t**********************************************************************"<<endl;
   cout <<endl<<endl;
   return 0;
}

int MathRat::gcd(int num1, int num2)
{
   if (num1 == 0 || num2 == 0)
       return 1;

   if (num1 < 0)
       num1 = -1 * num1;

   if (num2 < 0)
       num2 = -1 * num2;

   while (num2 != 0)
   {
       int temp = num2;
       num2 = num1 % num2;
       num1 = temp;
   }

   return num1;
}

ostream& operator<<(ostream& out, const MathRat& obj)
{
   out << obj.numerator << '/' << obj.denominator;

   return out;
}

istream& operator >> (istream& in, MathRat& obj)
{
   int n, d;

   in >> n;
   if (!in)
   {
       obj = MathRat();
       return in;
   }

   if (in.peek() == ' ' || in.peek() == '\n')
   {
       obj = MathRat(n);
       return in;
   }

   if (in.peek() != '/')
   {
       obj = MathRat(n);
       cout << "Bad input format for operator >>. Aborting!" << endl;
       exit(1);
   }
   in.get();

   in >> d;
   if (!in)
       return in;

   if (d == 0)
   {
       in.setstate(std::ios::failbit);
       return in;
   }

   obj = MathRat(n, d);

   return in;
}

bool MathRat::operator==(const MathRat& other)
{
   return (numerator == other.numerator && denominator == other.denominator);
}

bool MathRat::operator!=(const MathRat& other)
{
   return !(*this == other);
}

bool MathRat::operator<(const MathRat& other)
{
   return (numerator * other.denominator < denominator * other.numerator);
}

bool MathRat::operator<=(const MathRat& other)
{
   return (*this < other || *this == other);
}

bool MathRat::operator>(const MathRat& other)
{
   return (numerator * other.denominator > denominator * other.numerator);
}

bool MathRat::operator>=(const MathRat& other)
{
   return (*this > other || *this == other);
}

MathRat MathRat::operator+(const MathRat& other)
{
   int newNumerator = numerator * other.denominator + denominator * other.numerator;
   int newDenominator = denominator * other.denominator;
   MathRat result(newNumerator, newDenominator);

   return result;
}

MathRat MathRat::operator-(const MathRat& other)
{
   int newNumerator = numerator * other.denominator - denominator * other.numerator;
   int newDenominator = denominator * other.denominator;
   MathRat result(newNumerator, newDenominator);

   return result;
}

MathRat MathRat::operator*(const MathRat& other)
{
   int newNumerator = numerator * other.numerator;
   int newDenominator = denominator * other.denominator;
   MathRat result(newNumerator, newDenominator);

   return result;
}

MathRat MathRat::operator/(const MathRat& other)
{
   int newNumerator = numerator * other.denominator;
   int newDenominator = denominator * other.numerator;
   MathRat result(newNumerator, newDenominator);

   return result;
}


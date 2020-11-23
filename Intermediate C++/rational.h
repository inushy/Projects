//Anushka Verma
//06/09/2020
//Portfolio 1 - Lab 2
//headerfile
#ifndef rational_h
#define rational_h

using namespace std;

class MathRat
{
   friend ostream& operator<<(ostream& out, const MathRat& obj);
   friend istream& operator >> (istream& in, MathRat& obj);

private:
    int numerator;
    int denominator;
    
public:
    MathRat();
    MathRat(int numer, int denom);
    MathRat(int whNum);
   
    void normalize();
    int gcd(int num1, int num2);

    bool operator==(const MathRat& other);
    bool operator!=(const MathRat& other);
    bool operator<(const MathRat& other);
    bool operator<=(const MathRat& other);
    bool operator>(const MathRat& other);
    bool operator>=(const MathRat& other);

    MathRat operator+(const MathRat& other);
    MathRat operator-(const MathRat& other);
    MathRat operator*(const MathRat& other);
    MathRat operator/(const MathRat& other);
};

MathRat::MathRat():numerator(), denominator(1)
{
}

MathRat::MathRat(int numer, int denom):numerator(numer),denominator(1)
{
   //numerator = numer;

   if (denom != 0)
       denominator = denom;
   else
       //denominator = 1;

   normalize();
}
MathRat::MathRat(int whNum):numerator(whNum),denominator(1)
{
   //numerator = whNum;
   //denominator = 1;
}

void MathRat::normalize()
{
   if (numerator == 0)
   {
       denominator = 1;
   }
   else if (denominator < 0)
   {
       numerator = -1 * numerator;
       denominator = -1 * denominator;
   }

   int div = gcd(numerator, denominator);

   numerator = numerator / div;
   denominator = denominator / div;
}

#endif

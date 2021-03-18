//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
using namespace std;
//------------------------------
// You do not need to put class definitions to the separate files
// Write your code only in main.cpp

// Write the assignment code here
class Complex { 
private:
  double real, imaginary;
public:
  Complex(double x = 0.0, double y = 0.0);
  double GetReal();
  double GetImaginary();
    Complex operator*(double) const;
    void operator>>(std::string&) const;
    void operator<<(const std::string&);
};
class Surreal : public Complex
{
private:
  double surreal;
public:
  Surreal(double, double, double);
  Surreal operator*(double);
  double GetSurreal();
};
class Real { 
private:
  double real;
public:
  Real(double x);
  double GetReal();
    Real operator*(double) const;
};

Real::Real(double x)
{
  this->real = x;
}
double Real::GetReal(){
  return this->real;
}
Real Real::operator*(double a) const{
  double b = a;
  double c = b*this->real;
  return Real(c);
}
Complex::Complex(double x, double y)
{
  this->real = x;
  this->imaginary = y;

}

double Complex::GetReal()
{
 return this->real;
}

double Complex::GetImaginary()
{
  return this->imaginary;
}

void Complex::operator>>(std::string& s) const
{
  s.append(std::to_string(this->real));
  if(imaginary >= 0)
      s.append("+");
      s.append(std::to_string(this->imaginary));
      s.append("i");

}

void Complex::operator<<(const std::string& s)
{

        if (s[0] == '-')
        {
                int re = s[1] - '0';
                this->real = -1 * re;
        }
        else
        {
                this->real = s[0] - '0';
        }

        const char i = 'i';
        int ipos = s.find(i);
        int bpos = ipos - 1;
        int bsignpos = ipos - 2;
        if (s[bsignpos] == '-')
        {
           this->imaginary = -1 * (s[bpos] - '0');
        }
        else
        {
           this->imaginary = s[bpos] - '0';
        }
}

Complex Complex::operator*(double a) const{
  double b = this->real*a;
  double c = this->imaginary*a;
  return Complex(b,c);
}
Surreal::Surreal(double e, double f, double g): Complex(e,f){
  this->surreal = g;
}
double Surreal::GetSurreal(){
  return this->surreal;
}
Surreal Surreal::operator*(double d){
  double b = this->surreal*d;
  return Surreal(this->GetReal()*d, this->GetImaginary()*d, b);
}
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------

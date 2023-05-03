#include "Fraction.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace ariel;
using namespace std;

//-------------------------- constructors --------------------------//
Fraction::Fraction(){
    //by default create 0
    this->numerator = 0;
    this->denominator = 1;
}
Fraction::Fraction(int numerator_, int denominator_){
    if (denominator_ == 0){
        throw std::invalid_argument("ERROR- The denominator cannot be 0");
    }
    if(numerator_ < 0 && denominator_ < 0){
         numerator_ = abs(numerator_);
         denominator_ = abs(denominator_);
    }
    if((numerator_ > 0 && denominator_ < 0) || (numerator_ < 0 && denominator_ > 0)){
        numerator_ = abs(numerator_)*-1;
        denominator_ = abs(denominator_);
    }
    this->numerator = numerator_;
    this->denominator = denominator_;
    reduce();
}
Fraction::Fraction(float num){
        float numerator_= num;
    int denominator_=1;
    int sign = 0;
    if (num >= 0){
        sign = 1;   //positive
    }else{
        sign = -1;  //negative
    }
    while (numerator_-floor(abs(numerator_))>0)
    {
        denominator_ *= 10;
        numerator_ *= 10;
    }
    numerator_ *=sign;
    Fraction(static_cast<int>(numerator_), denominator_);
}
Fraction::Fraction(const Fraction& other) {
    // Copy constructor
    this->numerator = other.getNumerator();
    this->denominator = other.getDenominator();
}

//-------------------------- convert method --------------------------//
Fraction Fraction::convertToFraction(float num){
    // const float EPSILON = 0.00001f;
    // int sign = 0;
    // if (num >= 0){
    //     sign = 1;   //positive
    // }else{
    //     sign = -1;  //negative
    // }
    // num = abs(num);
    // int whole = static_cast<int>(num);
    // float remainder = num - whole;
    // int gcd_value = gcd(static_cast<int>(round(remainder / EPSILON)), static_cast<int>(1 / EPSILON));
    // int numerator_ = static_cast<int>(round((whole + remainder) / EPSILON));
    // int denominator_ = static_cast<int>(round(1 / (remainder / gcd_value + EPSILON)));
    // return Fraction(sign * numerator_, denominator_);
    float numerator_= num;
    int denominator_=1;
    int sign = 0;
    if (num >= 0){
        sign = 1;   //positive
    }else{
        sign = -1;  //negative
    }
    while (numerator_-floor(abs(numerator_))>0)
    {
        denominator_ *= 10;
        numerator_ *= 10;
    }
    numerator_ *=sign;
    return Fraction(static_cast<int>(numerator_), denominator_);
}

int Fraction::gcd(int num1, int num2){
    if (num2 == 0){
        return num1;
    }
    return gcd(num2, num1%num2);
}

//-------------------------- getters & setters --------------------------//
int Fraction::getNumerator() const{
    return this->numerator;
}
int Fraction::getDenominator() const{
    return this->denominator;
}
void Fraction::setNumerator(int numerator_){
    this->numerator = numerator_;
}
void Fraction::setDenominator(int denominator_){
    this->denominator = denominator_;
}

//---------- arithmetic operators: fraction operator fraction ----------//
Fraction Fraction::operator+(const Fraction& other) const{
  return Fraction();  
} 
Fraction Fraction::operator-(const Fraction& other) const{
    return Fraction();
}
Fraction Fraction::operator*(const Fraction& other) const{
    return Fraction();
}
Fraction Fraction::operator/(const Fraction& other) const{
    return Fraction();
}

//---------- arithmetic operators: fraction operator float ----------//
Fraction Fraction::operator+(const float& other) const{
  return Fraction();  
} 
Fraction Fraction::operator-(const float& other) const{
    return Fraction();
}
Fraction Fraction::operator*(const float& other) const{
    return Fraction();
}
Fraction Fraction::operator/(const float& other) const{
    return Fraction();
}

//----------------------- comparison operators -----------------------//
bool Fraction::operator==(const Fraction& other) const{
    return true;
}
bool Fraction::operator!=(const Fraction& other) const{
    return true;
}
bool Fraction::operator>(const Fraction& other) const{
    return true;
}
bool Fraction::operator>=(const Fraction& other) const{
    return true;
}
bool Fraction::operator<(const Fraction& other) const{
    return true;
}
bool Fraction::operator<=(const Fraction& other) const{
    return true;
}

//----------------- increment and decrement methods -----------------//
Fraction& Fraction::operator++(){
    int temp = this->denominator + this->numerator;
    setNumerator(temp);
    int gcd_val = gcd(numerator, denominator);
    numerator /= gcd_val;
    denominator /= gcd_val;
    return *this;
}
Fraction Fraction::operator++(int){
    return Fraction();
}
Fraction& Fraction::operator--(){
    return *this;
}
Fraction Fraction::operator--(int){
    return Fraction();
}

void Fraction::reduce(){
    int gcd_value = gcd(numerator, denominator);
    numerator /= gcd_value;
    denominator /= gcd_value;
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}
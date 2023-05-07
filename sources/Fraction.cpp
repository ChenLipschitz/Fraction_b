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
    for(int i=0; i<3 && (abs(numerator_)-floor(abs(numerator_))>0); i++){
        denominator_ *=10;
        numerator_*=10;
    }
    this->numerator = static_cast<int>(numerator_);
    this->denominator = denominator_;
    reduce();
}
Fraction::Fraction(const Fraction& other) {
    // Copy constructor
    this->numerator = other.getNumerator();
    this->denominator = other.getDenominator();
}

//-------------------------- convert method --------------------------//
Fraction Fraction::convertToFraction(float num){
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

int Fraction::gcd(int num1, int num2) const{
    num1 = abs(num1);
    num2 = abs(num2);
    while (num2 != 0)
    {
        int temp = num2;
        num2 = num1%num2;
        num1 = temp;
    }
    return num1;
}

int Fraction::lcm(int num1, int num2) const{
    int gcd_value = gcd(num1, num2);
    return (num1*num2) / gcd_value;
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
    reduce();
}
void Fraction::setDenominator(int denominator_){
    if (denominator_ == 0){
        throw std::invalid_argument("ERROR- The denominator cannot be 0");
    }
    this->denominator = denominator_;
    reduce();
}

//---------- arithmetic operators: fraction operator fraction ----------//
Fraction Fraction::operator+(const Fraction& other) const{
    int commonDen = lcm(denominator, other.getDenominator());
    if (commonDen == 0){
        throw std::invalid_argument("ERROR- The denominator cannot be 0");
    }
    int factor1 = commonDen / denominator;
    int factor2 = commonDen / other.getDenominator();
    int myExtendedNum = numerator*factor1;
    int otherExtendedNum = other.getNumerator()*factor2;
    return Fraction(myExtendedNum+otherExtendedNum, commonDen);
} 
Fraction Fraction::operator-(const Fraction& other) const{
    int commonDen = lcm(denominator, other.getDenominator());
    if (commonDen == 0){
        throw std::invalid_argument("ERROR- The denominator cannot be 0");
    }
    int factor1 = commonDen / denominator;
    int factor2 = commonDen / other.getDenominator();
    int myExtendedNum = numerator*factor1;
    int otherExtendedNum = other.getNumerator()*factor2;
    return Fraction(myExtendedNum-otherExtendedNum, commonDen);
}
Fraction Fraction::operator*(const Fraction& other) const{
    int newNumerator = numerator*other.getNumerator();
    int newDenominator = denominator*other.getDenominator();
    if (newDenominator == 0){
        throw std::invalid_argument("ERROR- The denominator cannot be 0");
    }
    return Fraction(newNumerator, newDenominator);
}
Fraction Fraction::operator/(const Fraction& other) const{
    int newNumerator = numerator*other.getDenominator();
    int newDenominator = denominator*other.getNumerator();
    if (newDenominator == 0){
        throw std::invalid_argument("ERROR- The denominator cannot be 0");
    }
    return Fraction(newNumerator, newDenominator);
}

//---------- arithmetic operators: fraction operator float ----------//
Fraction Fraction::operator+(const float& other) const{
  return Fraction();
//   Fraction result = newFrac+this*;
//   return result;  
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
    if (denominator == other.getDenominator()){
        if (numerator == other.getNumerator()){
            return true;
        }
    }
    return false;
}
bool Fraction::operator!=(const Fraction& other) const{
    if (denominator == other.getDenominator()){
        if (numerator == other.getNumerator()){
            return false;
        }
    }
    return true;
}
bool Fraction::operator>(const Fraction& other) const{
    int commonDen = lcm(denominator, other.getDenominator());
    int factor1 = commonDen / denominator;
    int factor2 = commonDen / other.getDenominator();
    int myExtendedNum = numerator*factor1;
    int otherExtendedNum = other.getNumerator()*factor2;
    if (myExtendedNum > otherExtendedNum){
        return true;
    }
    return false;
}
bool Fraction::operator>=(const Fraction& other) const{
    int commonDen = lcm(denominator, other.getDenominator());
    int factor1 = commonDen / denominator;
    int factor2 = commonDen / other.getDenominator();
    int myExtendedNum = numerator*factor1;
    int otherExtendedNum = other.getNumerator()*factor2;
    if (myExtendedNum >= otherExtendedNum){
        return true;
    }
    return false;
}
bool Fraction::operator<(const Fraction& other) const{
    int commonDen = lcm(denominator, other.getDenominator());
    int factor1 = commonDen / denominator;
    int factor2 = commonDen / other.getDenominator();
    int myExtendedNum = numerator*factor1;
    int otherExtendedNum = other.getNumerator()*factor2;
    if (myExtendedNum < otherExtendedNum){
        return true;
    }
    return false;
}
bool Fraction::operator<=(const Fraction& other) const{
    int commonDen = lcm(denominator, other.getDenominator());
    int factor1 = commonDen / denominator;
    int factor2 = commonDen / other.getDenominator();
    int myExtendedNum = numerator*factor1;
    int otherExtendedNum = other.getNumerator()*factor2;
    if (myExtendedNum <= otherExtendedNum){
        return true;
    }
    return false;
}

//----------------- increment and decrement methods -----------------//
Fraction& Fraction::operator++(){
    int newNumer = this->denominator + this->numerator;
    setNumerator(newNumer);
    return *this;
}
Fraction Fraction::operator++(int){
    Fraction curr(*this);
    int newNumer = this->denominator + this->numerator;
    setNumerator(newNumer);
    return curr;
}
Fraction& Fraction::operator--(){
    int newNumer = this->denominator - this->numerator;
    setNumerator(newNumer);
    return *this;
}
Fraction Fraction::operator--(int){
    Fraction curr(*this);
    int newNumer = this->denominator - this->numerator;
    setNumerator(newNumer);
    return curr;
}

void Fraction::reduce(){
    int gcd_value = gcd(numerator, denominator);
    numerator /= gcd_value;
    denominator /= gcd_value;
    // if (denominator < 0) {
    //     numerator *= -1;
    //     denominator *= -1;
    // }
    if(numerator < 0 && denominator < 0){
         numerator = abs(numerator);
         denominator = abs(denominator);
    }
    if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)){
        numerator = abs(numerator)*-1;
        denominator = abs(denominator);
    }
}

// bool checkOverFlow(){

// }
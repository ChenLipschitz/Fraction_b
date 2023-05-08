#pragma once
#include <iostream>

using namespace std;
namespace ariel{

    enum class Opr {
    Add,
    Sub,
    Mul,
    Div
};
    class Fraction{
        public:
        Fraction();
        Fraction(int numerator, int denominator);
        Fraction(float num);
        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator_);
        void setDenominator(int denominator_);
        
        //arithmetic operators: fraction operator fraction
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;

        //arithmetic operators: fraction operator float
        Fraction operator+(const float& other) const;
        Fraction operator-(const float& other) const;
        Fraction operator*(const float& other) const;
        Fraction operator/(const float& other) const;

        //arithmetic operators: float operator fraction
        friend Fraction operator + (const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num);
            int commonDen = fraction.lcm(fraction.getDenominator(), numAsAFraction.getDenominator());
            if (commonDen == 0){
                throw std::runtime_error("ERROR- The denominator cannot be 0");
            }
            int factor1 = commonDen / fraction.getDenominator();
            int factor2 = commonDen / numAsAFraction.getDenominator();
            int myExtendedNum = fraction.getNumerator()*factor1;
            int otherExtendedNum = numAsAFraction.getNumerator()*factor2;
            return Fraction(otherExtendedNum+myExtendedNum, commonDen);
        }
        friend Fraction operator - (const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num);
            int commonDen = fraction.lcm(fraction.getDenominator(), numAsAFraction.getDenominator());
            if (commonDen == 0){
                throw std::runtime_error("ERROR- The denominator cannot be 0");
            }
            int factor1 = commonDen / fraction.getDenominator();
            int factor2 = commonDen / numAsAFraction.getDenominator();
            int myExtendedNum = fraction.getNumerator()*factor1;
            int otherExtendedNum = numAsAFraction.getNumerator()*factor2;
            return Fraction(otherExtendedNum-myExtendedNum, commonDen);
        }
        friend Fraction operator * (const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num);
            int commonDen = fraction.getDenominator()*numAsAFraction.getDenominator();
            if (commonDen == 0){
                throw std::runtime_error("ERROR- The denominator cannot be 0");
            }
            int newNumerator = numAsAFraction.getNumerator()*fraction.getNumerator();
            return Fraction(newNumerator, commonDen);
        }
        friend Fraction operator / (const float& num, const Fraction& fraction) {
           Fraction numAsAFraction(num);
            int commonDen = numAsAFraction.getDenominator()*fraction.getNumerator();
            if (commonDen == 0){
                throw std::runtime_error("ERROR- The denominator cannot be 0");
            }
            int newNumerator = numAsAFraction.getNumerator()*fraction.getDenominator();
            return Fraction(newNumerator, commonDen);
        }
        
        //comparison operators: fraction operator fraction
        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        
        //comparison operators: float operator fraction
        friend bool operator==(const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num);
            if (numAsAFraction.getDenominator() == fraction.getDenominator()){
                if (numAsAFraction.getNumerator() == fraction.getNumerator()){
                    return true;
                }
            }
            return false;
        }
        friend bool operator!=(const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num);
            if (numAsAFraction.getDenominator() == fraction.getDenominator()){
                if (numAsAFraction.getNumerator() == fraction.getNumerator()){
                    return false;
                }
            }
            return true;
        }
        friend bool operator>(const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num);
            int commonDen = numAsAFraction.lcm(fraction.getDenominator(), numAsAFraction.getDenominator());
            int factor1 = commonDen / numAsAFraction.getDenominator();
            int factor2 = commonDen / fraction.getDenominator();
            int myExtendedNum = numAsAFraction.getNumerator()*factor1;
            int otherExtendedNum = fraction.getNumerator()*factor2;
            return myExtendedNum > otherExtendedNum;
        }
        friend bool operator>=(const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num);
            int commonDen = numAsAFraction.lcm(fraction.getDenominator(), numAsAFraction.getDenominator());
            int factor1 = commonDen / numAsAFraction.getDenominator();
            int factor2 = commonDen / fraction.getDenominator();
            int myExtendedNum = numAsAFraction.getNumerator()*factor1;
            int otherExtendedNum = fraction.getNumerator()*factor2;
            return myExtendedNum >= otherExtendedNum;
        }
        friend bool operator<(const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num);
            int commonDen = numAsAFraction.lcm(fraction.getDenominator(), numAsAFraction.getDenominator());
            int factor1 = commonDen / numAsAFraction.getDenominator();
            int factor2 = commonDen / fraction.getDenominator();
            int myExtendedNum = numAsAFraction.getNumerator()*factor1;
            int otherExtendedNum = fraction.getNumerator()*factor2;
            return myExtendedNum < otherExtendedNum;
        }
        friend bool operator<=(const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num);
            int commonDen = numAsAFraction.lcm(fraction.getDenominator(), numAsAFraction.getDenominator());
            int factor1 = commonDen / numAsAFraction.getDenominator();
            int factor2 = commonDen / fraction.getDenominator();
            int myExtendedNum = numAsAFraction.getNumerator()*factor1;
            int otherExtendedNum = fraction.getNumerator()*factor2;
            return myExtendedNum <= otherExtendedNum;
        }

        //increment and decrement methods
        Fraction& operator++();
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);

        //output/input objects to an/from ostream object
        friend ostream& operator<<(std::ostream& outputs, const Fraction& fraction){
            int gcd_value = fraction.gcd(fraction.getNumerator(), fraction.getDenominator());
            int numerator_ = fraction.getNumerator() / gcd_value;
            int denominator_ = fraction.getDenominator() / gcd_value;
            if(numerator_<0 && denominator_<0){
                numerator_ = abs(numerator_);
                denominator_ = abs(denominator_);
            }
            if((numerator_>0 && denominator_<0) || (numerator_<0 && denominator_>0)){
                numerator_ = abs(numerator_)*-1;
                denominator_ = abs(denominator_);
            }
            outputs << numerator_ << '/' << denominator_;
            return outputs;
        }
        friend istream& operator>>(std::istream& inputs, Fraction& fraction){
            int numerator_ = 0;
            int denominator_ = 0;
            inputs >> numerator_ >> denominator_;
            if(denominator_ == 0){
                throw runtime_error("ERROR- Denominator cannot be 0");
            }
            if (inputs.fail()) {
                throw runtime_error("ERROR- Invalid argument, stream must include two arguments");
            } 
            fraction.setNumerator(numerator_);
            fraction.setDenominator(denominator_);
            return inputs;
        }
        
        int gcd(int num1, int num2) const;
        int lcm(int num1, int num2) const;
        Fraction convertToFraction(float num);
        void reduce();
        void checkOverflow(Opr opr, const Fraction& other) const;

        private:
        int numerator;
        int denominator;
    };

}
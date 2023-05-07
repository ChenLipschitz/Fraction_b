#pragma once
#include <iostream>

using namespace std;
namespace ariel{
    class Fraction{
        public:
        Fraction();
        Fraction(int numerator, int denominator);
        Fraction(float num);
        Fraction(const Fraction& other);    //copy constructor
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
            Fraction numAsAFraction(num), copyFraction(fraction);
            int commonDen = copyFraction.lcm(copyFraction.getDenominator(), numAsAFraction.getDenominator());
            if (commonDen == 0){
                throw std::runtime_error("ERROR- The denominator cannot be 0");
            }
            int factor1 = commonDen / copyFraction.getDenominator();
            int factor2 = commonDen / numAsAFraction.getDenominator();
            int myExtendedNum = copyFraction.getNumerator()*factor1;
            int otherExtendedNum = numAsAFraction.getNumerator()*factor2;
            return Fraction(otherExtendedNum+myExtendedNum, commonDen);
        }
        friend Fraction operator - (const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num), copyFraction(fraction);
            int commonDen = copyFraction.lcm(copyFraction.getDenominator(), numAsAFraction.getDenominator());
            if (commonDen == 0){
                throw std::runtime_error("ERROR- The denominator cannot be 0");
            }
            int factor1 = commonDen / copyFraction.getDenominator();
            int factor2 = commonDen / numAsAFraction.getDenominator();
            int myExtendedNum = copyFraction.getNumerator()*factor1;
            int otherExtendedNum = numAsAFraction.getNumerator()*factor2;
            return Fraction(otherExtendedNum-myExtendedNum, commonDen);
        }
        friend Fraction operator * (const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num), copyFraction(fraction);
            int commonDen = copyFraction.getDenominator()*numAsAFraction.getDenominator();
            if (commonDen == 0){
                throw std::runtime_error("ERROR- The denominator cannot be 0");
            }
            int newNumerator = numAsAFraction.getNumerator()*copyFraction.getNumerator();
            return Fraction(newNumerator, commonDen);
        }
        friend Fraction operator / (const float& num, const Fraction& fraction) {
           Fraction numAsAFraction(num), copyFraction(fraction);
            int commonDen = copyFraction.getDenominator()*numAsAFraction.getNumerator();
            if (commonDen == 0){
                throw std::runtime_error("ERROR- The denominator cannot be 0");
            }
            int newNumerator = numAsAFraction.getNumerator()*copyFraction.getDenominator();
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
            Fraction numAsAFraction(num), copyFraction(fraction);
            if (numAsAFraction.getDenominator() == copyFraction.getDenominator()){
                if (numAsAFraction.getNumerator() == copyFraction.getNumerator()){
                    return true;
                }
            }
            return false;
        }
        friend bool operator!=(const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num), copyFraction(fraction);
            if (numAsAFraction.getDenominator() == copyFraction.getDenominator()){
                if (numAsAFraction.getNumerator() == copyFraction.getNumerator()){
                    return false;
                }
            }
            return true;
        }
        friend bool operator>(const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num), copyFraction(fraction);
            int commonDen = numAsAFraction.lcm(copyFraction.getDenominator(), numAsAFraction.getDenominator());
            int factor1 = commonDen / numAsAFraction.getDenominator();
            int factor2 = commonDen / copyFraction.getDenominator();
            int myExtendedNum = numAsAFraction.getNumerator()*factor1;
            int otherExtendedNum = copyFraction.getNumerator()*factor2;
            if (myExtendedNum > otherExtendedNum){
                return true;
            }
            return false;
        }
        friend bool operator>=(const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num), copyFraction(fraction);
            int commonDen = numAsAFraction.lcm(copyFraction.getDenominator(), numAsAFraction.getDenominator());
            int factor1 = commonDen / numAsAFraction.getDenominator();
            int factor2 = commonDen / copyFraction.getDenominator();
            int myExtendedNum = numAsAFraction.getNumerator()*factor1;
            int otherExtendedNum = copyFraction.getNumerator()*factor2;
            if (myExtendedNum >= otherExtendedNum){
                return true;
            }
            return false;
        }
        friend bool operator<(const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num), copyFraction(fraction);
            int commonDen = numAsAFraction.lcm(copyFraction.getDenominator(), numAsAFraction.getDenominator());
            int factor1 = commonDen / numAsAFraction.getDenominator();
            int factor2 = commonDen / copyFraction.getDenominator();
            int myExtendedNum = numAsAFraction.getNumerator()*factor1;
            int otherExtendedNum = copyFraction.getNumerator()*factor2;
            if (myExtendedNum < otherExtendedNum){
                return true;
            }
            return false;
        }
        friend bool operator<=(const float& num, const Fraction& fraction) {
            Fraction numAsAFraction(num), copyFraction(fraction);
            int commonDen = numAsAFraction.lcm(copyFraction.getDenominator(), numAsAFraction.getDenominator());
            int factor1 = commonDen / numAsAFraction.getDenominator();
            int factor2 = commonDen / copyFraction.getDenominator();
            int myExtendedNum = numAsAFraction.getNumerator()*factor1;
            int otherExtendedNum = copyFraction.getNumerator()*factor2;
            if (myExtendedNum <= otherExtendedNum){
                return true;
            }
            return false;
        }

        //increment and decrement methods
        Fraction& operator++();
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);

        //output/input objects to an/from ostream object
        //information for the following methods was taken from-
        //https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
        friend ostream& operator<<(std::ostream& os, const Fraction& fraction){
            os << fraction.getNumerator() << "/" << fraction.getDenominator();
            return os;
        }
        friend istream& operator>>(std::istream& is, const Fraction& fraction){
            return is;
        }
        
        int gcd(int num1, int num2) const;
        int lcm(int num1, int num2) const;
        Fraction convertToFraction(float num);
        void reduce();
        // void checkOverFlow();

        private:
        int numerator;
        int denominator;
    };

}
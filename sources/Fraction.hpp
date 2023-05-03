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
            return Fraction();
        }
        friend Fraction operator - (const float& num, const Fraction& fraction) {
            return Fraction();
        }
        friend Fraction operator * (const float& num, const Fraction& fraction) {
            return Fraction();
        }
        friend Fraction operator / (const float& num, const Fraction& fraction) {
            return Fraction();
        }
        
        //comparison operators
        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        
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
        
        int gcd(int num1, int num2);
        Fraction convertToFraction(float num);
        void reduce();

        private:
        int numerator;
        int denominator;
    };

}
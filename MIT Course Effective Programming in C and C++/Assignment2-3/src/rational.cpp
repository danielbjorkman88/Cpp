#include "rational.h"
#include "gcd.h"

#include <stdexcept>
#include <ostream>
#include <iostream>

using namespace std;

// Implement this
const Rational Rational::inverse() const {
    return Rational{ _den, _num };
  /* Return the Rational number 1 / current rational */
}

// Implement this
Rational::sign_type Rational::sign() const {

    Rational::sign_type sign;

    if (_num > 0 && _den > 0){
        sign = POSITIVE;
    }
    else if (_num < 0 && _den < 0){
        sign = POSITIVE;
    }
    else{
        sign = NEGATIVE;
    }

    return sign;
  /* Return, as a sign_type, the sign of the Rational */
}

/* Print the value num/den to the supplied output stream, or 0 if
 * the Rational happens to be identically zero.
 */
std::ostream& operator<<( std::ostream &os, const Rational &ratio ) {
  if( ratio == 0 ) {
    os << "0";
  } else {
    if( ratio.sign() == Rational::NEGATIVE ) {
      os << "-";
    }
    os << std::abs( ratio.num() ) << "/" << std::abs( ratio.den() );
  }
  return os;
}

/* This function will be called whenever the
 * Rational is constructed from integers that
 * are supplied as numerator and denominator.
 * It should reduce the fraction to lowest terms;
 * for example, when we try to construct a
 * Rational{ 4, -8 }, this is the function that
 * will cause the number to be exactly the same
 * as Rational{ -1, 2 }. Numerators should be
 * the only value potentially negative after
 * the call to ::normalize().
 * Throw bad_rational if there is an attempt
 * to set one with a zero denominator.
 */
void Rational::normalize() {
    if (_den == 0){
        throw bad_rational();
    }

    auto divider = gcd( abs(_num), abs(_den) );

    _num = _num/divider;
    _den = _den/divider;

      if( _den < 0 ) {
        _num = -_num;
        _den = -_den;
      }

  // You should implement
}

// Return the float precision number corresponding to the Rational
float Rational::to_float() const {

    float out = float(_num) / float(_den);

    return out;
  // You should implement
}

// Return the double precision number corresponding to the Rational
double Rational::to_double() const {

    double out = double(_num) / double(_den);


    return out;
  // You should implement
}

/*
 *  This file is part of the ZQNum bignum library and is distributed under the MIT licence.
 *  / Olle Eriksson 2018
 */

#ifndef Q_NUM_HEADER
#define Q_NUM_HEADER

#include <string>

#include "z.h"

namespace zqnum
{

/*!
 *  \brief  Q implements an arbitrary precision rational number.
 *
 *          The class Q implements an arbitrary precision rational number and provides basic
 *          relational and arithmetic operators for such numbers..
 */
class Q {

    public:

        /*!
         *  \brief  Constructs a rational number.
         *
         *          Constructs a rational number, initializing its value to 0.
         */
        Q();

        /*!
         *  \brief  Constructs a rational number from an integer.
         *
         *          Constructs a rational number, initializing its value to \p n.
         */
        Q( int n );

        /*!
         *  \brief  Constructs a rational number from two integers.
         *
         *          Constructs a rational number, initializing its value to \p num_ / \p den_.
         *          The denominator \p den_ must be nonzero.
         */
        Q( int num_, int den_ );

        /*!
         *  \brief  Constructs a rational number from a big integer.
         *
         *          Constructs a rational number, initializing its value to \p n.
         */
        Q( const Z& n );

        /*!
         *  \brief  Constructs a rational number from two big integers.
         *
         *          Constructs a rational number, initializing its value to \p num_ / \p den_.
         *          The denominator \p den_ must be nonzero.
         */
        Q( const Z& num_, const Z& den_ );

        /*!
         *  \brief  Constructs a rational number from a string.
         *
         *          Constructs a rational number from a string containing a base 10 decimal number,
         *          initializing its value to that of the string.
         *
         *   \param s A string containing a base 10 decimal number.
         */
        Q( const std::string& s );

        /*!
         *           Returns true if the number is equal to \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator==( const Q& rhs ) const;

        /*!
         *           Returns true if the number is not equal to \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator!=( const Q& rhs ) const;

        /*!
         *           Returns true if the number is less than \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator<( const Q& rhs ) const;

        /*!
         *           Returns true if the number is less than or equal to \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator<=( const Q& rhs ) const;

        /*!
         *           Returns true if the number is greater than \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator>( const Q& rhs ) const;

        /*!
         *           Returns true if the number is greater than or equal to \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator>=( const Q& rhs ) const;

        /*!
         *           Returns the sum of the number and \p rhs.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        Q operator+( const Q& rhs ) const;

        //!          Returns the negation of the number.
        Q operator-() const;

        /*!
         *           Returns the difference between the number and \p rhs.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        Q operator-( const Q& rhs ) const;

        /*!
         *           Returns the product of the integer and \p rhs.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        Q operator*( const Q& rhs ) const;

        /*!
         *           Returns the quotient of the integer and \p rhs.
         *
         *   \param  rhs The argument on the right-hand side of the operator (must be nonzero).
         */
        Q operator/( const Q& rhs ) const;

        /*!
         *   \brief  Returns a string containing the number.
         *
         *           Returns a string containing the number's numerator and denominator 
         *           (in canonical form) in base 10, separated by a '/'.
         */
        std::string toString() const;

        /*!
         *   \brief  Returns a string containing the number.
         *
         *           Returns a string containing a decimal representation of the number,
         *           rounded to \p decimal_places decimal places.
         */
        std::string toString( int decimal_places ) const;

        //!          Returns the number's numerator.
        Z numerator() const;

        //!          Returns the number's denominator.
        Z denominator() const;

    private:

        //!         The number's numerator.
        Z num;

        //!         The number's denominator.
        Z den;

        /*!
         *   \brief  Puts the number in canonical form.
         *
         *           Puts the number in canonical form, i.e. with \p num and \p den coprime and
         *           \p den nonnegative.
         */
        void normalize();

};

}

#endif

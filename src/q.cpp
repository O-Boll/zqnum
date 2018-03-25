/*
 *  This file is part of the ZQNum bignum library and is distributed under the MIT licence.
 *  / Olle Eriksson 2018
 */

#include <algorithm>
#include <iostream>

#include "q.h"

namespace zqnum
{

Q::Q()
{
    num = Z( 0 );
    den = Z( 1 );
}

Q::Q( int n )
{
    num = Z( n );
    den = Z( 1 );
}

Q::Q( int num_, int den_ )
{
    num = Z( num_ );
    den = Z( den_ );

    normalize();
}

Q::Q( const Z& n )
{
    num = n;
    den = Z( 1 );
}

Q::Q( const Z& num_, const Z& den_ )
{
    num = num_;
    den = den_;

    normalize();
}

Q::Q( const std::string& s )
{
    int k = s.find( '.' );

    if( k != std::string::npos )
    {
        std::string s_ = s;

        if( k == 0 || k == 1 && s[0] == '-' )
            s_.insert( k++, "0" );

        std::string nums = s_.substr( 0, k ) + s_.substr( k + 1 );
        std::string dens = "1" + std::string( s_.size() - k - 1, '0' );
        num = Z( nums );
        den = Z( dens );

    }
    else
    {
        num = Z( s );
        den = Z( 1 );
    }

    normalize();
}

bool Q::operator==( const Q& rhs ) const
{
    return num * rhs.den == rhs.num * den;
}

bool Q::operator!=( const Q& rhs ) const
{
    return !(*this == rhs);
}

bool Q::operator<( const Q& rhs ) const
{
    return num * rhs.den < rhs.num * den;
}

bool Q::operator<=( const Q& rhs ) const
{
    return !(*this > rhs);
}

bool Q::operator>( const Q& rhs ) const
{
    return rhs < *this;
}

bool Q::operator>=( const Q& rhs ) const
{
    return !(*this < rhs);
}

Q Q::operator+( const Q& rhs ) const
{
    Z num_ = num * rhs.den + rhs.num * den;
    Z den_ = den * rhs.den;

    return Q( num_, den_ );
}

Q Q::operator-() const
{
    return Q( -num, den );
}

Q Q::operator-( const Q& rhs ) const
{
    Z num_ = num * rhs.den - rhs.num * den;
    Z den_ = den * rhs.den;

    return Q( num_, den_ );
}

Q Q::operator*( const Q& rhs ) const
{
    Z num_ = num * rhs.num;
    Z den_ = den * rhs.den;

    return Q( num_, den_ );
}

Q Q::operator/( const Q& rhs ) const
{
    Z num_ = num * rhs.den;
    Z den_ = den * rhs.num;

    return Q( num_, den_ );
}

std::string Q::toString() const
{
    return num.toString() + "/" + den.toString();
}

std::string Q::toString( int decimal_places ) const
{
    /* add 1 to decimal_places to allow for rounding */
    Z mult_str( "1" + std::string( decimal_places + 1, '0' ) );
    Z n = num * Z( mult_str ) / den;

    bool negative = n < Z( 0 );

    Z ld = n % 10;

    if( !negative && ld >= Z( 5 ) )
    {
        n = n + Z( 10 );
    }
    else if( negative && Z( -9 ) <= ld && ld <= Z( -5 ) )
    {
        n = n - Z( 10 );
    }

    n = n / Z( 10 );

    std::string s = negative ? (-n).toString() : n.toString();
    std::string lzs( std::max(0, int( decimal_places - s.size() + 1) ), '0' );
    s = (negative ? "-" : "") + lzs + s;

    if( decimal_places != 0 )
    {
        s.insert( s.size() - decimal_places, "." );
    }

    return s;
}

Z Q::numerator() const
{
    return num;
}

Z Q::denominator() const
{
    return den;
}

void Q::normalize()
{
    if( den < Z(0) )
    {
        num = -num;
        den = -den;
    }

    Z gcd = Z::gcd( num, den );

    num = num / gcd;
    den = den / gcd;
}

}

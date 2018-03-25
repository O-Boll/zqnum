/*
 *  This file is part of the ZQNum bignum library and is distributed under the MIT licence.
 *  / Olle Eriksson 2018
 */

#ifndef ZQ_NUM_TESTS
#define ZQ_NUM_TESTS

#include <string>
#include <vector>
#include <utility>

#include "zqnum.h"

namespace zqnum
{

//!         Runs all tests for the classes Z and Q.
bool zqnumTests();

//!         Runs the tests in \p test_pointers under the heading \p test_name and prints the results.
bool runTests( const std::string& test_name,
               const std::vector<std::pair<std::string, bool> (*)(void)>& test_pointers );

//!         Returns a (uniformly distributed) random integer between \p min_ and \p max (inclusive).
int getRandNum( int min_, int max_ );

/*!
 *  \brief  Returns a string containing a random integer.
 *
 *          Returns a string containing a random integer with at most \p digits digits.
 */
std::string getRandStrNum( int digits );

/*!
 *  \brief  Returns a string containing a random nonzero integer.
 *
 *          Returns a string containing a random nonzero integer with at most \p digits digits.
 */
std::string getRandStrNumNonzero( int digits );

/*!
 *  \brief  Computes the next permutation.
 *
 *          Takes a permutation \p s  and changes it to the next permutationd 
 *          (in lexicographical order).
 *          This function is used to compute determinants of matrices in
 *          determinant(const std::vector<std::vector<Q>>& M).
 *
 *  \param  s A vector of containing the elements 1, 2,..., \p n.
 *
 *  \return The number of transpositions needed to change \p s into the next permutation.
 *          This value is used to determine the parity of permutations in
 *          determinant(const std::vector<std::vector<Q>>& M).
 */
int nextPermutation( std::vector<int>& s );

/*!
 *  \brief  Computes the determinant of the square matrix \p M.
 *
 *          Takes a square matrix \p M and computes its determinant.
 *          Computing determinants requires lots of arithmetic operations to be performed,
 *          and is thus useful for testing the correctness of a bignum library.
 *
 *  \param  M A vector of vectors that represents a matrix. Elements are indexed by row and
 *            column (in that order).
 *
 *  \return The determinant of \p M.
 */
Q determinant( const std::vector<std::vector<Q>>& M );

/*!
 *  \brief  Computes the inverse of a square matrix.
 *
 *          Takes a square matrix \p M and computes its inverse.
 *          Computing matrix inverses requires lots of arithmetic operations to be performed,
 *          and is thus useful for testing the correctness of a bignum library.
 *
 *  \param  M A vector of vectors that represents a matrix. Elements are indexed by row and
 *            column (in that order).
 *
 *  \return The inverse of \p M.
 */
std::vector<std::vector<Q>> mInverse( std::vector<std::vector<Q>> M );

/*!
 *  \brief  Constructs a Cauchy matrix from two vectors of rational numbers.
 *
 *          Constructs a Cauchy matrix of order \p n from two vectors of length \p n of rational numbers.
 *          There exist simple formulas for computing the determinants and inverses of Cauchy matrices.
 *          This makes them useful for testing the correctness of the implementation of the arithmetic
 *          operations on Q, as different formulas can be used to compute numbers that are then compared
 *          to each other.
 *
 *  \param  x A vector of distinct rational numbers. Must be the same length as \p y.
 *  \param  y A vector of distinct rational numbers. Must be the same length as \p x.
 *
 *  \return A Cauchy matrix of order \p n, where \p n is the size of \p x and \p y.
 */
std::vector<std::vector<Q>> cauchyMatrix( const std::vector<Q>& x, const std::vector<Q>& y );

/*!
 *  \brief  Computes element of the inverse of a Cauchy matrix.
 *
 *          Computes the element at row \p i and column \p j of the inverse of the Cauchy matrix
 *          defined by the two vectors \p x and \p y.
 *
 *  \param  x A vector of distinct rational numbers. Must be the same length as \p y.
 *  \param  y A vector of distinct rational numbers. Must be the same length as \p x.
 *  \param  i A zero-based row index.
 *  \param  j A zero-based column index.
 *
 *  \return The element at row \p i and column \p j of the inverse of the Cauchy matrix
 *          defined by \p x and \p y.
 */
Q cauchyMatrixInvCoef( const std::vector<Q>& x, const std::vector<Q>& y, int i, int j );

/*!
 *  \brief  Computes the determinant of a Cauchy matrix.
 *
 *          Computes the determinant of the Cauchy matrix defined by the two vectors \p x and \p y.
 *
 *  \param  x A vector of distinct rational numbers. Must be the same length as \p y.
 *  \param  y A vector of distinct rational numbers. Must be the same length as \p x.
 *
 *  \return The determinant of the Cauchy matrix defined by \p x and \p y
 */
Q cauchyMatrixDeterminant( const std::vector<Q>& x, const std::vector<Q>& y );

//! Tests Z::Z(const string& s) and Z::toString().
std::pair<std::string, bool> zTestConstructor_01();
//! Tests Z::Z(int n) and Z::toString().
std::pair<std::string, bool> zTestConstructor_02();
//! Tests Z::operator==(const Z& rhs).
std::pair<std::string, bool> zTestEqual_01();
//! Tests Z::operator==(const Z& rhs).
std::pair<std::string, bool> zTestEqual_02();
//! Tests Z::operator!=(const Z& rhs).
std::pair<std::string, bool> zTestNotEqual_01();
//! Tests Z::operator!=(const Z& rhs).
std::pair<std::string, bool> zTestNotEqual_02();
//! Tests Z::operator<(const Z& rhs).
std::pair<std::string, bool> zTestLessThan_01();
//! Tests Z::operator<(const Z& rhs).
std::pair<std::string, bool> zTestLessThan_02();
//! Tests Z::operator<=(const Z& rhs).
std::pair<std::string, bool> zTestLessThanOrEqual_01();
//! Tests Z::operator<=(const Z& rhs).
std::pair<std::string, bool> zTestLessThanOrEqual_02();
//! Tests Z::operator>(const Z& rhs).
std::pair<std::string, bool> zTestGreaterThan_01();
//! Tests Z::operator>(const Z& rhs).
std::pair<std::string, bool> zTestGreaterThan_02();
//! Tests Z::operator>=(const Z& rhs).
std::pair<std::string, bool> zTestGreaterThanOrEqual_01();
//! Tests Z::operator>=(const Z& rhs).
std::pair<std::string, bool> zTestGreaterThanOrEqual_02();
//! Tests Z::operator+(const Z& rhs).
std::pair<std::string, bool> zTestAddition_01();
//! Tests Z::operator+(const Z& rhs).
std::pair<std::string, bool> zTestAddition_02();
//! Tests Z::operator-(const Z& rhs).
std::pair<std::string, bool> zTestSubtraction_01();
//! Tests Z::operator-(const Z& rhs).
std::pair<std::string, bool> zTestSubtraction_02();
//! Tests Z::operator*(const Z& rhs).
std::pair<std::string, bool> zTestMultiplication_01();
//! Tests Z::operator*(const Z& rhs).
std::pair<std::string, bool> zTestMultiplication_02();
//! Tests Z::operator/(const Z& rhs).
std::pair<std::string, bool> zTestDivision_01();
//! Tests Z::operator/(const Z& rhs).
std::pair<std::string, bool> zTestDivision_02();
//! Tests Z::operator%(const Z& rhs).
std::pair<std::string, bool> zTestModulus_01();
//! Tests Z::operator%(const Z& rhs).
std::pair<std::string, bool> zTestModulus_02();
//! Tests Z::operator-().
std::pair<std::string, bool> zTestNegation_01();
//! Tests addition, subtraction and multiplication by computing the 1000th Fibonacci number.
std::pair<std::string, bool> zTestFibonacci();
//! Tests multiplication by computing 1000!.
std::pair<std::string, bool> zTestFactorial();

//! Tests Q::Q(const Z& num_, const Z& den_) and Q::toString(int decimal_places).
std::pair<std::string, bool> qTestConstructor_01();
//! Tests Q::Q(const std::string& s) and Q::toString(int n).
std::pair<std::string, bool> qTestConstructor_02();
//! Tests Q::operator==(const Q& rhs).
std::pair<std::string, bool> qTestEqual_01();
//! Tests Q::operator==(const Q& rhs).
std::pair<std::string, bool> qTestEqual_02();
//! Tests Q::operator==(const Q& rhs).
std::pair<std::string, bool> qTestEqual_03();
//! Tests Q::operator!=(const Q& rhs).
std::pair<std::string, bool> qTestNotEqual_01();
//! Tests Q::operator<(const Q& rhs).
std::pair<std::string, bool> qTestLessThan_01();
//! Tests Q::operator<=(const Q& rhs).
std::pair<std::string, bool> qTestLessThanOrEqual_01();
//! Tests Q::operator>(const Q& rhs).
std::pair<std::string, bool> qTestGreaterThan_01();
//! Tests Q::operator>=(const Q& rhs).
std::pair<std::string, bool> qTestGreaterThanOrEqual_01();
//! Tests Q::operator+(const Q& rhs).
std::pair<std::string, bool> qTestAddition_01();
//! Tests Q::operator-(const Q& rhs).
std::pair<std::string, bool> qTestSubtraction_01();
//! Tests Q::operator*(const Q& rhs).
std::pair<std::string, bool> qTestMultiplication_01();
//! Tests Q::operator/(const Q& rhs).
std::pair<std::string, bool> qTestDivision_01();
//! Tests Q::operator/(const Q& rhs).
std::pair<std::string, bool> qTestDivision_02();
//! Tests Q::operator-().
std::pair<std::string, bool> qTestNegation_01();
//! Tests arithmetic on Q by computing inverses of Cauchy matrices.
std::pair<std::string, bool> qTestCauchy_01();
//! Tests arithmetic on Q by computing determinants of Cauchy matrices.
std::pair<std::string, bool> qTestCauchy_02();

}

#endif

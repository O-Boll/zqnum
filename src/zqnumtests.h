#ifndef ZQ_NUM_TESTS
#define ZQ_NUM_TESTS

#include <string>
#include <vector>
#include <utility>

#include "zqnum.h"

namespace zqnum {

bool zqnumTests();

bool zTests(std::vector<std::pair<std::string, bool> (*)(void)>& test_pointers);

bool qTests(std::vector<std::pair<std::string, bool> (*)(void)>& test_pointers);


int getRandNum(int, int);

std::string getRandStrNum(int);

std::string getRandStrNumNonzero(int);


int nextPermutation(std::vector<int>& s);

Q determinant(std::vector<std::vector<Q>>&);

std::vector<std::vector<Q>> mInverse(std::vector<std::vector<Q>>);

std::vector<std::vector<Q>> cauchyMatrix(const std::vector<Q>&, const std::vector<Q>&);

Q cauchyMatrixCoefficient(const std::vector<Q>&, const std::vector<Q>&, int, int);

Q cauchyMatrixDeterminant(const std::vector<Q>&, const std::vector<Q>&);


std::pair<std::string, bool> zTestConstructor_01();

std::pair<std::string, bool> zTestConstructor_02();

std::pair<std::string, bool> zTestEqual_01();

std::pair<std::string, bool> zTestEqual_02();

std::pair<std::string, bool> zTestNotEqual_01();

std::pair<std::string, bool> zTestNotEqual_02();

std::pair<std::string, bool> zTestLessThan_01();

std::pair<std::string, bool> zTestLessThan_02();

std::pair<std::string, bool> zTestLessThanOrEqual_01();

std::pair<std::string, bool> zTestLessThanOrEqual_02();

std::pair<std::string, bool> zTestGreaterThan_01();

std::pair<std::string, bool> zTestGreaterThan_02();

std::pair<std::string, bool> zTestGreaterThanOrEqual_01();

std::pair<std::string, bool> zTestGreaterThanOrEqual_02();

std::pair<std::string, bool> zTestAddition_01();

std::pair<std::string, bool> zTestAddition_02();

std::pair<std::string, bool> zTestSubtraction_01();

std::pair<std::string, bool> zTestSubtraction_02();

std::pair<std::string, bool> zTestMultiplication_01();

std::pair<std::string, bool> zTestMultiplication_02();

std::pair<std::string, bool> zTestDivision_01();

std::pair<std::string, bool> zTestDivision_02();

std::pair<std::string, bool> zTestModulus_01();

std::pair<std::string, bool> zTestModulus_02();

std::pair<std::string, bool> zTestNegation_01();

std::pair<std::string, bool> zTestFibonacci();

std::pair<std::string, bool> zTestFactorial();


std::pair<std::string, bool> qTestConstructor_01();

std::pair<std::string, bool> qTestConstructor_02();

std::pair<std::string, bool> qTestEqual_01();

std::pair<std::string, bool> qTestEqual_02();

std::pair<std::string, bool> qTestEqual_03();

std::pair<std::string, bool> qTestNotEqual_01();

std::pair<std::string, bool> qTestLessThan_01();

std::pair<std::string, bool> qTestLessThanOrEqual_01();

std::pair<std::string, bool> qTestGreaterThan_01();

std::pair<std::string, bool> qTestGreaterThanOrEqual_01();

std::pair<std::string, bool> qTestAddition_01();

std::pair<std::string, bool> qTestSubtraction_01();

std::pair<std::string, bool> qTestMultiplication_01();

std::pair<std::string, bool> qTestDivision_01();

std::pair<std::string, bool> qTestDivision_02();

std::pair<std::string, bool> qTestNegation_01();

std::pair<std::string, bool> qTestCauchy_01();

std::pair<std::string, bool> qTestCauchy_02();

}

#endif

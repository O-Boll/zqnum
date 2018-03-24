#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

#define TTMATH_DONT_USE_WCHAR 1
#include <ttmath.h>

#include "zqnum.h"
#include "zqnumtests.h"

namespace zqnum {

bool zqnumTests() {

    using namespace std::chrono;

    std::vector<std::pair<std::string, bool> (*)(void)> z_test_pointers;
    z_test_pointers.push_back(zTestConstructor_01);
    z_test_pointers.push_back(zTestConstructor_02);
    z_test_pointers.push_back(zTestEqual_01);
    z_test_pointers.push_back(zTestEqual_02);
    z_test_pointers.push_back(zTestNotEqual_01);
    z_test_pointers.push_back(zTestNotEqual_02);
    z_test_pointers.push_back(zTestLessThan_01);
    z_test_pointers.push_back(zTestLessThan_02);
    z_test_pointers.push_back(zTestLessThanOrEqual_01);
    z_test_pointers.push_back(zTestLessThanOrEqual_02);
    z_test_pointers.push_back(zTestGreaterThan_01);
    z_test_pointers.push_back(zTestGreaterThan_02);
    z_test_pointers.push_back(zTestGreaterThanOrEqual_01);
    z_test_pointers.push_back(zTestGreaterThanOrEqual_02);
    z_test_pointers.push_back(zTestAddition_01);
    z_test_pointers.push_back(zTestAddition_02);
    z_test_pointers.push_back(zTestSubtraction_01);
    z_test_pointers.push_back(zTestSubtraction_02);
    z_test_pointers.push_back(zTestMultiplication_01);
    z_test_pointers.push_back(zTestMultiplication_02);
    z_test_pointers.push_back(zTestDivision_01);
    z_test_pointers.push_back(zTestDivision_02);
    z_test_pointers.push_back(zTestModulus_01);
    z_test_pointers.push_back(zTestModulus_02);
    z_test_pointers.push_back(zTestNegation_01);
    z_test_pointers.push_back(zTestFibonacci);
    z_test_pointers.push_back(zTestFactorial);

    bool z_passed = zTests(z_test_pointers);

    std::cout << std::endl;

    std::vector<std::pair<std::string, bool> (*)(void)> q_test_pointers;
    q_test_pointers.push_back(qTestConstructor_01);
    q_test_pointers.push_back(qTestConstructor_02);
    q_test_pointers.push_back(qTestEqual_01);
    q_test_pointers.push_back(qTestEqual_02);
    q_test_pointers.push_back(qTestEqual_03);
    q_test_pointers.push_back(qTestNotEqual_01);
    q_test_pointers.push_back(qTestLessThan_01);
    q_test_pointers.push_back(qTestLessThanOrEqual_01);
    q_test_pointers.push_back(qTestGreaterThan_01);
    q_test_pointers.push_back(qTestGreaterThanOrEqual_01);
    q_test_pointers.push_back(qTestAddition_01);
    q_test_pointers.push_back(qTestSubtraction_01);
    q_test_pointers.push_back(qTestMultiplication_01);
    q_test_pointers.push_back(qTestDivision_01);
    q_test_pointers.push_back(qTestDivision_02);
    q_test_pointers.push_back(qTestNegation_01);
    q_test_pointers.push_back(qTestCauchy_01);
    q_test_pointers.push_back(qTestCauchy_02);

    bool q_passed = qTests(q_test_pointers);

    std::cout << std::endl << std::string(16, '=');
    std::cout << " SUMMARY ";
    std::cout << std::string(16, '=') << std::endl << std::endl;
    std::cout << std::string(2, ' ');
    if(z_passed && q_passed)
    {
        std::cout << "[PASS]";
    }
    else
    {
        std::cout << "[FAIL]";
    }
    std::cout << std::endl;
}

bool zTests(std::vector<std::pair<std::string, bool> (*)(void)>& test_pointers) {
    std::cout << std::string(16, '=');
    std::cout << " TESTING CLASS Z ";
    std::cout << std::string(16, '=') << std::endl;
    std::cout << std::endl;
    int test_counter = 1;
    int pass_counter = 0;
    double total_time = 0.0;
    for(auto fnptr : test_pointers)
    {
        using namespace std::chrono;
        auto t0 = high_resolution_clock::now();
        std::pair<std::string, bool> test_result = fnptr();
        auto t1 = high_resolution_clock::now();
        duration<double> time = duration_cast<duration<double>>(t1 - t0);
        std::cout << std::string(2, ' ');
        std::cout << "[" << (test_result.second ? "PASS" : "FAIL") << "]";
        std::cout << "  |  ";
        std::cout << test_result.first;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << " (" << time.count() << " s)";
        std::cout << std::endl;
        test_counter++;
        if(test_result.second)
            pass_counter++;
        total_time += time.count();
    }
    std::cout << std::endl;
    std::cout << std::string(2, ' ');
    std::cout << "SUMMARY: ";
    std::cout << pass_counter << " of " << test_pointers.size() << " tests passed in ";
    std::cout << std::fixed << std::setprecision(2) << total_time << " seconds.";
    std::cout << std::endl;
}

bool qTests(std::vector<std::pair<std::string, bool> (*)(void)>& test_pointers) {
    std::cout << std::string(16, '=');
    std::cout << " TESTING CLASS Q ";
    std::cout << std::string(16, '=') << std::endl;
    std::cout << std::endl;
    int test_counter = 1;
    int pass_counter = 0;
    double total_time = 0.0;
    for(auto fnptr : test_pointers)
    {
        using namespace std::chrono;
        auto t0 = high_resolution_clock::now();
        std::pair<std::string, bool> test_result = fnptr();
        auto t1 = high_resolution_clock::now();
        duration<double> time = duration_cast<duration<double>>(t1 - t0);
        std::cout << std::string(2, ' ');
        std::cout << "[" << (test_result.second ? "PASS" : "FAIL") << "]";
        std::cout << "  |  ";
        std::cout << test_result.first;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << " (" << time.count() << " s)";
        std::cout << std::endl;
        if(test_result.second)
            pass_counter++;
        total_time += time.count();
    }
    std::cout << std::endl;
    std::cout << std::string(2, ' ');
    std::cout << "SUMMARY: ";
    std::cout << pass_counter << " of " << test_pointers.size() << " tests passed in ";
    std::cout << std::fixed << std::setprecision(2) << total_time << " seconds.";
    std::cout << std::endl;
}

int getRandNum(int min_, int max_)
{
    static std::mt19937 generator(clock());
    std::uniform_int_distribution<int> rand_int(min_, max_);
    return rand_int(generator);
}

std::string getRandStrNum(int digits)
{
    static std::mt19937 generator(clock());
    std::uniform_int_distribution<int> sign_dist(0, 1);
    std::uniform_int_distribution<int> digit_dist(0, 9);
    std::string nums;
    nums.reserve(digits + 1);
    if(sign_dist(generator))
        nums.push_back('-');
    bool leading_zero = true;
    for(int i = 0; i < digits; i++)
    {
        char digit = digit_dist(generator) + '0';
        if(digit != '0')
        {
          leading_zero = false;
          nums.push_back(digit);
        }
        else if(!(digit == '0' && leading_zero) || i == digits - 1)
          nums.push_back(digit);
    }
    if(nums == "-0")
        nums = "0";
    return nums;
}

std::string getRandStrNumNonzero(int digits)
{
    std::string nums;
    do
    {
        nums = getRandStrNum(digits);
    } while(nums == "0");
    return nums;
}

}

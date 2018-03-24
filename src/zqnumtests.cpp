#include <iomanip>
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

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

int nextPermutation(std::vector<int>& s)
{
    int i, k, l, transpositions = 0;
    for(i = s.size() - 2; !(s[i] < s[i + 1]) && i >= 0; i--);
    if(i >= 0)
    {
        for(k = s.size() - 1; !(s[i] < s[k]); k--);
        int temp = s[i];
        s[i] = s[k];
        s[k] = temp;
        transpositions++;
        for(l = 0; l < (s.size() - i - 1) / 2; l++)
        {
            temp = s[i + 1 + l];
            s[i + 1 + l] = s[s.size() - 1 - l];
            s[s.size() - 1 - l] = temp;
            transpositions++;
        }
    }
    return transpositions;
}

Q determinant(std::vector<std::vector<Q>>& M)
{
    int d = M.size(), transpositions = 0, t;
    std::vector<int> s(d);
    for(int i = 0; i < d; i++)
        s[i] = i;
    Q det(0);
    do {
        int sgn = transpositions % 2 ? -1 : 1;
        Q term(1);
        for(int i = 0; i < d; i++)
            term = term * M[i][s[i]];
        det = det + Q(sgn) * term;
        t = nextPermutation(s);
        transpositions += t;
    } while(t);
    return det;
}

std::vector<std::vector<Q>> mInverse(std::vector<std::vector<Q>> M)
{
    int d = M.size();

    /* construct identity matrix that will become M's inverse */
    std::vector<std::vector<Q>> I(d, std::vector<Q>(d, Q(0)));
    for(int i = 0; i < d; i++)
        I[i][i] = Q(1);

    /* row-reduce */
    for(int c = 0; c < d; c++)
    {
        /* find nonzero pivot and perform row swap */
        for(int r = c; r < d; r++)
            if(M[r][c] != Q(0))
            {
                auto temp = M[c];
                M[c] = M[r];
                M[r] = temp;

                temp = I[c];
                I[c] = I[r];
                I[r] = temp;
            }

        /* normalize row c sow that pivot is 1 */
        auto m = M[c][c];
        for(int k = 0; k < d; k++)
        {
            M[c][k] = M[c][k] / m;
            I[c][k] = I[c][k] / m;
        }

        /* subtract multiples of row c from the rows below */
        for(int r = c + 1; r < d; r++)
        {
            m = M[r][c];
            for(int k = 0; k < d; k++)
            {
                M[r][k] = M[r][k] - M[c][k] * m;
                I[r][k] = I[r][k] - I[c][k] * m;
            }
        }
    }

    /* back-substitute */
    for(int c = d - 1; c >= 0; c--)
    {
        for(int r = c - 1; r >= 0; r--)
        {
            auto m = M[r][c];
            for(int k = 0; k < d; k++)
            {
                M[r][k] = M[r][k] - M[c][k] * m;
                I[r][k] = I[r][k] - I[c][k] * m;
            }
        }
    }
    return I;
}

std::vector<std::vector<Q>> cauchyMatrix(const std::vector<Q>& x, const std::vector<Q>& y)
{
    int d = x.size();
    std::vector<std::vector<Q>> M(d, std::vector<Q>(d, Q(0)));
    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            M[i][j] = Q(1) / (x[i] + y[j]);
    return M;
}

Q cauchyMatrixCoefficient(const std::vector<Q>& x, const std::vector<Q>& y, int i, int j)
{
    int d = x.size();
    Q a(1);
    for(int k = 0; k < d; k++)
        a = a * ( (x[j] + y[k]) * (x[k] + y[i]) );
    Q b = x[j] + y[i];
    for(int k = 0; k < d; k++)
    {
        if(k != j)
            b = b * (x[j] - x[k]);
        if(k != i)
            b = b * (y[i] - y[k]);
    }
    return a / b;
}

Q cauchyMatrixDeterminant(const std::vector<Q>& x, const std::vector<Q>& y)
{
    int d = x.size();
    Q a(1);
    for(int i = 0; i < d; i++)
        for(int j = i + 1; j < d; j++)
            a = a * (x[j] - x[i]) * (y[j] - y[i]);
    Q b(1);
    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            b = b * (x[i] + y[j]);
    return a / b;
}

}

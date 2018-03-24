#include "zqnum.h"
#include "zqnumtests.h"

namespace zqnum {

std::pair<std::string, bool> qTestConstructor_01()
{
    std::string test_name = "Testing Q::Q(const Z&, const Z&) and Q::toString(int).";
    bool pass = true;
    for(int i = 1; i <= 100; i++)
    {
        std::string s0p9 = "0.9" + std::string(i, '9');
        zqnum::Q q0p9(s0p9);
        std::string sp9 = ".9" + std::string(i, '9');
        zqnum::Q qp9(sp9);
        std::string sm0p9 = "-0.9" + std::string(i, '9');
        zqnum::Q qm0p9(sm0p9);
        std::string smp9 = "-.9" + std::string(i, '9');
        zqnum::Q qmp9(smp9);
        if(     q0p9.toString(0) !=  "1"
            ||   qp9.toString(0) !=  "1"
            || qm0p9.toString(0) != "-1"
            ||  qmp9.toString(0) != "-1" )
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestConstructor_02()
{
    std::string test_name = "Testing Q::Q(const std::string&) and Q::toString(int).";
    bool pass = true;
    zqnum::Q a(Z("200000000000000000000"), Z(3));
    zqnum::Q b(Z("-200000000000000000000"), Z(3));
    zqnum::Q c(Z(-17), Z(-13));
    zqnum::Q d(Z(17), Z(-13));
    zqnum::Q e(Z(1), Z(3));
    zqnum::Q f(Z(-1), Z(3));
    if(     a.toString(3 ) != "66666666666666666666.667"
        ||  b.toString(3 ) != "-66666666666666666666.667"
        ||  c.toString(26) != "1.30769230769230769230769231"
        ||  d.toString(26) != "-1.30769230769230769230769231"
        ||  e.toString(50) != "0.33333333333333333333333333333333333333333333333333"
        ||  f.toString(1 ) != "-0.3" )
    {
        pass = false;
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestEqual_01()
{
    std::string test_name = "Testing Q::operator==(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        std::string sc = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z a(sa), b(sb), c(sc);
        zqnum::Q q(a, b), r(a * c, b * c);
        if(!(q == r))
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestEqual_02()
{
    std::string test_name = "Testing Q::operator==(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        std::string sc = getRandStrNum(getRandNum(1, 100));
        std::string sd = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z a(sa);
        zqnum::Z b(sb);
        zqnum::Z c(sc);
        zqnum::Z d(sd);
        zqnum::Q q(a, b), r(c, d);
        if((q == r) != (a * d == b * c) )
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestEqual_03()
{
    std::string test_name = "Testing Q::operator==(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sn = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z n(sn);
        zqnum::Q q(n, n), r(1, 1);
        if(q != r)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestNotEqual_01()
{
    std::string test_name = "Testing Q::operator!=(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        std::string sc = getRandStrNumNonzero(getRandNum(1, 100));
        std::string sd = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z a(sa), b(sb), c(sc), d(sd);
        zqnum::Q q(a, b), r(c, d);
        if(q != q || !(q + r != q))
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestLessThan_01()
{
    std::string test_name = "Testing Q::operator<(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z a(sa), b(sb);
        zqnum::Q q(a, b);
        if(q < q || !(q - Q(1, 1) < q))
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestLessThanOrEqual_01()
{
    std::string test_name = "Testing Q::operator<=(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z a(sa), b(sb);
        zqnum::Q q(a, b);
        if(q + Q(1, 1) <= q || !(q <= q))
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestGreaterThan_01()
{
    std::string test_name = "Testing Q::operator>(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z a(sa), b(sb);
        zqnum::Q q(a, b);
        if(q > q || !(q + Q(1, 1) > q))
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestGreaterThanOrEqual_01()
{
    std::string test_name = "Testing Q::operator>=(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z a(sa), b(sb);
        zqnum::Q q(a, b);
        if(q - Q(1, 1) >= q || !(q >= q))
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestAddition_01()
{
    std::string test_name = "Testing Q::operator+(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        std::string sc = getRandStrNum(getRandNum(1, 100));
        zqnum::Z a(sa);
        zqnum::Z b(sb);
        zqnum::Z c(sc);
        zqnum::Q q(a, b), r(c, b), s(a + c, b);
        if(q + r != s)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestSubtraction_01()
{
    std::string test_name = "Testing Q::operator-(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        std::string sc = getRandStrNum(getRandNum(1, 100));
        zqnum::Z a(sa);
        zqnum::Z b(sb);
        zqnum::Z c(sc);
        zqnum::Q q(a, b), r(c, b), s(a - c, b);
        if(q - r != s)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestMultiplication_01()
{
    std::string test_name = "Testing Q::operator*(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        std::string sc = getRandStrNum(getRandNum(1, 100));
        std::string sd = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z a(sa);
        zqnum::Z b(sb);
        zqnum::Z c(sc);
        zqnum::Z d(sd);
        zqnum::Q q(a, b), r(c, d), s(a * c, b * d);
        if(q * r != s)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestDivision_01()
{
    std::string test_name = "Testing Q::operator/(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        std::string sc = getRandStrNumNonzero(getRandNum(1, 100));
        std::string sd = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z a(sa);
        zqnum::Z b(sb);
        zqnum::Z c(sc);
        zqnum::Z d(sd);
        zqnum::Q q(a, b), r(c, d), s(a * d, b * c);
        if(q / r != s)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestDivision_02()
{
    std::string test_name = "Testing Q::operator/(const Q&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNumNonzero(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z a(sa);
        zqnum::Z b(sb);
        zqnum::Q q(a, b);
        if(q / Q(1, 1) != q || q / q != Q(1, 1))
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestNegation_01()
{
    std::string test_name = "Testing Q::operator-().";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string sa = getRandStrNum(getRandNum(1, 100));
        std::string sb = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z a(sa);
        zqnum::Z b(sb);
        zqnum::Q q(a, b), r(-a, b), s(a, -b);
        if(-q != r || -q != s || q + (-q) != Q(0, 1) || q * Q(-1,1) != -q)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestCauchy_01()
{
    std::string test_name = "Computing inverses of Cauchy matrices.";
    bool pass = true;
    for(int d = 1; d <= 20; d++)
    {
        std::vector<zqnum::Q> x;
        for(int i = 0; i < d; i++)
            x.push_back(i + 1);
        auto M = cauchyMatrix(x, x);
        auto I = mInverse(M);
        for(int i = 0; i < d; i++)
            for(int j = 0; j < d; j++)
            {
                auto e = zqnum::cauchyMatrixCoefficient(x, x, i, j);
                if(e != I[i][j])
                {
                    pass = false;
                    goto quit_test;
                }
            }
    }
    quit_test:
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> qTestCauchy_02()
{
    std::string test_name = "Computing determinants of Cauchy matrices.";
    bool pass = true;
    for(int d = 1; d <= 8; d++)
    {
        std::vector<zqnum::Q> x;
        for(int i = 0; i < d; i++)
            x.push_back(i + 1);
        auto M = cauchyMatrix(x, x);
        Q detA = determinant(M);
        Q detB = cauchyMatrixDeterminant(x, x);
        if(detA != detB)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

}

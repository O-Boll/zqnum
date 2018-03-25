/*
 *  This file is part of the ZQNum bignum library and is distributed under the MIT licence.
 *  / Olle Eriksson 2018
 */

#include <algorithm>

#include "z.h"

namespace zqnum
{

Z::Z()
{
    sign = '+';
}

Z::Z(int n)
{
    sign = n < 0 ? '-' : '+';
    mwuint.push_back(n < 0 ? -n : n);
    trimlz();
}

Z::Z(const std::string& s)
{
    int i = 0, chunk_size = 5;
    sign = '+';
    if(s[i] == '-')
    {
        sign = '-';
        i++;
    }
    Z n(0);
    while(i < s.length())
    {
        std::string subs = s.substr(i, chunk_size);
        int m = 0;
        int e = 1;
        for(int j = 0; j < subs.length(); j++, e *= 10)
            m = 10 * m + subs[j] - '0';
        n = n * Z(e) + Z(m);
        i += chunk_size;
    }
    mwuint = n.mwuint;
    trimlz();
}

bool Z::operator==(const Z& rhs) const
{
    if(sign != rhs.sign)
        return false;
    return ueq(*this, rhs);
}

bool Z::operator!=(const Z& rhs) const
{
  return !(*this == rhs);
}

bool Z::operator<(const Z& rhs) const
{
    if(sign == rhs.sign)
    {
        if(sign == '+')
            return ult(*this, rhs);
        return ult(rhs, *this);
    }
    else if(sign == '-')
        return true;
    return false;
}

bool Z::operator<=(const Z& rhs) const
{
    return !(rhs < *this);
}

bool Z::operator>(const Z& lhs) const
{
    return lhs < *this;
}

bool Z::operator>=(const Z& lhs) const
{
    return !(*this < lhs);
}

Z Z::operator+(const Z& rhs) const
{
    Z sum;
    if(sign == rhs.sign)
    {
        uadd(*this, rhs, sum);
        sum.sign = sign;
    }
    else if(ult(*this, rhs))
    {
          usub(rhs, *this, sum);
          sum.sign = rhs.sign;
    }
    else
    {
          usub(*this, rhs, sum);
          sum.sign = sign;
    }
    sum.trimlz();
    return sum;
}

Z Z::operator-() const
{
    if(*this == Z(0))
        return Z(0);
    Z add_inv = *this;
    add_inv.sign = add_inv.sign == '+' ? '-' : '+';
    return add_inv;
}

Z Z::operator-(const Z& rhs) const
{
    Z difference;
    if(sign != rhs.sign)
    {
        uadd(*this, rhs, difference);
        difference.sign = sign;
    }
    else if(ult(*this, rhs))
    {
        usub(rhs, *this, difference);
        difference.sign = sign == '+' ? '-' : '+';
    }
    else
    {
        usub(*this, rhs, difference);
        difference.sign = sign;
    }
    difference.trimlz();
    return difference;
}

Z Z::operator*(const Z& rhs) const
{
    Z product;
    umul(*this, rhs, product);
    if(sign != rhs.sign && product != Z(0))
        product.sign = '-';
    return product;
}

Z Z::operator/(const Z& rhs) const
{
    Z quotient, remainder;
    udiv(*this, rhs, quotient, remainder);
    if(sign != rhs.sign && quotient != Z(0))
        quotient.sign = '-';
    return quotient;
}

Z Z::operator%(const Z& rhs) const
{
    Z quotient, remainder;
    udiv(*this, rhs, quotient, remainder);
    if(remainder != Z(0))
        remainder.sign = sign;
    return remainder;
}

Z Z::gcd(Z a, Z b)
{
    while(b != Z(0))
    {
       Z q, r, t;
       udiv(a, b, q, r);
       t = b;
       b = r;
       a = t;
    }
    a.sign = '+';
    return a;
}

std::string Z::toString() const
{
    std::string s;
    if(*this == 0)
        s = "0";
    else
    {
        if(sign == '-')
            s.push_back('-');
        std::vector<int> digits;
        Z n = *this;
        while(n != Z(0))
        {
            Z quot, remainder;
            udiv(n, 10000, quot, remainder);
            n = quot;
            int r = remainder[0];
            for(int i = 0; i < 4; i++, r /= 10)
                digits.push_back(r % 10);
        }
        int i = digits.size() - 1;
        for(; digits[i] == 0; i--);
        for(; i >= 0; i--)
            s.push_back(digits[i] + '0');
    }
    return s;
}

uint32_t Z::operator[](int i) const
{
    return i >= mwuint.size() ? 0 : mwuint[i];
}

uint32_t& Z::operator[](int i)
{
    return mwuint[i];
}

void Z::trimlz() {

    while(!mwuint.empty() && !mwuint.back())
        mwuint.pop_back();

    if(mwuint.empty())
    {
        sign = '+';
        mwuint.push_back(0);
    }
}

bool Z::ueq(const Z& lhs, const Z& rhs)
{
    if(lhs.mwuint.size() != rhs.mwuint.size())
        return false;

    for(int i = 0; i < lhs.mwuint.size(); i++)
        if(lhs[i] != rhs[i])
            return false;

    return true;
}

bool Z::ult(const Z& lhs, const Z& rhs)
{
    if(lhs.mwuint.size() != rhs.mwuint.size())
        return  lhs.mwuint.size() < rhs.mwuint.size();

    for(int i = lhs.mwuint.size() - 1; i >= 0; i--)
        if(lhs[i] != rhs[i])
            return lhs[i] < rhs[i];

    return false;
}

void Z::uadd(const Z& lhs, const Z& rhs, Z& sum)
{
    uint64_t carryover = 0;
    int sum_size = std::max(lhs.mwuint.size(), rhs.mwuint.size());
    sum.mwuint.reserve(sum_size);

    for(int i = 0; i < sum_size; i++)
    {
        uint64_t psum = uint64_t(lhs[i]) + uint64_t(rhs[i]) + carryover;
        carryover = 0;
        if(psum > UINT32_MAX)
        {
            psum -= UINT32_MAX + 1;
            carryover = 1;
        }
        sum.mwuint.push_back(psum);
    }

    if(carryover > 0)
        sum.mwuint.push_back(1);

    sum.trimlz();
}

void Z::usub(const Z& lhs, const Z& rhs, Z& difference)
{
    int64_t carryover = 0;
    difference.mwuint.reserve(lhs.mwuint.size());

    for(int i = 0; i < lhs.mwuint.size(); i++) {
        int64_t pdif = int64_t(lhs[i]) - int64_t(rhs[i]) - carryover;
        carryover = 0;
        if(pdif < 0)
        {
            pdif += UINT32_MAX + 1;
            carryover = 1;
        }
        difference.mwuint.push_back(pdif);
    }
    if(carryover)
        difference.mwuint.push_back(1);
    difference.trimlz();
}

void Z::umul(const Z& lhs, const Z& rhs, Z& product)
{
    int m = lhs.mwuint.size();
    int n = rhs.mwuint.size();
    product.mwuint.resize(m + n, 0);
    uint64_t k, t, b;
    for(int i = 0; i < n; i++)
    {
        k = 0;
        for(int j = 0; j < m; j++)
        {
            t = uint64_t(lhs[j]) * uint64_t(rhs[i]) + uint64_t(product[i + j]) + k;
            product[i + j] = uint32_t(t);
            k = t >> 32;
        }
        product.mwuint[i + m] = k;
    }
    product.trimlz();
}

void Z::udiv(const Z& lhs, const Z& rhs, Z& quotient, Z& remainder)
{
    int m, n, s;
    m = lhs.mwuint.size();
    n = rhs.mwuint.size();

    quotient.mwuint.resize(m, 0);

    std::vector<uint32_t> ln, rn;
    int64_t t, k;
    uint64_t qhat, rhat, p, b;
    b = uint64_t(UINT32_MAX) + 1;

    if(m < n)
    {
        quotient = Z(0);
        remainder = lhs;
    }
    else if(n == 1)
    {
        k = 0;
        for(int i = m - 1; i >= 0; i--)
        {
            quotient[i] = (k * b + lhs[i]) / rhs[0];
            k = k * b + lhs[i] - quotient[i] * rhs[0];
        }
        remainder.mwuint.push_back(uint32_t(k));
    }
    else
    {
        s = __builtin_clzll(rhs[n - 1]) - 32;
        rn.resize(2 * n);
        for(int i = n - 1; i > 0; i--)
            rn[i] = uint64_t(rhs[i]) << s | uint64_t(rhs[i - 1]) >> 32 - s;
        rn[0] = uint64_t(rhs[0]) << s;

        ln.resize(2 * (m + 1));
        ln[m] = uint64_t(lhs[m - 1]) >> 32 - s;
        for(int i = m - 1; i > 0; i--)
            ln[i] = uint64_t(lhs[i]) << s | uint64_t(lhs[i - 1]) >> 32 - s;
        ln[0] = uint64_t(lhs[0]) << s;

        for(int j = m - n; j >= 0; j--)
        {
            qhat = (ln[j + n] * b + ln[j + n - 1]) / rn[n - 1];
            rhat =  ln[j + n] * b + ln[j + n - 1]  - qhat * rn[n - 1];

            again:
            if(qhat >= b || qhat * rn[n - 2] > b * rhat + ln[j + n - 2])
            {
                qhat -= 1;
                rhat = rhat + rn[n - 1];
                if(rhat < b)
                    goto again;
            }

            k = 0;
            for(int i = 0; i < n; i++)
            {
                p = qhat * rn[i];
                t = ln[i + j] - k - (p & 0xffffffff);
                ln[i + j] = t;
                k = (p >> 32) - (t >> 32);
            }
            t = ln[j + n] - k;
            ln[j + n] = t;

            quotient[j] = qhat;
            if(t < 0)
            {
                quotient[j] -= 1;
                k = 0;
                for(int i = 0; i < n; i++)
                {
                    t = uint64_t(ln[i + j]) + uint64_t(rn[i]) + k;
                    ln[i + j] = t;
                    k = t >> 32;
                }
                ln[j + n] = ln[j + n] + k;
            }
        }
        for(int i = 0; i < n; ++i)
            remainder.mwuint.push_back(   uint64_t(ln[i]) >> s
                                        | uint64_t(ln[i + 1]) << 32 - s);
    }
    quotient.trimlz();
    remainder.trimlz();
}

}

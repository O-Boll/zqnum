#include <vector>
#include <iostream>
#include "zqnum.h"
#include "zqnumtests.h"

namespace zqnum {

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

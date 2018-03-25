/*
 *  This file is part of the ZQNum bignum library and is distributed under the MIT licence.
 *  / Olle Eriksson 2018
 */

#ifndef Z_NUM_HEADER
#define Z_NUM_HEADER

#include <cstdint>
#include <string>
#include <vector>

namespace zqnum {

/*!
 *  \brief  Z implements a big integer.
 *
 *          The class Z implements a big integer as a multi-word unsigned integer along with a sign,
 *          and provides basic relational and arithmetic operators for such integers.
 */
class Z
{

    public:

        /*!
         *  \brief  Constructs a big integer.
         *
         *          Constructs a big integer, initializing its value to 0.
         */
        Z();

        /*!
         *   \brief  Constructs a big integer from an int.
         *
         *           Constructs a big integer, initializing its value to \p n.
         */
        Z(int n);

        /*!
         *   \brief  Constructs a big integer from a string.
         *
         *           Constructs a big integer from a string representing a base 10 integer.
         *
         *   \param s A string containing a base 10 integer.
         */
        Z(const std::string& s);

        /*!
         *           Returns true if the integer is equal to \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator==(const Z& rhs) const;

        /*!
         *           Returns true if the integer is not equal to \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator!=(const Z& rhs) const;

        /*!
         *           Returns true if the integer is less than \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator< (const Z& rhs) const;

        /*!
         *           Returns true if the integer is less than or equal to \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator<=(const Z& rhs) const;

        /*!
         *           Returns true if the integer is greter than \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator> (const Z& rhs) const;

        /*!
         *           Returns true if the integer is greater than or equal to \p rhs, false otherwise.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        bool operator>=(const Z& rhs) const;

        /*!
         *           Returns the sum of the integer and \p rhs.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        Z operator+(const Z& rhs) const;

        /*!
         *           Returns the negation of the integer.
         */
        Z operator-() const;

        /*!
         *           Returns the difference between the integer and \p rhs.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        Z operator-(const Z& rhs) const;

        /*!
         *           Returns the product of the integer and \p rhs.
         *
         *   \param  rhs The argument on the right-hand side of the operator.
         */
        Z operator*(const Z& rhs) const;

        /*!
         *           Returns the quotient of the integer and \p rhs (using integer division).
         *
         *   \param  rhs The argument on the right-hand side of the operator (must be nonzero).
         */
        Z operator/(const Z& rhs) const;

        /*!
         *           Returns the remainder after division of the integer by \p rhs.
         *           The return value has the same sign as the dividend.
         *
         *   \param  rhs The argument on the right-hand side of the operator (must be nonzero).
         */
        Z operator%(const Z& rhs) const;

        /*!
         *   \brief  Greatest common divisor.
         *
         *           Returns the greatest common divisor of \p a and \p b.
         *           Both arguments must not be 0.
         */
        static Z gcd(Z a, Z b);

        /*!
         *           Returns a string containing the integer in base 10 format.
         */
        std::string toString() const;

    private:

        /*!
         *   \brief  The sign of the integer.
         *
         *           The sign of the integer, which is either '+' or '-'.
         */
        char sign;

        /*!
         *   \brief  Multi-word unsigned integer.
         *
         *           A vector that contains a multi-word unsigned integer that represents
         *           the integer (modulo the sign).
         */
        std::vector<uint32_t> mwuint;

        /*!
         *           Returns the element at position \p i of #mwuint if it exists, otherwise 0.
         *
         *   \param  i Non-negative index variable.
         */
        uint32_t operator[](int i) const;

        /*!
         *           Returns a reference the element at position \p i of #mwuint.
         *
         *   \param  i Non-negative index variable.
         */
        uint32_t& operator[](int i);

        /*!
         *   \brief  Trim leading zeros.
         *
         *           Removes zero-elements from the back of #mwuint until the first nonzero-element
         *           is encountered or until only one element is left. If #mwuint contains a single
         *           element after this, and this element is 0, then #sign is set to '+', in accordance
         *           with our convention that 0 has positive sign.
         */
        void trimlz();

        /*!
         *   \brief  Unsigned equal.
         *
         *           Compares \p lhs and \p rhs as if they were both non-negative. Returns true if
         *           the absolute value of \p lhs equals the absolute value of \p rhs.
         *           This method is used in the implementations of some of the relational operators on Z.
         */
        static bool ueq(const Z& lhs, const Z& rhs);

        /*!
         *   \brief  Unsigned less than.
         *
         *           Compares \p lhs and \p rhs as if they were both non-negative. Returns true if
         *           the absolute value of \p lhs is less than the absolute value of \p rhs.
         *           This method is used in the implementations of some of the relational operators on Z.
         */
        static bool ult(const Z& lhs, const Z& rhs);

        /*!
         *   \brief  Unsigned addition.
         *
         *           Adds the absolute values of \p lhs and \p rhs and stores the result in \p sum.
         *           This method is used in the implementations of the addition and subtraction operators on Z.
         */
        static void uadd(const Z& lhs, const Z& rhs, Z& sum);

        /*!
         *   \brief  Unsigned subtraction.
         *
         *           Subtracts the absolute value of \p rhs from \p lhs and stores the result in \p difference.
         *           It is required that the absolute value of \p lhs is greater than or equal to the absolute
         *           value of \p rhs.
         *           This method is used in the implementations of the addition and subtraction operators on Z.
         */
        static void usub(const Z& lhs, const Z& rhs, Z& difference);

        /*!
         *   \brief  Unsigned multiplication.
         *
         *           Multiplies the absolute values of \p lhs and \p rhs and stores the result in \p product.
         *           This method is used in the implementation of the multiplication operator on Z.
         */
        static void umul(const Z& lhs, const Z& rhs, Z& product);

        /*!
         *   \brief  Unsigned integer division.
         *
         *           Divides the absolute value of \p lhs by the absolute value of and \p rhs and stores
         *           the quotient in \p quotient and the remainder in \p remainder.
         *           This method is used in the implementation of the division and modulo operators on Z.
         */
        static void udiv(const Z& lhs, const Z& rhs, Z& quotient, Z& remainder);

};

}

#endif

#ifndef Z_NUM_HEADER
#define Z_NUM_HEADER

#include <cstdint>
#include <string>
#include <vector>

namespace zqnum {

class Z
{

    public:

        Z();
        Z(int);
        Z(const std::string&);

        bool operator==(const Z&) const;
        bool operator!=(const Z&) const;
        bool operator< (const Z&) const;
        bool operator<=(const Z&) const;
        bool operator> (const Z&) const;
        bool operator>=(const Z&) const;

        Z operator+(const Z&) const;
        Z operator-() const;
        Z operator-(const Z&) const;
        Z operator*(const Z&) const;
        Z operator/(const Z&) const;
        Z operator%(const Z&) const;

        static Z gcd(Z, Z);

        std::string toString() const;

    private:

        char sign;
        std::vector<uint32_t> mwuint;

        uint32_t operator[](int) const;
        uint32_t& operator[](int);

        void trimlz();

        static bool ueq(const Z&, const Z&);
        static bool ult(const Z&, const Z&);

        static void uadd(const Z&, const Z&, Z&);
        static void usub(const Z&, const Z&, Z&);
        static void umul(const Z&, const Z&, Z&);
        static void udiv(const Z&, const Z&, Z&, Z&);

};

}

#endif

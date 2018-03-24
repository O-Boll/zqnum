#ifndef Q_NUM_HEADER
#define Q_NUM_HEADER

#include <string>

#include "z.h"

namespace zqnum {

class Q {

    public:

        Q();
        Q(int);
        Q(int, int);
        Q(const Z&);
        Q(const Z&, const Z&);
        Q(const std::string&);

        bool operator==(const Q&) const;
        bool operator!=(const Q&) const;
        bool operator< (const Q&) const;
        bool operator<=(const Q&) const;
        bool operator> (const Q&) const;
        bool operator>=(const Q&) const;

        Q operator+(const Q&) const;
        Q operator-() const;
        Q operator-(const Q&) const;
        Q operator*(const Q&) const;
        Q operator/(const Q&) const;

        std::string toString() const;
        std::string toString(int) const;

        Z numerator() const;
        Z denominator() const;

    private:

        Z num, den;

        void normalize();

};

}

#endif

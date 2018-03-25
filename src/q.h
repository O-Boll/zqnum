#ifndef Q_NUM_HEADER
#define Q_NUM_HEADER

#include <string>

#include "z.h"

namespace zqnum {

/**
 * A constructor.
 * A more elaborate description of the constructor.
 */
class Q {

    public:

        /**
         * A constructor.
         * Constructs a Z.
         */
        Q();

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Q(int);

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Q(int, int);

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Q(const Z&);

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Q(const Z&, const Z&);

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Q(const std::string&);

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        bool operator==(const Q&) const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        bool operator!=(const Q&) const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        bool operator< (const Q&) const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        bool operator<=(const Q&) const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        bool operator> (const Q&) const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        bool operator>=(const Q&) const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Q operator+(const Q&) const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Q operator-() const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Q operator-(const Q&) const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Q operator*(const Q&) const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Q operator/(const Q&) const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        std::string toString() const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        std::string toString(int) const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Z numerator() const;

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */
        Z denominator() const;

    private:

        Z num, den;

        void normalize();

};

}

#endif

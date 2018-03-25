/*
 *  This file is part of the ZQNum bignum library and is distributed under the MIT licence.
 *  / Olle Eriksson 2018
 */

#include <limits>

#define TTMATH_DONT_USE_WCHAR 1 /* Remove this line on 32-bit architectures. */
#include <ttmath/ttmath.h>

#include "zqnum.h"
#include "zqnumtests.h"

namespace zqnum
{

std::pair<std::string, bool> zTestConstructor_01()
{
    std::string test_name = "Testing Z::Z( const string& s ) and Z::toString().";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {

        /* From string to Z and back to string. Strings should be identical. */

        std::string snum_1 = getRandStrNum( i );
        zqnum::Z n( snum_1 );
        std::string snum_2 = n.toString();

        if( snum_1 != snum_2 )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestConstructor_02()
{
    std::string test_name = "Testing Z::Z( int n ) and Z::toString().";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        int n = getRandNum( std::numeric_limits<int>::min(), std::numeric_limits<int>::max() );

        std::string snum_1 = std::to_string( n );
        zqnum::Z m( snum_1 );
        std::string snum_2 = m.toString();

        if( snum_1 != snum_2 )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestEqual_01()
{
    std::string test_name = "Testing Z::operator==( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string snum_1 = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n( snum_1 );

        if( !(n == n) )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestEqual_02()
{
    std::string test_name = "Testing Z::operator==( const Z& ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string snum_1 = getRandStrNum( getRandNum( 1, 100 ) );
        std::string snum_2 = getRandStrNum( getRandNum( 1, 100 ) );

        while( snum_1 == snum_2 )
            snum_2 = getRandStrNum( getRandNum( 1, 100 ) );

        zqnum::Z n( snum_1 );
        zqnum::Z m( snum_2 );

        if( n == m )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestNotEqual_01()
{
    std::string test_name = "Testing Z::operator!=( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string snum_1 = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n( snum_1 );

        if( n != n )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestNotEqual_02()
{
    std::string test_name = "Testing Z::operator!=( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string snum_1 = getRandStrNum( getRandNum( 1, 100 ) );
        std::string snum_2 = getRandStrNum( getRandNum( 1, 100 ) );

        while( snum_1 == snum_2 )
            snum_2 = getRandStrNum( getRandNum( 1, 100 ) );

        zqnum::Z n( snum_1 );
        zqnum::Z m( snum_2 );

        if( !(n != m) )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestLessThan_01()
{
    std::string test_name = "Testing Z::operator<( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string snum_1 = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n( snum_1 );
        zqnum::Z m = n - Z( 1 );

        if( n < n || !(m < n) )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestLessThan_02()
{
    std::string test_name = "Testing Z::operator<( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string as = getRandStrNum( getRandNum( 1, 100 ) );
        std::string bs = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z za( as ), zb( bs );

        bool z_lt = za < zb;

        ttmath::Int<200>  tta( as );
        ttmath::Int<200>  ttb( bs );

        bool tt_lt = tta < ttb;

        if( z_lt != tt_lt )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestLessThanOrEqual_01()
{
    std::string test_name = "Testing Z::operator<=( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string snum_1 = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n( snum_1 );
        zqnum::Z m = n + Z( 1 );
        zqnum::Z o = n - Z( 1 );

        if( !(o <= n) || !(n <= n) || m <= n )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestLessThanOrEqual_02()
{
    std::string test_name = "Testing Z::operator<=( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string as = getRandStrNum( getRandNum( 1, 100 ) );
        std::string bs = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z za( as ), zb( bs );

        bool z_lt = za <= zb;

        ttmath::Int<200>  tta( as );
        ttmath::Int<200>  ttb( bs );

        bool tt_lt = tta <= ttb;

        if( z_lt != tt_lt )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestGreaterThan_01()
{
    std::string test_name = "Testing Z::operator>( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string snum_1 = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n( snum_1 );
        zqnum::Z m = n + Z( 1 );

        if( n > n || !(m > n) )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestGreaterThan_02()
{
    std::string test_name = "Testing Z::operator>( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string as = getRandStrNum( getRandNum( 1, 100 ) );
        std::string bs = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z za( as ), zb( bs );

        bool z_lt = za > zb;

        ttmath::Int<200>  tta( as );
        ttmath::Int<200>  ttb( bs );

        bool tt_lt = tta > ttb;

        if( z_lt != tt_lt )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestGreaterThanOrEqual_01()
{
    std::string test_name = "Testing Z::operator>=( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string snum_1 = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n( snum_1 );
        zqnum::Z m = n + Z( 1 );
        zqnum::Z o = n - Z( 1 );

        if( !(m >= n) || !(n >= n) || o >= n )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestGreaterThanOrEqual_02()
{
    std::string test_name = "Testing Z::operator>=( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string as = getRandStrNum( getRandNum( 1, 100 ) );
        std::string bs = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z za(as), zb(bs);

        bool z_lt = za >= zb;

        ttmath::Int<200>  tta( as );
        ttmath::Int<200>  ttb( bs );

        bool tt_lt = tta >= ttb;

        if( z_lt != tt_lt )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestAddition_01()
{
    std::string test_name = "Testing Z::operator+( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string as = getRandStrNum( getRandNum( 1, 100 ) );
        std::string bs = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z za( as ), zb( bs );
        zqnum::Z zc = za + zb;

        std::string zcs = zc.toString();

        ttmath::Int<200> tta( as ), ttb( bs );
        ttmath::Int<200> ttc = tta + ttb;

        std::string ttcs = ttc.ToString();

        if(zcs != ttcs)
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestAddition_02()
{
    std::string test_name = "Testing Z::operator+( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string ns = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n( ns );

        if( n + Z( 0 ) != n )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestSubtraction_01()
{
    std::string test_name = "Testing Z::operator-( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string as = getRandStrNum( getRandNum( 1, 100 ) );
        std::string bs = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z za( as ), zb( bs );
        zqnum::Z zc = za - zb;

        std::string zcs = zc.toString();

        ttmath::Int<200> tta( as ), ttb( bs );
        ttmath::Int<200> ttc = tta - ttb;

        std::string ttcs = ttc.ToString();

        if( zcs != ttcs )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestSubtraction_02()
{
    std::string test_name = "Testing Z::operator-( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string ns = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n( ns );

        if( n - Z( 0 ) != n )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestMultiplication_01()
{
    std::string test_name = "Testing Z::operator*(const Z& rhs).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string as = getRandStrNum( getRandNum( 1, 50 ) );
        std::string bs = getRandStrNum( getRandNum( 1, 50 ) );
        zqnum::Z za( as ), zb( bs );
        zqnum::Z zc = za * zb;

        std::string zcs = zc.toString();

        ttmath::Int<200> tta( as ), ttb( bs );
        ttmath::Int<200> ttc = tta * ttb;

        std::string ttcs = ttc.ToString();

        if( zcs != ttcs )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestMultiplication_02()
{
    std::string test_name = "Testing Z::operator*( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string ns = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n( ns );

        if( n * Z( 0 ) != Z( 0 ) || n * Z( 1 ) != n )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestDivision_01()
{
    std::string test_name = "Testing Z::operator/( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string as = getRandStrNum       ( getRandNum( 1, 100 ) );
        std::string bs = getRandStrNumNonzero( getRandNum( 1, 100 ) );

        zqnum::Z za( as ), zb( bs );
        zqnum::Z zc = za / zb;

        std::string zcs = zc.toString();

        ttmath::Int<200> tta( as ), ttb( bs );
        ttmath::Int<200>  ttc = tta / ttb;

        std::string ttcs = ttc.ToString();

        if( zcs != ttcs )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestDivision_02()
{
    std::string test_name = "Testing Z::operator/( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string ns = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n(ns);

        if( n / Z( 1 ) != n || (n != Z( 0 ) && n / n != Z( 1 )) )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestModulus_01()
{
    std::string test_name = "Testing Z::operator%( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string as = getRandStrNum       ( getRandNum( 1, 100 ) );
        std::string bs = getRandStrNumNonzero( getRandNum( 1, 100 ) );

        zqnum::Z za( as ), zb( bs );
        zqnum::Z zc = za % zb;

        std::string zcs = zc.toString();

        ttmath::Int<200> tta( as ), ttb( bs );
        ttmath::Int<200> ttc = tta % ttb;

        std::string ttcs = ttc.ToString();

        if( zcs != ttcs )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestModulus_02()
{
    std::string test_name = "Testing Z::operator%( const Z& rhs ).";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string ns = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n( ns );

        if( n % Z( 1 ) != Z( 0 ) || (n != Z( 0 ) && n % n != Z( 0 )) )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestNegation_01()
{
    std::string test_name = "Testing Z::operator-().";
    bool pass = true;

    for( int i = 1; i <= 1000; i++ )
    {
        std::string ns = getRandStrNum( getRandNum( 1, 100 ) );
        zqnum::Z n( ns );

        if( n + (-n) != Z( 0 ) || n - (-n) != Z( 2 ) * n || -n != Z( -1 ) * n )
        {
            pass = false;
            break;
        }
    }

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestFibonacci()
{
    std::string test_name = "Computing the 1000th Fibonacci number.";
    bool pass = true;

    /* 1000th Fibonacci number. */
    std::string fibonacci_1000 = "4346655768693745643568852767504062580256466051737178040248172908"
        "95365554179490518904038798400792551692959225930803226347752096896232398733224711616429964"
        "40906533187938298969649928516003704476137795166849228875";

    /* Computing 1000th Fibonacci number 'manually' should yield the same result. */
    zqnum::Z a( 1 ), b( 0 );
    for( int i = 2; i <= 1000; i++ )
    {
        a = a + b;
        b = a - b;
    }

    if( a.toString() != fibonacci_1000 )
        pass = false;

    return std::make_pair( test_name, pass );
}

std::pair<std::string, bool> zTestFactorial()
{
    std::string test_name = "Computing the factorial of 1000.";
    bool pass = true;

    /* Factorial of 1000. */
    std::string factorial_1000 = "4023872600770937735437024339230039857193748642107146325437999104"
        "29938512398629020592044208486969404800479988610197196058631666872994808558901323829669944"
        "59099742450408707375991882362772718873251977950595099527612087497546249704360141827809464"
        "64962910563938874378864873371191810458257836478499770124766328898359557354325131853239584"
        "63075557409114262417474349347553428646576611667797396668820291207379143853719588249808126"
        "86783837455973174613608537953452422158659320192809087829730843139284440328123155861103697"
        "68013573042161687476096758713483120254785893207671691324484262361314125087802080002616831"
        "51027341827977704784635868170164365024153691398281264810213092761244896359928705114964975"
        "41990934222156683257208082133318611681155361583654698404670897560290095053761647584772842"
        "18896796462449451607653534081989013854424879849599533191017233555566021394503997362807501"
        "37837615307127761926849034352625200015888535147331611702103968175921510907788019393178114"
        "19454525722386554146106289218796022383897147608850627686296714667469756291123408243920816"
        "01537808898939645182632436716167621791689097799119037540312746222899880051954444142820121"
        "87361745992642956581746628302955570299024324153181617210465832036786906117260158783520751"
        "51628422554026517048330422614397428693306169089796848259012545832716822645806652676995865"
        "26822728070757813918581788896522081643483448259932660433676601769996128318607883861502794"
        "65955131156552036093988180612138558600301435694527224206344631797460594682573103790084024"
        "43243846565724501440282188525247093519062092902313649327349756551395872055965422874977401"
        "14133469627154228458623773875382304838656889764619273838149001407673104466402598994902222"
        "21765904339901886018566526485061799702356193897017860040811889729918311021171229845901641"
        "92106888438712185564612496079872290851929681937238864261483965738229112312502418664935314"
        "39701374285319266498753372189406942814341185201580141233448280150513996942901534830776445"
        "69099073152433278288269864602789864321139083506217095002597389863554277196742822248757586"
        "76575234422020757363056949882508796892816275384886339690995982628095612145099487170124451"
        "64612603790293091208890869420285106401821543994571568059418727489980942547421735824010636"
        "77404595741785160829230135358081840096996372524230560855903700624271243416909004153690105"
        "93398383577793941097002775347200000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        "000000000000";

    /* Computing factorial of 1000 'manually' should yield the same result. */
    zqnum::Z n( 1 );
    for( int i = 2; i <= 1000; i++ )
        n = n * Z( i );

    if( n.toString() != factorial_1000 )
        pass = false;

    return std::make_pair( test_name, pass );
}

}

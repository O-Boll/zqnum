#include <limits>

#define TTMATH_DONT_USE_WCHAR 1
#include <ttmath.h>

#include "zqnum.h"
#include "zqnumtests.h"

namespace zqnum {

std::pair<std::string, bool> zTestConstructor_01()
{
    std::string test_name = "Testing Z::Z(string) and Z::toString().";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string snum_1 = getRandStrNum(i);
        zqnum::Z n(snum_1);
        std::string snum_2 = n.toString();
        if(snum_1 != snum_2)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestConstructor_02()
{
    std::string test_name = "Testing Z::Z(int) and Z::toString().";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        int n = getRandNum(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        std::string snum_1 = std::to_string(n);
        zqnum::Z m(snum_1);
        std::string snum_2 = m.toString();
        if(snum_1 != snum_2)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestEqual_01()
{
    std::string test_name = "Testing Z::operator==(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string snum_1 = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(snum_1);
        if(!(n == n))
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestEqual_02()
{
    std::string test_name = "Testing Z::operator==(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string snum_1 = getRandStrNum(getRandNum(1, 100));
        std::string snum_2 = getRandStrNum(getRandNum(1, 100));
        while(snum_1 == snum_2)
            snum_2 = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(snum_1);
        zqnum::Z m(snum_2);
        if(n == m)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestNotEqual_01()
{
    std::string test_name = "Testing Z::operator!=(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string snum_1 = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(snum_1);
        if(n != n)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestNotEqual_02()
{
    std::string test_name = "Testing Z::operator!=(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string snum_1 = getRandStrNum(getRandNum(1, 100));
        std::string snum_2 = getRandStrNum(getRandNum(1, 100));
        while(snum_1 == snum_2)
            snum_2 = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(snum_1);
        zqnum::Z m(snum_2);
        if(!(n != m))
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestLessThan_01()
{
    std::string test_name = "Testing Z::operator<(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string snum_1 = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(snum_1);
        zqnum::Z m = n - Z(1);
        if( n < n || !(m < n) )
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestLessThan_02()
{
    std::string test_name = "Testing Z::operator<(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string as = getRandStrNum(getRandNum(1, 100));
        std::string bs = getRandStrNum(getRandNum(1, 100));
        zqnum::Z za(as);
        zqnum::Z zb(bs);
        bool z_lt = za < zb;
        ttmath::Int<200>  tta(as);
        ttmath::Int<200>  ttb(bs);
        bool tt_lt = tta < ttb;
        if(z_lt != tt_lt)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestLessThanOrEqual_01()
{
    std::string test_name = "Testing Z::operator<=(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string snum_1 = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(snum_1);
        zqnum::Z m = n + Z(1);
        zqnum::Z o = n - Z(1);
        if( !(o <= n) || !(n <= n) || m <= n )
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestLessThanOrEqual_02()
{
    std::string test_name = "Testing Z::operator<=(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string as = getRandStrNum(getRandNum(1, 100));
        std::string bs = getRandStrNum(getRandNum(1, 100));
        zqnum::Z za(as);
        zqnum::Z zb(bs);
        bool z_lt = za <= zb;
        ttmath::Int<200>  tta(as);
        ttmath::Int<200>  ttb(bs);
        bool tt_lt = tta <= ttb;
        if(z_lt != tt_lt)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestGreaterThan_01()
{
    std::string test_name = "Testing Z::operator>(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string snum_1 = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(snum_1);
        zqnum::Z m = n + Z(1);
        if( n > n || !(m > n) )
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestGreaterThan_02()
{
    std::string test_name = "Testing Z::operator>(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string as = getRandStrNum(getRandNum(1, 100));
        std::string bs = getRandStrNum(getRandNum(1, 100));
        zqnum::Z za(as);
        zqnum::Z zb(bs);
        bool z_lt = za > zb;
        ttmath::Int<200>  tta(as);
        ttmath::Int<200>  ttb(bs);
        bool tt_lt = tta > ttb;
        if(z_lt != tt_lt)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestGreaterThanOrEqual_01()
{
    std::string test_name = "Testing Z::operator>=(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string snum_1 = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(snum_1);
        zqnum::Z m = n + Z(1);
        zqnum::Z o = n - Z(1);
        if( !(m >= n) || !(n >= n) || o >= n )
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestGreaterThanOrEqual_02()
{
    std::string test_name = "Testing Z::operator>=(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string as = getRandStrNum(getRandNum(1, 100));
        std::string bs = getRandStrNum(getRandNum(1, 100));
        zqnum::Z za(as);
        zqnum::Z zb(bs);
        bool z_lt = za >= zb;
        ttmath::Int<200>  tta(as);
        ttmath::Int<200>  ttb(bs);
        bool tt_lt = tta >= ttb;
        if(z_lt != tt_lt)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestAddition_01()
{
    std::string test_name = "Testing Z::operator+(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string as = getRandStrNum(getRandNum(1, 100));
        std::string bs = getRandStrNum(getRandNum(1, 100));
        zqnum::Z za(as);
        zqnum::Z zb(bs);
        zqnum::Z zc = za + zb;
        std::string zcs = zc.toString();
        ttmath::Int<200>  tta(as);
        ttmath::Int<200>  ttb(bs);
        ttmath::Int<200>  ttc = tta + ttb;
        std::string ttcs = ttc.ToString();
        if(zcs != ttcs)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestAddition_02()
{
    std::string test_name = "Testing Z::operator+(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string ns = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(ns);
        if(n + Z(0) != n)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestSubtraction_01()
{
    std::string test_name = "Testing Z::operator-(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string as = getRandStrNum(getRandNum(1, 100));
        std::string bs = getRandStrNum(getRandNum(1, 100));
        zqnum::Z za(as);
        zqnum::Z zb(bs);
        zqnum::Z zc = za - zb;
        std::string zcs = zc.toString();
        ttmath::Int<200>  tta(as);
        ttmath::Int<200>  ttb(bs);
        ttmath::Int<200>  ttc = tta - ttb;
        std::string ttcs = ttc.ToString();
        if(zcs != ttcs)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestSubtraction_02()
{
    std::string test_name = "Testing Z::operator-(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string ns = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(ns);
        if(n - Z(0) != n)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestMultiplication_01()
{
    std::string test_name = "Testing Z::operator*(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string as = getRandStrNum(getRandNum(1, 50));
        std::string bs = getRandStrNum(getRandNum(1, 50));
        zqnum::Z za(as);
        zqnum::Z zb(bs);
        zqnum::Z zc = za * zb;
        std::string zcs = zc.toString();
        ttmath::Int<200>  tta(as);
        ttmath::Int<200>  ttb(bs);
        ttmath::Int<200>  ttc = tta * ttb;
        std::string ttcs = ttc.ToString();
        if(zcs != ttcs)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestMultiplication_02()
{
    std::string test_name = "Testing Z::operator*(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string ns = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(ns);
        if(n * Z(0) != Z(0) || n * Z(1) != n)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestDivision_01()
{
    std::string test_name = "Testing Z::operator/(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string as = getRandStrNum(getRandNum(1, 100));
        std::string bs = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z za(as);
        zqnum::Z zb(bs);
        zqnum::Z zc = za / zb;
        std::string zcs = zc.toString();
        ttmath::Int<200>  tta(as);
        ttmath::Int<200>  ttb(bs);
        ttmath::Int<200>  ttc = tta / ttb;
        std::string ttcs = ttc.ToString();
        if(zcs != ttcs)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestDivision_02()
{
    std::string test_name = "Testing Z::operator/(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string ns = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(ns);
        if(n / Z(1) != n || (n != Z(0) && n / n != Z(1)))
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestModulus_01()
{
    std::string test_name = "Testing Z::operator%(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string as = getRandStrNum(getRandNum(1, 100));
        std::string bs = getRandStrNumNonzero(getRandNum(1, 100));
        zqnum::Z za(as);
        zqnum::Z zb(bs);
        zqnum::Z zc = za % zb;
        std::string zcs = zc.toString();
        ttmath::Int<200>  tta(as);
        ttmath::Int<200>  ttb(bs);
        ttmath::Int<200>  ttc = tta % ttb;
        std::string ttcs = ttc.ToString();
        if(zcs != ttcs)
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestModulus_02()
{
    std::string test_name = "Testing Z::operator%(const Z&).";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string ns = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(ns);
        if( n % Z(1) != Z(0) || (n != Z(0) && n % n != Z(0)) )
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestNegation_01()
{
    std::string test_name = "Testing Z::operator-().";
    bool pass = true;
    for(int i = 1; i <= 1000; i++)
    {
        std::string ns = getRandStrNum(getRandNum(1, 100));
        zqnum::Z n(ns);
        if( n + (-n) != Z(0) || n - (-n) != Z(2) * n || -n != Z(-1) * n )
        {
            pass = false;
            break;
        }
    }
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestFibonacci()
{
    std::string test_name = "Computing the 1000th Fibonacci number.";
    bool pass = true;
    std::string fibonacci_1000 = "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875";
    zqnum::Z a(1), b(0);
    for(int i = 2; i <= 1000; i++)
    {
        a = a + b;
        b = a - b;
    }
    if(a.toString() != fibonacci_1000)
        pass = false;
    return std::make_pair(test_name, pass);
}

std::pair<std::string, bool> zTestFactorial()
{
    std::string test_name = "Computing the factorial of 1000.";
    bool pass = true;
    std::string factorial_1000 = "402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    zqnum::Z n(1);
    for(int i = 2; i <= 1000; i++)
        n = n * Z(i);
    if(n.toString() != factorial_1000)
        pass = false;
    return std::make_pair(test_name, pass);
}

}

/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
    
    // NEW BASIC TESTS 
    PhysicalNumber e(4000, Unit::CM);
    PhysicalNumber f(80, Unit::SEC);
    PhysicalNumber g(4, Unit::TON);
    PhysicalNumber h(40, Unit::KG);
    PhysicalNumber i(700, Unit::G);
    PhysicalNumber l(3, Unit::KM);
    PhysicalNumber m(20, Unit::M);
    PhysicalNumber n(7, Unit::HOUR);
    PhysicalNumber o(60, Unit::MIN);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
      
   // PRINT OUTPUT
      
    .setname("Basic output")
    .CHECK_OUTPUT(e, "4000[cm]")
    .CHECK_OUTPUT(f, "80[sec]")
    .CHECK_OUTPUT(g, "4[ton]")
    .CHECK_OUTPUT(h, "40[kg]") 
    .CHECK_OUTPUT(i, "700[g]")
    .CHECK_OUTPUT(l, "3[km]")
    .CHECK_OUTPUT(m, "20[m]")
    .CHECK_OUTPUT(n, "7[hour]")
    .CHECK_OUTPUT(o, "60[min]")
    

  // operator (+) && operator (-)
 //  operator (++) && operator (--)
      
    .setname("Compatible dimensions")
    .CHECK_OUTPUT(e+e, "8000[cm]")
    .CHECK_OUTPUT(f+f, "160[sec]")
    .CHECK_OUTPUT(g+g, "8[ton]") 
    .CHECK_OUTPUT(f++, "81[sec]")
    .CHECK_OUTPUT(n++, "8[hour]")   
    .CHECK_OUTPUT(++i, "701[g]")
    .CHECK_OUTPUT(--i, "700[g]")
    .CHECK_OUTPUT(++m, "21[m]")
    .CHECK_OUTPUT(--m, "20[m]")
    .CHECK_OUTPUT((h-=i), "39.3[kg]")
      
      
  // error calculations    

    .setname("Incompatible dimensions")
    .CHECK_THROWS(o+m)
    .CHECK_THROWS(l+i)
    .CHECK_THROWS(e+f)
    .CHECK_THROWS(e+g)
    .CHECK_THROWS(h-f)
    .CHECK_THROWS(f-b)
    .CHECK_THROWS(g-=f)
    .CHECK_THROWS(h-=e)
    .CHECK_THROWS(e+g)
    .CHECK_THROWS(h-f)
    .CHECK_THROWS(i-e)
    .CHECK_THROWS(i>f)
    .CHECK_THROWS(i==e)
    .CHECK_THROWS(e<=f)
    
      
    .setname("Check OK")
    .CHECK_OK(istringstream("700[g]")>>i)
    .CHECK_OK(istringstream("8000[cm]")>>e)
    .CHECK_OK(istringstream("160[sec]")>>f)
    .CHECK_OK(istringstream("8[ton]")>>g)
    .CHECK_OK(istringstream("81[sec]")>>f)
    .CHECK_OK(istringstream("8[hour]")>>n)
    .CHECK_OK(istringstream("39.3[kg]")>>h)
    .CHECK_OK(istringstream("20[m]")>>m)

      
    .setname("Compatible dimensions")
    .CHECK_EQUAL(f<d,true)
    .CHECK_EQUAL(h==g,false)
    .CHECK_OK(istringstream("1000[kg]")>>h)
    .CHECK_OUTPUT(h , "1000[kg]")    
    .CHECK_EQUAL(g==h,true)
    .CHECK_EQUAL(i!=h,true)
    .CHECK_EQUAL(g>i,true)
    .CHECK_EQUAL(i>h,false)
    .CHECK_EQUAL(e==a,false)
    .CHECK_EQUAL(c<d,true)
    
      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}

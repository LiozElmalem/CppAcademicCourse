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


    // for my test under the original test
    PhysicalNumber p1(100, Unit::M);
    PhysicalNumber p2(200, Unit::CM);
    PhysicalNumber p3(3, Unit::KM);
    PhysicalNumber p4(60, Unit::SEC);
    PhysicalNumber p5(60, Unit::MIN);
    PhysicalNumber p6(1, Unit::HOUR);
    PhysicalNumber p7(10, Unit::G);
    PhysicalNumber p8(4, Unit::KG);
    PhysicalNumber p9(1, Unit::TON);
    // end for the variabales

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

      .CHECK_OUTPUT(p1, "100[m]")
      .CHECK_OUTPUT(p2, "200[cm]")
      .CHECK_OUTPUT(p3, "3[km]")
      .CHECK_OUTPUT(p4, "60[sec]")
      .CHECK_OUTPUT(p5, "60[min]")
      .CHECK_OUTPUT(p6, "1[hour]")
      .CHECK_OUTPUT(p7, "10[g]")
      .CHECK_OUTPUT(p8, "4[kg]")
      .CHECK_OUTPUT(p9, "1[ton]")
      .CHECK_THROWS(p1+p4)
      .CHECK_THROWS(p2+p5)
      .CHECK_THROWS(p3+p6)
      .CHECK_THROWS(p3>p7)
      .CHECK_THROWS(p3>=p7)
      .CHECK_THROWS(p3<p7)
      .CHECK_THROWS(p3<=p7)
      .CHECK_THROWS(p3==p7)
      .CHECK_THROWS(p3+p6)
      .CHECK_OK(istringstream("60[m]") >> p6)
      .CHECK_EQUAL(p1+p2,PhysicalNumber(3,Unit::CM))
      .CHECK_EQUAL(p4+p5,PhysicalNumber(61,Unit::MIN))
      .CHECK_EQUAL(p6,PhysicalNumber(1,Unit::HOUR))

      //
      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}

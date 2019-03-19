/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;

  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);


  //my test
  ariel::Tree x;
  x.insert(6).insert(5).insert(7).insert(4);
  ariel::Tree y;
  ariel::Tree z;
  z.insert(1);
  //
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)

  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())
  //my test
  .CHECK_EQUAL(x.size(),4)
  .CHECK_EQUAL(x.root(),6)
  .CHECK_EQUAL(x.parent(5),6)
  .CHECK_EQUAL(x.left(6),5)
  .CHECK_EQUAL(x.right(6),7)
  .CHECK_EQUAL(x.parent(7),6)
  .CHECK_OK(x.remove(4))
  .CHECK_OK(x.insert(9))
  .CHECK_THROWS(x.insert(5))
  //x end and y start here
  .CHECK_EQUAL(y.size(),0)
  .CHECK_THROWS(y.root())
  .CHECK_THROWS(y.print())
  //y end and z start here
  .CHECK_EQUAL(z.size(),1)
  .CHECK_EQUAL(z.root(),1)
  //end of my test
  .print();

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}

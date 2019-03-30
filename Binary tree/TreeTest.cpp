#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  ariel::Tree seventree;
  ariel::Tree fourrighttree;  //diagonal line
  ariel::Tree fourlefttree;   //diagonal line
  ariel::Tree ninetree;

  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  seventree.insert(50);
  seventree.insert(30);
  seventree.insert(70);
  seventree.insert(20);
  seventree.insert(40);
  seventree.insert(60);
  seventree.insert(80);

  fourrighttree.insert(22);
  fourrighttree.insert(35);
  fourrighttree.insert(44);
  fourrighttree.insert(59);

  fourlefttree.insert(22);
  fourlefttree.insert(15);
  fourlefttree.insert(9);
  fourlefttree.insert(3);


  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)


  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())

   .CHECK_EQUAL (seventree.root(),50)
   .CHECK_EQUAL (seventree.size(),7)
   .CHECK_EQUAL (seventree.contains(60),true)
   .CHECK_OK    (seventree.remove(80))
   .CHECK_THROWS(seventree.remove(80))
   .CHECK_THROWS (seventree.right(70))
  .CHECK_EQUAL (seventree.parent(40),30)
  .CHECK_EQUAL (seventree.parent(60),70)
  .CHECK_THROWS(seventree.parent(50))
  .CHECK_THROWS (seventree.left(20))
  .CHECK_EQUAL (seventree.left(50),30)
  .CHECK_OK    (seventree.remove(50))
  .CHECK_OK    (seventree.print())
  .CHECK_EQUAL (seventree.root(),60)
  .CHECK_EQUAL (seventree.parent(70),60)
  .CHECK_THROWS(seventree.insert(40))
  .CHECK_EQUAL (seventree.size(),5)
  .CHECK_OK    (seventree.print())

  .CHECK_EQUAL (fourrighttree.size(),4)
  .CHECK_EQUAL (fourrighttree.contains(44),true)
  .CHECK_EQUAL (fourrighttree.root(),22)
  .CHECK_EQUAL (fourrighttree.right(44),59)
  .CHECK_OK    (fourrighttree.remove(59))
  .CHECK_THROWS (fourrighttree.right(44))
  .CHECK_THROWS(fourrighttree.remove(59))
  .CHECK_EQUAL (fourrighttree.parent(35),22)
  .CHECK_THROWS(fourrighttree.parent(22))
  .CHECK_THROWS(fourrighttree.remove(29))
  .CHECK_THROWS (fourrighttree.left(35))
  .CHECK_OK     (fourrighttree.remove(22))
  .CHECK_OK(fourrighttree.print())
  .CHECK_EQUAL (fourrighttree.root(),35)
  .CHECK_EQUAL (fourrighttree.size(),2)
  .CHECK_OK    (fourrighttree.print())


  .CHECK_EQUAL (fourlefttree.size(),4)
  .CHECK_EQUAL (fourlefttree.root(),22)
  .CHECK_EQUAL (fourlefttree.contains(3),true)
  .CHECK_EQUAL (fourlefttree.left(15),9)
  .CHECK_OK    (fourlefttree.remove(9))
  .CHECK_EQUAL (fourlefttree.left(15),3)
  .CHECK_THROWS(fourlefttree.remove(9))
  .CHECK_EQUAL (fourlefttree.parent(3),15)
  .CHECK_THROWS(fourlefttree.parent(22))
  .CHECK_THROWS(fourlefttree.remove(73))
  .CHECK_THROWS (fourlefttree.right(3))
    .CHECK_OK  (fourlefttree.print())
  .CHECK_OK(fourlefttree.remove(22))
   .CHECK_OK  (fourlefttree.print())
  .CHECK_EQUAL (fourlefttree.root(),15)
    .CHECK_OK  (fourlefttree.print())
  .CHECK_EQUAL (fourlefttree.size(),2)
  .CHECK_OK    (fourlefttree.print())


  .CHECK_THROWS (ninetree.root())
  .CHECK_EQUAL (ninetree.size(),0)
  .CHECK_OK    (ninetree.insert(3))
  .CHECK_OK    (ninetree.insert(1))
  .CHECK_OK    (ninetree.insert(10))
  .CHECK_EQUAL (ninetree.contains(3),true)
  .CHECK_OK    (ninetree.insert(5))
  .CHECK_OK    (ninetree.insert(4))
  .CHECK_OK    (ninetree.insert(7))
  .CHECK_OK    (ninetree.insert(16))
  .CHECK_OK    (ninetree.insert(15))
  .CHECK_OK    (ninetree.insert(20))
  .CHECK_EQUAL (ninetree.root(),3)
  .CHECK_EQUAL (ninetree.parent(1),3)
   .CHECK_OK    (ninetree.remove(3))
  .CHECK_EQUAL (ninetree.contains(3),false)
  .CHECK_EQUAL (ninetree.root(),4)
    .CHECK_OK    (ninetree.print())
  .CHECK_EQUAL (ninetree.parent(1),4)
  .CHECK_EQUAL (ninetree.parent(16),10)
  .CHECK_EQUAL (ninetree.right(5),7)
  .CHECK_OK    (ninetree.remove(10))
  .CHECK_EQUAL (ninetree.size(),7)
  .CHECK_EQUAL (ninetree.parent(16),15)
  .CHECK_THROWS (ninetree.left(16))
  .CHECK_OK    (ninetree.remove(1))
  .CHECK_EQUAL (ninetree.root(),4)
  .CHECK_EQUAL (ninetree.contains(30),false)
  .CHECK_THROWS(ninetree.remove(3))
  .CHECK_THROWS (ninetree.left(5))
  .CHECK_OK    (ninetree.remove(4))
  .CHECK_THROWS (ninetree.left(5))
  .CHECK_EQUAL (ninetree.size(),5)
  .CHECK_OK    (ninetree.print())


  .print();

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}

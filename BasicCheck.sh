#!/bin/bash
#check success compiling of any file
echo "MATALA 0 BASH - lioz elmalem  , bar genish -> ID: 205804693 ,313174583"
echo""
echo""

echo "please enter a dir path to the program"
read dirPath
echo "please enter program name"
read program
echo "please enter the arguments for the program"
read arguments

echo""
echo""

$dirPath
make

$dirPath clang++-5.0 $program.cpp < $arguments
if [[ $? -gt 0 ]]; then
	firstANS=1
	echo "compilation fail"
	exit 1
 else
	 firstANS=0
	 echo "compilation success"

	 echo "valgrind work now"
	 ./a.out
	 valgrind --tool=memcheck --leak-check=full --error-exitcode=3 ./a.out
	 if [[ $? -gt 0 ]] ; then
		 secondANS=1
	 	echo "memory leaks fail"
	 else
		 secondANS=0
	 	echo "memory leaks pass"
	 fi

	 echo ""
	 echo ""
	 echo ""
	 echo ""
	 echo ""
	 echo ""
	 echo ""

	 echo "helgrind work now"
	 valgrind --tool=helgrind ./a.out
	 echo $?
	 if [[ $? -gt 0 ]]; then
		 thirdANS=1
	 	echo "thread race fail"
	 else
		 thirdANS=0
	 	echo "thread race pass"
	 fi

 fi

echo ""
echo ""
echo ""
echo ""
echo ""
echo "toal ans for this check :"

 ANS=$firstANS$secondANS$thirdANS
 if [ $ANS == '000' ]; then
	 echo "everything pass  - 0"
	 exit 1;
fi
if [ $ANS == '010' ]; then
	echo "thread race pass but memory leak fail  - 2"
	exit 1;
fi
if [ $ANS == '001' ]; then
	echo "thread race fail but memory leak pass  - 1"
	exit 1;
fi

if [ $ANS == '011' ]; then
	echo "thread race fail and memory leak fail too  - 3"
	exit 1;
 else
 echo "wrong program  - 111"
 exit 1;
 fi

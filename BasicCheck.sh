#!/bin/bash
# get 3 variabales from the user.
dirPath=$1
program=$2
arguments=${@:3}

#  we search the makefile file in the current path
#  if the makefile doesn't exist the value be different from 0 and the script will exit. 
#  else, the script will check compilation , Memory leaks and thread race.
#  the script returns binary number that represent which of the tests work and who fail.
cd $dirPath
make &> /dev/null
if [[ $? -gt 0 ]]; then
	firstANS=1
	exit 7
 else
	 firstANS=0
	 # valgrind memory leak check
	 valgrind --tool=memcheck --leak-check=full --error-exitcode=3 -q ./$program $arguments &> /dev/null
	 if [[ $? -gt 0 ]] ; then
		 secondANS=1
	 	 else
		 secondANS=0
	 fi
	 # valgrind-helgrind thread race check
	 valgrind --tool=helgrind --error-exitcode=3 -q ./$program $arguments &> /dev/null
	 if [[ $? -gt 0 ]]; then
		 thirdANS=1
	 else
		 thirdANS=0
	 fi

 fi
# binary ans request and print it in the end
 ANS=$firstANS$secondANS$thirdANS
 if [ $ANS == '000' ]; then
	 echo -e "Compilation   Memory leaks   Thread race\n    PASS         PASS           PASS"
	 exit 0;
fi
if [ $ANS == '010' ]; then
	echo -e "Compilation   Memory leaks   Thread race\n    PASS         FAIL           PASS"
	exit 2;
fi
if [ $ANS == '001' ]; then
	echo -e "Compilation   Memory leaks   Thread race\n    PASS         PASS           FAIL"
	exit 1;
fi

if [ $ANS == '011' ]; then
	echo -e "Compilation   Memory leaks   Thread race\n    PASS         FAIL           FAIL"
	exit 3;
 else
 echo -e "wrong program  - 111"
 exit 7;
 fi

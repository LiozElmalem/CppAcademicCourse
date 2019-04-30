#include <iostream>
#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,
using namespace bullpgia;
using namespace std;
int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		// ConstantChooser c1112{"1112"}, c14544{"145044"}, c99939{"99939"};
		// ConstantGuesser g1112{"1112"}, g14544{"145044"}, g99939{"99939"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1113","1131"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1113","1113"), "4,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1153","5131"), "1,3")      // 1 bull, 3 pgia
        .CHECK_OUTPUT(calculateBullAndPgia("1153","1153"), "4,0")      // 4 bull, 0 pgia
        .CHECK_OUTPUT(calculateBullAndPgia("1111","2222"), "0,0")      // 0 bull, 0 pgia
        .CHECK_OUTPUT(calculateBullAndPgia("1153","1153"), "4,0")      // 4 bull, 0 pgia
        .CHECK_OUTPUT(calculateBullAndPgia("1153","01153"), "1,3")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2233","3322"), "0,4")      // 0 bull, 4 pgia
		;

		// testcase.setname("Play with dummy choosers and guessers")
		// .CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		// .CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns
		// .CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		// .CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		// ;

		// testcase.setname("Play with smart guesser");
		// RandomChooser randy;
		// SmartGuesser smarty;
		// for (uint i=0; i<100; ++i) {
		// 	testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		// }

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

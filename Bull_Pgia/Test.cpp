/**
 * A demo program for bull-pgia.
 *
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {



		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;


 	// my test
		testcase.setname("my test")
		//length 5
		.CHECK_OUTPUT(calculateBullAndPgia("11131","22222"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("11131","22232"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12345","54321"), "1,4")      // 1 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12345","12346"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("78967","77777"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12345","98765"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("23456","27891"), "1,0")      // 1 bull, 0 pgia
		//end 5
		//length 4
		.CHECK_OUTPUT(calculateBullAndPgia("1113","1131"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1113","1113"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1153","5131"), "1,3")      // 1 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1153","1153"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1111","2222"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1153","1153"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1153","01153"), "1,3")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2233","3322"), "0,4")      // 0 bull, 4 pgia
		//end 4
		//length 3
		.CHECK_OUTPUT(calculateBullAndPgia("456","457"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("699","679"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("124","133"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("123","321"), "1,2")      // 1 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("654","432"), "0,1")      // 0 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("122","222"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("999","988"), "1,0")      // 1 bull, 2 pgia
		//end 3
		//length 2
		.CHECK_OUTPUT(calculateBullAndPgia("22","22"), "2,0")         // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12","42"), "1,0")        // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("32","63"), "0,1")        // 0 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("98","78"), "1,0")        // 1 bull, 0 pgia`
		.CHECK_OUTPUT(calculateBullAndPgia("23","32"), "0,2")        // 1 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("14","41"), "0,2")        // 1 bull, 1 pgoa
		.CHECK_OUTPUT(calculateBullAndPgia("89","22"), "0,0")        // 0 bull, 0 pgia
		//end 2
		//length 1
		.CHECK_OUTPUT(calculateBullAndPgia("1","2"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1","1"), "1,0")      // 1 bull, 0 pgia
		//end 1
		;
		// end for my test



		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

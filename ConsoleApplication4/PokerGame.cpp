// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cassert>
#include <iostream>

#include "./poker.h"

constexpr int TIE = 0;
constexpr int WIN = 1;
constexpr int LOSS = 2;

void testCaseOne() {
	PokerHand hand("TD 9S QS QH TH");
	PokerHand opponent("5D 5S QC 9H QH");
	assert(hand.compareWith(opponent) == WIN);
}

void testCaseTwo() {
	/* ROYAL FLUSH - YOU */
	PokerHand hand("TD KD QD AD JD");
	PokerHand opponent("5D 5S QC 9H QH");
	assert(hand.compareWith(opponent) == WIN);
}


void testCaseThree() {
	/*STRAIGHT FLUSH - OPPONENT*/
	PokerHand hand("9D KD QD AD JD");
	PokerHand opponent("5S 6S 7S 9S 8S");
	assert(hand.compareWith(opponent) == LOSS);
}


void testCaseFour() {
	/*FOUR OF A KIND - YOU*/
	PokerHand hand("9D 9C 9H 9S JD");
	PokerHand opponent("5S 6D 7S KS 8S");
	assert(hand.compareWith(opponent) == WIN);
}

void testCaseFive() {
	/*FULL HOUSE - YOU*/
	PokerHand hand("9D 9C 9H AH AC");
	PokerHand opponent("5S 6D 7S KS 8S");
	assert(hand.compareWith(opponent) == WIN);
}

void testCaseSix() {
	/*FLUSH - OPPONENT*/
	PokerHand hand("9D 9C JH AH AC");
	PokerHand opponent("5S 6S 7S KS 8S");
	assert(hand.compareWith(opponent) == LOSS);
}


void testCaseSeven() {
	/*STRAIGHT - OPPONENT*/
	PokerHand hand("9D 9C JH AH AC");
	PokerHand opponent("5S 4S 7H 8C 6D");
	assert(hand.compareWith(opponent) == LOSS);
}


void testCaseEight() {
	/*THREE OF KIND - YOU*/
	PokerHand hand("9D 9C 9H 3H 6C");
	PokerHand opponent("5S AS 7H 8C 2D");
	assert(hand.compareWith(opponent) == WIN);
}

void testCaseNine() {
	/*TWO PAIR - YOU*/
	PokerHand hand("AD AC 10H 3H 3C");
	PokerHand opponent("5S AS 7H 8C 2D");
	assert(hand.compareWith(opponent) == WIN);
}


void testCaseTen() {
	/*PAIR - OPPONENT*/
	PokerHand hand("AD QC TH 3H 6C");
	PokerHand opponent("5S 7S 7H 8C 2D");
	assert(hand.compareWith(opponent) == LOSS);
}

void testCaseEleven() {
	/*HIGH - OPPONENT*/
	PokerHand hand("2D 5C TH 3H 6C");
	PokerHand opponent("AS 3S 6H 8C 2D");
	assert(hand.compareWith(opponent) == LOSS);
}

void testCaseTwelve() {
	/*HIGH - YOU*/
	PokerHand hand("3D KC QH AH 8D");
	PokerHand opponent("KS AS QH 8C 2D");
	assert(hand.compareWith(opponent) == WIN);
}


void testCaseThirteen() {
	/*ROYAL FLUSH -TIE*/
	PokerHand hand("TD KD QD AD JD");
	PokerHand opponent("JS KS AS QS TS");
	assert(hand.compareWith(opponent) == TIE);
}


void testCaseFourteen() {
	/*STRAIGHT FLUSH - OPPONENT*/
	PokerHand hand("9D 5D 8D 6D 7D");
	PokerHand opponent("5S 6S 7S 9S 8S");
	assert(hand.compareWith(opponent) == TIE);
}


void testCaseFifteen() {
	/*FOUR OF A KIND - YOU, OPPONENT*/
	PokerHand hand("9D 9C 9H 9S JD");
	PokerHand opponent("5S TD TC TH TS");
	assert(hand.compareWith(opponent) == LOSS);
}

void testCaseSixteen() {
	/*FULL HOUSE - YOU, OPPONENT*/

	PokerHand hand("9D 9C 9H AH AC");
	PokerHand opponent("AS AD KS KD KC");
	assert(hand.compareWith(opponent) == LOSS);
}

void testCaseSeventeen() {
	/*FLUSH - OPPONENT*/
	PokerHand hand("9D 9C JH AH AC");
	PokerHand opponent("5S 6S 7S KS 8S");
	assert(hand.compareWith(opponent) == LOSS);
}


void testCaseEighteen() {
	/*STRAIGHT - OPPONENT*/
	PokerHand hand("9D 7D JD AD QD");
	PokerHand opponent("5S 4S 7H 8C 6D");
	assert(hand.compareWith(opponent) == WIN);
}


void testCaseNineteen() {
	/*THREE OF KIND - YOU*/
	/* STRAIGHT - OPPONENT */
	PokerHand hand("9D 9C 9H 3H 6C");
	PokerHand opponent("2S 6S 4H 3C 5D");
	assert(hand.compareWith(opponent) == LOSS);
}

void testCaseTwenty() {
	/*TWO PAIR - TIE*/
	PokerHand hand("AD AC TH 3H 3C");
	PokerHand opponent("3S AS AH TC 3D");
	assert(hand.compareWith(opponent) == TIE);
}


void testCaseTwentyOne() {
	/*PAIR - TIE*/
	PokerHand hand("8D 2C 7D 7C 5C");
	PokerHand opponent("5S 7S 7H 8C 2D");
	assert(hand.compareWith(opponent) == TIE);
}

void testCaseTwentyTwo() {
	/*HIGH - TIE*/
	PokerHand hand("2D 5C TH 3H 6C");
	PokerHand opponent("5S 6S 3H TC 2C");
	assert(hand.compareWith(opponent) == TIE);
}


int main(int argc, char *argv[]) {

	testCaseOne();
	testCaseTwo();
	testCaseThree();

	testCaseFour();
	testCaseFive();
	testCaseSix();


	testCaseSeven();
	testCaseEight();
	testCaseNine();
	testCaseTen();

	testCaseEleven();
	testCaseTwelve();
	testCaseThirteen();
	testCaseFourteen();


	testCaseFifteen();
	testCaseSixteen();
	testCaseSeventeen();

	testCaseEighteen();
	testCaseNineteen();
	testCaseTwenty();
	testCaseTwentyOne();
	testCaseTwentyTwo();
	std::cout << "All tests passed" << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

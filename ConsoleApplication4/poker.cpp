#include "pch.h"
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

#include "poker.h"

static int const WIN = 1;
static int const LOSS = 2;
static int const TIE = 0;

std::map<char, int> map1 = { {'2', 2}, {'3', 3} , {'4', 4}, {'5', 5} , {'6', 6}, {'7', 7} , {'8', 8}, {'9', 9} , {'T', 10}, {'J', 11} ,{'Q', 12} , {'K', 13}, {'A', 14} };

PokerHand::PokerHand(std::string pHand) : hand(pHand) {

	int a = 1;
	int colorCount = 0;
	std::set<char> suits;

	_hands.reserve(5);

	for (char c : hand) {
		if (' ' == c) {
			continue;
		}
		else if ((a % 2) != 0) {

			_hands.push_back(map1[c]);
		}
		else {
			if (suits.end() != suits.find(c)) {
				colorCount++;
			}
			else {
				colorCount = 1;
				suits.insert(c);

			}
		}
		a++;
	}
	if (colorCount == 5) {
		_suits = true;
	}

	std::sort(_hands.begin(), _hands.end());

	_processSequence();
	_processSuits();
}
void PokerHand::toString() {

	std::cout << "Hands" << std::endl;
	for (int a : _hands) {
		std::cout << " " << a;
	}
	std::cout << std::endl;
	std::cout << "Suits" << _suits << std::endl;

	std::cout << "Max Value " << _maxValue << std::endl;
	
	//std::cout << "handVal" << _hand << std::endl;
}
int PokerHand::compareWith(PokerHand &pOpponent) {
	
	int retVal = LOSS;
	pOpponent.toString();
	toString();
	if (pOpponent.getHand() > _hand) {

		retVal = WIN;
	}
	else if (pOpponent.getHand() == _hand) {
				
		if ((_hand == POKERHANDS::FourKind) || (_hand == POKERHANDS::FullHouse) || (_hand == POKERHANDS::ThreeKind) ||(_hand == POKERHANDS::TwoPairs)) {

			retVal = _computeOnMaxValue(pOpponent.getMaxValuePair(), getMaxValuePair());
			if (retVal == TIE) {

				retVal = _computeOnMaxValue(pOpponent.getMaxValue(), getMaxValue());
			}
		}
		else if (_hand == POKERHANDS::Pairs) {
			retVal = _computeOnMaxValue(pOpponent.getMaxValuePair(), getMaxValuePair());
			if (retVal == TIE) {
				retVal = _computeUsingHands(pOpponent.getHands(), getMaxValuePair());
			}
		}
		else {
			retVal = _computeOnMaxValue(pOpponent.getMaxValue(), getMaxValue());
		}
	}
	
	return retVal;
}

void PokerHand::_checkStraight(int *a, int size, enum POKERHANDS &curHand) {

	if (a[0] + 1 == a[1]) {
		return;
	}
	if (size == 3) {
		if ((a[0] == 5) && (a[1] == map1['A'])) {
			_maxValue -= (a[1] - 1);
			return;
		}
	}
	if (a[0] == a[1]) {
		curHand = POKERHANDS::Pairs;
		_maxValuePairs = a[0];

	}
}

void PokerHand::_checkPairs(int* a, int& lastVal, enum POKERHANDS &curHand) {

	if (curHand == POKERHANDS::Pairs) {

		if (a[0] == a[1])
			if (lastVal == a[1]) {
				curHand = POKERHANDS::ThreeKind;
			}
			else {
				curHand = POKERHANDS::TwoPairs;
				_maxValuePairs += a[0];
			}
	}
	else if (curHand == POKERHANDS::ThreeKind) {
		if (a[0] == a[1]) {
			if (lastVal == a[1]) {
				curHand = POKERHANDS::FourKind;
			}
			else {
				if (_maxValuePairs < a[0]) {
					_maxValuePairs = a[0];
				}
				curHand = POKERHANDS::FullHouse;
			}
		}
	}
	else if (curHand == POKERHANDS::TwoPairs) {
		if (a[0] == a[1]) {
			curHand = POKERHANDS::FullHouse;
			_maxValuePairs = a[0]; // with 3 same cards.
		}
	}
	else if (a[0] == a[1]) {
		curHand = POKERHANDS::Pairs;
		lastVal = a[0];
		_maxValuePairs = a[0];
		
	}

}
void PokerHand::_processSuits() {

	if (_suits) {

		if (_hand == POKERHANDS::HighCard) {
			_hand = POKERHANDS::Flush;
		}
		else if (_hand == POKERHANDS::Straight) {
			if (_maxValue == (map1['T'] + map1['J'] + map1['Q'] + map1['K'] + map1['A'])) {
				_hand = POKERHANDS::RoyalFlush;
			}
			else {
				_hand = POKERHANDS::StraightFlush;
			}
		}
	}
}
void PokerHand::_processSequence() {

	enum POKERHANDS hnd = POKERHANDS::HighCard;

	int *ptr = &_hands[0];
	int lastVal = 0;

	_maxValue = ptr[0] + ptr[1];

	if (ptr[0] + 1 == ptr[1]) {
		hnd = POKERHANDS::Straight;
	}
	else if (ptr[0] == ptr[1]) {
		hnd = POKERHANDS::Pairs;
		lastVal = ptr[0];
		_maxValuePairs = ptr[0];
	}
	for (int a = 1; a < 4; a++) {
		_maxValue += ptr[a + 1];

		if (hnd == POKERHANDS::Straight) {
			
			_checkStraight(ptr + a, a, hnd);
			lastVal = ptr[a];
		}
		else {
			_checkPairs(ptr + a, lastVal, hnd);
		}
	}
	_hand = hnd;
}
	
int  PokerHand::_computeOnMaxValue(const int maxValue, const int maxValueThis) {
	int retVal = LOSS;
	if (maxValue < maxValueThis) {

		retVal = WIN;
	}
	else if (maxValue == maxValueThis) {

		retVal = TIE;

	}
	return retVal;
}

int PokerHand::_computeUsingHands(const std::vector<int>& hands, int maxPairValue) {

	auto itr = hands.rbegin();
	auto itrSelf = getHands().rbegin();
	int retValue = TIE;

	for (; itr!= hands.rend(); ) {
		
		if (*itr == maxPairValue) {
			itr++;
			continue;
		}
		if (*itrSelf == maxPairValue) {
			itrSelf++;
			continue;
		}

		if (*itr == *itrSelf) {
			itr++; 
			itrSelf++;
			continue;
		}
		if (*itr > *itrSelf) {
			retValue = LOSS;
			break;
		}
		else {
			retValue = WIN;
			break;
		}
	}
	return retValue;
}


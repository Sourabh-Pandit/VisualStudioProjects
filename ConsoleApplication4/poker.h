#pragma once

#include <string>
#include <vector>

class PokerHand {

	enum class POKERHANDS { RoyalFlush, StraightFlush, FourKind, FullHouse, Flush, Straight, ThreeKind, TwoPairs, Pairs, HighCard };

public:
        std::string hand;

        PokerHand(std::string pHand);

        int compareWith(PokerHand &pOpponent);

		enum POKERHANDS getHand() const { return _hand; }

		int getMaxValue() const { return _maxValue; }

		int getMaxValuePair() const { return _maxValuePairs; }

		const std::vector<int>& getHands() const{ return _hands; }

		void toString();

	private:
	
	
	void _checkStraight(int *a, int size,  POKERHANDS &curHand);

	void _checkPairs(int* a, int &lastVal,  POKERHANDS &curHand);

	void _processSuits();

	void _processSequence();
	
	int _computeOnMaxValue(const int maxValue, const int  maxValueThis);
	
	int _computeUsingHands(const std::vector<int>& hands, int maxPairValue);

	POKERHANDS _hand = POKERHANDS::HighCard;
	std::vector<int> _hands;
	int				_maxValue = 0;
	int			    _maxValuePairs = 0;
	bool			_suits = false;

};
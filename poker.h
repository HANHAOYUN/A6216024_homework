#ifndef POKER_H_
#define POKER_H_
#include<string>
using namespace std;

class Poker
{
public:
	Poker();
	void shuffle();
	string getPlayer();
	string getLandlord();
	int getSumP();
	int getSumL();
	void playerAsk();
	void landlordAsk();
	void newGame();


private:
	int poker[53], pValue[53];
	string pName[53];
	int player[5], landlord[5];
	int playerN, landlordN;

};
#endif


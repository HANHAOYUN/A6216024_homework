#ifndef POKER_H_
#define POKER_H_
#include<string>
using namespace std;

class Poker
{
public:
	Poker();
	void shuffle();
	string getPlayer()const;
	string getLandlord()const;
	int getSumP()const;
	int getSumL()const;
	void playerAsk();
	void landlordAsk();
	void newGame();
	void landlordProcess();

private:
	int poker[53], pValue[53];
	string pName[53];
	int player[5], landlord[5];
	int playerN, landlordN;

};
#endif
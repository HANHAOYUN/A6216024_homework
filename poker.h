

#ifndef POKER_H_

#define POKER_H_
#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<sstream>
#include<limits>
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

	void landlordProcess();



private:

	int poker[53], pValue[53];

	string pName[53];

	int player[5], landlord[5];

	int playerN, landlordN;



};
#endif

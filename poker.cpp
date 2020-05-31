﻿#include "poker.h"
#include<time.h>
#include<iostream>
#include<string>
#define NUM 1000
int j = 2;
int randNum[NUM];

Poker::Poker()
{
	poker[0] = 0;
	for (int i = 0; i <= 13; i++)
	{
		poker[i] = i;
		poker[i + 13] = i;
		poker[i + 26] = i;
		poker[i + 39] = i;
	}
	pValue[0] = 0;
	for (int i = 0; i <= 52; i++)
	{
		if (poker[i] <= 10)
			pValue[i] = poker[i];
		else
			pValue[i] = 10;
	}
	pName[0] = "";
	for (int i = 0; i < 4; i++)
	{
		pName[1 + 13 * i] = "A";
		pName[2 + 13 * i] = "2";
		pName[3 + 13 * i] = "3";
		pName[4 + 13 * i] = "4";
		pName[5 + 13 * i] = "5";
		pName[6 + 13 * i] = "6";
		pName[7 + 13 * i] = "7";
		pName[8 + 13 * i] = "8";
		pName[9 + 13 * i] = "9";
		pName[10 + 13 * i] = "10";
		pName[11 + 13 * i] = "J";
		pName[12 + 13 * i] = "Q";
		pName[13 + 13 * i] = "K";
	}


	for (int i = 0; i < 5; i++)
	{
		player[i] = 0;
		landlord[i] = 0;
	}

}
void Poker::shuffle()
{
	cout << "遊戲開始，開始洗牌>>>>>" << endl;
	srand((int)time(0));
	for (int i = 0; i < NUM; i++)
	{
		randNum[i] = rand() * 51 / 32767 + 1;
	}
	player[0] = randNum[j++];
	player[1] = randNum[j++];
	landlord[0] = randNum[j++];
	landlord[1] = randNum[j++];

	playerN = 2;
	landlordN = 2;

	cout << "洗牌結束,你的牌為:" << getPlayer() << "  點數:" << getSumP() << endl;
}
string Poker::getPlayer()const
{
	int i;
	string pp = "";

	for (i = 0; i < playerN; i++)
		pp = pp + pName[player[i]] + " ";

	return pp;
}
string Poker::getLandlord()const
{
	int i;
	string lp = "";

	for (i = 0; i < landlordN; i++)
		lp = lp + pName[landlord[i]] + " ";

	return lp;
}
int Poker::getSumP()const
{
	int sp = 0;

	for (int i = 0; i < playerN; i++)
		sp = sp + pValue[player[i]];

	return sp;
}
int Poker::getSumL()const
{
	int sl = 0;

	for (int i = 0; i < landlordN; i++)
		sl = sl + pValue[landlord[i]];

	return sl;
}
void Poker::playerAsk()
{
	if (playerN >= 5)
	{
		cout << "你的牌數已經5張，不能再要牌了" << endl;
		landlordProcess();
	}
	else
	{
		player[playerN++] = randNum[j++];
		cout << "你的牌為:" << getPlayer() << "  點數:" << getSumP() << endl;
		if (getSumP() > 21)
		{
			cout << "你爆牌了,你輸了!!!!" << endl;
			shuffle();
		}
		else if (getSumP() == 21)
		{
			landlordProcess();
		}
	}
}
void Poker::landlordAsk()
{
	if (playerN >= 5)
	{
		if (getSumP() > getSumL())
		{
			cout << "莊家的牌為" << getPlayer() << "  點數:" << getSumL() << endl;
			cout << "你贏了!!!!" << endl;
			shuffle();


		}
		else if (getSumP() == getSumL())
		{
			cout << "莊家的牌為" << getLandlord() << "  點數:" << getSumL() << endl;
			cout << "雙方平手" << endl;
			shuffle();
		}
		else if (getSumP() < getSumL())
		{
			cout << "莊家的牌為" << getLandlord() << "  點數:" << getSumL() << endl;
			cout << "你輸了!!!!" << endl;
			shuffle();
		}
	}
	else
	{
		landlord[landlordN++] = randNum[j++];
		if (getSumL() > 21)
		{
			cout << "莊家的牌為" << getLandlord() << "  點數:" << getSumL() << endl;
			cout << "莊家爆牌,你贏了" << endl;
			shuffle();
		}
		else    landlordProcess();
	}
}

void Poker::newGame()
{
	system("CLS");
	cout << ">>>>>>>>>>>>>>>> Welcome To Play Black Jack <<<<<<<<<<<<<<<<" << endl << endl;
	shuffle();



}
void Poker::landlordProcess()
{
	if (getSumL() >= 17)
	{
		if (getSumL() > getSumP())
		{
			cout << "莊家的牌為" << getLandlord() << "  點數:" << getSumL() << endl;
			cout << "莊家獲勝，你輸了" << endl;
			shuffle();
		}
		else if (getSumP() == getSumL())
		{
			cout << "莊家的牌為" << getPlayer() << "  點數:" << getSumL() << endl;
			cout << "雙方平手" << endl;
			shuffle();
		}
		else
		{
			cout << "莊家的牌為" << getPlayer() << "  點數:" << getSumL() << endl;
			cout << "你贏了!!!!" << endl;
			shuffle();
		}
	}
	else
	{
		landlordAsk();
	}
}
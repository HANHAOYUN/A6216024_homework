#ifndef POKER_H_
#define POKER_H_
#include<string>
using namespace std;

class Poker
{
public:
	Poker();   //建構函式，對牌初始化
	void shuffle();   //洗牌,在每輪遊戲開始前進行
	string getPlayer()const;   //用字串的形式返回玩家的牌
	string getLandlord()const;   //用字串的形式返回莊家的牌
	int getSumP()const;        //返回玩家牌的點數，用以判斷是否超過21點
	int getSumL()const;          //返回莊家牌的點數
	void playerAsk();           //玩家要牌
	void landlordAsk();         //莊家要牌
	void newGame();           //開始新遊戲
	void landlordProcess();     //在玩家不要牌時進行處理

private:
	int poker[53], pValue[53]; //撲克,撲克代表的數值
	string pName[53];  //撲克名
	int player[5], landlord[5];  //玩家手中的牌 ,莊家手中的牌
	int playerN, landlordN;  //玩家手中的牌數,莊家手中的牌數

};
#endif


#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<pocker.h>
#include<sstream>
#include<limits>
using namespace std;


int main()

{



	Poker poker;

	cout << "****************** 歡迎玩二十一點遊戲 ******************" << endl << endl;



	poker.shuffle();                   //洗牌



	while (1)

	{
		int choose;
		cout << "1.要牌 2.不要牌 3.重新開始 4.退出  >>請輸入數字選擇操作:";
		cin >> choose;
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		if (!cin || cin.gcount() != 1)
		{
			cout << "輸入錯誤" << endl;
		}
		else
		{
			if (choose == 1)
			{
				poker.playerAsk();
			}
			else if (choose == 2)
			{
				poker.landlordProcess();
			}
			else if (choose == 3)
			{
				poker.newGame();
			}
			else if (choose == 4)
			{
				exit(0);
			}
			while (choose != 1 && choose != 2 && choose != 3 && choose != 4)
			{

				cout << "輸入錯誤" << endl;
				cin >> choose;
				if (choose == 1)
				{
					poker.playerAsk();
				}
				else if (choose == 2)
				{
					poker.landlordProcess();
				}
				else if (choose == 3)
				{
					poker.newGame();
				}
				else if (choose == 4)
				{
					exit(0);
				}
			}

		}


	}

	system("pause");

	return 0;

}
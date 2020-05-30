#include<iostream>

#include<string>

#include<time.h>

#include"poker.h"

using namespace std;







int main()

{

	int choose = 1;

	Poker poker;

	cout << "****************** 歡迎玩二十一點遊戲 ******************" << endl << endl;



	poker.shuffle();                   //洗牌



	while (choose == 1 || choose == 2 || choose == 3 || choose == 4)

	{

		cout << "1.要牌 2.不要牌 3.重新開始 4.退出  >>請輸入數字選擇操作:";

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
		while (choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
			
			cout << "請重新輸入:";
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

	system("pause");

	return 0;

}
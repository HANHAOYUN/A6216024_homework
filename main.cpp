#include<iostream>

#include<string>

#include<time.h>

#include"poker.h"

using namespace std;







int main()

{

	int choose = 1;

	Poker poker;

	cout << "****************** �w�缾�G�Q�@�I�C�� ******************" << endl << endl;



	poker.shuffle();                   //�~�P



	while (choose == 1 || choose == 2 || choose == 3 || choose == 4)

	{

		cout << "1.�n�P 2.���n�P 3.���s�}�l 4.�h�X  >>�п�J�Ʀr��ܾާ@:";

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
			
			cout << "�Э��s��J:";
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
#include <iostream>
#include <string>

class Player
{
public:
	Player() // ��������� �����������
	{
		name = "Default";
		score = 1000;
	}

	Player(std::string N, int S) 	// ����������� ��� ���������� ����������
	{
		name = N;
		score = S;
	}
	int score;
	std::string name;

	void Show()
	{
		std::cout << "Player name: " << name << " " << "Player score: " << score << std::endl;
	}

};

int main()
{
	int x = 0; // ��������� ���������� ��� ������� �������
	std::cout << "How many players to create?" << std::endl;
	std::cin >> x;
	Player* Players = new Player[x]; //������ ������ �������, �������� X


	for (int i = 0; i < x; ++i) //��������� ������
	{
		int localScore;
		std::string localName;

		std::cout << "Enter name player: " << std::endl;
		std::cin >> localName;
		std::cout << "Enter score player: " << std::endl;
		std::cin >> localScore;

		Players[i] = *new Player(localName, localScore);
	}

	//����������� ���������� 
	for (int j = 1; j < x; j++) //������ �� ����������
	{
		for (int r = x-1; r >= j; r--) //������ �� �������� 
		{
			if (Players[r - 1].score < Players[r].score) // ������ ������� ���� 
			{
				Player temp = Players[r - 1]; //��������� ���������� ����������� ������ �����
				Players[r - 1] = Players[r];
				Players[r] = temp;
			}
		}
	}

	std::cout << "\n";
	std::cout <<  "Score board from leader to lowest: " << "\n";
	

	for (int i = 0; i < x; ++i) // ����� ������� 
	{
		Players[i].Show();
	}

	delete[] Players;

	return 0;

}



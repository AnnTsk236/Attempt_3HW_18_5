#include <iostream>
#include <string>

class Player
{
public:
	Player() // ��������� �����������
	{
		name = "Default";
		score = 777;
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
		std::cout << "Player name: " << name << "Player score: " << score << std::endl;
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

		std::cout << "Input name: " << std::endl;
		std::cin >> localName;
		std::cout << "Input score: " << std::endl;
		std::cin >> localScore;

		Players[i] = *new Player(localName, localScore);
	}

	Players temp;

	for (int j = 1; j < Players; j++) //������ �� ����������
	{
		for (int r = 1; r < Players; r >= j; r--) //������ �� �������� 
		{
			if (Players[r - 1].score > Players[r].score) // ������ ������� 
			{
				Players temp = Players[r - 1];
				Players[r - 1] = Players[r];
				Players[r] = temp;
			}
		}
	}

	std::cout << "\n";
	

	for (int i = 0; i < Players; ++i) // ����� ������� 
	{
		Players[i].Show();
	}



	return 0;
}



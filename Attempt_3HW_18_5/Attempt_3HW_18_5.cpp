#include <iostream>
#include <string>

class Player
{
public:
	Player() // дефолтный конструктор
	{
		name = "Default";
		score = 777;
	}

	Player(std::string N, int S) 	// конструктор для заполнения переменных
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
	int x = 0; // временная переменная для размера массива
	std::cout << "How many players to create?" << std::endl;
	std::cin >> x;
	Player* Players = new Player[x]; //создаём массив игроков, размером X


	for (int i = 0; i < x; ++i) //заполняем массив
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

	for (int j = 1; j < Players; j++) //Массив на увеличение
	{
		for (int r = 1; r < Players; r >= j; r--) //Массив на убывание 
		{
			if (Players[r - 1].score > Players[r].score) // Меняем местами 
			{
				Players temp = Players[r - 1];
				Players[r - 1] = Players[r];
				Players[r] = temp;
			}
		}
	}

	std::cout << "\n";
	

	for (int i = 0; i < Players; ++i) // Вывод массива 
	{
		Players[i].Show();
	}



	return 0;
}



#include <iostream>
#include <algorithm>
#include <vector>
#include <Windows.h>
#include<ctime>

#define NOT_FOUND -1

using namespace std;

int counter = 0;
int health = 0;
class Random
{
public:
	static int randRange(int begin, int end)
	{
		return rand() % (end - begin) + begin;
	}

	template<class T>
	static T getRandomElementFromArray(const T vec[], int size)
	{
		return vec[randRange(0, size)];
	}

	template<class T>
	static T getRandomElementFromVector(const vector<T> vec)
	{
		return vec[randRange(0, vec.size())];
	}

};

class Player
{
public:

	Player(const string& selectedWord, int health) : m_selectedWord{ selectedWord }, m_health{ health }
	{
	}

	void setFoundCountSymbols(int count)
	{
		m_countFoundSymbols = normalize(count);
	}

	size_t getFoundCountSymbols() const
	{
		return m_countFoundSymbols;
	}

	const string& getSelectedWord() const
	{
		return m_selectedWord;
	}

	int getHealth() const
	{
		return m_health;
	}

	void setHealth(int health)
	{
		m_health = normalize(health);
	}

	bool isDie()
	{
		return m_health == 0;
	}

private:

	int normalize(int number)
	{
		return number > 0 ? number : 0;
	}

	int m_countFoundSymbols{ 0 };
	int m_health{ 0 };
	int m_pictureArr{ 7 };

	string m_selectedWord;

};

class Game
{
public:
	clock_t t0 = clock();
	Game(Player& player, const std::string* dictionary) : m_player{ player }, m_dictionary{ dictionary },
		m_foundedLetters(player.getSelectedWord().size(), '_')
	{


	}
	void launch()
	{
		cout << "Слово: ";
		for_each(m_player.getSelectedWord().begin(), m_player.getSelectedWord().end(), [](const auto e) {std::cout << '_' << " "; });

		char letter;

		string foundedLetters(m_player.getSelectedWord().size(), '_');

		while (m_player.getFoundCountSymbols() < m_player.getSelectedWord().size() && !m_player.isDie())
		{

			cout << "\nУгадайте букву: ";
			cin >> letter;

			letter = toupper(letter);

			if (m_player.getSelectedWord().find(letter) != NOT_FOUND)
			{
				cout << "Верно: ";

				for (int index{ 0 }; index < m_player.getSelectedWord().size(); ++index)
				{
					if (m_player.getSelectedWord()[index] == letter)
					{
						foundedLetters[index] = letter;
						m_player.setFoundCountSymbols(m_player.getFoundCountSymbols() + 1);
					}

					cout << foundedLetters[index] << " ";
				}
				counter++;
			}
			else
			{
				m_player.setHealth(m_player.getHealth() - 1);
				cout << "Неверно! Такой буквы нет, у вас осталось " << m_player.getHealth() << " попыток неверно указать букву!" << endl;
				counter++;
				health++;
				switch (health)
				{
				case 1:
					cout << "_______________________" << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||           ||    " << endl;
					cout << "____||___________||____" << endl;
					break;
				case 2:
					cout << "_______________________" << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||   _____   ||    " << endl;
					cout << "____||_____П_____||____" << endl;
					break;
				case 3:
					cout << "_______________________" << endl;
					cout << "    ||     |     ||    " << endl;
					cout << "    ||     Q     ||    " << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||   _____   ||    " << endl;
					cout << "____||_____П_____||____" << endl;
					break;
				case 4:
					cout << "_______________________" << endl;
					cout << "    ||     |     ||    " << endl;
					cout << "    ||     Q     ||    " << endl;
					cout << "    ||    /O\\    ||    " << endl;
					cout << "    ||   __Л__   ||    " << endl;
					cout << "____||_____П_____||____" << endl;
				case 5:
					cout << "_______________________" << endl;
					cout << "    ||     |     ||    " << endl;
					cout << "    ||     |     ||    " << endl;
					cout << "    ||     Q     ||    " << endl;
					cout << "    ||    /O\\    ||    " << endl;
					cout << "    ||     Л     ||    " << endl;
					cout << "____||___________||____" << endl;
					break;
				}
			}

		}
	}

	void sumUp()
	{
		clock_t t1 = clock();
		if (m_player.getFoundCountSymbols() == m_player.getSelectedWord().size()) cout << "\n\nПоздравляем: Вы выиграли!" << endl;
		else cout << "Вы проиграли, угадав " << m_player.getFoundCountSymbols() << " букв." << endl;
		cout << "Ушло попыток " << counter << endl;
		cout << "time: " << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;
	}

private:
	Player& m_player;
	const string* m_dictionary;

	string m_foundedLetters;
};

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");

	cout << "Добро пожаловать в игру \"Виселица\"" << endl;

	constexpr int WORD_COUNT{ 10 };
	string words[WORD_COUNT]{ "АРБУЗ","КОШКА","ПРОГРАММА","ГИТАРА" ,"ЭКРАН" ,"ПИТОН" ,"МАШИНА" ,"ГАРАЖ", "ЯЗЫК", "КНИГА" };

	Player player(Random::getRandomElementFromArray(words, WORD_COUNT), 5);
	Game game(player, words);

	game.launch();
	game.sumUp();

	return 0;
}
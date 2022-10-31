#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <Windows.h>
#include<ctime>
#define NOT_FOUND -1
using namespace std;
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
		for_each(m_player.getSelectedWord().begin(), m_player.getSelectedWord().end(), [](const auto e) {cout << '_' << " "; });

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

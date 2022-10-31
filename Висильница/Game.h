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
		cout << "�����: ";
		for_each(m_player.getSelectedWord().begin(), m_player.getSelectedWord().end(), [](const auto e) {cout << '_' << " "; });

		char letter;

		string foundedLetters(m_player.getSelectedWord().size(), '_');

		while (m_player.getFoundCountSymbols() < m_player.getSelectedWord().size() && !m_player.isDie())
		{

			cout << "\n�������� �����: ";
			cin >> letter;

			letter = toupper(letter);

			if (m_player.getSelectedWord().find(letter) != NOT_FOUND)
			{
				cout << "�����: ";

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
				cout << "�������! ����� ����� ���, � ��� �������� " << m_player.getHealth() << " ������� ������� ������� �����!" << endl;
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
					cout << "____||_____�_____||____" << endl;
					break;
				case 3:
					cout << "_______________________" << endl;
					cout << "    ||     |     ||    " << endl;
					cout << "    ||     Q     ||    " << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||           ||    " << endl;
					cout << "    ||   _____   ||    " << endl;
					cout << "____||_____�_____||____" << endl;
					break;
				case 4:
					cout << "_______________________" << endl;
					cout << "    ||     |     ||    " << endl;
					cout << "    ||     Q     ||    " << endl;
					cout << "    ||    /O\\    ||    " << endl;
					cout << "    ||   __�__   ||    " << endl;
					cout << "____||_____�_____||____" << endl;
				case 5:
					cout << "_______________________" << endl;
					cout << "    ||     |     ||    " << endl;
					cout << "    ||     |     ||    " << endl;
					cout << "    ||     Q     ||    " << endl;
					cout << "    ||    /O\\    ||    " << endl;
					cout << "    ||     �     ||    " << endl;
					cout << "____||___________||____" << endl;
					break;
				}
			}

		}
	}

	void sumUp()
	{
		clock_t t1 = clock();
		if (m_player.getFoundCountSymbols() == m_player.getSelectedWord().size()) cout << "\n\n�����������: �� ��������!" << endl;
		else cout << "�� ���������, ������ " << m_player.getFoundCountSymbols() << " ����." << endl;
		cout << "���� ������� " << counter << endl;
		cout << "time: " << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;
	}

private:
	Player& m_player;
	const string* m_dictionary;

	string m_foundedLetters;
};

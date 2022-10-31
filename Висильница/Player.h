#pragma once
#include"Game.h"
#include"Random.h"
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
	int m_pictureArr{ 15 };

	string m_selectedWord;

};

#pragma once
#include"Game.h"
#include"Player.h"
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

#include"Game.h"
#include"Player.h"
#include"Random.h"


int counter = 0;
int health = 0;


int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");

	cout << "����� ���������� � ���� \"��������\"" << endl;

	constexpr int WORD_COUNT{ 10 };
	string words[WORD_COUNT]{ "�����","�����","���������","������" ,"�����" ,"�����" ,"������" ,"�����", "����", "�����" };

	Player player(Random::getRandomElementFromArray(words, WORD_COUNT), 5);
	Game game(player, words);

	game.launch();
	game.sumUp();

	return 0;
}
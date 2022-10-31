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

	cout << "Äîáðî ïîæàëîâàòü â èãðó \"Âèñåëèöà\"" << endl;

	constexpr int WORD_COUNT{ 10 };
	string words[WORD_COUNT]{ "ÀÐÁÓÇ","ÊÎØÊÀ","ÏÐÎÃÐÀÌÌÀ","ÃÈÒÀÐÀ" ,"ÝÊÐÀÍ" ,"ÏÈÒÎÍ" ,"ÌÀØÈÍÀ" ,"ÃÀÐÀÆ", "ßÇÛÊ", "ÊÍÈÃÀ" };

	Player player(Random::getRandomElementFromArray(words, WORD_COUNT), 5);
	Game game(player, words);

	game.launch();
	game.sumUp();

	return 0;
}
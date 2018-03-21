
//#include "GameMove.h"
#include <conio.h>
#include <iostream>
#include "Game.h"
#include "move.h"
#include "fire.h"
using namespace std;

int main() {
	int enemyt = 3;

	
	CGame *game = new CGame(30,20, enemyt);
	game->show();
	
	fire* fr = new fire();
	cmove* mv = new cmove();
	
	bool stop = false;
	
	while ((game->getT()>0) &&(!stop)) {
		switch (_getch()) {
		case 72:
			stop=mv->moveAll(72);

			break;
		case 80:
			stop = mv->moveAll(80);
			break;
		case 75:
			stop = mv->moveAll(75);
			break;
		case 77:
			stop = mv->moveAll(77);
			break;
		case 32:
			fr->fireTanks();
			break;

			
		}
		cout << "enemy tanks left=" << game->getT() << endl;	
		cout << "you have " << game->getcounter() << " lives left "<< endl;
		if (game->getT()==0) {			
			cout << "u win. game over.";	

		}
		if (stop) {
			int c = game->getcounter()-1;
			game->setcounter(c);
			if (game->getcounter() <= 0) {
				cout << "u are dead. game over.";
				
			}
			else {
				game->resurrection();
				stop = false;
			}
		}
	}
	delete game;
	_getch();
}


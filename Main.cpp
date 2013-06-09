#include "Cell.hpp"

#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

int getposition(const char *array, size_t size, char c)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == c)
            return (int)i;
    }
    return -1;
}

int main() {
	int control = 0;
	bool lose = false;
	bool win = false;
	clock_t start;
	double duration;
	int width, height, numMines;
	char input;
    char row;
    int column, int_row;

	while (1){
		// pretty ASCII art that will print every time you loop back to the main menu
		cout << "          \\|/ " << endl;
		cout << "         .-*-   " << endl;
		cout << "        / /|\\    " << endl;
		cout << "       _L_ " << endl;
		cout << "     ,\"   \".        _ " << endl;                                            
		cout << " (\\ /  O O  \\ /)   | |______    __    ______                           " << endl;  
		cout << "  \\|    _    |/    |_|   __|___| |___|   __|_ _ _ ___ ___ ___ ___ ___ " << endl;
		cout << "    \\  (_)  /        |__   | . | | -_|__   | | | | -_| -_| . | -_|  _| " << endl;
		cout << "    _/.___,\\_        |_____|___|_|___|_____|_____|___|___|  _|___|_|  " << endl;
		cout << "   (_/     \\_)                                           |_|       " << endl;

		// MENU OPTIONS
		cout << "1 - Start Game			2 - Credits			3 - Quit " << endl;
		cout << "Selection: ";
		cin >> control;

		// PLAY GAME
		if (control == 1){
			cout << "What size grid do you want to play on?" << endl;
			cout << "Width: ";
			cin >> width;
			cout << "\n Height: ";
			cin >> height;
			cout << "How many mines do you want to play with? ";
			cin >> numMines;

			// create grid with width, height, and number of mines

			// starting the clock
			start = clock();
	
			// initialize the grid
            Grid grid = new Grid (width, height, numMines);
            while(!gameOver){
                cout << "Click[C] or flag[F]";
                cin >> input;
                cout << "What row? (a-y)";
                cin >> row;
                cout << "What column (#)";
                cin >> column;
                
                char alph[25] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y'};
                int_row = getposition(alph, 25, row);
                
                if (input == 'C'){
                    if(!grid.click(int_row, column)) {
                        gameOver = true;
                        lose = true;
                    }
                    
                }
                if (input == 'F') {
                    grid.flag(int_row, column);
                }
                
                if (grid.hasWon()) { gameOver = true; win = true; }
            }
            }
			if (lose) {
				/*
				cout << " __   __   ___    _   _             _       ___     ___    _____  " << endl;
				cout << " \ \ / /  / _ \  | | | |    o O O  | |     / _ \   / __|  |_   _| " << endl;
				cout << "  \ V /  | (_) | | |_| |   o       | |__  | (_) |  \__ \    | |   " << endl;
				cout << "  _|_|_   \___/   \___/   TS__[O]  |____|  \___/   |___/   _|_|_ " << endl;
				cout << "_| ''' |_|'''''|_|'''''| {======|_|''''''|_|''''|_|'''''|_|'''''| " << endl;
				cout << " '-0-0-'''-0-0-'''-0-0-'./o--000'''-0-0-''`-0-0-'''-0-0-'''-0-0-' " << endl;
				*/
				cout << "__     ______  _    _   _      ____   _____ _______ " << endl;
				cout << "\\ \\   / / __ \\| |  | | | |    / __ \\ / ____|__   __| " << endl;
				cout << " \\ \\_/ / |  | | |  | | | |   | |  | | (___    | |   " << endl;
				cout << "  \\   /| |  | | |  | | | |   | |  | |\\___ \\   | |   " << endl;
				cout << "   | | | |__| | |__| | | |___| |__| |____) |  | |   " << endl;
				cout << "   |_|  \\____/ \\____/  |______\\____/|_____/   |_|   " << endl;
			}
			if (win){
				cout << " __     ______  _    _  __          _______ _   _ " << endl;
				cout << " \\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | |" << endl;
				cout << "  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| |" << endl;
				cout << "   \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` |" << endl;
				cout << "    | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  |" << endl;
				cout << "    |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_|" << endl;

			}

			duration = (clock() - start ) / (double)CLOCKS_PER_SEC;
			cout << "Game duration: "<< duration << endl;
		}

		// PRINT CREDITS
		else if (control == 2) {
			cout << "\n======= CREDITS ======= " << endl;
			cout << "TEAM AWESOME: Lanya Butler, Craig Disselkoen, and Connie Lu" << endl;
			cout << "SPIRE - EIT 2013 \n" << endl;
		}

		// QUIT GAME
		else if (control == 3) {
			cout << "\n Quitting... Thanks for playing! " << endl;
			break;
		}
		else {;}
	}
	return 0;
}
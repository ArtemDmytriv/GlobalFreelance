
//- Your name, course name, and class time
//- Program assignment number, program file nameand due date
//- A sentence or two explaining the purpose of the program
//- Input: user enters names of first and second players
//- Program use random generate for dice, for simulating moves
//- Result: Displays all moves and winner of the game

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;


// get random number (1 - 6)
int RollDice();

// check if player has reached or passed end position 81
bool Win(int, int);

// Func to move player, takes current position and die number
int Move(int, int);

// Print information by one move by player
void PrintOneMove(string, int, int, int, int);

// Check if chute is in this position
int CheckChutes(int);

// Check if ladder is in this position
int CheckLadders(int);

// Print header in the program start
void PrintHeader(void);

// Prints separator between the moves
void PrintTurnSeparator(void);

// func set only correct players names (non zero length, not equal)
void GetPlayerNames(string& pl1, string& pl2);


int main() {

	srand(unsigned int(time(0)));
	
	int player1 = 1, player2 = 1;
	string pl1 = "Judy" , pl2 = "Jane";

	// Set users player names
	GetPlayerNames(pl1, pl2);
	
	int dice;
	int turn = 1; // turn counter 
	int end = 81; // end position
	
	PrintHeader();

	// while at least one player has not reached the end, the loop is working
	while (!Win(player1, end) && !Win(player2, end)) {

		// Player1 turn
		dice = RollDice();

		// Save new position
		int newplayer1 = Move(player1, dice);
	
		PrintOneMove(pl1, turn, player1, dice, newplayer1);
		
		// update position to the new position after move
		player1 = newplayer1;

		// Player2 turn
		dice = RollDice();

		// Save new position
		int newplayer2 = Move(player2, dice);

		PrintOneMove(pl2, turn, player2, dice, newplayer2);

		// update position to the new position after move
		player2 = newplayer2;

		// Print separator and increase turn counter
		PrintTurnSeparator();
		turn++;
	}

	if (Win(player1, end)) {
		cout << endl <<  pl1 << " Wins!!!" << endl;
	}
	else {
		cout << endl << pl2 << " Wins!!!" << endl;
	}

	return 0;
}

int RollDice()
{
	return rand() % 6 + 1;
}

bool Win(int pos, int fin)
{
	return pos >= fin;
}

int Move(int pos, int turn)
{
	int newpos = pos + turn;
	if ((newpos = CheckChutes(newpos)) != pos + turn) {
		return newpos;
	}
	else if ((newpos = CheckLadders(newpos)) != pos + turn) {
		return newpos;
	}
	else {
		return newpos;
	}
}

void PrintOneMove(string name, int i, int curr, int die, int newpos) 
{
	cout << left << setw(14) << name << setw(16) << i << setw(15) << curr;
	cout << setw(12) << die << setw(12) << newpos << endl;
}

int CheckChutes(int pos)
{
	int	chutesTop[6]    { 11, 15, 30, 44, 58, 64};
	int chutesBottom[6] { 4,  7, 21, 31, 43, 54 };

	for (int i = 0; i < 6; i++) {
		if (pos == chutesTop[i]) {
			return chutesBottom[i];
		}
	}

	return pos;
}

int CheckLadders(int pos)
{
	int	laddersBottom[6] { 8, 12, 28, 33, 48, 59  };
	int laddersTop[6]    { 16, 27, 39, 46, 55, 75 };

	for (int i = 0; i < 6; i++) {
		if (pos == laddersBottom[i]) {
			return laddersTop[i];
		}
	}

	return pos;
}

void PrintHeader(void)
{
	cout << left << setw(10) << "Player" << setw(15) << "Move Number" << setw(20) << "CurrentPosition";
	cout << setw(8) << "Die" << setw(17) << "NewPosition" << endl;

	int n = 8;
	while (n--) cout << "********";
	
	cout << endl;
}

void PrintTurnSeparator(void)
{
	int n = 8;
	while (n--) cout << "--------";
	
	cout << endl;
}

void GetPlayerNames(string& pl1, string& pl2)
{
	do {
		cout << "Enter player1 name: ";
		cin >> pl1;

		cout << "Enter player2 name: ";
		cin >> pl2;

		if (pl1 == pl2 || pl1.size() == 0 || pl2.size() == 0) {
			cout << "Incorrect input, try again..." << endl;
		}
		else {
			break;
		}

	} while (1); 
}




class TTTControlle
public:
void createPlayer(string name, string marker, int playerNum=1);
void startNewGame();
bool setSelection(int row, int col, int currentPlayer);
// row and col: have to be valid, between 0-2
// currentPlayer: 1=player1; 2=player2
//return bool: valid and available location
int determineWinner();
//return winner;
//0= no winner; 1=player1; 2=player2;
3=tie/no more available locations
string getGameDisplay();
//printable display of current selections;
//shows each players marker

//KingOFMongeese
//July 23, 2022
//Tic Tac Toe

#include <stdio.h>
#include <stdlib.h>

//prototypes
void printBoard(void);
void printHelp(void);
void doTurn(void);
void resolveMove(char target);
void getMove(void);
int validMove(char move);
int checkVictory(void);
int catsGame(void);
void passTurn(void);

//global vars
char turn = 'X';
int isGameover = 0;
char board[3][3];

int main(void)
{
	//print instructions and populate the board
    printf("All spaces are numbered for input following this pattern:\n1 2 3\n4 5 6\n7 8 9\nIf you need to see this pattern again enter a '?' when prompted for your move.\n");
	
    for (int rows = 0; rows < 3; rows++)
    {
        for (int cols = 0; cols < 3; cols++)
        {
            board[rows][cols] = '-'; 
        }
    }

    while(!(isGameover))
    {
		//main loop of the game
        doTurn();
        if (checkVictory())
        {
            isGameover = 1;
            printf("GAME OVER!\n%c won. Congrats\n", turn);
            printBoard();

        }
        else if (catsGame())
        {
            isGameover = 1;
            printf("GAME OVER!\nCats game.\n", turn);
            printBoard();
        }
        else 
        {
            passTurn();
        }
        
    }
    return 0;
}

void printBoard(void)
{
	
    for (int rows = 0; rows < 3; rows++)
    {
        for (int cols = 0; cols < 3; cols++)
        {
            printf("%c ", board[rows][cols]);
        }
        printf("\n");
    }
}

void printHelp(void)
{
    printf("1 2 3\n4 5 6\n7 8 9\n");
}

void doTurn(void)
{   
    printBoard();
    printf("It is %c's turn.\n", turn);
    getMove();
}

void resolveMove(char target)
{
    switch (target)
    {
        case '1': board[0][0] = turn; break;
        case '2': board[0][1] = turn; break;
        case '3': board[0][2] = turn; break;
        case '4': board[1][0] = turn; break;
        case '5': board[1][1] = turn; break;
        case '6': board[1][2] = turn; break;
        case '7': board[2][0] = turn; break;
        case '8': board[2][1] = turn; break;
        case '9': board[2][2] = turn; break;
    }
}

void getMove(void)
{
	//gets move input from console then processes
    char move;
    printf("Enter your move: ");
    move = getchar();

    //flush in buffer
    int b;
    while(b = getchar() != '\n' && b != EOF){}

    switch (move)
    {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6': 
        case '7': 
        case '8':
        case '9': if (validMove(move)) 
                 {
                    resolveMove(move); 
                    break;
                 }
                 else
                 {
                    printf("Invalid Move!\n");
                    getMove();
                    break;
                 }
    
        case '?': printHelp(); printf("--------------------------\n"); printBoard(); printf("It is %c's turn.\n", turn); getMove(); break;

        default: printf("Invalid option!\n"); getMove(); break;
    }
}

int validMove(char move)
{
    //prevents duplicate moves
    static char moves[9];
    static int movesMade = 0;
    int valid = 1;

    for (int i = 0; i < 9; i++)
    {
        if (moves[i] == move)
        {
            valid = 0;
        }
    }

    if (valid == 1)
    {
        moves[movesMade++] = move;
    }

    return valid;

}

int checkVictory(void)
{
    //returns true (1) if current player won
    for (int row = 0; row < 3; row++)
    {
        int hcount = 0;
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == turn)
            {
                hcount++;
            }
        }
        if (hcount == 3)
        {
            
            return 1;
        }
    }

    for (int col = 0; col < 3; col++)
    {
        int vcount = 0;
        for(int row = 0; row < 3; row++)
        {
            if (board[row][col] == turn)
            {
                vcount++;
            }
        }
        if (vcount == 3)
        {
            
            return 1;
        }
    }

    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)
    {
        
        return 1;
    }

    if (board[2][0] == turn && board[1][1] == turn && board[0][2] == turn)
    {
        
        return 1;
    }

    return 0;

}

int catsGame(void)
{
    //returns true (1) if it is a cats game
    int count = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] != '-')
            {
                count++;
            }
        }
    }

    if (count == 9)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void passTurn(void)
{
	//passes the turn to the next player
    if (turn == 'X')
    {
        turn = 'Y';
    }
    else 
    {
        turn = 'X';
    }
}

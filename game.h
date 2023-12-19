#ifndef game
#define game

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



typedef struct Board
{
    int row;
    int col;
    char** table;
}Board;

typedef struct Player{
    char element;
    char* playerName;
}Player;

typedef struct Turn{
    int turn;
    struct Turn* next;
}Turn;

typedef struct GameController{
    Turn* gameTurn; 
    Player playerX;
    Player playerO;
    char* pattern;
    int playerChoice;
}GameController;

Board initializeBoard(Board mainBoard);
Board updateBoard(Board mainBoard, GameController gameController);
GameController initializeGameController(GameController gameController);
void printBoard(Board mainBoard, GameController gameController);


#endif
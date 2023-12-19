#include "game.h"

const int row = 7;
const int col = 13;

Board updateBoard(Board mainBoard, GameController gameController){
    for(int i = 0; i<9; i++){
        if(gameController.pattern[i] == 'X'){
            mainBoard.table[2*(i/3)+1][4*(i%3)+2] = 'X'; 
        }
        else if(gameController.pattern[i] == 'O'){
            mainBoard.table[2*(i/3)+1][4*(i%3)+2] = 'O';
        }
    }
    return mainBoard;
}

Board initializeBoard(Board mainBoard){
    mainBoard.row = row;
    mainBoard.col = col;
    mainBoard.table = (char**)malloc(sizeof(char*) * mainBoard.row);
    for(int i = 0; i<mainBoard.row; i++)
        mainBoard.table[i] = (char*)malloc(sizeof(char) * mainBoard.col);
    for(int i = 0; i<mainBoard.row; i++){
        for(int j = 0; j<mainBoard.col; j++){
            if(i == 0 || i == mainBoard.row-1 || i % 2 == 0){
                mainBoard.table[i][j] = '-';
            }
            else if(j == 0 || j == mainBoard.col-1 || j % 4 == 0){
                mainBoard.table[i][j] = '|';
            }
            else{
                mainBoard.table[i][j] = ' ';
            }
        }
    }
    return mainBoard;
}

void printBoard(Board mainBoard, GameController gameController){
    for(int i = 0; i<mainBoard.row; i++){
        for(int j = 0; j<mainBoard.col; j++){
            printf("%c",mainBoard.table[i][j]);
        }
        printf("\n");
    }
    if(gameController.gameTurn->turn == 0){
        printf("%s's turn\n",gameController.playerX.playerName);    
    }
    else{
        printf("%s's turn\n",gameController.playerO.playerName);
    }

    printf("You can choose the below numbers.\n");
        for(int i = 0; i<9; i++){
            if(gameController.pattern[i] == ' '){
                printf("%d. ",i+1);
            }
        }
    printf("\n");

}



void initializePlayerElement(char* playerElement1, char* playerElement2){
    *playerElement1  = 'X';
    *playerElement2 = 'O';
}

void initializePlayerName(char** playerName1, char** playerName2){
    // allocate memory for player names
    *playerName1 = (char*)malloc(sizeof(char) * 100); 
    *playerName2 = (char*)malloc(sizeof(char) * 100); 

    // get player names
    printf("What is your name Player 1: ");
    scanf("%s",*playerName1);
    printf("What is your name Player 2: ");
    scanf("%s",*playerName2);
}

void initializeTurn(Turn** gameTurn){
    *gameTurn = (Turn*)malloc(sizeof(Turn));
    (*gameTurn)->turn = 0;
    (*gameTurn)->next = (Turn*)malloc(sizeof(Turn));
    (*gameTurn)->next->turn = 1;
    (*gameTurn)->next->next = *gameTurn;
}

void initializePattern(char** pattern){
    *pattern = (char*)malloc(sizeof(char) * 9);
    for(int i = 0; i<9; i++){
        (*pattern)[i] = ' ';
    }
}

// initializing game controller struct
GameController initializeGameController(GameController gameController){
    initializePlayerName(&gameController.playerX.playerName, &gameController.playerO.playerName);
    initializePlayerElement(&gameController.playerX.element, &gameController.playerO.element);
    initializeTurn(&gameController.gameTurn);
    initializePattern(&gameController.pattern);
    return gameController;
}


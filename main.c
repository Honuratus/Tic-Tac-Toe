#include "game.h"

int posibilities[8][3] = {{1,5,9},{3,5,7},{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9}}; 

int main(){
    system("cls"); // Cleaning all other terminal commands
    
    printf("Welcome the XOX game!!\n");
    printf("Press any key to start...\n");
    getchar();
    system("cls");
    
    // Setting up variables before the loop
    GameController gameController;
    gameController = initializeGameController(gameController);

    Board mainBoard;
    mainBoard = initializeBoard(mainBoard);

    system("cls");
    printf("Welcome %s and %s press any key to continue...\n",gameController.playerX.playerName,gameController.playerO.playerName);
    getch();
    system("cls");
    
    while(1){
        for(int i = 0; i<8; i++){
            if(gameController.pattern[posibilities[i][0]-1] == gameController.pattern[posibilities[i][1]-1] && gameController.pattern[posibilities[i][1]-1] == gameController.pattern[posibilities[i][2]-1]){
                if(gameController.pattern[posibilities[i][0]-1] == 'X'){
                    printf("Game is over. %s won the game.\n",gameController.playerX.playerName);
                    getch();
                    return 0;
                }
                else if(gameController.pattern[posibilities[i][0]-1] == 'O'){
                    printf("Game is over. %s won the game.\n",gameController.playerO.playerName);
                    getch();
                    return 0;
                }
            }
        }
        for(int i = 0; i<9; i++){
            if(gameController.pattern[i] == ' '){
                break;
            }
            if(i == 8){
                printf("Game is over. No one won the game.\n");
                getch();
                return 0;
            }
        }
        // Printing the board
        printBoard(mainBoard, gameController);
        scanf("%d",&gameController.playerChoice);
        if(gameController.playerChoice < 1 || gameController.playerChoice > 9 || gameController.pattern[gameController.playerChoice-1] != ' '){
            printf("You entered wrong number. For retyping press a chracter..\n");
            getch();
            system("cls");
            continue;
        }
        if(gameController.gameTurn->turn == 0){
            gameController.pattern[gameController.playerChoice-1] = gameController.playerX.element;
        }
        else{
            gameController.pattern[gameController.playerChoice-1] = gameController.playerO.element;
        }    
    
        gameController.gameTurn = gameController.gameTurn->next;

        mainBoard = updateBoard(mainBoard, gameController);
        
        system("cls");
    }
   
    return 0;    
}
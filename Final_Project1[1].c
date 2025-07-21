#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i,j;

// Making array with DMA
char **Board(int rows, int cols) {
    char **board = (char **)malloc(rows * sizeof(char *));
    for (i = 0; i < rows; i++) {
        board[i] = (char *)malloc(cols * sizeof(char));
        for (j = 0; j < cols; j++) {
            board[i][j] = ' '; // You can set any initial value here
        }
    }
    return board;
}

void printBoard(char **board, int rows, int cols) {
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n-----------------------------------\n");
    }
}

void initializeBoard(char **board, int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        j = 48 + i;
        board[0][i] = j;
        board[i][0] = j;
        (int)j;
        j++;
    }

    for (i = 1; i < rows; i++) {
        for (j = 1; j < cols; j++) {
            if (i % 2 == 1) {
                if (j % 2 == 0) {
                    board[i][j] = ' ';
                } else if (i < 4 && (j % 2 == 1)) {
                    board[i][j] = 'X';
                } else if (i > 5 && (j % 2 == 1)) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                if (j % 2 == 1) {
                    board[i][j] = ' ';
                } else if (i < 4 && (j % 2 == 0)) {
                    board[i][j] = 'X';
                } else if (i > 5 && (j % 2 == 0)) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }
}

int checkWinner(char **board, int rows, int cols) {
    int win_x = 0, win_o = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'A') {
                win_x++;
            } else if (board[i][j] == 'O' || board[i][j] == 'B') {
                win_o++;
            }
        }
    }

    if (win_x == 0) {
        printf("Player 2 is the winner!\nCongratulations!");
        return 1; // Indicates Player 2 is the winner
    } else if (win_o == 0) {
        printf("Player 1 is the winner!\nCongratulations!");
        return 2; // Indicates Player 1 is the winner
    }

    return 0; // Indicates no winner yet
}

void freeBoard(char **board, int rows) {
    for (i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);
}

int main() {
    srand(time(NULL));
    int x, i, j, moves = 0, x1, y1, x2, y2, comp = 1;
    int rows = 9;
    int cols = 9;
    int choice,consecutive_invalid_moves;
    int  invalid_move_count;
   int t_time,clock_start;
   
    printf("\t\t\t\t\t WELCOME TO CHECKERS BOARD GAME\n\n\n\n");
    printf("This is a two player game\nyou have to enter a move your move within the time period of 60 seconds ");
    printf("Game Mode Selection:\nAt the beginning of the game, the player is prompted to choose between two game modes: \n");
      printf(" Multiplayer or Single Player.\n\n");
printf("\n1. Board Initialization:\nThe game board is represented as a 9x9 grid.\n");
            printf("\n2. Player Movements:\nIn multiplayer mode, two players take turns making moves.");
            printf("\nIn single-player mode, the player competes against a computer opponent (AI).\n");
            printf("\n3. Player Pieces:\nPlayer 1 is represented by 'X,' and Player 2 (or the computer in single-player mode) is represented by 'O.'\n");
            printf("\n4. Move Input:\nPlayers are prompted to enter the positions of the piece they want to move and the position to which they want to move \nit.\n");
            printf("\n5. Move Validation:\nInvalid moves are detected and players are prompted to enter a valid move. Invalid moves include selecting a position \nwithout a player's piece or attempting an illegal move.\n");
            printf("\n6. Time Limit:\nA time limit of 60 seconds is imposed on each move. If the time limit is exceeded, the move is considered invalid.\n");
            printf("\n7. Capture Mechanism:\nPlayers can capture opponent pieces by moving diagonally and landing on a square occupied by an \nopponent piece. Captured pieces are removed from the board.\n");
            printf("\n8. Draw Condition:/nThe game can end in a draw if there are four consecutive invalid moves.\n");
            printf("\n9. Output Display:\nThe current state of the board is displayed after each move.\n");
    printf("Enter the mode in which you want to play:\n1 For multiplayer \n2 For single player\n");
    scanf("%d", &choice);
    int current_player;
    switch (choice) {
         case 1: {
            char **board = Board(rows, cols);
            initializeBoard(board, rows, cols);
            printBoard(board, rows, cols);

            while (x == 0) {
                // Multiplayer logic here
                for (moves = 0; ; moves++) {
                    if (moves % 2 == 0) {
                        current_player = 1;
                    } else {
                        current_player = 2;
                    }

                    int invalid_move_count = 0;

                    do {
                    if (current_player == 1) {
                    	
            clock_t start = clock();        	
                    	
            printf("Enter the positions of the piece you want to move for player(X) 1: ");
            scanf("%d %d", &x1, &y1);
            
            clock_t end = clock();
                    double time_taken = ((double)end - start)/CLOCKS_PER_SEC;
                    if(time_taken<60)
						printf("Time Taken : %.2f Seconds\n",time_taken);
                         
                    else if(time_taken>60.0)
                    {
                    	t_time = time_taken/60;
                    	printf("Time Limit Exceeded! Time Taken : %.2f Minutes\n Move is Invalid\n",t_time);
                    	continue;
					}

            if (board[x1][y1] != 'X' && board[x1][y1] != 'A') {
                printf("Invalid input! Please enter a valid move.\n");
                invalid_move_count++;
                continue;

                if (invalid_move_count == 2) {
                    printf("Player 2's turn!\n");
                    break;
                }
            } else {
            	
            	    clock_t start = clock();
            	
	                printf("Enter the position you want to move for player(X) 1: ");
	                scanf("%d %d", &x2, &y2);
	                
	                clock_t end = clock();
	                    double time_taken = ((double)end - start)/CLOCKS_PER_SEC;
	                    if(time_taken<60)
							printf("Time Taken : %.2f Seconds\n",time_taken);
	                         
	                    else if(time_taken>60.0)
	                    {
	                    	t_time = time_taken/60;
	                    	printf("Time Limit Exceeded! Time Taken : %.2f Minutes\n Move is Invalid\n",t_time);
	                    	continue;
						}

                if (board[x1][y1] == 'X') {
                    // Normal move for 'X'
                    if ((x2 == x1 + 1) && ((y2 == y1 + 1) || (y2 == y1 - 1)) && (x2 > 0 && x2 <= 8) && (y2 > 0 && y2 <= 8)) {
                        if (board[x2][y2] == ' ') {
                            board[x2][y2] = 'X';
                            board[x1][y1] = ' ';
                        } else if (board[x2][y2] == 'O') {
                        if (y2 == y1 + 1 && board[x2 + 1][y2 + 1] == ' ') {
                                    board[x1][y1] = ' ';
                                    board[x2][y2] = ' ';
                                    board[x2 + 1][y2 + 1] = 'X';
                                } else if (y2 == y1 - 1 && board[x2 + 1][y2 - 1] == ' ') {
                                    board[x1][y1] = ' ';
                                    board[x2][y2] = ' ';
                                    board[x2 + 1][y2 - 1] = 'X';
                                } else {
                                    printf("Invalid input! Please enter a valid move.\n");
                                    invalid_move_count++;
                                }  
                        }
                    }else {
                         printf("Invalid input! Please enter a valid move.\n");
                        invalid_move_count++;
                }
               }  else if (board[x1][y1] == 'A') {
                if(((x2 == x1 + 1) && (y2 == y1 + 1)) || ((x2 == x1 + 1) && (y2 == y1 - 1)) || ((x2 == x1 - 1) && (y2 == y1 + 1)) || ((x2 == x1 - 1) && (y2 == y1 - 1)) && (x2 > 0 && x2 <= 8) && (y2 > 0 && y2 <= 8)) {

                                               if (board[x2][y2] == ' ') {

                                                   board[x2][y2] = 'A';

                                                   board[x1][y1] = ' ';

                                               } else if (board[x2][y2] == 'O' || board[x2][y2]=='B') {

                                                   if (y2 == y1 + 1 &&  board[x2 + 1][y2 + 1] == ' ') {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 + 1][y2 + 1] = 'A';

                                                   } else if (y2 == y1 - 1 && board[x2 + 1][y2 - 1] == ' ') {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 + 1][y2 - 1] = 'A';

                                                   }

                                                       else if ((x2 == x1 - 1 && y2 == y1 + 1) && (board[x2 - 1][y2 + 1] == ' ')) {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 - 1][y2 + 1] = 'A';

                                                   }

                                                       else if ((x2 == x1 - 1 && y2 == y1 - 1) && (board[x2 - 1][y2 - 1] == ' ')) {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 - 1][y2 - 1] = 'A';

                                                   }
                                                       else{
                                                        printf("Invalid input! Please enter a valid move.\n");
                                                         invalid_move_count++;
   }

                                                      }
                                                    else {
                                                    printf("Invalid input! Please enter a valid move.\n");
                                                    invalid_move_count++;
                                                     }
                                         }
                    
                 
   if (invalid_move_count == 2) {
                    printf("Player 2's turn!\n");
                    break;
                }
                }

               
            }
                    }
                   
                   

else if (current_player == 2) {
	
	clock_t start = clock();
	
    printf("Enter the positions of the piece you want to move for player(O) 2: ");
    scanf("%d %d", &x1, &y1);

    clock_t end = clock();
                    double time_taken = ((double)end - start)/CLOCKS_PER_SEC;
                    if(time_taken<60)
						printf("Time Taken : %.2f Seconds\n",time_taken);
                         
                    else if(time_taken>60.0)
                    {
                    	t_time = time_taken/60;
                    	printf("Time Limit Exceeded! Time Taken : %.2f Minutes\n Move is Invalid\n",t_time);
                    	continue;
					}

    if (board[x1][y1] != 'O' && board[x1][y1] != 'B') {
        printf("Invalid input! Please enter a valid move.\n");
        invalid_move_count++;

        if (invalid_move_count >= 2) {
            printf("Player 1's turn!\n");
            break;
        }
    } else {
    	
    	clock_t start = clock();
    	
        printf("Enter the position you want to move for player(O) 2: ");
        scanf("%d %d", &x2, &y2);
        
        clock_t end = clock();
                    double time_taken = ((double)end - start)/CLOCKS_PER_SEC;
                    if(time_taken<60)
						printf("Time Taken : %.2f Seconds\n",time_taken);
                         
                    else if(time_taken>60.0)
                    {
                    	t_time = time_taken/60;
                    	printf("Time Limit Exceeded! Time Taken : %.2f Minutes\n Move is Invalid\n",t_time);
                    	continue;
					}

        if (board[x1][y1] == 'O') {
            // Normal move for 'O'
            if ((x2 == x1 - 1) && ((y2 == y1 + 1) || (y2 == y1 - 1)) && (x2 > 0 && x2 <= 8) && (y2 > 0 && y2 <= 8)) {
                if (board[x2][y2] == ' ') {
                    board[x2][y2] = 'O';
                    board[x1][y1] = ' ';
                } else if ((board[x2][y2] == 'X' ) && board[x2 - 1][y2 + 1] == ' ') {
                    // Capture move for 'O'
                    // (Modify this part according to your rules)
                    // ...
                     if (y2 == y1 + 1) {
                                    board[x1][y1] = ' ';
                                    board[x2][y2] = ' ';
                                    board[x2 - 1][y2 + 1] = 'O';
                                } else if (y2 == y1 - 1 && board[x2 - 1][y2 - 1] == ' ') {
                                    board[x1][y1] = ' ';
                                    board[x2][y2] = ' ';
                                    board[x2 - 1][y2 - 1] = 'O';
                                }
                else {
                    printf("Invalid input! Please enter a valid move.\n");
                    invalid_move_count++;
                }
            } else {
                printf("Invalid input! Please enter a valid move.\n");
                invalid_move_count++;
            }
        }} else if (board[x1][y1] == 'B') {    //King for 'O' Moves

                                                       if (((x2 == x1 + 1) && (y2 == y1 + 1)) || ((x2 == x1 + 1) && (y2 == y1 - 1)) || ((x2 == x1 - 1) && (y2 == y1 + 1)) || ((x2 == x1 - 1) && (y2 == y1 - 1)) && (x2 > 0 && x2 <= 8) && (y2 > 0 && y2 <= 8)) {

                                               if (board[x2][y2] == ' ') {

                                                   board[x2][y2] = 'B';

                                                   board[x1][y1] = ' ';

                                               } else if (board[x2][y2] == 'X' || board[x2][y2]=='A') {

                                                   if (y2 == y1 + 1 &&  board[x2 + 1][y2 + 1] == ' ') {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 + 1][y2 + 1] = 'B';

                                                   } else if (y2 == y1 - 1 && board[x2 + 1][y2 - 1] == ' ') {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 + 1][y2 - 1] = 'B';

                                                   }

                                                       else if ((x2 == x1 - 1 && y2 == y1 + 1) && (board[x2 - 1][y2 + 1] == ' ')) {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 - 1][y2 + 1] = 'B';

                                                   }

                                                       else if ((x2 == x1 - 1 && y2 == y1 - 1) && (board[x2 - 1][y2 - 1] == ' ')) {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 - 1][y2 - 1] = 'B';

                                                   } else {
                    printf("Invalid input! Please enter a valid move.\n");
                    invalid_move_count++;
                }
            } else {
                printf("Invalid input! Please enter a valid move.\n");
                invalid_move_count++;
            }
        }

        if (invalid_move_count >= 2) {
            printf("Player 1's turn!\n");
            break;
        }
    }
}


 
                   
                   
                        }
                    for(i=1;i<9;i++){

			            if(board[8][i]=='X')
			
			            board[8][i]='A';      //change 'X' to 'A' for King
			
			            if(board[1][i]=='O')
			
			            board[1][i]='B';      //change 'O' to 'B' for King

              		}
                    // board display after move
                    printBoard(board, rows, cols);
                    int win_x,win_o;
                    // winning condition
                    win_x = 0;
                    win_o = 0;
                    for (i = 0; i < 9; i++) {
                        for (j = 0; j < 9; j++) {
                            if (board[i][j] == 'X' || board[i][j] == 'A') {
                                win_x++;
                            } else if (board[i][j] == 'O' || board[i][j] == 'B') {
                                win_o++;
                            }
                        }
                    }

                    if (win_x == 0) {
                        printf("Player(O) 2 is the winner!\nCongratulations!");
                        return 0;
                    } else if (win_o == 0) {
                        printf("Player(X) 1 is the winner!\nCongratulations!");
                        return 0;
                    }

                    // Check for consecutive invalid moves
                    if (invalid_move_count > 0) {
                        consecutive_invalid_moves++;

                        if (consecutive_invalid_moves == 2) {
                            printf("The game is a draw due to four consecutive invalid moves!\n");
                            return 0;
                        }
                    } else {
                        consecutive_invalid_moves = 0;
                    }
                }while ((invalid_move_count > 0) && (invalid_move_count < 3));
            }

            freeBoard(board, rows);
            break;
        }
    }

   case 2: {
   	invalid_move_count=0;
    char **board = Board(rows, cols);
    initializeBoard(board, rows, cols);
    printBoard(board, rows, cols);

    while (x == 0) {
        if (moves % 2 == 0) {
            clock_t start = clock();
            printf("Enter the positions of the piece you want to move for player(X) 1: ");
            scanf("%d %d", &x1, &y1);
            
            clock_t end = clock();
            double time_taken = ((double)end - start)/CLOCKS_PER_SEC;
            
            if(time_taken < 60)
                printf("Time Taken : %.2f Seconds\n", time_taken);
            else if(time_taken > 60.0) {
                t_time = time_taken/60;
                printf("Time Limit Exceeded! Time Taken : %.2f Minutes\n Move is Invalid\n", t_time);
                continue;
            }

            if (board[x1][y1] != 'X' && board[x1][y1] != 'A') {
                printf("Invalid input! Please enter a valid move.\n");
                invalid_move_count++;

                if (invalid_move_count == 2) {
                    printf("Player 2's turn!\n");
                    break;
                }
            } else {
                clock_t start = clock();
                printf("Enter the position you want to move for player(X) 1: ");
                scanf("%d %d", &x2, &y2);
                
                clock_t end = clock();
                double time_taken = ((double)end - start)/CLOCKS_PER_SEC;
                
                if(time_taken < 60)
                    printf("Time Taken : %.2f Seconds\n", time_taken);
                else if(time_taken > 60.0) {
                    t_time = time_taken/60;
                    printf("Time Limit Exceeded! Time Taken : %.2f Minutes\n Move is Invalid\n", t_time);
                    continue;
                }

                if (board[x1][y1] == 'X') {
                    if ((x2 == x1 + 1) && ((y2 == y1 + 1) || (y2 == y1 - 1)) && (x2 > 0 && x2 <= 8) && (y2 > 0 && y2 <= 8)) {
                        if (board[x2][y2] == ' ') {
                            board[x2][y2] = 'X';
                            board[x1][y1] = ' ';
                        } else if (board[x2][y2] == 'O') {
                            if (y2 == y1 + 1 && board[x2 + 1][y2 + 1] == ' ') {
                                board[x1][y1] = ' ';
                                board[x2][y2] = ' ';
                                board[x2 + 1][y2 + 1] = 'X';
                            } else if (y2 == y1 - 1 && board[x2 + 1][y2 - 1] == ' ') {
                                board[x1][y1] = ' ';
                                board[x2][y2] = ' ';
                                board[x2 + 1][y2 - 1] = 'X';
                            } else {
                                printf("Invalid input! Please enter a valid move.\n");
                                invalid_move_count++;
                            }
                        }
                    } else {
                        printf("Invalid input! Please enter a valid move.\n");
                        invalid_move_count++;
                    }
                } else if (board[x1][y1] == 'A') {
                    // King move for 'X'
                    // Implement the kinging logic here
                    // (Modify this part according to your rules)
                    if (((x2 == x1 + 1) && (y2 == y1 + 1)) || ((x2 == x1 + 1) && (y2 == y1 - 1)) || ((x2 == x1 - 1) && (y2 == y1 + 1)) || ((x2 == x1 - 1) && (y2 == y1 - 1)) && (x2 > 0 && x2 <= 8) && (y2 > 0 && y2 <= 8)) {
                        if (board[x2][y2] == ' ') {
                            board[x2][y2] = 'A';
                            board[x1][y1] = ' ';
                        } else if (board[x2][y2] == 'O' || board[x2][y2] == 'B') {
                            if (y2 == y1 + 1 && board[x2 + 1][y2 + 1] == ' ') {
                                board[x1][y1] = ' ';
                                board[x2][y2] = ' ';
                                board[x2 + 1][y2 + 1] = 'A';
                            } else if (y2 == y1 - 1 && board[x2 + 1][y2 - 1] == ' ') {
                                board[x1][y1] = ' ';
                                board[x2][y2] = ' ';
                                board[x2 + 1][y2 - 1] = 'A';
                            } else if ((x2 == x1 - 1 && y2 == y1 + 1) && (board[x2 - 1][y2 + 1] == ' ')) {
                                board[x1][y1] = ' ';
                                board[x2][y2] = ' ';
                                board[x2 - 1][y2 + 1] = 'A';
                            } else if ((x2 == x1 - 1 && y2 == y1 - 1) && (board[x2 - 1][y2 - 1] == ' ')) {
                                board[x1][y1] = ' ';
                                board[x2][y2] = ' ';
                                board[x2 - 1][y2 - 1] = 'A';
                            } else {
                                printf("Invalid input! Please enter a valid move.\n");
                                moves--;
                                continue;
                            }
                        }
                    } else {
                        printf("Invalid input! Please enter a valid move.\n");
                        moves--;
                        continue;
                    }
                }
                
                if (invalid_move_count == 2) {
                    printf("Player 2's turn!\n");
                    break;
                }
            }
        }
    


                else {
                // Computer's move
                printf("Computer's move:\n");
                do {
                    x1 = rand() % 8 + 1;
                    y1 = rand() % 8 + 1;
                    x2 = rand() % 8 + 1;
                    y2 = rand() % 8 + 1;
                } while (!( (board[x1][y1] == 'O' || board[x1][y1] == 'B' ) && (board[x2][y2] == ' '|| board[x2][y2] == 'X' || board[x2][y2] == 'A') &&
                           ((x2 == x1 - 1) && (y2 == y1 + 1 || y2 == y1 - 1)) &&
                           (x2 > 0 && x2 <= 8) && (y2 > 0 && y2 <= 8)));

                if (board[x1][y1] == 'O') {
            // Normal move for 'O'
            if ((x2 == x1 - 1) && ((y2 == y1 + 1) || (y2 == y1 - 1)) && (x2 > 0 && x2 <= 8) && (y2 > 0 && y2 <= 8)) {
                if (board[x2][y2] == ' ') {
                    board[x2][y2] = 'O';
                    board[x1][y1] = ' ';
                } else if ((board[x2][y2] == 'X' || board[x2][y2] == 'A') && board[x2 - 1][y2 + 1] == ' ') {
                    // Capture move for 'O'
                    // (Modify this part according to your rules)
                    // ...
                     if (y2 == y1 + 1) {
                                    board[x1][y1] = ' ';
                                    board[x2][y2] = ' ';
                                    board[x2 - 1][y2 + 1] = 'O';
                                } else if (y2 == y1 - 1 && board[x2 - 1][y2 - 1] == ' ') {
                                    board[x1][y1] = ' ';
                                    board[x2][y2] = ' ';
                                    board[x2 - 1][y2 - 1] = 'O';
                                }
                else {
                    printf("Invalid input! Please enter a valid move.\n");
                    invalid_move_count++;
                }
            } else {
                printf("Invalid input! Please enter a valid move.\n");
                invalid_move_count++;
            }
        }}else if (board[x1][y1] == 'B') {    //King for 'O' Moves

                                                       if (((x2 == x1 + 1) && (y2 == y1 + 1)) || ((x2 == x1 + 1) && (y2 == y1 - 1)) || ((x2 == x1 - 1) && (y2 == y1 + 1)) || ((x2 == x1 - 1) && (y2 == y1 - 1)) && (x2 > 0 && x2 <= 8) && (y2 > 0 && y2 <= 8)) {

                                               if (board[x2][y2] == ' ') {

                                                   board[x2][y2] = 'B';

                                                   board[x1][y1] = ' ';

                                               } else if (board[x2][y2] == 'X' || board[x2][y2]=='A') {

                                                   if (y2 == y1 + 1 &&  board[x2 + 1][y2 + 1] == ' ') {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 + 1][y2 + 1] = 'B';

                                                   } else if (y2 == y1 - 1 && board[x2 + 1][y2 - 1] == ' ') {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 + 1][y2 - 1] = 'B';

                                                   }

                                                       else if ((x2 == x1 - 1 && y2 == y1 + 1) && (board[x2 - 1][y2 + 1] == ' ')) {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 - 1][y2 + 1] = 'B';

                                                   }

                                                       else if ((x2 == x1 - 1 && y2 == y1 - 1) && (board[x2 - 1][y2 - 1] == ' ')) {

                                                       board[x1][y1] = ' ';

                                                       board[x2][y2] = ' ';

                                                       board[x2 - 1][y2 - 1] = 'B';

                                                   } else {
                    printf("Invalid input! Please enter a valid move.\n");
                    invalid_move_count++;
                }
            } else {
                printf("Invalid input! Please enter a valid move.\n");
                invalid_move_count++;
            }
        }

        if (invalid_move_count >= 2) {
            printf("Player 1's turn!\n");
            break;
        }
    }

                printf("Computer moved from %d %d to %d %d\n", x1, y1, x2, y2);
            }
           

            printBoard(board, rows, cols);

            // Check for a winner
            x = checkWinner(board, rows, cols);

            moves++;
        }

        freeBoard(board, rows);
        break;
    }

    default:
        printf("Invalid choice. Exiting...\n");
    }

    return 0;
}

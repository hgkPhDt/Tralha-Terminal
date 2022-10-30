#include "fun/define.c"
#include "fun/functions.c"

int main(){
	bool run = true;
	short unsigned int line,column,box,jogada,score=0, l,c, sound = 1;
	unsigned char option,data,hash[3][3] ={ '~','~','~','~','~','~','~','~','~',};

char nickname[30] = "Anonymous";
start:
system("mpg123 -q --loop 99 sound/break-acid.mp3 &");

	//Start game
	while(run){

		//Print the menu
		theMenu(&option,hash);

		//Kill the game
		if(tolower(option) == 'e'){
			system("pkill mpg123");
			system("clear");
			break;
		}

		//I
		if(tolower(option) == 'w'){
			system("clear");
			printf("\n\t"BOLD GREEN REVERSE"  >>>> https://github.com/hgkPhDt/TT <<<<  "RESET);
			printf("\n\n This game's developed by Philip Torres.");
			printf("\n Press "BOLD"ENTER"RESET" to leave.");
			bufferClean();s
		}

		//Data the player
		if(tolower(option) == 'p'){
			system("clear");
			printf("\n\t "BOLD MAGENTA REVERSE" >>>> PLAYER <<<< "RESET);

			if(!strcmp(nickname, "Anonymous") == 0){
				printf("\n\n\tHello, %s. Welcome back!", nickname);
			}else{
				printf("\n\n Write your nickname here.\n");
				printf("\n Nick: ");
				scanf("%29[^\n]", &nickname[0]);
				bufferClean();
				printf("\n Welcome, %s. Enjoy yourself!", nickname);
				printf("\n Press "BOLD"ENTER"RESET".");
			}
			
			getchar();
		}

		//History and your score
		if(tolower(option) == 'h'){
			system("clear");
			printf("\n\t"BOLD CYAN REVERSE"  >>>> YOUR HISTORY HERE! <<<<  "RESET);
			printf("\n\n\n\t Nickname: %s", nickname);
			printf("\n\t Score: %hd", score);
			putchar('\n');
			putchar('\n');
			
			printf("\n\n\n\n Press "BOLD"ENTER"RESET" to leave.");
			bufferClean();
		}

		//Tic tac toe
		if(tolower(option) == 's'){
			xWin:
			system("pkill mpg123");

			//Print the table
			hashTable(line,column,hash);							

			for(jogada = 0; jogada < 9999; jogada++){
				//Player X's starts
				printf(" To leave, press 0.\n");
				restartX:
				printf(" The "RED BOLD"X"RESET" is playing: ");	
				scanf("%hd", &box);								
				bufferClean();										
				system("mpg123 -q -k 10 sound/click.mp3 &");
				
				///Checking if have the case occupied
				if(	box == 1 && hash[2][0] == 'O'||
					  box == 2 && hash[2][1] == 'O'||
					  box == 3 && hash[2][2] == 'O'||
					  box == 4 && hash[1][0] == 'O'||
					  box == 5 && hash[1][1] == 'O'||
					  box == 6 && hash[1][2] == 'O'||
					  box == 7 && hash[0][0] == 'O'||
					  box == 8 && hash[0][1] == 'O'||
					  box == 9 && hash[0][2] == 'O'||
					  //...........................//
					  box == 1 && hash[2][0] == 'X'||
					  box == 2 && hash[2][1] == 'X'||
					  box == 3 && hash[2][2] == 'X'||
					  box == 4 && hash[1][0] == 'X'||
					  box == 5 && hash[1][1] == 'X'||
					  box == 6 && hash[1][2] == 'X'||
					  box == 7 && hash[0][0] == 'X'||
					  box == 8 && hash[0][1] == 'X'||
					  box == 9 && hash[0][2] == 'X'){
					  printf(RED BOLD" Oops! try again!\n"RESET);
					  goto restartX;
				  }

					//If no having case occupied fill with the number
					switch(box){
						case 1:
							hash[2][0] = 'X';
							break;
						case 2:
							hash[2][1] = 'X';
							break;
						case 3:
							hash[2][2] = 'X';
							break;
						case 4:
							hash[1][0] = 'X';
							break;
						case 5:
							hash[1][1] = 'X';
							break;
						case 6:
							hash[1][2] = 'X';
							break;
						case 7:
							hash[0][0] = 'X';
							break;
						case 8:
							hash[0][1] = 'X';
							break;
						case 9:
							hash[0][2] = 'X';
							break;
						case 0:
							goto start;
							break;
					}							
					
				
        //Checking if the player X won
				//First line
				if(	hash[0][0] == 'X'&&
					hash[0][1] == 'X'&&
					hash[0][2] == 'X'||
					//Second line
					hash[1][0] == 'X'&&
					hash[1][1] == 'X'&&
					hash[1][2] == 'X'||
					//Third line
					hash[2][0] == 'X'&&
					hash[2][1] == 'X'&&
					hash[2][2] == 'X'||
					//First column
					hash[0][0] == 'X'&&
					hash[1][0] == 'X'&&
					hash[2][0] == 'X'||
					//Second column
					hash[0][1] == 'X'&&
					hash[1][1] == 'X'&&
					hash[2][1] == 'X'||
					//Third column
					hash[0][2] == 'X'&&
					hash[1][2] == 'X'&&
					hash[2][2] == 'X'||
					//First diagonal
					hash[0][0] == 'X'&&
					hash[1][1] == 'X'&&
					hash[2][2] == 'X'||
					//Second diagonal
					hash[0][2] == 'X'&&
					hash[1][1] == 'X'&&
					hash[2][0] == 'X'){
					system("clear");
					hashTable(line,column,hash);
					system("mpg123 -q -k 10 sound/you-win.mp3 &");
					printf("\n\tPlayer "RED BOLD"X"RESET" won!");
					printf("\n\tContinue [Y/n]? \n\n\n   "BOLD YELLOW">> "RESET);
					option = getchar();
					bufferClean();

					score += 5;

					//Return to menu
					if(tolower(option) == 'n'){
						system("pkill mpg123");
						hashClean(l,c,hash);
						goto start;
					}

					//Clean the table
					hashClean(l,c,hash);
					goto xWin;
            
				//Checking if it's a draw.
				}else if(	hash[0][0] != '~'&&
								hash[0][1] != '~'&&
								hash[0][2] != '~'&&
								hash[1][0] != '~'&&
								hash[1][1] != '~'&&
								hash[1][2] != '~'&&
								hash[2][0] != '~'&&
								hash[2][1] != '~'&&
								hash[2][2] != '~'){
						system("clear");
						hashTable(line,column,hash);
						system("mpg123 -q -k 10 sound/alshred-losersound.mp3 &");
						printf("\n\tIT'S A "YELLOW"DRAW"RESET".\n");
						printf("\tPress "BOLD"ENTER"RESET" to return.");
						getchar();

						//Clean the table
						hashClean(l,c,hash);
						system("clean");
					}
                                
				//Print the table
				hashTable(line,column,hash);						
				
				//Player's O starts
				restartO:
				box = rand() % 10;

				//Checking if have the case occupied
				if(	box == 1 && hash[2][0] == 'X'||
					box == 2 && hash[2][1] == 'X'||
					box == 3 && hash[2][2] == 'X'||
					box == 4 && hash[1][0] == 'X'||
					box == 5 && hash[1][1] == 'X'||
					box == 6 && hash[1][2] == 'X'||
					box == 7 && hash[0][0] == 'X'||
					box == 8 && hash[0][1] == 'X'||
					box == 9 && hash[0][2] == 'X'||
					//...........................//
					box == 1 && hash[2][0] == 'O'||
					box == 2 && hash[2][1] == 'O'||
					box == 3 && hash[2][2] == 'O'||
					box == 4 && hash[1][0] == 'O'||
					box == 5 && hash[1][1] == 'O'||
					box == 6 && hash[1][2] == 'O'||
					box == 7 && hash[0][0] == 'O'||
					box == 8 && hash[0][1] == 'O'||
					box == 9 && hash[0][2] == 'O'){
					goto restartO;
				}

					//If no having case occupied fill with the number
					switch(box){
						case 1:
							hash[2][0] = 'O';
							break;
						case 2:
							hash[2][1] = 'O';
							break;
						case 3:
							hash[2][2] = 'O';
							break;
						case 4:
							hash[1][0] = 'O';
							break;
						case 5:
							hash[1][1] = 'O';
							break;
						case 6:
							hash[1][2] = 'O';
							break;
						case 7:
							hash[0][0] = 'O';
							break;
						case 8:
							hash[0][1] = 'O';
							break;
						case 9:
							hash[0][2] = 'O';
							break;
						default:
							goto restartO;
							break;
					}								

				//Checking if player O won

				s// //First line
				if(	hash[0][0] == 'O'&&
						hash[0][1] == 'O'&&
						hash[0][2] == 'O'||
						//Second line
						hash[1][0] == 'O'&&
						hash[1][1] == 'O'&&
						hash[1][2] == 'O'||
						//Third line
						hash[2][0] == 'O'&&
						hash[2][1] == 'O'&&
						hash[2][2] == 'O'||
						//First column
						hash[0][0] == 'O'&&
						hash[1][0] == 'O'&&
						hash[2][0] == 'O'||
						//Second column
						hash[0][1] == 'O'&&
						hash[1][1] == 'O'&&
						hash[2][1] == 'O'||
						//Third column
						hash[0][2] == 'O'&&
						hash[1][2] == 'O'&&
						hash[2][2] == 'O'||
						//First diagonal
						hash[0][0] == 'O'&&
						hash[1][1] == 'O'&&
						hash[2][2] == 'O'||
						//Second diagonal
						hash[0][2] == 'O'&&
						hash[1][1] == 'O'&&
						hash[2][0] == 'O'){
						system("clear");
						hashTable(line,column,hash);
						system("mpg123 -q -k 10 sound/alshred-losersound.mp3 &");
						printf("\n\tPlayer "GREEN BOLD"O"RESET" won!");
						printf("\n\tContinue [Y/n]? \n\n\n   "BOLD YELLOW">> "RESET);
						option = getchar();
						bufferClean();
						system("clear");
						score -= 3;

						//Return to menu.
						if(tolower(option) == 'n'){
							system("pkill mpg123");
							hashClean(l,c,hash);
							goto start;
						}

						//Clean the table
						hashClean(l,c,hash);
						system("pkill mpg123");
						goto restartO;
						
					//Checking if it's a draw
					}else if(	hash[0][0] != '~'&&
								hash[0][1] != '~'&&
								hash[0][2] != '~'&&
								hash[1][0] != '~'&&
								hash[1][1] != '~'&&
								hash[1][2] != '~'&&
								hash[2][0] != '~'&&
								hash[2][1] != '~'&&
								hash[2][2] != '~'){
						system("clear");
						hashTable(line,column,hash);
						system("mpg123 -q -k 10 sound/alshred-losersound.mp3 &");
						printf("\n\tIT'S A "YELLOW"DRAW"RESET".\n");
						printf("\tPress "BOLD"ENTER"RESET" to return.");
						getchar();

						//Clean the table
						hashClean(l,c,hash);
						system("clean");
					}

				//Print the table
				hashTable(line,column,hash);
				
			}
		}
	}
}

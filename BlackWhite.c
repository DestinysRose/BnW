/* File: BlackWhite.c
* Date started: 21/04/2014
* Last Modified: 15/05/2014*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define ROW 8
#define COLUMN 8


/*Creates the initial board*/
void initialize(int board[ROW][COLUMN])
{
	int x, y;	
	for (x = 0; x < ROW; x++)
	{
		for (y =0; y < COLUMN; y++)
		{
			board[x][y] = '@';
		}
	}
	board[3][3] = '@';
	board[3][4] = 'O';
	board[4][3] = 'O';
	board[4][4] = '@';
}

/*Displays the current board*/
void display(int board[ROW][COLUMN], int bcount, int wcount, char fplyr[10], char splyr[10], char cplyr[10])
{
	int x, y;
	printf("\nCurrent score:");
	printf("\n%s (@): %2i          %s (O): %2i\n", fplyr, bcount, splyr, wcount);

	for (x = 0; x < ROW; x++)
	{
		for (y =0; y <COLUMN; y++)
		{
			printf("| %c ", board[x][y]);
		}
		printf("|\n");
	}
	 
}

/*Shows where the player is currently selecting*/
void move(int board[ROW][COLUMN], int bcount, int wcount, char fplyr[10], char splyr[10], char cplyr[10], char token)
{
	int x, y;
	printf("\nCurrent score:");
	printf("\n%s (@): %2i          %s (O): %2i\n", fplyr, bcount, splyr, wcount);
			
	for (x = 0; x < ROW; x++)
	{
		for (y =0; y <COLUMN; y++)
		{
			printf("| %c ", board[x][y]);
		}
		printf("|\n");
	}	
	
	printf("\nCurrent player: %s (%c)\n", cplyr, token);
	printf("Press a directional key to navigate around the board.\n");
	printf("Press Enter to place a token.\n");
	printf("Press ESC to exit.\n");
}

/*Check for token type to restore*/
int restoretoken(int board[ROW][COLUMN], int a, int b)
{
	int restore;
	if(board[a][b] == '@')
		{
			restore = 1;
		}
		else if(board[a][b] == 'O')
		{
			restore = -1;
		}
		else
		{
			restore = 0;
		}
	return restore;
}

/*Flips tokens: UP */
void ftup(int board[ROW][COLUMN], char token, int a, int b, int *flipup)
{
	int x, flip=0, up=a-1, f, tcount=0, counter=0;
	
		
	for (x=up; x>0; x--)
	{
		if(board[x][b] == token)
		{
			tcount = x;
			
			for(x=up; x>tcount; x--)
			{
				if(board[x][b] != token && board[x][b] != ' ')
				{	
					flip = flip + 1;
				}
				else
				{
						break;
				}
			}
			
			break;
		}
		else if(board[x][b] == ' ')
		{
			break;
		}
	}
	
	if (flip>0)
	{
		f=up-flip;
		for (x=up; x>f; x--)
		{
			board[x][b] = token;
			counter++;
		}
	}
	
	*flipup = counter;
}

/*Flips tokens: DOWN*/
void ftdown(int board[ROW][COLUMN], char token, int a, int b, int *flipdown)
{
	int x, flip=0,down=a+1, f, tcount=0, counter=0;
		
	for (x=down; x<8; x++)
	{
		if(board[x][b] == token)
		{
			tcount = x;
			
			for(x=down; x<tcount; x++)
			{
				if(board[x][b] != token && board[x][b] != ' ')
				{	
					flip = flip + 1;
				}
				else
				{
						break;
				}
			}
			break;	
		}
		else if(board[x][b] == ' ')
		{
			break;
		}
	}
	
	if (flip>0)
	{
		f=down+flip;
		for (x=down; x<f; x++)
		{
			board[x][b] = token;
			counter++;
		}
	}
	*flipdown = counter;
}

/*Flips tokens: LEFT*/
void ftleft(int board[ROW][COLUMN], char token, int a, int b, int *flipleft)
{
	int y, flip=0, left=b-1, f, tcount=0, counter=0;
	
	for (y=left; y>=0; y--)
	{
		if(board[a][y] == token)
		{
			tcount = y;
			
			for(y=left; y>tcount; y--)
			{
				if(board[a][y] != token && board[a][y] != ' ')
				{	
					flip = flip + 1;
				}
				else
				{
					break;
				}
			}
			break;
		}
		else if(board[a][y] == ' ')
		{
			break;
		}
	}
	
	if (flip>0)
	{
		f=left-flip;
		for (y=left; y>f; y--)
		{
			board[a][y] = token;
			counter++;
		}
	}
	*flipleft = counter;
}

/*Flips tokens: RIGHT*/
void ftright(int board[ROW][COLUMN], char token, int a, int b, int *flipright)
{
	int y, flip=0, right=b+1, f, tcount=0, counter=0;
	
	for (y=right; y<8; y++)
	{
		if(board[a][y] == token)
		{
			tcount = y;
			
			for(y=right; y<tcount; y++)
			{
				if(board[a][y] != token && board[a][y] != ' ')
				{	
					flip = flip + 1;
				}
				else
				{
					break;
				}
			}
			break;
		}
		else if(board[a][y] == ' ')
		{
			break;
		}
	}
	
	if (flip>0)
	{
		f=right+flip;
		for (y=right; y<f; y++)
		{
			board[a][y] = token;
			counter++;
		}
	}
	*flipright = counter;
}
/*Flips tokens (Diagonal): UP + LEFT*/
void ftul(int board[ROW][COLUMN], char token, int a, int b, int *flipul)
{
	int x, y, flip=0, up=a-1, f, tcount=0, counter=0;
	
	 x=a;
	 y=b;
	 
	 do{	
	 	
		do{
			x--;
			y--;
			if(board[x][y] == token)
		 	{
				tcount = x;
				break;
			}
			else if(board[x][y] == ' ')
			{
				break;
			}
		}while(board[x][y] != token && x>0 && y>0);
		
		x=a;
		y=b;
		
		do
		{
			if(tcount>0)
			{
				x--;
				y--;
				if(board[x][y] != token && board[x][y] != ' ')
				{
					flip = flip +1;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}while(x != tcount && x>0 && y>0);
		 
		x=a;
		y=b;
		 
		if (flip>=0)
		{
			f=up-flip;
			
			for (x=up; x>f; x--)
			{
				y--;
				board[x][y] = token;
				counter++;
			}
			break;
		}
		else
		{
			break;
		}
	 }while(board[x][y] != ' ' && x>0 && y>0);

	 *flipul = counter;
}

/*Flips tokens (Diagonal): UP + RIGHT*/
void ftur(int board[ROW][COLUMN], char token, int a, int b, int *flipur)
{
	int x=a, y=b, flip=0, up=a-1, f, tcount=0, counter=0;
		 
	 do{	
	 	 do{
			x--;
			y++;
			if(board[x][y] == token)
		 	{
				tcount = x;
				break;
			}
			else if(board[x][y] == ' ')
			{
				break;
			}
		}while(board[x][y] != token && x>0 && y<8);
			
		x=a;
		y=b;
		
		do
		{
			if(tcount>0)
			{
				x--;
				y++;
				if(board[x][y] != token && board[x][y] != ' ')
				{
					flip = flip +1;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}while(x != tcount && x>0 && y<8);
		 
		x=a;
		y=b;
			 
		if (flip>=0)
		{
			f=up-flip;
			
			for (x=up; x>f; x--)
			{
				y++;
				board[x][y] = token;
				counter++;
			}
			break;
		}
		else
		{
			break;
		}
	
	 }while(board[x][y] != ' ' && x>0 && y<8);
	 
	 *flipur = counter;
}

/*Flips tokens (Diagonal): DOWN + LEFT*/
void ftdl(int board[ROW][COLUMN], char token, int a, int b, int *flipdl)
{
	int x=a, y=b, down=a+1, flip=0, f, tcount=0, counter=0;
 
	 do{	
	 	 do{
			x++;
			y--;
			if(board[x][y] == token)
		 	{
				tcount = x;
				break;
			}
			else if(board[x][y] == ' ')
			{
				break;
			}
		}while(board[x][y] != token && x<8 && y>0);
			
		x=a;
		y=b;
		
		do
		{
			if(tcount>0)
			{
				x++;
				y--;
				if(board[x][y] != token && board[x][y] != ' ')
				{
					flip = flip +1;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}while(x != tcount && x<8 && y>0);
			 
		x=a;
		y=b;
		 
		if (flip>=0)
		{
			f=down+flip;
			
			for (x=down; x<f; x++)
			{
				y--;
				board[x][y] = token;
				counter++;
			}
			break;
		}
		else
		{
			break;
		}
	 }while(board[x][y] != ' ' && x<8 && y>0);

	*flipdl = counter;
}

/*Flips tokens (Diagonal): DOWN + RIGHT*/
void ftdr(int board[ROW][COLUMN], char token, int a, int b, int *flipdr)
{
	int x=a, y=b, flip=0, down=a+1, f, tcount=0, counter=0;
	 
	 do{	
	 
		do{
			x++;
			y++;
			if(board[x][y] == token)
		 	{
				tcount = x;
				break;
			}
			else if(board[x][y] == ' ')
			{
				break;
			}
		}while(board[x][y] != token && x<8 && y<8);
			
		x=a;
		y=b;
		
		do
		{
			if(tcount>0)
			{
				x++;
				y++;
				if(board[x][y] != token && board[x][y] != ' ')
				{
					flip = flip +1;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}while(x != tcount && x<8 && y<8);
			 
		x=a;
		y=b;
		 
		if (flip>=0)
		{
			f=down+flip;
				
			for (x=down; x<f; x++)
			{
				y++;
				board[x][y] = token;
				counter++;
			}
			break;
		}
		else
		{
			break;
		}
	}while(board[x][y] != ' ' && x<8 && y<8);


	*flipdr = counter;
}

/*Calculates the changes in black and white tokens*/
void calctoken(int board[ROW][COLUMN], int *bcount, int *wcount, int *total)
{
	int b=0, w=0, x, y;
	
	
	for (x = 0; x < ROW; x++)
	{
		for (y =0; y <COLUMN; y++)
		{
			if(board[x][y] == '@')
			{
				b += 1;
			}
			else if(board[x][y] == 'O')
			{
				w += 1;
			}	 
		}
	}

	*bcount = b;
	*wcount = w;
	*total = *bcount + *wcount;
}


/*Allows player to navigate through the board using the arrow keys*/

void navigation(int board[ROW][COLUMN], int ch1, int ch2, char token,int bcount, int wcount, int total, char fplyr[10], char splyr[10], char cplyr[10])
{
	int a=7, b=7, tr, flipup, flipdown, flipleft, flipright, flipul, flipur, flipdl, flipdr, yn;
	ch1 = 0;
	ch2 = 0;
	
	tr=restoretoken(board, a, b);
	board[a][b]= 'X';
	display(board, bcount, wcount, fplyr, splyr, cplyr);
	printf("\nCurrent player: %s (%c)\n", cplyr, token);
	printf("Press a directional key to navigate around the board.\n");
	printf("Press Enter to place a token.\n");
	printf("Press ESC to exit.\n");

	if(tr > 0)
		{
			board[a][b]='@';
		}
	else if(tr < 0)
		{
			board[a][b]='O';
		}

	else
		{
			board[a][b]=' ';
		}

again:
	do{
		ch1 = getch(); 
		ch2 = 0;
		
		if (ch1 == 0xE0)
		{ 
			ch2 = getch();
	
			if (ch2 == 72)/*Up Key*/
			{	
				a--;
				
				if(a<0)
				{
					a++;
					printf("End of board.\n");
				}
				else
				{
					tr=restoretoken(board, a, b);
					board[a][b] = 'X';
					move(board, bcount, wcount, fplyr, splyr, cplyr, token);
				}

			}
			else if (ch2 == 80)/*Down Key*/
			{
				a++;
				
				if(a>7)
				{
					a--;
					printf("End of board.\n");
				}
				else
				{
					tr=restoretoken(board, a, b);
					board[a][b]='X';
					move(board, bcount, wcount, fplyr, splyr, cplyr, token);
				}
			}
			else if (ch2 == 75)/*Left Key*/
			{ 
				b--;
				
				if(b<0)
				{
					b++;
					printf("End of board.\n");
				}
				else
				{
					tr=restoretoken(board, a, b);
					board[a][b]='X';
					move(board, bcount, wcount, fplyr, splyr, cplyr, token);
				}
			}
			else if (ch2 == 77)/*Right Key*/
			{
				b++;
				
				if(b>7)
				{
					b--;
					printf("End of board.\n");
				}
				else
				{
					tr=restoretoken(board, a, b);
					board[a][b]='X';
					move(board, bcount, wcount, fplyr, splyr, cplyr, token);
				}
			}
			else
			{
				printf("Invalid Key\n");
			}
		
			if(tr > 0)
				{
					board[a][b]='@';
				}
			else if(tr < 0)
				{
					board[a][b]='O';
				}

			else
				{
					board[a][b]=' ';
				}
		} 
		else if(ch1 == 27)/*ESC key*/
		{
			printf("Ok, bye.");
			exit(0);
		}
		else if(ch1 == 13) /*Enter Key*/
		{	 	 
			if(board[a][b] == ' ')
			{
				ftup(board, token, a, b, &flipup);
				ftdown(board, token, a, b, &flipdown);
				ftleft(board, token, a, b, &flipleft);
				ftright(board, token, a, b, &flipright);
				ftul(board, token, a, b, &flipul);
				ftur(board, token, a, b, &flipur);
				ftdl(board, token, a, b, &flipdl);
				ftdr(board, token, a, b, &flipdr);
				
				if(flipup>0 || flipdown>0 || flipleft>0 || flipright>0 || flipul>0 || flipur >0 || flipdl>0 || flipdr>0)
				{
					board[a][b] = token;
				}
				else
				{
					printf("\nUnable to flip anything.\n");
					
					
					printf("Do you wish to skip your turn?(Y/N)\n");
					yn = getch();
					YN:
					if(yn=='Y' || yn=='y')
					{
						break;
					}
					else if(yn=='N' || yn=='n')
					{
						printf("Alright, please place your token in another location.\n");
						goto again;
					}
					else
					{
						printf("Invalid key, please press 'Y' or 'N'.\n");
						yn = getch();
						goto YN;
					}
				}	 
			}
			else
			{
				printf("There is already a token there.\n");
				goto again; 
			}
			
		}
		else 
		{
			printf("Invalid Key.\n");
		}
	}while (ch1 != 13);
}



/*Main function*/
main()
{
	char fplyr[10], splyr[10], cplyr[10];
	char token = ' ', yn = ' ';
	int board[ROW][COLUMN];
	int x, y, a, b, bcount, wcount, total=0;
	int ch1,ch2;
	
	printf("********************** Welcome to Black & White Chess!!! **********************\n");
	
	Tut:
	
		printf("Would you like to know how to play?(Y/N)\n\n");
		yn = getch();
		
	if(yn=='Y' || yn=='y')
	{
		printf("First player is always black.\n");
		printf("Navigate around the board with directional keys, 'X' is your position.\n");
		printf("Place down your tokens with the enter key.\n");
		printf("Opponent tokens between your tokens will be flipped into your tokens.\n");
		printf("Tokens can be flipped horizontally, vertically or diagonally.\n");
		printf("Your turn may be skipped if you cannot flip at least one of your opponent's token.\n");
		printf("The player with the most tokens at the end of the game wins.\n\n");
	}
	else if(yn=='N' || yn=='n')
	{
	}
	else
	{
		printf("Invalid key, please press 'Y' or 'N'.\n");
		goto Tut;
	}
	
	
	
	printf("Please enter first player name:\n");
	scanf("%s",&fplyr);
	
	fflush(stdout);
	
	printf("Please enter second player name:\n");
	scanf("%s", &splyr);
	
	fflush(stdout);
	
	printf("\nAlright %s and %s! Let's start the game!\n", fplyr, splyr);
	
	initialize(board);
	
	do{
		if(total<64)
		{
			/*First Player*/
			token = '@';
	
			for(a=0; a<10; a++)
			{
				cplyr[a] = fplyr[a];
			}
			
			calctoken(board, &bcount,&wcount, &total);
			
			navigation(board, ch1, ch2, token, bcount, wcount, total, fplyr, splyr, cplyr);
				
		}
		
		calctoken(board, &bcount,&wcount, &total);
		
		if(total<64)
		{
			/*Second Player*/
			token = 'O';
	
			for(a=0; a<10; a++)
			{
				cplyr[a] = splyr[a];
			}	
	
			calctoken(board, &bcount, &wcount, &total);
	
			navigation(board, ch1, ch2, token, bcount, wcount, total, fplyr, splyr, cplyr);
		}
		
		calctoken(board, &bcount,&wcount, &total);
		
	}while(total<64);
	
	/*Display Final Board*/
	display(board, bcount, wcount, fplyr, splyr, cplyr);
	
	if(bcount > wcount)
	{
		printf("\nThe game has ended!\n\nCongratulations! The winner is %s, (@) with %i tokens!", fplyr, bcount);
	}
	else
	{
		printf("\nThe game has ended!\n\nCongratulations! The winner is %s, (O) with %i tokens!", splyr, wcount);
	}
	
	return 0;
}


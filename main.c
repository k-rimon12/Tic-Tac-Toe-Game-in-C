#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
Author: Komine Rimon
Student @HAW_Hamburg
*/
//Declare prototypes before main for it to be seen by main()
void printboard(char* arr);
int checkwin(char* arr);

int main() {
	printf("Tic Tac Toe Game: \nPlayer 1: X, Player 2: O\n\n");
	char board[] = { '0', '1', '2', '3', '4' , '5' , '6', '7', '8', '9' };
	int player = 1;
	int input;
	char mark;
	int moves = 0;
	int status = -1; // -1 = running, 0 = draw, 1 = win
	printboard(board);
	while (status == -1) {
		
		player = (player % 2 == 0) ? 2 : 1;
		mark = (player ==1) ? 'X' : 'O';
		printf("Enter the field number for player %d: ", player);
		int inp = scanf("%d", &input);

		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		if(inp != 1) {
			printf("Invlaid input, please enter a number not char.\n");
			continue;
		}

		if (input < 1 || input > 9) {
			printf("%d is an input out of field range from 1 to 9. \n", input);
			continue;
		}
		if (board[input] == 'X' || board[input] == 'O') {
			printf("Field already occupied.\n");
			continue;
		}
		board[input] = mark;
		printboard(board);
		int result = checkwin(board);
		if (result == 1) {
			printf("Congratulations.The winner is player %d.\n\n", player);
			return 0;
		}
		else if (moves == 9) {
			printf("\nIt's a draw...");
			return 0;
		}
		moves++;
		player++;
		printf("\n");
	}
 }

void printboard(char* arr) {
	//dynamic board to store fields where X or O will be stored later
	printf("\n      |     |\n");
	printf("   %c  |  %c  | %c\n", arr[1], arr[2], arr[3]);
	printf("______|_____|_____\n");
	printf("      |     | \n");
	printf("   %c  |  %c  | %c\n", arr[4], arr[5], arr[6]);
	printf("______|_____|_____\n");
	printf("      |     | \n");
	printf("   %c  |  %c  | %c\n", arr[7], arr[8], arr[9]);
	printf("      |     |\n\n");
}

int checkwin(char* arr)
{
	if ((arr[1] == arr[2] && arr[2] == arr[3]) ||
		(arr[1] == arr[4] && arr[4] == arr[7]) ||
		(arr[1] == arr[5] && arr[5] == arr[9]) ||
		(arr[2] == arr[5] && arr[5] == arr[8]) ||
		(arr[3] == arr[6] && arr[6] == arr[9]) ||
		(arr[4] == arr[5] && arr[5] == arr[6]) ||
		(arr[7] == arr[8] && arr[8] == arr[9]) ||
		(arr[3] == arr[5] && arr[5] == arr[7]))
	{return 1;}
	 //nobody won yet then we return status = -1
	return -1;
}

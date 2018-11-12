#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER N
#define SIZE N
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void initiate_bingo(int *arr);
void print_bingo(int arr[N][N]);
void process_bingo(int arr[N][N]);
void change_bingo_table(int arr[N][N], int number);
void print_winner(int winner);
int get_number_byMe(int number);
int get_number_byCom(int number);
int count_bingo();
int count = 0;
int bingo_byMe(int arr[N][N]);
int bingo_byCom(int arr[N][N]);

 
void initiate_bingo(int *arr){
	int x, y;
	srand(time(NULL));
	for(x=0; x<SIZE; x++)
	{
		for(y=0; y<SIZE; y++)
		{
			arr[x][y]=rand()%MAX_NUMBER;
		}
	}
}

void print_bingo(int arr[N][N]){
	int x,y;
	
	for(x=0; x<SIZE; x++){
		for(y=0; y<SIZE; y++){
			printf("\n\n", arr[x][y]);
		}
	}
}
	
int get_number_by(int who){
	int number;
	 
	do{
		if(who == 1){
			printf("N의 제곱까지의 숫자를 입력하시오 : ");
			scanf("%d", &number); 
		}
		else{
			number = rand() % N + 1;
		}	
}while();

void change_bingo_table(int arr[N][N], int input_number){
	int x,y;
	
	for(x=0; x<SIZE; x++){
		for(y=0; y<SIZE; y++){
			if(arr[x][y] == input_number){
				arr[x][y] = -1;
			}
		}
	}
}

void print_winner(int winner){
	switch(winner){
		case 1 :
			printf("사용자가 이겼습니다\n");
			break;
		case 2 :
		    printf("컴퓨터가 이겼습니다\n");
		    break;
		case 3 :
		    printf("비겼습니다\n");
			break;		
	}
}

	


	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER N
#define SIZE N*N
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void initiate_bingo(int *arr);
void print_bingo(int arr[N][N]);
void process_bingo(int arr[N][N]);
void check_bingo(int arr[N][N], int number);
void print_winner(int winner);
int get_number_byMe(int number);
int get_number_byCom(int number);
int count_bingo(int [N][N], int num);
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
	
int get_number_byMe(int number){
	int number;
	int x;
	
    do{
			printf("N의 제곱까지의 숫자를 입력하시오 : ");
			scanf("%d", &number); 
			 if(checked[x] == number){
			  printf("이미 입력한 숫자입니다. 다시 입력하시오 : ");
			  scanf("%d", &number);
			}
	}while(number<N*N);
	
	printf("사용자가 %d를 선택하였습니다 : \n", number);
	
	return number;
}

int get_number_byCom(int number){
	int number;
	int x;
	int try_again;
	
	do{
	    number = rand() % N*N + 1;
		if(checked[x] == number){
			try_again = 0; //try_again=0이면 다시 시도 
			break;
		} 
	}while(try_again == 0);
	
	printf("컴퓨터가 %d를 선택하였습니다 : \n", number);
	
	return number;
}
	
		
void check_bingo(int arr[N][N], int input_number){
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

int count_bingo(int [N][N], int num){
	int bingo = 0;
	int x, y;
	int horizontal_line, vertical_line, diagonal_line_leftside, diagonal_line_rightside;
	
	for(x=0; x<num; x++){
		horizontal_line = 0;
		for(y=0; y<num; y++){
			if(arr[N][N] == )
			horizontal_line++;
			
			if(){
				if(arr[N][N] == )
				diagonal_line_leftside++;
			}
			
			if(){
				if(arr[N][N] == )
				diagonal_line_rightside++;
			}
		}
		if(horizontal_line == M){
			bingo++;
		}
	}  
	
	for(y=0; y<num; y++){
		vertical_line = 0;
		for(x=0; x<num; x++){
			if(arr[N][N] == )
			vertical_line++;
		}
		if(vertical_line == M){
			bingo++;
		}
	}
}

	

	return 0;
}

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
			printf("N�� ���������� ���ڸ� �Է��Ͻÿ� : ");
			scanf("%d", &number); 
			 if(checked[x] == number){
			  printf("�̹� �Է��� �����Դϴ�. �ٽ� �Է��Ͻÿ� : ");
			  scanf("%d", &number);
			}
	}while(number<N*N);
	
	printf("����ڰ� %d�� �����Ͽ����ϴ� : \n", number);
	
	return number;
}

int get_number_byCom(int number){
	int number;
	int x;
	int try_again;
	
	do{
	    number = rand() % N*N + 1;
		if(checked[x] == number){
			try_again = 0; //try_again=0�̸� �ٽ� �õ� 
			break;
		} 
	}while(try_again == 0);
	
	printf("��ǻ�Ͱ� %d�� �����Ͽ����ϴ� : \n", number);
	
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
			printf("����ڰ� �̰���ϴ�\n");
			break;
		case 2 :
		    printf("��ǻ�Ͱ� �̰���ϴ�\n");
		    break;
		case 3 :
		    printf("�����ϴ�\n");
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

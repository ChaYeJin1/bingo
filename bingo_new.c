#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define N2 25
#define M 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void initiate_bingo(int bingo[5][5]);
void erase_bingo(int bingo[5][5], int number); //선택받은 숫자를 지움 
void count_bingo(int bingo_byMe[5][5], int bingo_byCom[5][5]); //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환 
void print_winner(int winner); //빙고 게임 승자를 출력 
int get_number_byMe(int num); //내가 빙고 번호 입력 선택 
int get_number_byCom(int num); //컴퓨터가 임의로 빙고 번호 선택 
int check_bingo(int bingo[5][5]); //가로, 세로, 오른쪽대각선, 왼쪽대각선 체크 
int checked[25];
int count=0;
int bingo_byMe [5][5]; // 나의 빙고 테이블 
int bingo_byCom [5][5]; //컴퓨터의 빙고 테이블 


int main(void){
    int bingo[5][5];
	
	printf("빙고 게임 규칙\n");
	printf("1. 1~25까지의 숫자를 입력하세요\n");
	printf("2. 빙고가 5개가 되면 승리\n");
	printf("준비되셨나요?\n");
	  
	return 0; 
}

void initiate_bingo(int bingo[5][5]){
	int x=0, y=0;
	int temp[50];
	int tem;
	long seed;
	
	seed=time(NULL);
	srand(seed);
	
	for(x=0; x<5; x++){
		for(y=0; y<5; y++){
			bingo[x][y]=0;
		}
		
    for(x=0; x<5; x++){
    	temp[x]=0;
	}
	
	for(x=0; x<5; x++){
		for(y=0; y<5; y++){
			while(1){
				tem=rand()%25+1;
				if(temp[tem]==0){
					bingo[x][y]=tem;
					temp[tem]=1;
					break;
				}
			}
		}	
    }

    	for(x=0; x<5; x++){
		  for(y=0; y<5; y++){
		    printf("%d", bingo[x][y]);
		    }
		printf("\n");
        }
    }
}

int get_number_byMe(int num){
	int number;
	int x, error;
    do{
            error = 0;  	
			printf("1~25까지의 숫자를입력하시오 : \n");
			scanf("%d", &number); 
			 if(number<1 || number>25){
			 error = 1;
			}
			if(error == 0){
	    	for(x=0; x<count; x++){
	    		if(checked[x] == number){
	    		printf("이미 입력한 숫자입니다\n");	
			    error = 1;
			    break;
	        	}    
			}
	}
	
	checked[count++] = number;
	printf("사용자가 %d를 선택하였습니다 : \n", number);
	
    }while(error == 1);
    
    return number;
}

int get_number_byCom(int num){
	int number;
	int x, error;
	
	do{
	    number = rand() % 25 + 1;
	    if(error == 0){
	    	for(x=0; x<count; x++){
	    		if(checked[x] == number){
	    		printf("이미 입력한 숫자입니다\n");
			    error = 1;
			    break;
	        	}    
			}
		}
		
	}while(error == 1);
	
	checked[count++] = number;
	printf("컴퓨터가 %d를 선택하였습니다 : \n", number);
	
	return number;
}
	

void erase_bingo(int arr[N][N], int number){
	int x,y;
	
	for(x=0; x<N; x++){
		for(y=0; y<N; y++){
			if(arr[x][y] == number){
				arr[x][y] = -1;
			}
		}
	}
}

int check_bingo(int arr[5][5]){
	int i, j;
	int rows = 0;
	int column = 0;
	int crossleft = 0;
	int crossright = 0;
	int check = 0;
	
	for(i=0; i<N; i++){
		rows=0;
		column=0;
		
		for(j=0; j<N; j++){
			if(bingo_byMe[i][j]==0){
				rows++;
			}
			if(bingo_byMe[j][i]==0){
				column++;
			}
		}
		
		if(rows==M){
			check++;
		}
		if(column==M){
			check++;
		}
		
		if(bingo_byMe[i][i]==0){
			crossleft++;
		}
		if(bingo_byCom[N-1-i][i]==0){
			crossright++;
		}
		
		if(crossleft==M){
			check++;
		}
		if(crossright==M){
			check++;
		}
	} 
	return check;
}

void count_bingo(int bingo_byMe[5][5], int bingo_byCom[5][5]){
	int i,j;
	int count = 1;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			bingo_byMe[i][j]=count;
			bingo_byCom[i][j]=count;
			count++;
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
		default :
		    printf("에러입니다\n");
			break;			
	}
}


#include <stdio.h>
#include <stdlib.h>

#define N 5
#define N2 25
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void initiate_bingo(); //빙고 테이블을 초기에 만들어줌 
void set_rand(int *arr);
void swap(int *i, int *j);
void print_bingo(int arr[5][5]); //빙고 테이블 현재 상황을 화면에 출력 
void erase_bingo(int arr[5][5], int number);
void print_winner(int winner);
void count_bingo(int bingo_byMe[5][5], int bingo_byCom[5][5]); //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환 
int get_number_byMe(int n); //내가 빙고 번호 입력 선택 
int get_number_byCom(int n); //컴퓨터가 임의로 빙고 번호 선택 
int check_bingo(int arr[5][5]);
int count = 0;
int checked[25];
int bingo_byMe [5][5];
int bingo_byCom [5][5]; 

int main(void){
	int number, winner_Me, winner_Com;
	initiate_bingo();
	
    do{
    	printf("내 빙고판\n");
    	print_bingo(bingo_byMe);
    	number = get_number_byMe(number);
    	erase_bingo(bingo_byMe, number);
    	erase_bingo(bingo_byCom, number);
    	number = get_number_byCom(number);
    	erase_bingo(bingo_byCom, number);
    	erase_bingo(bingo_byMe, number);
    	
    	winner_Me = check_bingo(bingo_byMe);
    	winner_Com = check_bingo(bingo_byCom);
    	
	}while((winner_Me == 0) && (winner_Com == 0)); //0은 아직 빙고 완성이 안 된 것을 의미
	
    printf("내 빙고판\n");
	print_bingo(bingo_byMe);
	printf("컴퓨터 빙고판\n"); 
	print_bingo(bingo_byCom);   
    
	return 0;   
}

void initiate_bingo(){
	srand((unsigned)time(NULL));
	set_rand((int*)bingo_byMe);
	set_rand((int*)bingo_byCom);
}

void set_rand(int *arr){
	int n;
	
	do{
		arr[n] = n + 1;
	}while(n<N2);
	
	do{
		swap(&arr[n], &arr[rand()%25]);
	}while(n<N2);
		
}

void swap(int *i, int *j){
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

void print_bingo(int arr[5][5]){
	int x,y;
	
	for(x=0; x<N; x++){
		for(y=0; y<N; y++){
			printf("%d",arr[x][y]);
		}
	    printf("\n\n");
	}
}
	
int get_number_byMe(int n){
	int number;
	int x, error;
    do{
            error = 0;  	
			printf("1~25까지의 숫자를입력하시오 : ");
			scanf("%d", &number); 
			 if(number<1 || number>25){
			 error = 1;
			}
			if(error == 0){
	    	for(x=0; x<count; x++){
	    		if(checked[x] == number){
	    		printf("이미 입력한 숫자입니다");	
			    error = 1;
			    break;
	        	}    
			}
	}while(error == 1);
	
	checked[count++] = number;
	printf("사용자가 %d를 선택하였습니다 : \n", number);
	
    }
    return number;
}

int get_number_byCom(int n){
	int number;
	int x, error;
	int try_again;
	
	do{
	    number = rand() % 25 + 1;
	    if(error == 0){
	    	for(x=0; x<count; x++){
	    		if(checked[x] == number){
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
	
		
void erase_bingo(int arr[N][N], int input_number){
	int x,y;
	
	for(x=0; x<N; x++){
		for(y=0; y<N; y++){
			if(arr[x][y] == input_number){
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
		
		if(rows==N){
			check++;
		}
		if(column==N){
			check++;
		}
		
		if(bingo_byMe[i][i]==0){
			crossleft++;
		}
		if(bingo_byCom[N-1-i][i]==0){
			crossright++;
		}
		
		if(crossleft==N){
			check++;
		}
		if(crossright==N){
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


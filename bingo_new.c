#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define N2 25
#define M 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void initiate_bingo(int bingo[5][5]);
void erase_bingo(int bingo[5][5], int number); //���ù��� ���ڸ� ���� 
void count_bingo(int bingo_byMe[5][5], int bingo_byCom[5][5]); //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
void print_winner(int winner); //���� ���� ���ڸ� ��� 
int get_number_byMe(int num); //���� ���� ��ȣ �Է� ���� 
int get_number_byCom(int num); //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
int check_bingo(int bingo[5][5]); //����, ����, �����ʴ밢��, ���ʴ밢�� üũ 
int checked[25];
int count=0;
int bingo_byMe [5][5]; // ���� ���� ���̺� 
int bingo_byCom [5][5]; //��ǻ���� ���� ���̺� 


int main(void){
    int bingo[5][5];
	
	printf("���� ���� ��Ģ\n");
	printf("1. 1~25������ ���ڸ� �Է��ϼ���\n");
	printf("2. ���� 5���� �Ǹ� �¸�\n");
	printf("�غ�Ǽ̳���?\n");
	  
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
			printf("1~25������ ���ڸ��Է��Ͻÿ� : \n");
			scanf("%d", &number); 
			 if(number<1 || number>25){
			 error = 1;
			}
			if(error == 0){
	    	for(x=0; x<count; x++){
	    		if(checked[x] == number){
	    		printf("�̹� �Է��� �����Դϴ�\n");	
			    error = 1;
			    break;
	        	}    
			}
	}
	
	checked[count++] = number;
	printf("����ڰ� %d�� �����Ͽ����ϴ� : \n", number);
	
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
	    		printf("�̹� �Է��� �����Դϴ�\n");
			    error = 1;
			    break;
	        	}    
			}
		}
		
	}while(error == 1);
	
	checked[count++] = number;
	printf("��ǻ�Ͱ� %d�� �����Ͽ����ϴ� : \n", number);
	
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
			printf("����ڰ� �̰���ϴ�\n");
			break;
		case 2 :
		    printf("��ǻ�Ͱ� �̰���ϴ�\n");
		    break;
		case 3 :
		    printf("�����ϴ�\n");
			break;
		default :
		    printf("�����Դϴ�\n");
			break;			
	}
}


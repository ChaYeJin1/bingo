#include <stdio.h>
#include <stdlib.h>

#define N 5
#define N2 25
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void initiate_bingo(); //���� ���̺��� �ʱ⿡ ������� 
void set_rand(int *arr);
void swap(int *i, int *j);
void print_bingo(int arr[5][5]); //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ��� 
void erase_bingo(int arr[5][5], int number);
void check_bingo(int arr[5][5]); 
void print_winner(int winner);
int get_number_byMe(int n); //���� ���� ��ȣ �Է� ���� 
int get_number_byCom(int n); //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
int count_bingo(int [5][5]); //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
int count = 0;
int checked[25];
int bingo_byMe [5][5];
int bingo_byCom [5][5]; 

void main(){
	int number, winner_Me, winner_Com;
	initiate_bingo();
	
    do{
    	printf("�� ������\n");
    	print_bingo(bingo_byMe);
    	number = get_number_byMe(number);
    	erase_bingo(bingo_byMe, number);
    	erase_bingo(bingo_byCom, number);
    	number = get_number_byCom(number);
    	erase_bingo(bingo_byCom, number);
    	erase_bingo(bingo_byMe, number);
    	
    	winner_Me = check_bingo(bingo_byMe);
    	winner_Com = check_bingo(bingo_byCom);
	}while((winner_Me == 0) && (winner_Com == 0)); //0�� ���� ���� �ϼ��� �� �� ���� �ǹ�
	
    printf("�� ������\n");
	print_bingo(bingo_byMe);
	printf("��ǻ�� ������\n"); 
	print_bingo(bingo_byCom);   
  
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
			printf("1~25������ ���ڸ��Է��Ͻÿ� : ");
			scanf("%d", &number); 
			 if(number<1 || number>25){
			 error = 1;
			}
			if(error == 0){
	    	for(x=0; x<count; x++){
	    		if(checked[x] == number){
			    error = 1;
			    break;
	        	}    
			}
	}while(error == 1);
	
	checked[count++] = number;
	printf("����ڰ� %d�� �����Ͽ����ϴ� : \n", number);
	
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
	printf("��ǻ�Ͱ� %d�� �����Ͽ����ϴ� : \n", number);
	
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

int count_bingo(int arr[5][5]){
	int line = 0;
	int x, y, xy;
	
	for(y=0; y<N; y++){
		for(x=0; x<N; x++){
			if(arr[y][x] == 0)
			break;
			else if(x == N-1)
			line++;
		}
	}
		
	for(y=0; y<N; y++){
		for(x=0; x<N; x++){
			if(arr[x][y] == 0)
			break;
			else if(x == N-1)
			line++;
	    }
		    
	}
	
	for(xy=0; xy<N; xy++){
		if(arr[xy][xy] == 0)
		break;
		else if(xy == N-1)
		line++;
	    }
	    
	for(xy=N-1; xy>=0; xy--){
		if(arr[xy][xy] == 0)
		break;
		else if(xy == 0)
		line++;
	}  
	return line;  
}


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
void print_winner(int winner);
void count_bingo(int bingo_byMe[5][5], int bingo_byCom[5][5]); //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
int get_number_byMe(int n); //���� ���� ��ȣ �Է� ���� 
int get_number_byCom(int n); //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
int check_bingo(int arr[5][5]);
int count = 0;
int checked[25];
int bingo_byMe [5][5];
int bingo_byCom [5][5]; 

int main(void){
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
			printf("1~25������ ���ڸ��Է��Ͻÿ� : ");
			scanf("%d", &number); 
			 if(number<1 || number>25){
			 error = 1;
			}
			if(error == 0){
	    	for(x=0; x<count; x++){
	    		if(checked[x] == number){
	    		printf("�̹� �Է��� �����Դϴ�");	
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


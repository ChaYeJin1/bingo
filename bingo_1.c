#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5//5*5�� ���� ���̺� 
#define M 1//���� �� �� �ϼ��� ��ǥ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int table;
int mtable[5][5]; //���� ���� ���̺� 
int ctable[5][5]; //��ǻ���� ���� ���̺� 
int check_bingo(int table[5][5]); //���ǿ� ���� ����, ����, �밢�� Ȯ�� 
int count=0;


void main(){
int x, y; 
int mtable[5][5];
int ctable[5][5];
int num = 0; 
int cnum = 0; 
int count; 
int breakpoint;
int line=0;
int my=0;
int com=0;
int ss=0;

printf("----���� ���� ���� ��----\n");
printf("1. ���õ� ���ڴ� 0���� ��ȯ\n");
printf("2. ����, ����, �밢���� Ȯ���Ͽ� ���� 0�� ���� 1���̸�  ����\n ");
printf("���� ���� ����\n");
printf("------------------\n");
srand((unsigned int)time(NULL));	
printf("---<���� ������>---\n");                                    	
	
for (x = 0; y < 25; x++) { 
   mtable[0][x] = rand() % 25 + 1; 
      for (y = 0; y < x; y++) { 
         if (mtable[0][y] == mtable[0][x]) 
		 { x--; } 
        } 
      } 
for (x = 0; x < 5; x++) { 
   for (y = 0; y < 5; y++) { 
      printf("\t"); 
      printf("%d ", mtable[x][y]); 
         } 
      printf("\n"); 
      } 
      
printf("---<��ǻ���� ������>---\n"); 
for (x = 0; x < 25; x++) { 
   ctable[0][x] = rand() % 25 + 1; 
      for (y = 0; y < x; y++) { 
         if (ctable[0][y] == ctable[0][x]) { x--; } 
         } 
      } 
for (x = 0; x < 5; x++) { 
   for (y = 0; y < 5; y++) { 
      printf("\t"); 
      printf("%d ", ctable[x][y]); 
         } 
      printf("\n"); 
      } 
      
while(1){
	breakpoint = 0;
	printf("���ڸ� �Է��ϼ��� : \n");
	scanf("%d", &num);
	
	for(x=0; x<5; x++){
		for(y=0; y<5; y++){
			if(mtable[x][y] == num){
				mtable[x][y] = 0;
				breakpoint = 1;
			}
			if(ctable[x][y] == num){
				ctable[x][y] = 0;
			}
			if(count>=1)
			break;
		}
	}
	
	if(breakpoint==0){
		printf("�̹� ������ �����Դϴ�! �ٽ� �Է��ϼ���\n");
		continue;
	}
	
	breakpoint = 0;
	printf("��ǻ���� �����Դϴ�\n");
	cnum = rand() % 25 + 1;
	for(x=0; x<5; x++){
		for(y=0; y<5; y++){
			if(ctable[x][y] == cnum){
				ctable[x][y] = 0;
				printf("��ǻ�ʹ� %d�� �Է��߽��ϴ�\n", cnum);
				breakpoint = 1;
			}
			
			if(mtable[x][y] == cnum){
				mtable[x][y] = 0;
			}
		}
	}
	
	
printf("---<���� ������>---\n");   
for (x = 0; x < 5; x++) { 
   for (y = 0; y < 5; y++) { 
      printf("\t"); 
      printf("%d ", mtable[x][y]); 
     } 
      printf("\n"); 
   } 

printf("---<��ǻ���� ������>---\n");       
for (x = 0; x < 5; x++) { 
   for (y = 0; y < 5; y++) { 
      printf("\t"); 
      printf("%d ", ctable[x][y]); 
     } 
      printf("\n"); 
     } 
	 ss++;
	 my=check_bingo(mtable);
	 com=check_bingo(ctable);
	 
	 if((my==1)){printf("���� ��\n");}
	 else if((com==1)){printf("��ǻ�� ��\n");}
	 
	 if((my==1)||(com==1)){
	 	printf("�̱� Ƚ�� : %d��\n", ss);
	 	break;
	  }
   } 
}

int check_bingo(int table[5][5]){
	int i, j;
	int sum;
	int line;
	
	
//���� �� Ȯ��	
for (j = 0; j < 5; j++) { 
   sum = 0;
   for (i = 0; i < 5; i++) {
   sum += table[j][i];
   }
   if(sum==0){
   	line++;
   }
}
//���� �� Ȯ�� 
for (i = 0; i < 5; i++) { 
   sum = 0;
   for (j = 0; j < 5; j++) {
   	sum += table[i][j];
   }
   if(sum==0){
   	line++;
   }
}
//�밢�� Ȯ�� 
sum=0;
for (i = 0; i < 5; i++) { 
   sum += table[i][i]; }
   if(sum==0){
    line++;
   }
   
sum=0;
for (i = 0; i < 5; i++) {
   sum += table[i][5-i-1]; }
   if(sum==0){
    line++;
   }
  
if(line>=1)
return 1;
else    
   return 0;
}

   







#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int table;
int mtable[5][5]; //���� ���� ���̺� 
int ctable[5][5]; //��ǻ���� ���� ���̺� 
int check_bingo(int *bingo); //���ǿ� ���� ����, ����, �밢�� Ȯ�� 
int count=0;


void main(){
int i, j; 
int mtable[5][5];
int ctable[5][5];
int num = 0; 
int cnum = 0; 
int count; 
int breakpoint;

printf("���� ���� ����\n");
srand((unsigned int)time(NULL));	
printf("---<���� ������>---\n");                                    	
	
for (i = 0; i < 25; i++) { 
   mtable[0][i] = rand() % 25 + 1; 
      for (j = 0; j < i; j++) { 
         if (mtable[0][j] == mtable[0][i]) 
		 { i--; } 
        } 
      } 
for (i = 0; i < 5; i++) { 
   for (j = 0; j < 5; j++) { 
      printf("\t"); 
      printf("%d ", mtable[i][j]); 
         } 
      printf("\n"); 
      } 
      
printf("---<��ǻ���� ������>---\n"); 
for (i = 0; i < 25; i++) { 
   ctable[0][i] = rand() % 25 + 1; 
      for (j = 0; j < i; j++) { 
         if (ctable[0][j] == ctable[0][i]) { i--; } 
         } 
      } 
for (i = 0; i < 5; i++) { 
   for (j = 0; j < 5; j++) { 
      printf("\t"); 
      printf("%d ", ctable[i][j]); 
         } 
      printf("\n"); 
      } 
      
while(1){
	breakpoint = 0;
	printf("���ڸ� �Է��ϼ��� : \n");
	scanf("%d", &num);
	
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			if(mtable[i][j] == num){
				mtable[i][j] = -1;
				breakpoint = 1;
			}
			if(ctable[i][j] == num){
				ctable[i][j] = -1;
			}
			if(count>=1)
			break;
		}
	}
	
	if(breakpoint==0){
		printf("�ٽ� �Է��ϼ���\n");
		continue;
	}
	
	breakpoint = 0;
	printf("��ǻ���� �����Դϴ�\n");
	COMPUTER:
	cnum = rand() % 25 + 1;
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			if(ctable[i][j] == cnum){
				ctable[i][j] = -1;
				printf("��ǻ�ʹ� %d�� �Է��߽��ϴ�\n", cnum);
				breakpoint = 1;
			}
			
			if(mtable[i][j] == cnum){
				mtable[i][j] = -1;
			}
		}
	}
	if(breakpoint == 0)
	goto COMPUTER;
	
printf("---<���� ������>---\n");   
for (i = 0; i < 5; i++) { 
   for (j = 0; j < 5; j++) { 
      printf("\t"); 
      printf("%d ", mtable[i][j]); 
     } 
      printf("\n"); 
   } 

printf("---<��ǻ���� ������>---\n");       
for (i = 0; i < 5; i++) { 
   for (j = 0; j < 5; j++) { 
      printf("\t"); 
      printf("%d ", ctable[i][j]); 
     } 
      printf("\n"); 
   }      
    		
 }  
 
}

int check_bingo(int *bingo){
	int checkedbingo[12] ={0} ; //�ִ� 12���� ������ �ʱ�ȭ (����5+����5+�밢��2) 
	int count = 0;
	int i, j;
//���� �� Ȯ��	
for (i = 0; i < 5; i++) { 
   for (j = 0; j < 5; j++) {
   	if(bingo[i*5+j] == -1)
   	checkedbingo[i]++;
   }
}
//���� �� Ȯ�� 
for (i = 0; i < 5; i++) { 
   for (j = 0; j < 5; j++) {
   	if(bingo[i*5+j] == -1)
   	checkedbingo[i+5]++;
   }
}
//���� �Ʒ����� ������ ���� ���� �밢�� �� Ȯ�� 
for (i = 4; i >= 0; i--) { 
   for (j = 4; j >= 4-i; j--) {
   	if(bingo[i*5+j] == -1)
   	checkedbingo[11]++;
   }
}
//���� ������ ������ �Ʒ��� ���� �밢�� �� Ȯ�� 
for (i = 0; i < 5; i++) { 
   for (j = 0; j < 5; j++) {
   	if(bingo[i*5+j] == -1)
   	checkedbingo[10]++;
   }
}
//������ �� 
for (i = 0; i < 12; i++){
	if(checkedbingo[i]==2){
		printf("bingo!\n");
	}
	count++;
}

return count;
}







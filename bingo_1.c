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
int i, j; 
//table[5][5];
int mtable[5][5];
int ctable[5][5];
int num = 0; 
int cnum = 0; 
int count=0; 
int breakpoint=0;
int line=0;
int my=0;
int com=0;
int ss=0;

printf("----���� ���� ���� ��----\n");
printf("1. ���õ� ���ڴ� 0���� ��ȯ\n");
printf("2. ����, ����, �밢���� Ȯ���Ͽ� ���� 0�� ���� 1���̸�  ����\n ");
printf("���� ���� ����\n");
printf("-------------------------\n");
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
            mtable[i][j] = 0;
            breakpoint = 1;
         }
         if(ctable[i][j] == num){
            ctable[i][j] = 0;
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
   //COMPUTER:
   cnum = rand() % 25 + 1;
   for(i=0; i<5; i++){
      for(j=0; j<5; j++){
         if(ctable[i][j] == cnum){
            ctable[i][j] = 0;
            printf("��ǻ�ʹ� %d�� �Է��߽��ϴ�\n", cnum);
            breakpoint = 1;
         }
         
         if(mtable[i][j] == cnum){
            mtable[i][j] = 0;
         }
      }
   }
   
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

ss++;
   my=check_bingo(mtable);
   com=check_bingo(ctable);

   if((my==1)){printf("---<�����մϴ�! ���� ��!>---\n");}
   else if((com==1)){printf("---<�ƽ��׿�!��ǻ�� ��!>---\n");}

   if((my==1)||(com==1)){
   printf("�̱� Ƚ��: %d��!\n",ss);
   break;
}
}
}

int check_bingo(int table[5][5]){
   int i, j;
   int sum=0;
   int line=0;
   
   
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
   //++
   if(line>=1)
      return 1;
   else
      return 0;
}

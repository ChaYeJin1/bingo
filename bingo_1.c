#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5//5*5인 빙고 테이블 
#define M 1//빙고 한 개 완성이 목표 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int table;
int mtable[5][5]; //나의 빙고 테이블 
int ctable[5][5]; //컴퓨터의 빙고 테이블 
int check_bingo(int table[5][5]); //조건에 따라 가로, 세로, 대각선 확인 
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

printf("----예진 빙고 게임 룰----\n");
printf("1. 선택된 숫자는 0으로 변환\n");
printf("2. 가로, 세로, 대각선을 확인하여 합이 0인 줄이 1개이면  빙고\n ");
printf("빙고 게임 시작\n");
printf("-------------------------\n");
srand((unsigned int)time(NULL));   
printf("---<나의 빙고판>---\n");                                       
   
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
      
printf("---<컴퓨터의 빙고판>---\n"); 
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
   printf("숫자를 입력하세요 : \n");
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
      printf("이미 선택한 숫자입니다! 다시 입력하세요\n");
      continue;
   }
   
   breakpoint = 0;
   printf("컴퓨터의 차례입니다\n");
   //COMPUTER:
   cnum = rand() % 25 + 1;
   for(i=0; i<5; i++){
      for(j=0; j<5; j++){
         if(ctable[i][j] == cnum){
            ctable[i][j] = 0;
            printf("컴퓨터는 %d를 입력했습니다\n", cnum);
            breakpoint = 1;
         }
         
         if(mtable[i][j] == cnum){
            mtable[i][j] = 0;
         }
      }
   }
   
printf("---<나의 빙고판>---\n");   
for (i = 0; i < 5; i++) { 
   for (j = 0; j < 5; j++) { 
      printf("\t"); 
      printf("%d ", mtable[i][j]); 
     } 
      printf("\n"); 
   } 

printf("---<컴퓨터의 빙고판>---\n");       
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

   if((my==1)){printf("---<축하합니다! 나의 승!>---\n");}
   else if((com==1)){printf("---<아쉽네요!컴퓨터 승!>---\n");}

   if((my==1)||(com==1)){
   printf("이긴 횟수: %d번!\n",ss);
   break;
}
}
}

int check_bingo(int table[5][5]){
   int i, j;
   int sum=0;
   int line=0;
   
   
//가로 줄 확인   
for (j = 0; j < 5; j++) { 
   sum = 0;
   for (i = 0; i < 5; i++) {
   sum += table[j][i];
   }
   if(sum==0){
      line++;
   }
}
//세로 줄 확인 
for (i = 0; i < 5; i++) { 
   sum = 0;
   for (j = 0; j < 5; j++) {
      sum += table[i][j];
   }
   if(sum==0){
      line++;
   }
}
//대각선 확인 
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

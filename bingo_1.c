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

printf("----예진 빙고 게임 룰----\n");
printf("1. 선택된 숫자는 0으로 변환\n");
printf("2. 가로, 세로, 대각선을 확인하여 합이 0인 줄이 1개이면  빙고\n ");
printf("빙고 게임 시작\n");
printf("------------------\n");
srand((unsigned int)time(NULL));	
printf("---<나의 빙고판>---\n");                                    	
	
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
      
printf("---<컴퓨터의 빙고판>---\n"); 
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
	printf("숫자를 입력하세요 : \n");
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
		printf("이미 선택한 숫자입니다! 다시 입력하세요\n");
		continue;
	}
	
	breakpoint = 0;
	printf("컴퓨터의 차례입니다\n");
	cnum = rand() % 25 + 1;
	for(x=0; x<5; x++){
		for(y=0; y<5; y++){
			if(ctable[x][y] == cnum){
				ctable[x][y] = 0;
				printf("컴퓨터는 %d를 입력했습니다\n", cnum);
				breakpoint = 1;
			}
			
			if(mtable[x][y] == cnum){
				mtable[x][y] = 0;
			}
		}
	}
	
	
printf("---<나의 빙고판>---\n");   
for (x = 0; x < 5; x++) { 
   for (y = 0; y < 5; y++) { 
      printf("\t"); 
      printf("%d ", mtable[x][y]); 
     } 
      printf("\n"); 
   } 

printf("---<컴퓨터의 빙고판>---\n");       
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
	 
	 if((my==1)){printf("나의 승\n");}
	 else if((com==1)){printf("컴퓨터 승\n");}
	 
	 if((my==1)||(com==1)){
	 	printf("이긴 횟수 : %d번\n", ss);
	 	break;
	  }
   } 
}

int check_bingo(int table[5][5]){
	int i, j;
	int sum;
	int line;
	
	
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
  
if(line>=1)
return 1;
else    
   return 0;
}

   







#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int table;
int mtable[5][5]; //나의 빙고 테이블 
int ctable[5][5]; //컴퓨터의 빙고 테이블 
int check_bingo(int *bingo); //조건에 따라 가로, 세로, 대각선 확인 
int count=0;


void main(){
int i, j; 
int mtable[5][5];
int ctable[5][5];
int num = 0; 
int cnum = 0; 
int count; 
int breakpoint;

printf("빙고 게임 시작\n");
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
		printf("다시 입력하세요\n");
		continue;
	}
	
	breakpoint = 0;
	printf("컴퓨터의 차례입니다\n");
	COMPUTER:
	cnum = rand() % 25 + 1;
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			if(ctable[i][j] == cnum){
				ctable[i][j] = -1;
				printf("컴퓨터는 %d를 입력했습니다\n", cnum);
				breakpoint = 1;
			}
			
			if(mtable[i][j] == cnum){
				mtable[i][j] = -1;
			}
		}
	}
	if(breakpoint == 0)
	goto COMPUTER;
	
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
    		
 }  
 
}

int check_bingo(int *bingo){
	int checkedbingo[12] ={0} ; //최대 12개의 빙고판 초기화 (가로5+세로5+대각선2) 
	int count = 0;
	int i, j;
//가로 줄 확인	
for (i = 0; i < 5; i++) { 
   for (j = 0; j < 5; j++) {
   	if(bingo[i*5+j] == -1)
   	checkedbingo[i]++;
   }
}
//세로 줄 확인 
for (i = 0; i < 5; i++) { 
   for (j = 0; j < 5; j++) {
   	if(bingo[i*5+j] == -1)
   	checkedbingo[i+5]++;
   }
}
//왼쪽 아래에서 오른쪽 위로 가는 대각선 줄 확인 
for (i = 4; i >= 0; i--) { 
   for (j = 4; j >= 4-i; j--) {
   	if(bingo[i*5+j] == -1)
   	checkedbingo[11]++;
   }
}
//왼쪽 위에서 오른쪽 아래로 가는 대각선 줄 확인 
for (i = 0; i < 5; i++) { 
   for (j = 0; j < 5; j++) {
   	if(bingo[i*5+j] == -1)
   	checkedbingo[10]++;
   }
}
//빙고의 수 
for (i = 0; i < 12; i++){
	if(checkedbingo[i]==2){
		printf("bingo!\n");
	}
	count++;
}

return count;
}







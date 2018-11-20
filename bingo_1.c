#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int mtable[5][5];
int ctable[5][5];
int check_bingo(int mtable[5][5], int ctable[5][5]);
void count_bingo(int mtable[5][5], int ctable[5][5]);
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

int check_bingo(int mtable[5][5], int ctable[5][5]){
	int i, j;
	int rows = 0;
	int column = 0;
	int crossleft = 0;
	int crossright = 0;
	int check = 0;

	
	for(i=0; i<5; i++){
		rows=0;
		column=0;
		
		for(j=0; j<5; j++){
			if(mtable[i][j]==-1){
				rows++;
			}
			if(mtable[j][i]==-1){
				column++;
			}
		}
		
		if(rows==1){
			printf("빙고");
			check++;
		}
		if(column==1){
			printf("빙고");
			check++;
		}
		
		if(mtable[i][i]==-1){
			crossleft++;
		}
		if(mtable[5-1-i][i]==-1){
			crossright++;
		}
		
		if(crossleft==1){
			printf("빙고");
			check++;
		}
		if(crossright==1){
			printf("빙고");
			check++;
		}
	} 
		for(i=0; i<5; i++){
		rows=0;
		column=0;
		
		for(j=0; j<5; j++){
			if(ctable[i][j]==-1){
				rows++;
			}
			if(ctable[j][i]==-1){
				column++;
			}
		}
		
		if(rows==1){
			printf("빙고");
			check++;
		}
		if(column==1){
			printf("빙고");
			check++;
		}
		
		if(mtable[i][i]==-1){
			crossleft++;
		}
		if(mtable[5-1-i][i]==-1){
			crossright++;
		}
		
		if(crossleft==1){
			printf("빙고");
			check++;
		}
		if(crossright==1){
			printf("빙고");
			check++;
		}
	} 
	return check;
}

void count_bingo(int mtable[5][5], int ctable[5][5]){
	int i,j;
	int count = 1;
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			mtable[i][j]=count;
			ctable[i][j]=count;
			count++;
		}
	}
}





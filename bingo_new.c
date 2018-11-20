
#include <stdio.h>


#include <stdlib.h>


#include <time.h>


#include <windows.h>




#define MAX 5


#define WHITE 15


#define YELLOW 14


9. 


10. 

void textcolor(int color_number); // 텍스트 칼라 출력

void gotoxy(int x, int y); // 좌표 이동

int baserand(int x, int y); // 랜덤 범위 지정


14. 


15.// 초기값 설정


16.void InitCount(int Player[MAX][MAX] , int Com[MAX][MAX]);


17. 


18.// MAP 설정


19.void MixMAP(int Player[MAX][MAX]);


20.int SearchMAP(int Player[MAX][MAX] ,int Num);


21.void printMAP(int Player[MAX][MAX]);


22.int CheckMAP(int Player[MAX][MAX]);


23. 


24.// 승리조건


25.void Winner(int flag , int Player[MAX][MAX],int Com[MAX][MAX]);


26. 


27. 


28. 


29. 


30.int main(void){


31. 


32.        int Player[MAX][MAX];


33.        int Com[MAX][MAX];


34.        int playerChk,comChk;


35.        int Num;        


36. 


37.        InitCount(Player,Com);


38.        


39.        MixMAP(Player);


40. 


41.        while(1){


42.                gotoxy(0,0);


43. 


44.                // 컴퓨터들 출력


45.                textcolor(WHITE);


46.                printf(" ====== Player ====== \n");


47.                printMAP(Player);


48.                textcolor(WHITE);


49.                printf(" ===== Computer ===== \n");


50.                printMAP(Com);          


51. 


52.                textcolor(WHITE);


53.                printf(" > ");


54.                scanf("%d",&Num);


55. 


56.                if( SearchMAP(Player,Num) == 0){


57.                        printf("잘못입력하셨습니다. \n");                      


58.                        system("pause");


59.                        system("cls");


60.                        continue;


61.                }


62. 


63.                SearchMAP(Com,Num);


64. 


65.                // 컴퓨터 턴


66.                while( 1 ){


67.                        Num = baserand(1,MAX*MAX); 


68.                        if(SearchMAP(Com, Num) ==1 ){


69.                                SearchMAP(Player, Num);


70.                                break;


71.                        }


72.                }


73. 


74.                playerChk = CheckMAP(Player);


75.                comChk = CheckMAP(Com);


76. 


77.                printf("Player Check = %d \n",playerChk);


78.                printf("Com Check = %d \n",comChk);


79. 


80.                if(playerChk >= MAX && comChk >= MAX){


81.                        if( playerChk > comChk){


82.                                Winner(0,Player,Com); // 내가 이겼을 때


83.                        }else if( playerChk < comChk) {


84.                                Winner(1,Player,Com); // 내가 졌을 때


85.                        }else{


86.                                Winner(2,Player,Com); // 배겼을 때


87.                        }


88.                }else  if(playerChk >= MAX){


89.                        Winner(0,Player,Com); // 내가 이겼을 때


90.                }else  if(comChk >= MAX){


91.                        Winner(1,Player,Com); // 내가 졌을 때


92.                }


93. 


94.                system("pause");


95.                system("cls");


96.        }


97.        return 0;


98.}


99. 


100.// 텍스트 칼라 출력


101.void textcolor(int color_number)


102.{


103. SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);


104.};


105.// 좌표 이동


106.void gotoxy(int x, int y)


107.{


108.     COORD Cur;


109.     Cur.X=x;


110.     Cur.Y=y;


111.     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);


112.}


113.// 랜덤 범위 지정


114.int baserand(int x, int y){


115. 


116.        static int z = 0;


117.        int tmp;


118.        if(z==0){


119.                srand((int)time(NULL));


120.                rand();rand();rand();rand();


121.                srand(rand());


122.                z=1;


123.        }


124. 


125.        tmp = rand()%(y-x+1)+x;


126.        return tmp;


127.}


128. 


129.void printMAP(int Player[MAX][MAX]){


130.        int i,j;


131.        for(i=0;i<MAX;i++){


132.                for(j=0;j<MAX;j++){


133.                        if(Player[i][j] == 0){


134.                                textcolor(YELLOW);


135.                                printf("%4s","♥");


136. 


137.                        }else{


138.                                textcolor(WHITE);


139.                                printf("%4d",Player[i][j]);


140.                        }


141.                }


142.                printf("\n");


143.        }


144.}


145. 


146. 


147.void MixMAP(int Player[MAX][MAX]){


148. 


149.        int i;


150.        int x1,y1;


151.        int x2,y2;


152.        int tmp;


153. 


154.        printMAP(Player);


155. 


156.        for(i=0;i< 10*MAX ;i++){


157. 


158.                x1 = baserand(0,MAX-1);


159.                y1 = baserand(0,MAX-1);


160. 


161.                x2 = baserand(0,MAX-1);


162.                y2 = baserand(0,MAX-1);


163. 


164.                // 두 값을 서로 바꾸는 코드


165.                tmp = Player[x1][y1];


166.                Player[x1][y1] = Player[x2][y2];


167.                Player[x2][y2] = tmp;


168. 


169.                gotoxy(0,0);


170.                printMAP(Player);               


171.        


172.                Sleep(10);


173.        }


174.        system("pause");


175.        system("cls");


176.        


177.}


178. 


179.int SearchMAP(int Player[MAX][MAX] ,int Num){


180. 


181.        int i,j;


182.        int flag = 0;


183. 


184.        for(i=0;i<MAX;i++){


185.                for(j=0;j<MAX;j++){


186.                        if(Player[i][j] == Num){


187.                                flag = 1;


188.                                Player[i][j] = 0;


189.                        }


190.                }


191.        }


192. 


193.        return flag;


194.}


195. 


196.int CheckMAP(int Player[MAX][MAX]){


197.        int i,j;


198.        int rowsFlag = 0;


199.        int columnFlag = 0;


200.        int crossleftFlag = 0;


201.        int crossrightFlag = 0;


202.        int check = 0;          


203. 


204.        for(i=0;i<MAX;i++){


205.                rowsFlag = 0;


206.                columnFlag = 0;


207. 


208.                for(j=0;j<MAX;j++){


209.                        if(Player[i][j] == 0){


210.                                rowsFlag++;


211.                        }


212.                        if(Player[j][i] == 0){


213.                                columnFlag++;


214.                        }


215.                }


216.                // 가로체크


217.                if(rowsFlag == MAX){


218.                        check++;


219.                }


220.                // 세로체크


221.                if(columnFlag == MAX){


222.                        check++;


223.                }


224.                // 대각선 왼쪽에서 오른쪽


225.                if(Player[i][i] == 0){


226.                        crossleftFlag++;


227.                }


228.                // 대각선 오른쪽에서 왼쪽


229.                if(Player[MAX-1-i][i] == 0){


230.                        crossrightFlag++;


231.                }


232.        }


233. 


234.        if(crossleftFlag == MAX){


235.                check++;


236.        }


237. 


238.        if(crossrightFlag == MAX){


239.                check++;


240.        }


241. 


242.        return check;


243.}


244. 


245.void Winner(int flag , int Player[MAX][MAX],int Com[MAX][MAX]){


246.        gotoxy(0,0);


247.        textcolor(WHITE);


248.        printf(" ====== Player ====== \n");


249.        printMAP(Player);


250.        textcolor(WHITE);


251.        printf(" ===== Computer ===== \n");


252.        printMAP(Com);          


253.        gotoxy(0,MAX*2+5);


254.        switch(flag){


255.                case 0:


256.                        printf("당신이 이겼습니다. \n");


257.                        break;


258.                case 1:


259.                        printf("당신이 졌습니다. \n");


260.                        break;


261.                case 2:


262.                        printf("비겼습니다. \n");


263.                        break;


264.        }


265.        exit(0);


266. 


267.}


268. 


269.void InitCount(int Player[MAX][MAX] , int Com[MAX][MAX]){


270. 


271.        int i,j;


272.        int count =1 ;


273.        for(i=0;i<MAX;i++){


274.                for(j=0;j<MAX;j++){


275.                        Player[i][j] = count;


276.                        Com[i][j] = count;


277.                        count++;


278.                }


279.        }


280.}


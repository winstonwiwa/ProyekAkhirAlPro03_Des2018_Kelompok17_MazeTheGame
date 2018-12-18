#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define ff() while(getchar()!='\n')

int xP = 4, yP = 18;
int step = 0;
int xRand, iRand;

struct highscore {
   char nama [50];
   int step;
   struct highscore *next;
};

struct highscore *head = NULL;

void bubbleSort(struct highscore *head) { 
    int swapped, i; 
    struct highscore *link; 
    struct highscore *lptr = NULL; 
  
    /* Checking for empty list */
    if (head == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        link = head; 
  
        while (link->next != lptr) 
        { 
            if (link->step > link->next->step) 
            {  
                swap(link, link->next); 
                swapped = 1; 
            } 
            link = link->next; 
        } 
        lptr = link; 
    } 
    while (swapped); 
} 

void swap(struct highscore *a, struct highscore *b) { 
	char tempnama[50];
    int tempstep = a->step; 
    strcpy(tempnama,a->nama);
    a->step = b->step;
	strcpy(a->nama,b->nama); 
    b->step = tempstep; 
   strcpy(b->nama,tempnama);
} 

void printlist() {
   struct highscore *ptr = head;
   int i=1;
   cls();
    printf("\n\t   -----------\n\t   LEADERBOARD\n\t   -----------\n\n");
    printf("\tRanking  Nama\t  Step\n"); 
    printf("\t----------------------\n");
   while(ptr != NULL) {       
      printf("\t%d        %s\t    %d\n", i, ptr->nama, ptr->step);
      ptr = ptr->next;
      i++;
   }
     printf("\n\n\tTekan tombol apapun untuk melanjutkan");
	 getch();
}

void insert (char *nama, int step) {
   struct highscore *link = malloc(sizeof(struct highscore));

   link->step = step;
   strcpy(link->nama, nama);	

   link->next = head;
   head = link;
}
	
char map [100][100] = {
	"######################################################",
	"##                                                  ##",
	"##                                                   O",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"##                                                  ##",
	"######################################################",
};

int random_number(int min_num, int max_num){
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL)*iRand*xRand);
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

void randomMap(){
	int xRand1, xRand2, xRand3, xRand4, xRand5, xRand6, xRand7, xRand8, xRand9, xRand10, xRand11, xRand12;
	for (iRand=1;iRand<21;iRand++){
		xRand=1 ;
		xRand1 = random_number (2,6);
		xRand++ ;
		xRand2 = random_number (7,11);
		xRand++ ;
		xRand3 = random_number (12,16);
		xRand++ ;
		xRand4 = random_number (17,21);						
		xRand++ ;
		xRand5 = random_number (22,26);
		xRand++ ;
		xRand6 = random_number (27,31);
		xRand++ ;
		xRand7 = random_number (32,36);
		xRand++ ;
		xRand8 = random_number (37,41);
		xRand++ ;
		xRand9 = random_number (42,46);
		xRand++ ;
		xRand10 = random_number (47,50);
		xRand++ ;
		map[iRand][xRand1] = 35;
		map[iRand][xRand2] = 35;
		map[iRand][xRand3] = 35;
		map[iRand][xRand4] = 35;
		map[iRand][xRand5] = 35;
		map[iRand][xRand6] = 35;
		map[iRand][xRand7] = 35;
		map[iRand][xRand8] = 35;
		map[iRand][xRand9] = 35;
		map[iRand][xRand10] = 35;		
	}
}

void clearMap(){
	int x,y;
	for (x=0;x<52;x++){
		map [0][x]=35;
		map [22][x]=35;
	}
	for (y=1;y<21;y++){
		map [y][0]=35;
		map [y][1]=35;
		map [y][52]=35;
		map [y][53]=35;
	}
	map [2][52]=' ';
	map [2][53]='O';
	
	for (y=1;y<21;y++){
		for (x=2;x<52;x++){
			map [y][x]=' ';
		}
	}
}

void cls(){
	system("cls");
}

void printMap(){
	map[yP][xP] = 1;
	int i;
	for(i=0;i<22;i++){
		printf("\n");
		printf(map[i]);
	}
}

int game(){
	int isBack=0;
	int i;
	clearMap();
	randomMap();
	do{
		system ("cls");
		printf("Tekan ESC untuk kembali ke menu utama");
		printf("\nSteps : %d\n", step);
		for(i=0;i<5;i++) printf("");
		printMap();
		for(i=0;i<5;i++) printf("");
		map[yP][xP] = ' ';
		switch(getch()){
			case 'w': case 'W':
				if(map[yP-1][xP] == ' '){
					yP--; step++;
				}
				break;
			case 's': case 'S':
				if(map[yP+1][xP] == ' '){
					yP++; step++;
				}
				break;
			case 'a': case 'A':
				if(map[yP][xP-1] == ' '){
					xP--; step++;
				}
				break;
			case 'd': case 'D':
				if(map[yP][xP+1] == 79){
					isBack = 1;
					finish();
				}
				else if(map[yP][xP+1] == ' '){
						xP++; step++;
					}
				break;
			case 27:
				isBack = 1;
				break;
		}
	}while(isBack!=1);
	xP = 4, yP = 18;
	return xP, yP, step;
}

int finish(){
	char nama[50];
	cls();
	printf("\nSELAMAT ANDA TELAH MENYELESAIKAN LEVEL INI !");
	printf("\n\nMasukkan nama anda :"); scanf_s("%s", &nama);
	insert(nama, step);
	cls();
	bubbleSort(head);
	printlist();
	step=0,xP = 4, yP = 10;
	getch();
	menu();

	return xP, yP, step;
}
	
void about(){
	cls();
	printf("\nThe Maze adalah sebuah game sederhana yang di buat dengan bahasa C \n\n Tujuan utama dari game adalah keluar dari labirin menuju O \n\n Pengguna menggerakan avatar dengan menekan tombol W/A/S/D");
	getch();
}

void menu(){
	char menu[4][50] = {
		"-> Mulai Game",
		"   Leaderboard",
		"   About",
		"   Keluar"
	};
	
	int idx = 0;
	int isExit=0;
	int i;
	do{
		system ("cls");
		for(i=0;i<4;i++){
			printf("\n");
			printf(menu[i]);
		}
		menu[idx][0] = ' ';
		menu[idx][1] = ' ';
		
		switch(getch()){
			case 's': case 'S':
				idx++;
				if(idx > 3) idx = 0;
				break;
			case 'w': case 'W':
				idx--;
				if(idx < 0) idx = 3;
				break;
			case 13:
				switch(idx){
					case 0:
						game();
						break;
					case 1:
						printlist();
	
						break;
					case 2:
						about();		
						break;
					case 3:
						isExit = 1;
						break;
				}
				break;
		}
		menu[idx][0] = '-';
		menu[idx][1] = '>';
	}while(isExit!=1);
}

int main(){
	insert("wiwa", 0);
	insert("rex", 72);
	menu();

	return 0;
}


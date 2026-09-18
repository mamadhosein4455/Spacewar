// STAR*****1
// CHECK KAMEL33
//CHANGE PASS22
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#include <pthread.h>

#define MAXLL 30
#define MAXCC 70
#define PLAYER1 '1'
#define PLAYER2 '2'
#define WALL '#'

char land[MAXLL][MAXCC];
int x1Row , x1Col ;
int x2Row , x2Col;
int Bx1Row, Bx1Col;
int Bx2Row, Bx2Col;


int jan1  ;
int jan2  ;

int xt1R = -1 , xt1C = -1 ;
int xt2R = -1 , xt2C = -1;
int bxt1R , bxt1C ;
int bxt2R , bxt2C ;
int hasf1  = -1, hasf2 = -1 ;
int hasft1 = -1; hasft2 = -1;
int hasft3 = -1; hasft4 = -1;
int hasf1r , hasf2r ;

int chale1 , chale2 ;
int chale3 , chale4 ;
int hasfch1 , hasfch2 ;
int emtias1 , emtias2 ;



int Rooh1 ;
int Rooh2 ;
int counterRooh1 ;
int counterRooh2 ;

int rh1 , rh2 ;

char J1 = 'W' ;
char J2 = 'i';
char JT1 ;
char JT2 ;

int ert1R  , ert1C  ;
int ert2R  , ert2C ;
int h1 , h2 ;


int ndarad1  , ndarad2  ;

int ertdarad1 , ertdarad2 ;

int por1R , por1C ;
int por2R , por2C ;

int n1 , n2 ;
int n3 , n4 ;
int bn1 , bn2 ;
int nh1 , nh2 ;

char JN ;

int bomb1R = -1 , bomb1C = -1;
int hbomb1R = -1 , hbomb1C = -1 ;
int bombdarad1 = 0 , bombdarad2 = 0 ;
clock_t start_time1;
clock_t start_time2;
int bomb2R = -1 , bomb2C = -1;
int hbomb2R = -1 , hbomb2C = -1 ;

int jabe1R  = -1 , jabe1C = - 1;
int hjabe1R = -1 , hjabe1C = -1 ;








struct User {
    char name[50];
    char email[50];
    char pass[50];
    char Winers[1000];
    int win;
    int fail;
    int total;
} u;

char p1[50];
char p2[50];
char History1[1000];
char History2 [1000];
int win1 ;
int win2 ;
int fail1;
int fail2;
int total1;
int total2;


void menuv(void);
void signUp(void);
int hasbefor(const char *Usernamein);
void printData(void);
void singIN(void);
void forgatp(void);
void EnterGame(void);
void menup(void);
void StartGame(void);
void Changeinformaion(void);
void changename(void);
void changeemial(void);
void changepassword(void);
void Historyism(void);
void build1 (void);
void build2 (void);
void build3(void) ;
void print(void);
void onthegmae(void);
void Move1 (void);
void Move2(void);
void Tir1 (void);
void Tir2 (void);
void sabt();
void randing();


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//void filebefile(void);

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);

    printf("\n\n\t\t\t\tWELCOME TO SPACE WAR\n\n\n");
    SetConsoleTextAttribute(hConsole, 7);
    Sleep(1500);
    menuv();
    return 0;
}

void menuv() {
    while (1) {
        char choice[10];
        printf("1. Signup\n2. Print\n3. Sign in\n4. Exit\n");
        gets(choice);

        if (strlen(choice) > 1) {
            printf("the input was not correct try again\n");
            continue;
        }

        switch (choice[0]) {
            case '1':
                signUp();
                break;
            case '2':
                system("cls");
                printData();
                break;
            case '3':

                singIN();
                break;
            case '4':
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please enter a valid number.\n");
        }
    }
}

void signUp() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("Enter username: ");
    fgets(u.name, sizeof(u.name), stdin);
    u.name[strcspn(u.name, "\n")] = '\0';

    while (hasbefor(u.name)) {
            SetConsoleTextAttribute(hConsole, 12);
        printf("Username already taken. Please enter a different username: ");
    SetConsoleTextAttribute(hConsole, 7);
        fgets(u.name, sizeof(u.name), stdin);
        u.name[strcspn(u.name, "\n")] = '\0';
    }

    printf("Enter email: ");
    fgets(u.email, sizeof(u.email), stdin);
    u.email[strcspn(u.email, "\n")] = '\0';

    while (1) {
        printf("Enter password (minimum 8 characters): ");
        fgets(u.pass, sizeof(u.pass), stdin);
        u.pass[strcspn(u.pass, "\n")] = '\0';

        char repeat[50];
        printf("Repeat password: ");
        fgets(repeat, sizeof(repeat), stdin);
        repeat[strcspn(repeat, "\n")] = '\0';
        if (strcmp(u.pass, repeat) != 0 || strlen(u.pass) < 8) {
                SetConsoleTextAttribute(hConsole, 12);
            printf("Passwords do not match or are less than 8 characters. Please try again.\n");
        SetConsoleTextAttribute(hConsole, 7);
        } else {
            break;
        }
    }

    FILE *file = fopen("user.dat", "ab+");
    if (file == NULL) {
        printf("the file not found");
    }
    fwrite(&u, sizeof(struct User), 1, file);
    printf("Account created successfully!\n");
    fclose(file);
}

void printData() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FILE *file = fopen("user.dat", "ab+");
    if (file == NULL) {
        printf("the file not found");
    }
    printf("Users Data:\n");
    rewind(file);
    while (fread(&u, sizeof(struct User), 1, file) == 1) {
            SetConsoleTextAttribute(hConsole, 14);
        printf("Username: %s\nEmail: %s\nPassword: %s\n\n", u.name, u.email, u.pass);
         SetConsoleTextAttribute(hConsole, 7);
    }
    fclose(file);
}

int hasbefor(const char *Usernamein) {
    FILE *file = fopen("user.dat", "ab+");
    if (file == NULL) {
        fclose(file);
        return 0;
    }
    rewind(file);

    struct User tempUser;

    while (fread(&tempUser, sizeof(struct User), 1, file) == 1) {
        if (strcmp(tempUser.name, Usernamein) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void singIN(){

while (1) {
        char choice [20];
        printf ("1.Enter to game\n2.forgat password\n3.return\n");
        gets (choice);

        if (strlen(choice)>2){
            printf("the input wan not correct\n");
            continue;
        }
        switch (choice[0]){
            case '1' :
            EnterGame();
            break;

            case'2':
            forgatp();
            break;

            case'3':
            system("cls");
            menuv();
            break;

            default :
            printf ("the input was not correct\n");
        }
    }
}

void forgatp(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf ("Enter username: ");
    char fusername[50];
    fgets(fusername,sizeof(fusername),stdin);
    fusername[strcspn(fusername, "\n")] = '\0';

    char femail[50];
    printf("Enter email: ");
    fgets(femail,sizeof(femail),stdin);
    femail[strcspn(femail,"\n")] = '\0';

    FILE*file = fopen("user.dat", "ab+");
    if (file == NULL) { printf("the file not found"); }

    rewind(file);

    while (fread(&u, sizeof(struct User), 1, file) == 1){
        if ( strcmp(u.name, fusername) == 0 && strcmp(u.email, femail) == 0 ){


            while(1){

            char newpasword[50];
              printf("Enter password (minimum 8 characters): ");
              fgets(newpasword, sizeof(newpasword), stdin);
              newpasword[strcspn(newpasword, "\n")] = '\0';

              char repeatedPassword[50];
              printf("Repeat password: ");
              fgets(repeatedPassword, sizeof(repeatedPassword), stdin);
              repeatedPassword[strcspn(repeatedPassword, "\n")] = '\0';

            if (strcmp(newpasword, repeatedPassword) != 0 || strlen(newpasword) < 8) {
            printf("Passwords do not match or are less than 8 characters. Please try again.\n");
              }

            else{
                  fclose(file);
                  FILE *file = fopen("user.dat", "ab+");
                  if (file == NULL) { printf("the file not found"); }

                  FILE *file2 = fopen("komak.dat", "wb+");
                  if (file2 == NULL) { printf("the file22 not found"); }

                  rewind(file);
                  rewind(file2);

                  while (fread(&u, sizeof(struct User), 1, file) == 1){

                      if ( strcmp(u.name, fusername) == 0  ){
                        strcpy(u.pass , newpasword);
                        fwrite(&u, sizeof(struct User), 1, file2);
                      }
                      else { fwrite(&u, sizeof(struct User), 1, file2); }

                  }

                  fclose(file);
                  fclose(file2);

                  remove( "user.dat" );
                  rename( "komak.dat" , "user.dat" );
                  SetConsoleTextAttribute(hConsole, 10);
                  printf("Your password changed successfuly\n");
                  SetConsoleTextAttribute(hConsole, 7);
                  singIN();
                  }

               }

            }
         }
         fclose(file);
         SetConsoleTextAttribute(hConsole, 12);
          printf("Error: your email or username has not found\n");
          SetConsoleTextAttribute(hConsole, 7);
           singIN();

      }


void EnterGame () {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

       printf("Enter username: ");
       char fusername[50];
    fgets(fusername, sizeof(fusername), stdin);
    fusername[strcspn(fusername, "\n")] = '\0';

    printf("Enter password: ");

    int i = 0;
    char femail[30];
    while (1) {
        char ch = getch();


        if (ch == '\r') {
            femail[i] = '\0';
            break;
        } else if (ch == 8 && i > 0) {
            i--;
            printf("\b \b");
        } else if (ch != 8) {
            femail[i] = ch;
            i++;
            printf("*");
        }
    }
    //printf("%s\n" , femail);

    FILE*file = fopen("user.dat", "ab+");
    if (file == NULL) { printf("the file not found"); }

    rewind(file);

    while (fread(&u, sizeof(struct User), 1, file) == 1){
        if ( strcmp(u.name, fusername) == 0 && strcmp(u.pass, femail) == 0 ){
                strcpy( History1 , "" );
                strcpy(p1 , u.name);
                strcpy ( History1 , u.Winers);
                win1 = u.win ;
                fail1 = u.fail ;
                total1 = u.total;
                printf("\nWelcome %s\n" , p1 );
                fclose(file);
                menup();
        }
    }
    fclose(file);
    SetConsoleTextAttribute(hConsole, 12);
    printf("\nError: your password or username is not correct\n");
    SetConsoleTextAttribute(hConsole, 7);
    singIN();
}

void menup(){


 while (1) {
        char choice[10];
        printf("1.Start\n2.Change information\n3.History\n4.Return\n");
        gets(choice);

        if (strlen(choice) > 1) {
            printf("the input was not correct try again\n");
            continue;
        }

        switch (choice[0]) {
            case '1':

                StartGame();
                break;
            case '2':
                system("cls");
                Changeinformaion();
                break;
            case '3':
                system("cls");
                Historyism();
                break;
            case '4':
                system("cls");
                menuv();
                break;
            default:
                printf("Invalid choice! Please enter a valid number.\n");
        }
    }

}

void StartGame(){
     printf("player number 2 please\n");
     printf ("Enter username: ");
    char fusername[50];
    fgets(fusername,sizeof(fusername),stdin);
    fusername[strcspn(fusername, "\n")] = '\0';

    int i = 0;
    char femail[50];
    printf("Enter password: ");
     while (1) {
        char ch = getch();


        if (ch == '\r') {
            femail[i] = '\0';
            break;
        } else if (ch == 8 && i > 0) {
            i--;
            printf("\b \b");
        } else if (ch != 8) {
            femail[i] = ch;
            i++;
            printf("*");
        }
    }

    FILE*file = fopen("user.dat", "ab+");
    if (file == NULL) { printf("the file not found"); }

    rewind(file);

    while (fread(&u, sizeof(struct User), 1, file) == 1){
        if ( strcmp(u.name, fusername) == 0 && strcmp(u.pass, femail) == 0 && strcmp(u.name, p1) != 0 ){
                strcpy( History2 , "");
                strcpy(p2 , u.name);
                strcpy(History2 , u.Winers);
                win2 = u.win ;
                fail2 = u.fail;
                total2 = u.total;
                printf("%s\n" , p2 );
                fclose(file);
                onthegame();
                //menup();
        }
    }
    fclose(file);
    printf("Error: your password or username for second player is not correct\n");
    menup();

}

void Changeinformaion(){

    while (1) {
        char choice[10];
        printf("Which one do you want to change?\n1.username\n2.email\n3.password\n4.Return\n");
        gets(choice);

        if (strlen(choice) > 1) {
            printf("the input was not correct try again\n");
            continue;
        }

        switch (choice[0]) {
            case '1':
                changename();
                break;
            case '2':
               changeemial();
                break;
            case '3':
               changepassword();
                break;
            case '4':
                system("cls");
                menup();
                break;
            default:
                printf("Invalid choice! Please enter a valid number.\n");
        }
    }


}




void changename(){
char fusername[50];
printf("Enter username: ");
    fgets(fusername, sizeof(fusername), stdin);
    fusername[strcspn(fusername, "\n")] = '\0';

    while (hasbefor(fusername)) {
        printf("Username already taken. Please enter a different username: ");
        fgets(fusername, sizeof(fusername), stdin);
       fusername[strcspn(fusername, "\n")] = '\0';
    }



                  FILE *file = fopen("user.dat", "ab+");
                  if (file == NULL) { printf("the file not found"); }

                  FILE *file2 = fopen("komak.dat", "wb+");
                  if (file2 == NULL) { printf("the file22 not found"); }

                  rewind(file);
                  rewind(file2);

                  while (fread(&u, sizeof(struct User), 1, file) == 1){

                      if ( strcmp(u.name, p1) == 0  ){
                        strcpy(u.name , fusername);
                        fwrite(&u, sizeof(struct User), 1, file2);
                      }
                      else { fwrite(&u, sizeof(struct User), 1, file2); }

                  }

                  fclose(file);
                  fclose(file2);

                  remove( "user.dat" );
                  rename( "komak.dat" , "user.dat" );
                  printf("your username changed successfuly!\n");
                  menup();

}

void changeemial(){

    char femail[50];
    printf("Enter email: ");
    fgets(femail,sizeof(femail),stdin);
    femail[strcspn(femail,"\n")] = '\0';

                  FILE *file = fopen("user.dat", "ab+");
                  if (file == NULL) { printf("the file not found"); }

                  FILE *file2 = fopen("komak.dat", "wb+");
                  if (file2 == NULL) { printf("the file22 not found"); }

                  rewind(file);
                  rewind(file2);

                  while (fread(&u, sizeof(struct User), 1, file) == 1){

                      if ( strcmp(u.name, p1) == 0  ){
                        strcpy(u.email , femail);
                        fwrite(&u, sizeof(struct User), 1, file2);
                      }
                      else { fwrite(&u, sizeof(struct User), 1, file2); }

                  }

                  fclose(file);
                  fclose(file2);

                  remove( "user.dat" );
                  rename( "komak.dat" , "user.dat" );
                  printf("your email changed successfuly!\n");
                  menup();




}

void  changepassword(){

    while(1){

            char newpasword[50];
              printf("Enter password (minimum 8 characters): ");
              fgets(newpasword, sizeof(newpasword), stdin);
              newpasword[strcspn(newpasword, "\n")] = '\0';

              char repeatedPassword[50];
              printf("Repeat password: ");
              fgets(repeatedPassword, sizeof(repeatedPassword), stdin);
              repeatedPassword[strcspn(repeatedPassword, "\n")] = '\0';

              if (strcmp(newpasword, repeatedPassword) != 0 || strlen(newpasword) < 8) {
            printf("Passwords do not match or are less than 8 characters. Please try again.\n");
              }

              else {
                FILE *file = fopen("user.dat", "ab+");
                  if (file == NULL) { printf("the file not found"); }

                  FILE *file2 = fopen("komak.dat", "wb+");
                  if (file2 == NULL) { printf("the file22 not found"); }

                  rewind(file);
                  rewind(file2);

                  while (fread(&u, sizeof(struct User), 1, file) == 1){

                      if ( strcmp(u.name, p1) == 0  ){
                        strcpy(u.pass , newpasword);
                        fwrite(&u, sizeof(struct User), 1, file2);
                      }
                      else { fwrite(&u, sizeof(struct User), 1, file2); }

                  }

                  fclose(file);
                  fclose(file2);

                  remove( "user.dat" );
                  rename( "komak.dat" , "user.dat" );
                  printf("your password changed successfuly!\n");
                  menup();

              }
    }

}


void Historyism() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

       printf("History:\n");

       if (strlen(History1) < 3) {  SetConsoleTextAttribute(hConsole, 12); printf("you don't have any play!\n");  SetConsoleTextAttribute(hConsole, 7);}
       else {  SetConsoleTextAttribute(hConsole, 14); printf("Wins : %d\nLoses : %d\nAll games : %d\n%s\n" ,win1 , fail1 , total1 ,History1) ;  SetConsoleTextAttribute(hConsole, 7);}

       menup();


}

void build1() {

    jan1 = 4 ;
    jan2 = 4 ;
    bomb1R = -1 ; bomb1C = -1;
 hbomb1R = -1 ; hbomb1C = -1 ;
 bombdarad1 = 0 ; bombdarad2 = 0 ;

 bomb2R = -1 ; bomb2C = -1;
 hbomb2R = -1 ; hbomb2C = -1 ;

    J1 = 'W' ;
    J2 = 'I';
    for (int i = 0; i < MAXLL; i++) {
        for (int j = 0; j < MAXCC; j++) {
            land[i][j] = ' ';
        }
    }

    for (int i = 0; i < MAXLL; i++) {
        for (int j = 0; j < MAXCC; j++) {
            land[0][j] = WALL;
            land[MAXLL - 1][j] = WALL;
        }
        land[i][0] = WALL;
        land[i][MAXCC - 1] = WALL;
    }

      x1Row = 15; x1Col = 9;
    x2Row = 15; x2Col = 65;
      land[15][35] = '|';
      land[14][35] = '#';
      land[13][35] = '#';
      land[12][35] = '#';
      land[11][35] = '#';
      land[10][35] = '#';
      land[9][35] = '#';

      h1 = 4; h2 = 35 ;
      jabe1R = 5 ; jabe1C = 33 ;

      land[16][35] = '#';
      land[17][35] = '#';
      land[18][35] = '#';
      land[19][35] = '#';
      land[20][35] = '#';
      land[21][35] = '#';

      land[11][40] = '#';
      land[11][41] = '#';
      land[11][42] = '#';
      land[11][43] = '#';
      land[11][44] = '#';
      land[11][45] = '#';
      land[11][46] = '#';

      land[19][30] = '#';
      land[19][29] = '#';
      land[19][28] = '#';
      land[19][27] = '#';
      land[19][26] = '#';
      land[19][25] = '#';
      land[19][24] = '#';



      land[15][12] = '#';
      land[14][12] = '#';
      land[13][12] = '#';
      land[12][12] = '#';
      land[11][12] = '#';
      land[10][12] = '#';
      land[9][12] = '#';
      land[8][12] = '#';
      land[7][12] = '#';

      land[11][13] = '|';
      land[10][13] = '|';
      land[9][13] = '|';

      land[7][11] = '#';
      land[7][10] = '#';
      land[7][9] = '#';
      land[7][8] = '#';

      land[16][12] = '#';
      land[17][12] = '#';
      land[18][12] = '#';
      land[19][12] = '#';
      land[20][12] = '#';
      land[21][12] = '#';
      land[22][12] = '#';
      land[23][12] = '#';

      land[19][13] = '|';
      land[20][13] = '|';
      land[21][13] = '|';

      land[23][11] = '#';
      land[23][10] = '#';
      land[23][9] = '#';
      land[23][8] = '#';






      land[15][62] = '#';
      land[14][62] = '#';
      land[13][62] = '#';
      land[12][62] = '#';
      land[11][62] = '#';
      land[10][62] = '#';
      land[9][62] = '#';
      land[8][62] = '#';
      land[7][62] = '#';

      land[11][61] = '|';
      land[10][61] = '|';
      land[9][61] = '|';



      land[7][63] = '#';
      land[7][64] = '#';
      land[7][65] = '#';
      land[7][66] = '#';


      land[16][62] = '#';
      land[17][62] = '#';
      land[18][62] = '#';
      land[19][62] = '#';
      land[20][62] = '#';
      land[21][62] = '#';
      land[22][62] = '#';
      land[23][62] = '#';

      land[19][61] = '|';
      land[20][61] = '|';
      land[21][61] = '|';

      land[23][63] = '#';
      land[23][64] = '#';
      land[23][65] = '#';
      land[23][66] = '#';

      land[25][18] = '#';
      land[26][18] = '#';
      land[27][18] = '#';

      por1R = 27 ; por1C = 5 ;
      por2R = 27 ; por2C = 67 ;

      land[25][55] = '#';
      land[26][55] = '#';
      land[27][55] = '#';
      land[25][54] = '|';
      land[26][54] = '|';
      land[27][54] = '|';

      chale1 = 22 ;
      chale2 = 19 ;
      chale3 = 3 ;
      chale4 = 64 ;


      land[3][55] = '#';
      land[4][55] = '#';
      land[5][55] = '#';

      land[3][18] = '#';
      land[4][18] = '#';
      land[5][18] = '#';
      land[3][19] = '|';
      land[4][19] = '|';
      land[5][19] = '|';

    nh1 = -1; nh2 = -1 ;

    n1 = -1 ; n2 = -1 ;
    n3 = -1 ; n4 = -1 ;
    bn1 = -1 ; bn2 = -1;
    rh1 = -1; rh2 = -1 ;
    Rooh1 = 0;
    Rooh2 = 0;
    ndarad1 = 0 ;
    ndarad2 = 0;
    ertdarad1 = 0 ;
    ertdarad2 = 0 ;

    counterRooh1 = 0;
    counterRooh2 = 0;


    ert1R = -1; ert1C = -1 ;
    ert2R = -1; ert2C = -1 ;


}


void build2() {

    J1 = 'W' ;
    J2 = 'I';
    bomb1R = -1 ; bomb1C = -1;
 hbomb1R = -1 ; hbomb1C = -1 ;
 bombdarad1 = 0 ; bombdarad2 = 0 ;

 bomb2R = -1 ; bomb2C = -1;
 hbomb2R = -1 ; hbomb2C = -1 ;

    jan1 = 4 ;
    jan2 = 4 ;
    for (int i = 0; i < MAXLL; i++) {
        for (int j = 0; j < MAXCC; j++) {
            land[i][j] = ' ';
        }
    }

    for (int i = 0; i < MAXLL; i++) {
        for (int j = 0; j < MAXCC; j++) {
            land[0][j] = WALL;
            land[MAXLL - 1][j] = WALL;
        }
        land[i][0] = WALL;
        land[i][MAXCC - 1] = WALL;
    }

    x1Row = 15; x1Col = 9;
    x2Row = 15; x2Col = 65;

    h1 = 15 ; h2 = 34 ;
    jabe1R = 15 ; jabe1C = 33 ;
    nh1 = 24; nh2 = 34 ;

    rh1 = 5; rh2 = 34 ;

    chale1 = 14 ; chale2 = 36 ;
    chale3 = 16 ; chale4 = 32 ;
    por1R = 26 ; por1C = 11 ;
    por2R = 26 ; por2C = 61 ;
    ert1R = 13; ert1C = 20 ;
    ert2R = 13; ert2C = 49 ;

    land[15][32] = '|';

    land[15][38] = '#';
    land[16][38] = '#';
    land[15][39] = '#';
    land[15][40] = '#';
    land[17][38] = '#';
    land[17][37] = '#';
    land[17][36] = '#';
    land[17][35] = '#';
    land[17][34] = '#';
    land[18][34] = '#';
    land[19][34] = '#';

    land[21][34] = '#';
    land[21][33] = '#';
    land[21][32] = '#';
    land[21][35] = '#';
    land[21][36] = '#';

    land[15][48] = '#';
    land[14][47] = '#';
    land[13][46] = '#';
    land[12][45] = '#';
    land[11][44] = '#';

    land[16][47] = '#';
    land[17][46] = '#';
    land[18][45] = '#';
    land[19][44] = '#';

    land[15][20] = '#';
    land[16][21] = '#';
    land[16][22] = '|';
    land[17][22] = '#';
    land[18][23] = '#';
    land[19][24] = '#';

    land[14][21] = '#';
    land[13][22] = '#';
    land[12][23] = '#';
    land[11][24] = '#';




    land[15][30] = '#';
    land[15][29] = '#';

    land[15][31] = '#';
    land[14][31] = '#';
    land[13][31] = '#';
    land[13][32] = '#';
    land[13][33] = '#';
    land[13][34] = '#';
    land[12][34] = '#';
    land[11][34] = '#';

    land[9][32] = '#';
    land[9][33] = '#';
    land[9][34] = '#';
    land[9][35] = '#';
    land[9][36] = '#';

    land[3][48] = '#';
    land[4][48] = '#';
    land[5][48] = '#';
    land[6][48] = '#';
    land[5][47] = '|';
    land[6][47] = '|';

    land[26][48] = '#';
    land[25][48] = '#';
    land[24][48] = '#';
    land[23][48] = '#';
    land[26][47] = '|';
    land[25][47] = '|';

    land[3][20] = '#';
    land[4][20] = '#';
    land[5][20] = '#';
    land[6][20] = '#';
    land[3][21] = '|';
    land[4][21] = '|';


    land[26][20] = '#';
    land[25][20] = '#';
    land[24][20] = '#';
    land[23][20] = '#';
    land[24][21] = '|';
    land[23][21] = '|';

    land[15][12] = '|';
    land[14][12] = '|';
    land[13][12] = '|';
    land[12][12] = '|';
    land[11][12] = '|';
    land[10][12] = '|';
    land[9][12] = '|';

    land[16][12] = '|';
    land[17][12] = '|';
    land[18][12] = '|';
    land[19][12] = '|';
    land[20][12] = '|';
    land[21][12] = '|';

    land[15][62] = '|';
    land[14][62] = '|';
    land[13][62] = '|';
    land[12][62] = '|';
    land[11][62] = '|';
    land[10][62] = '|';
    land[9][62] = '|';

    land[16][62] = '|';
    land[17][62] = '|';
    land[18][62] = '|';
    land[19][62] = '|';
    land[20][62] = '|';
    land[21][62] = '|';

    n1 = -1 ; n2 = -1 ;
    n3 = -1 ; n4 = -1 ;
    bn1 = -1 ; bn2 = -1;

    Rooh1 = 0;
    Rooh2 = 0;
    ndarad1 = 0 ;
    ndarad2 = 0;
    ertdarad1 = 0 ;
    ertdarad2 = 0 ;

    counterRooh1 = 0;
    counterRooh2 = 0;


}


void print() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < MAXLL; i++) {
        for (int j = 0; j < MAXCC; j++) {
            if (i == x1Row && j == x1Col) {
                gotoxy(j, i);
                SetConsoleTextAttribute(hConsole, 12);
                putchar(PLAYER1);
                SetConsoleTextAttribute(hConsole, 7);
            } else if (i == x2Row && j == x2Col) {
                gotoxy(j, i);
                SetConsoleTextAttribute(hConsole, 9);
                putchar(PLAYER2);
                SetConsoleTextAttribute(hConsole, 7);
            } else if ( i == xt1R && j == xt1C ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 12);
               putchar('*');
               SetConsoleTextAttribute(hConsole, 7);
            } else if ( i == xt2R && j == xt2C ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 9);
               putchar('*');
               SetConsoleTextAttribute(hConsole, 7);
            } else if ( i == ert1R && j == ert1C ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 14);
               putchar('U');
               SetConsoleTextAttribute(hConsole, 7);
            } else if ( i == ert2R && j == ert2C ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 14);
               putchar('U');
               SetConsoleTextAttribute(hConsole, 7);
            } else if ( i == h1 && j == h2 ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 12);
               putchar('+');
               SetConsoleTextAttribute(hConsole, 7);
            } else if ( i == por1R && j == por1C ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 11);
               putchar('@');
               SetConsoleTextAttribute(hConsole, 7);
            } else if ( i == por2R && j == por2C ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 11);
               putchar('@');
               SetConsoleTextAttribute(hConsole, 7);
            }
            else if ( i == nh1 && j == nh2 ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 12);
               putchar('&');
               SetConsoleTextAttribute(hConsole, 7);
            }
            else if ( i == n1 && j == n2 ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 12);
               putchar('&');
               SetConsoleTextAttribute(hConsole, 7);
            }
            else if ( i == n3 && j == n4 ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 9);
               putchar('&');
               SetConsoleTextAttribute(hConsole, 7);
            }
            else if ( i == rh1 && j == rh2 ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 15);
               putchar('S');
               SetConsoleTextAttribute(hConsole, 7);
            }
            else if ( i == chale1 && j == chale2 ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 13);
               putchar('0');
               SetConsoleTextAttribute(hConsole, 7);
            }
            else if ( i == chale3 && j == chale4 ){
               gotoxy(j , i );
               SetConsoleTextAttribute(hConsole, 13);
               putchar('0');
               SetConsoleTextAttribute(hConsole, 7);
            }
            else if (i == bomb1R && j == bomb1C) {
                gotoxy(j, i);
                SetConsoleTextAttribute(hConsole, 12);
                putchar('B');
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (i == bomb2R && j == bomb2C) {
                gotoxy(j, i);
                SetConsoleTextAttribute(hConsole, 9);
                putchar('B');
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (i == jabe1R && j == jabe1C) {
                gotoxy(j, i);
                SetConsoleTextAttribute(hConsole, 14);
                putchar('?');
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (i == hjabe1R && j == hjabe1C) {
                gotoxy(j, i);

                putchar(' ');

            }
            else if (i == hbomb2R && j == hbomb2C) {
                gotoxy(j, i);
                putchar(' ');
            }
            else if (i == hbomb1R && j == hbomb1C) {
                gotoxy(j, i);
                putchar(' ');
            }
            else if (i == hasfch1 && j == hasfch2) {
                gotoxy(j, i);
                putchar(' ');
            }
            else if (i == bxt2R && j == bxt2C) {
                gotoxy(j, i);
                putchar(' ');
            }

            else if ( i == hasft1 && j == hasft2 ){
               gotoxy(j , i );
               putchar(' ');
            }
            else if ( i == hasf1 && j == hasf2 ){
               gotoxy(j , i );
               putchar(' ');
            }
             else if ( i == hasf1r && j == hasf2r ){
               gotoxy(j , i );
               putchar(' ');
            }
            else if ( i == hasft3 && j == hasft4 ){
               gotoxy(j , i );
               putchar(' ');
            }
            else if (land[i][j] != ' ') {
                gotoxy(j, i);
                SetConsoleTextAttribute(hConsole, 14);
                putchar(land[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }

            else if ( i == bn1 && j == bn2 ){
               gotoxy(j , i );
               putchar(' ');
            }
            else if ( i == bxt1R && j == bxt1C ){
               gotoxy(j, i);
               putchar(' ');
            } else if (i == Bx1Row && j == Bx1Col) {
                gotoxy(j, i);
                putchar(' ');
            }
            else if (i == Bx2Row && j == Bx2Col) {
                gotoxy(j, i);
                putchar(' ');
            }

        }
    }

    SetConsoleTextAttribute(hConsole, 12);
    printf("\n%s : %d    Wins : %d  All games : %d\n", p1 , jan1 , win1 , total1 ) ;
    SetConsoleTextAttribute(hConsole, 7) ;
    SetConsoleTextAttribute(hConsole, 9);
    printf("\n%s : %d    Wins : %d  All games : %d\n", p2 , jan2 , win2 , total2 ) ;
    SetConsoleTextAttribute(hConsole, 7);



}

void  Move1 () {

         if ( x1Row == xt2R && x1Col == xt2C ){
            xt2R = -1;
            xt2C = -1;
            jan1--;
         }
       // Harkat Adi
        if ( Rooh1 == 0 ){
        if (GetAsyncKeyState('W') & 0x8001 && land[x1Row - 1][x1Col] == ' '   ) {
            //land[x1Row][x1Col] = ' ';
            Bx1Row = x1Row;
            Bx1Col = x1Col;
            J1 = 'W';
            x1Row--;
        } else if (GetAsyncKeyState('S') & 0x8001 && land[x1Row + 1][x1Col] == ' ' ) {
            //land[x1Row][x1Col] = ' ';
            Bx1Row = x1Row;
            Bx1Col = x1Col;
            J1 = 'S';
            x1Row++;
        } else if (GetAsyncKeyState('A') & 0x8001 && land[x1Row][x1Col - 1] == ' ' ) {
            //land[x1Row][x1Col] = ' ';
            Bx1Row = x1Row;
            Bx1Col = x1Col;
            J1 = 'A';
            x1Col--;
        } else if (GetAsyncKeyState('D') & 0x8001 && land[x1Row][x1Col + 1] == ' ' ) {
            //land[x1Row][x1Col] = ' ';
            Bx1Row = x1Row;
            Bx1Col = x1Col;
            J1 = 'D';
            x1Col++;
        }

        }

        // Harkat roohi
        if ( Rooh1 == 1 ){

        if (GetAsyncKeyState('W') & 0x8001 ) {
            //land[x1Row][x1Col] = ' ';
            Bx1Row = x1Row;
            Bx1Col = x1Col;
            J1 = 'W';
            x1Row--;
            counterRooh1--;
        } else if (GetAsyncKeyState('S') & 0x8001 ) {
            //land[x1Row][x1Col] = ' ';
            Bx1Row = x1Row;
            Bx1Col = x1Col;
            J1 = 'S';
            x1Row++;
            counterRooh1--;
        } else if (GetAsyncKeyState('A') & 0x8001 ) {
            //land[x1Row][x1Col] = ' ';
            Bx1Row = x1Row;
            Bx1Col = x1Col;
            J1 = 'A';
            x1Col--;
            counterRooh1--;
        } else if (GetAsyncKeyState('D') & 0x8001 ) {
            //land[x1Row][x1Col] = ' ';
            Bx1Row = x1Row;
            Bx1Col = x1Col;
            J1 = 'D';
            x1Col++;
            counterRooh1--;
        }


        }



        // check kardan inke daghel zamin basha
        if (x1Row < 0 || x1Col < 0 || x1Row >= MAXLL || x1Col >= MAXCC) {
            x1Row = Bx1Row;
            x1Col = Bx1Col;
        }
        // Check if players collide
        if (x1Row == x2Row && x1Col == x2Col) {
            x1Row = Bx1Row;
            x1Col = Bx1Col;
        }
        if ( x1Row == ert1R && x1Col == ert1C ){
            ertdarad1 = ertdarad1 + 5 ;
            ert1R = -1 ;
            ert1C = -1 ;
        }
        if ( x1Row == ert2R && x1Col == ert2C ){
            ertdarad1 = ertdarad1 + 5 ;
            ert2R = -1 ;
            ert2C = -1 ;
        }
        if ( x1Row == h1 && x1Col == h2 ){
            jan1 = jan1 + 5 ;
            h1 = -1 ;
            h2 = -1 ;
            randing();
        }
        if ( x1Row == por1R && x1Col == por1C ){
            x1Row = por2R +1 ;
            x1Col = por2C ;
        }
         if ( x1Row == por2R && x1Col == por2C ){
            x1Row = por1R  - 1;
            x1Col = por1C ;
        }
        if ( x1Row == nh1 && x1Col == nh2 ){
            nh1 = -1 ;
            nh2 = -1 ;
            ndarad1 = 1 ;
        }
        if ( x1Row == rh1 && x1Col == rh2 ){
            rh1 = -1 ;
            rh2 = -1 ;
            Rooh1 = 1 ;
            counterRooh1 = 90 ;
        }
        if (counterRooh1 <= 0 ) {
            Rooh1 = 0 ;
        }
        if ( x1Row == chale1 && x1Col == chale2 ) {
            hasfch1 = chale1 ;
            hasfch2 = chale2 ;
            chale1 = -1;
            chale2 = -1;
            x1Row = 15 ;
            x1Col = 9 ;
            jan1--;

        }
        if ( x1Row == chale3 && x1Col == chale4 ) {
            hasfch1 = chale3 ;
            hasfch2 = chale4 ;
            chale3 = -1;
            chale4 = -1;
            x1Row = 15 ;
            x1Col = 9 ;
            jan1--;

        }
        if ( x1Row == n3 && x1Col == n4 ){
            n3 = -1;
            n4 = -1;
            jan1--;
        }

        if (  GetAsyncKeyState('X') & 0x8001 && bombdarad1 == 0 && x1Col > 35  ){

            bomb1R = x1Row ;
            bomb1C = x1Col ;
            start_time1 = clock();
            bombdarad1 = 1 ;

        }

       if ( bombdarad2 == 1 ) {


            clock_t current_time = clock();

    double elapsed_time = ((double)(current_time - start_time2)) / CLOCKS_PER_SEC;
             if (elapsed_time > 10.0) {
                    hbomb2R = bomb2R ;
                    hbomb2C = bomb2C ;
                    bomb2R = -1 ;
                    bomb2C = - 1 ;
                    jan1 = jan1 - 2 ;
                    bombdarad2 = -1 ;
        }
        else if ( elapsed_time < 10.0 && x1Row == bomb2R && x1Col == bomb2C){
                    hbomb2R = bomb2R ;
                    hbomb2C = bomb2C ;
                    bomb2R = -1 ;
                    bomb2C = - 1 ;
                    bombdarad2 = -1 ;

        }

        }

        if ( x1Row == jabe1R && x1Col == jabe1C ){
            hjabe1R == jabe1R ;
            hjabe1C == jabe1C ;
            jabe1R = -1 ;
            jabe1C = - 1;
            srand(time(NULL));
            int i = rand() % 3 ;
            if ( i == 1 ) jan2--;
            else if ( i == 2 ) jan1++;
            else { jan2-- ; jan1++ ; }


        }


}

void Move2(){




        if (Rooh2 == 0){
          if (GetAsyncKeyState('I') & 0x8001 && land[x2Row - 1][x2Col] == ' ') {
            //land[x2Row][x2Col] = ' ';
            Bx2Row = x2Row;
            Bx2Col = x2Col;
            J2 = 'I';
            x2Row--;
        } else if (GetAsyncKeyState('K') & 0x8001 && land[x2Row + 1][x2Col] == ' ') {
            //land[x2Row][x2Col] = ' ';
            Bx2Row = x2Row;
            Bx2Col = x2Col;
            J2 = 'K';
            x2Row++;
        } else if (GetAsyncKeyState('J') & 0x8001 && land[x2Row][x2Col - 1] == ' ') {
            //land[x2Row][x2Col] = ' ';
            Bx2Row = x2Row;
            Bx2Col = x2Col;
            J2 = 'J';
            x2Col--;
        } else if (GetAsyncKeyState('L') & 0x8001 && land[x2Row][x2Col + 1] == ' ') {
            //land[x2Row][x2Col] = ' ';
            Bx2Row = x2Row;
            Bx2Col = x2Col;
            J2 = 'L';
            x2Col++;
        }
        }


        if ( Rooh2 == 1 ) {
            if (GetAsyncKeyState('I') & 0x8001 ) {
            //land[x2Row][x2Col] = ' ';
            Bx2Row = x2Row;
            Bx2Col = x2Col;
            J2 = 'I';
            x2Row--;
            counterRooh2--;
        } else if (GetAsyncKeyState('K') & 0x8001 ) {
            //land[x2Row][x2Col] = ' ';
            Bx2Row = x2Row;
            Bx2Col = x2Col;
            J2 = 'K';
            x2Row++;
            counterRooh2--;
        } else if (GetAsyncKeyState('J') & 0x8001 ) {
            //land[x2Row][x2Col] = ' ';
            Bx2Row = x2Row;
            Bx2Col = x2Col;
            J2 = 'J';
            x2Col--;
            counterRooh2--;
        } else if (GetAsyncKeyState('L') & 0x8001 ) {
            //land[x2Row][x2Col] = ' ';
            Bx2Row = x2Row;
            Bx2Col = x2Col;
            J2 = 'L';
            x2Col++;
            counterRooh2--;
        }

        }


        // Check if players collide
        if (x1Row == x2Row && x1Col == x2Col) {
            x2Row = Bx2Row;
            x2Col = Bx2Col;
        }
        if ( x2Row == rh1 && x2Col == rh2 ){
            rh1 = -1 ;
            rh2 = -1 ;
            Rooh2 = 1 ;
            counterRooh2 = 90 ;
        }
        if (counterRooh2 <= 0 ) {
            Rooh2 = 0 ;
        }
        if (x2Row < 0 || x2Col < 0 || x2Row >= MAXLL || x2Col >= MAXCC) {
            x2Row = Bx2Row;
            x2Col = Bx2Col;
        }
        if ( x2Row == h1 && x2Col == h2 ){
            jan2 = jan2 + 5 ;
            h1 = -1 ;
            h2 = -1 ;
            randing();
        }
        if ( x2Row == por1R && x2Col == por1C ){
            x2Row = por2R +1 ;
            x2Col = por2C ;
        }
        if ( x2Row == por2R && x2Col == por2C ){
            x2Row = por1R  - 1;
            x2Col = por1C ;
        }

        if ( x2Row == nh1 && x2Col == nh2 ){
            nh1 = -1 ;
            nh2 = -1 ;
            ndarad2 = 1 ;
        }
        if ( x2Row == ert1R && x2Col == ert1C ){
            ertdarad2 = ertdarad2 + 5 ;
            ert1R = -1 ;
            ert1C = -1 ;
        }
        if ( x2Row == ert2R && x2Col == ert2C ){
            ertdarad2 = ertdarad2 + 5 ;
            ert2R = -1 ;
            ert2C = -1 ;
        }
         if ( x2Row == chale1 && x2Col == chale2 ) {
            hasfch1 = chale1 ;
            hasfch2 = chale2 ;
            chale1 = -1;
            chale2 = -1;
            x2Row = 15 ;
            x2Col = 65 ;
            jan2--;

        }
        if ( x2Row == chale3 && x2Col == chale4 ) {
            hasfch1 = chale3 ;
            hasfch2 = chale4 ;
            chale3 = -1;
            chale4 = -1;
            x2Row = 15 ;
            x2Col = 65 ;
            jan2--;

        }
        if ( x2Row == n1 && x2Col == n2 ){
            n1 = -1;
            n2 = -1;
            jan2--;
        }
        /*
        if ( n3 == xt1R && n4 == xt1C ){
         hasft1 = n1 ;
        hasft2 = n2 ;

        n1 = -1 ;
        n2 = -1 ;
        xt2R = -1;
        xt2C = -1;
        }
*/

if (  GetAsyncKeyState('M') & 0x8001 && bombdarad2 == 0 && x2Col < 35  ){

            bomb2R = x2Row ;
            bomb2C = x2Col ;
            start_time2 = clock();
            bombdarad2 = 1 ;

        }


if ( bombdarad1 == 1 ) {


            clock_t current_time = clock();

    double elapsed_time = ((double)(current_time - start_time1)) / CLOCKS_PER_SEC;
             if (elapsed_time > 10.0) {
                    hbomb1R = bomb1R ;
                    hbomb1C = bomb1C ;
                    bomb1R = -1 ;
                    bomb1C = - 1 ;
                    jan2 = jan2 - 2 ;
                    bombdarad1 = -1 ;
        }
        else if ( elapsed_time < 10.0 && x2Row == bomb1R && x2Col == bomb1C){
                    hbomb1R = bomb1R ;
                    hbomb1C = bomb1C ;
                    bomb1R = -1 ;
                    bomb1C = - 1 ;
                    bombdarad1 = -1 ;

        }

        }

        if ( x2Row == jabe1R && x2Col == jabe1C ){
            hjabe1R == jabe1R ;
            hjabe1C == jabe1C ;
            jabe1R = -1 ;
            jabe1C = - 1;
            srand(time(NULL));
            int i = rand() % 3 ;
            if ( i == 1 ) jan1--;
            else if ( i == 2 ) jan2++;
            else { jan1-- ; jan2++ ; }


        }

}



void Tir1 (){

    if (GetAsyncKeyState('C') & 0x8001 && xt1R == -1 && n1 == -1 ){

        if (ndarad1 == 0){
        xt1R = x1Row ;
        xt1C = x1Col ;
        JT1 = J1 ;
        if (ertdarad1 > 0) ertdarad1--;
        }
        else if (ndarad1 == 1){
            n1 = x1Row ;
            n2 = x1Col ;
            JN = J1 ;
            ndarad1 = 0 ;
        }

    } //end of if

     if ( n1 != -1 ){

  if ( JN == 'W'){
            bn1 = n1 ;
            bn2 = n2 ;
            n1--;
            }
        else if ( JN == 'S'){
            bn1 = n1 ;
            bn2 = n2 ;
            n1++;
            }
        else if (JN == 'A')  {
            bn1 = n1 ;
            bn2 = n2 ;
            n2--;
            }
        else if (JN == 'D')  {
            bn1 = n1 ;
            bn2 = n2 ;
            n2++;
        }

   }

    if (  xt1R != -1){  // peida kardan jahat tir1

        if ( JT1 == 'W'){
            bxt1R = xt1R ;
            bxt1C = xt1C ;
            xt1R--;
            }
        else if ( JT1 == 'S'){
            bxt1R = xt1R ;
            bxt1C = xt1C ;
            xt1R++;
            }
        else if (JT1 == 'A')  {
            bxt1R = xt1R ;
            bxt1C = xt1C ;
            xt1C--;
            }
        else if (JT1 == 'D')  {
            bxt1R = xt1R ;
            bxt1C = xt1C ;
            xt1C++;
        }
    }
    // for narangak1
    if (land[n1][n2] == '|') {
            land[n1][n2] = ' ';
     hasf1 = n1 ;
     hasf2 = n2 ;
    /*
     if ( (hasf1 + 1 == x1Row && hasf2 == x1Row) || (hasf1 - 1 == x1Row && hasf2 == x1Row) || (hasf1  == x1Row && hasf2 +1 == x1Row) || (hasf1  == x1Row && hasf2 -1 == x1Row) || (hasf1  == x1Row && hasf2 == x1Row)
         || (hasf1 - 1 == x1Row && hasf2 -1 == x1Row) || (hasf1 + 1 == x1Row && hasf2 + 1 == x1Row) ) jan1--;
     if ( (hasf1 + 1 == x2Row && hasf2 == x2Row) || (hasf1 - 1 == x2Row && hasf2 == x2Row) || (hasf1  == x2Row && hasf2 +1 == x2Row) || (hasf1  == x1Row && hasf2 -1 == x1Row) || (hasf1  == x1Row && hasf2 == x1Row)
         || (hasf1 - 1 == x2Row && hasf2 -1 == x2Row) || (hasf1 + 1 == x2Row && hasf2 + 1 == x2Row) ) jan1--;
     */
     for (int i = 0 ; i < 3 ; i++ ){
        for (int j = 0 ; j < 3 ; j++ ){
            int xx = n1 - 1 + i ;
            int yy = n2 - 1  + j ;
            if (  xx == x1Row && yy == x1Col ) { jan1--; }
            if ( xx == x2Row && yy == x2Col ){ jan2--; }
        }
     }
         n1 = -1;
     n2 = -1;
       }

    else if ( land[n1][n2] == '#' ){
        // n1 = -1 ;
        // n2 = -1 ;

         for ( int i = 0 ; i <= 24 ; i++ ) {
            for ( int j = 0 ; j <= 24 ; j++ ) {
                    int xx = n1 - 12 + i ;
                    int yy = n2 - 12 + j ;
                if ( xx == x2Row && yy == x2Col) jan2--;
            }
         }
         n1 = -1 ;
         n2 = -1 ;
    }
    else if ( n1 == xt2R && n2 == xt2C ){
            hasf1 = xt2R ;
            hasf2 = xt2C ;
        n1 = -1 ;
        n2 = -1 ;
        xt2R = -1;
        xt2C = -1;

    }
    else if ( n1 == x2Row && n2 == x2Col ){
        n1 = -1 ;
        n2 = -1 ;
        jan2--;

    }





    // barghord for tir1
    if ( land[xt1R][xt1C] == '#' && Rooh1 == 0){
         xt1R = -1 ;
         xt1C = -1 ;
    }
    else if ( xt1R == x2Row && xt1C == x2Col ){
        if ( ertdarad1 > 0 ){
        xt1R = -1 ;
        xt1C = -1 ;
        jan2 = jan2 - 2;
            }
       else {
        xt1R = -1 ;
        xt1C = -1 ;
        jan2--;
       }
    }
    else if ( xt1R == x1Row && xt1C == x1Col ){
        xt1R = -1 ;
        xt1C = -1 ;
        jan1--;
    }
    else if (land[xt1R][xt1C] == '|' && Rooh1 == 0 ){
             if ( JT1 == 'W'){
             JT1 = 'S';
            }
        else if ( JT1 == 'S'){
            JT1 = 'W';
            }
        else if (JT1 == 'A')  {
            JT1 = 'D';
            }
        else if (JT1 == 'D')  {
           JT1 = 'A';
        }


    }
    else if ( xt1R == xt2R && xt1C == xt2C){
        hasft1 = xt1R ;
        hasft2 = xt1C ;
        xt1R = -1 ;
        xt1C = -1;
        xt2R = -1;
        xt2C = -1 ;
    }


    // barresi in ke tir dar zaman rooh1 biron nabashad ?
    if ( xt1R < 0 || xt1R > MAXLL || xt1C < 0 || xt1C > MAXCC ){
        xt1R = -1 ;
        xt1C = -1 ;

    }
     if ( n3 == xt1R && n4 == xt1C ){
            hasf1 = n3;
            hasf2 = n4;
        n3 = -1 ;
        n4 = -1 ;
        xt1R = -1;
        xt1C = -1;

    }


}


void Tir2() {

     if (GetAsyncKeyState('N') & 0x8001 && xt2R == -1 && n3 == -1 ){

        if (ndarad2 == 0){
        xt2R = x2Row ;
        xt2C = x2Col ;
        JT2 = J2 ;
        if (ertdarad2 > 0) ertdarad2--;
        }
        else if (ndarad2 == 1){
            n3 = x2Row ;
            n4 = x2Col ;
            JN = J2 ;
            ndarad2 = 0 ;
        }

    }

     if ( n3 != -1 ){

  if ( JN == 'I'){
            bn1 = n3 ;
            bn2 = n4 ;
            n3--;
            }
        else if ( JN == 'K'){
            bn1 = n3 ;
            bn2 = n4 ;
            n3++;
            }
        else if (JN == 'J')  {
            bn1 = n3 ;
            bn2 = n4 ;
            n4--;
            }
        else if (JN == 'L')  {
            bn1 = n3 ;
            bn2 = n4 ;
            n4++;
        }

   }

   if (  xt2R != -1){  // peida kardan jahat tir1

        if ( JT2 == 'I'){
            bxt2R = xt2R ;
            bxt2C = xt2C ;
            xt2R--;
            }
        else if ( JT2 == 'K'){
            bxt2R = xt2R ;
            bxt2C = xt2C ;
            xt2R++;
            }
        else if (JT2 == 'J')  {
            bxt2R = xt2R ;
            bxt2C = xt2C ;
            xt2C--;
            }
        else if (JT2 == 'L')  {
            bxt2R = xt2R ;
            bxt2C = xt2C ;
            xt2C++;
        }
    }


         if (land[n3][n4] == '|') {
            land[n3][n4] = ' ';
     hasf1r = n3 ;
     hasf2r = n4 ;
    /*
     if ( (hasf1 + 1 == x1Row && hasf2 == x1Row) || (hasf1 - 1 == x1Row && hasf2 == x1Row) || (hasf1  == x1Row && hasf2 +1 == x1Row) || (hasf1  == x1Row && hasf2 -1 == x1Row) || (hasf1  == x1Row && hasf2 == x1Row)
         || (hasf1 - 1 == x1Row && hasf2 -1 == x1Row) || (hasf1 + 1 == x1Row && hasf2 + 1 == x1Row) ) jan1--;
     if ( (hasf1 + 1 == x2Row && hasf2 == x2Row) || (hasf1 - 1 == x2Row && hasf2 == x2Row) || (hasf1  == x2Row && hasf2 +1 == x2Row) || (hasf1  == x1Row && hasf2 -1 == x1Row) || (hasf1  == x1Row && hasf2 == x1Row)
         || (hasf1 - 1 == x2Row && hasf2 -1 == x2Row) || (hasf1 + 1 == x2Row && hasf2 + 1 == x2Row) ) jan1--;
     */
     for (int i = 0 ; i < 3 ; i++ ){
        for (int j = 0 ; j < 3 ; j++ ){
            int xx = n3 - 1 + i ;
            int yy = n4 - 1  + j ;
            if (  xx == x1Row && yy == x1Col ) { jan1--; }
            if ( xx == x2Row && yy == x2Col ){ jan2--; }
        }
     }
         n3 = -1;
     n4 = -1;
       }

       else if ( n3 == xt1R && n4 == xt1C ){
            hasf1 = n3;
            hasf2 = n4;
        n3 = -1 ;
        n4 = -1 ;
        xt1R = -1;
        xt1C = -1;

    }
    else if ( n3 == x1Row && n4 == x1Col ){
        n3 = -1 ;
        n4 = -1 ;
        jan1--;

    }
     else if ( land[n3][n4] == '#' ){
        // n1 = -1 ;
        // n2 = -1 ;

         for ( int i = 0 ; i <= 24 ; i++ ) {
            for ( int j = 0 ; j <= 24 ; j++ ) {
                    int xx = n3 - 12 + i ;
                    int yy = n4 - 12 + j ;
                if ( xx == x1Row && yy == x1Col) jan1--;
            }
         }
         n3 = -1 ;
         n4 = -1 ;
    }


     // barghord for tir1
    if ( land[xt2R][xt2C] == '#' && Rooh2 == 0){
         xt2R = -1 ;
         xt2C = -1 ;
    }
    else if ( xt2R == x1Row && xt2C == x1Col ){
        if ( ertdarad2 > 0 ){
        xt2R = -1 ;
        xt2C = -1 ;
        jan1 = jan1 - 2;
            }
       else {
        xt2R = -1 ;
        xt2C = -1 ;
        jan1--;
       }
    }
    else if ( xt2R == x2Row && xt2C == x2Col ){
        xt2R = -1 ;
        xt2C = -1 ;
        jan2--;
    }
    else if (land[xt2R][xt2C] == '|' && Rooh2 == 0 ){
             if ( JT2 == 'I'){
             JT2 = 'K';
            }
        else if ( JT2 == 'K'){
            JT2 = 'I';
            }
        else if (JT2 == 'J')  {
            JT2 = 'L';
            }
        else if (JT2 == 'L')  {
           JT2 = 'J';
        }


    }

        else if ( xt1R == xt2R && xt1C == xt2C){
        hasft3 = xt2R ;
        hasft4 = xt2C ;
        xt1R = -1 ;
        xt1C = -1;
        xt2R = -1;
        xt2C = -1 ;
    }

    else if ( n1 == xt2R && n2 == xt2C ){
        hasft1 = n1 ;
        hasft2 = n2 ;

        n1 = -1 ;
        n2 = -1 ;
        xt2R = -1;
        xt2C = -1;

    }

    // barresi in ke tir dar zaman rooh1 biron nabashad ?
    if ( xt2R < 0 || xt2R > MAXLL || xt2C < 0 || xt2C > MAXCC ){
        xt2R = -1 ;
        xt2C = -1 ;

    }
    /*
     if ( n3 == xt1R && n4 == xt1C ){
         hasft1 = n1 ;
        hasft2 = n2 ;

        n1 = -1 ;
        n2 = -1 ;
        xt2R = -1;
        xt2C = -1;

     }
     */
     if ( n1 == xt2R && n2 == xt2C ){
            hasf1 = xt2R ;
            hasf2 = xt2C ;
        n1 = -1 ;
        n2 = -1 ;
        xt2R = -1;
        xt2C = -1;

    }


}


void onthegame (){

    system("cls");
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    emtias1 = 0 ;
    emtias2 = 0 ;

build1();


   while (1) {

     Move1();
     Move2();
     Tir1();
     Tir2();
     print();
     Sleep(1);
     if ( jan2 <= 0 || jan1 <= 0) {
       break;
     }
   }

   system("cls");

   char giveEnter[60000];
   //fgets(giveEnter , sizeof(giveEnter) , stdin);
   gets(giveEnter);

   system("cls");

   if ( jan1 <= 0 ){
        emtias2 = emtias2 + 10 ;
        SetConsoleTextAttribute(hConsole, 14);
    printf("\n\n\n%s WIN IN THIS ROUND", p2 );
   SetConsoleTextAttribute(hConsole, 7);
   }
   else if ( jan2 <= 0 ) {
         emtias1 = emtias1 + 10 ;
    SetConsoleTextAttribute(hConsole, 14);
    printf("\n\n\n%s WIN IN THIS ROUND", p1 );
   SetConsoleTextAttribute(hConsole, 7);
   }
    getch();
   system("cls");

   build2();

   while (1) {

     Move1();
     Move2();
     Tir1();
     Tir2();
     print();
     Sleep(1);
     if ( jan2 <= 0 || jan1 <= 0 ) {
       break;
     }
   }

   system("cls");

   gets(giveEnter);

   if ( jan1 <= 0 ){
        emtias2 = emtias2 + 10 ;
        SetConsoleTextAttribute(hConsole, 14);
    printf("\n\n\n%s WIN IN THIS ROUND", p2 );
   SetConsoleTextAttribute(hConsole, 7);
   }
   else if ( jan2 <= 0 ) {
         emtias1 = emtias1 + 10 ;
    SetConsoleTextAttribute(hConsole, 14);
    printf("\n\n\n%s WIN IN THIS ROUND", p1 );
   SetConsoleTextAttribute(hConsole, 7);
   }
   getch();
   system("cls");


   build3();

   while (1) {

     Move1();
     Move2();
     Tir1();
     Tir2();
     print();
     Sleep(1);
     if ( jan2 <= 0 || jan1 <= 0 ) {
       break;
     }
   }

   system("cls");
   gets(giveEnter);
   system("cls");
   if ( jan1 <= 0 ){
        emtias2 = emtias2 + 10 ;
        SetConsoleTextAttribute(hConsole, 14);
    printf("\n\n\n%s WIN IN THIS ROUND", p2 );
   SetConsoleTextAttribute(hConsole, 7);
   }
   else if ( jan2 <= 0 ) {
       emtias1 = emtias1 + 10 ;
    SetConsoleTextAttribute(hConsole, 14);
    printf("\n\n\n%s WIN IN THIS ROUND", p1 );
   SetConsoleTextAttribute(hConsole, 7);
   }
   getch();
   system("cls");
   sabt();
   getch();
   menup();
}

void sabt (){
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   char winner[50];
  if ( emtias1 > emtias2 ){
    strcpy( winner , p1 );
    win1++;
    total1++;
    fail2++;
    total2++;
    SetConsoleTextAttribute(hConsole, 14);
    printf("\n\n\n%s WIN IN THE MATCH", winner );
    SetConsoleTextAttribute(hConsole, 7);
  }
  else if ( emtias1 < emtias2 ){
    strcpy( winner , p2 );
    win2++;
    total2++;
    fail1++;
    total1++;
        SetConsoleTextAttribute(hConsole, 14);
    printf("\n\n\n%s WIN IN THE MATCH", winner );
    SetConsoleTextAttribute(hConsole, 7);
  }

    strcat( History1 , p1 );
    strcat( History1 , " VS ");
    strcat( History1 , p2 ) ;
    strcat( History1 , " : ");
    strcat( History1 , winner ) ;
    strcat( History1 , "\n" ) ;


    strcat( History2 , p2 );
    strcat( History2, " VS ");
    strcat( History2 , p1 ) ;
    strcat( History2 , " : ");
    strcat( History2 , winner ) ;
    strcat( History2 , "\n" ) ;

    FILE *file = fopen("user.dat", "ab+");
                  if (file == NULL) { printf("the file not found"); }

                  FILE *file2 = fopen("komak.dat", "wb+");
                  if (file2 == NULL) { printf("the file22 not found"); }

                  rewind(file);
                  rewind(file2);

                  while (fread(&u, sizeof(struct User), 1, file) == 1){

                    if ( strcmp(u.name, p1) == 0  ){
                       u.win = win1 ;
                       u.fail = fail1 ;
                       u.total = total1 ;
                       strcpy( u.Winers , History1);
                       fwrite(&u, sizeof(struct User), 1, file2);
                  }
                  else if ( strcmp(u.name, p2) == 0 ) {
                    u.win = win2;
                    u.fail = fail2 ;
                    u.total = total2 ;
                    strcpy( u.Winers , History2 );
                    fwrite(&u, sizeof(struct User), 1, file2);
                  }
                  else {  fwrite(&u, sizeof(struct User), 1, file2);  }

                  }

                  fclose(file);
                  fclose(file2);

                  remove( "user.dat" );
                  rename( "komak.dat" , "user.dat" );


}


void build3() {

    jan1 = 4 ;
    jan2 = 4 ;

    bomb1R = -1 ; bomb1C = -1;
 hbomb1R = -1 ; hbomb1C = -1 ;
 bombdarad1 = 0 ; bombdarad2 = 0 ;

 bomb2R = -1 ; bomb2C = -1;
 hbomb2R = -1 ; hbomb2C = -1 ;

    for (int i = 0; i < MAXLL; i++) {
        for (int j = 0; j < MAXCC; j++) {
            land[i][j] = ' ';
        }
    }

    for (int i = 0; i < MAXLL; i++) {
        for (int j = 0; j < MAXCC; j++) {
            land[0][j] = WALL;
            land[MAXLL - 1][j] = WALL;
        }
        land[i][0] = WALL;
        land[i][MAXCC - 1] = WALL;
    }

      x1Row = 15; x1Col = 9;
    x2Row = 15; x2Col = 65;

     h1 = 5 ; h2 = 36 ;
     jabe1R = 5 ; jabe1C = 34 ;
      land[10][20] = '#';
      land[10][21] = '#';
      land[10][22] = '#';
      land[10][23] = '#';
      land[10][24] = '#';
      land[10][25] = '#';
      land[10][26] = '#';
      land[10][27] = '#';
      land[10][28] = '#';
      land[10][29] = '#';
      land[10][30] = '#';
      land[10][31] = '#';
      land[10][32] = '#';

      land[10][40] = '#';
      land[10][41] = '#';
      land[10][42] = '#';
      land[10][43] = '#';
      land[10][44] = '#';
      land[10][45] = '#';
      land[10][46] = '#';
      land[10][47] = '#';
      land[10][48] = '#';
      land[10][49] = '#';
      land[10][50] = '#';
      land[10][51] = '#';
      land[10][52] = '#';

      land[20][20] = '#';
      land[20][21] = '#';
      land[20][22] = '#';
      land[20][23] = '#';
      land[20][24] = '#';
      land[20][25] = '#';
      land[20][26] = '#';
      land[20][27] = '#';
      land[20][28] = '#';
      land[20][29] = '#';
      land[20][30] = '#';
      land[20][31] = '#';
      land[20][32] = '#';

      land[20][40] = '#';
      land[20][41] = '#';
      land[20][42] = '#';
      land[20][43] = '#';
      land[20][44] = '#';
      land[20][45] = '#';
      land[20][46] = '#';
      land[20][47] = '#';
      land[20][48] = '#';
      land[20][49] = '#';
      land[20][50] = '#';
      land[20][51] = '#';
      land[20][52] = '#';

      land[15][36] = '|';
      land[14][36] = '|';
      land[13][36] = '|';
      land[16][36] = '|';
      land[17][36] = '|';




      land[15][12] = '#';
      land[14][12] = '#';
      land[13][12] = '#';
      land[12][12] = '#';
      land[11][12] = '#';
      land[10][12] = '#';
      land[9][12] = '#';
      land[8][12] = '#';
      land[7][12] = '#';

      land[11][13] = '|';
      land[10][13] = '|';
      land[9][13] = '|';

      land[7][11] = '#';
      land[7][10] = '#';
      land[7][9] = '#';
      land[7][8] = '#';

      land[16][12] = '#';
      land[17][12] = '#';
      land[18][12] = '#';
      land[19][12] = '#';
      land[20][12] = '#';
      land[21][12] = '#';
      land[22][12] = '#';
      land[23][12] = '#';

      land[19][13] = '|';
      land[20][13] = '|';
      land[21][13] = '|';

      land[23][11] = '#';
      land[23][10] = '#';
      land[23][9] = '#';
      land[23][8] = '#';






      land[15][62] = '#';
      land[14][62] = '#';
      land[13][62] = '#';
      land[12][62] = '#';
      land[11][62] = '#';
      land[10][62] = '#';
      land[9][62] = '#';
      land[8][62] = '#';
      land[7][62] = '#';

      land[11][61] = '|';
      land[10][61] = '|';
      land[9][61] = '|';



      land[7][63] = '#';
      land[7][64] = '#';
      land[7][65] = '#';
      land[7][66] = '#';


      land[16][62] = '#';
      land[17][62] = '#';
      land[18][62] = '#';
      land[19][62] = '#';
      land[20][62] = '#';
      land[21][62] = '#';
      land[22][62] = '#';
      land[23][62] = '#';

      land[19][61] = '|';
      land[20][61] = '|';
      land[21][61] = '|';

      land[23][63] = '#';
      land[23][64] = '#';
      land[23][65] = '#';
      land[23][66] = '#';

      land[25][18] = '#';
      land[26][18] = '#';
      land[27][18] = '#';

      por1R = 27 ; por1C = 5 ;
      por2R = 27 ; por2C = 67 ;

      land[25][55] = '#';
      land[26][55] = '#';
      land[27][55] = '#';
      land[25][54] = '|';
      land[26][54] = '|';
      land[27][54] = '|';

      chale1 = 22 ;
      chale2 = 19 ;
      chale3 = 3 ;
      chale4 = 64 ;


      land[3][55] = '#';
      land[4][55] = '#';
      land[5][55] = '#';

      land[3][18] = '#';
      land[4][18] = '#';
      land[5][18] = '#';
      land[3][19] = '|';
      land[4][19] = '|';
      land[5][19] = '|';

    nh1 = -1; nh2 = -1 ;

    n1 = -1 ; n2 = -1 ;
    n3 = -1 ; n4 = -1 ;
    bn1 = -1 ; bn2 = -1;
    rh1 = -1; rh2 = -1 ;
    Rooh1 = 0;
    Rooh2 = 0;
    ndarad1 = 0 ;
    ndarad2 = 0;
    ertdarad1 = 0 ;
    ertdarad2 = 0 ;

    counterRooh1 = 0;
    counterRooh2 = 0;


    ert1R = -1; ert1C = -1 ;
    ert2R = -1; ert2C = -1 ;


}

void randing(){

    srand(time(NULL));
    while(1){
        int xx = rand() % 30 ;
        int yy = rand() % 75 ;
        if ( land[xx][yy] != '#' && land[xx][yy] != '|' && xx != x1Row && yy != x1Col && xx != x2Row && yy != x2Col && xx != xt1R && yy != xt1C && xx != xt2R
            && yy != xt2C && xx != nh1 && yy != nh2 && xx != n1 && yy != n2 && xx != n3 && yy != n4 && xx != chale1 && yy != chale2 && xx != chale3 && yy != chale4 && xx != rh1 && yy != rh2 && xx != por1R && yy != por1C
            && xx != por2R && yy != por2C ){
                h1 = xx ;
                h2 = yy ;
                break;
            }

    }
}
















#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char arr[26][26];

char* encptFunc(char plaintext[], char key[]);
char* decptFunc(char encpt[], char key[]);
int findRow(char col);
int findColumn(char col);
int findDecRow(char col,int j);

int main(){
    int choose = 0;
    char key[100], plaintext[100], encpt[100], decpt[100];

    do{
        printf("\n\nVernam Cipher\n");
        printf("====================\n");
        printf("[0] Exit\n");
        printf("[1] Encrypt\n");
        printf("[2] Decrypt\n");
        printf("====================\n");

        printf("Enter Operation: ");
        scanf("%d", &choose);

        
        switch(choose){
            case 1:
                printf("Enter Plain Text: \n");
                fflush(stdin);
                gets(plaintext);
                printf("Enter Key:  \n");
                fflush(stdin);
                gets(key);
                strcpy(encpt, encptFunc(plaintext, key));
                break;
            case 2:
                strcpy(decpt, decptFunc(encpt, key));
                break;
        }
    }while(choose);

    return 0;
}


char* decptFunc(char encpt[], char key[]){
    int i, j, k , row, col;
    char *decrypted = calloc(sizeof(encpt), sizeof(char));

    for(i = 0; key[i] != NULL; i++){
        col = findColumn(key[i]);
        row = findDecRow(encpt[i], col);
        decrypted[i] = arr[row][0];
    }
    decrypted[i]='\0';

    printf("\nDecrypted:\n");
    for(i = 0; decrypted[i] != NULL; i++){
        printf("%c", decrypted[i]);
    } 
    getch();
    system("cls");
    return decrypted;
}

char* encptFunc(char plaintext[], char key[]){
    int i, j, k , row, col;
    char *encrypted = calloc(sizeof(plaintext), sizeof(char));

     k=96;
    for(i = 0; i < 26; i++){
        k++;
        for(j = 0; j < 26; j++){
            arr[i][j]=k++;
            if(k==123)
                k=97;
        }
    }

    for(i = 0; key[i] != NULL; i++){
        col = findRow(key[i]);
        row = findColumn(plaintext[i]);
        encrypted[i] = arr[row][col];
    }
    encrypted[i]='\0';

    printf("\nEncrypted:\n");
    for(i = 0; encrypted[i] != NULL; i++)
        printf("%c", encrypted[i]);

    getch();
    system("cls");
    return encrypted;
}

int findRow(char col){
    int i;

    for(i=0;i<26;i++){
        if(arr[0][i]==col)
    return(i);
  }
}

int findColumn(char col){
    int i;

    for(i=0;i<26;i++){
        if(arr[i][0]==col)
    return(i);
  }
}

int findDecRow(char col,int j){
    int i;

    for(i=0;i<26;i++){
        if(arr[i][j]==col)
   return(i);
  }
}
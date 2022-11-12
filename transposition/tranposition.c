#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char* encptFunc(char plainText[], char key[]){
    printf("Hello World");

}

int main(){
    int choose = 0;
    char plainText[20], key[20], encpt[20], decpt[20];

    do{
        printf("\nTranposition Cipher\n");
        printf("=======================\n");
        printf("[0] Exit\n");
        printf("[1] Encrypt\n");
        printf("[2] Decrypt\n");
        printf("=======================\n\n");

        printf("Enter operation to begin: ");
        scanf("%d", &choose);

        switch(choose){
            case 1:
                printf("\nEnter Plaint Text:\n");
                fflush(stdin);
                gets(plainText);
                printf("\nEnter Key:\n");
                gets(key);
                system("cls");
                strcpy(encpt, encptFunc(plainText, key));
                getch();
                break;

        }
    }while(choose);

    return 0;
}
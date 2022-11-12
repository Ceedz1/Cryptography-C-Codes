#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//-------------------------------------------------------------

char* funcEncpt(char plaintext[]){
  int i, a;
  char ch;

  char* encrypted = malloc(sizeof(encrypted)*sizeof(char*));
  for(i = 0; i < strlen(plaintext); i++){
    a=plaintext[i];
    a=91-(a-64);
    ch=a;
    encrypted[i] = ch;
  }

  return encrypted;
}

//-------------------------------------------------------------

char* funcDecpt(char encpt[]){
  int i, a;
  char ch;

  char* decrypted = malloc(sizeof(decrypted)*sizeof(char*));
  for(i = 0; i < strlen(encpt); i++){
    a=encpt[i];
    a=91-(a-64);
    ch=a;
    decrypted[i] = ch;
  }
  return decrypted;
}

//-------------------------------------------------------------

int main(){
  char plaintext[100], encpt[100], decpt[100];
  int choose;

  do{
    printf("\n\nAtbash Cipher\n");
    printf("=================\n");
    printf("[0] Exit\n");
    printf("[1] Encrypt\n");
    printf("[2] Decrypt\n");
    printf("=================\n");
    printf("\nEnter Operation to Begin: ");
    scanf("%d", &choose);


    switch(choose) {
      case 1:
        fflush(stdin);
        printf("\nEnter Plaintext:\n");
        gets(plaintext);
        strcpy(encpt, funcEncpt(plaintext));
        printf("Encrypted Value:\n%s", encpt);
        break;
      case 2:
        printf("\nEncrypted Value:\n%s\n", encpt);
        strcpy(decpt, funcEncpt(encpt));
        printf("Decrypted Value:\n%s", decpt);
        break;
      default:
        break;
    }
  }while(choose);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Encrypt Function-------------------------------------------------------------

char* funcEncpt(char plaintext[]){
  int i, a;
  char ch;

  // FILE *fptr;

  //dynamically allocating "encrypted"
  char* encrypted = malloc(sizeof(encrypted)*sizeof(char*));

  //convert to ascii value
  for(i = 0; i < strlen(plaintext); i++){
    a=plaintext[i];
    a=91-(a-64);
    ch=a;
    encrypted[i] = ch;
  }
  
  //return decrypted value
  return encrypted;
}

//Decrypt Function-------------------------------------------------------------

char* funcDecpt(char encpt[]){
  int i, a;
  char ch;

  //dynamically allocating "decrypted"
  char* decrypted = malloc(sizeof(decrypted)*sizeof(char*));

  //convert to ascii value
  for(i = 0; i < strlen(encpt); i++){
    a=encpt[i];
    a=91-(a-64);
    ch=a;
    decrypted[i] = ch;
  }

  //return decrypted value
  return decrypted;
}

//Main Function-------------------------------------------------------------

int main(){
  char plaintext[100], encpt[100], decpt[100];
  int choose;

  //Main Operation Menu
  do{
    printf("\n\nAtbash Cipher\n");
    printf("=================\n");
    printf("[0] Exit\n");
    printf("[1] Encrypt\n");
    printf("[2] Decrypt\n");
    printf("=================\n");

    //Initialize "choose" by selecting from Main Operation Menu
    printf("\nEnter Operation to Begin: ");
    scanf("%d", &choose);

    //"Choose" switch case action
    switch(choose) {
      //Case 1: Will send "plaintext" to "funcEncpt"
      case 1:
        fflush(stdin);
        printf("\nPlease use UPPERCASE");
        printf("\nEnter Plain text:\n");
        gets(plaintext);
        strcpy(encpt, funcEncpt(plaintext));
        printf("Encrypted Value:\n%s", encpt);
        break;

      //Case 2: Will send "encpt" to "funcDecpt"
      case 2:
        printf("\nEncrypted Value:\n%s\n", encpt);
        strcpy(decpt, funcEncpt(encpt));
        printf("Decrypted Value:\n%s", decpt);
        free(decpt);
        break;
      
      //Default: will terminate program if "choose" is not in Menu
      default:
        break;
    }
  }while(choose);

  return 0;
}

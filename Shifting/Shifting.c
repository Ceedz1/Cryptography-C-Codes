#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

char* encptFunc(char plaintext[], int shftCount){
    int i;

    char *encrypted = calloc(strlen(plaintext), sizeof(char));

    for(i = 0; i < strlen(plaintext); i++){
      if(isalnum(plaintext[i])){
        if(islower(plaintext[i])){
          encrypted[i] = (plaintext[i] - 'a' + shftCount) % 26 + 'a';
        }
        if(isupper(plaintext[i])){
          encrypted[i] = (plaintext[i] - 'A' + shftCount) % 26 + 'A';
        }
        if(isdigit(plaintext[i])){
          encrypted[i] = (plaintext[i] - '0' + shftCount) % 10 + '0';
        }
      }
    }
    return encrypted;
}


char* decptFunc(char encrypt[], int shftCount){
    int i;

    char *decrypted = calloc(strlen(encrypt), sizeof(char));

    for(i = 0; i < strlen(encrypt); i++){
      if(isalnum(encrypt[i])){
        if(islower(encrypt[i])){
          decrypted[i] = (encrypt[i] - 'a' - shftCount) % 26 + 'a';
        }
        if(isupper(encrypt[i])){
          decrypted[i] = (encrypt[i] - 'A' - shftCount) % 26 + 'A';
        }
        if(isdigit(encrypt[i])){
          decrypted[i] = (encrypt[i] - '0' - shftCount) % 10 + '0';
        }
      }
    }
    return decrypted;
}


int main(){
  int choose, shftCount = 0;
  char plaintext[100];
  char encrypt[100];
  char decrypt[100];

  do{
    printf("\n\nShifting Cryptography\n");
    printf("==========================\n");
    printf("[0] Exit\n");
    printf("[1] Encrypt\n");
    printf("[2] Decrypt\n");
    printf("==========================\n");
    printf("Enter Operation to Begin: ");
    scanf("%d", &choose);

    switch(choose){
      case 1:
        fflush(stdin);
        printf("\nEnter Plaintext: \n");
        gets(plaintext);
        printf("Enter shift count: ");
        scanf("%d", &shftCount);
        strcpy(encrypt, encptFunc(plaintext, shftCount));
        printf("Encrypted Value:\n%s", encrypt);
        break;
      case 2:
        printf("\nEncrypted Value:\n%s\n", encrypt);
        strcpy(decrypt, decptFunc(encrypt, shftCount));
        printf("Decrypted Value:\n%s", decrypt);
      default:
        break;
    }
  }while(choose);
  return 0;
}

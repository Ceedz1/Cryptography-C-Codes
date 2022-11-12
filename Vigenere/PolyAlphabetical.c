#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Encrypt function------------------------------------------------
char* encryptFunc(char plaintext[], char key[]){
  int i, j;

  //dynamically allocating "encrypted"
  char *encrypted = calloc(strlen(plaintext), sizeof(char));

  //initialize "size" to the value of length of "plaintext"
  int size = strlen(plaintext);

  //Lenght of plaintext equal to length of key
  j = 0;
  for(i = strlen(key); i < size; i++){
    if(j == strlen(key)){
      j = 0;
    }
    key[i] = key[j];
    j++;
  }
  printf("\nNew Key:\n  %s", key);

  //convert plaintext to cipher text (encrypt)
  for(i = 0; i < size; i++){
    encrypted[i] = (((plaintext[i] - 97) + (key[i] - 97)) % 26 ) + 97;
  }
  printf("\nEncrypted Value:\n  %s", encrypted);

  printf("\n\n\nPress Any Key to Continue...");
  getch();
  system("cls");
    //return encrypted value
  return encrypted;
}

//Decrypt function------------------------------------------------------
char* decryptFunc(char encrypt[], char key[]){
  int i;

  char *decrypted = calloc(strlen(encrypt), sizeof(char));

  //convert cipher to plaintext (decrypt)
  for(i = 0; i < strlen(encrypt); i++){
    if(encrypt[i] < key[i]){
      decrypted[i] = 26+((encrypt[i]-97) - (key[i]-97))+97;
    }
    else
      decrypted[i] = (((encrypt[i]-97) - (key[i]-97))%26)+97;

  }


  //display decrypted value
  printf("\nDecrypted Value:\n %s", decrypted);
  printf("\n\n\nPress Any Key to Continue...");
  getch();
  system("cls");

  return decrypted;
}

//Main Function-----------------------------------------------------
int main(){
  char plaintext[20], encrypt[20], decrypt[20], key[20];
  int choose;

  do{
    //operation menu
    printf("\n\nPolyAlphabetical Cipher\n");
    printf("=================\n");
    printf("[0] Exit\n");
    printf("[1] Encrypt\n");
    printf("[2] Decrypt\n");
    printf("=================\n");
    printf("\nEnter Operation to Begin: ");
    scanf("%d", &choose);

    //operation selected
    switch (choose) {
      case 1:

      //input plain text to encryp
        fflush(stdin);
        printf("\n\nEnter Plain text: \n  ");
        gets(plaintext);
        fflush(stdin);
        printf("Enter Key: \n  ");
        gets(key);

        //initialize array "encrypt" to the return value from encryptFunc
        strcpy(encrypt,encryptFunc(plaintext, key));
        break;
      case 2:
        //initialize array "decrypt" to the return value from decryptFunc
        strcpy(decrypt, decryptFunc(encrypt, key));
        break;
      default:
        
        system("cls");
        getch();
        break;
    }
  }while(choose);

  return 0;
}

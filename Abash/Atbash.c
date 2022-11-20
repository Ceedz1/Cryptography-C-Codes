#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char plaintext[100];

//Encrypt Function-------------------------------------------------------------
char* funcEncpt(char plaintext[]){
  int i, a;
  char ch;

  // FILE *fptr;

  //dynamically allocating "encrypted"
  char* encrypted = malloc(sizeof(encrypted)*sizeof(char*));

  //traverse the ASCII value of A - Z
  for(i = 0; i < strlen(plaintext); i++){
    if(isupper(plaintext[i])){
      a=plaintext[i];
      a=91-(a-64);
      ch=a;
      encrypted[i] = ch;
    }else if(islower(plaintext[i])){
      a=plaintext[i];
      a=123-(a-96);
      ch=a;
      encrypted[i] = ch;
    }
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

  //traverse the ASCII value of A - Z
  for(i = 0; i < strlen(encpt); i++){
    if(isupper(encpt[i])){
      a=encpt[i];
      a=91-(a-64);
      ch=a;
      decrypted[i] = ch;
    }else if(islower(encpt[i])){
      a=encpt[i];
      a=123-(a-96);
      ch=a;
      decrypted[i] = ch;
    }
  }

  //return decrypted value
  return decrypted;
}


//Write to a File----------------------------
void writeFile(){
  FILE *fptr = fopen("cipher.txt", "w");
  
  printf("\nPlease use UPPERCASE");
  printf("\nEnter Plain text:\n");
  fflush(stdin);
  gets(plaintext);
  fputs(plaintext, fptr);
  fclose(fptr);

}


//Encrypt File--------------------------------- 
void encptFile(){
  int i, a;
  char ch, encrypted[100];
  //opens file stream
  FILE *fptr = fopen("cipher.txt", "r");
  fgets(plaintext, 100, fptr);
  
  //traverse the ASCII value of A - Z 
  for(i = 0; i < strlen(plaintext); i++){
    //if string is UPPERCASE 
    if(isupper(plaintext[i])){
      //"a" holds a charcter value of "plaintext"
      a=plaintext[i];
      a=91-(a-64);
      ch=a;
      encrypted[i] = ch;
    }else if(islower(plaintext[i])){
      a=plaintext[i];
      a=123-(a-96);
      ch=a;
      encrypted[i] = ch;
    }
    
  }
  printf("Current File Value: %s", plaintext);
  printf("\nEncrypted Value: %s", encrypted);
  fclose(fptr);

  fptr = fopen("cipher.txt", "w");
  fputs(encrypted, fptr);
  fclose(fptr);
  getch();
}


//Decrypt File Value--------------------------
void decptFile(){
  int i, a;
  char ch, encpt[100], decrypted[100];
  //opens file stream
  FILE *fptr = fopen("cipher.txt", "r");
  fgets(encpt, 100, fptr);

  for(i = 0; i < strlen(encpt); i++){
    //if string is UPPERCASE 
    if(isupper(encpt[i])){
      //"a" holds a charcter value of "encpt"
      a=encpt[i];
      a=91-(a-64);
      ch=a;
      decrypted[i] = ch;
    //if string is LOWERCASE
    }else if(islower(encpt[i])){
      a=encpt[i];
      a=123-(a-96);
      ch=a;
      decrypted[i] = ch;
    }
  } 
  //prints the current value of file (cipher)
  printf("Current File Value: %s", encpt);
  //prints the decrypted value of file
  printf("\nDecrypted Value: %s", decrypted);
  fclose(fptr);
  getch();
}

//Main Function-------------------------------------------------------------
int main(){
  char encpt[100], decpt[100];
  int choose;

  //Main Operation Menu
  do{
    printf("\n\nAtbash Cipher\n");                            
    printf("=================\n");
    printf("[0] Exit\n");
    printf("[1] Encrypt\n");
    printf("[2] Decrypt\n");
    printf("-----------------\n");
    printf("[3] Write to File\n");
    printf("[4] Encrypt File\n");
    printf("[5] Decrypt File\n");
    printf("=================\n");

    //Initialize "choose" by selecting from Main Operation Menu
    printf("\nEnter Operation to Begin: ");
    scanf("%d", &choose);

    //"Choose" switch case action
    switch(choose) {
      //Case 1: Will send "plaintext" to "funcEncpt"
      case 1:
        printf("\nPlease use UPPERCASE");
        printf("\nEnter Plain text:\n");
        fflush(stdin);
        gets(plaintext);
        strcpy(encpt, funcEncpt(plaintext));
        printf("Encrypted Value:\n%s", encpt);
        getch();
        system("cls");
        break;

      //Case 2: Will send "encpt" to "funcDecpt"
      case 2:
        printf("\nEncrypted Value:\n%s\n", encpt);
        strcpy(decpt, funcEncpt(encpt));
        printf("Decrypted Value:\n%s", decpt);
        free(decpt);
        getch();
        system("cls");
        break;
      //Case 3: write plain text to file
      case 3: 
        writeFile();
        system("cls");
        break;
      //Case 4: Encrypt text file
      case 4:
        encptFile();
        system("cls");
        break;
      //Case 5; Decrypt text file
      case 5:
        decptFile();
        system("cls");
        break;
      
      //Default: will terminate program if "choose" is not in Menu
      default:
        break;
    }
  }while(choose);

  return 0;
}


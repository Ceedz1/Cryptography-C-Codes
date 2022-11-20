#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


//Encrypt Function---------------------------------------------------
char* encptFunc(char plaintext[], int shftCount){
    int i;

    //Dynamically Allocating "encrypted"
    char *encrypted = calloc(strlen(plaintext), sizeof(char));

    //SHIFTING
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
    
    //returning encrypted value
    return encrypted;
}

//Decrypt Function---------------------------------------------------
char* decptFunc(char encrypt[], int shftCount){
    int i;

    //Dynamically Allocating "decrypted"
    char *decrypted = calloc(strlen(encrypt), sizeof(char));

    //SHIFTING
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
    //returning decrypted value
    return decrypted;
}

//Write to a File-------------------------------------------------
void writeFile(){
  char plaintext[100];
  FILE * fptr = fopen("cipher.txt", "w");

  printf("\nEnter Plaintext: \n");
  fflush(stdin);
  gets(plaintext);
  
  fputs(plaintext, fptr);
  fclose(fptr);
}

int encptFile(){
  int i, shftCount;
  char plaintext[100], encrypted[100];

  FILE *fptr = fopen("cipher.txt", "r");
  fgets(plaintext, 100, fptr);

  printf("Enter shift count: ");
  fflush(stdin);
  scanf("%d", &shftCount);

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
  fclose(fptr);

  fptr = fopen("cipher.txt", "w");

  printf("\nPlain Text: %s", plaintext);
  printf("\nEncrypted: %s", encrypted);
  fputs(encrypted, fptr);
  fclose(fptr);
  getch();

  return shftCount;
}

void decptFile(int shftCount){
  int i;
  char encrypted[100], decrypted[100];

  FILE *fptr = fopen("cipher.txt", "r");
  fgets(encrypted, 100, fptr);

  for(i = 0; i < strlen(encrypted); i++){
      if(isalnum(encrypted[i])){
        if(islower(encrypted[i])){
          decrypted[i] = (encrypted[i] - 'a' - shftCount) % 26 + 'a';
        }
        if(isupper(encrypted[i])){
          decrypted[i] = (encrypted[i] - 'A' - shftCount) % 26 + 'A';
        }
        if(isdigit(encrypted[i])){
          decrypted[i] = (encrypted[i] - '0' - shftCount) % 10 + '0';
        }
      }
    }
  printf("\nEncrypted Text: %s", encrypted);
  printf("\nDecrypted Text: %s", decrypted);
  fclose(fptr);
  getch();

}

//Main Function---------------------------------------------------
int main(){
  int choose, shftCount = 0;
  int ptr;
  char plaintext[100];
  char encrypt[100];
  char decrypt[100];

  do{

    //Main Operation Menu
    printf("\n\nShifting Cryptography\n");
    printf("==========================\n");
    printf("[0] Exit\n");
    printf("[1] Encrypt\n");
    printf("[2] Decrypt\n");
    printf("--------------------------\n");
    printf("[3] Write to File\n");
    printf("[4] Encrypt File\n");
    printf("[5] Decrypt File\n");
    printf("==========================\n");

    //Initialize "Choose" according to the operation menu
    printf("Enter Operation to Begin: ");
    scanf("%d", &choose);

    //switch case according to "choose"
    switch(choose){
      //case 1: will encrypt
      case 1:
        //initialize (Plain Text) and (Shift Count)
        fflush(stdin);
        printf("\nEnter Plaintext: \n");
        gets(plaintext);
        printf("Enter shift count: ");
        scanf("%d", &shftCount);

        //Initialize array "encrypt" to the return value of "encptFunc"
        strcpy(encrypt, encptFunc(plaintext, shftCount));
        printf("Encrypted Value:\n%s\n\n", encrypt);
        printf("Press any key to continue...");
        getch();
        system("cls");
        break;
      
      //case 2: will decrypt
      case 2:
        strcpy(decrypt, decptFunc(encrypt, shftCount));
        system("cls");
        printf("Decrypted Value:\n%s\n\n", decrypt);
        printf("Press any key to continue...");
        getch();
        system("cls");
        free(decrypt);
        break;
      
      case 3:
        writeFile();
        system("cls");
        break;
      
      case 4:
        ptr = encptFile();
        getch();
        system("cls");
        break;

      case 5:
        decptFile(ptr);
        system("cls");
        break;

      default:
        break;
    }
  }while(choose);
  return 0;
}

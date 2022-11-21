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
void writeFile();
void decptFile();
void encptFile();


int main(){
    int choose = 0, textIdx;
    char key[100], plaintext[100], encpt[100], decpt[100];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    do{
        printf("\n\nVernam Cipher\n");
        printf("====================\n");
        printf("[0] Exit\n");
        printf("[1] Encrypt\n");
        printf("[2] Decrypt\n");
        printf("--------------------\n");
        printf("[3] Write to File\n");
        printf("[4] Encrypt File\n");
        printf("[5] Decrypt File\n");
        printf("====================\n");

        printf("Enter Operation: ");
        scanf("%d", &choose);

        
        switch(choose){
            case 1:
                printf("\nEnter Plain Text: \n");
                fflush(stdin);
                gets(plaintext);
                int length = strlen(plaintext);
                printf("Length of key needed: %d\n", length);


                // Iterate N times where N is the size of text                      //basically automatically generates key
                for (textIdx = 0; textIdx < length; textIdx++) {
                    // Generate random int which determines which character to concatenate to
                    // the key string
                    int getKey = rand() % (int)(sizeof charset - 1);
                    key[textIdx] = charset[getKey];
                }
                //key[textIdx] = '\0';


                printf("Gerated Key: \n%s", key);
                strcpy(encpt, encptFunc(plaintext, key));
                break;

            case 2:
                strcpy(decpt, decptFunc(encpt, key));
                break;

            case 3:
                writeFile();
                break;
            
            case 4:
                encptFile();
                break;

            case 5:
                decptFile();
                break;
        }
    }while(choose);

    return 0;
}

//writing plain text to file-----------------------------------------------
void writeFile(){
    int textIdx, length;
    char key[100], plaintext[100];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    FILE *fptr = fopen("cipher.txt", "w");  //opening file stream
    
    printf("\nEnter Plain Text: \n");       //writing plaintext to file
    fflush(stdin);
    gets(plaintext);
    fputs(plaintext, fptr);

    length = strlen(plaintext);               //getting length of string
    printf("Length of key needed: %d\n", length);
    getch();
    fclose(fptr);

    fptr = fopen("key.txt", "w");
    
    // Iterate N times where N is the size of text      //automatically generates key
    for (textIdx = 0; textIdx < length; textIdx++) {
        // Generate random int which determines which character to concatenate to
        // the key string
        int getKey = rand() % (int)(sizeof charset - 1);
        key[textIdx] = charset[getKey];
    }
    fputs(key, fptr);           //store key to key.txt
    //key[textIdx] = '\0';

    printf("Generated Key: \n%s", key);         //printing key
    fclose(fptr);
    getch();
    system("cls");
}


//encrypting plain text function -------------------------------------
void encptFile(){
    int i, j, k , row, col;
    char key[100], plaintext[100], encrypted[100];

    FILE *fptr;         //opening file stream
    
    fptr = fopen("key.txt", "r");   //copyig key from key.txt
    fgets(key, 100, fptr);
    fclose(fptr);

    fptr = fopen("cipher.txt", "r");    //copying plain text from ciher.txt
    fgets(plaintext, 100, fptr);
    fclose(fptr);
    
    
    k=96;                       //traversing A-Z using ascii values
    for(i = 0; i < 26; i++){
        k++;
        for(j = 0; j < 26; j++){
            arr[i][j]=k++;      //stroring in a matrix form
            if(k==123)
                k=97;
        }
    }

    for(i = 0; key[i] != NULL; i++){        //basically calling findColumn and findDecRow to encrypt using 'key' and 'plaintext'
        col = findRow(key[i]);              
        row = findColumn(plaintext[i]);     
        encrypted[i] = arr[row][col];       //encrypted value is store in 'encrypted'
    }   
    encrypted[i]='\0';

    fptr = fopen("cipher.txt", "w");        //storing encrypted value to file
    printf("\n\nEncrypted:\n");
    for(i = 0; encrypted[i] != NULL; i++){
        printf("%c", encrypted[i]);
    }   
    fputs(encrypted, fptr); 
    fclose(fptr);           //closing file stream

    getch();
    system("cls");
}

//Decrypting ciphered text function---------------------------------------
void decptFile(){
    int i, row, col;
    char encrypted[100], key[100], decrypted[100];
    
    FILE *fptr;                         //opening file stream
    
    fptr = fopen("cipher.txt", "r");    //reading encrypted string from cipher.txt
    fgets(encrypted, 100, fptr);        //copying encrypted value to 'encrypted'
    fclose(fptr);

    fptr = fopen("key.txt", "r");       //reading key string from key.txt
    fgets(key, 100, fptr);              //copying key value to 'key'
    fclose(fptr);

    for(i = 0; key[i] != NULL; i++){            //basically calling findColumn and findDecRow to decrypt using 'key' and 'decrypted'
        col = findColumn(key[i]);
        row = findDecRow(encrypted[i], col);
        decrypted[i] = arr[row][0];
    }
    decrypted[i]='\0';

    printf("\nDecrypted:\n");               //printing decrypted value
    for(i = 0; decrypted[i] != NULL; i++){
        printf("%c", decrypted[i]);
    } 

    getch();
    system("cls");
}



//Encrypt & Decrypt(no file handling)------------------------------------------
char* decptFunc(char encpt[], char key[]){
    int i, j, k, row, col;
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

    //
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

    printf("\n\nEncrypted:\n");
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
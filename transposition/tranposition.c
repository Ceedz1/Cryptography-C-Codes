#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

//function prototypes
void encptFunc(char pad[10][10]);
void Encrypt(char pad[10][10]);
void Decrypt(char pad[10][10]);
void decptFile();
void encptFile();
void writeFile();

//Dynamically declared variables
int row,col,i,j;
char pad[10][10];


//MAIN FUNCTION-------------------------------------------
int main(){
     int choose=0,l=0;
     char plaintext[100], encpt[100], decpt[100], key[10];

    do{
        printf("\n\nTransposition Cipher\n");
        printf("========================\n");
        printf("[0] Exit\n");
        printf("[1] Encrypt & Decrypt\n");
        printf("------------------------\n");
        printf("[2] Write to file\n");      //we store text to be encryptaed to file
        printf("[3] Encrypt File\n");
        printf("[4] Decrypt File\n");     
        printf("========================\n");

        printf("Select Operation:");
        scanf("%d", &choose);

        switch(choose){
        case 1:
            printf("\nEnter Plain Text:\n");
            fflush(stdin);
            gets(plaintext);
            printf("Enter no. of rows:");
            scanf("%d", &row);
            printf("Enter no. of columns:");
            scanf("%d", &col);

            //forms the string into matrix form
            for(i=0;i<row;i++){
                for(j=0;j<col;j++){
                    if(plaintext[l]!='\0'){
                        if(plaintext[l]==' ')
                        l++;
                        pad[i][j]=plaintext[l];
                        l++;
                    }else{ 
                        break; 
                    }
                }
            }

            encptFunc(pad);
            getch();
            system("cls");
            break;
        case 2:
            writeFile();
            system("cls");
            break;
        case 3:
            encptFile();
            getch();
            system("cls");
            break;
        case 4:
            decptFile();
            getch();
            system("cls");
        default:
            break;
        }
    }while(choose);

    return 0;
}

//Get Key Function---------------------------------------
int *getKey(){
    int *key = calloc(sizeof(key), sizeof(int));    //dynamically allocating variable 'key'

    printf("\nEnter key sequence:\n", row);
    for(i = 0; i < row; i++){                   //getting key value from user input
        scanf("%d",&key[i]);
    }  
    return key;                 //return to function call
}


//store plain text to file----------------------------
void writeFile(){
    char plaintext[100];
    FILE *fptr = fopen("cipher.txt", "w");          //writing to file

    printf("\nEnter Plain Text:\n");
    fflush(stdin);
    scanf("%[^\n]s", plaintext);            //getting plain text value from user
    fputs(plaintext, fptr);             //storing string value to file
    fclose(fptr);                   //closing file

}

//Copy Plaintext to Matrix--------------------------
void encptFile(){
    char pad[10][10], plaintext[100];
    int l = 0;

    FILE *fptr = fopen("cipher.txt", "r");
    fgets(plaintext, 100, fptr);

    printf("Enter no. of rows:");
    scanf("%d", &row);
    printf("Enter no. of columns:");
    scanf("%d", &col);

    //forms the string into matrix form
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(plaintext[l]!='\0'){
                if(plaintext[l]==' ')
                l++;
                pad[i][j]=plaintext[l];
                l++;
            }else{ 
                break; 
            }
        }
    }
    fclose(fptr);
    Encrypt(pad);
    
}

//Encrypt Operation-----------------------------------------------
void Encrypt(char pad[10][10]){
    char encrypted[10][10];
    char plaintext[100], encryptVal[100];
    int u = 0, l = 0;
    
    FILE *fptr;             //declaring file pointer

    int *key = getKey();        //calling getKey function

    printf("\nEncrypted\n");                
    printf("========================\n");       
    for(i=0;i<row;i++){             //encrypting 'pad' value and storing it to 'encrypted' matrix
        for(j=0;j<col;j++){
            u=key[l]-1;
            encrypted[i][j]=pad[u][j];
        }
        l++;
    }

    for(i=0;i<row;i++){             //printing encrypted matrix
        for(j=0;j<col;j++){
            printf("%c ",encrypted[i][j]);
        }
        printf("\n");
    }
    
    fptr = fopen("cipher.txt", "w");    //writing encrypted value to file

    printf("Encrypted Text: ");
    for(i = 0, u = 0; i < row; i++){            
        for(j = 0; j < col; j++){           //printing encrypted value
            printf("%c", encrypted[i][j]);

            if(isgraph(encrypted[i][j])){   
                encryptVal[u] = encrypted[i][j];
                u++;    
            }    
        }
    }
    encryptVal[u] = '\0';        
    fputs(encryptVal, fptr);            
    printf("\n========================\n");
    fclose(fptr);

}



//Copy Encrypted File to Matrix---------------------------------------------
void decptFile(){
    
    char pad[10][10], encrypted[100];
    int l = 0;

    FILE *fptr = fopen("cipher.txt", "r");  //reading cipher.txt file
    fgets(encrypted, 100, fptr);            //copy file value to 'encrypted' array

    for(i=0;i<row;i++){             //print encrypted value to matrx (pad)
        for(j=0;j<col;j++){
            if(encrypted[l]!='\0'){
                if(encrypted[l]==' ')
                l++;
                pad[i][j]=encrypted[l];
                l++;
            }else{ 
                break; 
            }
        }
    }
    fclose(fptr);           //closing file
    Decrypt(pad);           //passing pad value to 'Decrypt' function
}

//Decrypt Operation-----------------------------------------------
void Decrypt(char pad[10][10]){
    int l,u;
    char encrypted[10][10],decrypted[10][10], encryptedVal[100];
    
    int *key = getKey();    //calling getKey Function

    printf("\nDecrypted\n");
    printf("========================\n");
    l=0;
    for(i=0;i<row;i++){             //we decrypt 'pad' and store it in 'decrypted' matrix
        for(j=0;j<col;j++){
            u=key[l]-1;
            decrypted[u][j]=pad[i][j];
        }
        l++;
    }

    for(i=0;i<row;i++){         //print decrypted matrix
        for(j=0;j<col;j++){
            printf("%c ",decrypted[i][j]);
        }
        printf("\n");
    }

    printf("Decrypted Text: ");

    for(i=0;i<row;i++){         //print decrypted value
        for(j=0;j<col;j++){
            printf("%c",decrypted[i][j]);
        }
    }
    printf("\n========================\n");
}




//ENCRYPT FUNCTION (No File Handling)------------------------------------
void encptFunc(char pad[10][10]){
    int l=0,key[10],u;
    char encrypted[10][10],decrypted[10][10];

    printf("\nEnter key sequence:\n", row);
    for(i = 0; i < row; i++)
        scanf("%d",&key[i]);
    
    printf("\nEncrypted\n");
    printf("========================\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            u=key[l]-1;
            encrypted[i][j]=pad[u][j];
        }
        l++;
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%c ",encrypted[i][j]);
        }
        printf("\n");
    }
    
    printf("Cipher Text: ");
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%c",encrypted[i][j]);
        }
    }
    printf("\n========================\n");

    printf("\nDecrypted\n");
    printf("========================\n");
    l=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            u=key[l]-1;
            decrypted[u][j]=encrypted[i][j];
        }
        l++;
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%c ",decrypted[i][j]);
        }
        printf("\n");
    }

    printf("Plain Text = ");

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%c",decrypted[i][j]);
        }
    }
    printf("\n========================\n");
}



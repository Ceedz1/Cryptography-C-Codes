#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


void encptFunc(char pad[10][10]);
void writeFile(char pad[10][10]);
void readFile();

int row,col,i,j;
char pad[10][10];


//MAIN FUNCTION-------------------------------------------
int main(){
     int choose=0,l=0;
     char plainText[100], encpt[100], decpt[100];

     printf("\nEnter Plain Text:\n");
     gets(plainText);
     printf("Enter no. of rows:");
     scanf("%d", &row);
     printf("Enter no. of columns:");
     scanf("%d", &col);

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(plainText[l]!='\0'){
                if(plainText[l]==' ')
                    l++;
                    pad[i][j]=plainText[l];
                    l++;
            }
            else{ 
                break; 
            }
        }
    }

    // for(i=0;i<row;i++){
    //     for(j=0;j<col;j++){
    //         printf("%c ",pad[i][j]);
    //     }
    //     printf("\n");
    // }

    do{
        printf("\n\nTransposition Cipher\n");
        printf("========================\n");
        printf("[0] Exit\n");
        printf("[1] Encrypt\n");
        printf("[2] Write to file\n");      //we store text to be encryptaed to file
        printf("[3] Read from file\n");     //access the file containing plain text
        printf("========================\n");

        printf("Select Operation:");
        scanf("%d", &choose);

        switch(choose){
        // case 1:
        //     system("cls");
        //     encptFunc(pad);
        //     getch();
        //     break;
        case 2:
            system("cls");
            writeFile(pad);
            getch();
            break;
        case 3:
            system("cls");
            readFile(pad);
            getch();
            break;
        default:
            break;
        }
    }while(choose);

    return 0;
}


//Write to File Function-----------------------------------------
void writeFile(char pad[10][10]){
    int l=0,k[10],u;
    char encrypted[10][10],decrypted[10][10];
    char ch, encryptVal[100];

    
    printf("\nEnter key sequence:\n",row);
    for(i=0;i<row;i++)
        scanf("%d",&k[i]);
    
    printf("\nEncrypted\n");
    printf("========================\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            u=k[l]-1;
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
    FILE *fptr = fopen("encryptVal.txt", "w");

    for(i = 0, u = 0; i < row; i++){
        for(j=0;j<col;j++){
            printf("%c", encrypted[i][j]);

            if(isgraph(encrypted[i][j])){   
                encryptVal[u] = encrypted[i][j];//encryptVal will have the value of encrypted
                u++;    //add 1 every iteration to 'u'
            }    
        }
    }
    encryptVal[u] = '\0';//after loop encryptVal now is at the EOF
    fprintf(fptr, "%s", encryptVal);
    fclose(fptr);
}


//Read from File Function (decrypt)-----------------------------------------
void readFile(){
    int l=0,k[10], u = 0;
    char encrypted[10][10],decrypted[10][10];
    char ch, buffer[150];

    FILE *fptr;
    fptr = fopen("encryptVal.txt", "r");
    
    // while(fgets(buffer, 150, fptr)){
    //     strcpy(encrypted[u], buffer);
    //     printf("Line %d: %s", u, encrypted[u]);
    //     u++;
    // } 
     
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            ch = fgetc(fptr);
            if (feof(fptr)){
                break ;
            }
            printf("%c", ch);
            encrypted[i][j]=ch;  
             
        }
           
    }
    
    printf("\nDecrypted\n");
    printf("========================\n");
    l=0;
    printf("1");
    for(i=0;i<row;i++){
        printf("2");
        for(j=0;j<col;j++){
            printf("3");
            u=k[l]-1;
            decrypted[u][j]=encrypted[i][j];
            printf("%c", decrypted[u][j]);
            printf("%c", encrypted[i][j]);
        }
        printf("4");
        l++;
    }
    printf("5");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%c ",decrypted[i][j]);
        }
        printf("\n");
    }

    printf("Plain Text = "); 
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%c",decrypted[i][j]);
        }
    } 
    printf("\n========================\n");   
    fclose(fptr);
}


//ENCRYPT FUNCTION------------------------------------
// void encptFunc(char pad[10][10]){
//     int l=0,k[10],u;
//     char encrypted[10][10],decrypted[10][10];

//     printf("\nEnter key sequence:\n", row);
//     for(i = 0; i < row; i++)
//         scanf("%d",&k[i]);
    
//     printf("\nEncrypted\n");
//     printf("========================\n");
//     for(i=0;i<row;i++){
//         for(j=0;j<col;j++){
//             u=k[l]-1;
//             encrypted[i][j]=pad[u][j];
//         }
//         l++;
//     }

//     for(i=0;i<row;i++){
//         for(j=0;j<col;j++){
//             printf("%c ",encrypted[i][j]);
//         }
//         printf("\n");
//     }
    
//     printf("Cipher Text: ");
    
//     for(i=0;i<row;i++){
//         for(j=0;j<col;j++){
//             printf("%c",encrypted[i][j]);
//         }
//     }
//     printf("\n========================\n");

//     printf("\nDecrypted\n");
//     printf("========================\n");
//     l=0;
//     for(i=0;i<row;i++){
//         for(j=0;j<col;j++){
//             u=k[l]-1;
//             decrypted[u][j]=encrypted[i][j];
//         }
//         l++;
//     }

//     for(i=0;i<row;i++){
//         for(j=0;j<col;j++){
//             printf("%c ",decrypted[i][j]);
//         }
//         printf("\n");
//     }

//     printf("Plain Text = ");

//     for(i=0;i<row;i++){
//         for(j=0;j<col;j++){
//             printf("%c",decrypted[i][j]);
//         }
//     }
//     printf("\n========================\n");
// }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void encptFunc(char pad[10][10]);

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
        printf("========================\n");

        printf("Select Operation:");
        scanf("%d", &choose);

        switch(choose){
        case 1:
            system("cls");
            encptFunc(pad);
            getch();
            break;
        default:
            break;
        }
    }while(choose);

    return 0;
}


//ENCRYPT FUNCTION------------------------------------
void encptFunc(char pad[10][10]){
    int l=0,k[10],u;
    char c[10][10],x[10][10];

    printf("\nEnter key sequence:\n",row);
    for(i=0;i<row;i++)
        scanf("%d",&k[i]);
    
    printf("\nEncrypted\n");
    printf("========================\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            u=k[l]-1;
            c[i][j]=pad[u][j];
        }
        l++;
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%c ",c[i][j]);
        }
        printf("\n");
    }
    
    printf("Cipher Text: ");
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%c",c[i][j]);
        }
    }
    printf("\n========================\n");

    printf("\nDecrypted\n");
    printf("========================\n");
    l=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            u=k[l]-1;
            x[u][j]=c[i][j];
        }
        l++;
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%c ",x[i][j]);
        }
        printf("\n");
    }

    printf("Plain Text = ");

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%c",x[i][j]);
        }
    }
    printf("\n========================\n");
}





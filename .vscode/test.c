#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
 
void rowtrans(char pad[10][10]);
int row,col,i,j;
char pad[10][10];
 
void main(){
    int ch=0,l=0;
    char plaintext[100];

    system("cls");
    printf("Enter the plain text: ");
    gets(plaintext);
    printf("Enter no of rows and column = ");
    scanf("%d",&row);
    scanf("%d",&col);

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(plaintext[l]!='\0'){
                if(plaintext[l]==' ')
                    l++;
                    pad[i][j]=plaintext[l];
                    l++;
            }
            else{ 
                break; 
            }
        }
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%c ",pad[i][j]);
        }
        printf("\n");
    }

    rowtrans(pad);
    getch();
}

void rowtrans(char pad[10][10]){
    int l=0,k[10],u;
    char c[10][10],x[10][10];

    printf("Enter the key to arrange 1 to %d row =\n",row);
    for(i=0;i<row;i++)
        scanf("%d",&k[i]);

    printf("\n**********Encryption**********\n");

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

    printf("Cipher Text = ");

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%c",c[i][j]);
        }
    }
}
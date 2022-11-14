#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int check(int x,int y){
    int a,b,c;

    if(x%y==0)
    return 0;

    a=x/y;
    b=y*(a+1);
    c=b-x;
    return c;
}

char* encptFunc(){
    int length,i,depth,j;
    //enter the length of the key
    printf("\nEnter Key Length:  ");
    scanf("%d", &length);

    int sequence[length];
    //enter sequence key
    printf("\nEnter Key Sequence: ");
    for(i = 0; i < length; ++i){
        scanf("%d", &sequence[i]);
    }

    int order[length];
    //we sort sequence key in order
    for(i = 1; i < length; ++i){
        for(j = 0; j < length; ++j){
            if(sequence[j] == i){
                order[i-1] = j;
            }
        }
    }

    printf("\nEnter Depth: ");
    scanf("%d", &depth);

    int length2;

    printf("\nEnter length of string to be entered (no spaces): ");
    scanf("%d", &length2);

    int temp1 = check(length2, length);
    int r = (length2+temp1)/length;

    char p[length2+temp1];
    char p1[r][length];

    if(temp1 > 0)
        printf("\nEnter %d bugos characters. \nSo enter total %d Characters. ", temp1, (length2+temp1));
    else    
        printf("\nEnter String: \n");
        for(i = -1; i < (length2+temp1); ++i){
            scanf("%c", &p[i]);
        }

    int count = 0;
    while (depth > 0){
        count = 0;

        for(i = 0; i < r; ++i){
            for(j = 0; j < length; ++j){
                p1[i][j] = p[count];
                count = count+1;
            }
        }

        printf("\n\n\n");

        for(i = 0; i < r; ++i){
            for(j = 0; j < length; ++j){
                printf("%c", p1[i][j]);
            }
            printf("\n");
        }

        count=0;
        for(i=0;i<length;++i){
            for(j=0;j<r;++j){
                p[count]=p1[j][order[i]];
                count=count+1;
            }
        }

        for(i = 0; i < (length2+temp1); ++i)
            printf("%c", p[i]);
            depth=depth-1;
        
    }
}

int main(){
    int choose = 0;
    char plainText[20], key[20], encpt[20], decpt[20];

    do{
        printf("\nTranposition Cipher\n");
        printf("=======================\n");
        printf("[0] Exit\n");
        printf("[1] Encrypt\n");
        printf("[2] Decrypt\n");
        printf("=======================\n\n");

        printf("Enter operation to begin: ");
        scanf("%d", &choose);

        switch(choose){
            case 1:
                system("cls");
                encptFunc();
                getch();
                break;

        }
    }while(choose);

    return 0;
}
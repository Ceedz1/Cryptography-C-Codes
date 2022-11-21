#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

void encptFunc();
int prime(int pValue);

int main(){
    int choose=0;

    do{
        printf("\n==================\n");
        printf("[0] Exit\n");
        printf("[1] Encrypt\n");
        printf("[2] Decrypt\n");
        printf("==================\n");

        printf("\n\nEnter Operation: ");
        scanf("%d", &choose);

        switch(choose){
        case 1:
            encptFunc();
            break;
        
        default:
            break;
        }
    }while(choose);
}

void encptFunc(){
    int p1, p2, flag;
    int i; 

    printf("\nEnter first Prime Number: ");
    scanf("%d", &p1);

    flag = prime(p1);
    if(flag == 0){
        printf("\nWrong Input\n\n");
        exit(1);
    }

    printf("\nEnter second Prime Number: ");
    scanf("%d", &p2);

    flag = prime(p2);
    if(flag == 0 || p1 == p2){
        printf("\nWrong Input\n\n");
        exit(1);
    }

}

int prime(int pValue){      //check prime function
    int i; 

    j = sqrt(pValue);               //this operation check no. whether its a prime or not
    for(i = 2; i <= j; i++){ 
        if(pValue % i == 0) 
            return 0; 
    } 
    return 1;
}
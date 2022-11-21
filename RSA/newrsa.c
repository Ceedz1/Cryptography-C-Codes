#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void encptFunc();

int main(){
    int choose=0;

    do{
        printf("\n==================\n");
        printf("[0] Exit\n");
        printf("[1] Encrypt\n");
        printf("[2] Decrypt\n");
        printf("==================\n");

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
    
}
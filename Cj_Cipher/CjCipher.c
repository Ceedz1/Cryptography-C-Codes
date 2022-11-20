#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char plaintext[100];

int main(){

    int choose;
    char decpt[100];

    do{
        printf("\nAtbash Cipher (Cj's Altered Version)\n");
        printf("===================================\n");
        printf("[1] Encrypt\n");
        printf("[2] Decrypt\n");
        printf("[0] Exit\n");
        printf("===================================\n");

        printf("Enter Operation: ");
        scanf("%d", &choose);

        FILE *fptr;

        switch(choose){
        case 1:
            fptr = fopen("cipher.txt", "w");
            printf("\nEnter Plain Text: \n");
            fflush(stdin);
            gets(plaintext);
            fputs(plaintext, fptr);
            getch();
            fclose(fptr);
            system("cls");
            // encptFunc();
            break;
        case 2:
            fptr = fopen("cipher.txt", "r");
            printf("\nString in File:  \n");
            fgets(decpt, 100, fptr);
            printf("%s", decpt);
            printf("\n\nEnter any key to continue..");
            getch();
            fclose(fptr);
            system("cls");
            break;
        default:
            break;
        }

    }while(choose);

    return 0;
}


// void encptFunc(){
//     int len, ascii, i;
//     char encrypted[100];

//     char upper_case[]={'Z', 'Y', 'X', 'W', 'V', 'U',
//  				   'T', 'S', 'R', 'Q', 'P', 'O',
// 				   'N', 'M', 'L', 'K', 'J', 'I', 
// 				   'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    
//     char lower_case[]={'z', 'y', 'x', 'w', 'v', 'u',
//   					't', 's', 'r', 'q', 'p', 'o',
// 					'n', 'm', 'l', 'k', 'j', 'i',
// 					'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

//     FILE *fptr = fopen("cipher.txt", "r");
//     fgets(plaintext, 100, fptr);

//     len = strlen(plaintext);

//     for(i = 0; i < len; i++){
//         ascii = plaintext[i];
//         if(ascii >= 'A' && ascii <= 'Z')
//             encrypted[i] = encrypted + upper_case[ascii - 65];
//         else
//             encrypted[i] = encrypted + lower_case[ascii - 75];
        
//     }
//     fclose(fptr);
//     printf("\nEncrypted: %s", encrypted);
// }
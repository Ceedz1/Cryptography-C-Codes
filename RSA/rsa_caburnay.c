#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

void encptFunc();
int prime(int pValue);
int calProd(int p1, int p2);
int calTotient(int p1, int p2);
int findGCD(int totient, int pubK);
char *Encrypt(char text[], int key, int product);
long long int power(char base, int power);


int j, p1, p2, flag, pubK, privK;
char decpt[100];

int main(){
    int choose=0;

    do{
        printf("\n\n==================\n");
        printf("[0] Exit\n");
        printf("[1] Encrypt\n");
        // printf("[2] Decrypt\n");
        printf("==================\n");

        printf("\nEnter Operation: ");
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
    int i;
    char plaintext[100];


    printf("\nEnter first Prime Number: ");
    scanf("%d", &p1);

    flag = prime(p1);
    if(flag == 0){
        printf("\nWrong Input\n\n");
        exit(1);
    }
    
    printf("Enter second Prime Number: ");
    scanf("%d", &p2);

    flag = prime(p2);
    if(flag == 0 || p1 == p2){
        printf("\nWrong Input\n\n");
        exit(1);
    }
    


    int product = calProd(p1,p2);
    int totient = calTotient(p1, p2);
    printf("Product Value: %d", product);
    printf("\nTotient Value: %d", totient);


    for(pubK = 5; pubK <= 100; pubK++){
        if(findGCD(totient, pubK) == 1){
            break;
        }   
    }

    for(privK = pubK + 1; privK <= 100; privK++){
        if(((privK*pubK) % totient) == 1)
        break;
    }

    printf("\nPublic Key: ");
    printf("%d", pubK);
    printf("\nPrivate Key: ");
    printf("%d", privK);

    printf("\n\nEnter Plain Text:\n");
    fflush(stdin);
    gets(plaintext);

    // for(i = 0; plaintext[i] != NULL; i++){
    //     encpt[i] = plaintext[i];
    // }
    char *encrypted = Encrypt(plaintext, pubK, product);
    printf("\nEncrypted:\n%s", encrypted);
    char *Decrypt = Encrypt(encrypted, privK, product);
    printf("\nDecrypted:\n%s", Decrypt);
}

/* 
    encrypting a message needs
    - Plain Text
    - Public Key
    - Product
    
    Formula: (plaintext*pubK) mod (Prod) = cipher text
*/
long long int power(char base, int power) {
  long long int result;

  result = (long long int)pow(base, power);

  return result;
}

char *Encrypt(char text[], int key, int product){
    int i;
    int size = strlen(text);
    char *result = calloc(strlen(text), sizeof(char));

    for(i = 0; i < size; i++){
        if (isgraph(text[i]) && !isspace(text[i])) {
            if (isupper(text[i])) {
                result[i] =
                (char)((power((text[i] - 'A'), key) % product) + 'A');
            }

            if (islower(text[i])) {
                result[i] =
                (char)((power((text[i] - 'a'), key) % product) + 'a');
            }
        } else {
            result[i] = text[i];
        }
    }
    
    return result;
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

int calProd(int p1, int p2){
    int prodVal;

    prodVal = (p1*p2);
    return prodVal;
}

int calTotient(int p1, int p2){
    int totVal;

    totVal = (p1 - 1)*(p2 - 1);
    return totVal;
}

int findGCD(int totient, int pubK){
    int i, gcd;

	for(i = 1; i <= totient && i <= pubK; ++i) {
		if(totient % i == 0 && pubK % i == 0)
			gcd = i;
	}
	return gcd;
}

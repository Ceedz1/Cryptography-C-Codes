#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

void writeFile();
void encptBash();
int prime(int pqValue);
void encptRSA();
void rsaEN();
void rsaDE();
int calProd(int p, int q);
int calTotient(int p, int q);
int findGCD(int totient, int pubK);
char *rsaEncrypt(int key, int product);

int i, j, p, q, pubK, privK, len, flag, product, totient;
char encrypted[100], plaintext[100], *result;

int main(){
    int i, choose;
    
    do{
        printf("\nCipher Jacket\n");
        printf("=======================\n");
        printf("[1] Populate File\n");
        printf("[2] Encrypt\n");
        printf("[3] Decrypt\n");
        printf("[0] Exit\n");
        printf("=======================\n");

        printf("Enter Operation: ");
        scanf("%d", &choose);


        switch(choose){
        case 1:
            writeFile();
            system("cls");
            break;
        case 2:
            encptBash();
            getch();
            system("cls");
            break;
        case 3:
            rsaDE();
            getch();
            system("cls");
            break;
        default:
            break;
        }

    }while(choose);

    return 0;
}


//Write to file ------------------------------
void writeFile(){
  char plaintext[100];

  FILE *fptr = fopen("cipher.txt", "w");

  printf("\nEnter Plain Text: \n");
  fflush(stdin);
  gets(plaintext);
  fputs(plaintext, fptr);
  fclose(fptr);

}


//Encrypt Abash---------------------------------
void encptBash(){
  char plaintext[100], encrypted[100];
  int i, len;

  FILE *fptr = fopen("cipher.txt", "r");

  fgets(plaintext, 100, fptr);
  fclose(fptr);

  len = strlen(plaintext);
  
  for(i = 0; i < len; i++){
    if(isupper(plaintext[i])){
      encrypted[i] = 'Z' - (plaintext[i] - 'A');
    }else if(islower(plaintext[i])){
      encrypted[i] = 'z' - (plaintext[i] - 'a');
    }else{
      encrypted[i] = plaintext[i];
    }
  }
  
  fptr = fopen("cipher.txt", "w");
  fputs(encrypted, fptr);
  fclose(fptr);

  printf("Encrypted: %s", encrypted);

  encptRSA();

}

// Encrypt RSA---------------------------------
void encptRSA(){
  
  printf("\nEnter First Prime: ");
  scanf("%d", &p);
  flag = prime(p);
  if(flag == 0){
      printf("\nWrong Input\n\n");
      exit(1);
  }

  printf("Enter second Prime Number: ");
  scanf("%d", &q);
  flag = prime(q);
  if(flag == 0 || p == q){
      printf("\nWrong Input\n\n");
      exit(1);
  }

    product = calProd(p, q);
    totient = calTotient(p, q);

    printf("%d", product);
    printf("%d", totient);
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

    pubK = 5;
    privK = 5;

    rsaEN();
  
}

void rsaEN(){
    //here lies rsa encryption implemenetation
    //RSA ecnryption process
      //- (plaintext) ^ (E) mod (N) = ciphertext
      //plaintext, pubk, product

  result = rsaEncrypt(pubK, product);
  printf("\n\nrsa encpt: %s", result);

  FILE *fptr = fopen("cipher.txt", "w");
  fputs(result, fptr);
  fclose(fptr);

  getch();
}

void rsaDE(){
  char encptRSA[100], *newResult;     //stores rsa encpt value

  newResult = rsaEncrypt(privK, product);
  printf("\nrsa decpt: %s", newResult);

  FILE *fptr = fopen("cipher.txt", "w");
  fputs(newResult, fptr);
  fclose(fptr);
  getch();
}


//Encrypt/Decrypt RSA Function---------------------------------
char *rsaEncrypt(int key, int product){
  char  encrypted[100];
  long long int powVal, len, i;

  FILE *fptr = fopen("cipher.txt", "r");
  fgets(encrypted, 100, fptr);
  len = strlen(encrypted);
  fclose(fptr);

  char *result = calloc(sizeof(encrypted), sizeof(char));

    for(i = 0; i < len; i++){
      powVal = pow(encrypted[i], key);
      powVal= powVal % product;
      result[i] = powVal;
      
    }
    return result;
}
 
//Called Functions---------------------------------


int prime(int pqValue){      //check prime function
    int i, j; 

    j = sqrt(pqValue);               //this operation check no. whether its a prime or not
    for(i = 2; i <= j; i++){ 
        if(pqValue % i == 0) 
            return 0; 
    } 
    return 1;
}

int calProd(int p, int q){
    int prodVal;

    prodVal = (p*q);
    return prodVal;
}

int calTotient(int p, int q){
    int totVal;

    totVal = (p - 1)*(q - 1);
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


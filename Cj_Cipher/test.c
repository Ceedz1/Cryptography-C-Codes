#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int x, y, n, t, i, flag;
long int e[50], d[50], temp[50], j, m[50], en[50];
char msg[100];

int prime(long int);
void encryption_key();
long int cd(long int);
void encrypt();
void decrypt();

int main()
{
  printf("\nENTER FIRST PRIME NUMBER\n");
  scanf("%d", &x);                //x = p
  flag = prime(x);                 //pass p to to check if its a prime number
  if(flag == 0)
  {
    printf("\nINVALID INPUT\n");
    exit(0);
  }
  printf("\nENTER SECOND PRIME NUMBER\n");
  scanf("%d", &y);              //y = q
  flag = prime(y);              //pass q to to check if its a prime number
  if(flag == 0 || x == y)
  {
    printf("\nINVALID INPUT\n");
    exit(0);
  }
  printf("\nENTER MESSAGE OR STRING TO ENCRYPT\n");

  scanf("%s",msg);                    //msg = plaintext
  for(i = 0; msg[i] != NULL; i++){
    m[i] = msg[i];                   //m contains msg
    printf("%c", m[i]);
  }
    
  n = x * y;                            // n = product
  t = (x-1) * (y-1);                     //t = totient

  
  encryption_key();
  printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
  for(i = 0; i < j-1; i++)
    printf("\n%ld\t%ld", e[i], d[i]);


  encrypt();
  decrypt();


  return 0;
}
int prime(long int pr)      //check pass value if its prime
{
  int i;                      
  j = sqrt(pr);
  for(i = 2; i <= j; i++)
  {
   if(pr % i == 0)
     return 0;
  }
  return 1;
 }

//function to generate encryption key
void encryption_key()
{
  int k;
  k = 0;
  for(i = 2; i < t; i++)
  {
    if(t % i == 0)
     continue;
    flag = prime(i);
    if(flag == 1 && i != x && i != y)
    {
     e[k] = i;
     flag = cd(e[k]);
    if(flag > 0)
    {
     d[k] = flag;
     k++;
    }
   if(k == 99)
    break;
   }
 }
    
}
long int cd(long int a)
{
  long int k = 1;
  while(1)
  {
    k = k + t;
    if(k % a == 0)
     return(k / a);
  }
  
}

//function to encrypt the message
void encrypt(){
  long int pt, ct, key = e[0], k, len;  //pt = plain text && e = public key && key = holds value of e
  i = 0;                                //ct = crypt text
  len = strlen(msg);                //msg = variable holding plaintext

  while(i != len){
    pt = m[i];                      //m = contains value of msg
    pt = pt - 96;
    k = 1;

    for(j = 0; j < key; j++){
        k = k * pt;
        k = k % n;          //n = product
    }

    temp[i] = k;
    ct = k + 96;
    en[i] = ct;
    i++;
  }
  en[i] = -1;

  printf("\n\nTHE ENCRYPTED MESSAGE IS\n");
  for(i = 0; en[i] != -1; i++)
    printf("%c", en[i]);
}

//function to decrypt the message
void decrypt(){
  long int pt, ct, key = d[0], k;
  i = 0;
  while(en[i] != -1)
  {
    ct = temp[i];
    k = 1;
    for(j = 0; j < key; j++)
    {
      k = k * ct;
      k = k % n;
    }
   pt = k + 96;
   m[i] = pt;
   i++;
  }
  m[i] = -1;
  printf("\n\nTHE DECRYPTED MESSAGE IS\n");
  for(i = 0; m[i] != -1; i++)
   printf("%c", m[i]);
  printf("\n");
}
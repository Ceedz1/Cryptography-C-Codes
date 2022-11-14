#include <stdio.h>

int main(){
    char transposition[]={2,4,0,1,3};
    char input[256] = "JacksJacksJacks\n";
    int len = sizeof(transposition);
    char ch, temp[len];
    int i, j, k;

    j=i=0;
    do {
        for( ; '\0'!=(ch = input[i]) && ch != '\n';++i){
            temp[j++] = ch;
            if(j == len){
                j=0;
                ++i;
                break;
            }
        }
        while(j!=0){
            temp[j++] = '.';//pading if(i % len != 0)
            if(j == len)
                j = 0;
        }
        for(k=0;i && k<len;++k){
            printf("%c", temp[transposition[k]]);
        }
    }while(ch != '\n' && ch != '\0');
    printf("\n");

    return 0;
}
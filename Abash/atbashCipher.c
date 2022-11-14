char translate(char text){
    char letter;
    char reverse;
    letter  = text;
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char atbash[26] = {'Z','Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    int x = 0;
    int size = 26;

    while(x <= size)
     {
        if(letter == alphabet[x])
            {
               reverse = atbash[x];
               break;
            }
        x++;        
     }
    return reverse;
}

int main(){
    char text [100];
    char translation [100];
    int strSize, i;

    printf("Hi! this is ATBASH translator.\n");
    printf("Use CAPSLOCK to input text\n");

    printf("ENTER TEXT: ");
    scanf("%[^\n]", text);

    strSize = strlen(text); //I removed the minus 1 
for (i = 0; i < strSize; i++){
    translation[i] = translate(text[i]);
}
    printf("TRANSLATION: %s", translation);
    return 0;
}
#include <stdio.h>
#include <ctype.h>

void encrotciph(char str[], int u, int k);
void decrotciph(char str[], int u, int k);
void encsubciph(char str[], int u, char alph[]);
void decsubciph();
void decencrotciph();
void decencsubciph();

void encrotciph(char str[], int u, int k){
    for (int i = 0; i < u; i++){
        if (isupper(str[i])){
            str[i] = str[i] - 65;//takes the letter in array g into ASCII code numbers
            str[i] = (k + str[i]) % 26;//uses the key encrypte 
            str[i] = str[i] + 65;//takes the numbers and turns them back into letters  
}     
} 
     printf("\n\n%s", str);//prints the ecnryption
}
void decrotciph(char str[], int u, int k){
    for(int i = 0; i < u; i++){
         if(isupper(str[i])){
         str[i] = 26 + str[i] - 65;
         str[i] = (str[i] - k) % 26;
         str[i] = str[i] + 65;
}              
}
     printf("%s\n", str);
}
void encsubciph(char str[], int u, char alph[]){
    int f;
    for(int i = 0; i < u; i++){
         if(isupper(str[i])){
             f = str[i] - 65;
             str[i] = alph[f];
}
}
    printf("%s\n", str);
}


    
int main(){
    int k = 1;  
    char selec='c';
    int u;
    char str[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    u = sizeof(str)/sizeof(char);
    char alph[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    printf("%d\n", u); //shows the size of the array 
    printf("Please select and option: \n");
    printf("a) Encrypt a rotation cipher \n");
    printf("b) Decrypt a rotation cipher \n");
    printf("c) Encrypt a substitution cipher \n");
    printf("d) Decrypt a substitution cipher \n");
    printf("e) Decrypt a message encrypted with rotation cipher \n");
    printf("f) Decrypt a message ecrypted with substitution cipher \n");
    printf("Selection: \n");
    //scanf(" %c", &selec); 
    
    switch(selec) {
        case 'a':
        encrotciph(str, u, k);
        //break;
        case 'b': 
        decrotciph(str, u, k);
        break;
        case 'c': 
        encsubciph(str, u, alph);
        break;
 /*       case 'd': decsubciph();
        break;
        case 'e': decencrotciph();
        break;
        case 'f': decencsubciph();*/
        default: printf("Unknown option %c\n Please enter a, b, c, d, e, f\n", selec);
    } 
    
    int j,f;
    for(int i = 0; i < u; i++){
        if(isupper(str[i])){
            for(int m=0; m<26; m++){
                
            }
        j = str[i];
        f = alph[j-65];
        str[i] = f;
    }
  }
  
  printf("%s\n", str);
    
     return 0;
}


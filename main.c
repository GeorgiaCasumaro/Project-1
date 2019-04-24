#include <stdio.h>
#include <ctype.h> //this header file has been included to use the pre determined function "isupper", to check if the letter is upper case

void encrotciph(char str[], int u, int k);
void decrotciph(char str[], int u, int k);
void encsubciph(char str[], int u, char alph[]);
void decsubciph(char str[], int u, char alph[]);
void decencrotciph(char str[], int u);
void decencsubciph();

void encrotciph(char str[], int u, int k){
    for (int i = 0; i < u; i++){
        if (isupper(str[i])){
            str[i] = str[i] - 65;//takes the letter in array g into ASCII code numbers
            str[i] = (k + str[i]) % 26;//uses the key encrypt
            str[i] = str[i] + 65;//takes the numbers and turns them back into letters  
        }       
    } 
     printf("\n\n%s", str);//prints the encryption
}
void decencrotciph(char str[], int u){
   int w = 1;
      while( w<=25)
      for(int i = 0; i < u; i++){
        if(isupper(str[i])){
            str[i] = 26 + str[i] - 65;
            str[i] = (str[i] - w) % 26;
            str[i] = str[i] + 65;
            w++;     
        }
      }

        printf("%s\n",str);
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
void decsubciph(char str[], int u, char alph[]){
    int a, b;
    for(int i = 0; i < u; i++){
        if(isupper(str[i])){
            a = str[i];
            b = 0;
            while(a != alph[b])
            b++;
            str[i] = b + 65;
    }
  }
  printf("%s\n", str);
}
int main(){
    int k = 1;  
    char selec='d';
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
        case 'd': decsubciph(str, u, alph);
/*       case 'e': decencrotciph();
        break;
        case 'f': decencsubciph();*/
        break;
        default: printf("Unknown option %c\n Please enter a, b, c, d, e, f\n", selec);
    } 
     return 0;
     
//FILE *fopen(const char *input, const char *r+); //fopens prototype


}

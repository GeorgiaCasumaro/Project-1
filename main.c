#include <stdio.h>
#include <ctype.h> //this header file has been included to use the pre determined function "isupper", to check if the letter is upper case
/*these are function prototypes, void is stated as they do not provide a return value*/
void encrotciph(char str[], int u, int k);
void decrotciph(char str[], int u, int k);
void encsubciph(char str[], int u, char alph[]);
void decsubciph(char str[], int u, char alph[]);
void decencrotciph(char str[], int u);
void decencsubciph();

/*this function encodes through the use of a rotational cipher. This is done by adding a predetermined key to the provided message*/ 
void encrotciph(char str[], int u, int k){ 
    for (int i = 0; i < u; i++){ // this for loop uses i as a counter to increase throughout the size of the array u
        if (isupper(str[i])){ // isupper checks if the letter is upper case then comtinue through the loop
            str[i] = str[i] - 65;//takes the letter in array g into ASCII code numbers
            str[i] = (k + str[i]) % 26;//uses the key encrypt
            str[i] = str[i] + 65;//takes the numbers and turns them back into letters  
        }       
    } 
    printf("\n\n%s", str);//prints the encryption
}
/*this function decodes without the use of a key*/
void decencrotciph(char str[], int u){
   int w = 0; //introduces a new counter for all the possible keys
      while( w<=25){
      for(int i = 0; i < u; i++){
        if(isupper(str[i])){
            str[i] = 26 + str[i] - 65;
            str[i] = (str[i] - 1) % 26;
            str[i] = str[i] + 65;     
        } 
      }
      w++; //increases the possible keys  
      printf("Key is %d. message %s\n", w, str);//prints the key and the decrypted message
      }
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
    int k; 
    int u;
    char alph[26];
    FILE *input;
    input=fopen("input.txt", "r");
    
    if(input==NULL){
         perror("input fopen()");
         return 0;   
    }
    char selec;
    fscanf(input, "%c", &selec);
    if(selec == 97 || selec == 98){
        fscanf(input, "%d", &k); //reads from file
    }
    else if(selec == 100 || selec == 101){  
        fscanf(input, "%s", alph);
    }

    FILE *message;
    message=fopen("message.txt", "r");
    
    if(message==NULL){
         perror("message fopen()");
         return 0;   
    }
    char str[1024];
    u = sizeof(str)/sizeof(char);
    for(int i=0; i<u; i++){
        char g; 
        fscanf(message, "%c", &g);
        if(feof(message)==0){
            if(islower(g)){
                g-=32;
            } 
            str[i] = g;
        }
    }     
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
        break;
        case 'b': 
        decrotciph(str, u, k);
        break;
        case 'c': 
        decencrotciph(str, u);    
        break;
        case 'd': 
        encsubciph(str, u, alph); 
        break;   
        case 'e':
        decsubciph(str, u, alph);
        break;
    /*    case 'f': decencsubciph();
        break; */
        default: printf("Unknown option %c\n Please enter a, b, c, d, e, f\n", selec);
    } 
     return 0;
     
}

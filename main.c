#include <stdio.h>
#include <ctype.h> //this header file has been included to use the pre determined function "isupper", to check if the letter is upper case
/*these are function prototypes, void is stated as they do not provide a return value*/
void encrotciph(char str[], int u, int k, FILE *output);
void decrotciph(char str[], int u, int k, FILE *output);
void encsubciph(char str[], int u, char alph[], FILE *output);
void decsubciph(char str[], int u, char alph[], FILE *output);
void decencrotciph(char str[], int u, FILE *output);


/*This function encrypts through the use of a rotational cipher.
This is done by adding a predetermined key to the provided message, to change the values of the ASCII numbers*/ 

void encrotciph(char str[], int u, int k, FILE *output){ 
    for (int i = 0; i < u; i++){ // this for loop uses i as a counter to increase throughout the size of the array u
        if (isupper(str[i])){ // isupper checks if the letter is upper case then continue through the loop
            str[i] = str[i] - 65; //takes the letters in the array and converts to ASCII code numbers
            str[i] = (k + str[i]) % 26; //uses the key encrypt
            str[i] = str[i] + 65; //takes the numbers and turns them back into letters  
        }       
    } 
    printf("\n\n%s", str); //prints the encryption
    fprintf(output, "\n\n%s", str); //prints the encryption to the output file
}
/*This function decrypts without the use of a key.
This is completed by introducing a counter starting at 0 through to all the possible keys available for the key which is 25.
The message is than ran through a for loop to test each possible key and printed*/

void decencrotciph(char str[], int u, FILE *output){
   int w = 0; //introduces a new counter for all the possible keys
      while( w<=25){ //all thr possible keys
      for(int i = 0; i < u; i++){ // this for loop uses i as a counter to increase throughout the size of the array u
        if(isupper(str[i])){ // isupper checks if the letter is upper case then continue through the loop
            str[i] = 26 + str[i] - 65; //takes the letters in the array and converts to ASCII code numbers with the addition of 26
            str[i] = (str[i] - 1) % 26; //uses the str converted in line 31 to decrypt
            str[i] = str[i] + 65; //takes the ASCII numbers and turns them back into letters       
        } 
      }
      w++; //increases until the while loop is no longer true
      printf("Key is %d. message %s\n\n", w, str); //prints the key and the decrypted message
      fprintf(output, "Key is %d. message %s\n\n", w, str); //prints to the output file
      }
}
/*This function decrypts through the use of a key.
This is simply done by subtracting the initial key off of the encrypted message and then printed*/

void decrotciph(char str[], int u, int k, FILE *output){
    for(int i = 0; i < u; i++){ // this for loop uses i as a counter to increase throughout the size of the array u
         if(isupper(str[i])){ // isupper checks if the letter is upper case then continue through the loop
            str[i] = 26 + str[i] - 65; //turns the encrypted message letters into ASCII and adds 26 other wise will not decrypt
            str[i] = (str[i] - k) % 26; //subtracts the key to decrypt the message from the new str[i] value
            str[i] = str[i] + 65; //takes the ASCII numbers and turns them back into letters 
    }              
         }
     printf("%s\n", str); //prints the new decrypted value of str
     fprintf(output, "%s\n", str); //prints new decryption to the output file
}

/*This function encrypts through the use of a substitution cipher.
This is done through the use of a predetermined key, which is a string composed of 26 letters.
A declaration of another integer f has been done as the as the intial string of i, str[i], needs to become another string, alph[f} in order to change the message to the predetermined key*/ 

void encsubciph(char str[], int u, char alph[], FILE *output){
    int f;
    for(int i = 0; i < u; i++){ // this for loop uses i as a counter to increase throughout the size of the array u
         if(isupper(str[i])){ // isupper checks if the letter is upper case then continue through the loop
             f = str[i] - 65; //f is now equal to str[i] ASCIIcode number
             str[i] = alph[f]; //these ASCII code numbers now equal to alph[f]
    }
        }
    printf("%s\n", str); //prints the encryption of the original message 
    fprintf(output, "%s\n", str); //prints to the output file
}

/*This function decrypts the encrypted message through substitution cipher.
This is completed through the addition if two new variables a and b. 
B is used as a counter to move across the message decrypt each letter through use of the key.*/
void decsubciph(char str[], int u, char alph[], FILE *output){
    int a, b;
    for(int i = 0; i < u; i++){ // this for loop uses i as a counter to increase throughout the size of the array u
        if(isupper(str[i])){ // isupper checks if the letter is upper case then continue through the loop
            a = str[i]; 
            b = 0; //counter b
            while(a != alph[b]) //while str is not equal to alph of b continue to decrypt
            b++; //adds one to b to continue through the message 
            str[i] = b + 65; //takes the ASCII numbers and turns them back into letters 
    }
  }
  printf("%s\n", str); //prints the decrypted value of str
  fprintf(output, "%s\n", str); //prints decryption to the output file 
}
int main(){
    int k; 
    int u; 
    char alph[26]; //alph is the size of the alphabet, 26
    
    FILE *input; //introduces the input file 
    input=fopen("input.txt", "r"); //opens file input with mode of reading 
    
    if(input==NULL){ /*This if statement is used so that if the file trying to be accessed is NULL,
                     it does not result in a segmentation fault rather a error*/
                    
         perror("input fopen()"); //returns a user friendly message 
         return 0;   
    }
    
    /*int size=0; 
    char c;
    while((fscanf(input, "%c", &c)) !=EOF){
        size++; 
    }
    
    printf("\n\n%d\n\n", size); */
   
    fseek(input, 446, SEEK_SET);
    char selec;
    fscanf(input, "%c", &selec);
    fseek(input, 453, SEEK_SET);
    if(selec == 97 || selec == 98){ //if option a(ASCII value of 97) or b(ASCII value of 98) are selected 
        fscanf(input, "%d", &k); //reads from file
    }
    else if(selec == 100 || selec == 101){ //if option d(ASCII value of 100) or e(ASCII value of 101) are selected 
        fscanf(input, "%s", alph); //reads from file
    }

    FILE *message;
    message=fopen("message.txt", "r"); //opens file messgae with mode of reading 
    
    if(message==NULL){ /*This if statement is used so that if the file trying to be accessed is NULL,
                         it does not result in a segmentation fault rather a error*/
         perror("message fopen()"); //returns a user friendly message 
         return 0;   
    }
    char str[1024]; //allocates str to a large value of 1024 suitable for large messages 
    u = sizeof(str)/sizeof(char); //determines the size of u, used throughout the functions
    for(int i=0; i<u; i++){ // this for loop uses i as a counter to increase throughout the size of the array u
        char g; 
        fscanf(message, "%c", &g); //scans char g into the message file
        if(feof(message)==0){ 
            if(islower(g)){ 
                g-=32; // change to upper case 
            } 
            str[i] = g;
        }
        else    {
            str[i]=0; //fills the rest of the array with NULL characters
        }
    }     
    
    FILE *output; 
    output=fopen("output.txt", "w"); //opens file output with mode of writing 
    
    if(output==NULL){ /*This if statement is used so that if the file trying to be accessed is NULL,
                        it does not result in a segmentation fault rather a error*/
         perror("output fopen()"); //returns a user friendly message 
         return 0;  
    }

/*This switch statement as a user friendly menu for all the possible encryption and decryption functions. 
In each case, what the function is doing is printed to both the console and the output file including the function used for that particular task*/
    
    switch(selec) {
        case 'a':
        printf("Encrypt a rotation cipher using a key: %d\n\n", k); //prints to console
        fprintf(output," Encrypt a rotation cipher using a key: %d\n\n", k); //prints to output file
        encrotciph(str, u, k, output); //including the relevant function needed for the case to run
        break;
        case 'b': 
        printf("Decrypt a rotation cipher using a key: %d\n\n", k); //prints to console
        fprintf(output, "Decrypt a rotation cipher using a key: %d\n\n", k); //prints to output file
        decrotciph(str, u, k, output); //including the relevant function needed for the case to run
        break;
        case 'c': 
        printf("Decrypt without a key: \n"); //prints to console
        fprintf(output, "Decrypt without a key: \n"); //prints to output file
        decencrotciph(str, u, output); //including the relevant function needed for the case to run  
        break;
        case 'd':
        printf("Encrypting a substitution cipher using a key: %s\n\n", alph); //prints to console
        fprintf(output, "Encrypting a substitution cipher using a key: %s\n\n", alph); //prints to output file
        encsubciph(str, u, alph, output); //including the relevant function needed for the case to run
        break;   
        case 'e':
        printf("Decrypt a substitution cipher using a key: %s\n\n", alph); //prints to console
        fprintf(output, "Decrypt a substitution cipher using a key: %s\n\n", alph); //prints to output file
        decsubciph(str, u, alph, output); //including the relevant function needed for the case to run
        break;
        default: //needs to include a default case if no other case has been chosen
        printf("Unknown option %c\n Please enter a, b, c, d, e, f\n", selec);
        fprintf(output, "Unknown option %c\n Please enter a, b, c, d, e, f\n", selec);
    } 
     return 0;
     
}


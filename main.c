#include <stdio.h>
    char opt(encrotciph, decrotciph, encsubciph, decsubciph, decenccrotciph, decencsubciph)//function prototypes for the switch case 
    char enc(int k);//function prototype for integers m and k
main(){
    char (encrotciph, decrotciph, encsubciph, decsubciph, decenccrotciph, decencsubciph); //declearing functions 
    char enc(int k); //declearing functions 
    int k = key;
    ex = (m + k)*(%26); //calculation to determine the encryption 
    char m;
    scanf("%c", m);
    m = m - 65;
    char i;
    printf("Please select and option: \n");
    printf("a) Encrypt a rotation cipher \n");
    printf("b) Decrypt a rotation cipher \n");
    printf("c) Encrypt a substitution cipher \n");
    printf("d) Decrypt a substitution cipher \n");
    printf("e) Decrypt a message encrypted with rotation cipher \n");
    printf("f) Decrypt a message ecrypted with substitution cipher \n");
    printf("Selection: \n");
    scanf("%c", i); 
    
    switch(i) {
        case 'a': encrotciph();
        break;
        case 'b': decrotciph();
        break;
        case 'c': encsubciph();
        break;
        case 'd': decsubciph;
        break;
        case 'e': decencrotciph;
        break;
        case 'f': decencsubciph;
        default: printf("Unknown option %c\n Please enter a, b, c, d, e, f\n", i);
    }  
    do {
        encrotciph();
        int k = key;
        printf("Enter a message \n");
        printf("Enter a key to the message \n");
        scanf("%d", &k); //stores the number of k
        char m; //first time initialised in this do while loop 
        ex = (m + k)*(%26);
        scanf("%c", m);
        m = m - 65//convert each letter of the alphabet to a number with the allocation A = 0 ... Z = 25
     while( m <'a'|| m > ); //this is wrong 
      e(x)= (m + k)(%26);
      printf()
 } 
    
 
 return 0;
}

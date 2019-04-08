#include <stdio.h>
/*
    int opt(char encrotciph, char decrotciph, char encsubciph, char decsubciph, char decenccrotciph, char decencsubciph)//function prototypes for the switch case 
    char enc(int k);//function prototype for integers m and k
*/
int main(){
/*
    char (encrotciph, decrotciph, encsubciph, decsubciph, decenccrotciph, decencsubciph); //declearing functions 
    char enc(int k); //declearing functions 
*/
    int k = 1;
    int u;
    char m;
    scanf("%c", &m);
    m = m - 65;
    char str[] = "georgia";
    u = sizeof(str)/sizeof(char);
    char ex[u];
    printf("%d\n", u); //shows the size of the array 
    printf("Please select and option: \n");
    printf("a) Encrypt a rotation cipher \n");
    printf("b) Decrypt a rotation cipher \n");
    printf("c) Encrypt a substitution cipher \n");
    printf("d) Decrypt a substitution cipher \n");
    printf("e) Decrypt a message encrypted with rotation cipher \n");
    printf("f) Decrypt a message ecrypted with substitution cipher \n");
    printf("Selection: \n");
 /*   
    switch(i) {
        case 'a': encrotciph();
        break;
        case 'b': decrotciph();
        break;
        case 'c': encsubciph();
        break;
        case 'd': decsubciph());
        break;
        case 'e': decencrotciph();
        break;
        case 'f': decencsubciph();
        default: printf("Unknown option %c\n Please enter a, b, c, d, e, f\n", i);
*/
    for (int g; g < u; g ++ ){
        str[g] = str[g] - 65;
        ex[u] = (k + str[g])%(26);
        ex[u] = ex[u] + 65;
        printf("%c", ex[u]);        
} 
 return 0;
}

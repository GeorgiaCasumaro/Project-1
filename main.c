#include <stdio.h>

void encrotciph(char n[], char enc[], int u, int k);
void decrotciph(char enc[], int u, int k);
//void encsubciph(char m[], int j, int kc);
void decsubciph();
void decencrotciph();
void decencsubciph();

void encrotciph(char n[], char enc[], int u, int k){
    for (int g = 0; g < u; g++){
        if(n[g] == ' '){
           enc[g] = ' ';
           continue;
        //need an if statement for getting the array to stop at the final number 
        }
        } 
  /*      else if(n[g] == '\0') break;
        if(n[g] < 90){
            enc[g] = n[g] - 32;
            continue;   */
        }
        n[g] = n[g] - 65;//takes the letter in array g into ASCII code numbers
        enc[g] = (k + n[g])%(26);//uses the key encrypte 
        enc[g] = enc[g] + 65;//takes the numbers and turns them back into letters 
    } 
     printf("%s\n", enc);//prints the ecnryption
}

void decrotciph(char enc[], int u, int k){
    for(int i = 0; i < u; i++){
         if(enc[i] == ' ') continue;
         enc[i] -= 65;
         if(enc[i] < 0) enc[i] += 26;
         enc[i] = (enc[i] - k) % 26;
         enc[i] += 65;
     }
     printf("%s\n", enc);
}

int main(){
    int k = 1;
    int u, j, q, xn, yn;
    char selec;
    char str[] = "ATTACK AT SUNRISE";
    char sti[] = "PLEASE GET MILK AT THE SHOPS";
    u = sizeof(str)/sizeof(str[0]);
    j = sizeof(sti)/sizeof(sti[0]);
    char ex[u];
    char alph[xn], char sub[yn];
    printf("%d\n", u); //shows the size of the array 
    printf("%d\n", j);
    printf("Please select and option: \n");
    printf("a) Encrypt a rotation cipher \n");
    printf("b) Decrypt a rotation cipher \n");
    printf("c) Encrypt a substitution cipher \n");
    printf("d) Decrypt a substitution cipher \n");
    printf("e) Decrypt a message encrypted with rotation cipher \n");
    printf("f) Decrypt a message ecrypted with substitution cipher \n");
    printf("Selection: \n");
    scanf(" %c", &selec); 
 switch(selec) {
        case 'a': encrotciph(str, ex, u, k);
        //break;
        case 'b': decrotciph(ex, u, k);
        break;
/*        case 'c': encsubciph();
        break;
        case 'd': decsubciph();
        break;
        case 'e': decencrotciph();
        break;
        case 'f': decencsubciph();*/
        default: printf("Unknown option %c\n Please enter a, b, c, d, e, f\n", selec);
    } 
    for(int m = 0; m < j; m++){
         if(q[m] == ' '){
             emc[m] = ' ';
             continue;
         } 
         else if (q[m] =='\0') break;
         int xn, yn;
         xn = ABCDEFGHIJKLMNOPQRSTUVWXYZ
         xn = xn - 65;
         yn = QWERTYUIOPASDFGHJKLZXCVBNM;
         yn = yn - 65;
         }
         q[m] = q[m] - 65;
         sub[yn] = alph[xn];
         emc[m] = alph[xn];
 }
    printf("%s\n", emc);

     return 0;
}

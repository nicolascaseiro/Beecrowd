#include <stdio.h>
#include <string.h>

int main() {
    
    char a[1000];
    scanf("%s",a);
    char *b = strstr(a,"13");
    if(b!=NULL) {
        
        printf("%s es de Mala Suerte\n",a);
    }
    else { 
        printf("%s NO es de Mala Suerte\n",a);
    }
    return 0;
}

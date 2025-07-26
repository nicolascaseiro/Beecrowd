#include <stdio.h>
 
int main() {
    
    char jon[1001], medico[1001];
    scanf("%s %s\n", &jon, &medico);
    
    int n1 = 0;
    int n2 = 0;
    
    for(int i = 0; ; i++) {
        if(jon[i] == 'a') {
            n1++;
        }
        
        else {
            break;    
        }
    }

    for(int i = 0; ; i++) {
        if(medico[i] == 'a') {
            n2++;
        }
        
        else {
            break;    
        }
    }
    
    if(n1 < n2) {
        printf("no\n");
    }
    
    else {
        printf("go\n");
    }
    
    return 0;
    
}

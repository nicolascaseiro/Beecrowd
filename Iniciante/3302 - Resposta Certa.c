#include <stdio.h>

int main(){
    
  int n, resposta;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", &resposta);
    printf("resposta %d: %d\n", i+1, resposta);
  }
  
  return 0;
}

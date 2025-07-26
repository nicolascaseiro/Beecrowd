#include <stdio.h>
#include <string.h>

int main()
{
  int n;
  scanf("%d",&n);
  int c = 0;
   while(n>0)
   {
     char a[1001];
     scanf("%s%*c",a);
     if(strstr(a,"CD")=='\0') c++;
       n--;
   }
   printf("%d\n",c);
   return 0;
}

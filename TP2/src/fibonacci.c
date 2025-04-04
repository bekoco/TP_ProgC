#include <stdio.h>
int main(){int n=7,a=0,b=1,c;
printf("%d",a);
for(int i=1;i<=n;i++){
printf(", %d",b);
c=a+b;a=b;b=c;}
return 0;}

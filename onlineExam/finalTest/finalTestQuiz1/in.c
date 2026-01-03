#include <stdio.h>
int main()
{
 int n,a,c1,c2,i;
 scanf("%d",&n);
 c1=c2=0;
 for ( i=0; i<n; i++ )
 {
  scanf("%d",&a);
  if ( a>=0 )
   c1++;
  else
   c2++;
 }
 printf("%d %d",&c1,&c2);
 return 0;
}
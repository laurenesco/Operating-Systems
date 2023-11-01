//----------------------------------------------------------
// Dr. Art Hanna
// Ackermann function, A(m,n), for (0 <= m <= 3), (0 <= n <= 11)
// Problem6.c
//----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int calls,depth,maxDepth;

//----------------------------------------------------------
int main()
//----------------------------------------------------------
{
   int A(const int m,const int n);

   for (int m = 0; m <= 3; m++)
   {
      for (int n = 0; n <= 11; n++)
      {
         int r;
         
         calls = 0;
         depth = 0; maxDepth = 0;
         r = A(m,n);
         printf("A(%2d,%2d) = %10d (%10d calls, maxDepth = %10d)\n",m,n,r,calls,maxDepth);
      }
   }
   system("PAUSE");
   return( 0 );
}

//----------------------------------------------------------
int A(const int m,const int n)
//----------------------------------------------------------
{
   int r;
   
   ++calls;
   ++depth;
   if ( depth > maxDepth ) maxDepth = depth;
   if       ( m == 0 )
      r = n+1;
   else  if ( (m > 0) && ( n == 0) )
      r = A(m-1,1);
   else//if ( (m > 0) && ( n > 0) )
      r = A(m-1,A(m,n-1));
   depth--;
   return( r );
}

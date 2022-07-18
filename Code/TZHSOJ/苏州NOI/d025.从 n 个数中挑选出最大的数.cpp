#include <iostream>
 
using namespace std;
 
int main()
{
   int n;
   cin >> n;
   int a[n-1];
   for(int i=0;i<=n-1;i++)
   {
      cin >> a[i];
   }
   int max = -1000;
   for(int i=0;i<=n-1;i++)
   {
      if(a[i]>=max)
      {
         max = a[i];
      }
      else
      {
         max = max;
      }
   }
   cout << max;
}
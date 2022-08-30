#include <iostream>
#include <cstring>
 
using namespace std;
 
int main()
{
   string a;
   cin >> a;
   int count,i;
   for(i=0;i<=a.length()-1;i++)
   {
      char letter = a[i];
      if(letter == 'a' || letter == 'A')
      {
         count++;
      }
       
      if(letter == '#')
      {
         break;
      }
   }
   cout << count;
}
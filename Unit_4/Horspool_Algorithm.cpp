#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;


class Horspool{
public:
     void horspool(char *text, char *pattern){
     int table[126];
     int n,i,k,j,m,flag=0;
     strcpy(t, text);
     strcpy(p, pattern);
     n=strlen(t);
     m=strlen(p);
     for(i=0;i<126;i++)
          table[i]=m;
     for(j=0;j<m-2;j++)
          table[p[j]]=m-1-j;
     i=m-1;
     while(i<=n-1){
          k=0;
          while(k<=m-1 && p[m-1-k]==t[i-k])
               k++;
          if(k==m){
               printf("The position of the pattern is %d\n",i-m+2);
               flag=1;
               break;
          }
          else
               i=i+table[t[i]];
     }
     if(!flag)
          printf("Pattern is not found in the given text ");
     }
private:
     char t[100],p[25];
};

int main()
{
     char text[12] = "Hello There";
     char pattern[10] = "The";
     Horspool A;
     A.horspool(text, pattern);
return 0;
}

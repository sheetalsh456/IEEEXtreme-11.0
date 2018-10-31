// Added solution to problem Rumour of IEEEXtreme-11.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double level(double x)
{
    return floor(log(x)/log(2));
}
int main() {
    long  long int q;
    double i,j;
    double a,b;
    cin>>q;
    while(q--)
    {
        
        
        cin>>a>>b;
        if(level(a)>level(b))
        {
            i = a; j =b;
            while(level(i)!=level(b))
            i=floor(i/2);
            while(i!=j)
            {
                i = floor(i/2);
                j = floor(j/2);
            }
            cout<<level(a)+level(b)-2*level(i)<<"\n";
        }
        else
        {
            i = b; j=a;
            while(level(i)!=level(a))
            i=floor(i/2);
            while(i!=j)
            {
                i = floor(i/2);
                j = floor(j/2);
               
            }
            cout<<level(a)+level(b)-2*level(i)<<"\n";
            
        }
        
    }
    return 0;
}

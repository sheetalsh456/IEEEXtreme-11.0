// Added solution of problem RecXor of IEEEXtreme-11.0

#include<bits/stdc++.h>
#include <iostream>

using namespace std;

long long f(long long a) 
{
     long long res[] = {a,1,a+1,0};
     return res[a%4];
}
int main() 
{
    long long t,n,d1,d2,l,h,i,small_col,temp_d1,xor_small,xor_big,xor_final,d1_col,d2_col;
    cin >> t;
    while(t--)
    {
        scanf("%lld%lld%lld%lld%lld",&l,&h,&n,&d1,&d2);
        xor_big=f(n-1)^f(n+(l*h)-1);
        if((d1-n+1)%l==0)
            d1_col=l;
        else
            d1_col=(d1-n+1)%l;
        if((d2-n+1)%l==0)
            d2_col=l;
        else
            d2_col=(d2-n+1)%l;
        if(d1_col > d2_col)
        {
            temp_d1=d1;
            for(i=d2;i>=d1;i-=l);
            d1=i;
            for(i=temp_d1;i<=d2;i+=l);
            d2=i;
        }
        for(i=d2;i>=d1;i-=l);
        i+=l;
        small_col=i-d1;
        xor_small=0;
        for(i=d1;i<=d2;i+=l)
        {
            xor_small=xor_small^(f(i-1)^f(i+small_col));
        }
        xor_final=xor_big^xor_small;
        printf("%lld\n",xor_final);
    }
    return 0;
}

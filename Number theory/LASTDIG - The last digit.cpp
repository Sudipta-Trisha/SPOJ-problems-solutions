#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll bigmod(ll a, ll b, ll m) {
    if (b == 0)
        return 1;
    ll res = bigmod(a, b / 2,m);
    if (b % 2)
        return (res * res * a)%m;
    else
        return (res * res)%m;
}
int main()
{
    ll test;
    cin>>test;
    while(test-- ){
        ll B,P;
        cin>>B>>P;
        cout<<bigmod(B,P,10)<<endl;
    }

	return 0;
}

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define sz 1000000009

ll phi_func(ll n)
{
    ll node = n;
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            node = node - (node/i);
        }
    }
    if(n>1){
        node = node - (node/n);
    }
    return node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll test;
    scanf("%lld",&test);
    while(test--){
        ll n;
        scanf("%lld",&n);
        if(n==0) printf("0\n");
        else if(n==1) printf("1\n");
        else printf("%lld\n",phi_func(n));
    }
    return 0;
}



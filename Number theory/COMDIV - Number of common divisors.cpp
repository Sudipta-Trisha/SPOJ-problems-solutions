#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    scanf("%d",&test);
    while(test--){
        ll a,b;
        scanf("%lld %lld",&a,&b);
        ll g = __gcd(a,b);
        ll cnt=0;
        for(ll i=1; i<=sqrt(g); i++){
            if(i*i==g) cnt++;
            else if(g%i==0) cnt+=2;
        }

        printf("%lld\n",cnt);
    }
    return 0;
}

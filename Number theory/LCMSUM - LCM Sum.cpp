/*To find the lcm sum from 1 to n..
Using this formula:
LCM_SUM = summation of ((d*ETF(d) + 1)*n)/2
Here, ETF(d) stands for the eluler's totient function of d where d is the divisors of n.

if the number is 5, then the lcm sum will be,
LCM_SUM = ((1*ETF(1) + 5*ETf(5) + 1)*5)/2
Here, 1 & 5 are the divisors of 5.

***Source--- GeeksforGeeks***
I have learned the ETF from CP-Algorithm.
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define sz 1000009

 vector<ll>phi(sz+1);
vector<ll>ans(sz+1);

void phi_func(ll n)
{
    phi[0] = 0;
    phi[1] = 1;

    for(ll i=2; i<=n; i++){
        phi[i] = i;
    }

    for(ll i=2; i<=n; i++){
        if(phi[i]==i){
            for(ll j=i; j<=n; j+=i){
                phi[j] = phi[j] - (phi[j]/i);
            }
        }
    }

    for(ll i=1; i<=n; i++){
        for(ll j=i; j<=n; j+=i){
            ans[j]  = ans[j] + (i*phi[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    phi_func(sz);

    ll test;
    scanf("%lld",&test);
    while(test--){
        ll num;
        scanf("%lld",&num);

        ll result = ans[num];
        result = (result+1)*num;
        result /= 2;

        printf("%lld\n",result);
    }
    return 0;
}



#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define sz 100000008

bitset<sz>b;
vector<ll>primes;

ll power(ll x, ll y)
{
    ll temp=1;
    if(y==0)
        return 1;
    else if(y==1)
        return x;
    while(y--){
        temp = temp * x;
    }
    return temp;
}

void factorization (ll n)
{
   if(n==2) printf("1\n");
   else if(n==1) printf("0\n");
   else{
  ll node = n;
  ll ans=1;

  for(ll i=0; i<primes.size()&& i*i<n; i++){
    ll cnt=0;
    ll x = primes[i];
   if(n%x==0){
      cnt=0;
    while(n%x==0){
      cnt++;
      n/=x;
    }
        ans*= (power(primes[i],(cnt+1))-1)/(primes[i]-1);
       }

  }
  if(n>1){
     ans = ans * (n+1);
  }
  printf("%lld\n",ans-node);
   }
}

void sieve()
{
    b.set();
    b[0] = b[1] = 0;
    primes.push_back(2);

    for(ll i=3; i<=sz+1; i+=2){
        if(b[i]){
            for(ll j=i*i; j<=sz+1; j+=i){
                b[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  sieve();
  ll test;
  scanf("%lld",&test);
  while(test--){
    ll n;
    scanf("%lld",&n);
    factorization(n);
  }
  return 0;
}

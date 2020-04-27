#include<bits/stdc++.h>
#define ll long long int
#define MAX 32000
using namespace std;
vector<int>primes;

void sieve()
{
	bool isprime[MAX];
	for(int i=0; i<MAX; i++)
		isprime[i] = true;
	for(int i=3; i*i<=MAX; i+=2)  {
		if(isprime[i]){
			for(int j=i*i; j<=MAX; j+=i){
				isprime[j] = false;
			}
		}
	}
	primes.push_back(2);
	for(int i=3; i<MAX; i+=2) {
		if(isprime[i]){
			primes.push_back(i);
		}
	}
}

void segSieve(ll l,ll r){
	bool isprime[r-l+1];
	for(ll i=0; i<r-l+1; i++){
		isprime[i] = true;
	}
	if(l==1) isprime[0] = false;
	for(ll i=0; primes[i]*primes[i]<=r; i++){
		ll current_prime = primes[i];
		ll temp = (l/current_prime)*current_prime;
		if(temp<l)
			temp += current_prime;
		for(ll j=temp; j<=r; j+=current_prime){
			isprime[j-l] = false;
		}
		if(temp==current_prime)
			isprime[temp-l] = true;
	}
	for(ll i=0; i<r-l+1; i++){
		if(isprime[i]){
				cout<< (i+l) <<endl;
			}
	}
	puts("");
}
int main()
{
	sieve();
	int test;
	cin>>test;
	while(test--){
		ll l,r;
		cin>>l>>r;
		segSieve(l,r);
	}	
    
    return 0;
}


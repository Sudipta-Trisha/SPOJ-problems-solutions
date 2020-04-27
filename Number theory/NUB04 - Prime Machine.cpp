#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n;
	while(cin>>n)
	{
		ll cnt=0;
		for(int i=2; i<=sqrt(n); i++)
		{
			if(n%i==0){
				cnt=1;
				break;
			}
		}
		if(n==1)
			cout<<"NO"<<endl;
		else if(cnt==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;

}

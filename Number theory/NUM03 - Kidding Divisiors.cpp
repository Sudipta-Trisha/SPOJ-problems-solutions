#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll test;
	cin>>test;
	ll cnt=0;
	while(test--){
		ll n;
		cin>>n;
		vector<ll>v;
		 
		for(int i=1; i<=sqrt(n); i++){
				if(n%i==0){
					v.push_back(i);
					
			
					if(i!=n/i)
						v.push_back(n/i);
					}
				
		}
		sort(v.begin(),v.end());
		printf("Case %lld:",++cnt);
		for(int i=0; i<v.size(); i++){
			cout<<" "<<v[i];
		}
		cout<<endl;
		if(test)
			cout<<endl;
		v.clear();
	}
	return 0;			

}

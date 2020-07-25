#include<bits/stdc++.h>
#define maxC 1000
using namespace std;
int dp[maxC][maxC];

int lcs(string s1, string s2,int m, int n)
{
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m][n];
}

int main()
{
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    string s1,s2;
    
    while(cin >> s1 >> s2){

       int m = s1.length();
       int n = s2.length();
       
       int length = lcs(s1,s2,m,n);
       cout << length << endl;
    }
    return 0;
}




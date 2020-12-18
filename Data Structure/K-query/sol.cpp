
/**
 *    author        : Sudipta Banik Trisha 
 *    created       : December 17, 2020 1:32 PM
 *    Problem Name  : K-query
 *    Problem Limit : 1000 ms , 1536 MB
 *    Problem Url   : https://www.spoj.com/problems/KQUERY/
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MAX 30001

ll v[30001];
vector<ll>tree[4*30001];

void merge(vector<ll> &left, vector<ll> &right, vector<ll> &node)
{
    int i=0,j=0;

    while(i < left.size() && j < right.size()){
        if(left[i] > right[j]) {
            node.push_back(right[j]);
            j++;
        }

        else{
            node.push_back(left[i]);
            i++;
        }
    }

    while(i < left.size()) {
        node.push_back(left[i]);
        i++;
    }

     while(j < right.size()) {
        node.push_back(right[j]);
        j++;
    }
}

void build_tree(ll node,ll beg, ll end)
{
    if(beg == end){
        tree[node].push_back(v[beg]);
        return;
    }

    ll mid = (beg+end)/2;
    ll left = 2*node;
    ll right = (2*node) + 1;

    build_tree(left,beg,mid); // left subtree
    build_tree(right,mid+1,end); // right subtree

    merge(tree[left],tree[right],tree[node]); //merging left and right subtree    
}

ll query(ll node, ll beg, ll end, ll l,ll r, ll k)
{
    if(beg > r || end < l ){
        return 0; // out of range
    }

    if( beg >= l && end <= r){
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(),k);
    }

    ll mid = (beg+end)/2;
    ll left = 2*node;
    ll right = 2*node+1;
    return query(left,beg,mid,l,r,k) + query(right,mid+1,end,l,r,k);
}

int main(){
    ios_base::sync_with_stdio(false);
    
    ll n,q,l,r,k;
    cin >> n;

    for(ll i=1; i<=n; i++){
        cin >> v[i];
    }
    build_tree(1,1,n);

    cin >> q;
    while(q--){
        cin >> l >> r >> k;
        cout << query(1,1,n,l,r,k) << endl;
    }

    return 0 ;
}

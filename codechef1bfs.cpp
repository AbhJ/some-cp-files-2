#include <bits/stdc++.h>
#define ll long long int
#define N 100000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
    // ll n[1001],r[1001];
    // double a[1001],p[1001];
int a[100][100];
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti;
    int t,n,m,q,x,y;
    cin>>t;
    while(t--){
    	int odd=0;
    	cin>>n>>m>>q;
    	while(q--){
    		cin>>x>>y;
    		for (int i = 1; i <=n; ++i)
    		{
    			a[i][y]++;
    		}
    		for (int i = 1; i <=m; ++i)
    		{
    			a[x][i]++;
    		}
    	}
    	for (int i = 1; i <=n; ++i) 
	    { 
	        for (int j = 1; j <=m; ++j) 
	        { 
	            // modulo by 2 to check 
	            // even and odd 
	            if (a[i][j] % 2) 
	      
	                ++odd; 
	        } 
	        
	    } 
    	cout<<odd<<"\n";
    }

    
    return 0;
}
//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,l[N],k[N],r[N],ans;vpii f,b;
void F(vpii a){
	priority_queue<int>q;
	for(auto i:a){
		q.push(-i.S);
		ans+=i.S;
		//we assume its left is best
		while(q.size()>i.F)ans+=q.top(),q.pop();
		//we take the rights for them
	}
}
void solve(){
	cin>>n;ans=0;f.clear(),b.clear();
	rep(i,1,n)cin>>k[i]>>l[i]>>r[i];
	rep(i,1,n){
		if(l[i]>r[i]){
			ans+=r[i];
			f.pb({k[i],l[i]-r[i]});
		}
		else{
			ans+=l[i];
			b.pb({n-k[i],r[i]-l[i]});
		}
	}
	sort(all(f)),sort(all(b));
	F(f),F(b);cout<<ans;
}
int32_t main()
{
  ibs;cti;
  // solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
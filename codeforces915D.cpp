//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 04 in 16 : 57 : 22
//title - D_Almost_Acyclic_Graph.cpp
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
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec "<<endl;
#define deb(x) cout<<endl<<"["<<#x<<" = "<<x<<"]"<<endl;
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
int n, m, x[N], y[N];vi a[N];
int dp[505][505];
bool dfs(int curr, set<int>&wSet, set<int>&gSet, set<int>&bSet) {
   //moving curr to white set to grey set.
   wSet.erase(wSet.find(curr));
   gSet.insert(curr);

   for(int v = 1; v <= n; v++) {
      if(dp[curr][v] != 0) {    //for all neighbour vertices
         if(bSet.find(v) != bSet.end())
            continue;    //if the vertices are in the black set
         if(gSet.find(v) != gSet.end())
            return true;    //it is a cycle
         if(dfs(v, wSet, gSet, bSet))
            return true;    //cycle found
      }
   }

   //moving v to grey set to black set.
   gSet.erase(gSet.find(curr));
   bSet.insert(curr);
   return false;
}

bool f() {
   set<int> wSet, gSet, bSet;    //three set as white, grey and black
   for(int i = 1; i<= n; i++)
      wSet.insert(i);    //initially add all node into the white set

   while(wSet.size() > 0) {
      for(int current = 1; current <= n; current++) {
         if(wSet.find(current) != wSet.end())
            if(dfs(current, wSet, gSet, bSet))
               return false;
      }
   }
   return true;
}
queue<int>que;
int indeg[505],indeg1[505];
int u,v,flag;
bool temp;
bool g(){
    while(!que.empty())
        que.pop();
    for(int i=1;i<=n;i++)
    {
        if(!indeg[i])
            que.push(i);
    }
    int now,num=0;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        num++;
        for(int i=0;i<a[now].size();i++)
        {
            if(--indeg[a[now][i]]==0)
                que.push(a[now][i]);
        }
    }
    if(num==n)
        return true;
    return false;
}
void solve(){
	//number of cycles may not be 1
	//remove edges one by one only those in cycle and one way
	cin >> n >> m;
	rep(i, 1, m){
		cin >> x[i] >> y[i];
		dp[x[i]][y[i]] = 1;
		a[x[i]].pb(y[i]);
		indeg1[y[i]]++;
		indeg[y[i]]++;
	}
	if(f()){
		cout << "YES";
		return;
	}
	rep(i, 1, n){
		rep(j, 1, n)indeg[j] = indeg1[j];
		indeg[i]--;
		if(g()){
			cout << "YES";
			return;
		}
		que = queue<int>();
	}
	cout << "NO";
	return;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}
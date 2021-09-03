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
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
#define deb(x) cout<<"\n["<<#x<<" = "<<x<<"]\n";
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
 int n;vector<vector<string>>ans;
 int f(int x,int y,vector<string>v){
        rep(j,0,y-1)
            rep(i,0,n-1)
                if(v[i][j]=='Q' and ((i-j)==(x-y) or ((i+j)==(x+y)) or (i==x)))
                    return 0;
        return 1;
    }
    int dfs(int j,vector<string>v){
        int ok=0;
        if(j==n){
            ans.push_back(v);
            return 1;
        }
        for(int i=0;i<n;i++){
            if(f(i,j,v)){
                v[i][j]='Q';
                ok|=dfs(j+1,v);
                v[i][j]='-';
            }
        }
        return ok;
    }
    vector<vector<string>> solveNQueens(int n) {
        auto v=vector<string>(n,string(n,'-'));
        ans.clear();
        dfs(0,v);
        return ans;
    }
void solve(){
  cin>>n;
  auto v=solveNQueens(n);
  if(solveNQueens(n).empty()==1){cout<<"Not Possible";return;}
  sort(all(v));
  reverse(all(v));
  for(auto V:v){
    rep(i,0,n-1){
      rep(j,0,n-1){
        cout<<V[i][j]<<"\t";
      }
      cout<<"\n";
    }
    cout<<"\n";
  }
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  ;int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
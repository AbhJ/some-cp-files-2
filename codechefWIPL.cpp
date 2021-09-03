//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 01 in 16 : 23 : 07
//title - codechefWIPL.cpp
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
const int N=4e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, k, dp[N][N], h[N];
void solve(){
    cin >> n >> k;
    rep(i, 1, n)cin >> h[i];
    sort(h + 1, h + 1 + n);
    reverse(h + 1, h + 1 + n);
    int sum = 0;
    int ans = inf;
    rep(i, 0, N - 1)rep(j, 0, N - 1)dp[i][j] = inf;
    dp[0][0] = 0;
    if(h[1] >= k and n > 1 and h[2] >= k){
        cout << 2;
        return;
    }
    rep(i, 1, n){
        sum += h[i];
        rep(left, 0, min(N - 1, sum)){
            int right = sum - left;
            if(left > h[i] - 1)dp[left][i] = min(dp[left][i], 1 + dp[left - h[i]][i - 1]);
            dp[left][i] = min(dp[left][i], 1 + dp[left][i - 1]);
            if(left >= k and right >= k)ans = min(ans, dp[left][i]);
        }
    }
    if(ans == inf or ans < 2){
        cout << - 1;
        return;
    }
    cout << ans;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}
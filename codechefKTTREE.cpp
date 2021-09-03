//Coded by Abhijay Mitra (AbJ) on 2020 / 12 / 27 in 17 : 39 : 10
//title - codechefKTTREE.cpp
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
#include <bits/stdc++.h>
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
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, k, a[N], c[N], freq[N][20], dp[N][400], name_of_com[N];vvi A;
int parent[N], ind[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = rand();
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
    }
}
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
void solve(){
    cin >> n >> k;
    rep(i, 1, n)cin >> a[i], make_set(i), c[i] = 0, name_of_com[i] = 0;
    rep(i, 1, n)rep(j, 1, k)freq[i][j] = 0;
    rep(i, 1, n)rep(j, 0, 399)dp[i][j] = 0;
    rep(i, 1, n - 1){
        int x, y;
        cin >> x >> y;
        if(a[x] != 0 and a[y] != 0){
            union_sets(x, y);
        }
    }
    unordered_set<int>s;
    rep(i, 1, n)if(a[i] != 0){
        c[i] = find_set(i);
        if(s.count(c[i]) == 0)name_of_com[c[i]] = s.size() + 1;
        s.insert(c[i]);
    }
    rep(i, 1, n)if(a[i] != 0){
        freq[name_of_com[c[i]]][a[i]]++;
    }
    dp[0][0] = 1;
    rep(i, 1, s.size()){
        rep(mas, 0, (1 << k) - 1)dp[i][mas] = dp[i - 1][mas];
        rep(col, 0, k - 1){
            if(freq[i][col + 1] == 0)continue;
            rep(mas, 0, (1 << k) - 1)if((mas & (1 << col)) != 0){
                dp[i][mas] = add(dp[i][mas], mul(dp[i - 1][mas - (1 << col)], freq[i][col + 1]));
            }
        }
    }
    cout << dp[s.size()][(1 << k) - 1];
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}
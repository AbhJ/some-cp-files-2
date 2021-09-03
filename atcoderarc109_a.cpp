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
int a, x, y, b;
map<pii, int> m;
int f(){
  //less take more close to b
  priority_queue<vi>p;
  p.push(vi{0, -abs(a - b), a, 0});
  int k = 0;
  int ans = inf;
  while(p.empty() == 0 and ++k < 6e8){
    vi v = p.top();
    p.pop();
    int taka = - v[0], a = v[2], ty = v[3];
    if(m.count(mp(a, ty)) == 1)continue;
    m[mp(a, ty)] = taka;
    if(ty == 0){
      if(b < a)p.push(vi{-(taka + x), -abs(a - 1 - b), a - 1, 1});
      p.push(vi{-(taka + x), -abs(a - b), a, 1});
      if(b != a)p.push(vi{-(taka + y), -abs(a - 1 - b), a + ((b > a) ? 1 : - 1), 0});
    }
    else{
      if(b > a)p.push(vi{-(taka + x), -abs(a + 1 - b), a + 1, 0});
      p.push(vi{-(taka + x), -abs(a - b), a, 0});
      if(b != a)p.push(vi{-(taka + y), -abs(a - 1 - b), a + ((b > a) ? 1 : - 1), 1});
    }
  }
  return m[mp(b, 1)];
}
void solve(){
  cin >> a >> b >> x >> y;
  m.clear();
  cout << f();
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}
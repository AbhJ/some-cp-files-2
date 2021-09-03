//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 02 in 09 : 22 : 57
//title - D_Mahmoud_and_Ehab_and_another_array_construction_task.cpp
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
// const double Pi = M_PI;
#define F first
#define S second
int a[N], p[N], n, F, sp[N];set<int>s;
void gen_primes() {
  for(int i=0;i<N;i++){
    p[i]=true;
  }
  p[0]=false;
  p[1]=false;
  for(int j=2;j*j<N;j++){
    if(p[j]){
      for(int i=j*j;i<N;i+=j){
        p[i]=false;
      }
    }
  }
  for(int i=2;i< N;i++)
   {
        if(sp[i] == 0)
        {
            for(int j=i;j< N;j+=i)
            {
                sp[j] = i;
            }
        }
    }
}
void er(int v){
	if(s.count(v) == 0)
		return;
	rep(i, 1, N - 1){
		if(i * v > N - 1)
			break;
		s.erase(i * v);
	}
}
void pri(int x){
	int p = sp[x];
	int y = x;
	while(p){
		while(y % p == 0)
			y /= p;
		er(p);
		p = sp[y];
	}
}
void solve(){
	cin >> n;
	rep(i, 1, n)
		cin >> a[i];
	rep(i, 2, N - 1)
		s.insert(i);
	rep(i, 1, n){
		if(F == 1){
			a[i] = *s.begin(),
			pri(a[i]);
			continue;
		}
		if(s.count(a[i]) == 1){
			pri(a[i]);
			continue;
		}
		a[i] = *s.upper_bound(a[i]);
		pri(a[i]);
		F = 1;
	}
	rep(i, 1, n)
		cout << a[i] << " ";
}
int32_t main()
{
  ibs;cti;
  gen_primes();
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}
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
#include <iomanip>
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
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n;
void f(int l,int r){
  if(l>r)return;
  int m=l+r>>1;
  cout<<m<<"\n";cout.flush();
  char n1,n2,n3;
  int d=0,u=0;
  cin>>n1;
  if(n1=='E')exit(0);
  if(n1=='L')d++;
  if(n1=='G')u++;
  cout<<m<<"\n";cout.flush();
  cin>>n2;
  if(n2=='E')exit(0);
  if(n2=='L')d++;
  if(n2=='G')u++;
  if(d==2){f(l,m-1);return;}
  if(u==2){f(m+1,r);return;}
  // f(l,m-1);f(m+1,r);
  cout<<m<<"\n";cout.flush();
  cin>>n3;
  if(n3=='E')exit(0);
  if(n3=='L')d++;
  if(n3=='G')u++;
  if(d==2){f(l,m-1);return;}
  if(u==2){f(m+1,r);return;}
  if(l==r)return;
}
void solve(){
  cin>>n;
  f(1,n);
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+10;
const ll M =  998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n,c=0;
    cin >> n;
  for(int i=0;i<n;i++){
    int x; cin >> x;
    if(x&1) c++;
  }
  cout << min(c,n - c);
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}
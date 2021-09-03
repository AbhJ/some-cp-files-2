//ulrich_nielsen on Codeforces
//I'll reveal my identity soon
//target CM
/* __ __  _      ____   ____   __  __ __      ____   ____    ___  _     _____   ___  ____       _____  ____   ___   ___ ___      ______  __ __    ___      ___      ___   ____  ___
  |  |  || |    |    \ |    | /  ]|  |  |    |    \ |    |  /  _]| |   / ___/  /  _]|    \     |     ||    \ /   \ |   |   |    |      ||  |  |  /  _]    |   \    /  _] /    ||   \
  |  |  || |    |  D  ) |  | /  / |  |  |    |  _  | |  |  /  [_ | |  (   \_  /  [_ |  _  |    |   __||  D  )     || _   _ |    |      ||  |  | /  [_     |    \  /  [_ |  o  ||    \
  |  |  || |___ |    /  |  |/  /  |  _  |    |  |  | |  | |    _]| |___\__  ||    _]|  |  |    |  |_  |    /|  O  ||  \_/  |    |_|  |_||  _  ||    _]    |  D  ||    _]|     ||  D  |
  |  :  ||     ||    \  |  /   \_ |  |  |    |  |  | |  | |   [_ |     /  \ ||   [_ |  |  |    |   _] |    \|     ||   |   |      |  |  |  |  ||   [_     |     ||   [_ |  _  ||     |
  |     ||     ||  .  \ |  \     ||  |  |    |  |  | |  | |     ||     \    ||     ||  |  |    |  |   |  .  \     ||   |   |      |  |  |  |  ||     |    |     ||     ||  |  ||     |
   \__,_||_____||__|\_||____\____||__|__|    |__|__||____||_____||_____|\___||_____||__|__|    |__|   |__|\_|\___/ |___|___|      |__|  |__|__||_____|    |_____||_____||__|__||_____|
*/
#include <bits/stdc++.h>
#define double long double
#define int long long int
#define per(i,b,a) for (int i = b; i >= a; i--)
#define pb emplace_back
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
using vi = std::vector<int>;
using vvi = std::vector<vi>;
#define all(x)     x.begin(), x.end()
using pii = std::pair<int,int>;
#define S second
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define F first
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
#define ll int
const int inf = 1e18+10;
// const ll M = 998244353;
const int M = 1e9+7;
const int N = 4e6+10;
int a[N], n, ans = 1;map<int, int>m;
int f[N],b[N];
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
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
void calc_fact(){
  f[0]=b[0]=1;
  rep(i,1,N-1){
    f[i]=mul(f[i-1],i);
    b[i]=powM(f[i],M-2);
  }
}
int C(int n,int r){
  assert(n<N);assert(r<N);
  if(r>n)return 0;
  return (f[n]*mul(b[r],b[n-r])%M)%M;
}
void solve(){
	cin >> n;m.clear();
	rep(i, 1, n)
		cin >> a[i],
		m[a[i]]++;
	m[0] = 0;
	// for(auto i = next(m.rbegin()); i != m.rend(); i = next(i))
	// 	(*i).S += (*(prev(i))).S;
	for(auto i = next(m.begin()); i != m.end(); i = next(i))
		ans = mul(ans, mul(1LL, i -> F - prev(i) -> F + 1));
	cout << ans;
	ans = 1;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
//   cin>>t;
  while(t--){
	  solve();
	  cout<<"\n";
  }
  return 0;
}
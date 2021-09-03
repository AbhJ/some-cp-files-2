#include <bits/stdc++.h>
#define ll long long int
#define N 100000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
    // ll n[1001],r[1001];
    // double a[1001],p[1001];
ll r[N],c[N];
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti;
    ll t,n,m,q,x,y;
    cin>>t;
    while(t--){
        ll reven,rodd,ceven,codd=0;
        reven=rodd=ceven=codd=0;
        cin>>n>>m>>q;
        for (ll i = 1; i <= n; ++i)
        {
            r[i]=0;
        }
        for (ll i = 1; i <= m; ++i)
        {
            c[i]=0;
        }
        while(q--){
            cin>>x>>y;
            r[x]++;
            c[y]++;
        }
        for (ll j = 1; j <= n; ++j) 
            { 
                // modulo by 2 to check 
                // even and odd 
                if (r[j] % 2) 
          
                    ++rodd;
            }
        reven=n-rodd;
        // cout<<reven<<rodd;
        for (ll j = 1; j <= m; ++j) 
            { 
                // modulo by 2 to check 
                // even and odd 
                if (c[j] % 2) 
          
                    ++codd;
            }
        ceven=m-codd;
        // cout<<ceven<<codd;
        ll odd=ceven*rodd+codd*reven;
        cout<<odd<<"\n";
        
    }

    
    return 0;
}
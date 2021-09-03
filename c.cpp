#include <bits/stdc++.h>
#define ll long long
const ll kk=1e12;
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,m,x;
        cin>>n>>m>>x;

        for(ll i=0;i<m;i++)
        pq.push({0,i+1});
        vector<pair<ll,ll>> a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i;
        }
        ll ans[n];
        sort(a.begin(),a.end());
        for(ll i=n-1;i>=0;i--){
            pair<ll,ll> p=pq.top();
            pq.pop();
            ans[a[i].second]=p.second;
            p.first+=a[i].first;
            pq.push(p);

        }
        ll maxx=0,minn=kk;
        for(ll i=0;i<m;i++){
            pair<ll,ll> p=pq.top();
            pq.pop();
            maxx=max(maxx,p.first);
            minn=min(minn,p.first);

        }
        if(maxx-minn<=x){
            cout<<"YES"<<endl;
            for(ll i=0;i<n;i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}

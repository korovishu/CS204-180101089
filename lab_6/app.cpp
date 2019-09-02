#include <bits/stdc++.h>
#define ll long long
#define f(i, a, b) for(ll i=a; i<b; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    int a[n+1]={};
    ll max=0;
    ll t;cin>>t;
    while(t--)
    {
        int o;cin>>o;
        if(o==1)
        {
            int u,r; cin>>u>>r;
            a[u]+=r;
            if(a[u]>a[max]) max=u;
        }
        if(o==2)
        {
            if(a[max]!=0) cout<<max<<endl;
            else cout<<"NO data available.\n";
        }
    }
}

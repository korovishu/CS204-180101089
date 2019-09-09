#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for (ll i = a; i < b; i++)
using namespace std;

void sortab(string a[], string b[], int n)
{
	pair <string, string> v[n];
	f(i,0,n)
	{
		v[i].first = a[i];
		v[i].second = b[i];
	}
	sort(v,v+n);
	f(i,0,n)
	{
		a[i]=v[i].first;
		b[i]=v[i].second;
	}
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n,maxl=0; cin>>n;
    	string a[n],b[n];
    	f(i,0,n)
    	{
    		cin>>a[i];
    		if(a[i].size()>maxl) maxl=a[i].size();
    	}
    	f(i,0,n)
    	{
    		b[i]=a[i];
    		while(b[i].size() <= maxl+1) b[i]+=b[i];
    		b[i]=b[i].substr(0,maxl+1);
    	}
    	sortab(b,a,n);
    	reverse(a,a+n);
    	f(i,0,n) cout<<a[i];
    	cout<<endl;
    }
    return 0;
}

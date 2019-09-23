#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll partition(ll arr[], ll l, ll r, ll k); 
  
ll findMedian(ll arr[], ll n) 
{ 
    sort(arr, arr+n);   
    return arr[n/2];   
} 
  
ll kthSmallest(ll arr[], ll l, ll r, ll k) 
{ 
    
    if (k > 0 && k <= r - l + 1) 
    { 
        ll n = r-l+1; 
   
        ll i,median[(n+4)/5]; 
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n)  
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
   
        ll medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
   
        ll pos = partition(arr, l, r, medOfMed); 
  
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  
            return kthSmallest(arr, l, pos-1, k); 
  
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
    return INT_MAX; 
} 
  
void swapm(ll *a, ll *b) 
{ 
    ll temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
ll partition(ll arr[], ll l, ll r, ll x) 
{ 
    // Search for x in arr[l..r] and move it to end 
    ll i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swapm(&arr[i], &arr[r]); 
  
    // Standard partition algorithm 
    i = l; 
    for (ll j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swapm(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swapm(&arr[i], &arr[r]); 
    return i; 
} 

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll d[n];
        for(ll i=0; i<n; i++)
        {
            ll x,y; cin>>x>>y;
            ll t=(x*x+y*y);
            d[i]=t;
        }
        ll a=kthSmallest(d, 0, n-1, n/2);
        double sa=sqrt(a);
        ll b=kthSmallest(d, 0, n-1, (n+1)/2);
        double ba=sqrt(b);
        if(n%2==0) cout<<sa<<endl;
        else cout<<ba<<endl;
    }
}

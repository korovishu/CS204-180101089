#include <bits/stdc++.h>
using namespace std;
#define ll long long

int partition(int arr[], int l, int r, int k); 
  
int findMedian(int arr[], int n) 
{ 
    sort(arr, arr+n);   
    return arr[n/2];   
} 
  
int kthSmallest(int arr[], int l, int r, int k) 
{ 
    
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; 
   
        int i,median[(n+4)/5]; 
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n)  
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
   
        int medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
   
        int pos = partition(arr, l, r, medOfMed); 
  
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  
            return kthSmallest(arr, l, pos-1, k); 
  
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
    return INT_MAX; 
} 
  
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
int partition(int arr[], int l, int r, int x) 
{ 
    // Search for x in arr[l..r] and move it to end 
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  
    // Standard partition algorithm 
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int d[n];
        for(int i=0; i<n; i++)
        {
            int x,y; cin>>x>>y;
            int t=(x*x+y*y);
            d[i]=t;
        }
        int a=kthSmallest(d, 0, n-1, n/2);
        double sa=sqrt(a);
        int b=kthSmallest(d, 0, n-1, (n+1)/2);
        double ba=sqrt(b);
        if(n%2==0) cout<<sa<<endl;
        else cout<<ba<<endl;
    }
}

#include <bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for (ll i = a; i < b; i++)
using namespace std;

ll search(ll arr[], ll n, ll k){
    
    ll u = k;
    ll l = 0;
 
    
    while(u>=l){
        
        if(arr[(u+l)/2] == n){
            
            return (u+l)/2;
            
        } else if(arr[(u+l)/2] > n){
            
            u = (u+l)/2 - 1;
            
        } else {
            
            l = (u+l)/2 + 1;
            
        }
        
        
    }
    
    return -1;
    
    
}

int main(){

    int n,q;
    cin>>n>>q;
    ll x[q];
    ll y[q];
    ll z[q];
    ll w[q];
    ll k=0;
    REP(i,0,q){
        cin>>x[i];
        if(x[i]==1){
            cin>>y[i]>>z[i];
            w[k]=y[i];
            k++;
        }else{
            y[i]=-1;
            z[i]=-1;
        }
    }
    sort(w,w+k);
    ll users[k];

    users[0]=w[0];
    ll k2=1;
    REP(i,1,k){
        if(w[i]==w[i-1])continue;
        else{
            users[k2]=w[i];
            k2++;
        }
    }

    ll val[k2]={0};

    //REP(i,0,k2)cout<<users[i]<<endl;
    //sort(users, users+k2);
    ll max1=-1,maxindex=-1;
    REP(i,0,q){
        if(x[i]==1){
            ll temp=search(users,y[i],k2);
            //cout<<temp<<endl;
            val[temp]+=z[i];
            if(val[temp]>max1){
                max1=val[temp];
                maxindex=temp;
            }
        } else{
            if(maxindex==-1)cout<<"No data available."<<endl;
            else cout<<users[maxindex]<<endl;
        }
    }

}

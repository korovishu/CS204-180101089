#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        stack<char> box;
        box.push('0');
        int n=s.length();
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' || s[i]=='<')
            {
                box.push(s[i]);
            }
            
            if(s[i]==')')
            {
                if(box.top()=='(') box.pop();
                else {i=n; box.push('k');}
            }

            if(s[i]=='}')
            {
                if(box.top()=='{') box.pop();
                else {i=n; box.push('k');}
            }

            if(s[i]==']')
            {
                if(box.top()=='[') box.pop();
                else {i=n; box.push('k');}
            }

            if(s[i]=='>')
            {
                if(box.top()=='<') box.pop();
                else {i=n; box.push('k');}
            }
            if(s[i]=='|')
            {
                if(box.top()=='|') box.pop();
                else box.push('|');
            }
        }
        if(box.top()=='0') cout<<"YES\n";
        else cout<<"NO\n";
    }
}

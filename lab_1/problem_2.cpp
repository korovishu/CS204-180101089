#include <bits/stdc++.h>
using namespace std;
// SUBTRACTION
bool equal(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    if(n1!=n2) return false;
    for(int i=0; i<n1; i++)
    {
        if((s1[i]-'0')!=(s2[i]-'0')) return false;
    }
    return true;
}
bool small(string s1, string s2)
{
    int n1=s1.length(); int n2=s2.length();
    if(n1<n2) return true;
    if(n1>n2) return false;
    if(n1==n2)
    {
        for(int i=0; i<n1; i++)
        {
            if((s1[i]-'0')>(s2[i]-'0')) return false;
            if((s1[i]-'0')<(s2[i]-'0')) return true;
        }
        if(equal(s1, s2)) return false;
    }
}
int main() {
    string s1, s2, s3;
    cin >> s1 >> s2;
    // s1 is bigger.
    if(small(s1, s2)) swap(s1, s2);
    int c=0;
    int n1=s1.length(), n2=s2.length();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for(int i=0; i<n2; i++)
    {
        if((s1[i]-'0')>(s2[i]-'0'))
        {
            int sub = (s1[i]-'0') - (s2[i]-'0') - c;
            s3.push_back(sub + '0');
            c=0;
        }else if((s1[i]-'0')<(s2[i]-'0'))
        {
            int sub = (s1[i]-'0') - (s2[i]-'0') - c + 10;
            s3.push_back(sub + '0');
            c=1;
        }else{
            s3.push_back('0');
            c=0;
        }
    }
     for (int i=n2; i<n1; i++) 
    { 
        int sub = ((s1[i]-'0') - c); 
          
        // if the sub value is -ve, then make it positive 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            c = 1; 
        } 
        else
            c = 0; 
              
        s3.push_back(sub + '0'); 
    } 
     for(int i=s3.length()-1; i>=1; i--)
    {
        if(s3[i]=='0') s3.pop_back();
        else break;
    }
    reverse(s3.begin(), s3.end());
    cout << s3;
}

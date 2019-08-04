#include <bits/stdc++.h>
using namespace std;
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
string diff(string s1, string s2)
{
    string s3;
    // s1 is bigger.
    if(small(s1, s2)) swap(s1, s2);
    int c=0;
    int n1=s1.length(), n2=s2.length();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for(int i=0; i<n2; i++)
    {
        if((s1[i]-'0')-c>(s2[i]-'0'))
        {
            int sub = (s1[i]-'0') - (s2[i]-'0') - c;
            s3.push_back(sub + '0');
            c=0;
        }else if((s1[i]-'0')-c<(s2[i]-'0'))
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
        c=0;      
        s3.push_back(sub + '0'); 
    } 
    if(s3.length()!=1)
    {
        for(int i=s3.length()-1; i>=1; i--)
        {
            if(s3[i]=='0') s3.pop_back();
            else break;
        }
    }    
    reverse(s3.begin(), s3.end());
    return s3;
}


string add(string s1, string s2)
{
    string s3;
    int n1, n2;
    if (s1.length() > s2.length()) swap(s1, s2);
    n1=s1.length();
    n2=s2.length();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int c=0;
    for(int i=0; i<n1; i++)
    {
        int sum = (s1[i]-'0') + (s2[i]-'0') + c;
        s3.push_back(sum%10 + '0');
        c=sum/10;
    }
    for(int i=n1; i<n2; i++)
    {
        int sum = (s2[i] - '0') + c;
         s3.push_back(sum%10 + '0');
         c=sum/10;
    }
    if(c!=0) s3.push_back(c + '0');
    reverse(s3.begin(), s3.end());
    return s3;
}
int main() {
     int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {    
    string s1, s2, q, r, y;
    q="0";
    cin >> s1 >> s2;
    int n2 = s2.length();
    string s=s1;
    while(small(s2, s) || equal(s, s2))
    {
        string ts2 = s2;
            int n1 = s.size();
            y = "1";
            for(int i=0; i<n1-n2; i++)
            {
                ts2.push_back('0');
                y.push_back('0');
            }
            if(small(s, ts2))
            {
                ts2.pop_back();
                y.pop_back();
            }
            q = add(q, y);
            s = diff(s, ts2);
    }
    r = s;
    cout << q << "\n" << r << endl;
    }    
}

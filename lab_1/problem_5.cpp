#include <bits/stdc++.h>
using namespace std;
string mwod(string s1, int n)
{
    int c=0;
     reverse(s1.begin(), s1.end());
     string s;
     int n1=s1.length();
     for (int i=0; i<n1; i++)
     {
         int mul = (s1[i] - '0')*n + c;
         s.push_back(mul%10 + '0');
         c = mul/10;
     }
     if(c!=0) s.push_back(c + '0');
     reverse(s.begin(), s.end());
     return s;
}
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
            if((s1[i]-'0')>=(s2[i]-'0')) return false;
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
string rmndr(string s1, string s2)
{
    string q, r;
    q="0";
    int n2 = s2.length();
    while(small(s2, s1) || equal(s1, s2))
    {
        string s = s2;
        int n1 = s1.length();
        for(int i=0; i<n1-n2; i++)
        {
            s = s + "0";
        }
        if(small(s1, s)) 
        {
            s.pop_back();
            long long t = pow(10, n1-n2-1);
            string qs = to_string(t);
            q = add(q, qs);
        }
        else 
        {
            long long t = pow(10, n1-n2);
            string qs = to_string(t);
            q = add(q, qs);
        }
        s1 = diff(s1, s);
    }
    r = s1;
    return r;
}
string mul(string s1, string s2)
{
    string s3;
    s3 = "0";
    int n2 = s2.length();
    reverse(s2.begin(), s2.end());
    for(int i=0; i<n2; i++)
    {
        string s = mwod(s1, (s2[i] - '0'));
        for(int j=0; j<i; j++)
        {
            s = s + "0";
        }
        s3 = add(s3, s);
    }
    return s3;
}
int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {    
    string s;
    cin >> s;
    if(s =="0" || s =="1") cout << "Not a Prime";
    if(s == "2" || s == "3") cout << "Prime";    
    else if(rmndr(s, "2") == "0" || rmndr(s, "3")=="0") cout << "Not a Prime";
    else{
        string i = "5";
        while(small(mul(i, i), s))
        {
            if(rmndr(s, i)=="0" || rmndr(s, add(i, "2"))=="0")
            {
                cout << "Not a Prime";
                break;
            }
            i = add(i, "6");
        }
        if(!small(mul(i, i), s)) cout << "Prime";
    }
        cout<<endl;
    }    
}

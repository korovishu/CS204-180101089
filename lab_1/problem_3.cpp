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
string add(string s1, string s2)
{
    int n1, n2;
    string s3;
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
    string s1, s2, s3;
    cin >> s1 >> s2;
    s3 = '0';
    int n2 = s2.length();
    reverse(s2.begin(), s2.end());
    for(int i=0; i<n2; i++)
    {
        string s = mwod(s1, (s2[i] - '0'));
        for(int j=0; j<i; j++)
        {
            s.push_back('0');
        }
        s3 = add(s3, s);
    }
    reverse(s3.begin(), s3.end());
    for(int i=s3.length()-1; i>=1; i--)
    {
        if(s3[i]=='0') s3.pop_back();
        else break;
    }
    reverse(s3.begin(), s3.end());
    cout << s3 << endl;
    }
}

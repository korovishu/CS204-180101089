#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {    
    string s1, s2, s3;
    cin >> s1 >> s2;
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
    cout << s3 << endl;
    }    
}

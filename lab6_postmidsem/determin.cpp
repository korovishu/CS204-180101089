#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<string> a, b;
	string s;

	for (int i=0; i<n; i++)
	{
		cin >> s;
		string ar = s;
		reverse(ar.begin(), ar.end());
		if (s!=ar) {
			a.push_back(s);
			b.push_back(ar);
		}
	}

	sort(a.begin(), a.end());

	for (auto str: b)
	{
		if (binary_search(a.begin(), a.end(), str))
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}

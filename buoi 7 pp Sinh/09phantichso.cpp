#include<bits/stdc++.h>

using namespace std;

int n, cnt, a[100], ok;
void ktao()
{
	cnt = 1;
	a[1] = n;
}
void next()
{
	int i = cnt;
	while(i >= 1&& a[i] == 1) --i;
	if(i == 0) ok = 0;
	else
	{
		a[i]--;
		int d = cnt - i + 1;
		cnt = i;
		int q = d/a[i];
		int r = d%a[i];
		if(q)
		{
			for(int j = 1; j <= q; ++j)
			{
				a[++cnt] = a[i];
			}
		}
		if(r)
		{
			a[++cnt] = r;
		}
	}
}
int main()
{
	int t; cin >>t;
	while(t--)
	{
		cin >> n;
		ok = 1;
		ktao();
		while(ok)
		{
			cout << "(";
			for(int i = 1; i <= cnt; ++i)
			{
				cout << a[i];
				if(i != cnt) cout <<" ";
			}
			cout <<") ";
			next();
		}
		cout <<endl;
	}
	return 0;
}


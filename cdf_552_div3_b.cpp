#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("inputf.in",  "r",   stdin);
	freopen("outputf.in", "w",  stdout);
	#endif
	FastIO
	lld n, i;
	cin >> n;
	lld A[n];
	lld B[2];
	lld C[3];
	set <lld> restore;
	foi(i, n)
	{
		cin >> A[i];
		restore.insert(A[i]);
	}
		sort(A,A+n);
	if (restore.size()  <=  3)
	{
		if (restore.size() == 1)
			cout << "0\n";
		if (restore.size() == 2)
		{
			lld j = 0;
			for(set <lld> :: iterator pos = restore.begin(); pos != restore.end(); pos++)
			{
				B[j] = *pos;
				j++;
			}
			if ((B[1]-B[0])%2 == 0)
				cout << ((B[1]-B[0])/2) << "\n";
			else
				cout << (B[1]-B[0]) << "\n";
		}
		if (restore.size() == 3)
		{
			lld j = 0;
			for(set <lld> :: iterator pos = restore.begin(); pos != restore.end(); pos++)
			{
				C[j] = *pos;
				j++;
			}
			if ((C[0]+C[2])%2 == 0 && (C[0]+C[2])/2 == C[1])
				cout << (C[1]-C[0]) << "\n";
			else
				cout << "-1" << "\n";
		}
	}
	else
		cout << "-1" << "\n";
	return 0;
}
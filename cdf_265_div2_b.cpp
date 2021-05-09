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
	lld k;
	foi(i,n){
		cin >> A[i];
	}
	foi(i,n){
		if (A[i] == 1)
			break;
	}
	fod(k,n){
		if (A[k] == 1)
			break;
	}
	lld count = 0;
	for(lld j = i; j <= k;  j += 1){
		if (A[j] == 1){
			count+=1;
		}
		else{
			if (A[j-1] != A[j]){
				count+= 1;
			}
		}
	}
	cout << count;
	return 0;
}
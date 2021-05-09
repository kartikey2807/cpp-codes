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
	lld n, m;
	cin >> n;
	cin >> m;
	lld i, j;
	lld B[m];
	lld A[m];
	foi(i,m){
		cin >> B[i];
		A[i] = B[i];
	}
	lld max_sum   = 0;
	lld min_sum   = 0;
	foi(i,n){
		lld max = MIN;
		lld pos = 0;
		foi(j,m){
			if (B[j] > max && B[j] > 0){
				max = B[j];
				pos = j;
			}
		}
		max_sum+=B[pos];
		B[pos] -= 1;
	}
	foi(i,n){
		lld min = MAX;
		lld pos = 0;
		foi(j,m){
			if (A[j] < min && A[j] > 0){
				min = A[j];
				pos = j;
			}
		}
		min_sum+=A[pos];
		A[pos] -= 1;
	}
	cout << max_sum << " " << min_sum << "\n";
	return 0;
}
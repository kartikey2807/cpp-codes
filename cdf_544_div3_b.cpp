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
#define L 200005
int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("inputf.in",  "r",   stdin);
	freopen("outputf.in", "w",  stdout);
	#endif
	FastIO
	lld n, k;
	cin >> n;
	cin >> k;
	lld i, c;
	lld A[n];
	lld B[L];
	foi(i,L){
		B[i] = 0;
	}
	foi(i,n){
		cin >>A[i];
		A[i] %= k;
		B[A[i]]+=1;
	}
	lld count = 0;
	foi(i,n){
		if (A[i] == 0){
			if (B[A[i]] >= 2){
				B[A[i]]-=2;
				count += 1;
			}
		}
		else{
			if (A[i] != (k-A[i])){
				if (B[A[i]] >= 1 && B[k-A[i]] >= 1){
					count += 1;
					B[A[i]]-=1;
					B[k-A[i]]-=1;
				}
			}
			else{
				if (B[A[i]]>=2){
					count += 1;
					B[A[i]]-=2;
				}
			}
		}
	}
	cout << (count*2) << "\n";
	return 0;
}
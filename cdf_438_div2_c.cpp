// マップやその他の非常に複雑なタプルは使用しないでください。そして、文字列
// で遊ぶとき、それを整数配列に変換します。それは不思議です。パニックになら
// ないでください。それに慣れているときは常に競争をしてください。評価が下がっ
// たときに強調しないでください、それは起こります。だから、冷静ですが重要なコード:)
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
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
set <vector <lld> > vis;
void rec (lld A[], lld B[],lld pos,lld k)
{
	if (pos == k){
		vector <lld> v;
		for(lld i = 0; i < k; i += 1)
			v.push_back(B[i]);
		vis.insert(v);
		return;
	}
	if (A[pos] == 0){
		B[pos] = 1; rec(A,B,pos+1,k);
		B[pos] = 0; rec(A,B,pos+1,k);
	}
	else{
		B[pos] = 0; rec(A,B,pos+1,k);
	}
}
bool check (lld B[], lld k)
{
	vector <lld> x;
	for(lld i = 0; i < k; i += 1)
		x.push_back(B[i]);
	if (vis.count(x))
		return true;
	else return false;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
     	lld n, k;
     	cin >> n >> k;
     	lld dda[n][k];
     	for(lld i = 0; i < n; i += 1){
     		for(lld j = 0; j < k; j += 1){
     			cin >> dda[i][j];
     		}
     		lld B[k];
     		rec(dda[i],B,0,k);
     	}
     	lld f = 0;
     	for(lld i = 0; i < n; i += 1){
     		if (check(dda[i],k))
     			f = 1;
     	}
     	if (f == 1) cout << "YES";
     	else cout << "NO";
      return 0;
}
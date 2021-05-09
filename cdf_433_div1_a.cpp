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
void psort (lld A[], lld B[], lld n)
{
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1){
		P[i].first  = A[i];
		P[i].second = B[i];
	}
	sort(P,P+n);
	for(lld i = 0; i < n; i += 1){
		A[i] = P[i].first;
		B[i] = P[i].second;
	}
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
      lld A[n],B[n],C[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	C[i] = A[i];
      	B[i] =  i+1;
      }
      psort(A,B,n);
      lld j = n-1;
      set <lld> vis;
      map <lld, lld> m;
      for(lld i = k+1; i <= k+n;){
      	if (vis.count(i)){
      		i++;
      		continue;
      	}
      	if (i >= B[j]) {m[B[j]] = i;vis.insert(i);}
      	else {m[B[j]] = B[j];vis.insert(B[j]);}
      	j--;
      }
      lld sum = 0;
      for(lld i = 1; i <= n; i += 1)
      	sum += C[i-1]*(m[i]-i);
      cout << sum << "\n";
      for(lld i = 1; i <= n; i += 1)
      	cout << m[i] << " ";
      return 0;
}
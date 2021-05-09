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
      lld n;
      cin >> n;
      lld A[n],B[n];
      map <lld, lld> cnt;
      map <pair <lld, lld>, lld> px;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i] >> B[i];
      	cnt[A[i]]++;
      	px[{A[i],B[i]}] = i;
      }
      lld f = 0;
      for(lld i = 0; i < n; i += 1){
      	if (cnt[A[i]] > 1)
      		f = A[i];
      }
      if (f != 0){
      	vector <lld> v;
      	for(lld i = 0; i < n; i += 1){
      		if (f == A[i])
      			v.push_back(i);
      	}
      	if (B[v[0]] <= B[v[1]]) cout << v[0]+1 << " " << v[1]+1 << "\n";
      	else cout << v[1]+1 << " " << v[0]+1 << "\n";
      }
      else{
      	psort(A,B,n);
      	for(lld i = 1; i < n; i += 1){
      		if (B[i] <= B[i-1]){
      			cout << px[{A[i],B[i]}]+1 << " " << px[{A[i-1],B[i-1]}]+1 << "\n";
      			return 0;
      		}
      	}
      	cout << "-1 -1\n";
      }
      return 0;
}
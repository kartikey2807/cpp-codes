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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      dbl m;
      cin >> n >> m;
      dbl A[n],B[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      for(lld i = 0; i < n; i += 1){
      	cin >> B[i];
      }
      dbl sum = 0;
      if (B[0] == 1) {cout << "-1"; return 0;}
      dbl y = m*((B[0]/(B[0]-1))-1);
      sum += y;
      m += y;
      for(lld i = n-1; i >= 0; i -= 1){
      	if (A[i] == 1) {cout << "-1"; return 0;}
      	y = m*((A[i]/(A[i]-1))-1);
      	sum += y;
      	m += y;
      	if (i == 0) break;
      	if (B[i] == 1) {cout << "-1"; return 0;}
      	y = m*((B[i]/(B[i]-1))-1);
      	sum += y;
      	m += y;
      }
      cout << fixed << setprecision(10) << sum;
      return 0;
}
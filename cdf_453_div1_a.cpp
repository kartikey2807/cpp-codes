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
      cin >> n;
      lld A[n+1];
      for(lld i = 0; i <= n; i += 1){
      	cin >> A[i];
      }
      lld f = 0;
      for(lld i = 1; i <= n; i += 1){
      	if (A[i]>1 && A[i-1]>1)
      		f = 1;
      }
      if (f == 0) cout << "perfect\n";
      else{
      	cout << "ambiguous\n";
      	lld sum = 0;
      	for(lld i = 0; i <= n; i += 1){
      		sum += A[i];
      	}
      	lld vis[sum+1];
      	lld x = 0;
      	for(lld i = 0; i <= n; i += 1){
      		lld prev = x;
      		for(lld j = 0; j < A[i]; j += 1){
      			x++;
      			vis[x] = prev;
      		}
      	}
      	for(lld i = 1; i <= sum; i += 1)
      		cout << vis[i] << " ";
      	cout << "\n";
      	lld p;
      	for(lld i = 1; i <= n; i += 1){
      		if (A[i]>1 && A[i-1]> 1){
      			p = i;
      			break;
      		}
      	}
      	lld s1 = 0;
      	lld s2 = 0;
      	for(lld i = 0; i < p-1; i += 1)
      		s1 += A[i];
      	s1++;
      	for(lld i = 0; i < p-0; i += 1)
      		s2 += A[i];
      	s2++;
      	vis[s2] = s1;
      	for(lld i = 1; i <= sum;i += 1)
      		cout << vis[i] << " ";
      }
      return 0;
}
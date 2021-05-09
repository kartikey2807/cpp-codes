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
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      lld f = 1;
      for(lld i = 1; i < n; i += 1){
      	if (A[i] != A[i-1])
      		f = 0;
      }
      if (f == 1){
      	cout << n;
      }
      else{
      	vector <lld> len, type;
      	lld cnt = 0;
      	for(lld i = 1; i < n; i += 1){
      		if (A[i] == A[i-1]){
      			cnt++;
      		}
      		else{
      			cnt++;
      			len.push_back(cnt);
      			type.push_back(A[i-1]);
      			cnt=0;
      		}
      	}
      	cnt++;
      	len.push_back(cnt);
      	type.push_back(A[n-1]);
      	lld ans = MIN;
      	lld len0 = 0;
      	for(lld i = 0; i < len.size(); i += 1){
      		if (type[i]  ==  0)
      			len0+=len[i];
      		lld len1 = 0;
      		for(lld j = i; j < len.size(); j += 1){
      			if (type[j]  ==  1)
      				len1+=len[j];
      		}
      		// cout << len0 << " " << len1 << "\n";
      		ans = max(ans,len1+len0);
      	}
      	cout << ans;
      }
      return 0;
}
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
      lld n, k1, k2;
      cin >> n >> k1 >> k2;
      lld A[n],B[n],dif[n];
      for(lld i = 0; i < n; i += 1)
      	cin >> A[i];
      for(lld i = 0; i < n; i += 1)
      	cin >> B[i];
      for(lld i = 0; i < n; i += 1)
      	dif[i] = abs(A[i]-B[i]);
      sort(dif,dif+n,greater<lld>());
      while(true){
      	lld cnt = 0;
      	for(lld i = 0; i < n; i += 1){
      		if (dif[i] == 0)
      			cnt++;
      	}
      	if (cnt == n)
      		break;
      	lld pos = n-1;
      	for(lld i = 1; i < n; i += 1){
      		if (dif[i] != dif[i-1]){
      			pos = i-1;
      			break;
      		}
      	}
      	lld gap;
      	if (pos == n-1)
      		gap = dif[pos];
      	else
      		gap = dif[pos]-dif[pos+1];
      	if (gap*(pos+1) <= (k1+k2)){
      		if (gap*(pos+1)<= k1){
      			k1-=gap*(pos+1);
      		}
      		else{
      			lld t = gap*(pos+1);
      			t-= k1;
      			k1 = 0;
      			k2-= t;
      		}
      		for(lld i = 0; i <= pos; i += 1)
      			dif[i] -= gap;
      	}
      	else{
      		lld t = k1+k2;
      		lld q = t/(pos+1);
      		lld r = t%(pos+1);
      		t = 0;
      		for(lld i = 0; i <= pos; i += 1){
      			dif[i] -= q;
      		}
      		for(lld i = 0; i <= pos; i += 1){
      			if (r == 0)
      				break;
      			dif[i]--;
      			r--;
      		}
      		k1 = 0;
      		k2 = 0;
      		break;
      	}
      }
      if (k1+k2!=0){
      	if ((k1+k2)%2 != 0) cout << "1\n";
      	else cout << "0\n";
      }
      else{
      	lld sum = 0;
      	for(lld i = 0; i < n; i += 1)
      		sum += (dif[i]*dif[i]);
      	cout << sum;
      }
      return 0;
}
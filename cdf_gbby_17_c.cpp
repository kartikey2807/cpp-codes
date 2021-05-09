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
#define MAX std::numeric_limits<dbl>::max()
#define MIN std::numeric_limits<dbl>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      dbl r;
      cin >> n >> r;
      dbl A[n],B[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	dbl ans = r;
      	for(lld j = 0; j < i; j += 1){
      		if (abs(A[j]-A[i])>2*r){
      			continue;
      		}
      		else{
      			dbl y = sqrt(pow(2*r,2)-pow(A[i]-A[j],2));
      			ans = max(ans,y+B[j]);
      		}
      	}
      	cout << fixed << setprecision(11) << ans << " ";
      	B[i] = ans;
      }
      
      return 0;
}
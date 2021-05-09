// みなさん私はカーティキー・シャルマです。LNMIITで勉強しています。私は2年目で、コロナパンデミックが発
// 生しています。世界は終わりそうだ。だから私はそれを最大限に生きたいと思っています。それはつまり、コー
// ドを最大限に意味しているのです。私の好きなアニメは「キメツノヤイバ」で、私の一番の男の子はゼニツで、
// 私の一番の女の子はネズコです。私の好きな呼吸スタイルは息吹です。私の最高の悪魔の血の芸術は、
// ククシボによって使用される月の息です。ムーザンは亡くなり、今ではタンジローがポップの新しい魔王です。
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
lld greatep (lld A[], lld l, lld r, lld x) {return (A+r) - lower_bound(A+l,A+r,x);}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string s;
      cin >> s;
      lld n = s.length();
     	lld len[26], A[26][n];
     	memset(len, 0, sizeof(len));
     	for(lld i = 0; i < n; i += 1){
     		lld x = (lld)s[i]-97;
     		A[x][len[x]] = i;
     		len[x]++;
     	}
     	lld ans = MIN;
     	for(lld i = 0; i < 26; i+= 1){
     		if (len[i] != 0)
     			ans = max(ans,max(len[i],(len[i]*(len[i]-1))/2));
     	}
     	for(lld i = 0; i < 26; i+= 1){
     		if (len[i] > 0){
     			for(lld j = 0; j < 26; j+= 1){
     				if (i == j)
     					continue;
     				if (len[j] > 0){
     					lld sum = 0;
     					for(lld k = 0; k < len[i]; k++){
     						sum += greatep(A[j], 0, len[j], A[i][k]);
     					}
     					ans = max(ans,sum);
     				}
     			}
     		}
     	}
     	cout << ans;
      return 0;
}
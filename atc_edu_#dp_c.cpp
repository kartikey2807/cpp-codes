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
#define LEN 100005
lld dda[LEN][3];
lld vis[LEN][4];
lld rec_ (lld day, lld type, lld n)
{
	if (vis[day][type] == -1){
		if (day == n+1) vis[day][type] = 0;
		else{
			lld ans = MIN;
			for(lld i = 1; i < 4; i += 1)
			{
				if (i != type){
					ans = max(ans, rec_(day+1,i,n)+dda[day][i]);
				}
			}
			vis[day][type]  = ans;
		}
	}
	return vis[day][type];
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
      for(lld i = 1; i <= n; i += 1){
      	cin >> dda[i][1] >> dda[i][2] >> dda[i][3];
      }
      memset(vis, -1, sizeof(vis));
      cout << rec_(1, 0, n);
      return 0;
}
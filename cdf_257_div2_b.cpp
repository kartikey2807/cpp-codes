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
#define MOD 1000000007
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld x, y;
      cin >> x >> y;
      lld A[7];
      A[1] = x >= 0 ? x%MOD : MOD+(x%MOD);
      A[2] = y >= 0 ? y%MOD : MOD+(y%MOD);
      A[3] = (((y%MOD)-(x%MOD))%MOD) >= 0 ? ((y%MOD)-(x%MOD))%MOD : MOD + (((y%MOD)-(x%MOD))%MOD);
      A[4] = (-1*x) >= 0 ? ((-1*x)%MOD) : MOD+((-1*x)%MOD);
      A[5] = (-1*y) >= 0 ? ((-1*y)%MOD) : MOD+((-1*y)%MOD);
      A[6] = (((x%MOD)-(y%MOD))%MOD) >= 0 ? ((x%MOD)-(y%MOD))%MOD : MOD + (((x%MOD)-(y%MOD))%MOD);
      lld n;
      cin >> n;
      if (n % 6 == 0){
      	cout << A[6];
      }
      else{
      	cout << A[n%6];
      }
      return 0;
}
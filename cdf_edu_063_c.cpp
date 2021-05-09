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
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
lld gcd_ (lld a, lld b)
{
	lld max = a > b ? a : b;
	lld min = a < b ? a : b;
	while (min){
		lld rem = max%min;
		max = min;
		min = rem;
	}
	return max;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n;
      cin >> m;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      lld g = A[1]-A[0];
      for(lld i = 1; i < n; i += 1){
      	g = gcd_(A[i]-A[i-1],g);
      }
      lld p, f;
      lld B[m];
      f = 0;
      for(lld i = 0; i < m; i += 1){
      	lld r; 
      	cin >> r;
      	B[i] = r;
      	if (g % r == 0){
      		f = 1;
      		p = i+1;
      	}
      }
      if (f == 0){
      	cout <<  "NO\n";
      }
      else{
      	cout << "YES\n";
      	cout << A[0] << " " << p << "\n";
      }
      return 0;
}
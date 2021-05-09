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
lld check(lld A[], lld l, lld r, lld x)
{
	lld c = 0;
	for(lld i = l; i <= r; i += 1)
		if (A[i] != x)
			c++;
	return c;
}
lld rec_ (lld A[], lld l, lld r, lld x)
{
	if (l ==r)
	{
		if (A[l] == x) return 0;
		else return 1;
	}
	if (l < r)
	{
		lld mid = (l+r)/2;
		lld len1 = check(A,l, mid, x);
		lld len2 = check(A,mid+1,r,x);
		return min(len1+rec_(A,mid+1,r,x+1),len2+rec_(A,l,mid,x+1));
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n;
      	string s;
      	cin >> n >> s;
      	lld A[n];
      	for(lld i = 0; i < n; i += 1){
      		A[i] = (lld)s[i]-97;
      	}
      	cout << rec_(A,0,n-1,0) << "\n";
      }
      return 0;
}
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
lld bin_ (lld A[], lld l, lld r,lld offset)
{
	lld start = l;
	lld end = r;
	lld mid = 0;
	while (l <= r){
		mid = (l + r)/2;
		if ((A[mid]-offset) <= 0){
			l = mid+1;
		}
		if ((A[mid]-offset)  > 0){
			r = mid-1;
		}
	}
	if (mid+1 <= end && (A[mid+1]-offset) <= 0){
		return mid+2; 
	}
	if ((A[mid]-offset) <= 0){
		return mid+1;
	}
	if (mid-1 >= start&&(A[mid-1]-offset) <= 0){
		return mid+0;
	}
	if ((A[start]-offset)> 0){
		return start;
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n, r;
      	cin >> n >> r;
      	set <lld> pos;
      	for(lld i = 0; i < n; i += 1){
      		lld x;
      		cin >> x;
      		pos.insert(x);
      	}
      	lld A[pos.size()] , j = 0;
      	for(set <lld> :: iterator itr = pos.begin(); itr!=pos.end(); itr++){
      		A[j] = (*itr);
      		j++;
      	}
      	lld p = 0;
      	lld offset = 0;
      	lld q = pos.size()-1;
      	while (p  < q){
      		q--;
      		offset += r;
      		p = bin_(A, p, q, offset);
      	}
      	if (p == q && A[p] > 0){
      		offset += r;
      	}
      	cout << (offset/r) << "\n";
      }
      return 0;
}
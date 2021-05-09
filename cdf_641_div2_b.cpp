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
map <lld, lld> index;
map <lld, lld> point;
lld rec_ (lld B[], lld A[], lld x, lld n)
{
	if (!index.count(x)){
		lld max = MIN;
		lld flag =  0;
		lld k = 2;
		while((k*A[x]) <= n)
		{
			if (point[(k*A[x])] > point[A[x]] && B[point[(k*A[x])]] > B[point[A[x]]]){
				lld count = rec_(B, A, point[(k*A[x])], n)+1;
				if (count > max){
					max=count;
					flag =  1;
				}
			}
			k++;
		}
		if (flag == 0){
			index[x] = 1;
		}
		else{
			index[x] = max;
		}
	}
	return index[x];
}
void psort (lld A[], lld B[], lld n)
{
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1){
		P[i].first  = A[i];
		P[i].second = B[i];
	}
	sort(P, P+n);
	for(lld i = 0; i < n; i += 1){
		A[i] = P[i].first;
		B[i] = P[i].second;
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
      	index.clear();
      	point.clear();
      	lld n;
      	cin >> n;
      	lld A[n], B[n];
      	for(lld i = 0; i < n; i += 1){
      		A[i] =  i+1;
      		cin >> B[i];
      	}
      	psort(B, A, n);
      	for(lld i = 0; i < n; i += 1){
      		point[A[i]]= i;
      	}
      	lld max = MIN;
      	for(lld i = 0; i < n; i += 1){
      		lld c = rec_(B, A,i,n);
      		if (c > max)
      			max=c;
      	}
      	cout << max << "\n";
      }
      return 0;
}
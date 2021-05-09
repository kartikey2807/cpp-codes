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
void psort (lld A[], lld B[], lld n)
{
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1){
		P[i].first  = A[i];
		P[i].second = B[i];
	}
	sort(P,P+n);
	for(lld i = 0; i < n; i += 1){
		A[i] = P[i].first ;
		B[i] = P[i].second;
	}
}
void get_ (lld X, lld Y, lld a, lld b, lld c, lld d, map <pair <lld, lld>, vector <lld> > *v)
{
	(*v)[{X,Y}].push_back(a);
      (*v)[{X,Y}].push_back(b);
      (*v)[{X,Y}].push_back(c);
      (*v)[{X,Y}].push_back(d);
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
      cin >> n;
      lld X[n],Y[n];
      map <pair <lld, lld>, vector <lld> > v;
      for(lld i = 0; i < n; i += 1){
      	lld a, b, c, d;
      	cin >> X[i] >> Y[i];
      	cin >> a >> b >> c >> d;
      	get_(X[i],Y[i],a,b,c,d,&v);
      }
      psort(Y,X,n);
      psort(X,Y,n);
      pair <lld, lld> P[2];
      P[0] = {-100000, 100000};
      P[1] = {-100000, 100000};
      for(lld i = 0; i < n; i += 1){
      	if (v[{X[i],Y[i]}][0] != 1) P[0].first = max(X[i],P[0].first );
      	if (v[{X[i],Y[i]}][1] != 1) P[1].second= min(Y[i],P[1].second);
      	if (v[{X[i],Y[i]}][2] != 1) P[0].second= min(X[i],P[0].second);
      	if (v[{X[i],Y[i]}][3] != 1) P[1].first = max(Y[i],P[1].first );
      }
      if (P[0].first > P[0].second || P[1].first > P[1].second)
      	cout << "0\n";
      else
      	cout << "1 " << P[0].first << " " << P[1].first << "\n";
      }
      return 0;
}
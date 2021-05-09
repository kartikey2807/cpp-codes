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
#define LEN 1000001
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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      vector <lld> v[LEN];
      set  <lld>  visited;
      map <lld,lld> count;
      for(lld i = 0; i < n; i += 1){
      	lld r;
      	cin >> r;
      	count[r]++;
      	v[r].push_back(i);
      	visited.insert(r);
      }
      lld A[n], B[n];
      lld j = 0;
      for(set <lld> :: iterator itr = visited.begin(); itr != visited.end(); itr++){
      	A[j] = (*itr);
      	B[j] = count[*itr];
      	j++;
      }
      psort(B, A, j);
      lld max_count = B[j-1];
      lld min = MAX, start, end;
      for(lld i = 0; i < j; i += 1){
      	if (B[i] ==  max_count){
      		lld x = v[A[i]].front();
      		lld y = v[A[i]].back ();
      		if ((y-x+1) < min){
      			min = y-x+1;
      			start = x;
      			end = y;
      		}
      	}
      }
      cout << start+1 << " " << end+1;
      return 0;
}
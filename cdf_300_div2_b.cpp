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
vector <lld> get_ (lld x)
{
	vector <lld> result;
	while(x){
		result.push_back(x%10);
		x /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}
void psort (lld A[], lld B[], lld n)
{
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1){
		P[i].first  = A[i];
		P[i].second = B[i];
	}
	sort(P,P+n);
	for(lld i = 0; i < n; i += 1){
		A[i] = P[i].first;
		B[i] = P[i].second;
	}
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
      vector <lld> v = get_(n);
      lld len = v.size();
      lld A[len], B[len];
      vector <lld> ans;
      lld L[len];
      for(lld i = 0; i < len; i += 1){
      	A[i] = v[i];
      	B[i] = i;
      	L[i] = 1;
      }
      psort(A, B, len);
      lld prev  = 0;
      for(lld i = 0; i < len; i += 1){
      	for(lld j = 0; j < A[i]-prev; j += 1){
      		lld r = 0;
      		for(lld k = 0; k < len; k += 1){
      			r = (r*10)+L[k];
      		}
      		ans.push_back(r);
      	}
      	L[B[i]] = 0;
      	prev = A[i];
      }
      cout << ans.size() << "\n";
      for(lld i = 0; i < ans.size(); i += 1){
      	cout << ans[i] << " ";
      }
      return 0;
}
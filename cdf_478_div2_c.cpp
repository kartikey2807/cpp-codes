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
lld countSmaller (lld A[], lld l, lld r, lld x) {return upper_bound(A+l,A+r,x)-(A+l);}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, q;
      cin >> n >> q;
      lld A[n],B[q];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      for(lld i = 1; i < n; i += 1){
      	A[i] += A[i-1];
      }
      for(lld i = 0; i < q; i += 1){
      	cin >> B[i];
      }
      lld sum = 0;
      vector <lld> res;
      for(lld i = 0; i < q; i += 1){
      	sum+= B[i];
      	lld count = countSmaller(A,0,n,sum);
      	if ((n - count) == 0){
      		res.push_back(n);
      		sum = 0;
      	}
      	else{
      		res.push_back(n-count);
      	}
      }
      for(lld i = 0; i < res.size(); i += 1){
      	cout << res[i] << "\n";
      }
      return 0;
}
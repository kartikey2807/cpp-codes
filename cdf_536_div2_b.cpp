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
      lld n, m;
      cin >> n >> m;
      lld A[n], C[n], B[n], D[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	B[i] = i;
      }
      for(lld i = 0; i < n; i += 1){
      	cin >> C[i];
      	D[i] = C[i];
      }
      psort(D,B,n);
      lld x = 0;
      for(lld i = 0; i < m; i += 1){
      	lld t, d;
      	cin >> t >> d;
      	if (A[t-1] >= d){
      		A[t-1]-=d;
      		cout << (d*C[t-1]) << "\n";
      	}
      	else{
      		lld sum = 0;
      		d-=A[t-1];
      		sum += (A[t-1]*C[t-1]);
      		A[t-1]= 0;
      		lld j;
      		for(j = x; j < n; j += 1){
      			if (A[B[j]] != 0){
      				if (d > A[B[j]]){
      					d-=A[B[j]];
      					sum += (A[B[j]]*C[B[j]]);
      					A[B[j]]= 0;
      				}
      				else{
      					A[B[j]]-=d;
      					sum += (d*C[B[j]]);
      					d = 0;
      					break;
      				}
      			}
      		}
      		x = j;
      		if (d != 0) cout << "0\n";
      		else cout << sum <<  "\n";
      	}
      }
      return 0;
}
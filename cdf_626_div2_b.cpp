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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m, k;
      cin >> n >> m >> k;
      lld A[n];
      lld B[m];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      for(lld i = 0; i < m; i += 1){
      	cin >> B[i];
      }
      vector <lld> res1(n+1);
      vector <lld> res2(m+1);
      for(lld i = 0; i < n; i += 1){
      	if (A[i] == 1){
      		lld count = 0;
      		lld j;
      		for(j = i; j < n; j += 1){
      			if (A[j] == 1)
      				count++;
      			else
      				break;
      		}
      		for(lld t = count; t >= 1; t--){
      			res1[t] += count-t+1;
      		}
      		i = j-1;
      	}
      }
      for(lld i = 0; i < m; i += 1){
      	if (B[i] == 1){
      		lld count = 0;
      		lld j;
      		for(j = i; j < m; j += 1){
      			if (B[j] == 1)
      				count++;
      			else
      				break;
      		}
      		for(lld t = count; t >= 1; t--){
      			res2[t] += count-t+1;
      		}
      		i = j-1;
      	}
      }
      lld sum = 0;
      for(lld i = 1; i <= sqrt(k); i += 1){
      	if (k%i == 0){
      		if (i != (k/i)){
      			if (i <= n && (k/i) <= m) sum += res1[i]*res2[k/i];
      			if (i <= m && (k/i) <= n) sum += res1[k/i]*res2[i];
      		}
      		else{
      			if (i <= n && (k/i) <= m) sum += res1[i]*res2[k/i];
      		}
      	}
      }
      cout << sum;
      return 0;
}
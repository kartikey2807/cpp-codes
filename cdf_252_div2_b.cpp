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
      lld n, v;
      cin >> n >> v;
      lld A[n],B[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i] >> B[i];
      }
      psort(A,B,n);
      lld p = n;
      lld sum = B[0];
      lld prev = 0;
      lld count = 0;
      for(lld i = 1; i < n; i += 1){
      	if (A[i] == A[i-1]){
      		sum+= B[i];
      	}
      	else{
      		p = i;
      		break;
      	}
      }
      if (sum > v){
      	count += v;
      	prev = sum-v;
      }
      else{
      	count += sum;
      	prev = 0;
      }
      for(lld i = p; i < n; i += 1){
      	if (A[i] - A[i-1] == 1){
      		lld sum = B[i];
      		p = n;
      		for(lld j = i+1; j < n; j += 1){
      			if (A[j] == A[j-1]){
      				sum+= B[j];
      			}
      			else{
      				p = j;
      				break;
      			}
      		}
      		i = p-1;
      		if (prev > v){
      			count += v;
      			prev = sum;
      		}
      		else{
      			count += prev;
      			lld x =v-prev;
      			if (sum >= x){
      				count += x;
      				prev = sum-x;
      			}
      			else{
      				count += sum;
      				prev = 0;
      			}
      		}
      	}
      	else{
      		count += min(prev, v);
      		sum = B[i];
      		prev = 0;
      		p = n;
      		for(lld j = i+1; j < n; j += 1){
      			if (A[j] == A[j-1]){
      				sum+= B[j];
      			}
      			else{
      				p = j;
      				break;
      			}
      		}
      		i = p-1;
      		if (sum > v){
      			count += v;
      			prev = sum-v;
      		}
      		else{
      			count += sum;
      			prev = 0;
      		}
      	}
      }
      count += min(prev, v);
      cout << count;
      return 0;
}
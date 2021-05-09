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
      lld n;
      cin >> n;
      lld A[n];
      map <lld, lld> count;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	count[A[i]]++;
      }
      lld max = MIN;
      lld pos;
      for(lld i = 0; i < n; i += 1){
      	if (count[A[i]] >  max){
      		max = count[A[i]];
      		pos = A[i];
      	}
      }
      set <lld> points;
      for(lld i = 0; i < n; i += 1){
      	if (A[i] == pos)
      		points.insert(i);
      }
      lld prev = -1;
      lld cnt = 0;
      vector <lld> a, b, c;
      for(set <lld> :: iterator itr = points.begin(); itr != points.end(); itr++){
      	for(lld i = (*itr)-1; i > prev; i -= 1){
      		if (A[i] < A[i+1]){
      			a.push_back(1);
      			b.push_back(i);
      			c.push_back(i+1);
      		}
      		else{
      			a.push_back(2);
      			b.push_back(i);
      			c.push_back(i+1);
      		}
      		A[i] = A[i+1];
      		cnt++;
      	}
      	prev = (*itr);
      }
      for(lld i = prev+1; i < n; i += 1){
      	if (A[i] < A[i-1]){
      		a.push_back(1);
      		b.push_back(i);
      		c.push_back(i-1);
      	}
      	else{
      		a.push_back(2);
      		b.push_back(i);
      		c.push_back(i-1);
      	}
      	A[i] = A[i-1];
      	cnt++;
      }
      cout << cnt << "\n";
      for(lld i = 0; i < a.size(); i += 1){
      	cout << a[i] << " " << b[i]+1 << " " << c[i]+1 << "\n";
      }
      return 0;
}
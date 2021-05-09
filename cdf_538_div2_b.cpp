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
      lld A[n],B[n];
      set <lld> vis;
      map <lld, lld> cnt;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	B[i] = A[i];
      }
      sort(B,B+n,greater<lld>());
      lld x = 0;
      while(x < (m*k)){
      	vis.insert(B[x]);
      	cnt[B[x]]++;
      	x++;
      }
      lld prev = 0;
      lld c = 0;
      lld sum = 0;
      vector <lld> v;
      for(lld i = 0; i < n; i += 1){
      	if (vis.count(A[i])){
      		c++;
      		cnt[A[i]]--;
      		if (cnt[A[i]] == 0) vis.erase(A[i]);
      	}
      	if (c == m){
      		v.push_back(i+1);
      		vector <lld> cze;
      		for(lld j = prev; j <= i; j += 1)
      			cze.push_back(A[j]);
      		sort(cze.begin(),cze.end(),greater<lld>());
      		lld j = 0;
      		while(c){
      			sum += cze[j];
      			c--;
      			j++;
      		}
      		prev = i+1;
      	}
      }
      cout << sum << "\n";
      foi(i,v.size()-1) cout << v[i] << " ";
      return 0;
}
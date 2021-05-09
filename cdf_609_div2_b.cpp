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
void solve (map <lld, vector <lld> > a, map <lld, vector <lld> > b, lld m)
{
	map <lld, vector <lld> > :: iterator p1 = a.begin();
      map <lld, vector <lld> > :: iterator p2 = b.begin();
      vector <lld> arr = p1->second;
      vector <lld> brr = p2->second;
      lld len = brr.size();
      sort(arr.begin() , arr.end());
      sort(brr.begin() , brr.end());
      lld j = 0;
      lld ans = MAX;
      while(j < len){
      	lld k = j;
      	map <lld, lld> cnt;
      	for(lld i = 0; i < len; i += 1){
      		if (arr[i] <= brr[k%len]) cnt[brr[k % len] - arr[i]]++;
      		else cnt[(brr[k%len]+m)-arr[i]]++;
      		k++;
      	}
      	if (cnt.size() == 1){
      		if (arr[0] <= brr[j%len]) ans = min(ans, brr[j]-arr[0]);
      		else ans = min(ans, (brr[j]+m)-arr[0]);
      	}
      	j++;
      }
      cout << ans;
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
      lld A[n],B[n];
      map <lld, lld> c1, c2;
      map <lld, vector <lld> > a, b;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	c1[A[i]]+=1;
      }
      for(lld i = 0; i < n; i += 1){
      	cin >> B[i];
      	c2[B[i]]+=1;
      }
      for(map <lld, lld> :: iterator itr = c1.begin(); itr != c1.end(); itr++)
      	a[itr->second].push_back(itr->first);
      for(map <lld, lld> :: iterator itr = c2.begin(); itr != c2.end(); itr++)
      	b[itr->second].push_back(itr->first);
      solve(a,b,m);
      return 0;
}
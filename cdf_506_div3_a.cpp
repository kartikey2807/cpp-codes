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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n, k;
      cin >> n >> k;
      string s;
      cin >> s;
      string A[n];
      string B[n];
      for(lld i = 0; i < n; i += 1){
      	string r = "";
      	for(lld j = 0; j < i; j += 1){
      		r += s[j];
      	}
      	A[i] = r;
      }
      for(lld i = 0; i < n; i += 1){
      	string r = "";
      	for(lld j = i+1; j<n; j += 1){
      		r += s[j];
      	}
      	B[i] = r;
      }
      lld f = 0;
      lld pos = -1;
      lld max = MIN;
      for(lld i = 0; i < n; i += 1){
      	f = 0;
      	for(lld j = 0; j < n; j += 1){
      		if (A[i] == B[j]){
      			f = 1;
      			break;
      		}
      	}
      	if (f == 1){
      		lld Len = A[i].length();
      		if (Len > max){
      			max=A[i].length();
      			pos=i;
      		}
      	}
      }
      if (pos == -1){
      	string x = s;
      	lld count= 1;
      	while (count != k){
      		x += s;
      		count++;
      	}
      	cout << x <<  "\n";
      }
      else{
      	lld p = A[pos].length()-1;
      	string x = s;
      	lld count= 1;
      	while (count != k){
      		for(lld i = p+1; i < n; i += 1){
      			x += s[i];
      		}
      		count++;
      	}
      	cout << x << "\n";
      }
      return 0;
}
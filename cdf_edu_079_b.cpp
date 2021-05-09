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
lld bin1 (lld B[], lld l, lld r, lld x)
{
	lld start = l;
	lld end = r;
	lld mid = 0;
	while (l <= r){
		mid = (l + r)/2;
		if (B[mid] == x)
			break;
		if (B[mid]  > x)
			r = mid-1;
		if (B[mid]  < x)
			l = mid+1;
	}
	if (mid+1 <= end && B[mid+1] <= x)
		return (mid+1)- start + 1;
	if (B[mid]<= x)
		return mid - start + 1;
	if (mid-1 >= start&&B[mid-1] <= x)
		return (mid-1)- start + 1;
	if (x < B[start]){
		return 0;
	}
}
lld bin2 (lld B[], lld l, lld r, lld x, lld offset)
{
	lld start = l;
	lld end = r;
	lld mid = 0;
	while (l <= r){
		mid = (l + r)/2;
		if ((B[mid]-offset)== x)
			break;
		if ((B[mid]-offset) > x)
			r = mid-1;
		if ((B[mid]-offset) < x)
			l = mid+1;
	}
	if (mid+1 <= end && (B[mid+1]-offset) <= x)
		return (mid+1) - start + 1;
	if ((B[mid]-offset) <= x)
		return mid - start + 1;
	if (mid-1 >= start&&(B[mid-1]-offset) <= x)
		return (mid-1) - start + 1;
	if (x <(B[start]-offset)){
		return 0;
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n,s;
      	cin >> n >> s;
      	lld A[n];
      	lld B[n];
      	for(lld i = 0; i < n; i += 1){
      		cin >> A[i];
      		B[i] = A[i];
      	}
      	for(lld i = 1; i < n; i += 1){
      		B[i] += B[i-1];
      	}
      	if (B[n-1] <= s){
      		cout << "0\n";
      		continue;
      	}
      	lld max = MIN, max_pos, count;
      	for(lld i = 0; i < n; i += 1){
      		if (i == 0){
      			count = bin2(B, i+1, n-1, s, A[i]);
      		}
      		else if (i == n-1){
      			count = bin1(B, 0, n-2, s);
      		}
      		else{
      			if (B[i-1] > s){
					count = bin1(B, 0, i-1, s);
      			}
      			else{
      				count = bin2(B, i+1, n-1, s, A[i]);
      				count+= i;
      			}
      		}
      		// cout << count << "\n";
      		if (count > max){
      			max = count;
      			max_pos = i;
      		}
      	}
      	cout << max_pos+1 << "\n";
      }
      return 0;
}
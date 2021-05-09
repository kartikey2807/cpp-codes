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
lld bin_ (lld x[], lld l, lld r, lld val) {
      lld mid = -1;
      while(l <= r){
            mid = (l+r)/2;
            if (x[mid] == val)
                  return 1;
            if (x[mid]  > val)
                  r = mid-1;
            if (x[mid]  < val)
                  l = mid+1;
      }
      return 0;
}
lld cnt_ (lld x[], lld l, lld r, lld val) {return upper_bound(x+l,x+r,val)-(x+l);}
lld xyz_ (lld x[], lld n)
{
      lld count = 0;
      sort(x, x+n);
      for(lld i = 0; i < n-1; i += 1){
            if (x[i] < 0){
                  if (bin_(x,0,n-1,-1*x[i])== 1){
                        count += cnt_(x,i+1,n,-1*(x[i]+1));
                  }
                  else{
                        count += cnt_(x,i+1,n,-1*x[i]);
                  }
            }
      }
      return count;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld a[n], b[n];
      lld A[n], B[n];
      for(lld i = 0; i < n; i += 1){
            cin >> a[i];
      }
      for(lld i = 0; i < n; i += 1){
            cin >> b[i];
      }
      for(lld i = 0; i < n; i += 1){
            A[i]= a[i]-b[i];
            B[i]= b[i]-a[i];
      }
      cout << xyz_(B,n);
      return 0;
}
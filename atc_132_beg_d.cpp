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
#define MOD 1000000007
#define size 2100000
lld fac [size];
lld ifac[size];
lld inv [size];
void fac_mod ()
{
      fac[0] = 1;
      fac[1] = 1;
      for(lld i = 2; i < size; i++){
            fac[i] = fac[i-1]*i%MOD;
      }
}
void ifac_mod()
{
      ifac[0] = 1;
      ifac[1] = 1;
      inv [1] = 1;
      for(lld i = 2; i < size; i++){
            inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
            ifac[i]= ifac[i - 1] * inv[i] % MOD;
      }
}
lld nCk_ (lld n, lld k)
{
      if (n < k) return 0;
      if (n < 0 || k < 0){
            return 0;
      }
      return fac[n]*(ifac[k]*ifac[n-k]%MOD)%MOD;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n, k;
      cin >> n;
      cin >> k;
      fac_mod();
      ifac_mod();
      for(lld i = 1; i <= k; i++){
            cout << (nCk_(k-1,i-1)*nCk_(n-k+1,i))%MOD << "\n";
      }
      return 0;
}
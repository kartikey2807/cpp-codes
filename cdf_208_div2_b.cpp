// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
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
#define pb push_back
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld len[n];
      string arr[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> arr[i];
      	arr[i]+= "<3";
      	len[i] = arr[i].size();
      }
      arr[0] = "<3"+arr[0];
      len[0]+= 2;
      string s;
      cin >> s;
      lld l = s.size();
      lld j = 0, k = 0, f = 0;
      for(lld i = 0; i < l; i += 1){
      	if (s[i] == arr[j][k]){
      		k++;
      		if (k == len[j]){
      			j++;
      			k = 0;
      		}
      	}
      	if (j == n){
      		f = 1;
      		break;
      	}
      }
      if (f == 1) cout << "yes";
      else cout << "no";
      return 0;
}
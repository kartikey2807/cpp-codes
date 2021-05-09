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
#define LEN 200005
lld A[LEN];
lld B[LEN];
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string a;
      string b;
      cin >> a >> b;
      lld len_a = a.size(), len_b = b.size();
      for(lld i = 0; i < len_a; i += 1)
      	A[i] = (lld)a[i]-48;
      for(lld i = 0; i < len_b; i += 1)
      	B[i] = (lld)b[i]-48;
      if (len_a == len_b){
      	lld c = 0;
      	for(lld i = 0; i < len_b; i += 1){
      		if (A[i] != B[i])
      			c++;
      	}
      	cout<< c;
      	return 0;
      }
      if (len_b < (2*len_a)){
      	lld z = 0, o = 0;
      	lld cnt[len_b];
      	for(lld i = 0; i < len_b-len_a+1; i += 1){
      		if (A[i] == 0)
      			z++;
      		if (A[i] == 1)
      			o++;
      		if (B[i] == 0) cnt[i] = o;
      		else cnt[i] = z;
      	}
      	lld j = 0;
      	for(lld i = len_b-len_a+1; i < len_b; i += 1){
      		if (A[j] == 0)
      			z--;
      		if (A[j] == 1)
      			o--;
      		j++;
      		if (i < len_a){
      			if (A[i] == 0)
      				z++;
      			if (A[i] == 1)
      				o++;
      			if (B[i] == 0) cnt[i] = o;
      			else cnt[i] = z;
      		}
      		else{
      			if (B[i] == 0) cnt[i] = o;
      			else cnt[i] = z;
      		}
      	}
      	lld sum = 0;
      	for(lld i = 0; i < len_b; i += 1)
      		sum += cnt[i];
      	cout << sum;
      	return 0;
      }
      lld zero[len_a], one[len_a];
      lld z = 0;
      lld o = 0;
      for(lld i = 0; i < len_a; i += 1){
      	if (A[i] == 0)
      		z++;
      	if (A[i] == 1)
      		o++;
      	zero[i] = z;
      	one [i] = o;
      }
      lld cnt[len_b];
      for(lld i = 0; i < len_b-len_a+1;  i += 1){
      	if (i < len_a){
      		if (B[i] == 0) cnt[i] = one[i];
      		else cnt[i] = zero[i];
      	}
      	else{
      		if (B[i] == 0) cnt[i] = one[len_a-1];
      		else cnt[i] = zero[len_a-1];
      	}
      }
      lld j = len_a-1;
      lld z1 = 0, o1 = 0;
      for(lld i = len_b-1; i >= len_b-len_a+1; i -= 1){
      	if (A[j] == 0)
      		z1++;
      	if (A[j] == 1)
      		o1++;
      	if (B[i] == 0) cnt[i] = o1;
      	else cnt[i] = z1;
      	j--;
      }

      lld sum = 0;
       for(lld i = 0; i < len_b; i += 1)
       	sum += cnt[i];
       cout << sum;
      return 0;
}
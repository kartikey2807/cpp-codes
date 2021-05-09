#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define LEN 100000
lld isprime[LEN];
lld clprime[LEN];
void prime ()
{
	isprime[0] = 0;
	isprime[1] = 0;
	for(lld i = 2; i < LEN; i += 1)
		isprime[i] = 1;
	for(lld i = 4; i < LEN; i += 2)
		isprime[i] = 0;
	for(lld i = 3; i*i<LEN; i += 1)
	{
		if (isprime[i])
			for(lld j = i*i; j < LEN; j += i)
				isprime[j] = 0;
	}
	lld lim;
	for(lld i = 0; i < LEN; i += 1)
		if (isprime[i])
			lim = i;
	for(lld i = lim; i >=0; i -= 1)
	{
		if (isprime[i])
			lim = i;
		clprime[i] = lim;
	}
}
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    prime();
    lld t;
    cin >> t;
    while(t--)
    {
    	lld d;
    	cin >> d;
    	lld x = clprime[1+d];
    	lld y = clprime[x+d];
    	cout << x*y << "\n";
    }
    return 0;
}
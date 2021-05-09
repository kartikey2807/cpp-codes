#include <bits/stdc++.h>
#include <set>
#include <vector>
#include <string>
#include <limits>
using namespace std;
typedef long long int lld;
#define MAXN 1000001
lld Flag[10005];
set <lld> minim;
#define infi std::numeric_limits<lld>::max()
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
lld spf[MAXN];
void sieve (){
    spf[1]= 1;
    for(lld i=2; i<MAXN; i+=1)
        spf[i] = i;
    for(lld i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for(lld i=3; i*i<MAXN;i++)
    {
        if (spf[i] == i)
        {
            for(lld j=i*i;j<MAXN;j+=i){
                if (spf[j]==j)
                    spf[j]= i;
            }
        }
    }
}
vector <lld>  getFactorization (lld x){
    vector<lld>ret; 
    while (x != 1){
        ret.push_back(spf[x]);
        x/= spf[x];
    }
    return ret;
}
double getComb (double n  ,  double x){
    if (x > n){
        return 0;
    }
    else{
        double r = 1.0;
        for(double i = 1.0;i<=x; i+=1){
            double a = n-i+1;
            double b = a / i;
            r*=b;
        }
        return r;
    }
}
void merge(lld crr[], lld brr[], lld arr[], lld l, lld m, lld r){
    lld i , j ,  k;
    lld n1 = m-l+1; 
    lld n2 = r - m;
    lld L1[n1],L2[n1],L3[n1];
    lld R1[n2],R2[n2],R3[n2];
    for (i = 0; i < n1; i++){
        L1[i] = arr[l + i];
        L2[i] = brr[l + i];
        L3[i] = crr[l + i];
    }
    for (j = 0; j < n2; j++){
        R1[j] = arr[m+1+j];
        R2[j] = brr[m+1+j];
        R3[j] = crr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L1[i] <= R1[j]){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
        }
        else{
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
        }
        k++;
    }
        while (i   <   n1){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
            k++;
        }
        while (j   <   n2){
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
            k++;
        }
}
void mergeSort(lld crr[], lld brr[], lld arr[], lld l, lld r){
    if (l < r)
    {
        lld m = l+(r-l)/2;
        mergeSort(crr, brr, arr,l, m);
        mergeSort(crr, brr,arr,m+1,r);
        merge(crr, brr, arr, l, m, r);
    } 
}
lld countSmaller(lld arr[], lld l, lld n, lld x){
    return upper_bound(arr+l, arr+n, x)- (arr+l);
}
int main () {
    freopen("input.txt" , "rt" , stdin);
    freopen("output.txt", "wt", stdout);
    FastIO
    lld n, i;
    cin >> n;
    lld A[n];
    for(i = 0;i<n; i+=1){
        cin>>A[i];
    }
    sort(A,A + n);
    lld min =infi;

    for(i = 0;i<n; i+=1){
        lld rem = n - countSmaller(A,i,n,2*A[i]);
        if (rem <=  min){
            min  =  rem;
        }
    }
    cout << min << "\n";
    return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> a;
long long m;

bool check(long long mid) {
    int n = a.size();
    long long cnt = 0;
    for (int i=0; i<n; i++) {
        if (a[i]-mid > 0) {
            cnt += a[i]-mid;
        }
    }
    return cnt >= m;
}

int main() {
    int n;
    scanf("%d %lld",&n,&m);
    a = vector<long long>(n);
    long long l=0;
    long long r=0;
    for (int i=0; i<n; i++) {
        scanf("%lld",&a[i]);
        if (r < a[i]) {
            r = a[i];
        }
    }
    long long ans = 0;
    while (l <= r) {
        long long mid = (l+r)/2;
        if (check(mid)) {
            ans = max(ans,mid);
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
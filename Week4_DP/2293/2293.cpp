#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    int coin[n]; int dp[10001] = {0};
    for(int i = 0; i < n; i++) cin >> coin[i];

    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = coin[i]; j <= k; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[k] << "\n";
}
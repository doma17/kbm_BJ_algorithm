#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;

int main() {
    fastio;
    int T, n;
    cin >> T;
    vector<int> v;
    priority_queue<int> q;
    while(T--) {
        cin >> n;
        v.push_back(n);
        q.push(n);
    }
    
    // 최대값
    ll dp[q.top() + 1][4];
    dp[0][1] = 1; dp[0][2] = 0; dp[0][3] = 0;
    dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
    for(int i = 2; i <= q.top(); i++) {
        // 1 인덱스 전의 있던 1을 사용한 가짓수를 가져온다.
        dp[i][1] = dp[i-1][1];
        // 현재의 -2 인덱스의 값들을 가져오는데
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        if(i >= 3) dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }
    for(auto x : v) {
        cout << dp[x][1] + dp[x][2] + dp[x][3] << "\n";
    }
}
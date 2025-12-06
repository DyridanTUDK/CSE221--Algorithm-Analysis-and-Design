#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M , K;
    if(!(cin>>N>>M>>K)) return 0;

    vector<pair<int, int>> knights(K);

    for(int i = 0; i < K ; i++){
        cin >> knights[i].first >> knights[i].second;
    }

    const int dx[8] = {2,2,-2,-2,1,1,-1,-1};
    const int dy[8] = {1,-1,1,-1,2,-2,2,-2};

    unordered_set<long long> seen;
    seen.reserve(K*2+10);

    for(auto&p : knights){
        long long key = ((long long)p.first << 32 | (long long)p.second);
        seen.insert(key);
    }

    for(auto&p : knights){
        int x = p.first;
        int y = p.second;

        for(int d = 0; d<8; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx<1||nx>N||ny<1||ny>M) continue;
            long long key = (long long )nx << 32 | (long long) ny;

            if(seen.find(key) != seen.end()){
                if(!(nx==x&&ny==y)){
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}
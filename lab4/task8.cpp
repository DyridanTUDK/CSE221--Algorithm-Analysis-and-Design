#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    if(!(cin>>N>>Q)) return 0; 

    vector<vector<int>> adj(N+1);
    for(int i = 1 ; i <= N ; ++i){
        adj[i].reserve(N/2);
        for (int j = 1; j <= N; ++j)
        {
            if(i==j)continue;
            if(std::gcd(i,j)==1) adj[i].push_back(j);
        }
        
    }
    while(Q--){
        int x;
        long long k;
        cin >> x >> k;
        if(k<=0||k>(long long)adj[x].size()){
       cout << -1 << "\n";
        }
        else{
            cout << adj[x][k-1] << "\n";
        }
    }
    
    
    return 0;
}
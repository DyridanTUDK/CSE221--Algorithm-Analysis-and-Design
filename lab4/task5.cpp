#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;

    cin >> N >> M;
    
    vector<long long> indeg(N+1, 0), outdeg(N+1,0);
    vector<int> u(M), v(M);

    for(int i = 0; i < M; i++) cin >> u[i]; 
    for(int i = 0; i < M; i++) cin >> v[i]; 
    
    for(int i = 0; i <M; i++){
        outdeg[u[i]]++;
        indeg[v[i]]++;
    }
    
    for(int i =1;i<=N; i++){
        cout << indeg[i] - outdeg[i];
        if(i<N) cout << " ";
    }
    
    
    
    return 0; 
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N , M;
    cin >> N  >> M;

    vector<vector <int>> mat(N+1);
    vector<int> indeg(N+1,0);
    for(int i = 0; i<M; i++){
        int u,v;
        cin >> u >> v;
        mat[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(indeg[i]==0) q.push(i);
    }
    vector<int> order;
    order.reserve(N);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(int v:mat[u]){
            if(--indeg[v] == 0){
                q.push(v);
            }
        }
    }

    if((int)order.size()<N){
        cout << -1 << "\n";
    }
    else{
        for (size_t i = 0; i < N; i++)
        {
            if(i) cout << ' ';
            cout << order[i];
        }
        cout << "\n";
        
    }
    return 0;
}
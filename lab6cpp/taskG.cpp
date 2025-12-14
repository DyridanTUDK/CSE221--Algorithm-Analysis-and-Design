#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    vector<string> words(N);
    for(int i = 0; i < N ; i++){
        cin >> words[i];
    }

    vector<vector<int>> adj(26);
    vector<int> indeg(26,0);
    vector<bool> used (26, false);

    for(auto &w: words){
        for(char c: w){
            used[c-'a'] = true;
        }
    }

    for(int i = 0; i < N-1; i++){
        string &a = words[i];
        string &b = words[i+1];
        int len = min(a.size(), b.size());
        bool found = false;
        for(int j = 0; j<len ;j++){
            if(a[j]!=b[j]){
                int u = a[j] - 'a';
                int v = b[j] - 'a';
                adj[u].push_back(v);
                indeg[v]++;
                found = true;
                break; 
            }
        }
        if(!found && a.size() > b.size()){
            cout << -1 << "\n";
            return 0;
        }

        
    }
    priority_queue<int , vector<int> , greater<int>> pq;
    for(int  i = 0; i<26;i++){
        if(used[i] && indeg[i]==0){
            pq.push(i);
        }
    }
    string order;
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        order.push_back(char('a'+u));
        for( int v : adj[u]){
            indeg[v]--;
            if(indeg[v]==0){
                pq.push(v);
            }
        }
    }

    int usedCount = 0;
    for(bool x:used) if(x) usedCount++;

    if((int)order.size() != usedCount){
        cout<<-1<<"\n";
    }
    else{
        cout << order <<"\n";
    }

    return 0;

}
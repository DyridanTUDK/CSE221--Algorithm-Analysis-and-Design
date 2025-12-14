#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int n){
    vector<int> factors; 
    int temp = n;

    for(int i = 2; i*i <=temp; i++){
        if(temp%i==0){
            factors.push_back(i);
            while(temp%i==0){
                temp/=i;
            }
        }
    }
    if(temp>1 && temp!=n){
        factors.push_back(temp);
    }

    return factors;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--)
    {
        int s, t;
        cin >> s >> t; 

        if(s==t){
            cout << 0 << "\n";
            continue;
        }
        if(s>t){
            cout<< -1 << "\n";
            continue;
        }

        vector<int> dist(t+1, -1);
        queue<int>  q;

        dist[s] = 0;
        q.push(s);

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            vector<int> factor = primeFactors(cur);

            for(int p: factor){
                int nxt = cur + p;
                if(nxt<=t && dist[nxt]==-1){
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        cout << dist[t] << "\n";
    }
    

    return 0;
}
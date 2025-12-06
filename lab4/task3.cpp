#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    // make the matrix
    vector<vector<int>> adjMat(N, vector<int>(N,0));

    for(int i = 0; i <N;i++){
        int k;
        cin >> k;
        for(int j = 0 ; j < k ; j++){
            int v;
            cin >> v;
            adjMat[i][v] = 1;
        }
    }
    
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << adjMat[i][j];
            if(j+1<N) cout << " ";
        }
        cout << "\n";
        
    }


    return 0;
}
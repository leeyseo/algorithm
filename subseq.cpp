#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() 
{
    int n, m;
    cin >> n >> m;
    
    vector<int> arr_1;
    vector<int> arr_2;
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for (int i = 0; i <= n; i++) 
    {
        arr_1.push_back(0);
        arr_2.push_back(0);
    }
    for (int i = 1; i <= n; i++) 
    {
        cin >> arr_1[i];
    }
    
    for (int i = 1; i <= m; i++) 
    {
        cin >> arr_2[i];
    }
    
    for (int i = 0; i <= n; i++) 
    {
        dp[i][0] = 1;
    }
    

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (arr_1[i] == arr_2[j]) 
            {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 202201022;
            } 
            else 
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[n][m] << endl;
    
    return 0;
}
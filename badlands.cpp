#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> arr(m, vector<int>(n, 0)); 
    vector<vector<int>> dp(m, vector<int>(n, -1)); 

 
    for (int i = 0; i < k; i++) 
    {
        int a, b;
        cin >> a >> b;
        arr[a - 1][b - 1] = -1;  
    }


    for (int j = 0; j < n; j++) 
    {
        if (arr[0][j] != -1) 
        {
            dp[0][j] = 1;  
        }
    }
    

    for (int i = 0; i < m; i++) 
    {
        vector<int> tmp1(n,0);
        vector<int> tmp2(n,0);
        for(int j=0;j<n;j++)
        {
            tmp1[j]=dp[i][j];
            tmp2[j]=dp[i][j];
        }
        
        for (int j = 0; j < n; j++) 
        {
            if (arr[i][j] == -1) continue;  
            if (j + 1 < n && arr[i][j + 1] != -1 && tmp1[j] != -1) 
            {
                tmp1[j+1] = max(tmp1[j+1], tmp1[j] + 1);
            }
        }

        for(int j=n-1;j>=0;j--)
        {
            if (arr[i][j] == -1) continue; 
            if (j - 1 >= 0 && arr[i][j - 1] != -1 && tmp1[j] != -1) 
            {
                tmp2[j-1] = max(tmp2[j-1], tmp2[j] + 1);
            }
        }

        for (int j = 0; j < n; j++) 
        {
            if (arr[i][j] == -1) continue;  
            dp[i][j]=max(tmp1[j],tmp2[j]);

            if (i + 1 < m && arr[i + 1][j] != -1 && dp[i][j] != -1) 
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
            }
        }    
    }

    int ans = -1;
    for (int j = 0; j < n; j++) 
    {
        ans = max(ans, dp[m - 1][j]);
    }


    cout << ans << endl;
    return 0;
}

    

 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> t(n);

    int sums = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> t[i];
        sums =sums+t[i];
    }

    vector<bool> dp(sums + 1);
    dp={false};



    dp[0] = true;
    for (int i = 0; i < n; i++) 
    {
        for (int j = sums; j >= t[i]; j--) 
        {
            if (dp[j - t[i]]) 
            {
                dp[j] = true;
            }
        }
    }

    int ans = 2 * sums; 


    for (int s = 0; s <= sums; s++) 
    {
        if (dp[s]) 
        {
            int a=2 * s;

            int b=sums - s;
            int tmp = max(a,b);
            
            if (tmp < ans) 
            {
                ans = tmp;
            }
        }
    }

    cout << ans;
    return 0;
}

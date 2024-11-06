#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(vector<int>& v1, vector<int>& v2, int mid, int n, int m) 
{
    int tmp = 0;
    for (int i = 0; i < m; i++) 
    {   
        int k = mid;
        while (k > 0 && tmp < n && v1[tmp] <= v2[i]) 
        {
            tmp++;
            k--;
        }
    }
    //cout<<"---------------"<<"\n";
    //cout<<tmp<<" "<<n<<"\n";

    if(tmp==n)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);
    for (int i = 0; i < n; i++) 
    {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++) 
    {
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end(),greater<>());
    sort(v2.begin(), v2.end(),greater<>());
    if (v1[0] > v2[0]) 
    {
        cout << -1;
        return 0;
    }
    int min_1 = 1; 
    int max_1 = n; 
    int ans = max_1;

    while (min_1 <= max_1) 
    {
        int mid = (min_1 + max_1) / 2;
        //cout<<"mid:"<<mid<<"\n";
        if (compare(v1, v2, mid,n,m)) 
        {
            ans = mid;  
            //cout<<"ans:"<<ans<<"\n";
            max_1 = mid - 1;
        } 
        else 
        {
            min_1 = mid + 1; 
        }
    }
    cout << ans*3;
    return 0;
}

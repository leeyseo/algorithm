#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
    long long int d;
    long long int r;
    int n;
    cin >> d >> r >> n;
    
    vector<int> v1(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++) 
    {
        // int tmp;
        // cin >> tmp;
        // if(tmp<0)
        // {
        //     north_sensors[i]=pow(tmp,2)*-1;
        // }
        // else
        // {
        //     north_sensors[i]=pow(tmp,2);
        // }
        // cout<<north_sensors[i]<<" ";
        cin>>v1[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cin >> v2[i];
    }


    sort(v1.begin(), v1.end());


    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) 
    {

        auto in_a = lower_bound(v1.begin(), v1.end(), v2[i]-sqrt(pow(r,2)-pow(d,2)))- v1.begin();
        auto in_b = upper_bound(v1.begin(), v1.end(), v2[i]+sqrt(pow(r,2)-pow(d,2)))- v1.begin();

        ans[i] = in_b - in_a;

    }


    sort(ans.begin(), ans.end());


    for (int i = 0; i < n; i++) 
    {
        cout << ans[i]<<" ";
    }

    return 0;
}

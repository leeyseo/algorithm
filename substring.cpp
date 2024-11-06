#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    int n;
    string str;
    cin >> n >> str;
    
    cout << n + 1 << "\n";
    cout << "1"<<" "<< n << "\n";

    vector<vector<int>> arr(n + 1, vector<int>(2, 0));


    for (int i = 0; i < n; i++)
    {
        string str_1 = str.substr(0, i); 
        for (int j = 0; j < 2; ++j) 
        {
            string tmpa=j+"0";
            string str_2 = str_1 + tmpa;

            int tmp;
            for (tmp = i + 1; tmp > 0; tmp--)
            {
                if (str.substr(0, tmp) == str_2.substr(str_2.size() - tmp)) 
                {
                    break;
                }
            }
            arr[i][j] = tmp; 
        }
    }


    arr[n][0] = n;
    arr[n][1] = n;


    for (int i = 0; i < n + 1; i++) 
    {
        cout << arr[i][0] << " " << arr[i][1] << "\n";
    }

    return 0;
}

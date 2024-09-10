#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countall = 0;
void fillvector(string str, vector<pair<int, int>> &v)
{
    int str_len = str.length();
    int s = -1;
    for (int i = 0; i < str_len; ++i)
    {
        if (str[i] == '1')
        {
            if (s == -1)
            {
                s = i;
            }
        }
        else
        {
            if (s != -1)
            {
            v.push_back({ s, i - 1 });
            s = -1;
            }
        }
    }
    if (s != -1)
    {
        v.push_back({ s, str_len - 1 });
    }
}

int findminmax(vector<pair<int, int>>& v, int n, int minmaxday)
{
    for (int i = 0; i < v.size(); i++)
    {
        int maxday;
        int nlen = v[i].second - v[i].first + 1;
        countall = countall + nlen;
        if ((v[i].second == n - 1 || v[i].first == 0) && nlen != 1)
        {
            maxday = nlen - 1;
        }
        else
        {
            maxday = (nlen - 1) / 2;
        }
        minmaxday = min(minmaxday, maxday);
    }
    return minmaxday;
}



int countmintrees(int ans, vector<pair<int, int>>& v, int n, int i, int minmaxday)
{
    int mintree;
    int nlen = v[i].second - v[i].first + 1;
    if ((v[i].second == n - 1 || v[i].first == 0) && (nlen - 1 == minmaxday))
    {
        mintree = 1;
    }
    else
    {
        if (nlen % 3 != 0)
        {
            mintree = nlen / 3 + 1;
        }
        else
        {
            mintree = nlen / 3;
        }
        if (minmaxday > 1)
        {
            int tmp_f = v[i].first + minmaxday;
            int tmp_s = v[i].second - minmaxday;
            if (tmp_s - tmp_f - 1 <= 2 * minmaxday)
            {
                if (tmp_s == tmp_f)
                {
                    mintree = 1;
                }
                else 
                {
                    mintree = 2;
                }
      
            }
            else if (tmp_s - tmp_f - 1 > 2 * minmaxday)
            {
                int var;
                if ((tmp_s - tmp_f - 1) % (2 * minmaxday + 1) == 0)
                {
                    var = (tmp_s - tmp_f - 1) / (2 * minmaxday + 1);
                }
                else
                {
                    var = ((tmp_s - tmp_f - 1) / (2 * minmaxday + 1)) + 1;
                }
                mintree = 2 + var;
            }
        }
    }
    ans = ans + mintree;
    return ans;
}






int main()
{
    int n;
    string str;
    cin >>  n >> str;
    vector<pair<int, int>> v;
    fillvector(str, v);

    int minmaxday = 1000000;
    //1의 연속이 하나라면
    if (v.size() == 1)
    {
        if ((v[0].second == n - 1 || v[0].first == 0)|| (v[0].second - v[0].first + 1)%2!=0)
        {
            cout << 1<< endl;
            return 0;
        }
        else
        {
            cout << 2 << endl;
            return 0;
        }
    }

    minmaxday = findminmax( v, n,minmaxday);
    //시간줄이기
    if (minmaxday == 0)
    {
        cout << countall <<endl;
        return 0;
    }
   
    int ans=0;
    for (int i = 0; i < v.size(); i++)
    {
        ans = countmintrees(ans, v, n, i,minmaxday);
    }
    

    cout <<ans<< endl;
    return 0;
}




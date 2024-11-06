#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
    int a, b, c, d, e, f, g, h;
    int answer = 0;

    cin >> a >> b >> c >> d >> e >> f >> g >> h;

    for (int t1 = 1; t1 <= 13; t1++) 
    {
        for (int t2 = 1; t2 <= 13; t2++) 
        {
            if (t1 == t2)
            {
                continue;
            }
            for (int t3 = 1; t3 <= 13; t3++) 
            {
                if (t1 == t3 || t2 == t3)
                {
                    continue;
                }
                for (int t4 = 1; t4 <= 13; t4++) 
                {
                    if (t1 == t4 || t2 == t4 || t3 == t4)
                    {
                        continue;
                    }
                    for (int t5 = 1; t5 <= 13; t5++) 
                    {
                        if (t1 == t5 || t2 == t5 || t3 == t5 || t4 == t5)
                        {
                            continue;
                        }
                        for (int t6 = 1; t6 <= 13; t6++) 
                        {
                            if (t1 == t6 || t2 == t6 || t3 == t6 || t4 == t6 || t5 == t6)
                            {
                                continue;
                            }

                            bool tmp[20] = { false };
                            tmp[t1] = true;
                            tmp[t2] = true;
                            tmp[t3] = true;
                            tmp[t4] = true;
                            tmp[t5] = true;
                            tmp[t6] = true;

                            int a1 = e - t1 - t2 - t3;
                            int a2 = a - t1 - t4 - t6;
                            int a3 = h - a2;
                            int a4 = b - t2 - t5 - a3;
                            int a5 = g - t6 - a4;
                            int a6 = c - t3 - a5;
                            int a7 = f - t4 - t5 - a6;

                            if (a1 > 13 || a1 <= 0|| tmp[a1])
                            {
                                continue;
                            } 
                            tmp[a1] = true;
                            if (a2 > 13 || a2 <= 0 || tmp[a2]) 
                            {
                                tmp[a1] = false;
                                continue;
                            }
                            tmp[a2] = true;
                            if (a3 > 13 || a3 <= 0 || tmp[a3]) 
                            {
                                tmp[a1] = false;
                                tmp[a2] = false;
                                continue;
                            }
                            tmp[a3] = true;
                            if (a4 > 13 || a4 <= 0 || tmp[a4]) 
                            {
                                tmp[a1] = false;
                                tmp[a2] = false;
                                tmp[a3] = false;
                                continue;
                            }
                            tmp[a4] = true;
                            if (a5 > 13 || a5 <= 0 || tmp[a5]) 
                            {
                                tmp[a1] = false;
                                tmp[a2] = false;
                                tmp[a3] = false;
                                tmp[a4] = false;
                                continue;
                            }
                            tmp[a5] = true;
                            if (a6 > 13 || a6 <= 0 || tmp[a6]) 
                            {
                                tmp[a1] = false;
                                tmp[a2] = false;
                                tmp[a3] = false;
                                tmp[a4] = false;
                                tmp[a5] = false;
                                continue;
                            }
                            tmp[a6] = true;
                            if (a7 > 13 || a7 <= 0 || tmp[a7]) 
                            {
                                tmp[a1] = false;
                                tmp[a2] = false;
                                tmp[a3] = false;
                                tmp[a4] = false;
                                tmp[a5] = false;
                                tmp[a6] = false;
                                continue;
                            }
                            tmp[a7] = true;
                            if (a1 + a7 != d) 
                            {
                                tmp[a1] = false;
                                tmp[a2] = false;
                                tmp[a3] = false;
                                tmp[a4] = false;
                                tmp[a5] = false;
                                tmp[a6] = false;
                                tmp[a7] = false;
                                continue;
                            }
                            int all = 0;
                            for (int i = 1; i <= 13; i++) 
                            {
                                if (tmp[i]=false) 
                                {
                                    all = 1;
                                    break;
                                }
                            }

                            if (all==0) 
                            {
                                answer++;
                            }

                        }
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}

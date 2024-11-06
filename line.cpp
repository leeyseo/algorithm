#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;



int main()
{
    int a1a, b1a, a2a, b2a;
    int x1a, y1a, x2a, y2a;
    cin >> a1a >> b1a >> a2a >> b2a;
    cin >> x1a >> y1a >> x2a >> y2a;
    int a1=min(a1a,a2a);
    int a2=max(a1a,a2a);
    int b1=min(b1a,b2a);
    int b2=max(b1a,b2a);
    int x1=min(x1a,x2a);
    int x2=max(x1a,x2a);
    int y1=min(y1a,y2a);
    int y2=max(y1a,y2a);

    if(x1<a1)
    {
        swap(a1,x1);
        swap(a2,x2);
        swap(b1,y1);
        swap(b2,y2);
    }

    double ans = 0.0;


    if ((b1 == b2)&&(x1==x2))//수평 수직
    {
        if((y2>=b1)&&(y1<=b1))
        {
            if(a1<=x1&&a2>=x1)
            {
                ans=0.0;
            }
            else if(a2<x1)
            {
                ans=abs(x1-a2);
            }
        }
        else if(y2<b1)
        {
            if(a1<=x1&&a2>=x1)
            {
                ans=abs(b1-y2);
            }
            else if(a2<x1)
            {
                ans=sqrt(pow((x1-a2),2)+pow(b1-y2,2));
            }
        }
        else if(y1>b1)
        {
            if(a1<=x1&&a2>=x1)
            {
                ans=abs(y1-b1);
            }
            else if(a2<x1)
            {
                ans=sqrt(pow((x1-a2),2)+pow(y1-b1,2));
            }
        }
    }
    if ((a1 == a2)&&(y1==y2))//수직 수평
    {
        if((b2>=y1)&&(b1<=y1))
        {
            if(x1<=a1&&x2>=a1)
            {
                ans=0.0;
            }
            else if(a1<x1)
            {
                ans=abs(x1-a2);
            }
        }
        else if(y1<b1)
        {
            if(x1<=a1&&x2>=a1)
            {
                ans=abs(b1-y1);
            }
            else if(a2<x1)
            {
                ans=sqrt(pow((x1-a2),2)+pow(b1-y2,2));
            }
        }
        else if(y1>b2)
        {
            if(a1<=x1&&a2>=x1)
            {
                ans=abs(y1-b2);
            }
            else if(a2<x1)
            {
                ans=sqrt(pow((x1-a2),2)+pow(y1-b2,2));
            }
        }
    }
    else if ((b1==b2)&&(y1==y2))//수평 수평
    {

        if ((a2 >= x1)&&(b1==y1))
        {
            ans=0.0;
        }
        else if(a2>=x1&&(b1!=y1))
        {
            ans=abs(y1-b1);
        }
        else
        {
            ans=sqrt(pow((x1-a2),2)+pow(abs(y1-b1),2));
        }
    }
    else if ((a1==a2)&&(x1==x2))//수직 수직
    {
        if(min(b2,y2)==b2)
        {
            if ((b2 >= y1)&&(a1==x1))
            {
                ans=0.0;
            }
            else if((b2 >= y1)&&(a1!=x1))
            {
                ans=abs(x1-a1);
            }
            else
            {
                ans=sqrt(pow((x1-a1),2)+pow(abs(y1-b2),2));
            }
        }
        else
        {
            if ((b1 <= y2)&&(a1==x1))
            {
                ans=0.0;
            }
            else if((b1 <= y2)&&(a1!=x1))
            {
                ans=abs(x1-a1);
            }
            else
            {
                ans=sqrt(pow((x1-a1),2)+pow(abs(b1-y2),2));
            }
        }
    }

    cout << fixed << setprecision(1) << ans << endl;
    
}

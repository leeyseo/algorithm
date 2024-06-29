#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


void bubble_sort(vector<int>&v, int n)
{
  int i, j, tmp;
  for(i = n-1; i > 0; i--)
  {
    for(j = 0; j < i; j++)
    {
      if(v[j] < v[j+1])
      {
        tmp = v[j];
        v[j] = v[j+1];
        v[j+1] = tmp;
      }
    }
  }
}


int main(void) 
{
  int num;
  cin>>num;
  vector<int>v;
  for(int i=0;i<num;i++)
  {
    int tmp;
    cin>>tmp;
    v.push_back(tmp);
  }
  // 버블 정렬 수행
  bubble_sort(v, num);

  // 정렬 결과 출력
  for(int i=0; i<num; i++)
  {
    cout<<v[i]<<" ";
  }
  return 0;
}

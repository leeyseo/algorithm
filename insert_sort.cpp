#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


void insert_sort(vector<int>&v, int n)
{
  int i, j, key;
  for(i = 1; i < n; i++)
  {
    key = v[i];
    for(j = i-1; j >= 0 && v[j] > key; j--)
    {
      v[j+1] = v[j];
    }
    v[j+1] = key;
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
  // 삽입 정렬 수행
  insert_sort(v, num);

  // 정렬 결과 출력
  for(int i=0; i<num; i++)
  {
    cout<<v[i]<<" ";
  }
  return 0;
}

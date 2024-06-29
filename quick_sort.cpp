#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


void quick_sort(int left, int right, vector<int>&v)
{
	int L = left, R = right;
	int pivot = (L + R) / 2; // 피벗을 중심으로 두었습니다.
	if (L < R)
	{
		while (L < R)
		{
			while (v[L] <= v[pivot]) L++;
			while (v[R] > v[pivot] && R > pivot) R--;
			if (L < R)  swap(v[L], v[R]);
		}
		swap(v[R], v[pivot]);
		pivot = R;
		quick_sort(left, pivot - 1, v);
		quick_sort(pivot + 1, right, v);
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
  quick_sort(0,num-1,v);

  // 정렬 결과 출력
  for(int i=0; i<num; i++)
  {
    cout<<v[i]<<" ";
  }
  return 0;
}

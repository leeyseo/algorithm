#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


void merge(int left, int right, vector<int>& v) {
    int mid = (left + right) / 2;

    vector<int> sorted(v.size()); // 임시 배열 대신 v 벡터를 직접 사용

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            sorted[k++] = v[i++];
        } else {
            sorted[k++] = v[j++];
        }
    }

    while (i <= mid) {
        sorted[k++] = v[i++];
    }
    while (j <= right) {
        sorted[k++] = v[j++];
    }

    for (int idx = left; idx <= right; idx++) {
        v[idx] = sorted[idx];
    }
}

void merge_sort(int left, int right, vector<int>&v)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2; 
		merge_sort(left, mid,v);
		merge_sort(mid + 1, right,v);
		merge(left, right, v);
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
  merge_sort(0, num-1,v);

  // 정렬 결과 출력
  for(int i=0; i<num; i++)
  {
    cout<<v[i]<<" ";
  }
  return 0;
}

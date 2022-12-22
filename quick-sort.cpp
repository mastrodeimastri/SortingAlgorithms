#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


// --------- QUICK SORT ---------

// funzione di supporto per scambiare valori
void swap(vector<int>& A, int i, int j)
{
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

// funzione di supporto che ordina i valori a seconda del pivot
int pivot(vector<int> A, int lo, int hi)
{
  int pivot = A[lo];
  int j = lo;
  for(int i = lo + 1; i <= hi; i++)
    {
      if(A[i] < pivot)
	{
	  j++;
	  swap(A, i, j);
	}
    }
  A[lo] = A[j];
  A[j] = pivot;

  return j;
}

void QuickSort(vector<int> A, int lo, int hi)
{
  if(lo < hi)
    {
      int j = pivot(A, lo, hi);
      QuickSort(A, lo, j - 1);
      QuickSort(A, j + 1, hi);
    }
}

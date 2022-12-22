#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// ---------- MERGE SORT ----------

void Merge(vector<int> A, int first, int last, int mid)
{
  vector<int> B; // vettore di appoggio
  int i,j,k,h;   // indici
  i = first;
  j = mid + 1; // primo elemento del secondo vettore

  while(i <= mid && j <= last) // finche' non ho esaurito nessuno dei due vettori
    {
      if(A[i] <= A[j])
	{
	  B.push_back(A[i]);
	  i++;
	}
      else
	{
	  B.push_back(A[j]);
	  j++;
	}
    }

  j = last;

  for(int h = mid; h > i; h--) // se mi sono rimasti degli elementi nel sottoarray di sx allora li sposto alla fine
    {
      A[j] = A[h];
      j--;
    }

  for(j = first; j < B.size(); j++)
    {
      A[j] = B[j];
    }
}

void MergeSort(vector<int> A, int first, int last)
{
  if(first < last)
    {
      int mid = floor((first + last) / 2);
      MergeSort(A, first, mid);
      MergeSort(A, mid + 1, last);
      Merge(A, first, last, mid);
    }
}

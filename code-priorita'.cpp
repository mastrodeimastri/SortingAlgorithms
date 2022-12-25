#include "heap.cpp"
#include <vector>
using namespace std;

/*
  Max priorita':
  - inserimento
  - extract_max
  - increase_key

  Min priorita':
  - inserimento
  - extract_min
  - decrease_key
 */


// implementazione code di massima priorita'

int heap_maximum(vector<int> A)
{
  return A.empty() ? -1 : A.at(0);
}

int heap_extract_max(vector<int>& A)
{
  if(A.empty()) return -1;
  
  int max(A.at(0));
  A.at(0) = A.at(A.size() - 1);
  
  A.pop_back();
  
  max_heapify(A, A.size(), 0);
  
  return max;
}

void increase_key(vector<int>& A, int i, int key)
{
  heap_increase_key(A, i, key);
}



// implementazione code di minima priorita'

// to be completed...

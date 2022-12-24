#include<iostream>
#include <vector>
#include <cmath>
#include "heap.cpp"
using namespace std;

/*
  Questo algoritmo di ordinamento si basa sulla tecnica del confronto ed
  e' effettuato in loco su un Heap (struttra dati ad albero completo o quasi completo)  
 */
void heap_sort(vector<int>& A)
{
  build_maxheap(A);
  int heap_size(A.size());
  for(int i(A.size() - 1); i >= 0; i--)
    {
      swap(A, 0, i);
      heap_size--;
      max_heapify(A, heap_size, 0);
    }
}

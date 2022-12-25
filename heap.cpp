#include <climits>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// funzione di supporto per scambiare valori
void swap(vector<int>& A, int i, int j)
{
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

// funzione che mi restituisce l'indice del padre
int parent(int i) { return floor(i/2); }

// funzione che mi restituisce l'indice del figlio sx
int left(int i) { return i*2; }

// funzione che mi restituisce l'indice del figlio dx
int right(int i) { return i*2 + 1; }


/*
  funzione di supporto che mi consente di far rispettare le
  carateristiche di un max_heap al mio vettore
*/
void max_heapify(vector<int>& A, int heap_size, int i)
{
  int max(i);
  int l(left(i));
  int r(right(i));

  if(l< heap_size && A.at(l) > A.at(i)) max = l;

  if(r < heap_size && A.at(r) > A.at(max)) max = r;

  if(i != max)
    {
      swap(A, i, max);
      max_heapify(A, heap_size ,max);
    }
}

/*
  funzione che mi consente di costruire un max_heap a partire da un qualsiasi vettore di interi
*/

void build_maxheap(vector<int>& A)
{
  for(int i(A.size()/2); i >= 0; i--) max_heapify(A, A.size() ,i);
}

void heap_increase_key(vector<int>& A, int i, int key)
{
  if(key < A.at(i))
    cout << "la chiave inserita e' piu' piccola di quella presente" << endl;

  A.at(i) = key;

  while (i > 0 && A.at(parent(i)) < A.at(i))
    {
      swap(A, i, parent(i));
      i = parent(i);
    }
}

void maxheap_insert(vector<int>&A, int key)
{
  A.push_back(INT_MIN);
  heap_increase_key(A, A.size() - 1, key);
}

/*
  Questa funzione mi permette di andare a cancellare l'elemento in posizione i del mio heap
  
  Pre condizione: il nodo all'indice i deve fare parte di un heap
  Post condizione: l'elemento in posizione i e' stato cancellato
 */

void heap_delete(vector<int>& A, int i)
{
  int val;
  if(A.size() == 1)
    A.pop_back();
  else
    {
      val = A.at(i);
      A.at(i) = A.at(A.size() - 1);
      A.pop_back();
    }

  if(val > A.at(i))
    max_heapify(A, A.size(), i);
  else
    {
      while(i > 1 && A.at(i) > A.at(parent(i)))
	{
	  swap(A, i, parent(i));
	  i = parent(i);
	}
    }
}

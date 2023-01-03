#include <algorithm>
#include <climits>
#include <cwctype>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Heap
{
  vector<int> v;
  int heap_size;

  Heap()
  {
    heap_size = 0;
  }
};

// funzione di supporto per scambiare valori
void swap(vector<int>& A, int i, int j)
{
  int temp = A.at(i);
  A.at(i) = A.at(j);
  A.at(j) = temp;
}

// funzione che mi restituisce l'indice del padre
int parent(int i) { return floor( ( i - 1 ) / 2 ); }

// funzione che mi restituisce l'indice del figlio sx
int left(int i) { return i*2 + 1; }

// funzione che mi restituisce l'indice del figlio dx
int right(int i) { return i*2 + 2; }


// ---------------- REFACTOR ------------------

void maxHeapify(Heap& H, int i)
{

  int left_child = left(i);
  int right_child = right(i);
  int max(i);

  // trovo il maggiore tra il padre e i due figli
  if(left_child <= H.heap_size && H.v.at(max) < H.v.at(left_child)) max = left_child;
  if(right_child <= H.heap_size && H.v.at(max) < H.v.at(right_child)) max = right_child;

  // se il maggiore era un figlio allora scambio il madre con il max chiamo la maxHeapify sul max
  if(max != i)
    {
          swap(H.v, i, max);
	  maxHeapify(H, max);	  
    }
}

/*
  COMPLESSITA' buildMaxHeap: O(nlog(n))

  COMPLESSITA' STRETTA: O(n)

  SPIEGAZIONE:

  la complessità di questa funzione è LIMITATA SUPERIORMENTE da nlog(n) in quanto io vado a chiamare la maxHeapify, il quale costo è log(n), n/2 volte.

  SPIEGAZIONE PRECISA:

  Osserviamo che la funzione maxHeapify per un nodo di altezza h è pari a O(h) ed il numero di nodi di altezza h è ceil(n/2^(h + 1)).
  Quindi la maxHeapify viene chiamata ceil(n/2^(h + 1)) per ogni altezza h.

  Quindi il costo della buildMaxHeap risulterà essere:

  sommatoria con h che va da 0 a log(n) di ceil(n/2^(h + 1))*O(h).

  questa sommatoria, una volta risolta, porterà ad avere un O(2n) per cui la complessità asintotica della funzioni si può dire che sia O(n)

 
 */

Heap buildMaxHeap(vector<int> v)
{
  // dichiaro ed inizializzo l'heap
  Heap H;
  H.v = v;
  H.heap_size = H.v.size() - 1;

  // chiamo la maxHeapify su ogni non a partire dal livello log(n) - 1, così facendo vado a costruire vari "sotto maxHeap"
  //che poi andranno a formare il maxHeap finale
  for(int i(floor(H.heap_size / 2)); i >= 0; i--)  maxHeapify(H, i);
  
  return H;
}

void heapIncrease(Heap& h, int i, int elem)
{
  if(elem < h.v.at(i))
    cout << "valore minore rispetto a quello gia' presente" << endl;
  else
    {
      h.v.at(i) = elem;
      while(i > 0 && elem > h.v.at(parent(i)))
	{
	  swap(h.v, i,parent(i));
	  i = parent(i);
	}
    }
}

void heapInsert(Heap& h, int elem)
{
  h.v.push_back(INT_MIN);
  heapIncrease(h, ++h.heap_size, elem);

}

void print(vector<int> v)
{
  for(int i(0); i < v.size(); i++)
    {
      cout << v.at(i) << endl;
    }
}

int main()
{
  vector<int> v = {16,4,10,14,7,9,3,2,8,1};
  
  Heap h = buildMaxHeap(v);

  print(h.v);

  heapInsert(h, 55);

  cout << "con inserimento:" << endl;
  print(h.v);
}

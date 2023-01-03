#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>

using namespace std;

void print(vector<int> v)
{
  for(int i(0); i < v.size(); i++)
    {
      cout << "elem : " << v.at(i) <<endl;
    }
}

// -------------- RIMPLEMENTAZIONE MERGE SORT -----------------

// COMPLESSITA' MERGE SORT = THETA(nlog(n))

/*
  SPIEGAZIONE:

  la complessità della funzione di mergesort può essere calcolata tramite il teorema master

  T(n) = 2T(n/2) + O(n)

  d = log_2(2) = 1

  g(n) = n = f(n)

  dato che f(n) = g(n) siamo nel secondo caso del master theorem, per cui T(n) = Theta(nlog(n))

  la complessità poteva anche essere calcolata tramite il metodo delle ricorrenze in quanto
  io ad ogni livello del mio albero ho una complessità pari ad O(n) e l'altezza è uguale a log(n).
  Da ciò ricaverei che la complessità totale della funzione è un O(nlog(n))
 */

void merge(vector<int>& v, int p, int middle, int r)
{
  vector<int> sup;
  int i(p);
  int j(middle + 1);

  cout << "array prima:" << endl;
  print(v);
  
  while(i <= middle && j <= r) // complessità pari a O(n)
    {
      if(v.at(i) <= v.at(j))
	{
	  sup.push_back(v.at(i++));
	}
      else
	{
	  sup.push_back(v.at(j++));
	}
    }

  j = r;

  for(int k = middle; k >= i; k--)
    {
      v.at(j) = v.at(k);
      j--;
    }

  
  for(int i(0); i < sup.size(); i++)
    v.at(i + p) = sup.at(i);

  cout << "array dopo:" << endl;
  print(v);
    
}
       

void mergesort(vector<int>& v, int p, int r)
{
  // vedere se il limite sinistro non supera quello destro
  if(p < r)
    {
      int middle = ( p + r ) / 2;
      mergesort(v, p, middle);
      mergesort(v, middle + 1, r);
      merge(v, p, middle, r);
    }

}

int main()
{
  vector<int> v = {16,4,10,14,7,9,3,2,8,1};

  print(v);

  mergesort(v, 0, v.size() - 1);

  cout << "merge" <<endl;

  print(v);



  return 0;
}

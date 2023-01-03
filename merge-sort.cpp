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

void merge(vector<int>& v, int p, int middle, int r)
{
  vector<int> sup;
  int i(0);
  int j(middle + 1);

  while(i <= middle && j <= r) // complessità pari a O(n)
    {
      if(v.at(i) <= v.at(j))
	{
	  sup.push_back(v.at(i));
	  i++;
	}
      else
	{
	  sup.push_back(v.at(j));
	  j++;
	}
    }

  j = r;
  
  for(int k = middle; k >= i; k--)
    {
      v.at(j) = v.at(k);
      j--;
    }

  
  for(int k(0); k < sup.size(); k++)
    v.at(k) = sup.at(k);
  
    
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
  vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};

  print(v);

  mergesort(v, 0, v.size() - 1);

  cout << "merge"<<endl;

  print(v);

  return 0;
}

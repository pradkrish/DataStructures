
// Hash table using separate chaining technique

#include "hashtable.cpp"

using namespace std;

int main()
{
  std::cout << "separate chaining technique" << std::endl;
  hashTable<int,std::string>* ht = new hashTable<int,std::string>();

  bool b = ht->isEmpty();
  if(b)
    cout << "Hash table is empty";
  else
    cout << "Hash table is not empty";
  cout << endl;

  cout << "Adding a data" << endl;
  ht->Insert(434, "Dylan");
  b = ht->isEmpty();
  if(b)
    cout << "Hash table is empty";
  else
    cout << "Hash table is not empty";
  cout << endl;

  // Adding others data
  ht->Insert(391132, "adam");
  ht->Insert(85406, "bob");
  ht->Insert(12317, "cindy");
  ht->Insert(548989, "daniel");
  ht->Insert(66923, "elin");
  ht->Insert(72298, "fanny");
  ht->Insert(276465, "gina");
  ht->Insert(566953, "hannah");
  ht->Insert(89795, "ida");

  int key = 72298;
  cout << "Search value for key: "<<endl;
  string name = ht->Search(key);
  if(name != "")
    cout << "Value for key " << key << " is " << name;
  else
    cout << "Value for key " << key << " is not found";
  
  cout << endl;
  
  return 0;
}

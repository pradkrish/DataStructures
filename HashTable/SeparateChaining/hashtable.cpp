  
#include "hashtable.hpp"

template <typename T1, typename T2>
hashTable<T1,T2>::hashTable()
{
  for (int i = 0; i < TABLE_SIZE; ++i)
    table[i].clear();
}

template <typename T1, typename T2>
int hashTable<T1,T2>::hashFunction(T1 key)
{
  return key%TABLE_SIZE;
}

template <typename T1, typename T2>
bool hashTable<T1,T2>::isEmpty()
{
  int totalElements = 0;

  for (int i = 0; i < TABLE_SIZE; ++i)
    totalElements += static_cast<int>(table[i].size());

  return (totalElements > 0) ? false : true;
}

template <typename T1, typename T2>
void hashTable<T1,T2>::Insert(T1 key, T2 value)
{
  bool isKeyFound = false;
  int hashKey = hashFunction(key);
  for (auto& k:table[hashKey])
  {
    if (k.first == key)
    {
      isKeyFound = true;
      k.second = value;
    }
  }

  if (!isKeyFound)
    table[hashKey].emplace_back(key,value);
}

template <typename T1, typename T2>
T2 hashTable<T1,T2>::Search(T1 key)
{
  int hashKey = hashFunction(key);
  for (auto& k:table[hashKey])
  {
    if (k.first == key)
      return k.second;
  }
  return "";
}

template <typename T1, typename T2>
void hashTable<T1,T2>::Remove(T1 key)
{
  int hashKey = hashFunction(key);

  for(auto it = table[hashKey].begin(); it != table[hashKey].end(); ++it)
  {
    if (it->first == key)
    {
      table[hashKey].erase(it);
      break;
    }
  }
}



#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>

#define TABLE_SIZE 8

template <typename T1, typename T2>
class hashTable
{
private:
  std::list<std::pair<T1,T2>> table[TABLE_SIZE];
  int hashFunction(T1 key);
public:
  hashTable();
  bool isEmpty();
  void Insert(T1 key, T2 value);
  T2 Search(T1 key);
  void Remove(T1 key);
};

#endif

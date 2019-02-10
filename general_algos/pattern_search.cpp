
// Finds multiple occurences of pattern in a target string

#include <iostream>
#include <vector>

using namespace std;

vector<int> Search(string& mainStr, string& pattern)
{
  // returns all the found indices as a vector
  vector<int> indices;
  int strLen = mainStr.size();
  int patLen = pattern.size();

  if (patLen <= strLen)
  {
    for (int i = 0; i <= strLen; ++i)
    {
      int j;
      for (j = 0; j < patLen; ++j)
      {
	if (mainStr[i+j] != pattern[j])
	  break;
      }

      if (j == patLen)
	indices.push_back(i);
    }
  }

  return indices;
}

int main()
{
  string mainStr {"to be or not to be"};
  string pattern {"to"};

  vector<int> indices = Search(mainStr, pattern);

  if(indices.size() > 0)
  {
    cout << "pattern found at indices ";
    for (vector<int>::iterator it = indices.begin();
	 it != indices.end(); ++it)
      cout << *it << " ";
  }
  else
    cout << "not found";
  cout << endl;
  
  return 0;
}


// check whether the sequence (substring) is a part of mainstring

#include <iostream>
using namespace std;

bool isSubsequence(string& str1, string& str2, int x, int y)
{
  if (x == 0)
    return true;

  if (y == 0)
    return false;

  if (str1[x - 1] == str2[y - 1])
    return isSubsequence(str1, str2, x - 1, y - 1);
  else
    return isSubsequence(str1, str2, x, y - 1);
}

int main()
{
  cout << "subsequence search" << endl;
  std::string mainString {"Christmas"};
  std::string subString {"has"};

  cout << endl;
  if (isSubsequence(subString, mainString,
		    subString.size(), mainString.size()))
    cout << subString << " is a subsequence of "<<mainString<< endl;
  else
    cout << subString << " is not a subsequence of "<<mainString<< endl;
  return 0;
}

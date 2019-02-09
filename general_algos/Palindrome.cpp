#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(string& str)
{
  transform(str.begin(),str.end(),str.begin(),::tolower);
  // erase-remove idiom to remove all blanks
  str.erase(remove(str.begin(),str.end(), ' '),str.end());

  int left = 0;
  int right = str.length() - 1;
  while(right > left)
  {
    if(str[left++] != str[right--])
    {
      return false;
    }
  }

  return true;
}

int main()
{
  cout << "Palindrome" <<endl;

  std::string str {"radar"};
  
  if(isPalindrome(str))
    cout << "The string " << str << " is a palindrome" << endl;
  else
    cout << "The string " << str << " is not a palindrome" << endl;
  return 0;
}

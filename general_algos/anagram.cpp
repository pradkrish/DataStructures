
#include <iostream>
#include <algorithm>

using namespace std;

bool isAnagram(std::string& s1, std::string& s2)
{
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

  // erase-remove idiom to remove all blanks
  s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
  s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());

  // sort and compare
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  return s1 == s2;
}


int main()
{
  std::string string1 {"SCHOOL MASTER"};
  std::string string2 {"THE CLASSROOM"};

  bool result = isAnagram(string1, string2);

  if(result)
    cout<<"they are anagrams"<<endl;
  else
    cout<<"they are not anagrams"<<endl;
  
  return 0;
}

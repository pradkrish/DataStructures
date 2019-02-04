// A very interesting application of stack is to find the
// validity of parenthesis expressions like {()}.
// Running the following code will prompt for a user input
// example(s) of valid expression(s): {()[{}]}
// example(s) of invalid expression(s): {([)}] and {()}[

#include <iostream>
#include "Stack.cpp"

bool isValid(std::string& s)
{
  int len = s.size();
  Stack<char> stack = Stack<char>();
  
  for (int i = 0; i < len; ++i)
  {
    if (s[i] == '(')
      stack.Push('(');
    else if (s[i] == '{')
      stack.Push('{');
    else if (s[i] == '[')
      stack.Push('[');
    else if (s[i] == ')' ||
	     s[i] == '}' ||
	     s[i] == ']')
    {
      if(s[i] == ')' &&
	      (stack.IsEmpty() || stack.Top() != '('))
	return false;
      else if(s[i] == '}' &&
	      (stack.IsEmpty() || stack.Top() != '{'))
	return false;
      else if(s[i] == ']' &&
	      (stack.IsEmpty() || stack.Top() != '['))
	return false;
      else
	stack.Pop();
      
    }
  }

  if (stack.IsEmpty())
    return true;
  else
    return false;
}


int main()
{
  std::string expression;
  std::cout << "Please type the parenthesis expression ";
  std::cout << "then press ENTER!" << std::endl;
  std::cin>>expression;
  std::cout<<std::endl;
  
  bool result = isValid(expression);

  std::cout << "The " << expression << " expression is ";
  if(result)
    std::cout << "valid";
  else
    std::cout << "invalid";
  std::cout << std::endl;
  return 0;
}

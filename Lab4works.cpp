//Lab04.cpp
//Reece Barritt
//2-18-25

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


//function declarations
string stringReverse(string toReverse);
bool parenCheck(string toCheck);

/*DO NOT CHANGE MAIN OR THE FUNCTION DECLARATIONS*/
int main()
{
  //paren strings
  string paren1 = "(()((((()()()((()(((()()()()(((()(()()()(())()())()()))))()()()))()))()())())())))";
  string paren2 = "()((((((()(((((()((()()()()()(()))))))))()))()(())(())(((((()()(())))(()()())(()))";
  string paren3 = "(()((()(()()(()(((((()()(()()()((((()()(()()))()))))()()())))))()()())()()))())())";
  string paren4 = "(()()(((()()(()(()()(()()()()()()(()(((((((((())())))))()))))()()))()())()()))()))";
  string paren5 = "((())";
  string paren6 = ")))(((";

  string rev1 = "sekopog";
  string rev2 = "racecar";
  string rev3 = "regnolsignirtssiht";
  string rev4 = "wonybnwodsihtevahyllufepohdluohssyuguoy";

  //Ignore this for now, these vectors are just part of the program
  vector<string> parens;
  parens.push_back(paren1);
  parens.push_back(paren2);
  parens.push_back(paren3);
  parens.push_back(paren4);
  parens.push_back(paren5);
  parens.push_back(paren6);

  vector<string> rever;
  rever.push_back(rev1);
  rever.push_back(rev2);
  rever.push_back(rev3);
  rever.push_back(rev4);
  
  //call the parenCheck
  for(int i=0; i<6; i++)
  {
    cout<<"Checking string"<<i+1<<endl;
    if(parenCheck(parens.at(i)))
    {
      cout<<"Your code says that string"<<i+1<<" is good.";
      if(i == 0 || i == 2 || i==3)
      {
        cout<<" Correct!"<<endl<<endl;
      }
      else
      {
        cout<<" Incorrect!"<<endl<<endl;
      }
    }
    else
    {
      cout<<"Your code says that string"<<i+1<<" is bad.";
      if(i == 1 || i == 4 || i==5)
      {
        cout<<" Correct!"<<endl<<endl;
      }
      else
      {
        cout<<" Incorrect!"<<endl<<endl;
      }
    }
  }

  //now to reverse some strings
  for(int i =0; i<4; i++)
  {
    cout<<"Reversing string"<<i+1<<endl;
    cout<<stringReverse(rever.at(i))<<endl<<endl;
  }
}

//This function takes a string and reverses it using a stack
//it returns the reversed string
string stringReverse(string toReverse)
{
  stack<char> reverse; 
  string newstring = "";
  for (char c : toReverse) {
    reverse.push(c);
}

// Pop characters from the stack to form the reversed string
while (!reverse.empty()) {
    newstring.push_back(reverse.top());
    reverse.pop();
}

return newstring;
}
  

//this function uses a queue to check if a string of parens is properly matched
bool parenCheck(string toCheck)
{
  queue<char> checker; //declare my queue
  int paren_balanced = 0; 

  for (char ch : toCheck)
  {
    if (ch == '(')
    {
      checker.push(ch); 
      paren_balanced++;
    }
    else if (ch == ')')
    {
      if (paren_balanced == 0)
      {
        return false; 
      }
      checker.pop(); 
      paren_balanced--;
    }
  }

  if (paren_balanced == 0)
  {
    return true; 
  }
  return false; //need a return statement to compile
}

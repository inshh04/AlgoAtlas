#include<iostream>
#include<string.h>
using namespace std;


bool isbalanced(string s)
{
    int size=s.size();
    char* stack=new char[size];
    int top=-1;
    for(int i=0;i<size;i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {
         top++;
         stack[top]=s[i];
        }
        else if(s[i]==')')
        {
            if(stack[top]=='(')
            top--;
        }
        else if(s[i]=='}')
        { 
            if(stack[top]=='{')
            top--;
        }
        else if(s[i]==']')
        {
        if(stack[top]=='[')
            top--;
        }

    }
    if(top==-1)
    return true;
    else 
    return false;
}


int main()
{
    string s;
    cout<<"enter the string\n";
    cin>>s;
    if(isbalanced(s))
    cout<<"the expression is balanced\n";
    else
    cout<<"the expression is unbalanced\n";
}

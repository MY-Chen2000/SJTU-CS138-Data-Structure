#include <iostream>
#include"stack2.h"

using namespace std;

bool isoperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='/'||ch=='^'||ch=='('||ch==')')
        return true;
    else return false;
}

string its(const string &infix)
{
    seqstack<char> opstack;     //运算符栈
    string result=" ";           //保存后缀表达式
    char topop;

    for(int i=0;i<infix.size();++i)
    {
        if(infix[i]==' ')continue;

        switch(infix[i])
        {
        case')':
            while(!opstack.isempty()&&(topop=opstack.pop())!='(')
            {
                result+=' ';
                result+=topop;
            }
            if(topop!='(')
            {
                cerr<<"缺左括号"<<endl;
                return "error";
            }
            break;

        case'(':opstack.push('(');break;
        case'^':opstack.push('^');break;
        case'*':case'/':
            while(!opstack.isempty()&&(opstack.top()=='*'||opstack.top()=='/'||opstack.top()=='^'))
            {
                result+=' ';
                result+=opstack.pop();
            }
            opstack.push(infix[i]);
            break;
        case'+':case'-':
            while(!opstack.isempty()&&opstack.top()!='(')
            {
                result+=' ';
                result+=opstack.pop();
            }
            opstack.push(infix[i]);
            break;
        default:
            if(!result.empty())result+=' ';
            while(i<infix.size()&&!isoperator(infix[i])&&infix[i]!=' ')
            {
                result+=infix[i];
                ++i;
            }
            --i;
        }
    }


    while(!opstack.isempty())
    {
        if(opstack.top()=='(')return "error";
        result+=' ';
        result+=opstack.pop();
    }

    return result;

}

int main()
{
   cout<<its("( 5 + 6 *(7+3) /3)/4+5");
    return 0;
}

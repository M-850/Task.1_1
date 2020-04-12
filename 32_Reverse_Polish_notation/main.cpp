#include <QCoreApplication>
#include<iostream>
#include<Qstack>
#include<string>
#include<math.h>
std::string reverse_polish_notation(std::string str)
{
    char check = NULL;
    std::string str_ret;
    QStack<char>stk;
    for(int counter = 0 ; str[counter]; counter++){
    switch (str.at(counter)) {
    case '(':
    {
        stk.push('(');
        check = '(';
        break;
    }
    case '+':
    {

        if(check=='-'||check=='+'||check=='*'||check=='/')
        {
        str_ret += stk.pop();
        str_ret += ' ';
        }
        check='+';
        stk.push('+');
        break;
    }
    case '-':
    {
        if(check=='-'||check=='+'||check=='*'||check=='/'|| check =='^')
        {
        str_ret += stk.pop();
        str_ret += ' ';
        }
        stk.push('-');
        check='-';
        break;
    }
    case '*':
    {
        if(check=='*'||check=='/'|| check =='^')
        {
            str_ret +=stk.pop();
            str_ret += ' ';
        }
        stk.push('*');
        check = '*';
        break;
    }
    case '/':
    {
        if(check=='*'||check=='/'|| check =='^')
        {
            str_ret +=stk.pop();
            str_ret += ' ';
        }
        stk.push('/');
        check = '/';
        break;
    }
    case '^':
    {
         if(check =='^')
         {
         str_ret += stk.pop();
         str_ret += ' ';
         }
         stk.push('^');
         check='^';
         break;
    }
    case ')':
    {
        for(int i=0; ;i++)
        {
            char temp = stk.pop();
            if(temp == '(')
            {
                break;
            }
            else
            {
             str_ret += temp;
             str_ret += ' ';
            }
        }
        break;
    }
    case '.':
    {
        str_ret.resize(str_ret.size()-1);
        str_ret += '.';
    }
    case ' ':
    {
        break;
    }

    default:
    {
        str_ret += str.at(counter);
        str_ret += ' ';
        break;
    }
    }

}
    while(!stk.empty())
    {
        str_ret += stk.pop();
        str_ret += ' ';
    }
    return str_ret;
}

double Result(std::string str)
{
    QStack<double>stk;
    char temp = NULL;
    int counter = 0;
    bool check = false;
    bool check_2 = false;
    for(int i = 0; str[i]; i++){
    switch (str[i]) {
    case'+':
    {
        stk.push(stk.pop()+stk.pop());
        break;
    }
    case'-':
    {
        temp = stk.pop();
        stk.push(stk.pop()-temp);
        break;
    }
    case'*':
    {
        stk.push(stk.pop()*stk.pop());
        break;
    }
    case'/':
    {
        temp = stk.pop();
        stk.push(stk.pop()/temp);
        break;
    }
    case'^':
    {
        temp = stk.pop();
        stk.push(pow(stk.pop(),temp));
        break;
     }
    case'.':
    {
        check_2 = true;
        break;
    }
    case'0':
    {
      if(check_2)
      {
          counter--;
           //stk.push(stk.pop()+pow(1,counter));
      }
     else if(check)
      {
          stk.push(stk.pop()*10);
      }

        check =true;
       break;
    }
    case'1':
    {
      if(check_2)
      {
          counter--;
           stk.push(stk.pop()+pow(10,counter));
      }
     else if(check)
      {
          stk.push(stk.pop()*10+1);
      }
      else
      {
         stk.push(1);
      }

        check =true;
       break;
    }
    case'2':
    {
      if(check_2)
      {
          counter--;
           stk.push(stk.pop()+ 2*pow(10,counter));
      }
     else if(check)
      {
          stk.push(stk.pop()*10+2);
      }
      else
      {
         stk.push(2);
      }
        check =true;
       break;
    }

    case'3':
    {
      if(check_2)
      {
          counter--;
           stk.push(stk.pop()+3*pow(10,counter));
      }
     else if(check)
      {
          stk.push(stk.pop()*10+3);
      }
      else
      {
         stk.push(3);
      }
        check =true;
       break;
    }
    case'4':
    {
      if(check_2)
      {
          counter--;
           stk.push(stk.pop()+4*pow(10,counter));
      }
     else if(check)
      {
          stk.push(stk.pop()*10+4);
      }
      else
      {
         stk.push(4);
      }
        check =true;
       break;
    }
    case'5':
    {
      if(check_2)
      {
          counter--;
           stk.push(stk.pop()+5*pow(10,counter));
      }
     else if(check)
      {
          stk.push(stk.pop()*10+5);
      }
      else
      {
         stk.push(5);
      }
        check =true;
       break;
    }
    case'6':
    {
      if(check_2)
      {
          counter--;
           stk.push(stk.pop()+6*pow(10,counter));
      }
     else if(check)
      {
          stk.push(stk.pop()*10+6);
      }
      else
      {
         stk.push(6);
      }
        check =true;
       break;
    }
    case'7':
    {
      if(check_2)
      {
          counter--;
           stk.push(stk.pop()+7*pow(10,counter));
      }
     else if(check)
      {
          stk.push(stk.pop()*10+7);
      }
      else
      {
         stk.push(7);
      }
        check =true;
       break;
    }
    case'8':
    {
      if(check_2)
      {
          counter--;
           stk.push(stk.pop()+8*pow(10,counter));
      }
     else if(check)
      {
          stk.push(stk.pop()*10+8);
      }
      else
      {
         stk.push(8);
      }
        check =true;
       break;
    }
    case'9':
    {
      if(check_2)
      {
          counter--;
           stk.push(stk.pop()+9*pow(10,counter));
      }
     else if(check)
      {
          stk.push(stk.pop()*10+9);
      }
      else
      {
         stk.push(9);
      }
        check =true;
       break;
    }
   default:
    {
        check = false;
        check_2 = false;
        counter = 0;
        break;
    }
    }
    }

    return stk.pop();
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::string str;
    getline(std::cin, str, '\n');
    std::string str_2;
    str_2 = reverse_polish_notation(str);
    std::cout << str_2 <<std::endl;
    std::cout << Result(str_2)<<std::endl;
    return a.exec();
}

﻿#include <iostream>
#include<exception>
#include <typeinfo>
using namespace std;
class MyException1:public exception
{
public:
    MyException1() {};
    ~MyException1() {};
    const char* what() { return typeid(MyException1).name(); }
};
class MyException2:public exception
{
public:
    MyException2() {};
    ~MyException2() {};
    const char* what() { return typeid(MyException2).name(); }
};
int divide(int a, int b)
{
    if (b == 0)throw b;
    return a/b ;
}
int  main()
{
    int  id, k;
    cin >> id;
    char  a;
    string  s = "hello";
    try
    {
        switch (id)
        {
        case  1:
            throw  MyException1();
            break;
        case  2:
            throw  MyException2();
            break;
        case  3:
            k = divide(8, 0);
            break;
        case  4:
            a = s.at(10);
            cout << a << endl;
            break;
        default:
            break;
        }
    }
    catch (MyException1& e)
    {
        cout << "exception:  " << e.what() << endl;
    }
    catch (MyException2& e)
    {
        cout << "exception:  " << e.what() << endl;
    }
    catch (int& e)
    {
        cout << "exception:  " << e << endl;
    }
    catch (exception& e)
    {
        cout << "exception:  " << e.what() << endl;
    }
    cout << "Return  to  main()" << endl;
    return  0;
}


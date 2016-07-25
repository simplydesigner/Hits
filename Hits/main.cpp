#include <iostream>

class Widget
{
    
};

const Widget & operator++(const Widget &lhs)// lvalue-ссылка может быть инициализирована rvalue-объектом, если только она не является константной
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return lhs;
}

int f1(int param)
{
    return param;
}
Widget f1(Widget param)
{
    return param;
}

int & f2(int & param)
{
    return param;
}
Widget & f2(Widget & param)
{
    return param;
}

int && f3(int && param)
{
    return std::move(param);
}
Widget && f3(Widget && param)
{
    return std::move(param);
}

int * f4(int param)
{
    return new int(param);
}
Widget * f4(Widget param)
{
    return new Widget(param);
}

int main(int argc, const char * argv[]) {
    
    int value = 0;
    ++f1(value);
    ++f2(value);
    ++f3(std::move(value));
    ++f4(value);
    
    Widget widget;
    ++f1(widget);
    ++f2(widget);
    ++f3(std::move(widget));
    ++f4(widget);
    
    
    return 0;
}

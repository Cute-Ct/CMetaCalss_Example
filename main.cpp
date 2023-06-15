#include <iostream>

#include <qobject.hpp>


class Test : public QObject
{

};

int main(int, char**){
    std::cout << "Hello, from QTest!\n";

    Test test;

    return test.staticMetaObject.methodCount();
}

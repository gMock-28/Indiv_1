#include <QtTest>
#include "../Indiv/List.h"
#include "../Indiv/List.cpp"
// add necessary includes here

class Test1 : public QObject
{
    Q_OBJECT

public:
    Test1();
    ~Test1();

private slots:
    void IsEmpty();
    void checkElem();
    void count();

};

Test1::Test1()
{

}

Test1::~Test1()
{

}

void Test1::IsEmpty()
{
    List x;
    QCOMPARE(x.isEmpty(),true);
    x.addFirst("Key_1", 1);
    QCOMPARE(x.isEmpty(),false);
}

void Test1::checkElem()
{
    List x;
    x.addFirst("Key_1", 1);
    QCOMPARE(x.checkElem("Key_1",1),true);
}

void Test1::count()
{
    List x;
    x.addFirst("Key_1", 1);
    x.addFirst("Key_2", 2);
    QCOMPARE(x.count(),2);
}



QTEST_APPLESS_MAIN(Test1)

#include "tst_test1.moc"

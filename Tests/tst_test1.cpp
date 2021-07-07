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
    void checkElem();

};

Test1::Test1()
{

}

Test1::~Test1()
{

}

void Test1::checkElem()
{
    List x;
    x.addFirst("Key_1", 1);
    QCOMPARE(x.checkElem("Key_1",1),true);

}

QTEST_APPLESS_MAIN(Test1)

#include "tst_test1.moc"

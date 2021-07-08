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
    void sorting();
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
    QCOMPARE(x.checkElem("Key_1",0),false);
    QCOMPARE(x.checkElem("Key_one",1),false);
}

void Test1::count()
{
    List x;
    x.addFirst("Key_1", 1);
    x.addFirst("Key_2", 2);
    QCOMPARE(x.count(),2);
}

void Test1::sorting()
{
    List a1;
    a1.addFirst("Key_1", 1);
    a1.addFirst("Key_2", 2);
    a1.addFirst("Key_3", 3);
    a1.addFirst("Key_4", 4);

    List a2;
    a2.addFirst("Key_1", 1);
    a2.addLast("Key_2", 2);
    a2.addFirst("Key_3", 3);
    a2.addLast("Key_4", 4);

    //cout examples
    cout << a1;
    cout << a2;
    a2.sorting();
    cout << a2;

    for (int i = 0; i < 4; i++) {
        QCOMPARE(a1["Key_" + to_string(i)],a2["Key_" + to_string(i)]);
    }

}

QTEST_APPLESS_MAIN(Test1)

#include "tst_test1.moc"

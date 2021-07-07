#include <QCoreApplication>
#include <iostream>
#include <string>
#include "List.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    List x;

    x.addFirst("Key_1", 0);
    x.addFirst("Key_2", 1);
    x.addFirst("Key_3", 2);

    cout << x;
    cout << x["Key_1"] << endl;

    cout << "Number of elements: " << x.count() << endl << endl;

    cout << "Is elem ('Key_1', 0) is in the list: " << x.checkElem("Key_1", 0) << endl << endl;

    x.delLast();

    cout << x;
    cout << "Number of elements: " << x.count() << endl;

    cout << x["Key_2"] << endl;

    List words;

    ifstream in;
    in.open("C:/Users/Matthew/Desktop/popka/Indiv/in.txt");

    string word;
    while (in>>word) {
       words.addFirst(word, 1);
    }

    cout << words;

    // ------------------

    return a.exec();
}

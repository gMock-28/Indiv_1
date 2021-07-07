#include <QCoreApplication>
#include <iostream>
#include <string>
#include "List.h"
#include <fstream>

using namespace std;

string Path = "/Users/Gold_Mock/Indiv_1/Indiv/in.txt";
//string Path = "C:/Users/Matthew/Desktop/popka/Indiv/in.txt";

List Task(string path) {
    List words;
    string word;

    ifstream in;
    in.open(path);

    while (in>>word) {
       if (words[word] == -1) {
           words.addLast(word, 1);
       } else {
           words.raiseValue(word);
       }
    }

    return words;
}


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

    cout << x["Key_2"] << endl << endl;

    cout << Task(Path);

    // ------------------

    return a.exec();
}

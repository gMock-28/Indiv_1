#include <QCoreApplication>
#include <iostream>
#include <string>
#include "List.h"

#include <map>
#include <fstream>



using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*
    //Создали ассоц. массив words
    map <string,int> words;

    //Подключили исходный файлик
    ifstream in;
    in.open("/Users/Gold_Mock/Indiv_1/Indiv/in.txt");

    //Подключили исходный файлик
    string word;
    while (in>>word) {
        words[word]++;
    }

    int count = 0;

    //Подрубили итератор
    map <string,int>::iterator cur;

    cout <<"Words count:"<< endl;

    for (cur=words.begin();cur!=words.end();cur++) {
        cout << (*cur).first<<": " << (*cur).second << endl;count+=(*cur).second;
    }
    */

    List x;

    x.addFirst("Privet", 0);
    x.addFirst("Privet_1", 1);

    cout << x;
    cout << "Number of elements: " << x.count() << endl << endl;

    cout << "Is elem ('Privet_1', 0) is in the list: " << x.checkElem("Privet_1", 0) << endl << endl;

    x.delLast();
    x.delLast();


//    for(int i = 0; i < 5; ++i) {
//        x.delLast();
//    }

    cout << x;
    cout << "Number of elements: " << x.count() << endl;

    return a.exec();
}

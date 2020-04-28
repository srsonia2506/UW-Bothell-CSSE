#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <cstdlib>
using namespace std;

int main() {
    string line;
    int linecount, charcount, wordcount;

    ifstream ifs("ReadBook.cpp");
    if (!ifs.is_open()) {
        cout  << "Cannot find file" << endl;
        exit(0);
    }

    istream_iterator<string> in{ifs}, end;
    wordcount=distance(in, end);

    if (ifs.is_open()){
        while (getline(ifs, line)) {
            cout << line << endl;
            linecount++;
            charcount += line.length();
        }
    }
    ifs.close();

    cout << charcount << " characters and " << wordcount << " words within " << linecount << " lines." << endl;

    return 0;
}


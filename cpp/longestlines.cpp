//Write a program which reads a file and prints to stdout the specified number of the longest lines that are sorted based on their length in descending order.

//INPUT SAMPLE:
//Your program should accept a path to a file as its first argument. The file contains multiple lines. The first line indicates the number of lines you should output, the other lines are of different length and are presented randomly. You may assume that the input file is formatted correctly and the number in the first line is a valid positive integer.

#include <iostream>
#include <queue>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

class comparator {
public:

    bool operator()(const string &s1, const string &s2) {
            return s1.length() > s2.length();
    }
};

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;

    // Get input length
    getline(stream,line);
    unsigned number_of_lines = atoi(line.c_str());

    priority_queue<string, vector<string>, comparator> pq;

    while (number_of_lines-- && getline(stream, line)) {
        pq.push(line);
    }
    
    while (getline(stream,line)) {
        pq.push(line);
        pq.pop();
    }

    list<string> l;
    while(!pq.empty()) {
        l.push_front(pq.top());
        pq.pop();
    }

    std::copy(l.begin(),l.end(),std::ostream_iterator<string>(cout,"\n"));

    return 0;
} 

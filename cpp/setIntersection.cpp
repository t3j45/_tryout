//You are given two sorted list of numbers (ascending order). The lists themselves are comma delimited and the two lists are semicolon delimited. Print out the intersection of these two sets.

//INPUT SAMPLE:
//File containing two lists of ascending order sorted integers, comma delimited, one per line

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(int argc, char *argv[]) {
    
    ifstream stream(argv[1]);
    string line;

    while (getline(stream, line)) {
        
        stringstream ss(line);
        unordered_set<int> set1;
        int buf;
        
        while(ss>>buf) {
            set1.insert(buf);
            if (ss.peek() == ',')
                ss.ignore();
            if (ss.peek() == ';') {
                ss.ignore();
                break;
            }
        }
        vector<int> intersection;
        while(ss>>buf) {
 
            if (set1.find(buf) != set1.end())
                intersection.push_back(buf);
            if (ss.peek() == ',')
                ss.ignore();
        }


        if (!intersection.empty()) {
        
            vector<int>::iterator i = intersection.begin();
            cout<<*i++;
            for(; i!=intersection.end(); ++i)
                cout<<","<<*i;
        }
        cout<<endl;
        
    }
    return 0;
}

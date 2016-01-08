//You are given a prefix expression. Write a program which evaluates it.

//INPUT SAMPLE:
//Your program should accept a file as its first argument. The file contains one prefix expression per line.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <cctype>

using namespace std;

string evaluate(string &op, string &item1, string &item2) {
    double i1 = stod(item1.c_str());
    double i2 = stod(item2.c_str());
    double result = 0;    
    char operation = op[0];

    switch(operation) {
    
    case '*':
        result = i1*i2;
        break;
        
    case '+':
        result = i1+i2;
        break;
        
    case '/':
    	result = i2/i1;
    	break;
    	
    default :
        result = -1;
    }
#ifdef DEBUG    
   cout<<"evaluate("<<op<<", "<<item1<<", "<<item2<<") = "<<result<<endl;
#endif
    return to_string(result);
}

bool isNum(string &num) {
    for (auto &ch: num)
        if (!isdigit(ch))
            if (ch != '.')
                return false;
    return true;
}

void evaluate(string &expression) {

    stringstream ss(expression);
    string buffer;
    stack<string> s;
    
    ss>>buffer;
    s.push(buffer);
    ss>>buffer;
    s.push(buffer);
    
    while(ss>>buffer) {
#ifdef DEBUG
        cout<<"Buffer "<<buffer<<endl;
#endif
        s.push(buffer);
        while(s.size() > 1) {
            string item1 = s.top();
            s.pop();
            string item2 = s.top();
            s.pop();
#ifdef DEBUG
            cout<<"Popping "<<item2<<", "<<item1<<endl;
#endif
            if (isNum(item1) && isNum(item2)) {
                
                string op = s.top();
                s.pop();
                if (!isNum(op)) {
                    s.push(evaluate(op,item1,item2));
                }
                else {
                    s.push(op);
                    s.push(item2);
                    s.push(item1);
                    break;
                }
            }
            else {
                s.push(item2);
                s.push(item1);
                break;
            }
        }
    }
//    cout<<"Solution:";
    cout<<stoi(s.top())<<endl;
    
}

class prefixexpression {

    int execute(int argc, char *argv[]) {
        //ifstream stream(argv[1]);
        //string line("+ + * 5 6 2 + * 4 * 7 1 9");
        string line(" + 1 3");
        //while (getline(stream, line)) {
            evaluate(line);
        //}
        return 0;
}
};

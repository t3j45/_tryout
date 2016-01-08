//There are two strings: A and B. Print 1 if string B occurs at the end of string A. Otherwise, print 0.
//The first argument is a path to the input filename containing two comma-delimited strings, one per line. Ignore all empty lines in the input file.

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

unsigned process(string _str_in) {
    std::string _str_main, _str_trail;
    unsigned _ui_out = 0;
    
    {
        char buffer[1000] = {0};
        std::sscanf(_str_in.c_str(), "%[^\t\n]", buffer);
        std::string _str_buffer(buffer);
        unsigned _u_sep = _str_buffer.find(",");
        _str_main = _str_buffer.substr(0,_u_sep);
        _str_trail = _str_buffer.substr(_u_sep+1,_str_buffer.length()-1);
    }
    
    if (_str_main.length() < _str_trail.length()) return _ui_out;
    
    _ui_out = 1;
    
    for (string::reverse_iterator iter_main = _str_main.rbegin(),
            iter_trail = _str_trail.rbegin();
         (iter_main != _str_main.rend()) && (iter_trail != _str_trail.rend());
         iter_main++, iter_trail++)
        {
            if(*iter_trail != *iter_main)
                {
                    _ui_out = 0;
                    break;
                }
        }
    return _ui_out;
}

int main (int argc, char* argv[]) {
    string _str_line;
    ifstream infile;
    infile.open (argv[1]);
    while(!infile.eof()) {
        getline(infile,_str_line);
        if (_str_line.length()>0)
            cout<<process(_str_line)<<"\n";
    }
    infile.close();
    
    return 0;
}
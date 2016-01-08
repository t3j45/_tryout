//By starting at the top of the triangle and moving to adjacent numbers on the row below, the maximum total from top to bottom is 27.

//   5
//  9 6
// 4 6 8
//0 7 1 5
//5 + 9 + 6 + 7 = 27

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <iterator>

void execute(std::vector<std::vector<unsigned long>> &triangle) {
    
    for (int i = triangle.size()-2; i >= 0; --i)
        for (int j = 0; j <= i; ++j) 
            triangle[i][j] = std::max((triangle[i][j]+triangle[i+1][j]),
                                      (triangle[i][j]+triangle[i+1][j+1]));
    
    std::cout<<triangle[0][0]<<std::endl;
}

void parseline(std::vector<std::vector<unsigned long>> &triangle, std::string &str) {

    std::istringstream ss(str);
    std::string num;
    std::vector<unsigned long> vec;
    while(ss>>num)
        vec.push_back(atoi(num.c_str()));
    triangle.push_back(vec);
}

int main(int argc, char* argv[]){
    std::ifstream infile;
    std::vector<std::vector<unsigned long>> triangle;
    std::string _str_line;
    infile.open (argv[1]);
    int i = 0;
    while(!infile.eof()) {
        getline(infile,_str_line);
        if (_str_line.length()>0)
            parseline(triangle,_str_line);
    }
    infile.close();
    execute(triangle);
}

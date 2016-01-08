// Find maximum subarray

#include <iostream>
#include <vector>

std::vector<int> contigueous(std::vector<int> input_) {
    
    unsigned length = input_.size();
    int m[length][length];

    // Initialize the Dynamic Programming matrix
    for (unsigned i = 0; i < length; ++i)
        for (unsigned j = 0; j < length; ++j) {
            if (i == j)
                m[i][j] = input_[i];
            else
                m[i][j] = 0;
        }

    // Computer the Dynamic Programming matrix values
    for (unsigned i = 0; i < length; ++i)
        for (unsigned j = i+1; j < length; ++j) {
        
            m[i][j] = m[i][j-1] + input_[j];
        }

    // Process the optimal values
    int max = 0;
    int maxi=0,maxj=0;

    for (unsigned i = 0; i < length; ++i)
        for (unsigned j = 0; j < length; ++j) {
            if ( m[i][j] > max) {
                max = m[i][j];
                maxi = i;
                maxj = j;
            }        
        }

    // Return the solution
    std::vector<int> output_;
    for (unsigned i = maxi; i <= maxj; ++i)
        output_.push_back(input_[i]);
    return output_;
}

int main() {

    std::vector<int> arr_{-2, -3, 4, -1, -2, 1, 5, -3};
    
    for (auto &v: contigueous(arr_))
        std::cout<<v<<" ";
    std::cout<<std::endl;

}

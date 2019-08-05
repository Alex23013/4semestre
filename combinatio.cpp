#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

vector<vector<int>> comb(int N, int K)
{
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
    vector<vector<int>> combinations;
    do {
        vector<int> one;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
            { //std::cout << " " << i;
              one.push_back(i);
            }            
        }
        combinations.push_back(one);
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
    return combinations;
}
 
int main()
{
    vector<vector<int> > combinations;
    combinations = comb(2, 2);
    for(int i = 0;i <combinations.size();i++){
            for(int j = 0;j <combinations[i].size();j++){
            cout<<combinations[i][j]<<"-";
        }
        cout<<"\n";
    }
}

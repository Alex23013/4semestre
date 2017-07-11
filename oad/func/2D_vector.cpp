#include <iostream>
#include <vector>
using namespace std;

int main()
{
// An empty vector of vectors. The space 
// between the 2 '>' signs is necessary
   vector<vector<int> > v2d;

// Now we'll try to create a 3 by 5 "matrix".
// First, create a vector with 5 elements
   vector<int> v2(5, 0); 

// Now create a vector of 3 elements. 
// Each element is a copy of v2
   vector<vector<int> > v2d2(3,v2);

// Print out the elements
   for(int i=0;i<v2d2.size(); i++) {
      for (int j=0;j<v2d2[i].size(); j++)
        cout << v2d2[i][j] << " "; 
      cout << endl;
   }
	v2d2[2].push_back(4);
cout << "aaaaa"<< endl;
for(int i=0;i<v2d2.size(); i++) {
      for (int j=0;j<v2d2[i].size(); j++)
        cout << v2d2[i][j] << " "; 
      cout << endl;
   }
	v2d2[0][0]=3;
cout << "aaaaa"<< endl;
for(int i=0;i<v2d2.size(); i++) {
      for (int j=0;j<v2d2[i].size(); j++)
        cout << v2d2[i][j] << " "; 
      cout << endl;
   }
}

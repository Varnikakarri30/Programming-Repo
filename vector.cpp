#include <bits/stdc++.h>
using namspace std;
int main()
{
    //Vectors = A vector is a dynamic array which can grow or shrink its size based on the program execution.
    // Functions in vectors:

    vector<int> arr;
    arr.push_back(0); //Alternative for push_back() is 'emplace_back()' using this is a a little faster than the pushback in cp we use it. // Adds the element at the last of the vactor.
    arr.push_back(5);
    arr.emplace_back(3);
    // segmentation fault or error occures where if you push_back 10^7 times same like arry but dynamic sizing.

    arr.pop_back() ; //removes or reduces by one number in the size of the vector.
    vec.clear(); // clears all the elements in that vector.

    vector<int> vec(4,0); // {0,0,0,0} after this we can do the any push_backs
    vector<int> vec2(4,10);

    // If we want to add the elements in both the vetors in vector 3 then this is how :
    vector<int> vec3(vec2.begin(),vec2.end()) // [) means [ included and ) means end excluded.OR vector<int> vec3(vec2); // copies all the elements of the vector 2.
    vector<int> vec3(vec2.begin(),vec2.begin()+2) or vec2.end()-2) for the start 2 numbers in the vectors.

    // begin(),end(),rbegin(),rend();
    // Swap function;
    swap(v1,v2);

    

    // 2D Vectors:
     int main(){
    
    vector<vector<int>> vec;
    vector<int> vec1(4,12); 
    vector<int> vec2(3,10);
     vec.emplace_back(vec1);
     vec.emplace_back(vec2);
    
    
    for(auto n: vec)
    {
        for( auto x : n)
        {
            cout<< x <<" ";
        }
        cout<<endl;
    }
} //output : 12 12 12 12
             10 10 10 

  





}
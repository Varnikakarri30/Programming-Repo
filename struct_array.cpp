//#include<bits/stdc++.h> // all the packages are contained in this single package.
#include <iostream>
#include <string>
using namespace std; //to eliminate the use of std::cout<<endl we use the namespace and std is the library which has all.

//Struct - is a self made datatype when you want to create a data type custimise it on your necessary requiremnts of input and out.

struct node{
    string str;
    double db;
    int number;
    char c;

    node(str_,db_,number_,c_)
    {
        str = str_;
        db = db_;
        number = number_;
        char = c_;
    }
};
//max size of array globally for integer and double = 10^7 

int main()
{
    node varni = new node("Varnika",93.5,1,'V'); // when u use a constructor new is used.
}

//Arrays --> to store same type of values
//Array Container
//max size of array inside int main  for intergers and double = 10^6 for boolen 10^7.
array<int,3> arr; //--> if we declare this in the int main then this will output the garbage value and then if we write that array and declare that globally before int main then that will give only '0' as values.
array<int,5> arr = {1,2,3,0,0};
array<int,5>arr = {0}; // = {0,0,0,0,0} all the values will be 0 that does not mean if we write array<int,3> arr = {1} --> this does NOT mean all three are '1' then that will be {1,0,0}.

//DOT FILL Function:
array<int,5>arr;
arr.fill(5);  //-->{5,5,5,5,5}

//arr.at(index no.);
 for(int i = 0;i<5 ; i++)
 {
    cout << arr.at(i)<< " ";
 }

//ITERATORS: --> begin(),end(),rbegin(),rend() - 'r' means reverse. rbegin() is the last element and end() is the next of the last element so we need to access like the 'end()-1'.
//for REVERSE iterators ++ means moves left and -- means moves right
// {1,2,3,4,5} begin = 1
//             end = 5 +
//             rbegin = 5
//             rend = - 1

array<int,5> arr = {1,2,3,4,5};
for(auto it = arr.begin();it != arr.end() ;it++) //auto means automatically adapts the datatype of the array no need for data type decalartion.
{
    cout<<*it<<" "; //'*' is used because it is a pointer pointing towards the elements at the indexes in an array.
}
for(auto it : arr)
{
    cout<<it<<" ";
}
//output = 1 2 3 4 5 for both the approaches

for(auto it = arr.rbegin(); it!= arr.rend();it++)
    {
        cout<<*it<<" ";
    }
    //output 5 4 3 2 1

for (auto it = arr.rend() - 1 ; it >= arr.rbegin();it --) // here -1 means one position after the rend() so it then starts from the 1st element or else if we start from the +1 then it moves forwards which prints two garbage values like this '-1600492228 32767 1 2 3 4 5 '.
    {
        cout<<*it<<" ";
    }
    //output 1 2 3 4 5
    
//Without the iterator
//For Each loop -> can alo we used by a string. for each loop goes to the value not adress that is why we haven't used *it.
{
    cout<<it<<" ";
}
  
string str = "Varnika";
for(auto c : str)
{
    cout << c << " ";
}

  //Array Size
  arr.size();

  //Front Element 
  arr.front(); OR  arr.at(0);

  //Back Element
  arr.back(); OR  arr.at(arr.size()-1);
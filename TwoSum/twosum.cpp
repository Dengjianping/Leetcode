/*
Link: https://leetcode.com/problems/two-sum/

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

template <class T>
class TwoSum
{
public:
    vector<int> twoSum(vector<T> & nums, T & target)
    {
        vector<int> tmp;
        for (size_t i = 0; i < nums.size(); i++)
        {           
            T t = nums[i];
            for (size_t j = i + 1; j <nums.size(); j++)
            {
                if (t + nums[j] == target)
                {
                    tmp.push_back(i);
                    tmp.push_back(j);
                }
            }
        }
        return tmp;
    }
};

template <class T>
void initArray(vector<T> & array, const int count)
{
    for (size_t i = 0; i < count; i++)
    {
        T t = rand() % (T)10;
        array.push_back(t);
    }
}

template <class T>
void showArray(vector<T> & array)
{
    for (size_t i = 0; i < array.size(); i++)
    {        
        cout << array[i] << ", ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    const int N = 10;
    int target = atoi(argv[1]);
    
    vector<int> nums;
    
    //srand((unsigned)time(NULL);
    
    initArray(nums, N);
    showArray(nums);
    
    TwoSum<int> ts;
    vector<int> t = ts.twoSum(nums, target);
    showArray(t);
    
    return 0;
}
/*

Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubString(string s)
    {
        int length = 1;
        for (size_t i = 0; i < s.length(); i++)
        {
            int currentLength = 1;            
            size_t j = 0;
            for (j = i + 1; j < s.length(); j++)
            {
                if (s[i] != s[j]) continue;
                break;
            }
            cout << "i: " << i << ", j: " << j << endl;
            showString(s, i, j);
            for (size_t p = i; p < j; p++)
            {
                for (size_t q = p + 1; q < j; q++)
                {
                    if (s[p] != s[q]) 
                    {
                        currentLength = q - p + 1;
                        continue;
                    }
                    break;
                }
            }
            cout << "current length: " << currentLength << ", length: " << length << endl;
            if (length < currentLength) length = currentLength;
        }
        
        return length;
    }
    void showString(string s, int start, int end) const
    {
        cout << "------------" << endl;
        for (size_t i = start; i < end; i++)
        {
            cout << s[i] <<", ";
        }
        cout << endl << "------------" << endl;
    }
};

int main(int argc, char** argv)
{
    string a = "abcabcdbb";
    
    Solution trial;
    int length = trial.lengthOfLongestSubString(a);
    cout << "length: " << length << endl;
    
    return 0;
}
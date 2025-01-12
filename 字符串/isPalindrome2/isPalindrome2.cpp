﻿// isPalindrome2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

 

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串
示例 2:

输入: "race a car"
输出: false
解释："raceacar" 不是回文串
 

提示：

1 <= s.length <= 2 * 105
字符串 s 由 ASCII 字符组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>

#include <string>

using namespace std;
class Solution {
public:
	bool isPalindrome(string s)
	{
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		
		int left = 0;
		int right = s.size()-1;

		for (left; left < right;)
		{
			if (ispunct(s[left]))
			{
				left++;
				continue;
			}

			if (ispunct(s[right]))
			{
				right--;
				continue;
			}
			
			if (tolower(s[left]) != tolower(s[right]))
			{
				return false;
			}

			left++; right--;
		}
		return true;
	}
};

int main()
{
	Solution s;
	auto a = s.isPalindrome("A maan, a plan, a canal: Panama");
    std::cout << "Hello World!\n";
}

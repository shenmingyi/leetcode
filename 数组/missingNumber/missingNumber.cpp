﻿// missingNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

 

进阶：

你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?
 

示例 1：

输入：nums = [3,0,1]
输出：2
解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
示例 2：

输入：nums = [0,1]
输出：2
解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
示例 3：

输入：nums = [9,6,4,2,3,5,7,0,1]
输出：8
解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
示例 4：

输入：nums = [0]
输出：1
解释：n = 1，因为有 1 个数字，所以所有的数字都在范围 [0,1] 内。1 是丢失的数字，因为它没有出现在 nums 中。
 

提示：

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
nums 中的所有数字都 独一无二
通过次数150,731提交次数241,280

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/missing-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) 
	{
		if (nums.empty())
		{
			return 0;
		}

		std::sort(nums.begin(), nums.end());
	
		if (nums[nums.size() - 1] < nums.size())
		{
			return nums.size();
		}

		int lastNum = nums[0] - 1;
		for (auto i = 0; i < nums.size(); i++, lastNum++)
		{
			if (nums[i] - 1 != lastNum)
			{
				return nums[i] - 1;
			}
		}

		return 0;
	}
};

int main()
{
	Solution s;
	vector<int> t{ 0,1};
	auto a = s.missingNumber(t);

    std::cout << "Hello World!\n";
}
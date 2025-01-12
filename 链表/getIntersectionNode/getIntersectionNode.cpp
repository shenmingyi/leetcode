﻿// getIntersectionNode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

图示两个链表在节点 c1 开始相交：



题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。

 

示例 1：



输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
示例 2：



输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Intersected at '2'
解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。
在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
示例 3：



输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
这两个链表不相交，因此返回 null 。
 

提示：

listA 中节点数目为 m
listB 中节点数目为 n
0 <= m, n <= 3 * 104
1 <= Node.val <= 105
0 <= skipA <= m
0 <= skipB <= n
如果 listA 和 listB 没有交点，intersectVal 为 0
如果 listA 和 listB 有交点，intersectVal == listA[skipA + 1] == listB[skipB + 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <iostream>
#include <vector>


using namespace std;

/*
/**
 * Definition for singly-linked list.
 * */
  struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
    {
        vector<ListNode*> vec;

        ListNode* curA = headA;      
        while (curA != nullptr)
        {
            vec.push_back(curA);
            curA = curA->next;
        }

        ListNode* curB = headB;
		while (curB != nullptr)
		{
            if (vec.end() != std::find(vec.cbegin(), vec.cend(), curB))
            {
                return curB;
            }

			vec.push_back(curB);
			curB = curB->next;
		}

        return nullptr;
    }
};


int main()
{
    ListNode a(1);
    ListNode a1(2);
    ListNode a2(3);

    ListNode b(4);
    ListNode b1(5);
    ListNode b2(6);

    ListNode c1(7);
    ListNode c2(8);

    a.next = &a1;
    a1.next = &a2;
    a2.next = &c1;
    c1.next = &c2;

    b.next = &b1;
    b1.next = &b2;
    b2.next = &c1;

    Solution s;
    auto r = s.getIntersectionNode(&a, &b);

    std::cout << "Hello World!\n";
}



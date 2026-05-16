//Leetcode 1669: Merge in between Linked Lists
//Time complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* beforeA; ListNode* preA = list1;
        for (int i=0; i<a-1; i++) preA = preA->next;
        ListNode* afterB = preA;
        for (int i=0; i<b-a+2; i++) afterB = afterB->next;
        preA->next = list2;
        while (list2->next!=nullptr) list2=list2->next;
        list2->next = afterB;
        return list1;
    }
};
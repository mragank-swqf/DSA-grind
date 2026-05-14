//143. Reorder List
#include <iostream>
#include <vector>
#include <stack>
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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* nd = head;
        while (nd != nullptr) { st.push(nd); nd = nd->next; }
    
        int n = st.size(), i = 0;
        nd = head;
        while (i < (n+1)/2) {
            ListNode* nxt = nd->next;
            ListNode* tp = st.top(); st.pop();
            nd->next = tp;
            tp->next = nxt;
            i++;
            if (i == (n+1)/2) tp->next = nullptr;
            nd = nxt;
        }
    }
};
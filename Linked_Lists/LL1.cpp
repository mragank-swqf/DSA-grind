//Floyd'a Algorithm AKA Fast and Slow Pointers
//Leetcode 2095. Delete the middle node of a linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; Node* next;
    Node(int val) {
        data=val; next=nullptr;
    }
};
Node* head;
void createfromarr(vector<int>arr) {
    Node* prev = nullptr;
    for (int a:arr) {
        Node* nw = new Node(a);
        if (head==nullptr) { head = nw; prev = nw; }
        else {
            prev->next = nw;
            prev= prev->next;
        }
    } 
}
vector<int> Floyd(Node* root) {
    vector<int> res;
    Node* slow = root; Node* fast = root; Node* prev;
    while (fast!=nullptr && fast->next!=nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    } if (prev) prev->next = slow->next;
    while(root!=nullptr) {
        res.push_back(root->data);
        root = root->next;
    } return res;
}
int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6};
    createfromarr(arr);
    vector<int> res1 = Floyd(head);
    for (int x:res1) cout << x << " ";
    cout << endl;
    return 0;
}
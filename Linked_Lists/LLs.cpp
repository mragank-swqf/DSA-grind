//Creating a linked list

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data; Node* next;
    Node(int val) {
        data=val; next=nullptr;
    }
};
class LList {
private:
    Node* head;
    int length;
public:
    LList() {
        head = nullptr;
        length = 0;
    } int getLength() { return length; }
    void createfromarr(vector<int>arr) {
        Node* prev = nullptr;
        for (int a:arr) {
            Node* nw = new Node(a);
            if (head==nullptr) { head = nw; prev = nw; length++;}
            else {
                prev->next = nw;
                prev= prev->next;
                length++;
            }
        } 
    } void traverse() {
        Node* nd = head;
        while (nd!=nullptr) {
            cout << nd->data << " ";
            nd = nd->next;
        } cout << endl;
    } void insert(int num, int pos) {
        if (pos==0) {
            Node* nw = new Node(num);
            Node* temp = head;
            head = nw; nw->next = temp;
        } else if (pos==length) {
            Node* nd = head;
            while (nd->next!=nullptr) nd = nd->next;
            Node* nw = new Node(num);
            nd->next = nw;
        } else {
            pos -= 1; Node* nd = head;
            while (pos--) nd = nd->next;
            Node* temp = nd->next;
            Node* nw = new Node(num);
            nd->next = nw;
            nw->next = temp;
        } length++;
    } void del(int pos) {
        if (pos==0) {
            Node* temp = head->next;
            delete head;
            head = temp;
        } else if (pos==length-1) {
            Node* nd = head; pos -= 1;
            while (pos--) nd = nd->next;
            Node* nws = nd->next;
            delete nws;
            nd->next = nullptr;
        } else {
            pos -= 1; Node* nd = head;
            while (pos--) nd = nd->next;
            Node* nxt = nd->next;
            Node* temp = nxt->next;
            nd->next = temp;
            delete nxt;
        } length--;
    } int search (int num) {
        int pos = 0;
        Node* nd = head;
        while (nd != nullptr) {
            if (nd->data == num) return pos;
            pos++; nd = nd->next;
        } return -1;
    }
};
int main() {
    LList mylist;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    mylist.createfromarr(arr);
    mylist.del(0);
    mylist.traverse();
    mylist.del(mylist.getLength()-1);
    mylist.traverse();
    mylist.del(3);
    mylist.traverse();
    cout << mylist.search(6) << endl;
    return 0;
}
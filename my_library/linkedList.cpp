using namespace std;
#include <utility>
#include <iostream>
#include <vector>

class LinkedList {
  private:
    struct Node {
        Node *prev;
        int key;
        Node *next;
    };
  
  Node *nil; // 番兵 
  public:
  LinkedList() {
    nil = new Node;
    nil->prev = nil;
    nil->next = nil;
  }

  Node *search(int key) {
    Node *curr = nil->next;
    while (curr != nil && curr->key != key) {
      curr = curr->next;
    }
    return curr;
  }

  void deleteNode(int key) {
    Node *x = search(key);
    x->prev->next = x->next;
    x->next->prev = x->prev;
    delete x;  // メモリ解放
  }

  void insert_front(int key) {
    Node *x;
    x = new Node;
    x->key = key;
    x->next = nil->next;
    nil->next->prev=x;
    nil->next=x;
    x->prev= nil;
  }

  void insert_back(int key) {
    Node *x;
    x = new Node;
    x->key = key;
    x->prev = nil->prev;
    nil->prev->next=x;
    nil->prev=x;
    x->next= nil;
  }

  void printList() {
    Node *curr = nil->next;
    while(curr!=nil) {
      cout << curr->key;
      curr=curr->next;
      cout << " ";
    }
    cout << endl;
  }
};

int main() {
  LinkedList l;
  for (int i=1; i<10; i++) l.insert_front(i);
  for (int i=19; i>=10; i--) l.insert_back(i);
  l.printList();
  l.deleteNode(8);
  l.deleteNode(13);
  l.printList();
  return 0;
}
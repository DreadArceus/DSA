//Linked lists for the first time, lets go
//TC: O(n+m), SC: O(n)
#include <iostream>
#include <unordered_map>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

Node* list_maker(int n)
{
    Node *head = new Node;
    cin >> head->data;
    Node *tail = head;
    for(int i = 0; i < n - 1; i++)
    {
        Node* curr = new Node;
        cin >> curr->data;
        tail->next = curr;
        tail = curr;
    }
    return head;
}

void print_list(Node *head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

Node* get_union(Node *head1, Node *head2)
{
    unordered_map<int, bool> hashMap;
    hashMap[head1->data] = 1;
    Node* resultHead = new Node;
    resultHead->data = head1->data;
    head1 = head1->next;

    Node* resultTail = resultHead;
    while(head1)
    {
        hashMap[head1->data] = 1;
        resultTail->next = new Node;
        resultTail = resultTail->next;
        resultTail->data = head1->data;
        head1 = head1->next;
    }

    while(head2)
    {
        if(hashMap[head2->data] != 1)
        {
            resultTail->next = new Node;
            resultTail = resultTail->next;
            resultTail->data = head2->data;
        }
        head2 = head2->next;
    }

    return resultHead;
}
Node* get_intersection(Node *head1, Node *head2)
{
    unordered_map<int, bool> hashMap;
    Node* resultHead = new Node;
    Node* resultTail = resultHead;
    while(head1)
    {
        hashMap[head1->data] = 1;
        head1 = head1->next;
    }
    while(head2)
    {
        if(hashMap[head2->data] == 1)
        {
            resultTail->next = new Node;
            resultTail = resultTail->next;
            resultTail->data = head2->data;
        }
        head2 = head2->next;
    }
    return resultHead->next;
}

int main()
{
    int n1 = 0, n2 = 0;
    cin >> n1 >> n2;

    Node *head1 = list_maker(n1), *head2 = list_maker(n2);

    Node *union_head = get_union(head1, head2), *intersection_head = get_intersection(head1, head2);

    print_list(union_head);
    print_list(intersection_head);
}
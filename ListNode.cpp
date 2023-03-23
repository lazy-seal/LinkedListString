#include <iostream>
#include "ListNode.h"
using namespace std;

// define the static int counters used by report_allocations()
int ListNode::total_allocations = 0;
int ListNode::net_allocations = 0;
int ListNode::total_bytes = 0;

// put all other ListNode definitions below

// returns a linked list from a c-string
List ListNode::list_from_string(const char * s)
{
    if (*s != '\0') {
        return new ListNode(*s, list_from_string(s+1));
    } else {
        return nullptr;
    }
}

// deletes all the nodes in linked list L, using delete
void ListNode::list_delete(List L)
{
    for (List p = L; p != nullptr;)
    {
        p = p->next;
        // cout << "deleting: " << L->data << endl;
        delete L;
        L = p;
    }
}

// print the characters in linked list L to out
void ListNode::print(ostream & out, List L)
{
    for (List p = L; p != nullptr; p = p->next)
        out << p->data;
}

// returns a count of the number of nodes in list L
int ListNode::list_length(List L)
{
    int count = 0;
    for (List p = L; p != nullptr; p = p->next)
        count++;
    return count;
}

// returns an exact duplicate of list L
List ListNode::list_copy(List L)
{
    List cpy = L;
    if (cpy != nullptr) {
        return new ListNode(cpy->data, list_copy(L->next));
    } else {
        return nullptr;
    }
}

// returns a duplicate list that is the result of appending L1 and L2
List ListNode::list_append(List L1, List L2)
{
    List cpy1 = L1;
    List cpy2 = L2;
    if (cpy1 != nullptr) {
        return new ListNode(cpy1->data, list_append(L1->next, L2));
    } else if (cpy2 != nullptr) {
        return new ListNode(cpy2->data, list_append(L1, L2->next));
    } else {
        return nullptr;
    }
}

// returns the reverse of list L
List ListNode::list_reverse(List L)
{
    // try 1
    // List cpy = L;
    // List last = list_last(L);
    // if (cpy != last) {
    //     return new ListNode(last->data, cpy);
    // } 
    // return last;

    // try 2
    // List cpy = L;
    // List last = list_last(L);
    // if (cpy != nullptr) {
    //     return new ListNode(last->data, list_reverse(list_nth(L, list_length(L) - 2)));
    // } else {
    //     return nullptr;
    // }


    // try 3
    // if (L == nullptr || L->next == nullptr) {return L;}
    // List rcpy = ListNode::list_reverse((ListNode::list_copy(L))->next);
    // L->next->next = L;
    // L->next = nullptr;
    // return rcpy;

    // try 4 (works)
    // List prev = nullptr;
    // List curr = ListNode::list_copy(L);
    // List next = nullptr;
    // while (curr != nullptr)
    // {
    //     next = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = next;
    // }
    // return prev;

    List result = nullptr;
	for ( List p = L; p != nullptr; p = p->next )
		result = new ListNode(p->data, result);
	return result;

}

// returns pointer to last element of L, nullptr if L is null
List ListNode::list_last(List L)
{
    for (List p = L; p != nullptr; p = p -> next)
    {
        if (p->next == nullptr)
            return p;
    }
    return nullptr;
}

// returns a pointer to the Nth element of the list
// first element is 0th, returns nullptr if n exceeds
List ListNode::list_nth(List str, int n)
{
    int len = list_length(str);
    int i = 0;
    
    if (n >= len || n < 0)
        return nullptr;

    for (List p = str; p != nullptr; p = p->next, i++)
    {
        if (i == n)
            return p;
    }
    return nullptr;
}

// similar to strchr(), but for a list of char and a char
List ListNode::list_chr(List str, int c)
{
    for (List p = str; p != nullptr; p = p -> next)
    {
        if (p->data - c == 0)
            return p;
    }
    return nullptr;
}

// similar to strstr(), but for two lists of char
List ListNode::list_str(List haystack, List needle)
{
    int needle_len = ListNode::list_length(needle);
    for (List p = haystack; (p = ListNode::list_chr(p, needle->data)); p = p->next) {
        if (ListNode::list_ncmp(p, needle, needle_len) == 0) {
            return p;
        }
    }
    return nullptr;
}


// similar to strcmp() but for list of char
int ListNode::list_cmp(List L1, List L2)
{
    List left = L1;
    List right = L2;
    for (; left != nullptr && right != nullptr; right = right->next, left = left->next) 
    {
        if (left->data != right->data) 
        {
            return left->data - right->data;
        }
    }
    if (left == nullptr && right != nullptr) {return -1;}
    else if (left != nullptr && right == nullptr) {return 1;}
    else {return 0;}
}


// similar to strncmp() but for list of char
int ListNode::list_ncmp(List L1, List L2, int n)
{
    int limit_num = n;
    int i = 0;
    List left = L1;
    List right = L2;
    for (; (left != nullptr) && (right != nullptr) && (i < limit_num); right = right->next, left = left->next, i++) 
    {
        if (left->data != right->data) 
        {
            return left->data - right->data;
        }
    }
    if (i == limit_num) {return 0;}
    else if (left == nullptr && right != nullptr) {return -1;}
    else if (left != nullptr && right == nullptr) {return 1;}
    else {return 0;}
}


// L1 points at start, L2 points later in same list
// returns the number of elements to traverse to get
// from L1 to L2
int ListNode::list_difference(List L1, List L2)
{
    return (ListNode::list_length(L1)) - (ListNode::list_length(L2));
}

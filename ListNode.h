#include <iostream>
using namespace std;

typedef struct ListNode *List;

struct ListNode
{
    char data;
    List next;

    /* there are 3 method definitions that must be
       in this .h file (rather than .cpp) for autograder:
       constructor, destructor, report_allocations()
    */
   ListNode(char new_data, List new_next)
        : data(new_data), next(new_next)
    {
        ++net_allocations;
        ++total_allocations;
        total_bytes += sizeof(ListNode);
    }

    ~ListNode()
    {
        --net_allocations;
    }

    // clear
    // returns a linked list from a c-string
    static List list_from_string(const char * s);

    // clear
    // returns an exact duplicate of list L
    static List list_copy(List L);

    // clear
    // returns the reverse of list L
    static List list_reverse(List L);

    // clear
    // returns a duplicate list that is the result of appending L1 and L2
    static List list_append(List L1, List L2);

    // clear
    // similar to strstr(), but for two lists of char
    static List list_str(List haystack, List needle);

    // clear
    // similar to strchr(), but for a list of char and a char
    static List list_chr(List str, int c);

    // clear
    // returns a pointer to the Nth element of the list
    // first element is 0th, returns nullptr if n exceeds
    static List list_nth(List str, int n);

    // clear
    // deletes all the nodes in linked list L, using delete
    static void list_delete(List L);

    // clear
    // print the characters in linked list L to out
    static void print(ostream & out, List L);

    // clear
    // L1 points at start, L2 points later in same list
    // returns the number of elements to traverse to get
    // from L1 to L2
    static int list_difference(List L1, List L2);

    // clear
    // returns pointer to last element of L, nullptr if L is null
    static List list_last(List L);

    // clear
    // similar to strcmp() but for list of char
    static int list_cmp(List L1, List L2);

    // clear
    // similar to strncmp() but for list of char
    static int list_ncmp(List L1, List L2, int n);

    // clear
    // returns a count of the number of nodes in list L
    static int list_length(List L);

    // clear
    // replaces Alloc::report_allocations()
    static void report_allocations()
    {
        cout << "Total allocations: " << total_allocations << endl;
        cout << "Total bytes: " << total_bytes << endl;
        if (net_allocations != 0)
            cout << "Error: Mismatching number of new/delete: " << net_allocations << endl;
        else
            cout << "Yay! All allocated memory has been freed! (probably)" << endl;
    }

private: 

    static int total_allocations;
    static int total_bytes;
    static int net_allocations;
    
};
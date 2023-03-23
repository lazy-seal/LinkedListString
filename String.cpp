#include <iostream>
using namespace std;
#include "String.h"

void String::error(const char * msg) const
{
    cout << "ERROR: " << msg << endl;
}

bool String::in_bounds(int i) const
{
    return i >= 0 && i < ListNode::list_length(head);
}

// Define your other String methods below
// constructs this string from a C string, defaults to empty string
String::String( const char * s ) {
    head = ListNode::list_from_string(s);
}

String::String( List L )
{
    head = L;
}

// construct this string as a copy of string s
String::String( const String & s ) {
    head = ListNode::list_copy(s.head);
}

// construct this string by moving from dying string s
String::String( String && s )
{
    head = s.head;
    s.head = nullptr;
}

// assingment to this string by moving from dying string to s
String & String::operator = ( String && s )
{
    ListNode::list_delete(head);
    head = s.head;
    s.head = nullptr;
    return *this;
}

// returns the logical length of this string
int String::size() const
{
    return ListNode::list_length(head);
}

// assignment operator from one string, s, to this string
String & String::operator = ( const String & s )
{
    ListNode::list_delete(head);
    head = ListNode::list_copy(s.head);
    return *this;
}

bool String::operator == ( const String & s ) const
{
    if (ListNode::list_length(head) != ListNode::list_length(s.head)) {return false;}
    int num = ListNode::list_cmp(head, s.head);
    return num == 0;
}
bool String::operator != ( const String & s ) const
{
    int num = ListNode::list_cmp(head, s.head);
    return num != 0;
}
bool String::operator > ( const String & s ) const
{
    if (ListNode::list_length(head) < ListNode::list_length(s.head)) {return false;}
    int num = ListNode::list_cmp(head, s.head);
    return num > 0;
}
bool String::operator < ( const String & s ) const
{
    if (ListNode::list_length(head) > ListNode::list_length(s.head)) {return false;}
    int num = ListNode::list_cmp(head, s.head);
    return num < 0;
}
bool String::operator <= ( const String & s ) const
{
    if (ListNode::list_length(head) > ListNode::list_length(s.head)) {return false;}
    int num = ListNode::list_cmp(head, s.head);
    return num <= 0;
}
bool String::operator >= ( const String & s ) const
{
    if (ListNode::list_length(head) < ListNode::list_length(s.head)) {return false;}
    int num = ListNode::list_cmp(head, s.head);
    return num >= 0;
}


// concatenate this and s to form a return string
String String::operator + ( const String & s ) const
{
    return String( ListNode::list_append(head, s.head) );
}

// concatenate s onto the end of this string
String & String::operator += ( const String & s )
{
    List cpy = ListNode::list_append(head, s.head);
    ListNode::list_delete(head);
    head = cpy;
    return *this;
}

// returns index into this string for first occurrence of c
int String::indexOf( const char c ) const
{
    if (ListNode::list_chr(head, c)) 
    {
        return ListNode::list_difference(head, ListNode::list_chr(head, c));
    }
    else {return -1;}
}

// returns index into this string for first occurrence of s
int String::indexOf( const String & s ) const
{
    if (s.head == nullptr) {return ListNode::list_length(head);}
    if (ListNode::list_str(head, s.head)) 
    {
        return ListNode::list_difference(head, ListNode::list_str(head, s.head));
    }
    else {return -1;}
}

// print
void String::print(ostream & out) const
{
    ListNode::print(out, head);
}

// read next word into this string from in
void String::read( istream & in )
{
    char p[3000];
    in >> p;
    ListNode::list_delete(head);
    head = ListNode::list_from_string(p);
}

// allow indexing this string with notation s[i]
char & String::operator [] ( int index )
{
    if (String::in_bounds(index))
        return (ListNode::list_nth(head, index))->data;
    else
    {
        String::error("Index Out Of Bounds");
        return head->data;
    }
}

// returns a reversal of this string, does not modify this string
String String::reverse() const
{
    return String(ListNode::list_reverse(head));
}


// destructor for this string
String::~String()
{
    ListNode::list_delete(head);
}

// // reverse
// String String::reverse() const
// {
//     return String(ListNode::list_reverse(head));
// }






// inserter and extractor for string objects
// use the pattern I showed you for inserter and extractor
ostream & operator << ( ostream & out, const String & s ) {s.print( out ); return out;}
istream & operator >> ( istream & in, String & s ) {s.read( in ); return in;}
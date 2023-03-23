#include <iostream>
#include "ListNode.h"

class String
{
public:

    // clear
    // constructs this string from a C string
    explicit String( const char * s =  "" );

    // clear
    // construct this string as a copy of string s
    String( const String & s );

    // clear
    // construct this string by moving from dying string s
    String( String && s );

    // clear
    // assingment to this string by moving from dying string to s
    String & operator = ( String && s );

    // clear
    // assignment operator from one string, s, to this string
    String & operator = ( const String & s );

    // clear
    // allow indexing this string with notation s[i]
    char & operator [] ( int index );

    // clear
    // returns the logical length of this string
    int size() const;

    // sort of
    // clear
    // returns a reversal of this string, does not modify this string
    String reverse() const;

    // clear
    // returns index into this string for first occurrence of c
    int indexOf( const char c ) const;

    // clear
    // returns index into this string for first occurrence of s
    int indexOf( const String & s ) const;

    // clear
    // relational operators for comparing this string to another string
    bool operator == ( const String & s ) const;
    bool operator != ( const String & s ) const;
    bool operator > ( const String & s ) const;
    bool operator < ( const String & s ) const;
    bool operator <= ( const String & s ) const;
    bool operator >= ( const String & s ) const;
    
    // clear
    // concatenate this and s to form a return string
    String operator + ( const String & s ) const;

    // clear
    // concatenate s onto the end of this string
    String & operator += ( const String & s );

    // clear
    // print the chars of this string to out
    void print( ostream & out ) const;

    // clear
    // read next word into this string from in
    void read( istream & in );

    // clear
    // destructor for this string
    ~String();

//private:

    // clear
    // construct this string using a given linked list
    String( List L );

    // clear
    bool in_bounds( int i ) const;
    void error( const char * msg ) const;

    List head;

    // DO NOT add any other data members

};

ostream & operator << ( ostream & out, const String & s );
istream & operator >> ( istream & in, String & s );
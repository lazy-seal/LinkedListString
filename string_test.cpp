#include <iostream>
using namespace std;
#include "String.h"

// ListNode
void test_list_from_string_and_print()
{
    cout << "TESTS: list_from_string_and_print" << endl;
    List L1 = ListNode::list_from_string("Hello ");
    List L2 = ListNode::list_from_string("World");
    List L3 = ListNode::list_copy(L1);
    List L4 = ListNode::list_copy(L2);
    ListNode::print(cout, L1);
    ListNode::print(cout, L2);
    cout << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    // add more tests

    ListNode::print(cout, L3);
    ListNode::print(cout, L4);
    cout << endl;
    ListNode::list_delete(L3);
    ListNode::list_delete(L4);
    cout << endl;
}

void test_list_append()
{
    cout << "TESTS: list_append" << endl;
    List L1 = ListNode::list_from_string("Hello");
    List L2 = ListNode::list_from_string("World");
    List C = ListNode::list_append(L1, L2);
    ListNode::print(cout, C);
    cout << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(C);
    // add more tests
    cout << endl;
}

void test_list_last()
{
    List L1 = ListNode::list_from_string("Hello");
    List L2 = ListNode::list_from_string("World");
    List L3 = ListNode::list_from_string("");

    cout << "should be empty string: ";
    ListNode::print(cout, ListNode::list_last(L3));
    cout << endl;

    cout << "should be \"o\": ";
    ListNode::print(cout, ListNode::list_last(L1));
    cout << endl;

    cout << "should be \"d\": ";
    ListNode::print(cout, ListNode::list_last(L2));
    cout << endl;

    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(L3);
    cout << endl;
}

void test_list_chr()
{
    List L1 = ListNode::list_from_string("Hello");
    List L2 = ListNode::list_from_string("World");
    List L3 = ListNode::list_from_string("");

    cout << "should be \"ello\": ";
    ListNode::print(cout, ListNode::list_chr(L1, 'e'));
    cout << endl;

    cout << "should be nothing: ";
    ListNode::print(cout, ListNode::list_chr(L1, 'z'));
    cout << endl;

    cout << "should be \"o\": ";
    ListNode::print(cout, ListNode::list_chr(L1, 111));
    cout << endl;

    cout << "should be nothing: ";
    ListNode::print(cout, ListNode::list_chr(L3, 'z'));
    cout << endl;

    List L4 = ListNode::list_from_string("J-6gOc57#p3ovXyl#5!1b53tUgH6Arlbvbhbeeaat3wWTU7XR?JT4E#QTLGl-Rmy1Bz5Fz'YutMffD3WJEHF8EgThM4cwaAhJ7e?yj41CA6P-TvNh3cizi1G3QRjYbys9CyzLnkfVbUZ2hw.cykJPdiCTZTK8b.9LstgNDttEfkrmGtx#L6LO?'AXQcYZ#RuocA.G1nc6FBl-2I7xGLeFIEurOcaK2v6430uX'FNK?6F1GFq'auKQ647E!ag1D'PyXcf3P1xNR-GqAXnIjXiiTiUSq1LT6tbNDpAca6XZ1o!ldm1ub9KVjxFzqbkgumTXJm7JcOs3.Ag'U7AW8.Jcr?JHhUNB?zqHThi34IYY844N3otVq.5Qazhil3Jju8QfhY8-qQUrMQ4H#pmmjk2jRcz2'9dz91EaJE#7mYqYGepCBJWK1R2C1lw6mzpnk1o1xs1JibrOoOiPp4sbNeLyx8oSzL5SElL1DwuTGTzUzHtPELQbXlAnlO'Ts.vWg6IRv.v1WUNfu?UYSCZzWjU!6RSiM'#0#EBrH4knR5A-3fTFPK'D2RDSBf8fl4'pBGOavYv#NV!I80?Iu--gUG6nUYA5Vxeo4SorIJvnwuVpe1XyW0NJzDWdup8!MevI4R7EsmROGE3SqSbeLWN.jC'DR'Kvj5#'O3B6akFOOsr#dAbOgOIpiN1ZKDf1tj67#z6#JvTpV.uYuvwAb#XkJQ9leg#Fx2wutuy2PbkD-Etp7YX8UNcwneHrsMWQGlc0FAUnK#QFAb3rZSsEpC8DGHU7dBPSURKjjoETlejToed'WvB#XtHw9ln#U.WyLqQUNey6rPRFTUCH!#L5xclqoGvaAjH-IpXntndS22pNH0fO4QDt1WK!m'hMgOPW3F9pS#!NZpkyhx#-gIo7o6?J3fnc23YXAS#cWePNB8dIpiDvQRu#IsFDy1NsOE!?oeiciYQJQ1b'9MBRvVW-?tzEee40Q364!");
    cout << "should be very long string that starts with !: ";
    ListNode::print(cout, ListNode::list_chr(L4, '!'));


    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(L3);
    ListNode::list_delete(L4);
    cout << endl;
}

void test_list_reverse()
{
    cout << "TESTS: list_reverse" << endl;
    List L1 = ListNode::list_from_string("|111111111111111111111111|");
    List L2 = ListNode::list_from_string("|222222222222222222222222|");
    List C = ListNode::list_append(L1, L2);
    List R = ListNode::list_reverse(C);
    ListNode::print(cout, C);
    cout << endl;
    ListNode::print(cout, R);
    cout << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(C);
    ListNode::list_delete(R);
    cout << endl;
}

void test_list_nth()
{
    List L1 = ListNode::list_from_string("Hello");
    List L2 = ListNode::list_from_string("World");

    cout << "should be 'Hello': ";
    ListNode::print(cout, ListNode::list_nth(L1, 0));
    cout << endl;

    cout << "should be 'o': ";
    ListNode::print(cout, ListNode::list_nth(L1, 4));
    cout << endl;

    cout << "should be 'rld': ";
    ListNode::print(cout, ListNode::list_nth(L2, 2));
    cout << endl;

    if (ListNode::list_nth(L1, 5) == nullptr) {
        cout << "The nth when n > list_length(L1) works (returns nullptr)" << endl;
    } else {cout << "Error on list_nth when n > list_length(L1)" << endl;}

    if (ListNode::list_nth(L1, -1) == nullptr) {
        cout << "The nth when n < 0 works (returns nullptr)" << endl;
    } else {cout << "Error on list_nth when n < 0" << endl;}

    cout << endl;

    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    cout << endl;
}


// String
void test_constructors_and_print()
{
    cout << "Constructor and operator << TESTS" << endl;

    // FYI these two lines use both constructors, print(), and operator <<
    String s("Hello World");
    cout << "\"" << s << "\"" << endl;

    String s2("0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    cout << s2 << endl;

    String s3(s);
    cout << s3 << endl;

    String s4(s2);
    cout << s4 << endl;
    cout << endl;
}

void test_assignment()
{
    cout << "Assignment TESTS" << endl;
    String a = String("a");
    String b = String("bbb");
    b = a;
    cout << "should be a a: " << a << " " << b << endl;
    // ...your code continues here
    cout << endl;
}

void test_size()
{
    cout << "size TESTS" << endl;
    String a("0123456");
    String b("0123456");
    String c("0000");
    String d("0001");
    String e("");
    // String f("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    
    if (a.size() == 7) {cout << "CORRECT 1" << endl;}
    else {cout << "ERROR" << endl;}

    if (b.size() == a.size()) {cout << "CORRCET 2" << endl;}
    else {cout << "ERROR" << endl;}

    if (c.size() != a.size() && c.size() == 4) {cout << "CORRECT 3" << endl;}
    else {cout << "ERROR" << endl;}

    if (e.size() == 0) {cout << "CORRECT 4" << endl;}
    else {cout << "ERROR" << endl;}

    // cout << e.size() << endl;
    // cout << f << endl;
    // cout << f.size() << endl;
    cout << endl;
}

void test_concatenate()
{
    cout << "Concatenate TESTS" << endl;
    String a("0123456");
    String b("");
    String c("");
    String d("22222");

    cout << a + b << endl;
    cout << c + d << endl;
    a += b;
    cout << a << endl;
    c += d;
    cout << c << endl;

    String x("0123456789012345678901234567890123456789012345678901234567890123456789");
    String y("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    cout << x + y << endl;
    x += y;
    cout << x << endl;
    cout << endl;
}

void test_indexOf_chr()
{
    cout << "indexOf TESTS" << endl;
    String a("0123456");
    String b("7891011");
    String c("11111");
    String d("22222");

    int five = a.indexOf('5');
    if (five == 5) {cout << "CORRECT 1" << endl;}
    else {cout << "ERROR " << five << endl;}
    if (c.indexOf('4') == -1) {cout << "CORRECT 2" << endl;}
    else {cout << "ERROR" << endl;}
    


    
    cout << endl;
}

void test_indexOf_strstr()
{
    cout << "indexOf(const String s) TEST" << endl;
    String a("0000abc00");
    String b("1111abc");
    String c("111  1");
    String d("  ");
    cout << a.indexOf(b) << " Supposed to be -1" << endl;
    cout << c.indexOf(d) << " Supposed to be 3" << endl;
    cout << d.indexOf(a) << " Supposed to be -1" << endl;

    // String fourthString("Forth");
    // String fifthString = String();
    // cout << "indexOf(empty String) should be 5: " << fourthString.indexOf(fifthString) << endl;

    //cout << "==: " << (secondString == firstString) << endl;

    // String x("7PQY-B!Efkl5dIEXVjVJ'ORKfu7A5ew51#N4yVBL5MI9n#QagDRlbsVoNNPKZ-zK8'");
    // String y("7PQY-B!Efkl5dIEXVjVJ'ORKfu7A5ew51#N4yVBL5MI9n#Q8bHMKI7Oq7UTR5V9T9OyIjhMIZMNy.pqd5-Nx2mO2?rD#eEPgdfOmus2d4AKYX0.MVHcQ1QC0!'4mBLsEQ?Y.rLffdP#0I6x");
    // cout << "strncmp " << String::strncmp(x.buf, y.buf, 47) << endl;
    // cout << 'a' - '8' << endl;

    String long_ex("wVAoMUSnB#TfG8foWFquSfCapz7Pft.KgDY1hJgRFZWdS2rGzP8jUCjb1bZ7CTBQgrJw0P'pH1ArVZ5ezXwlkFn-O#.aPvZ4NskF8pVHinY4'NawuwPE22IA6CJO6sCLKUaKb3bjbZf?EoC7KbvE#-'2yOIw?c7IW!l53uh#mmcQIEHlN-PR6UMwAeSyhR!-Zk1ME8IQmKzVg6619NL0Aho8l!rAYqwHIplep13BDmoJkmDe8?#AnksGrJ7a7vHHKTMZEHsa1HRd1eh1kllxEE");
    String EE("EE");
    cout << "indexOf(EE) should be a 276: " << long_ex.indexOf(EE) << endl;
    // cout << long_ex.size() - ListNode::list_length(ListNode::list_str(long_ex.head, EE.head)) << endl;
    // ListNode::print(cout, ListNode::list_str(long_ex.head, EE.head));
    // cout << endl;
    

    String z("PDKZ46J.DXlAJgfDmX2cV#wt2apAacqPN0zJR");
    String PN("PN");
    cout << "indexOf(PN) should be 31: " << z.indexOf(PN) << endl;
    

    String finding("J-6gOc57#p3ovXyl#5!1b53tUgH6Arlbvbhbeeaat3wWTU7XR?JT4E#QTLGl-Rmy1Bz5Fz'YutMffD3WJEHF8EgThM4cwaAhJ7e?yj41CA6P-TvNh3cizi1G3QRjYbys9CyzLnkfVbUZ2hw.cykJPdiCTZTK8b.9LstgNDttEfkrmGtx#L6LO?'AXQcYZ#RuocA.G1nc6FBl-2I7xGLeFIEurOcaK2v6430uX'FNK?6F1GFq'auKQ647E!ag1D'PyXcf3P1xNR-GqAXnIjXiiTiUSq1LT6tbNDpAca6XZ1o!ldm1ub9KVjxFzqbkgumTXJm7JcOs3.Ag'U7AW8.Jcr?JHhUNB?zqHThi34IYY844N3otVq.5Qazhil3Jju8QfhY8-qQUrMQ4H#pmmjk2jRcz2'9dz91EaJE#7mYqYGepCBJWK1R2C1lw6mzpnk1o1xs1JibrOoOiPp4sbNeLyx8oSzL5SElL1DwuTGTzUzHtPELQbXlAnlO'Ts.vWg6IRv.v1WUNfu?UYSCZzWjU!6RSiM'#0#EBrH4knR5A-3fTFPK'D2RDSBf8fl4'pBGOavYv#NV!I80?Iu--gUG6nUYA5Vxeo4SorIJvnwuVpe1XyW0NJzDWdup8!MevI4R7EsmROGE3SqSbeLWN.jC'DR'Kvj5#'O3B6akFOOsr#dAbOgOIpiN1ZKDf1tj67#z6#JvTpV.uYuvwAb#XkJQ9leg#Fx2wutuy2PbkD-Etp7YX8UNcwneHrsMWQGlc0FAUnK#QFAb3rZSsEpC8DGHU7dBPSURKjjoETlejToed'WvB#XtHw9ln#U.WyLqQUNey6rPRFTUCH!#L5xclqoGvaAjH-IpXntndS22pNH0fO4QDt1WK!m'hMgOPW3F9pS#!NZpkyhx#-gIo7o6?J3fnc23YXAS#cWePNB8dIpiDvQRu#IsFDy1NsOE!?oeiciYQJQ1b'9MBRvVW-?tzEee40Q364!");
    String wow("!");
    cout << "Should be 18: " << finding.indexOf(wow) << endl;
    
    cout << endl;
}

void test_relationals()
{
    cout << "Relational TESTS" << endl;
    String a("0123456");
    String b("0123456");
    String c("0000");
    String d("0001");

    String aa("aa");
    String aaa("aaa");
    string f("f");
    string F("F");

    if (aa < aaa) {cout << "aa < aaa is true" << endl;}
    else {cout << "ERROR" << endl;}
    if (aa > aaa) {cout << "ERROR" << endl;}
    else {cout << "aa > aaa is false" << endl;}

    if (f > F) {cout << "f > F is true" << endl;}
    else {cout << "ERROR" << endl;}
    if (!(f < F)) {cout << "f < F is false" << endl;}
    else {cout << "ERROR" << endl;}



    // == testing
    // 1, 2
    if (a == b) {cout << "CORRECT 1" << endl;}
    else {cout << "ERROR" << endl;}
    if (a == c) {cout << "ERROR" << endl;}
    else {cout << "CORRECT 2" << endl;}

    // != testing
    // 3, 4
    if (a != b) {cout << "ERROR" << endl;}
    else {cout << "CORRECT 3" << endl;}
    if (c != d) {cout << "COORCET 4" << endl;}
    else {cout << "ERROR" << endl;}

    // > testing
    // 5,
    if (a > c) {cout << "CORRECT 5" << endl;}
    else {cout << "ERROR" << endl;}

    // > testing
    // 6,
    if (a < c) {cout << "ERROR" << endl;}
    else {cout << "CORRCET 6" << endl;}

    // <= testing
    // 7, 8
    if (a <= c) {cout << "ERROR" << endl;}
    else {cout << "CORRCET 7" << endl;}
    if (a <= b) {cout << "CORRCET 8" << endl;}
    else {cout << "ERROR" << endl;}

    // >= testing
    // 9, 10
    if (a >= c) {cout << "CORRCET 9" << endl;}
    else {cout << "ERROR" << endl;}
    if (a >= b) {cout << "CORRCET 10" << endl;}
    else {cout << "ERROR" << endl;}
    cout << endl;


    // test
    // List Test1 = ListNode::list_from_string("Hello");
    // List Test2= ListNode::list_from_string("Hellow");
    // cout << ListNode::list_cmp(Test2, Test1) << endl;
    // ListNode::list_delete(Test1);
    // ListNode::list_delete(Test2);
}

void test_index_operator()
{
    cout << "Index_operator TESTS" << endl;
    String a("0123456");
    cout << a[0] << " " << 
    a[1] << " " << 
    a[2] << " " << 
    a[3] << " " << 
    a[4] << " " << 
    a[5] << " " << 
    a[6] << endl;
    cout << "Next line should be error" << endl;
    cout << a[7] << endl;
    cout << "Next line should be error" << endl;
    cout << a[-1] << endl;
    cout << endl;
}

void test_read()
{
    cout << "read TEST" << endl;
    cout << "type anything" << endl;
    String a("");
    cin >> a;
    cout << "you typed: " << a << endl;
    cout << endl;
}


int main()
{
    // passed (List Node)
    test_list_from_string_and_print();
    test_list_append();
    test_list_last();
    test_list_nth();
    test_list_chr();
    test_list_reverse();


    // Need to pass (ListNode testing)


    // passed (String)
    test_indexOf_strstr();
    test_indexOf_chr();
    test_relationals();
    test_constructors_and_print();
    test_assignment();
    test_size();
    test_concatenate();
    test_index_operator();
    test_read();


    // Need to pass (String.h / .cpp testing)


    ListNode::report_allocations();
    return 0;
}
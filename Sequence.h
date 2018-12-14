#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <cstring>
using namespace std;

class Sequence
{
public:
    // constructors and destructor
    Sequence();
    Sequence(int length);
    Sequence(Sequence& rhs);
    virtual ~Sequence();
    // pure virtual function that should be overridden because every
    // type of sequence has its own details to be printed
    virtual void Print();
    // friend function that will find the LCS (longest common
    // subsequence) between 2 sequences of any type, according to
    // polymorphism
    friend string Align(Sequence s1, Sequence s2);
    // loading and save files
    bool operator == (Sequence &s) ;
    bool operator != (Sequence &s) ;
    virtual void loadsequence(string FileName);
    virtual void savesequence(string FileName);
    virtual Sequence operator + (Sequence &s);
    friend ostream& operator << (ostream& out ,Sequence &s);
    friend istream& operator >> (istream& in ,Sequence &s);
    //Functions to Get and Set seq
    string getseq();
    void setseq(string a);
    protected:
    string seq;
    int length;
};

#endif

#include "Sequence.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

Sequence:: Sequence()
{
}
Sequence:: Sequence(int length)
{

}
Sequence:: Sequence(Sequence& rhs)
{

}
Sequence:: ~Sequence()
{
// pure virtual function that should be overridden because every
// type of sequence has its own details to be printed
}
void Sequence:: Print()
{
// friend function that will find the LCS (longest common
// subsequence) between 2 sequences of any type, according to
// polymorphism
}
string Sequence:: getseq()
{
    return seq;
}
void Sequence:: setseq(string a)
{
    seq=a;
}
string Align(Sequence s1, Sequence s2)
{
    string LCS ="";
    int indexofs1=0;
    for (int i=0 ; i< s2.getseq().length() ; i++)
    {
        for (int j=indexofs1 ; j<s1.getseq().length(); j++)
        {
            if (s2.getseq()[i]==s1.getseq()[j])
            {
                LCS=LCS+s2.getseq()[i];
                indexofs1=j;
                break;
            }
        }
    }
    return LCS ;
}
Sequence Sequence:: operator + (Sequence &s)
{
    Sequence x;
    string SEQ;
    SEQ= this->getseq() + s.getseq();
    x.setseq(SEQ);
    return x;
}
bool Sequence::operator == (Sequence &s)
{
    if (this->getseq() == s.getseq())
        return true;
    return false;
}
bool Sequence::operator!= (Sequence &s)
{
    if(this ->getseq() != s.getseq())
        return true;
    return false;
}
ostream& operator<< (ostream& out,Sequence &s)
{
    out << s.getseq() ;
    return out;
}
istream& operator>> (istream& in,Sequence &s)
{
    string ss;
    in >>ss;
    s.setseq(ss) ;
    return in;
}
void Sequence::loadsequence(string FileName)
{
    fstream FILE ;
    FILE.open(FileName,ios::in);
    if (FILE.fail())
        cout << "fail ";
    while (FILE&&!FILE.eof())
    {
        string s;
        FILE >>s;
         setseq(s);
    }
    FILE.close();
}
void Sequence::savesequence(string FileName)
{
    fstream FILE ;
    FILE.open(FileName,ios::out);
    if (FILE.fail())
        cout << "fail ";
    FILE << getseq();
    cout << "Done";
    FILE.close();
}

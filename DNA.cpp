#include "DNA.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

DNA::DNA()
{
}
DNA:: DNA(string s, DNA_Type atype)
{
    setseq(s);
    settype(atype);
}
DNA:: DNA(DNA& rhs)
{
    setseq(rhs.getseq());
    settype(rhs.gettype());
}
DNA:: ~DNA()
{
}
void DNA:: Print()
{
    int x,y;
    cout << "Enter start index: ";
    cin >> x ;
    setstartindex(x);
    cout<< "Enter End index: ";
    cin >> y ;
    setendindex(y);
    for (int i=getstartindex() ; i<=getendindex() ; i++)
        cout << getseq()[i];
}
RNA DNA:: ConvertToRNA()
{
    RNA rna("",mRNA);
    string newseq;
    int x,y;
    cout << "Enter start index: ";
    cin >> x ;
    cout<< "Enter End index: ";
    cin >> y ;
    if (x==-1 && y==-1)
    {
        setstartindex(0);
        setendindex(getseq().length()-1);
    }
    else
    {
        setstartindex(x);
        setendindex(y);
    }
    for (int i=startIndex ; i<=endIndex ; i++)
    {
        if (getseq()[i]== 'T')
            newseq=newseq+'U';
        else
            newseq=newseq+getseq()[i];
    }
    rna.setseq(newseq);
    return rna;
}
void DNA:: BuildComplementaryStrand()
{
    string newseq;
    int x,y;
    cout << "Enter start index: ";
    cin >> x ;
    setstartindex(x);
    cout<< "Enter End index: ";
    cin >> y ;
    setendindex(y);
    for (int i=startIndex ; i<=endIndex ; i++)
    {
        if (getseq()[i]== 'T')
            newseq =newseq+'A';
        else if (getseq()[i]== 'A')
            newseq=newseq+'T';
        else if (getseq()[i]== 'C')
            newseq=newseq+'G';
        else if (getseq()[i]== 'G')
            newseq=newseq+'C';
    }
    char temp;
    for (int i=0; i<newseq.length(); i++)
    {
        temp = newseq[i];
        newseq[i]=newseq[endIndex-i];
        newseq[endIndex-i] = temp;
    }
    getcomstrand()->setseq(newseq);
}
DNA DNA::operator + (DNA &dna)
{
    DNA x;
    string SEQ;
    SEQ= this->getseq() + dna.getseq();
    x.setseq(SEQ);
    return x;
}
void DNA:: settype (DNA_Type t)
{
    type=t;
}
DNA_Type DNA::gettype ()
{
    return type;
}
int DNA:: getstartindex()
{
    return startIndex;
}
int DNA:: getendindex()
{
    return endIndex;
}
void DNA:: setstartindex (int x)
{
    startIndex=x;
}
void DNA::setendindex (int x)
{
    endIndex=x;
}
DNA* DNA:: getcomstrand ()
{
    return complementary_strand;
}

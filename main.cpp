/*
Assignment 4
Ahmed Ibrahim Mohamed Kassab - G3 - 20170008
Nourhan Atef Radwan - G3 - 20170325
*/
#include <iostream>
#include <cstring>
#include<fstream>
#include<Sequence.h>
#include<DNA.h>
#include<RNA.h>
#include<Protein.h>
#include<CodonsTable.h>
using namespace std;

int main()
{
    DNA dna ;
    RNA rna ;
    Protein p;
    CodonsTable table;
    table.LoadCodonsFromFile("RNA_codon_table.txt");
Enter_Sequenc :
    cout <<"1) DNA      2) RNA      3)Protein" <<endl << "Choose the type of Sequence: "   ;
    int choiceSeq;
    cin >> choiceSeq ;
    if (choiceSeq==1)
    {
        cout << "1) Enter Your Sequence         2) Load From File " << endl;
        int inputtype;
        cin>> inputtype;
        if (inputtype==1)
        {
            cout << "Enter Sequence: ";
            cin >> dna ;
        }
        else if (inputtype==2)
        {
            cout << "Enter File Name: ";
            string name;
            cin >> name;
            dna.loadsequence(name);
        }
        try
        {
            for (int i=0 ; i<dna.getseq().length() ; i++)
            {
                if (dna.getseq()[i]== 'A' || dna.getseq()[i]== 'C' || dna.getseq()[i]== 'G' || dna.getseq()[i]== 'T')
                    continue;
                throw (dna.getseq()[i]);
            }
            goto DNA_Menu_Point;
        }
        catch (char error)
        {
            if (error != 'A' && error != 'C' && error != 'G' && error != 'T')
                cout << "Please ReEnter Your Sequence" << endl <<endl;
            goto Enter_Sequenc;
        }
DNA_Menu_Point:
        cout << endl <<"1) Print your DNA sequence " << endl << "2) Save your DNA sequence to file" << endl;
        cout << "3) Convert to RNA " << endl << "4) Print Complementary Strand" << endl <<"5) Save Complementary Strand to file";
        cout<<endl<<"6) Enter a new sequence "<<endl<< "0) EXIT" <<endl;
        int choice;
        cout << "Enter Your Choice: ";
        cin >> choice;
        if (choice==1)
        {
            cout << dna ;
            goto DNA_Menu_Point;
        }
        else if (choice==2)
        {
            string name;
            cout << "Enter file name: ";
            cin >> name ;
            dna.savesequence(name);
            cout << "DONE" ;
            goto DNA_Menu_Point;
        }
        else if (choice==3)
        {
            rna=dna.ConvertToRNA();
            goto RNA_Menu_Point;
        }
        else if (choice==4)
            {
                dna.BuildComplementaryStrand();
                cout<<dna.getcomstrand()->getseq();
                goto DNA_Menu_Point;
            }
        else if (choice==5)
        {
            string name;
            cout << "Enter file name: ";
            cin >> name ;
            dna.getcomstrand()->savesequence(name);
            goto DNA_Menu_Point;
        }
        else if (choice==6)
        {
            goto Enter_Sequenc;
        }
        else if (choice == 0)
        {
            return 0;
        }
        else
        {
            cout << "invalid choice" << endl;
            goto Enter_Sequenc;
        }
    }
    else if (choiceSeq== 2)
    {
        cout << "1) Enter Your Sequence         2) Load From File " << endl;
        int inputtype;
        cin>> inputtype;
        if(inputtype==1)
        {
            cout << "Enter Sequence: ";
            cin >> rna ;
        }
        else if (inputtype==2)
        {
            cout << "Enter File Name: ";
            string name;
            cin >> name;
            rna.loadsequence(name);
            cout << "DONE";
        }
        else
        {
            cout << "Invalid Choice " << endl << endl;
            goto Enter_Sequenc;
        }
        try
        {
            for (int i=0 ; i<rna.getseq().length() ; i++)
            {
                if (rna.getseq()[i]== 'A' || rna.getseq()[i]== 'C' || rna.getseq()[i]== 'G' || rna.getseq()[i]== 'U')
                    continue;
                throw (rna.getseq()[i]);
            }
        }
        catch (char error)
        {
            if (error != 'A' && error != 'C' && error != 'G' && error != 'U')
                cout << "Please ReEnter Your Sequence" << endl <<endl;
            goto Enter_Sequenc;
        }
RNA_Menu_Point:
        cout << endl <<"1) Print your RNA sequence " << endl << "2) Save your RNA sequence to file" << endl;
        cout << "3) Convert to DNA " << endl << "4) Convert to Protein " ;
        cout<<endl<<"5) Enter a new sequence "<<endl<< "0) EXIT" <<endl;
        int choice ;
        cout << "Enter Your choice: ";
        cin >> choice;
        if (choice==1)
            {
            cout << rna ;
            goto RNA_Menu_Point;
            }
        else if (choice==2)
        {
            string name;
            cout << "Enter file name: ";
            cin >> name ;
            rna.savesequence(name);
            cout << "DONE" ;
            goto RNA_Menu_Point;
        }
        else if (choice ==3)
            {
            dna=rna.ConvertToDNA();
            goto DNA_Menu_Point;
            }
        else if (choice==4)
        {
            p=rna.ConvertToProtein(table);
            goto Protein_Menu_Point;
        }
        else if (choice == 5)
            {goto Enter_Sequenc;}
        else if (choice==0)
        {
            return 0;
        }
        else
            {
            cout<<"Invalid Choice";
            goto RNA_Menu_Point;
            }
    }
    else if (choiceSeq==3)
    {cout << "1) Enter Your Sequence         2) Load From File " << endl;
        int inputtype;
        cin>> inputtype;
        if (inputtype==1)
        {
            cout << "Enter Sequence: ";
            cin >> p ;
        }
        else if (inputtype==2)
        {
            cout << "Enter File Name: ";
            string name;
            cin >> name;
            p.loadsequence(name);
            cout << "DONE";
        }
        try
        {
            for (int i=0 ; i<p.getseq().length() ; i++)
            {
                if (p.getseq()[i]!= 'B' && p.getseq()[i]!= 'J' && p.getseq()[i]!= 'O' && p.getseq()[i]!= 'U' && p.getseq()[i]!= 'X'&& p.getseq()[i]!= 'Z')
                    continue;
                throw (dna.getseq()[i]);
            }
            goto Protein_Menu_Point;
        }
        catch (char error)
        {
            if (error == 'B' || error == 'J' || error == 'O' || error == 'U' || error == 'X' || error == 'Z')
                cout << "Please ReEnter Your Sequence" << endl <<endl;
            goto Enter_Sequenc;
        }
Protein_Menu_Point:
        cout << endl <<"1) Print your Protein sequence " << endl << "2) Save your Protein sequence to file" << endl;
        cout<<"3) Enter a new sequence "<<"4) Get DNA Strands Encoding"<<endl<< "0) EXIT" <<endl;
        int choice;
        cout << "Enter Your Choice: ";
        cin >> choice;
        if (choice==1)
        {
            cout << p ;
            goto Protein_Menu_Point;
        }
        else if (choice==2)
        {
            string name;
            cout << "Enter file name: ";
            cin >> name ;
            p.savesequence(name);
            goto Protein_Menu_Point;
        }
        else if (choice==3)
        {
            goto Enter_Sequenc;
        }
        else if (choice==4)
        {
            DNA d2;
            BACK:
        cout << "1) Enter Your Sequence         2) Load From File " << endl;
        int inputtype;
        cin>> inputtype;
        if (inputtype==1)
        {
            cout << "Enter Sequence: ";
            cin >> d2 ;
        }
        else if (inputtype==2)
        {
            cout << "Enter File Name: ";
            string name;
            cin >> name;
            d2.loadsequence(name);
        }
        try
        {
            for (int i=0 ; i<d2.getseq().length() ; i++)
            {
                if (d2.getseq()[i]== 'A' || d2.getseq()[i]== 'C' || d2.getseq()[i]== 'G' || d2.getseq()[i]== 'T')
                    continue;
                throw (d2.getseq()[i]);
            }
            goto next;
        }
        catch (char error)
        {
            if (error != 'A' && error != 'C' && error != 'G' && error != 'T')
                cout << "Please ReEnter Your Sequence" << endl <<endl;
            goto BACK;
        }
        next:
        DNA *arr;
        arr=p.GetDNAStrandsEncodingMe(d2);
        for (int i=0 ;i<10 ; i++)
        {
            cout << *(arr+i) <<endl;
        }
        goto Protein_Menu_Point;
        }
        else if (choice == 0)
        {
            return 0;
        }
        else
        {
            cout << "invalid choice" << endl;
            goto Enter_Sequenc;
        }
    }
    return 0;
}

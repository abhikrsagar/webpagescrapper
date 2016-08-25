//Pass 1 Assembler
//Made by Abhishek Kumar  25/08/16
//The given pass 1 Assembler reads source file,opcode file and dumps symbol table and pass 1 intermediate file
//I have used WinExec and system commands which are most compatible with Windows.Thus please run the program
//in windows as running in Linux or any other OS might have some compatibility issue

#include<iostream>
#include<unistd.h>
#include<string>
#include<cstring>
#include<fstream>
# define MAXOP 10
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<windows.h>
using namespace std;
struct op
{
    string oper;
    unsigned int opcode;
    int s;

};
struct sym
{
    string label;
    int loctr;
}sy[MAXOP];
int hash_sym[MAXOP][MAXOP];
int hash_oper[MAXOP][MAXOP];
typedef struct op opr;
int key_op(string s)
{
    int n=s.size();int x=0;
    for(int i=0;i<n;i++)
        x+=s[i];
    return x%MAXOP;

}
void hash_op(opr* h,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int t=key_op(h->oper);
        for(j=1;j<MAXOP;j++)
        {
            if(hash_oper[t][j]==-1)
            {
                hash_oper[t][j]=i;
                break;
            }
        }
        h+=0x1;
    }
}
bool hash_find(opr *h,string s)
{
    int key=key_op(s);
    int i,j;bool f=false;
        for(j=1;j<MAXOP;j++)
        {
            if(hash_oper[key][j]!=-1)
            {unsigned int t=hash_oper[key][j];
            t*=0x1;
            opr *qt;
            qt=h;
            qt=qt+t;
                string z=qt->oper;
                if(z==s)
                    return true;
            }
            else
                return f;
        }
}
void hash_syms(string lab,int c)
{
    int key=key_op(lab);
    int j;
    for(j=1;j<MAXOP;j++){
            if(hash_sym[key][j]==-1)
    {hash_sym[key][j]=c;
    }
}
}
bool hash_symfind(string lab)
{
    int key=key_op(lab);
    for(int j=1;j<MAXOP;j++)
    {
  int k=hash_sym[key][j];
  if(k==-1)
    return false;
  else if(sy[k].label==lab)
    return true;
    }
    return false;
}
int main()
{
    cout<<"Abhi Pass 1 Assembler";
    system("color b");
    char buff[50];
    getcwd(buff,50);
     std::string str(buff);
     string q="start/d "+str;
    u_int hp=WinExec(q.c_str(),SW_HIDE);
    cout<<"\n\n\nPlease check the source program and optable";
    cout<<"\n\n\nSymbol Table dumped to symtab.txt file in your directory\n\n\n";
    cout<<"Output dumped to out.txt file in current directory";
    system("input.txt");
    TerminateProcess(HANDLE(),hp);
     hp=WinExec(q.c_str(),SW_HIDE);
    system("optab.txt");
    cout<<"\n\n\nThanks for using Abhi Pass1 Assembler!!!\n\n\n";
    opr o[MAXOP];
    fstream op,in,out;
    int loc=0;
    op.open("optab.txt",ios::in);
    string opc;unsigned int opcd;int sz;
    int i=0;while(op>>opc>>opcd>>sz)
    {
        o[i].oper=opc;o[i].opcode=opcd;o[i].s=sz;
        i++;
    }
    int n=i;
    memset(hash_oper,-1,sizeof(hash_oper));
    for(i=0;i<MAXOP;i++)
        hash_oper[i][0]=i;
        memset(hash_sym,-1,sizeof(hash_sym));
    for(i=0;i<MAXOP;i++)
        hash_sym[i][0]=i;
    hash_op(&o[0],n);
    op.close();
in.open("input.txt",ios::in);
out.open("output.txt",ios::out);
fstream syms;
syms.open("symtab.txt",ios::out);
int loctr;
string s;
getline(in,s);
size_t index=s.find("START");
if(index!=std::string::npos)
{
    int w=s.find("START");
    string qt=s.substr(w+5,s.size()-1);
    int x=atoi(qt.c_str());
    loc+=x;
out<<s<<endl;
}
else
    loc=0;
string lab,otp,val;
in>>lab>>otp>>val;
int counter=0;
while(otp!="END")
{
    if(lab=="-"||lab==" "||lab==".")
    {
        if(!hash_symfind(val)&&hash_find(&o[0],otp)){
       sy[counter].label=val;
       sy[counter].loctr=loc;
       hash_syms(val,counter);
       counter++;
    syms<<val<<"    "<<loc<<endl;
       }
       else
       {cout<<"Duplicate Symbol"<<endl;
       exit(1);}}
       if(hash_find(&o[0],otp))
        loc+=3;
        else if(otp=="WORD")
            loc+=3;
        else if(otp=="RESW")
            loc+=(atoi(val.c_str())*3);
        else if(otp=="BYTE")
            loc+=(ceil((val.size()+1)/2));
        else if(otp=="RESB")
        loc+=atoi(val.c_str());
        else
            cout<<"Invalid Opcode"<<endl;

       out<<lab<<"  "<<otp<<"   "<<val<<"   "<<loc<<endl;
       in>>lab>>otp>>val;
       }
     out<<lab<<"    "<<otp<<"   "<<val<<"   "<<loc;
     in.close();
     syms.close();
     out.close();
      WinExec(q.c_str(),SW_HIDE);
     system("output.txt");
      WinExec(q.c_str(),SW_HIDE);
     system("symtab.txt");
}

/*Text Editor Code implemented in C
Text Editor gives the facility of creating files with any extension rather than restricting to .txt.Not only
this Text Editor also gives the facility of editing the files(find/replace/view)

Made by Abhishek Kumar

Welcome to the world of Abhi Text Editor
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<windows.h>

//pos means index at which to insert
void ins(char *a,int pos,char b,int *n)
{

    int i;
    for(i=(*n)-1;i>=pos;i--)
        a[i+1]=a[i];
    a[pos]=b;
    *n=*n+1;

}
void del(char *a,int pos,int *n)
{
    printf("hi");
    int i;
    for(i=pos;i<(*n)-1;i++)
        a[i]=a[i+1];
    *n=*n-1;
}


void delay(unsigned int ms)
{
    clock_t  g= ms + clock();
    while (g > clock());
}
int finder(char * st,char * fin)
{
    register int i=0,j,k,l;
    int nq=strlen(st);
    int n=strlen(fin);
    static int c=0;
    while(i+n<nq)
    {
        char * w=malloc(n*sizeof(char));
        for(j=i;j<i+n;j++)
            w[j-i]=st[j];
        int r=strcmp(w,fin);
        if(r==0)
            c++;
        i++;
    }
    return c;
}
void rep(char * st,char * fin,char * re)
{

    register int i=0,j,k,l;
    int nq=strlen(st);
    int n=strlen(fin);
    int n1=strlen(re);
    static int c=0;
    fflush(stdin);
    while(i+n-1<nq)
    {
        char * w=malloc(n*sizeof(char));
        for(j=i;j<i+n;j++)
            w[j-i]=st[j];
        int r=strcmp(w,fin);
        if(r==0)
            {
                c++;l=0;
                if(n==n1){
                for(k=i;k<i+n1;k++)
                {
                    st[k]=re[l];l++;
                     fflush(stdin);
                }
                i+=(n1-1);}
                else if(n>n1)
                {
                    l=0;
                    for(k=i;k<i+n1;k++)
                        {st[k]=re[l];
                        l++; fflush(stdin);}
                    for(k=i+n1;k<i+n;k++)
                    st[k]='~';
                        i+=(n-1);
                }
                else
                {
                      l=0;
                    for(k=i;k<i+n;k++)
                        {st[k]=re[l];
                        l++;}
                    for(k=i+n;k<i+n1;k++)
                        ins(st,k,re[l++],&nq); fflush(stdin);
                        i+=(n1-1);
                }

            }
        i++;
    }
st[nq]='\0';
fflush(stdin);
system("color a");
    printf("\n%d Replaces\n",c);
}
int main()
{
    FILE *fp;int t;int opt;
    char * filenam=malloc(100*sizeof(char));char zw;
    menu:
        system("color a");
        printf("\a\a\a\aWelcome to Abhi Text Editor:\n\n\n1:Create a new file\n2:Edit a file:\n3:View file\n4:Show current directory\n5:Exit");
        printf("\n\nSelect your option:");
    fflush(stdin);
    scanf("%d",&t);
    if(t==1)
    {
        fflush(stdin);
        system("color b");
        printf("\nEnter the file name with extension:");
        gets(filenam);
        fflush(stdin);
        fp=fopen(filenam,"w");
        fflush(stdin);char opt;
        system("color 7");
        printf("\n\a\a\a\aFile created!!!Wanna insert data into the file(Y/N):");
        opt=getchar();
        if(opt=='Y'||opt=='y')
        {
            system("color  a");
            printf("\nEnter the data,null character is ~:");
           while((opt=getchar())!='~')
            fprintf(fp,"%c",opt);
            system("color 6");
            printf("\n\a\a\a\a\aText written to the file!!!\n");
            delay(3000);
            system("cls");
            fclose(fp);
            goto menu;

        }
        else
        {system("cls");
        fclose(fp);
        goto menu;
        }

    }
    else if(t==2)
    {
        edit:system("cls");
         system("color b");
        printf("Welcome to edit menu!!!\n\n\n1:Append\n2:Find\n3:Replace\n4:View a file\n5:Main menu\n6:Exit:");
        scanf("%d",&opt);
        if(opt==1)
        {
            fflush(stdin);
             system("color 3");
        printf("\n\nEnter the file name with extension:");
        gets(filenam);
        fflush(stdin);
        fp=fopen(filenam,"r");
        fflush(stdin);
        char st,zw;
         system("color a");
        printf("\n\a\aCurrently file is:\n");
        while((zw=getc(fp))!=EOF)
            {printf("%c",zw);}
            fclose(fp);
            fp=fopen(filenam,"a");
             system("color e");
        printf("\n\nEnter the data to append to file,null character is ~:");
           while((st=getchar())!='~')
            fprintf(fp,"%c",st);
            fclose(fp);
             system("color 7");
            printf("\n\a\a\aText appended to the file!!!\n");
            delay(3000);
            system("cls");
            fp=fopen(filenam,"r");
        fflush(stdin);
         system("color e");
        printf("\n\nNow file is:\n");
        while((zw=getc(fp))!=EOF)
            {printf("%c",zw);}fclose(fp);
             system("color b");
        printf("\nWat do you wanna do now!!!\n1:Main menu   2:Exit:");int t;
        scanf("%d",&t);
        fclose(fp);
        if(t==1)
            goto edit;
            else
                return 0;
        }
        else if(opt==2)
        {
            char *stq=malloc(1000*sizeof(char));
            fflush(stdin);
             system("color a");
        printf("\n\nEnter the file name with extension:");
        gets(filenam);
        fflush(stdin);
        fp=fopen(filenam,"r");
        fflush(stdin);int i=0;
        char st,zw;
         system("color b");
        printf("\n\n\a\a\aCurrently file is:\n");
        while((zw=getc(fp))!=EOF)
            {stq[i++]=zw;
            printf("%c",zw);}
            fclose(fp);
             system("color 2");
            printf("\n\nWord to find:");
            char *w=malloc(sizeof(char)*100);
            fflush(stdin);
            gets(w);fflush(stdin);
            int mat=finder(stq,w);
             system("color a");
            printf("\n\a\a\a\aFound %d matches!!!",mat);
            delay(3000);
            goto edit;
        }
        else if(opt==3)
        {
     char *stq=malloc(1000*sizeof(char));
            fflush(stdin);
             system("color 2");
        printf("\n\nEnter the file name with extension:");
        gets(filenam);
        fflush(stdin);
        fp=fopen(filenam,"r");
        fflush(stdin);int i=0;
        char st,zw;
         system("color e");
        printf("\n\n\a\a\aCurrently file is:\n");
        while((zw=getc(fp))!=EOF)
            {stq[i++]=zw;
            printf("%c",zw);}
            fclose(fp);
             system("color a");
            printf("\n\nWord to replace:");
            char *ol=malloc(sizeof(char)*100);
            fflush(stdin);
            gets(ol);fflush(stdin);
             system("color 2");
            printf("\n\nReplacing word:");
            char *re=malloc(sizeof(char)*100);
            fflush(stdin);
            gets(re);fflush(stdin);
            rep(stq,ol,re);
             system("color a");
             printf("\n\n\a\a\aNow file becomes:\n");
             fp=fopen(filenam,"w");
             int qt=0;fflush(stdin);
        while(stq[qt]!='\0')
            {
                fflush(stdin);
                if(stq[qt]!='~'){
            fprintf(fp,"%c",stq[qt]);
            printf("%c",stq[qt]);
            }qt++;}
            fclose(fp);
            delay(6000);
            goto edit;
        }
        else if(opt==4)
        {
            goto view;

        }
        else if(opt==5)
        {
goto menu;
        }
        else
            return 0;
    }
    else if(t==2)
    {
        goto edit;

    }
    else if(t==3)
    {
        view:fflush(stdin);
         system("color b");
        printf("\nEnter the file name with extension:");
        gets(filenam);
        fflush(stdin);
        FILE *fq;
        fq=fopen(filenam,"r");
        fflush(stdin);
         system("color 2");
        printf("\n\a\a\a\aFile opened!!!\nLoading Content of file...\n");
        delay(3000);
        system("cls");
        printf("File:");
        puts(filenam);
        //printf("\n\n\n");
        fflush(stdin);
        while((zw=getc(fq))!=EOF)
            {printf("%c",zw);}
            fclose(fq);
             system("color a");
            printf("\n\n\a\a\a\aWat do you wanna do now...1:Go to main menu  2:Goto Edit Menu:");
            fflush(stdin);
            scanf("%d",&opt);
            if(t==1)
            {
                system("cls");
                goto menu;
            }
            else
                goto edit;
    }
    else if(t==4)
    {system("dir");
    delay(7000);
    system("cls");
    goto menu;}
    else
        return 0;
}

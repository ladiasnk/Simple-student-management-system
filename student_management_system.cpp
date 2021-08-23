#include<conio.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<dos.h>
#include<cctype>
#include<sstream>
#include<string>
using namespace std;
bool check = true;
struct node    //structure of node //
{
 char name[20];
 char discipline[20];
 int rollNo;
 char section;
 node *next;
}*head,*lastptr;

void add()    //Adds record of student//
{
 node *p;
 p=new node;
 cout<<"Enter name of student:"<<endl;
 gets(p->name);
 fflush(stdin);
 cout<<"Enter discipline of student:"<<endl;
 gets(p->discipline);
 fflush(stdin);
 cout<<"Enter Roll Number of student:"<<endl;
 cin>>p->rollNo;
 fflush(stdin);
 cout<<"Enter section of student:"<<endl;
 cin>>p->section;
 fflush(stdin);
 p->next=NULL;

 if(check)
 {
  head = p;
  lastptr = p;
  check = false;
 }
 else
 {
  lastptr->next=p;
  lastptr=p;
 }
 cout<<endl<<"Record Entered";
 getch();
}
void modify()   //modifies record of student//
{
 node *ptr;
 node *prev=NULL;
 node *current=NULL;
 int roll_no;
 cout<<"Enter Roll Number to search:"<<endl;
 cin>>roll_no;
 prev=head;
 current=head;
 while(current->rollNo!=roll_no)
 {
  prev=current;
  current=current->next;
 }
 ptr=new node;
 fflush(stdin);
 cout<<"Enter name of student:"<<endl;
 gets(ptr->name);
 fflush(stdin);
 cout<<"Enter discipline of student:"<<endl;
 gets(ptr->discipline);
 fflush(stdin);
 cout<<"Enter Roll Number of student:"<<endl;
 cin>>ptr->rollNo;
 fflush(stdin);
 cout<<"Enter section of student:"<<endl;
 cin>>ptr->section;
 fflush(stdin);
 prev->next=ptr;
 ptr->next=current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Record Modified";
 getch();
}
void search()   //searches record of student//
{
 node *prev=NULL;
 node *current=NULL;
 int roll_no;
 cout<<"Enter Roll Number to search:"<<endl;
 cin>>roll_no;
 prev=head;
 current=head;
 while(current->rollNo!=roll_no)
 {
  prev=current;
  current=current->next;
 }

 if (current->rollNo==roll_no){
 cout<<"\nName: ";
 puts(current->name);
 cout<<"\nRoll No:";
 cout<<current->rollNo;
 cout<<"\nDiscipline:";
 puts(current->discipline);
 cout<<"\nSection:";
 cout<<current->section;
 getch();
 }
 else{
    cout << "Sorry the Roll number you entered does not exist!" ;
 }

}

void del()    //deletes record of a student//
{
 node *ptr=NULL;
 node *prev=NULL;
 node *current=NULL;
 int roll_no;
 cout<<"Enter Roll Number to Delete:"<<endl;
 cin>>roll_no;
 prev=head;
 current=head;
 while(current->rollNo!=roll_no)
 {
  prev=current;
  current=current->next;
 }
 prev->next = current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Record Deleted";
 getch();
}

//Main menu

int main()
{
 char x;
 cout<<"\t\t ********************************* \t\t\t"<<endl;
 cout<<"\t\t ****STUDENT MANAGEMENT SYSTEM**** \t\t\t"<<endl;
 cout<<"\t\t ********************************* \t\t\t"<<endl;
 cout<<"…………………………………….."<<endl;
 cout<<"…………………"<<endl;
 cout<<"……………………………………………………."<<endl;
 cout<<"\n\nPress Any Key To Continue . . . ."<<endl;
 getch();
 do
 {
  system("cls");
  cout<<"Press '1' to add New record:"<<endl;
  cout<<"Press '2' to search a record:"<<endl;
  cout<<"Press '3' to modify a record:"<<endl;
  cout<<"Press '4' to delete a record:"<<endl;
  cout<<"Press '5' to exit:"<<endl;
  x=getch();
  switch(x){

  case '1':
   system("cls");
   add();
   break;

  case '2':
   system("cls");
   search();
   break;

  case '3':
   system("cls");
   modify();
   break;

  case '4':
   system("cls");
   del();
   break;

  case '5':
   exit(1);
   break;
 }

 }while(x != 27);
 getch();

}


#include <iostream>
using namespace std;
 
struct clients{
	int client_id;
	string name;
	string surname;
	string address;
	int nid;
	int phone_no;
	string email;
	bool activated=true;
  bool handed=true;
};
   

struct books{
	int bookid;
	string title;
	int volume;
	string author;
	int stock;
	string genre;
};


struct transaction{
int tr_id ;
int book_id ;
int client_id ;
int startd ;
int startm ;
int starty ;
int endd ;
int endm ;
int endy ;
int decider ;
};

void menu();
void getbooks(int anum);
void getclients(int bnum);
void deactivate();
void pick();
void hand();
void history();
void bad();

books a[1000];
int anum=0;
clients b[1000];
int bnum=0;
transaction c[1000];
int cnum=0 ;
int tridnumber=10 ;

int main ( ){

menu();

return 0 ;
}
void menu()
{
int n;
cout<<"1.Add new book\n";
cout<<"2.Add new client\n"; 
cout<<"3.Deactivate client\n"; 
cout<<"4.Pick a book\n"; 
cout<<"5.Hand in the book\n";
cout<<"6.Client story\n";
cout<<"7.Bad clients\n"; 
cin>>n;
if(n==1){
	anum++;
	getbooks(anum);
}
if(n==2){
	bnum++;
	getclients(bnum);
}
if (n==3){
  deactivate();
}
if (n==4){
  cnum++ ;
  pick();
}

if (n==5){
  hand();
}

if (n==6){
  history();
}
if (n==7){
  bad();
}

}

   
   
void getbooks(int anum){
cout<<"Enter book id\n";
cin>>a[anum].bookid;	
cout<<"Enter book title\n";
cin>>a[anum].title;
cout<<"Enter the name of the author\n";
cin>>a[anum].author;
cout<<"Enter the stock number\n";
cin>>a[anum].stock;
cout<<"Enter the book category\n";
cin>>a[anum].genre;
menu();
}
void getclients(int bnum){
	cout<<"Enter client id\n";
	cin>>b[bnum].client_id;
	cout<<"Enter the name of the client\n";
	cin>>b[bnum].name;
	cout<<"Enter the surname of the client\n";
	cin>>b[bnum].surname;
	cout<<"Enter the adress of the client\n";
	cin>>b[bnum].address;
	cout<<"Enter the nid of the client\n";
	cin>>b[bnum].nid;
	cout<<"Enter the phone number of the client\n";
	cin>>b[bnum].phone_no;
	cout<<"Enter the e-mail of the client\n";
	cin>>b[bnum].email;
  menu();
}
void deactivate()
{
	int id;
	cout<<"Enter client_id\n";
	cin>>id ;
  for (int i = 1 ;i < 1000 ; i++)
  {
    if (b[i].client_id==id)
    {
      if (b[i].handed==true)
      {
      cout<<"Please return your book first \n" ;
      menu();
      }
      else
      {
      b[i].activated=false;
      cout<<"The client has been deactivated \n" ;
      menu();
      }
    } 
  }
  cout<<"This id is invalid \n" ;
  menu();
}  
void pick()
{
  int id ;
  cout<<"Enter the client id \n" ;
  cin>>id ;
  for ( int i ; i<1000 ; i ++)
  {
    if (id==b[i].client_id && b[i].activated==true)
    { 
      if (b[i].handed==false)
      {
        cout<<"Please return your book first \n" ;
        menu();
      }
      cout<<"Enter the book id \n" ;
      int bookid ;
      cin>>bookid ;
      for(int j=0;j<1000;j++)
      {
        if (bookid==a[j].bookid)
        {
          if (a[j].stock==0)
          {
            cout<<"The book is out of stock \n" ;
            menu();
          }
          else
          {
          b[i].handed=false ;
          cout<<"Enter the day \n" ;
          cin>>c[cnum].startd ;
          cout<<"Enter the month \n" ;
          cin>>c[cnum].startm ;
          cout<<"Enter the year \n" ;
          cin>>c[cnum].starty ;
          c[cnum].tr_id=tridnumber++ ;
          c[cnum].book_id=bookid ;
          c[cnum].client_id=id ;
          menu();
          }
        }
      }
    }
    else 
    continue ;
  }
  cout<<"The id is invalid \n" ;
  menu();
}
void hand()
{
 int id;
	cout<<"Enter client_id\n";
	cin>>id ;
  for (int i=0 ; i < 1000 ; i++)
  {
    if (id==b[i].client_id)
    {
      if (b[i].handed==false )
      {
        for (int j=0 ; j<1000 ; j++)
        {
          if (c[j].client_id==b[i].client_id && b[j].activated==true )
          {
          b[i].handed=true ;
          cout<<"Enter the day of return \n" ;
          cin>>c[cnum].endd ;
          cout<<"Enter the month of return \n" ;
          cin>>c[cnum].endm ;
          cout<<"Enter the year of return\n" ;
          cin>>c[cnum].endy ;
          a[i].stock+=1 ;
          b[i].handed=true ;
          c[cnum].decider=c[cnum].endm-c[cnum].startm ;
          cout<<"The book has been returned \n" ;
          menu();
          }
        }
      }
    }
    else
    continue ;
  }
  cout<<"The id is invalid \n" ;
  menu();
}
void history()
{
  int id ;
  cout<<"Enter the id to see the client history \n" ; 
  cin>>id ;
  for(int i=1 ; i<1000 ; i++)
  {
  if (c[i].client_id==id)
  {
    cout<<"book id : \n"<< c[i].book_id ;
    cout<<"start day : \n"<< c[i].startd ; 
    cout<<"start month : \nn"<< c[i].startm ; 
    cout<<"start year : \n"<< c[i].starty ; 
    cout<<"end day : \n"<< c[i].endd ; 
    cout<<"end month : \n"<< c[i].endm ;
    cout<<"end year : \n"<< c[i].endy ;
  }
  }
}
void bad()
{
  for (int i = 0 ; i<1000 ; i++)
  {
    if(b[i].handed==false)
    {
    cout<<b[i].name<<b[i].surname<<"is a bad client \n" ;
    }
    if(c[i].decider>3)
    {
    cout<<"client with id "<<c[i].tr_id<<"is a bad client \n" ;
  }
  }
  menu();
}

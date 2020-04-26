
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
class Libmod
	{
	    public:
	    int id,admin_no,Clas,clas;
	    char sname[20],bookt[30],fname[10];
	    void modify();
	    void display();
	    int runmenu();
	    void putdata();
	    void Delete();
	    time_t t;
	    int getroll()
		{
			return id;
		}
	    int getclas()
		{
			return clas;
		}
	    char newline;


	};
void Libmod :: modify()
      {
	 char nm[20];
	 int r;
	  gotoxy(32,10);cout<<"Enter new ID No. :";
	   cin>>r;
	  gotoxy(32,12);cout<<"Enter Name :";
	   gets(nm);
	  gotoxy(32,14);cout<<"Enter Admission no :";
	   cin>>admin_no;
	  gotoxy(32,16);cout<<"Enter Class :";
	   cin>>Clas;
	  gotoxy(32,18);cout<<"Enter title of Book issued:";
	   gets(bookt);
	   strcpy(sname,nm);
	   id=r;
	  gotoxy(32,21);cout<<"{RECORD IS MODIFIED}";
	   getch();

     }
void Libmod :: display()
	{
	  clrscr();
	  gotoxy(2,3);cout<<" EXSISTING DATA ";
	  gotoxy(3,6);cout<<"ID :"<<id;
	  gotoxy(3,8);cout<<"NAME :"<<sname;
	  gotoxy(3,10);cout<<"ADMISSION NO. :"<<admin_no;
	  gotoxy(3,12);cout<<"CLASS :"<<Clas;
	  gotoxy(3,14);cout<<"ISSUED BOOK:"<<bookt;
	  for(int h=30;h<=30;h++)
	  {
		for(int k=1;k<=25;k++)
		{
			gotoxy(h,k);cout<<"";
			delay(40);
		}
	  }
	}
       void Libmod :: Delete()
	{      gotoxy(25,17);cout<<"{ RECORD IS DELETED }";
	       getch();
	}
void Libmod :: putdata()
	{
	   cout<<"\n\n\t\t INSERTION  OF  RECORD ";
	   cout<<"\n\n\t\tSTUDENT NAME: ";
	   gets(sname);
	   cout<<"\n\t\tFATHER'S NAME:";
	   gets(fname);
	   cout<<"\n\t\tENTER ID: ";
	   cin>>id;
	   cout<<"\n\t\tCLASS (1 to 12):";
	   cin>>Clas;
	   cout<<"\n\t\tADMISSION NUMBER: ";
	   cin>>admin_no;
	   cout<<"\n\t\tISSUED BOOK TITLE: ";
	   gets(bookt);
	   time(&t);
	   printf("\n\t\tBOOK ISSURED ON\n\n\t\t\t %s\n",ctime(&t));
	   delay(250);
	   getch();
	   clrscr();
	   gotoxy(22,13);cout<<"{RECORD IS ADDED}";

	}
void main()
	{  clrscr();
		int ch;
		textbackground(9);
		for(int j=0;j<=100;j++)
			{
				gotoxy(30,15);cout<<"LOADING("<<j<<"%) PLEASE WAIT....";
				textbackground(j);
				delay(25);
				clrscr();
			}
		for(int i=1;i<=70;i++)
			{
				gotoxy(i,15);cout<<"";
				delay(40);
				clrscr();
				gotoxy(37,15);cout<<"WELCOME";

			}

	while(1)
	  {   clrscr();
	      cout<<"\n\t\t                           _ _                 ";
	      cout<<"\n\t\t   |   |  |~~ |   |~) |~| |-!-| |~~    ~|~|~|  ";
	      cout<<"\n\t\t   | ! |  |-  |   |   | | | ! | |-      | | |  ";
	      cout<<"\n\t\t   |_!_|  |_, |__ |_) |_| |   | |_,     | |_|  ";
	      cout<<"\n\n\n\t\t\t   K.V.  JUTOGH  CANTT.  SHIMLA";
	      cout<<"\n\n\t\t\t\t LIBRARY RECORD";
	      cout<<"\n\n\t\t\t    ----------MENU----------   ";
	      cout<<"\t\n\n\n\t\t\t  1. INSERT A RECORD";
	      cout<<"\t\n\n\t\t\t  2. SEARCH A RECORD";
	      cout<<"\t\n\n\t\t\t  3. MODIFY A RECORD";
	      cout<<"\t\n\n\t\t\t  4. DELETE A RECORD";
	      cout<<"\t\n\n\t\t\t  5. EXIT";
	      cout<<"\t\n\n\t\t\t     ENTER YOUR CHOICE: ";
	      cin>>ch;
	     switch(ch)
	    {
		case 1: clrscr();
			ofstream ofile;
			Libmod z;
			z.newline='\n';
			ofile.open("DNA_LIB.txt",ios::app);
			z.putdata();
			ofile.write((char*)&z,sizeof(z));
			ofile.close();
			break;
		case 2: clrscr();
			int ID;
			char found='n';
			Libmod t;
			ifstream fin;
			fin.open("DNA_LIB.txt",ios::in|ios::out|ios::binary);
			gotoxy(17,8);cout<<"ENTER ID no. OF STUDENT (TO SEARCH FOR): ";
			cin>>ID;
			fin.seekg(0);
			while(!fin.eof())
			{
				fin.read((char*)&t,sizeof(t));
				if(t.getroll()==ID)
				{
					t.display();
					found='y';
					break;
				}
				else
				if(found=='n')
				{
					gotoxy(25,17);cout<<"RECORD NOT FOUND!!!!!";
				}
			}
			fin.close();
			break;
		case 3: clrscr();
			gotoxy(15,1);cout<<" MODIFICATION  OF  RECORD ";
			Libmod g;
			int cls,rol;
			char d='n';
			fstream fout;
			fout.open("DNA_LIB.txt",ios::in|ios::out|ios::binary);
			gotoxy(20,8);cout<<"ENTER EXISTING ID no. OF STUDENT FOR UPDATION: ";
			cin>>rol;
			fout.seekg(0);
			while(!fout.eof())
			     {
			       int loc = fout.tellg();
			       fout.seekg(0);
			       fout.read((char*)&g,sizeof(g));
			       if(g.getroll()==rol)
				 {
					g.display();
					d='y';
					g.modify();
					fout.seekg(loc);
					fout.write((char*)&g,sizeof(g));
					break;
				 }
			     else{
					if(d=='n')
					{     clrscr();
					      gotoxy(25,10);cout<<"{ RECORD NOT FOUND }";
					      break;
					}
				  }
			     }
			fout.close();
			break;
		case 4: clrscr();
			gotoxy(13,5);cout<<" DELETI0N  OF  RECORD";
			Libmod q;
			ifstream fine("DNA_LIB.txt",ios::in|ios::out|ios::binary);
			ofstream out("TEMP.txt",ios::in|ios::out|ios::binary);
			int rno,klas;
			gotoxy(20,9);cout<<"ENTER THE ID no. WHOSE RECORD IS TO BE DELETED  :";
			cin>>rno;
			fine.seekg(0);
			while(!fine.eof())
			{
			   fine.read((char*)&q,sizeof(q));
			   if(q.getroll()==rno)
			   {
				q.Delete();
				break;
			   }
			   else
				if(q.getroll()!=rno)
				{
					clrscr();
					gotoxy(25,17);cout<<"RECORD NOT FOUND";
					break;
				}
			}
			remove("DNA_LIB.txt");
			rename("temp.dat","DNA_LIB.txt");
			out.close();
			fine.close();
			break;
		case 5:exit(0);
	      }
	      getch();
	    }


	}

//Sturec v_6.1

/*Copyright(C) 2017-2018. The Priyanshu Ranjan open source project.
Before you proceed,please read the terms and conditions carefully.
Licenced under legal agencies.This is an open source project.
You may not use this unless you agree with the terms and conditions.
Unless required by the legal entity(the programmer) in writing,the user can not develop,modify,or distribute this project or any part of it.
All the rights are reserved under the issuing policy.Illegal use of the project or any part of it can lead to serious legal actions and penalties.
We have ensured minimum errors in this project. But,however,In case of DATA LOSS, ERROR OCCURRENCE,or any other RUN TIME DISABILITY of program, the programmer is not responsible or liable in any situation or case.
User should proceed only if the user takes the responsibility of his/her any kind of loss.*/
 //(C)Priyanshu Ranjan 2017-2018



#include<dos.h>
#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<ctype.h>

void main(void);

class area
{ public:
  int street;
  char block,colony[10];
};
class fdetail
{ public:
  char fname[20],femail[20],foccup[10];
  char fphone[12];
};
class mdetail
{ public:
  char mname[20],memail[20],moccup[20];
  char mphone[12];
};
class addr: public area
{ public:
  int hno,sector;
  char city[10],state[10];
};
class pdetail:public fdetail,public mdetail
{ public:
  char guardn[20];
};
class transport
{ public:
  int route;
  char other[10];
};
class personal
{ public:
 char hobby[20],aim[10],strenth[20],weaknes[20],skill[20];
};                                         //sub-classes

class pinning
{  public:  long PIN;
	    long getpin()
	     { return PIN;}
	   pinning()
	    {   PIN=1234; }
	    void changepn(void);
}pn;


class student:private addr,private pdetail,private transport,private personal,private pinning
{ private:
   int rno,admino,clas,age;
   char sfname[10],slname[10],sec[3];
   char stream[10],bgrup[5];
   char gpswrd[50];
   int n,rut;
   char p[10];

  public:
   int pass;
   void welcome(void);
   void accept(void);
   void settings(void);
   void show(void);
   int getrno()
   { return rno; }
   int getadmino()
   { return admino; }
   student()
   {	pass=0; }
}stu;                          //base class

int gr=2;
void home(void);
void deleterec(void);
void search(void);
void success(void);
void interact(void);

void load()
{  cout<<"\n";
   for(int x=0;x<79;x++)
	{ delay(5); cout<<"_";   delay(5); }
	 delay(40);
}

void delcol()
 {   textbackground(RED); textcolor(BLACK+CYAN);   }


void errcol()
 {  textbackground(RED);  textcolor(WHITE);   }


void pinning::changepn()
{   long newpin,conpin;
     ofstream fout("pin.dat",ios::out|ios::binary);
	 textcolor(BLUE);textbackground(WHITE);
       cout<<"\n Enter the new PIN: "; cin>>newpin;
		  cout<<"\n Confirm the new PIN: "; cin>>conpin;
		  if(conpin==newpin)
		   {  PIN=conpin;
		     fout.write((char*)&pn,sizeof(pn));
			 fout.close();
		       cout<<"\n PIN Successfully changed\n";
		       getch();
                        fout.close();
		      stu.settings();
		   }
		  else
		  {    errcol();
		    cout<<"\n PIN doesn't match.\n";
		    fout.close();
		    getch();
		    stu.settings();
		   }
}

void exitor()                        //quit message
{  textbackground(BLUE); textcolor(WHITE);
   clrscr();
   gotoxy(5,5); cout<<"Saving your preferences";
     for(int m=28;m<36;m++)
       { delay(500); gotoxy(m,5); cout<<"."; }
   delay(1000); gotoxy(5,7); cout<<"Application is shutting down.";
   delay(1000); gotoxy(11,24); cout<<"(C)Copyright 2017-18.Priyanshu Ranjan.All rights reserved(IPR)"; delay(1000);
      for(int d=1;d<80;d++)
       { delay(20); gotoxy(d,25); cout<<"."; } delay(1000);
  }

void terminate()         //auto terminate message
{  clrscr();
   errcol();
	cout<<"\n\nThe software terminated itself might because of the following reasons:";
	cout<<"\n\n(1) The user might not be in the state to proceed.\n";
	cout<<"(2) User might have entered irrelevant answers.\n";
	cout<<"(3) User might have entered a wrong password or PIN somewhere in the software.";
	cout<<"\n(3) User might have mistyped.\n";
	cout<<"(4) There may be a PC fault.";
	 cout<<"\n\nDon't panic,just go through the following steps:\n\n";
	 cout<<">> Troubleshoot the problem,if the reason is one of the above mentioned.";
	 cout<<"\n>> After troubleshooting,restart the software.\n";
	 cout<<">> If you can't trace the problem, then go through the manual provided with the    software CD.";
	 cout<<"\n>> If the problem continues,please report it to the developer at:\n    feedback.sturec@ranjan.com\n";
  cout<<"\n\n\t\t\t(C)Copyright 2017-18.Top Developers.All rights reserved.\n";
 }

void student:: settings()
{ textbackground(WHITE); textcolor(BLACK);
  int oldpin,newpin,conpin,pos;
  char setch;
   fstream fo("pin.dat",ios::in|ios::out|ios::binary);
  afty: clrscr();
  cout<<"================================SOFTWARE SETTING================================\n";
  textbackground(CYAN);
  textcolor(BLACK);
  cout<<"\n(1) Change PIN\n";
  cout<<"(2) Change language\n";
  cout<<"(3) Check for updates\n";
  cout<<"(4) Credits\n";
  cout<<"(5) Restore factory settings\n";
  cout<<"(6) Main menu\n";
  setch=getch();
  switch(setch)
  { case '1': clrscr();
  cout<<"==============================PIN SETTINGS==============================\n";
	   cout<<"\n Enter the current PIN: ";
	    cin>>oldpin;
	    fo.read((char*)&pn,sizeof(pn));
	    if(oldpin==pn.getpin())
		fo.close(); pn.changepn();
	    else { cout<<"\n PIN doesn't match!"; fo.close(); getch(); clrscr(); settings(); }
	      break;
    case '2': { clrscr();
	    cout<<"================================LANGUAGE SETTING================================\n";
	     cout<<"\n\n At present only ENGLISH language is supported.\n More languages will be supported soon.\n"; getch(); fo.close(); clrscr(); settings();}  break;
    case '3':  cout<<"\n\n Checking for updates";
	      for( int i=0; i<10;i++)
	       { cout<<".";
		 delay(200);
		 }
	     cout<<"\n You are using the latest version.Cheers!\n "; delay(2000); load(); clrscr(); fo.close();settings(); break;
     case '6':  fo.close(); home(); break;
     case '5':{ char rech[8];  clrscr();
	       cout<<"\n\n Enter the access PIN: ";
		 cin>>oldpin;
		fo.read((char*)&pn,sizeof(pn));
		   if(oldpin==pn.getpin())
		    { clrscr();
		      cout<<"\n WARNING: All the responses here are irreversible!\n";
		      cout<<"\n Do you want to reset the application to its default settings?\n ";
		      gets(rech);
		     if(strcmpi(rech,"yes")==0)
		     {  cout<<"\n Do you also want to delete all the stored records?\n ";
			gets(rech);
			 if(strcmpi(rech,"yes")==0)
			 {  clrscr();
			   gotoxy(36,13); cout<<"Please wait";
			   for(int s=0;s<5;s++)
			     {   delay(1000); cout<<"."; }
			      remove("sturec.dat"); remove("pin.dat");pn.PIN=1234; delay(3000);
			   gotoxy(3,13); cout<<"Application has been resetted to default settings.Press any key to continue";
			   getch();
                            fo.close();
			   load();
			   main();
			 }
			 else if(strcmpi(rech,"no")==0)
			 {        clrscr();
			    cout<<"\n NOTE: The stored records are not affected";
			   gotoxy(38,13); cout<<"Please wait";
			   for(int s=0;s<5;s++)
			     {   delay(1000); cout<<"."; }
				  remove("pin.dat");pn.PIN=1234; delay(3000);
			   gotoxy(3,13); cout<<"Application has been resetted to default settings.Press any key to continue";
			   load();
                            fo.close();
			   getch();

			   main();
			 }
		     }
		    else
		     fo.close(); settings();
		   }
		else
		 cout<<"\n PIN doesn't match. Reverting";
		 delay(1000);
		 load();
		  for(int x=0;x<80;x++)
		   { delay(10); cout<<"_";   delay(10); }
		     delay(2000);
		 fo.close();
		 settings();
		break; }
     case '4':  fo.close();
		  clrscr();
		   textbackground(GREEN+BLUE); textcolor(WHITE);
		 cout<<"\n\n Developer : Priyanshu Ranjan";
		 cout<<"\n             12th Science";
		 cout<<"\n             Nehru International Public School,Noida";
		 cout<<"\n\n Developer address:\n\t     Mountain view, Puerto Rico,CA (U.S.)";
		 cout<<"\n\n Contact   : priyanshuranjan88@gmail.com";
		 cout<<"\n Support   : www.sturec.co.in/dev";
		 gotoxy(15,16);  cout<<"Try the Sturec Premium to get the best expericience";
		 gotoxy(15,17);  cout<<"Get it from: www.sturec.co.in/premium";
		 gotoxy(15,18); cout<<"(Cost may vary from region to region)";

		 delay(1000); gotoxy(11,20); cout<<"(C)Copyright 2017-18.Priyanshu Ranjan.All rights reserved(IPR)\n";
		 getch();
		  load();
		delay(2000);
		 settings();
     default: fo.close(); settings();
    }
    fo.close();
  }

void student::welcome()                            //welcomer
{ clrscr();
   textbackground(BLUE); textcolor(WHITE);
  long int i,num,mnpwd,k=4,flag;
  char ch,opt,pac[5],tc[5],auth[5],ex[7],mintro[55];
  ifstream fio("pin.dat",ios::in|ios::nocreate|ios::binary);
  do
  {
   mainpswrd:                                        //security check
   clrscr();
    cout<<"=================================SECURITY CHECK=================================\n";
   cout<<" Enter the access PIN: ";
   cin>>mnpwd;
   fio.read((char*)&pn,sizeof(pn));
   if(mnpwd!=pn.getpin())                               //password
   {  flag=1;
      cout<<"\n Access Denied: ";
       if(k-1!=1) cout<<"Only "<<k-1<<" chances left\n";
       else if(k-1==1) { errcol(); cout<<" This is your last attempt.Try your best.\n"; }
       k--;
       if(k>0)
       {
       cout<<"\n Are you an authorised person?\n ";
       gets(auth);cout<<"\n";
	if(strcmpi(auth,"yes")==0||strcmpi(auth,"y")==0||strcmpi(auth,"yep")==0||strcmpi(auth,"yes i am")==0)
	 { long shpn=pn.getpin();
	   cout<<" The passcode is:"<<shpn<<"\n";
	   want: cout<<" Wan't to enter again or not?\n ";
	      gets(pac);
	      { if(strcmpi(pac,"yes")==0||strcmpi(pac,"ok")==0||strcmpi(pac,"okay")==0||strcmpi(pac,"sure")==0||strcmpi(pac,"why not")==0||strcmpi(pac,"y")==0)
		 goto mainpswrd;
		else if(strcmpi(pac,"no")==0||strcmpi(pac,"n")==0)
		  { fio.close(); exitor(); exit(0); }
		else {  cout<<" Please tell whether you";goto want;  }
	       }
	  }
	 else
	  { nwant: cout<<" Wan't to enter again or not?\n ";
	      gets(pac);
	      { if(strcmpi(pac,"yes")==0||strcmpi(pac,"ok")==0||strcmpi(pac,"okay")==0||strcmpi(pac,"sure")==0||strcmpi(pac,"why not")==0||strcmpi(pac,"y")==0)
		 goto mainpswrd;
		else if(strcmpi(pac,"no")==0||strcmpi(pac,"n")==0)
		  { fio.close(); exitor(); exit(0); }
		else {   cout<<" Please tell whether you";goto nwant;  }
	       }
	  }
       }
       else if(k==0)
       { exi:
	cout<<"\n No chances are left now.Press X to exit.\n";
	cin>>ex;
	if(strcmpi(ex,"x")==0||strcmpi(ex,"X")==0)
       { fio.close(); exitor();	exit(0); }
       else
	cout<<"\n I'm really sorry, but please try to understand that ";
	goto exi;
       }
     }
   else
    { cout<<"\n\n Access Granted\n\n\n";
       fio.close(); load();
	 delay(500);

      flag=2; break; }
  } while(k!=0||flag!=2);

    if(flag==2)
   {clrscr();
     cout<<"\n----------------------------------DISCLAIMER------------------------------------\nCopyright(C) 2017. The Priyanshu Ranjan open source project\n";
     cout<<"Before you proceed,please read the terms and conditions carefuly.\n\n\tLicenced under legal agencies.This is an open source project.\n\tYou may not use this unless you agree with the terms and conditions.\n";
    cout<<"\tUnless required by the legal entity, the programmer,in writing,\n\tthe user can not develop,modify,or distribute this project or \n\tany part of it.\n\n\tAll the rights are reserved under the issuing policy.Illegal use of the \tproject or any part of it can lead to serious legal actions and\n\tpenalties.\n";
   cout<<"\nWe have ensured minimum errors in this project. But,however,In case of DATA LOSS ERROR OCCURRENCE,or any other RUN TIME DISABILITY of program, the programmer is not responsible or liable in any situation or case.User should proceed only if the user takes the responsibility of his/her any kind of loss.\n";
   cout<<"--------------------------------------------------------------------------------";
   cout<<" If you agree with the terms and conditions and want to proceed,say YES.Else say NO to QUIT.\nEnter here: ";
   gets(tc);
    if(strcmpi(tc,"no")==0||strcmpi(tc,"quit")==0)
      { exitor(); exit(0); }

     else if(strcmpi(tc,"yes")==0||strcmpi(tc,"y")==0||strcmpi(tc,"agree")==0||strcmpi(tc,"yes i agree")==0)		    //if agreed
     { cout<<"\n";load();
       clrscr();
	 textbackground(BLACK); textcolor(WHITE);
	for(int l=1;l<=100;l++)
	 { gotoxy(35,8); cout<<"LOADING "<<l<<" %"; delay(10);

	 }
	cout<<"\n";

	 for(int k=l;k<80;k++)
	  { gotoxy(k,10);delay(10);  cout<<"||"; delay(10); }

	 interact();
	}
      else
      { terminate();  exit(0);  }
  } }

void interact()
{    char mintro[30];
     textbackground(BLUE+BLACK); textcolor(WHITE);
     char hm[60],intro[55],nice[40];
	clrscr();
	char mood[56], siri[55],newser[12];
	cout<<"===============================BEFORE YOU PROCEED===============================";
	 cout<<"\n Hello! can I have your name?\n ";
	 bhai:
	 gets(mintro);
	 strcpy(intro,mintro);
	 if(strcmpi(mintro,"no")==0)
	  { cout<<"\n Okay.How are you?\n ";
	    gets(mood);
	  }
	 else if(strcmpi(mintro,"yes")==0||strcmpi(mintro,"sure")==0)
	 { cout<<"\n Please tell me your good name: ";
	   goto bhai;
	 }
	 else
	  {
	    cout<<"\n ";
	    puts(strcat(mintro,"! How are you?"));
	    cout<<" ";gets(mood);
	  }
       if(strcmpi(mood,"fine")==0||strcmpi(mood,"good")==0||strcmpi(mood,"happy")==0||strcmpi(mood,"i am fine")==0||strcmpi(mood,"i'm fine")==0||strcmpi(mood,"im fine")==0||strcmpi(mood,"i am good")==0)
       { hell:
	 char cont[23];
	 cout<<"\n Are you a new user?\n ";
	 gets(newser);
	 if(strcmpi(newser,"no")==0||strcmpi(newser,"nope")==0||strcmpi(newser,"n")==0)
	  { load(); home(); }
	 else
	 { cout<<"\n I am your assistant throughout the program,and you can call me anywhere in this program wherever you are strucked.But before that you have to give me my name.\n Suggest any name you like:";
	 gets(siri);
	 strcpy(hm," Great! ");
	 strcat(hm,siri);
	 strcpy(nice," is a nice name!");
	 strcat(hm,nice);
	 cout<<"\n";
	 puts(hm);
	   cout<<"\n (1) Try to answer in yes or no in program, whenever asked to do so, or respond     as per the requirement.\n";
	   cout<<" (2) Be patient while the program runs.\n";
	   cout<<" (3) Try to keep your text shorter wherever possible. Otherwise software may get     overloaded.\n";
	   cout<<"\n Now type YES to continue, NO to quit: ";
	   gets(cont);
	  if(strcmpi(cont,"no")==0)
	   {exitor(); exit(0); }
	  else
	    {load();
	    home();}
	  }
       }
     else   // if bad mood
     { errcol();
      char bad;
      cout<<"\n You can press X to exit,or C to continue: ";
	 bad=getch();
       if(bad=='C'||bad=='c')
	{ load(); home(); }
       else if(bad=='x'||bad=='X')
       { exitor();
	exit(0);
	}
      else{ exitor(); exit(0); }

     }
  }


void home()
{ conti:  textbackground(GREEN+BLUE); textcolor(BLACK);
  clrscr();
   char ch;
    cout<<"================================================================================\n";
   cout<<"               \t                 MAIN MENU \n";
   cout<<"\n Hello, what do you want to do?\n";
   cout<<"\n (1) Add a new record in drive\n";
   cout<<" (2) See a particular record\n";
   cout<<" (3) Delete an existing record\n";
   cout<<" (4) Exit main menu\n";
   cout<<" (5) App settings\n";
   cout<<" (6) Quit application\n";
   gotoxy(70,24); cout<<" (B) Back\n";
   ch=getch();
   switch(ch)
   {   char qt;
    case '2': search(); break;                                                      //confirm to quit
    case '1':   clrscr();   int norec;
	      gotoxy(2,2); cout<<"How many records do you want to enter this time?\n ";
	      gotoxy(70,24); cout<<" (0) Back\n";
	      gotoxy(2,4); cin>>norec;
	      if(norec==0||norec==0)
	       home();
	      else {
	      cout<<"\n\n";
	      load();
	      for(int i=0; i<norec;i++)
	      { clrscr();
	       cout<<"================================ADD RECORD TO DRIVE=============================\n";
	       cout<<"Enter Record Number: "<<i+1<<"\n";
	       stu.accept(); }
	       load();
	      success();} break;
    case '3':  deleterec();  break;
    case '4':  stu.welcome(); break;
    case 'b':  interact();
    case 'B':  interact();
    case '5': clrscr(); stu.settings(); goto conti;
    case '6':  { mno:delcol(); clrscr(); cout<<"===============================CONFIRM TO QUIT================================\n";
		      gotoxy(30,10); cout<<"Do you want to exit?\n";
			gotoxy(30,12);cout<<" (1) Yes    (2) No\n\n\t\t\t\t       ";
			qt=getch();
			if(qt=='2')
			goto conti;
			else if(qt=='1')
			{ exitor();
			 exit(0);}
			else goto mno;
			  break;}
      default: goto conti;
   }        //switch closed
}

void search()                 //case 2: to search an existing record
{   student stur;
   int num;
   char opt,qt;
   ifstream fin;
   fin.open("sturec.dat",ios::in|ios::binary|ios::nocreate);
   do
   { clrscr();  textbackground(GREEN); textcolor(WHITE);
   cout<<"=====================================SEARCH=====================================\n";
     cout<<"\n Enter the roll or admission number of a particular person: ";
      cin>>num;
     int flag=0;
     if(!fin)
       { cout<<"\n File is empty. Reverting in ";
          fin.close();   for(int i=5;i>=1;i--)
       {  gotoxy(30,6);cout<<i<<" seconds"; delay(1000);}
      home(); }
     else{
      while(!fin.eof())
       { fin.read((char*)&stur, sizeof(stur));
	 if(stur.getrno()==num||stur.getadmino()==num)
	      { stur.show();
		flag=1;
		goto done;
	      }
	 else flag=2;
       }
      if(flag==2)
      {  errcol(); cout<<"\nSorry, No such student in the record\n";  }
     done:
     fin.close();
      cout<<"\nIf you want to continue the search press C, press M for main menu, X to exit\n";
      opt=getch(); }
    }while(opt=='C'||opt=='c');
    if(opt=='m'||opt=='M')
     home();
    else if(opt=='x'||opt=='X')
     { gum: clrscr(); delcol(); cout<<"===============================CONFIRM TO QUIT================================\n";
		       gotoxy(30,10);cout<<"Do you want to exit?\n";
			gotoxy(30,12);cout<<" (1) Yes    (2) No\n\n\t\t\t\t       ";
			qt=getch();
			if(qt=='2')
			home();
			else if(qt=='1')
			{ exitor();
			 exit(0);}
			else goto gum;
     }
     else home();
}

void student::accept()                       //case 2: add a record
{  char ch,opt[5],cl,pwdch[8],cnfpwd[15];
  fstream fo;
  fo.open("sturec.dat",ios::app|ios::binary);

   cout<<"Please enter the details asked:\n ";
    cout<<"\nRoll no.: ";
    cin>>rno;
    cout<<"\nAdmission no.: ";
    cin>>admino;
    cout<<"\nFirst Name: ";
    gets(sfname);
    cout<<"\nLast name: ";
    gets(slname);
    cout<<"\nAge: ";
    cin>>age;
    cout<<"\nAddress details\n";
     cout<<"House no.: ";
     cin>>hno;
     cout<<"\nBlock: ";
     cin>>block;
     cout<<"\nStreet no.: ";
     cin>>street;
     cout<<"\nArea: ";
     gets(colony);
     cout<<"\nSector: ";
     cin>>sector;
     cout<<"\nCity: ";
     gets(city);
     cout<<"\nState: ";
     gets(state);
    cout<<"\nParent's details\n";
     cout<<"Mother's name: ";
     gets(mname);
     cout<<"\nOccupation: ";
     gets(moccup);
     cout<<"\nContact no.: ";
     gets(mphone);
     cout<<"\nEmail-ID: ";
     gets(memail);
     cout<<"\nFather's name: ";
     gets(fname);
     cout<<"\nOccupation: ";
     gets(foccup);
     cout<<"\nContact no.: ";
     gets(fphone);
     cout<<"\nEmail-ID: ";
     gets(femail);
     cout<<"\nAny guardian?(y/n)\n";
     cin>>ch;
       if(ch=='y'||ch=='Y')
       { gr=1;
	 cout<<"\nGuardian name: ";
	gets(guardn); goto brud; }
       else
       { gr=0;
	 brud:
     cout<<"\nAvailing school transport faclities?: ";
     gets(opt);
      if(strcmpi(opt,"y")==0||strcmpi(opt,"yes")==0)
      {  cout<<"\nEnter the route no.: ";
	cin>>route;
	rut=route;
      }
     else
      { cout<<"\nMode of transport: ";
	gets(other);
	rut=route;
      }
     cout<<"\nPersonal details please\n";
      cout<<"\nHobbies: ";
      gets(hobby);
      cout<<"\nAim in life: ";
      gets(aim);
      cout<<"\nStrengths: ";
      gets(strenth);
      cout<<"\nWeaknesses: ";
      gets(weaknes);
      cout<<"\nSkills: ";
      gets(skill);
      cout<<"\nStudying in which class? ";
	cin>>clas;
	  if(clas==11||clas==12)
	   { cout<<"\nStream opted: ";
	     gets(stream);
	     strcpy(p,stream);
	   }
	   else
	   { cout<<"Section: ";
	     gets(sec);
	     strcpy(p,sec);
	   }
       cout<<"\nBlood group: ";
       gets(bgrup);
       pc:
      cout<<"\nWant to secure personal info?\n";
      gets(pwdch);
      if(strcmpi(pwdch,"yes")==0)
      { pass=1; pswrd:
	cout<<"\nEnter a password: ";
	gets(gpswrd);
	int len=strlen(gpswrd);
	 if(len<8)
	 { cout<<"\nPlease enter at least 8 charecters!\n";
	   goto pswrd;
	 }
	 else
	 { cout<<"\nConfirm your password: ";
	   gets(cnfpwd);
	   if(strcmpi(gpswrd,cnfpwd)!=0)
	     { cout<<"\n\aPassword do not match!";
	      goto pswrd;
	     }
	    else
	   cout<<"\nPassword confirmed\n";
	 }
	}      //password accepted
     else
      { char sure[8];
	cout<<"\nThe personal inforamation might be vulnerable if not protected.Are you sure not to keep a password for personal information?\n";
	gets(sure);
	if(strcmpi(sure,"y")==0||strcmpi(sure,"yes")==0||strcmpi(sure,"sure")==0||strcmpi(sure,"yes i am sure")==0||strcmpi(sure,"yes i'm sure")==0)
	{ pass=0; goto sucs; }
	else goto pc;
      }
    }
    sucs:
    fo.write((char*)&stu,sizeof(stu));
    fo.close(); 
 }

void success()
{
  con:
  clrscr();                                       //success
  char added,qt;
   cout<<"==================================TASK SUCCESS==================================\n";
  cout<<"\n Record was successfully manipuated in drive.\n Press M to return to main menu,or X to exit.\n ";
  added=getch();
  if(added=='M'||added=='m')
   home();
  else if(added=='x'||added=='X')
   { gum: clrscr(); delcol(); cout<<"===============================CONFIRM TO QUIT================================\n";
		       gotoxy(30,10);cout<<"Do you want to exit?\n";
			gotoxy(30,12); cout<<" (1) Yes    (2) No\n\n\t\t\t\t       ";
			qt=getch();
			if(qt=='2')
			 home();
			else if(qt=='1')
			{ cout<<"\n\n\t\t\t  "; exitor();
			 exit(0);}
			else goto gum;
    }
  else  goto con;                         //accepted values
}


void deleterec()             //case 3: to delete a record
{  student delstu;

   int no; char conf='2',flag='f',del[7],aftdel;
   redel: clrscr();
   textbackground(GREEN); textcolor(BLACK);
   ifstream fio("sturec.dat",ios::in|ios::binary|ios::nocreate);
   ofstream file("temp.dat",ios::out|ios::binary);
   cout<<"=====================================DELETE=====================================\n";
   cout<<"\n Enter the roll number or admission number of student to delete record: ";
   cin>>no;
   if(!fio)
   { cout<<"\n File is empty.Reverting in ";
      fio.close(); file.close(); for(int i=5;i>=1;i--)
       {  gotoxy(29,6);cout<<i<<" seconds"; delay(1000);}

      home(); }
  else{
   while(!fio.eof())
   {  fio.read((char*)&delstu,sizeof(delstu));
      if(fio.eof())
       break;
     if(delstu.getrno()==no||delstu.getadmino()==no)
      { delstu.show(); flag='t';
	cout<<"\n Type YES to delete or NO to return: ";
	 gets(del);
	    if(strcmpi(del,"no")==0)
	      { fio.close(); file.close();home();}
            else
              {  gum: delcol(); clrscr(); cout<<"==============================CONFIRM TO DELETE===============================\n";
		       gotoxy(28,10);cout<<"Do you want to delete "<<no<<" ?\n";
			gotoxy(30,12);cout<<" (1) Yes    (2) No\n\n\t\t\t\t       ";
			conf=getch();
			if(conf=='2')
			 file.write((char*)&delstu,sizeof(delstu));
			else if(conf!='1'&&conf!='2')
			 goto gum;
	      }
      }
     else
      file.write((char*)&delstu,sizeof(delstu));
  }
      fio.close();
     file.close();
     remove("sturec.dat");
     rename("temp.dat","sturec.dat");
    if(flag=='f')
    {  cout<<"\n No such record exists in drive.\n\nPress M for main menu,C to search again,X to exit: ";
     aftdel=getch();
     if(aftdel=='m'||aftdel=='M')
       home();
     else if(aftdel=='c'||aftdel=='C')
	goto redel;
     else if(aftdel=='x'||aftdel=='X')
	{ cum: char qt; delcol(); clrscr(); cout<<"===============================CONFIRM TO QUIT================================\n";
		       gotoxy(30,10); cout<<"Do you want to exit?\n";
			gotoxy(30,12);cout<<" (1) Yes    (2) No\n\n\t\t\t\t       ";
			qt=getch();
			if(qt=='2')
			 home();
			else if(qt=='1')
			{ exitor();
			 exit(0);}
			else goto cum;  }


   else home();
  }
  else if(flag=='t') success();
}
}
void student::show()                       //display a record
{ char gjz,d[6],epswrd[15],k[5],name[70],ma[70],pa[70],ad[70];
	 int snap=0,z=4,ngram;
   aftshow:
   textbackground(BLUE+BLACK); textcolor(WHITE);
    clrscr();
  { cout<<"\n=====================================DETAILS====================================\n";
   for(int e=3;e<=22;e++)
   {  gotoxy(40,e);cout<<"|"; }
   gotoxy(2,3);cout<<" Roll number: "<<rno;
   strcat(sfname," ");
   strcat(sfname,slname);
    toupper(sfname[0]);
    for(int g=0;g<strlen(sfname);g++)
    { if(sfname[g]==' ')
      toupper(sfname[g+1]); }
    gotoxy(2,4); cout<<" Name of Student: ";
    puts(sfname);
    gotoxy(2,5);cout<<" Admission Number: "<<admino;
    gotoxy(42,4); cout<<" Class: ";
      if(clas==1)
	cout<<clas<<"st "<<p;
      else if(clas==2)
	cout<<clas<<"nd "<<p;
      else if(clas==3)
	cout<<clas<<"rd "<<p;
      else cout<<clas<<"th "<<p;
    strcat(bgrup,"+");
    char gp[]={" Blood Group: "};
    strcat(gp,bgrup);gotoxy(42,5); puts(gp);
    gotoxy(2,6); cout<<" Age: "<<age;
    gotoxy(29,8); cout<<"RESIDENTIAL DETAILS";
     gotoxy(2,9); cout<<" House number: "<<hno;
    gotoxy(42,9); cout<<" Locality: "<<street<<","<<block<<",";
     puts(colony);
     gotoxy(2,10); cout<<" City: "; puts(city);
     gotoxy(42,10); cout<<" State: "; puts(state);
    gotoxy(30,12); cout<<" TRANSPORT DETAILS ";
   if(rut!=0)
      {	gotoxy(2,13);cout<<" Route number: "<<rut; }
   else { gotoxy(2,13); cout<<" Mode of transport: "; puts(other);   }
    gotoxy(30,15); cout<<" PARENTAL DETAILS\n";
     gotoxy(2,16); cout<<" Father's name: "; puts(fname);
     gotoxy(42,16);cout<<" Occupation: "; puts(foccup);
     gotoxy(2,17); cout<<" Phone number: "<<fphone;
     gotoxy(42,17); cout<<" Email ID: ";  puts(femail);
     gotoxy(2,19); cout<<" Mother's name: ";  puts(mname);
      gotoxy(42,19);cout<<" Occupation: "; puts(moccup);
      gotoxy(2,20); cout<<" Phone number "<<mphone;
      gotoxy(42,20); cout<<" Email ID: ";  puts(memail);
      if(gr==1)
      {
	gotoxy(2,21); cout<<" Guardian: ";  puts(guardn);     }
     cout<<"\n\n Want personal details also?: ";  cin>>d;

     if(strcmpi(d,"y")==0||strcmpi(d,"yes")==0)
     {
       for(int x=0;gpswrd[x]!='\0';++x)
	{ if(x>0)
	   snap=1;
	 }
       if(snap==1)
	{if(!pass)
	goto detail;
	do
	  {  rpwrd:
	  clrscr();
	  cout<<"\n\n Enter the access password for personal details: ";
	   gets(epswrd);
	    if(strcmpi(epswrd,gpswrd)==0)
	     {
	      detail:
	       clrscr();
		cout<<"\nAccess granted for: PERSONAL DETAILS";
	       cout<<"\n\n Hobbies: ";
	       puts(hobby);
	       cout<<"\n Creative skills: ";
	       puts(skill);
	       cout<<"\n Strength: ";
	       puts(strenth);
	       cout<<"\n Weakness: ";
	       puts(weaknes);
	       cout<<"\n Aim in life: ";
	       puts(aim);
	       cout<<"\n Press B to go back,M for main menu, X to exit\n ";
	       gjz=getch();
	       if(gjz=='b'||gjz=='B')
		goto aftshow;
	       else if(gjz=='m'||gjz=='M')
		home();
	       else if(gjz=='x'||gjz=='X')
		{ cout<<"\n\n"; exitor();}
	       else goto detail;
	      }

	  else if(strcmpi(epswrd,gpswrd)!=0)
	      { errcol();cout<<"\n\aAccess Denied\n";
		cout<<"\nTry again for personal details?";
	        gets(k);
		if(strcmpi(k,"y")==0||strcmpi(k,"yes")==0)
		 goto rpwrd;
		else if(strcmpi(k,"n")==0||strcmpi(k,"no")==0)
		 home();
	       }
	  } while(z!=0||ngram==1);          //while closed
	 }
       else
	goto detail;
     }                        //choice of yes closed
    else
     cout<<"\n As you wish\n";
   }
}

void main()          //main body
{ clrscr();
 textbackground(BLUE); textcolor(WHITE);
   gotoxy(30,3); delay(2000);
   cout<<"S T U R E C O R D E R";
   gotoxy(34,8);
    delay(2000); cout<<"W "; delay(100); cout<<"E ";delay(100);cout<<"L ";delay(100);cout<<"C ";delay(100);cout<<"O ";delay(100);cout<<"M ";delay(100);cout<<"E \n";delay(800);
    for(int i=0;i<80;i++)
    { delay(10); cout<<"_";  }  delay(1000);
      gotoxy(37,14); cout<<" +_/";delay(990);cout<<"\\_+";delay(2000);
      delay(1000); gotoxy(11,24); cout<<"(C)Copyright 2017-18.Priyanshu Ranjan.All rights reserved(IPR)"; delay(2000);
      for(int d=1,e=79;d<=40&&e>=40;d++,e--)
       { delay(100); gotoxy(d,25); cout<<".";gotoxy(e,25);cout<<"."; } delay(3000);
stu.welcome();  }

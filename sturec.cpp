
//accSturec v_7 (upgraded sturec)

/*Copyright(C) 2019-2020. The Priyanshu Ranjan open source project.
Before you proceed,please read the terms and conditions carefully.
Licenced under legal agencies.This is an open source project.
You may not use this unless you agree with the terms and conditions.
Unless required by the legal entity(the programmer) in writing,the user can not develop,modify,or distribute this project or any part of it.
All the rights are reserved under the issuing policy.Illegal use of the project or any part of it can lead to serious legal actions and penalties.
I have ensured minimum errors in this project. But, however, in case of DATA LOSS, ERROR OCCURRENCE,or any other RUN TIME DISABILITY of program, the programmer is not responsible or liable in any situation or case.
User should proceed only if the user takes the responsibility of his/her any kind of loss.*/
//(C)Copyright Priyanshu Ranjan 2019.



#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<ctype.h>
#include<conio.h>

using namespace std;
int main(void);

class area
{
public:
	int street;
	char block, colony[10];
};
class fdetail
{
public:
	char fname[20], femail[20], foccup[10];
	char fphone[12];
};
class mdetail
{
public:
	char mname[20], memail[20], moccup[20];
	char mphone[12];
};
class addr : public area
{
public:
	int hno, sector;
	char city[10], state[10];
};
class pdetail :public fdetail, public mdetail
{
public:
	char guardn[20];
};
class transport
{
public:
	int route;
	char other[10];
};
class personal
{
public:
	char hobby[20], aim[10], strenth[20], weaknes[20], skill[20];
};                                         //sub-classes

class pinning
{
public:  long PIN;
		 long getpin()
		 {
			 return PIN;
		 }
		 pinning()
		 {
			 PIN = 1234;
		 }
		 void changepn(void);
}pn;


class student :private addr, private pdetail, private transport, private personal, private pinning
{
private:
	int rno, admino, clas, age;
	char sfname[10], slname[10], sec[3];
	char stream[10], bgrup[5];
	char gpswrd[50];
	int n, rut;
	char p[10];

public:
	int pass;
	void welcome(void);
	void accept(void);
	void settings(void);
	void show(void);
	int getrno()
	{
		return rno;
	}
	int getadmino()
	{
		return admino;
	}
	student()
	{
		pass = 0;
	}
}stu;                          //base class

class account
{
private:
	char faccnm[50], laccnm[20];
	char accusrnm[20], accpass[20];
	char accphn[12], accmail[20];
	int accage;
	char accbday[18], accnat[10], acctou[10];
public:
	void create(void);
	void login(void);
	// char retusrnm()
	 // { return *accusrnm; }
}acc;
int gr = 2;
void home(void);
void deleterec(void);
void terminate(void);
void colouring(int textColor, int bgColor) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}

void gotoxy(int x, int y)
{
	COORD coordinates;     // coordinates is declared as COORD
	coordinates.X = x;     // defining x-axis
	coordinates.Y = y;     //defining  y-axis
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void search(void)                 //case 2: to search an existing record
{
	student stur;
	int num;
	char opt, qt;
	ifstream fin;
	fin.open("sturec.dat", ios::in | ios::binary );
	do
	{
		system("cls");  system("color 7F"); //colouring(8);
		cout << "=====================================SEARCH=====================================\n";
		cout << "\n Enter the roll or admission number of a particular person: ";
		cin >> num;
		int flag = 0;
		if (!fin)
		{
			cout << "\n File is empty. Reverting in ";
			fin.close();   for (int i = 5;i >= 1;i--)
			{
				gotoxy(30, 6);cout << i << " seconds"; Sleep(1000);
			}
			home();
		}
		else {
			while (!fin.eof())
			{
				fin.read((char*)&stur, sizeof(stur));
				if (stur.getrno() == num || stur.getadmino() == num)
				{
					stur.show();
					flag = 1;
					goto done;
				}
				else flag = 2;
			}
			if (flag == 2)
			{
				/*errcol();*/ cout << "\nSorry, No such student in the record\n";
			}
		done:
			fin.close();
			cout << "\nIf you want to continue the search press C, press M for main menu, X to exit\n";
			opt = getchar();
		}
	} while (opt == 'C' || opt == 'c');
	if (opt == 'm' || opt == 'M')
		home();
	else if (opt == 'x' || opt == 'X')
	{
	gum: system("cls");/* delcol();*/ cout << "===============================CONFIRM TO QUIT================================\n";
		gotoxy(30, 10);cout << "Do you want to exit?\n";
		gotoxy(30, 12);cout << " (1) Yes    (2) No\n\n\t\t\t\t       ";
		qt = getchar();
		if (qt == '2')
			home();
		else if (qt == '1')
		{
		//	exitor();
			exit(0);
		}
		else goto gum;
	}
	else home();
}

void success(void);
void interact(void);
void exitor(void);
void errcol(void);
void delcol(void);
void load(void);
void load()
{
	cout<<"\n";
	for (int x = 0;x < 79;x++)
	{
		Sleep(5); cout << "_";   Sleep(5);
	}
	Sleep(40);
}

void delcol()
{
	int empty = 0;//textbackground(RED);
	//colouring(448);
}


void errcol()
{
	//textbackground(RED);
	//colouring(000);
}


void pinning::changepn()
{
	long newpin, conpin;
	ofstream fout("pin.dat", ios::out | ios::binary);
	//colouring(007);//textbackground(WHITE);
	cout << "\n Enter the new PIN: "; cin >> newpin;
	cout << "\n Confirm the new PIN: "; cin >> conpin;
	if (conpin == newpin)
	{
		PIN = conpin;
		fout.write((char*)&pn, sizeof(pn));
		fout.close();
		cout << "\n PIN Successfully changed\n";
		getchar();
		fout.close();
		stu.settings();
	}
	else
	{
		errcol();
		cout << "\n PIN doesn't match.\n";
		fout.close();
		getchar();
		stu.settings();
	}
}

void exitor()                        //quit message
{
	//textbackground(BLUE);
	//colouring(000);
	system("cls");
	gotoxy(5, 5); cout << "Saving your preferences";
	for (int m = 28;m < 36;m++)
	{
		Sleep(500); gotoxy(m, 5); cout << ".";
	}
	Sleep(1000); gotoxy(5, 7); cout << "Application is shutting down.";
	Sleep(1000); gotoxy(11, 24); cout << "(C)Copyright 2017-18.Priyanshu Ranjan.All rights reserved(IPR)"; Sleep(1000);
	for (int j = 0;j < 5;j++)
	{
		for (int d = 1;d < 80;d++)
		{
			Sleep(10); gotoxy(d, 25); cout << ".";
		}
		for (int e = 1;e < 80;e++)
		{
			Sleep(10); gotoxy(e, 25); cout << " ";
		} //Sleep(500);
	}
}

void terminate()         //auto terminate message
{
	system("cls");
	//errcol();
	cout << "\n\nThe software terminates itself often because of the following reasons:";
	cout << "\n\n(1) The user might not have agreed to the terms and conditions.\n";
	cout << "(2) User might have entered irrelevant answers.\n";
	cout << "(3) User might have entered a wrong password or PIN somewhere in the software.";
	cout << "\n(3) User might have mistyped.\n";
	cout << "(4) There may be a PC fault.";
	cout << "\n\nDon't panic,just go through the following steps:\n\n";
	cout << ">> Troubleshoot the problem,if the reason is one of the above mentioned.";
	cout << "\n>> After troubleshooting,restart the software.\n";
	cout << ">> If you can't trace the problem, then go through the manual provided with the software CD.";
	cout << "\n>> If the problem continues,please report it to the developer at:\n    feedback.sturec@ranjan.com\n";
	Sleep(5000);
	cout << "\n\n\t\t\t(C)Copyright 2017-18.Top Developers.All rights reserved.\n";
	Sleep(2000); cout << "\nPRESS ANY KEY"; getchar();
}

void student::settings()
{
	//textbackground(WHITE); 
	//colouring(800);
	int oldpin, newpin, conpin, pos;
	char setch;
	fstream fo("pin.dat", ios::in | ios::out | ios::binary);
afty: system("cls");
	cout << "================================SOFTWARE SETTING================================\n";
	//textbackground(000000);
	//colouring (888);
	cout << "\n(1) Change PIN\n";
	cout << "(2) Change language\n";
	cout << "(3) Check for updates\n";
	cout << "(4) Credits\n";
	cout << "(5) Restore factory settings\n";
	cout << "(6) Main menu\n";
	setch = getchar();
	switch (setch)
	{
	case '1': system("cls");
		cout << "==============================PIN SETTINGS==============================\n";
		cout << "\n Enter the current PIN: ";
		cin >> oldpin;
		fo.read((char*)&pn, sizeof(pn));
		if (oldpin == pn.getpin())
		{
			fo.close(); pn.changepn();
		}
		else {
			cout << "\n PIN doesn't match!"; fo.close(); getchar(); system("cls"); settings(); }
			break;
	case '2': { system("cls");
		cout << "================================LANGUAGE SETTING================================\n";
		cout << "\n\n At present only ENGLISH language is supported.\n More languages will be supported soon.\n"; getchar(); fo.close(); system("cls"); settings();}  break;
	case '3':  cout << "\n\n Checking for updates";
		for (int i = 0; i < 10;i++)
		{
			cout << ".";
			Sleep(200);
		}
		cout << "\n You are using the latest version.Cheers!\n "; Sleep(2000); load(); system("cls"); fo.close();settings(); break;
	case '6':  fo.close(); home(); break;
	case '5': { char rech[8];  system("cls");
		cout << "\n\n Enter the access PIN: ";
		cin >> oldpin;
		fo.read((char*)&pn, sizeof(pn));
		if (oldpin == pn.getpin())
		{
			system("cls");
			cout << "\n WARNING: All the responses here are irreversible!\n";
			cout << "\n Do you want to reset the application to its default settings?\n ";
			cin.getline(rech, '\n');
			if (_strcmpi(rech, "yes") == 0)
			{
				cout << "\n Do you also want to delete all the stored records?\n ";
				cin.getline(rech, '\n');
				if (_strcmpi(rech, "yes") == 0)
				{
					system("cls");
					gotoxy(36, 13); cout << "Please wait";
					for (int s = 0;s < 5;s++)
					{
						Sleep(1000); cout << ".";
					}
					remove("sturec.dat"); remove("pin.dat");pn.PIN = 1234; Sleep(3000);
					gotoxy(3, 13); cout << "Application has been resetted to default settings.Press any key to continue";
					getchar();
					fo.close();
					load();
					main();
				}
				else if (_strcmpi(rech, "no") == 0)
				{
					system("cls");
					cout << "\n NOTE: The stored records are not affected";
					gotoxy(38, 13); cout << "Please wait";
					for (int s = 0;s < 5;s++)
					{
						Sleep(1000); cout << ".";
					}
					remove("pin.dat");pn.PIN = 1234; Sleep(3000);
					gotoxy(3, 13); cout << "Application has been resetted to default settings.Press any key to continue";
					load();
					fo.close();
					getchar();

					main();
				}
			}
			else
				fo.close(); settings();
		}
		else
			cout << "\n PIN doesn't match. Reverting";
		Sleep(1000);
		load();
		for (int x = 0;x < 80;x++)
		{
			Sleep(10); cout << "_";   Sleep(10);
		}
		Sleep(2000);
		fo.close();
		settings();
		break; }
	case '4':  fo.close();
		system("cls");
		//textbackground(FFFFFF);
		//colouring(000);
		cout << "\n\n Developer : Priyanshu Ranjan";
		cout << "\n             12th Science";
		cout << "\n             Nehru International Public School,Noida";
		cout << "\n\n Developer address:\n\t     Mountain view, Puerto Rico,CA (U.S.)";
		cout << "\n\n Contact   : priyanshuranjan88@gmail.com";
		cout << "\n Support   : www.sturec.co.in/dev";
		gotoxy(15, 16);  cout << "Try the Sturec Premium to get the best expericience";
		gotoxy(15, 17);  cout << "Get it from: www.sturec.co.in/premium";
		gotoxy(15, 18); cout << "(Cost may vary from region to region)";
		Sleep(1000); gotoxy(11, 20); cout << "(C)Copyright 2017-18.Priyanshu Ranjan.All rights reserved(IPR)\n";
		getchar();
		load();
		Sleep(2000);
		settings();
	default: fo.close(); settings();
	}
			  fo.close();
		}
  

void student::welcome()                            //welcomer
{
	system("cls");
	//textbackground(BLUE);
	//colouring(800);
	long int i, num, mnpwd, k = 4, flag;
	char ch, opt; char pac[5], tc[5], auth[5], ex[7], mintro[55];
	ifstream fio("pin.dat", ios::in | ios::binary);//ios::nocreate |*/
	
		do
		{
		 mainpswrd:                                        //security check
		   system("cls");
			cout << "=================================SECURITY CHECK=================================\n";
			cout << " Enter the access PIN: ";
			cin >> mnpwd;gotoxy(24, 3);for (int v = 0;v < sizeof(mnpwd);v++) { cout << "*"; }
			fio.read((char*)&pn, sizeof(pn));
			if (mnpwd != pn.getpin())                               //password
			{
				flag = 1;
				cout << "\n Access Denied: ";
				if (k - 1 != 1) cout << "Only " << k - 1 << " chances left\n";
				else if (k - 1 == 1) { errcol(); cout << " This is your last attempt.Try your best.\n"; }
				k--;
				if (k > 0)
				{
					cout << "\n Are you an authorised person?\n ";
					cin.getline(auth, '\n');cout << "\n";
					if (_strcmpi(auth, "yes") == 0 || _strcmpi(auth, "y") == 0 || _strcmpi(auth, "yep") == 0 || _strcmpi(auth, "yes i am") == 0)
					{
						long shpn = pn.getpin();
						cout << " The passcode is:" << shpn << "\n";
					want: cout << " Wan't to enter again or not?\n ";
						cin.getline(pac, '\n');
						{ if (_strcmpi(pac, "yes") == 0 || _strcmpi(pac, "ok") == 0 || _strcmpi(pac, "okay") == 0 || _strcmpi(pac, "sure") == 0 || _strcmpi(pac, "why not") == 0 || _strcmpi(pac, "y") == 0)
							goto mainpswrd;
						else if (_strcmpi(pac, "no") == 0 || _strcmpi(pac, "n") == 0)
						{
							fio.close(); exitor(); exit(0);
						}
						else { cout << " Please tell whether you";goto want; }
						}
					}
					else
					{
					nwant: cout << " Wan't to enter again or not?\n ";
						cin.getline(pac, '\n');
						{ if (_strcmpi(pac, "yes") == 0 || _strcmpi(pac, "ok") == 0 || _strcmpi(pac, "okay") == 0 || _strcmpi(pac, "sure") == 0 || _strcmpi(pac, "why not") == 0 || _strcmpi(pac, "y") == 0)
							goto mainpswrd;
						else if (_strcmpi(pac, "no") == 0 || _strcmpi(pac, "n") == 0)
						{
							fio.close(); exitor(); exit(0);
						}
						else { cout << " Please tell whether you";goto nwant; }
						}
					}
				}
				else if (k == 0)
				{
				exi:
					cout << "\n No chances are left now.Press X to exit.\n";
					cin >> ex;
					if (_strcmpi(ex, "x") == 0 || _strcmpi(ex, "X") == 0)
					{
						fio.close(); exitor();	exit(0);
					}
					else
						cout << "\n I'm really sorry, but please try to understand that ";
					goto exi;
				}
			}
			else
			{
				cout << "\n\n Access Granted\n\n\n";
				fio.close(); load();
				Sleep(500);

				flag = 2; break;
			}
		} while (k != 0 || flag != 2);
	
	if (flag == 2)
	{
		system("cls");
		cout << "\n----------------------------------DISCLAIMER------------------------------------\nCopyright(C) 2017. The Priyanshu Ranjan open source project\n";
		cout << "Before you proceed,please read the terms and conditions carefuly.\n\n\tLicenced under legal agencies.This is an open source project.\n\tYou may not use this unless you agree with the terms and conditions.\n";
		cout << "\tUnless required by the legal entity, the programmer,in writing,\n\tthe user can not develop,modify,or distribute this project or \n\tany part of it.\n\n\tAll the rights are reserved under the issuing policy.Illegal use of the \tproject or any part of it can lead to serious legal actions and\n\tpenalties.\n";
		cout << "\nWe have ensured minimum errors in this project. But,however,In case of DATA LOSS ERROR OCCURRENCE,or any other RUN TIME DISABILITY of program, the programmer is not responsible or liable in any situation or case.User should proceed only if the user takes the responsibility of his/her any kind of loss.\n";
		cout << "--------------------------------------------------------------------------------";
		cout << " If you agree with the terms and conditions and want to proceed,say YES.Else say NO to QUIT.\nEnter here: ";
		cin.getline(tc, '\n');
		if (_strcmpi(tc, "no") == 0 || _strcmpi(tc, "quit") == 0)
		{
			exitor(); Sleep(8000); exit(0);
		}

		else if (_strcmpi(tc, "yes") == 0 || _strcmpi(tc, "y") == 0 || _strcmpi(tc, "agree") == 0 || _strcmpi(tc, "yes i agree") == 0)		    //if agreed
		{
			cout << "\n";load();
			system("cls");
			//textbackground(BLACK);
			//colouring(800);
			for (int l = 1;l <= 100;l++)
			{
				gotoxy(35, 8); cout << "LOADING " << l << " %"; Sleep(10);

			}
			cout << "\n";

			for (int k = 1;k < 80;k++)
			{
				gotoxy(k, 10);Sleep(10);  cout << "||"; Sleep(10);
			}

			interact();
		}
		else
		{
			terminate();  exit(0);
		}
	}
}

void interact()
{
	char mintro[30];
	//textbackground(BLUE + BLACK);
	//colouring(800);
	system("color A1");
	char hm[60], intro[55], nice[40];
	system("cls");
	char mood[56], siri[55], newser[12];
	cout << "===============================BEFORE YOU PROCEED===============================";
	cout << "\n Hello! can I have your name?\n ";
bhai:
	cin.getline(mintro, '\n');
	strcpy_s(intro, mintro);
	if (_strcmpi(mintro, "no") == 0)
	{
		cout << "\n Okay.How are you?\n ";
		cin.getline(mood, '\n');
	}
	else if (_strcmpi(mintro, "yes") == 0 || _strcmpi(mintro, "sure") == 0)
	{
		cout << "\n Please tell me your good name: ";
		goto bhai;
	}
	else
	{
		const char howru[20]= "! How are you?";
		cout << "\n ";
     	//puts(strcat(mintro,howru));
		cout << " ";cin.getline(mood, '\n');
	}
	if (_strcmpi(mood, "fine") == 0 || _strcmpi(mood, "good") == 0 || _strcmpi(mood, "happy") == 0 || _strcmpi(mood, "i am fine") == 0 || _strcmpi(mood, "i'm fine") == 0 || _strcmpi(mood, "im fine") == 0 || _strcmpi(mood, "i am good") == 0)
	{
	hell:
		char cont[23];
		cout << "\n Are you a new user?\n ";
		cin.getline(newser, '\n');
		if (_strcmpi(newser, "no") == 0 || _strcmpi(newser, "nope") == 0 || _strcmpi(newser, "n") == 0)
		{
			load(); home();
		}
		else
		{
			cout << "\n I am your assistant throughout the program,and you can call me anywhere in this program wherever you are strucked.But before that you have to give me my name.\n Suggest any name you like:";
			cin.getline(siri, '\n');
			strcpy_s(hm, " Great! ");
			strcat_s(hm, siri);
			strcpy_s(nice, " is a nice name!");
			strcat_s(hm, nice);
			cout << "\n";
			puts(hm);
			cout << "\n (1) Try to answer in yes or no in program, whenever asked to do so, or respond     as per the requirement.\n";
			cout << " (2) Be patient while the program runs.\n";
			cout << " (3) Try to keep your text shorter wherever possible. Otherwise software may get     overloaded.\n";
			cout << "\n Now type YES to continue, NO to quit: ";
			cin.getline(cont, '\n');
			if (_strcmpi(cont,"no") == 0)
			{
				exitor(); exit(0);
			}
			else
			{
				load();
				home();
			}
		}
	}
	else   // if bad mood
	{
		errcol();
		char bad;
		cout << "\n You can press X to exit,or C to continue: ";
		bad = getchar();
		if (bad == 'C' || bad == 'c')
		{
			load(); home();
		}
		else if (bad == 'x' || bad == 'X')
		{
			exitor();
			exit(0);
		}
		else { exitor(); exit(0); }

	}
}


void home()
{
conti://textbackground(GREEN+BLUE);
	//colouring(800);
	system("cls");
	char ch;
	cout << "================================================================================\n";
	cout << "               \t                 MAIN MENU \n";
	cout << "\n Hello, what do you want to do?\n";
	cout << "\n (1) Add a new record in drive\n";
	cout << " (2) See a particular record\n";
	cout << " (3) Delete an existing record\n";
	cout << " (4) Login\n";
	cout << " (5) Exit main menu\n";
	cout << " (6) App settings\n";
	cout << " (7) Quit application\n";
	gotoxy(70, 24); cout << " (B) Back\n";
	ch = getchar();
	switch (ch)
	{
		char qt;
	case '2': search(); break;                                                      //confirm to quit
	case '1':   system("cls");   int norec;
		gotoxy(2, 2); cout << "How many records do you want to enter this time?\n ";
		gotoxy(70, 24); cout << " (0) Back\n";
		gotoxy(2, 4); cin >> norec;
		if (norec == 0 || norec == 0)
			home();
		else {
			cout << "\n\n";
			load();
			for (int i = 0; i < norec;i++)
			{
				system("cls");
				cout << "================================ADD RECORD TO DRIVE=============================\n";
				cout << "Enter Record Number: " << i + 1 << "\n";
				stu.accept();
			}
			load();
			success();
		} break;
	case '3':  deleterec();  break;
	case '4':  acc.login(); break;
	case '5':  stu.welcome(); break;
	case 'b':  interact();
	case 'B':  interact();
	case '6': system("cls"); 
		     stu.settings(); goto conti;
	case '7': { mno:delcol(); system("cls"); 
		cout << "===============================CONFIRM TO QUIT================================\n";
		gotoxy(30, 10); cout << "Do you want to exit?\n";
		gotoxy(30, 12);cout << " (1) Yes    (2) No\n\n\t\t\t\t       ";
		qt = getchar();
		if (qt == '2')
			goto conti;
		else if (qt == '1')
		{
			exitor();
			exit(0);
		}
		else goto mno;
		break;}
	default: goto conti;
	}        //switch closed
}

void student::accept()                       //case 2: add a record
{
	char ch, cl;char opt[5], pwdch[8], cnfpwd[15];
	fstream fo;
	fo.open("sturec.dat", ios::app | ios::binary);

	cout << "Please enter the details asked:\n ";
	cout << "\nRoll no.: ";
	cin >> rno;
	cout << "\nAdmission no.: ";
	cin >> admino;
	cout << "\nFirst Name: ";
	cin.getline(sfname, '\n');
	cout << "\nLast name: ";
	cin.getline(slname, '\n');
	cout << "\nAge: ";
	cin >> age;
	cout << "\nAddress details\n";
	cout << "House no.: ";
	cin >> hno;
	cout << "\nBlock: ";
	char(block);
	cout << "\nStreet no.: ";
	cin >> street;
	cout << "\nArea: ";
	cin.getline(colony, '\n');
	cout << "\nSector: ";
	cin >> sector;
	cout << "\nCity: ";
	cin.getline(city, '\n');
	cout << "\nState: ";
	cin.getline(state, '\n');
	cout << "\nParent's details\n";
	cout << "Mother's name: ";
	cin.getline(mname, '\n');
	cout << "\nOccupation: ";
	cin.getline(moccup, '\n');
	cout << "\nContact no.: ";
	cin.getline(mphone, '\n');
	cout << "\nEmail-ID: ";
	cin.getline(memail, '\n');
	cout << "\nFather's name: ";
	cin.getline(fname, '\n');
	cout << "\nOccupation: ";
	cin.getline(foccup, '\n');
	cout << "\nContact no.: ";
	cin.getline(fphone, '\n');
	cout << "\nEmail-ID: ";
	cin.getline(femail, '\n');
	cout << "\nAny guardian?(y/n)\n";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		gr = 1;
		cout << "\nGuardian name: ";
		cin.getline(guardn, '\n'); goto brud;
	}
	else
	{
		gr = 0;
	brud:
		cout << "\nAvailing school transport faclities?: ";
		cin.getline(opt, '\n');
		if (_strcmpi(opt, "y") == 0 || _strcmpi(opt, "yes") == 0)
		{
			cout << "\nEnter the route no.: ";
			cin >> route;
			rut = route;
		}
		else
		{
			cout << "\nMode of transport: ";
			cin.getline(other, '\n');
			rut = route;
		}
		cout << "\nPersonal details please\n";
		cout << "\nHobbies: ";
		cin.getline(hobby, '\n');
		cout << "\nAim in life: ";
		cin.getline(aim, '\n');
		cout << "\nStrengths: ";
		cin.getline(strenth, '\n');
		cout << "\nWeaknesses: ";
		cin.getline(weaknes, '\n');
		cout << "\nSkills: ";
		cin.getline(skill, '\n');
		cout << "\nStudying in which class? ";
		cin >> clas;
		if (clas == 11 || clas == 12)
		{
			cout << "\nStream opted: ";
			cin.getline(stream, '\n');
			strcpy_s(p, stream);
		}
		else
		{
			cout << "Section: ";
			cin.getline(sec, '\n');
			strcpy_s(p, sec);
		}
		cout << "\nBlood group: ";
		cin.getline(bgrup, '\n');
	pc:
		cout << "\nWant to secure personal info?\n";
		cin.getline(pwdch, '\n');
		if (_strcmpi(pwdch, "yes") == 0)
		{
			pass = 1; pswrd:
		cout << "\nEnter a password: ";
		cin.getline(gpswrd, '\n');
		size_t len = strlen(gpswrd);
		if (len < 8)
		{
			cout << "\nPlease enter at least 8 charecters!\n";
			goto pswrd;
		}
		else
		{
			cout << "\nConfirm your password: ";
			cin.getline(cnfpwd, '\n');
			if (_strcmpi(gpswrd, cnfpwd) != 0)
			{
				cout << "\n\aPassword do not match!";
				goto pswrd;
			}
			else
				cout << "\nPassword confirmed\n";
		}
		}      //password accepted
		else
		{
			char sure[8];
			cout << "\nThe personal inforamation might be vulnerable if not protected.Are you sure not to keep a password for personal information?\n";
			cin.getline(sure, '\n');
			if (_strcmpi(sure, "y") == 0 || _strcmpi(sure, "yes") == 0 || _strcmpi(sure, "sure") == 0 || _strcmpi(sure, "yes i am sure") == 0 || _strcmpi(sure, "yes i'm sure") == 0)
			{
				pass = 0; goto sucs;
			}
			else goto pc;
		}
	}
sucs:
	fo.write((char*)&stu, sizeof(stu));
	fo.close();
}

void success()
{
con:
	system("cls");                                       //success
	char added, qt;
	cout << "==================================TASK SUCCESS==================================\n";
	cout << "\n Record was successfully manipuated in drive.\n Press M to return to main menu,or X to exit.\n ";
	added = getchar();
	if (added == 'M' || added == 'm')
		home();
	else if (added == 'x' || added == 'X')
	{
	gum: system("cls"); 
		delcol(); cout << "===============================CONFIRM TO QUIT================================\n";
		gotoxy(30, 10);cout << "Do you want to exit?\n";
		gotoxy(30, 12); cout << " (1) Yes    (2) No\n\n\t\t\t\t       ";
		qt = getchar();
		if (qt == '2')
			home();
		else if (qt == '1')
		{
			cout << "\n\n\t\t\t  "; exitor();
			exit(0);
		}
		else goto gum;
	}
	else  goto con;                         //accepted values
}


void deleterec()             //case 3: to delete a record
{
	student delstu;

	int no; char conf = '2', flag = 'f', aftdel; char del[7];
redel: system("cls");
	//textbackground(GREEN); 
	//colouring(800);
	ifstream fio("sturec.dat", ios::in | ios::binary );
	ofstream file("temp.dat", ios::out | ios::binary);
	cout << "=====================================DELETE=====================================\n";
	cout << "\n Enter the roll number or admission number of student to delete record: ";
	cin >> no;
	if (!fio)
	{
		cout << "\n File is empty.Reverting in ";
		fio.close(); file.close(); for (int i = 5;i >= 1;i--)
		{
			gotoxy(29, 6);cout << i << " seconds"; Sleep(1000);
		}

		home();
	}
	else {
		while (!fio.eof())
		{
			fio.read((char*)&delstu, sizeof(delstu));
			if (fio.eof())
				break;
			if (delstu.getrno() == no || delstu.getadmino() == no)
			{
				delstu.show(); flag = 't';
				cout << "\n Type YES to delete or NO to return: ";
				cin.getline(del, '\n');
				if (_strcmpi(del, "no") == 0)
				{
					fio.close(); file.close();home();
				}
				else
				{
				gum: delcol(); system("cls"); 
					cout << "==============================CONFIRM TO DELETE===============================\n";
					gotoxy(28, 10);cout << "Do you want to delete " << no << " ?\n";
					gotoxy(30, 12);cout << " (1) Yes    (2) No\n\n\t\t\t\t       ";
					conf = getchar();
					if (conf == '2')
						file.write((char*)&delstu, sizeof(delstu));
					else if (conf != '1'&&conf != '2')
						goto gum;
				}
			}
			else
				file.write((char*)&delstu, sizeof(delstu));
		}
		fio.close();
		file.close();
		remove("sturec.dat");
		rename("temp.dat", "sturec.dat");
		if (flag == 'f')
		{
			cout << "\n No such record exists in drive.\n\nPress M for main menu,C to search again,X to exit: ";
			aftdel = getchar();
			if (aftdel == 'm' || aftdel == 'M')
				home();
			else if (aftdel == 'c' || aftdel == 'C')
				goto redel;
			else if (aftdel == 'x' || aftdel == 'X')
			{
			cum: char qt; delcol(); system("cls"); 
				cout << "===============================CONFIRM TO QUIT================================\n";
				gotoxy(30, 10); cout << "Do you want to exit?\n";
				gotoxy(30, 12);cout << " (1) Yes    (2) No\n\n\t\t\t\t       ";
				qt = getchar();
				if (qt == '2')
					home();
				else if (qt == '1')
				{
					exitor();
					exit(0);
				}
				else goto cum;
			}


			else home();
		}
		else if (flag == 't') success();
	}
}

void student::show()                       //display a record
{
	char gjz; char d[6], epswrd[15], k[5], name[70], ma[70], pa[70], ad[70];
	int snap = 0, z = 4, ngram=0;
aftshow:
	//textbackground(BLUE + BLACK);
	//colouring(800);
	system("cls");
	{ cout << "\n=====================================DETAILS====================================\n";
	for (int e = 3;e <= 22;e++)
	{
		gotoxy(40, e);cout << "|";
	}
	gotoxy(2, 3);cout << " Roll number: " << rno;
	strcat_s(sfname, " ");
	strcat_s(sfname, slname);
	toupper(sfname[0]);
	for (int g = 0;g < strlen(sfname);g++)
	{
		if (sfname[g] == ' ')
			toupper(sfname[g + 1]);
	}
	gotoxy(2, 4); cout << " Name of Student: ";
	puts(sfname);
	gotoxy(2, 5);cout << " Admission Number: " << admino;
	gotoxy(42, 4); cout << " Class: ";
	if (clas == 1)
		cout << clas << "st " << p;
	else if (clas == 2)
		cout << clas << "nd " << p;
	else if (clas == 3)
		cout << clas << "rd " << p;
	else cout << clas << "th " << p;
	// strcat_s(bgrup,"+");
	char gp[] = { " Blood Group: " };
	strcat_s(gp, bgrup);gotoxy(42, 5); puts(gp);
	gotoxy(2, 6); cout << " Age: " << age;
	gotoxy(29, 8); cout << "RESIDENTIAL DETAILS";
	gotoxy(2, 9); cout << " House number: " << hno;
	gotoxy(42, 9); cout << " Locality: " << street << "," << block << ",";
	puts(colony);
	gotoxy(2, 10); cout << " City: "; puts(city);
	gotoxy(42, 10); cout << " State: "; puts(state);
	gotoxy(30, 12); cout << " TRANSPORT DETAILS ";
	if (rut != 0)
	{
		gotoxy(2, 13);cout << " Route number: " << rut;
	}
	else { gotoxy(2, 13); cout << " Mode of transport: "; puts(other); }
	gotoxy(30, 15); cout << " PARENTAL DETAILS\n";
	gotoxy(2, 16); cout << " Father's name: "; puts(fname);
	gotoxy(42, 16);cout << " Occupation: "; puts(foccup);
	gotoxy(2, 17); cout << " Phone number: " << fphone;
	gotoxy(42, 17); cout << " Email ID: ";  puts(femail);
	gotoxy(2, 19); cout << " Mother's name: ";  puts(mname);
	gotoxy(42, 19);cout << " Occupation: "; puts(moccup);
	gotoxy(2, 20); cout << " Phone number " << mphone;
	gotoxy(42, 20); cout << " Email ID: ";  puts(memail);
	if (gr == 1)
	{
		gotoxy(2, 21); cout << " Guardian: ";  puts(guardn);
	}
	cout << "\n\n Want personal details also?: ";  cin.getline(d, '\n');

	if (_strcmpi(d, "y") == 0 || _strcmpi(d, "yes") == 0)
	{
		for (int x = 0;gpswrd[x] != '\0';++x)
		{
			if (x > 0)
				snap = 1;
		}
		if (snap == 1)
		{
			if (!pass)
				goto detail;
			do
			{
			rpwrd:
				system("cls");
				cout << "\n\n Enter the access password for personal details: ";
				cin.getline(epswrd, '\n');
				if (_strcmpi(epswrd, gpswrd) == 0)
				{
				detail:
					system("cls");
					cout << "\nAccess granted for: PERSONAL DETAILS";
					cout << "\n\n Hobbies: ";
					puts(hobby);
					cout << "\n Creative skills: ";
					puts(skill);
					cout << "\n Strength: ";
					puts(strenth);
					cout << "\n Weakness: ";
					puts(weaknes);
					cout << "\n Aim in life: ";
					puts(aim);
					cout << "\n Press B to go back,M for main menu, X to exit\n ";
					gjz = getchar();
					if (gjz == 'b' || gjz == 'B')
						goto aftshow;
					else if (gjz == 'm' || gjz == 'M')
						home();
					else if (gjz == 'x' || gjz == 'X')
					{
						cout << "\n\n"; exitor();
					}
					else goto detail;
				}

				else if (_strcmpi(epswrd, gpswrd) != 0)
				{
					errcol();cout << "\n\aAccess Denied\n";
					cout << "\nTry again for personal details?\n ";
					cin.getline(k, '\n');
					if (_strcmpi(k, "y") == 0 || _strcmpi(k, "yes") == 0)
						goto rpwrd;
					else if (_strcmpi(k, "n") == 0 || _strcmpi(k, "no") == 0)
						home();
				}
			} while (z != 0 || ngram == 1);          //while closed
		}
		else
			goto detail;
	}                        //choice of yes closed
	else
		cout << "\n As you wish\n";
	}
}
void account::login()
{
	system("cls");
	//colouring(800);// textbackground(BLUE);
	fstream fcin; char ch; char user[20], userpass[20]; int log = 0;
lgin: fcin.open("account.dat", ios::in | ios::out | ios::binary );//ios::nocreate);
	system("cls"); gotoxy(70, 24); cout << "(B)Back";

	gotoxy(1, 2);cout << "\n Press C to create an account.\n L to login.\n ";
	ch = getchar();

	if (ch == 'b' || ch == 'B')
	{
		fcin.close(); home();
	}
	else if (ch == 'c' || ch == 'C')
	{
		system("cls"); fcin.close(); create();
	}
	else if (ch == 'l' || ch == 'L')
	{
		fcin.seekg(0);
		cout << "\n Enter your username\n ";
		cin.getline(user, '\n');
		while (!fcin.eof())
		{
			fcin.read((char*)&acc, sizeof(acc));
			if (_strcmpi(user, accusrnm) != 0)
			{
				printf("\n No account exists");
				ch = getchar(); fcin.close(); goto lgin;
			}
			else if (_strcmpi(user, accusrnm) == 0)
			{
				cout << "\n Enter the password\n "; cin.getline(userpass, '\n');
				if (strcmp(userpass, accpass) != 0)
				{
					cout << "\nInvalid password"; ch = getchar();fcin.close(); goto lgin;
				}
				else if (strcmp(userpass, accpass) == 0)
				{
				wll: system("cls");
					gotoxy(67, 24); cout << "(3) LOGOUT";
					strcat_s(faccnm, " ");
					strcat_s(faccnm, laccnm);
					gotoxy(1, 3); cout << "\n Welcome";gotoxy(10, 4); puts(faccnm);
					cout << "\n What do you want?\n\n";
					cout << " (1) Chat";
					cout << "\n (2) My profile\n";
					short ch=0;
					switch (ch)
					{
					case '3':system("cls"); printf(faccnm); cout << " ";printf(laccnm);printf(" do you really want to log out?");
						cout << "(1) YES\t(2) NO";    
						if (log == 1)
						{
							system("cls"); cout << "Please wait";Sleep(1500); cout << "\nYouv'e been logged out successfully.";Sleep(1500); fcin.close(); home(); break;
						}
						else goto wll;

					case '1': cout << "\n Many features are under construction.\n This is one of them.";
						getchar(); fcin.close(); cout << "\nYouv'e been logged out"; Sleep(2000); home();
					case '2': inf: system("cls");
						gotoxy(38, 2); cout << "PROFILE\n\n ";
						printf(faccnm);cout << " "; printf(laccnm);
						cout << "\n\n Username: "; printf(accusrnm);
						cout << "\n\n Birthday: "; printf(accbday);
						cout << "\n\n Age: " << accage << " years old";
						cout << "\n\n Email ID: ";printf(accmail);
						cout << "\n\n Phone: ";printf(accphn);
						gotoxy(69, 24); cout << "(B) BACK";
						char bk = getchar();
						if (bk == 'B' || bk == 'b')
							goto wll;
						else goto inf;


					}
				}
			}
		}
	}
	else { fcin.close();goto lgin; }
	fcin.close();
	home();
}
void account::create()
{
	system("cls");
	//colouring(800);// textbackground(BLUE);
	cout << "\nThis segment of software is in beta release. Might break anytime.\n\nProceed with caution\n";
	getchar(); system("cls");
	fstream fcout;char ch;
	fcout.open("account.dat", ios::app | ios::binary);
	do {
		cout << "\nEnter your first name: "; cin.getline(faccnm, '\n');
		cout << "\nEnter the last name: "; cin.getline(laccnm, '\n');
		cout << "\nEnter your birth date(like:1 January 2001): ";cin.getline(accbday, '\n');
		cout << "\nEnter your age: ";cin >> accage;
		if (accage < 18)
		{
			cout << "\nYou are not eligible to create an account here.Come after a few years.";Sleep(5000);
			fcout.close(); home();
		}
		else
		{
			char cnfaccpass[20];
			cout << "\nEnter your email ID: "; cin.getline(accmail, '\n');
			cout << "\nEnter your phone number: "; cin.getline(accphn, '\n');
			cout << "\nEnter your username for login purpose: ";
			cin.getline(accusrnm, '\n');passw:
			cout << "\nEnter your password: ";
			cin.getline(accpass, '\n');
			cout << "\nConfirm your password: ";
			cin.getline(cnfaccpass, '\n');
			if (strcmp(accpass, cnfaccpass) != 0)
			{
				cout << "\nPasswords do not match";
				ch = getchar();
				goto passw;
			}
			else
			{
				cout << "\nPassword confirmed.";
				cout << "\nenter the charecters shown: xO1eFVql\n "; char capctcha[20];
				cin.getline(capctcha, '\n');
				if (strcmp(capctcha, "xO1eFVql") != 0)
				{
					cout << "\nDoesn't match";
					fcout.close(); Sleep(2000); home();
				}
				else
				{
					fcout.write((char*)&acc, sizeof(acc));
					printf("\nYour account was successfully created, ");
					puts(faccnm);
					fcout.close();
					cout << "\nWant to login now?(y/n) "; ch = getchar();
					if (ch == 'y')
						login();
					else  home();
				}
			}
		}
	} while (!fcout.eof() || ch != 'x' || ch != 'X');
	if (ch == 'x') home();
}
int main()          //main body
{
	system("cls");
	//textbackground(BLUE);
	
	gotoxy(30, 3); Sleep(2000);
	colouring(7, 1);
	cout << "A C C O U S T U R E C";
	gotoxy(34, 8);
	Sleep(2000); cout << "W "; Sleep(400); cout << "E ";Sleep(400);cout << "L ";Sleep(400);cout << "C ";Sleep(400);cout << "O ";Sleep(400);cout << "M ";Sleep(400);cout << "E \n";Sleep(800);
	for (int i = 0;i < 80;i++)
	{
		Sleep(10); cout << "_";
	}  Sleep(1000);
	gotoxy(37, 14); cout << " +_/";Sleep(990);cout << "\\_+";Sleep(2000);
	Sleep(1000); gotoxy(11, 23); cout << "(C)Copyright 2017-18.Priyanshu Ranjan.All rights reserved(IPR)"; Sleep(2000);
	for (int m = 0;m < 5;m++)
	{
		for (int x1 = 39, x2 = 40;x1 >= 1 && x2 <= 80;x1--, x2++)
		{
			Sleep(10); gotoxy(x1, 1); cout << ".";gotoxy(x2, 1);cout << ".";
		}
		for (int y1 = 1, y2 = 1;y1 <= 24 && y2 <= 24;y1++, y2++)
		{
			Sleep(20); gotoxy(1, y1); cout << ".";gotoxy(80, y2);cout << ".";
		}
		for (int x3 = 1, x4 = 80;x3 <= 40 && x4 >= 40;x3++, x4--)
		{
			Sleep(10); gotoxy(x3, 24); cout << ".";gotoxy(x4, 24);cout << ".";
		}
		for (int bx1 = 39, bx2 = 40;bx1 >= 1 && bx2 <= 80;bx1--, bx2++)
		{
			Sleep(10); gotoxy(bx1, 1); cout << " ";gotoxy(bx2, 1);cout << " ";
		}
		for (int by1 = 1, by2 = 1;by1 <= 24 && by2 <= 24;by1++, by2++)
		{
			Sleep(20); gotoxy(1, by1); cout << " ";gotoxy(80, by2);cout << " ";
		}
		for (int bx3 = 1, bx4 = 80;bx3 <= 40 && bx4 >= 40;bx3++, bx4--)
		{
			Sleep(10); gotoxy(bx3, 24); cout << " ";gotoxy(bx4, 24);cout << " ";
		}
	}
	// }
	  Sleep(500);
	//  char v = _getch();
	stu.welcome();
 return 0;
}

#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<conio.h>
//using namespace std;
void predictor(void);
int main()
{
    begin:
	int num=0; int n=0; char start[4], prev[4], gen;
	fstream fio, fcount;
	cout << "\n Do you want me to run with the last record?";
	cin.getline(prev, '\n');
	if (strcmp(prev, "no") == 0)
	{
		fcount.open("counter.txt", ios::in | ios::out);
		fio.open("numberpredict.txt", ios::in | ios::out);
		cout << "\n Please tell me your gender (first letter only): ";
		cin >> gen;
		cout << "\n How many times should I record your activity? (Remember that the more this number, the better my prediction.): ";
		cin >> n;
		//cout << "\n\n Enter a number between 1 and 10: ";
		//cin >> num;
		fcount << n;
		fio << num;
		for (int i = 0;i < n;i++)
		{
			cout << "\n Enter another (Repetition is allowed): ";
			cin >> num;
			fio << num;
			/*if (n % 2 == 0)
			{
				if (i = (n / 2))
					cout << "\n Just halfway there ;-).";
				else continue;
			}
			else
			{
				if (i = (n + (1 / 2)))
					cout << "\n Keep entering. You're almost there.";
				else continue;
			}*/

		}
		fio.close();
		fcount.close();
		predictor();
	}
	else if (strcmp(prev, "yes") == 0)
	{
		while (!fio||!fcount)
		{
			cout << "\n No previous data retrived. Starting from the beginning."; delay(3000);
			goto begin;
		}
		if(fio&&fcount)
		{
			cout << "\n Shall I start my prediction?";
			cin.getline(start, '\n');
			if (strcmp(start, "no") == 0)
			{
				cout << "\n Your wish is my command.";delay(2000);cout << "\n No discussions further.\n"; delay(1000);
				cout << "\n I value your privacy, so please let me know, whether you want your traces here to be removed or not? ";
				char rem = getch();
				if (rem == 'y')
				{
					delete("counter.txt");
					delete("numberpredict.txt");
					cout << "\n Have a good day! See ya!";delay(2000);
					exit(0);
				}
				else 
				{
					delay(1000); exit(0);
				}
			}
			else if (strcmp(start, "yes") == 0)
			{
				predictor();

			}
		}
	}
	else goto begin;
	return 0;
}

void predictor()
{
	short num;int n,v = 0,m = 0, i = 0, temp = 0,count[10],fav[20];char nxt; short ar[40];
	double prob[10];
	ifstream fio, fcount;
	fcount.open("counter.txt", ios::in | ios::nocreate);
	fio.open("numberpredict.txt", ios::in | ios::nocreate);
	fcount >> n;
	while (!fio.eof() && i < n)
	{
		fio >> num;
		ar[i] = num;
	}
	for (int x = 0;x < n;x++)
	{
		for (int i = 0;i < n;i++)
		{
			if (ar[i] > ar[i + 1])
			{
				temp = ar[i];
				ar[i] = ar[i + 1];
				ar[i + 1] = temp;
			}
		}
	}
	count[0] = 1;
	for (int k = 0;k < n;k++)
	{
		if (ar[k] == ar[k + 1])
			count[m]++;
		else 
		{
			if(v==0)
			{
			    fav[v] = ar[k];
			    fav[v + 1] = ar[k + 1];
				v += 2;
			}
			else if (ar[k] == fav[v - 1])
			{
				fav[v] = ar[k + 1];
				v++;
			}
			else
			{
				fav[v] = ar[k];
				fav[v + 1] = ar[k + 1];
			}
			m++;
			count[m] = 1;
		}
	}
	for(int s=0;s<v;s++)
	{
		cout << fav[s] << " ";
	}
	for ( s = 0;s < v;s++)
	{
		cout << count[s] << " ";
	}
	char st = getch();
	cout<<st;
	fio.close();
	fcount.close();
	exit(0);
}
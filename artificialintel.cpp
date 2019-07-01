#include<iostream>
#include<fstream>
#include<string.h>
#include<Windows.h>
using namespace std;
void predictor(void);

void predictor()
{
	short num;int n, v = 0, m = 0, i = 0, temp = 0, count[10], fav[20];char nxt; short ar[40];
	double prob[10];
	ifstream fio, fcount;
	fcount.open("counter.txt", ios::in | ios::_Nocreate | ios::_Noreplace);
	fio.open("numberpredict.txt", ios::in | ios::_Nocreate | ios::_Noreplace);
	if(fcount)
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
			if (v == 0)
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
	for (int s = 0;s < v;s++)
	{
		cout << fav[s] << " ";
	}
	for (int s = 0;s < v;s++)
	{
		cout << count[s] << " ";
	}
	cout << "hellp;";
	Sleep(7000);
	fio.close();
	fcount.close();
}
int main()
{
    begin:
	int num=0; int n=0; char start[4], prev[4], gen;
	fstream fio, fcount;
	fcount.open("counter.txt", ios::in | ios::out | ios::_Nocreate);
	fio.open("numberpredict.txt", ios::in | ios::out | ios::_Nocreate);
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
		
		fcount << n;
		fio << num;cout << "\n (Repetition is allowed):.";
		for (int i = 0;i < n;i++)
		{
			if (i != 0)
			{
				cout << "\n\n Enter another: ";
				cin >> num;
				fio << num;
			}
			else
			{
				cout << "\n\n Enter a number between 1 and 10: ";
				cin >> num;
			}
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
			if (i == (n-1))
				predictor();
		}
		//predictor();
		fio.close();
		fcount.close(); return 0;
	}
	else if (strcmp(prev, "yes") == 0)
	{
		while (!fio||!fcount)
		{
			cout << "\n No previous data retrived. Starting from the beginning."; Sleep(3000);
			goto begin;
		}
		if(fio&&fcount)
		{
			cout << "\n Shall I start my prediction?";
			cin.getline(start, '\n');
			if (strcmp(start, "no") == 0)
			{
				cout << "\n Your wish is my command.";Sleep(2000);cout << "\n No discussions further.\n"; Sleep(1000);
				cout << "\n I value your privacy, so please let me know, whether you want your traces here to be removed or not? ";
				char rem = getchar();
				if (rem == 'y')
				{
					delete("counter.txt");
					delete("numberpredict.txt");
					cout << "\n Have a good day! See ya!";Sleep(2000); return 1;
					exit(0);
				}
				else 
				{
					Sleep(1000); return 0; exit(0);
				}
			}
			else if (strcmp(start, "yes") == 0)
			{
				predictor();
				return 1;

			}
		}
	}
	else return 0;;
}


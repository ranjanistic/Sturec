#include<iostream>
#include<fstream>
#include<string.h>
#include<Windows.h>
#define time(x) Sleep(x*60000);
using namespace std;
int main()
{
	int n, g = 0, v = 0, m = 0, i = 0; float ar[90], count[90], eve[90], temp = 0;
	float prob[90];
	cout << "\n Enter the amount of data you want to be recorded: ";
	cin >> n;
	cout << "\n Enter here the data " << n << " times.";
	while (g < n)
	{
		if (g > 0)
		{	cout << "\n Enter again: ";
		cin >> ar[g];
	    }
		else 
		{
			cout << "\n Enter: ";
			cin >> ar[g];
		}
		if (n % 2 == 0)
		{
			if (g == (n / 2))
				cout << "\n Just there.Keep entering.\n";
		}
		else if (n % 2 != 0)
		{
			if (g == ((n + 1) / 2))
				cout << "\n Almost there.Keep entering.";
		}
		g++;
		if (g == 1)cout << " (Repetition is allowed)\n";
	}
	for (int x = 0;x < n;x++)
	{
		for (int y = 0;y < n;y++)
		{
			if (ar[y] > ar[y + 1])
			{
				temp = ar[y];
				ar[y] = ar[y + 1];
				ar[y + 1] = temp;
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
				eve[v] = ar[k];
				eve[v + 1] = ar[k + 1];
				v += 2;
			}
			else if (ar[k] == eve[v - 1] && v!=0)
			{
				eve[v] = ar[k + 1];
				v++;
			}
			else
			{
				eve[v] = ar[k];
				eve[v + 1] = ar[k + 1];
			}
			m++;
			count[m] = 1;
		}
	}
	cout << "\n\n The frequency distribution is following-\n\n Events: ";
	for (int s = 1;s < v;s++)
	{
		cout << eve[s] << " ";
	}
	cout << "\n Frqncy: ";
	for (int b = 1;b < v;b++)
	{
		cout << count[b] << " ";
	}
	cout << "\n Prblty: ";
	for(int h=1;h<v;h++)
	{
		prob[h] = (count[h] /n);
		cout << prob[h]<<" ";
	}
	time(5); return(0);
}
#include <iostream>
using namespace std;

double howLongForXMoney(double rate, int times, int n = 0, double sum = 1);
double howMuchInXTime(double rate, int numTime, int n = 0, double sum = 1);

int main()
{	
	string time = "";
	string inp;
	cout << string(2, '\n');
	cout << "Welcome to the rate-time calculator! NOTE: This calculator assumes accumulated"<< endl;
	cout << "income is constantly being reinvested." << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Type <day> if rate is daily. <year> if yearly: " << endl;
	cin >> time;
	cout << "-----------------------------------------------------------------" << endl;
	while(1)
	{
		inp = "";
		cout << "Type <mult> to calculate how long it would take to multiply money by X" << endl;
		cout << "Type <time> to calculate how much you could multiply money in X " << time << "s." << endl;
		cout << "Type <Exit> to exit." << endl;
		cin >> inp;
		cout << "-----------------------------------------------------------------" << endl;
		if(inp == "mult")
		{
			double rate;
			int times;
			cout << "Enter rate, then <Enter>, then how much you want money to multiply, then <Enter>." << endl;
			cin >> rate;
			cin >> times;
			cout << "It would take " << howLongForXMoney(rate,times) << " " << time << "s for money to multiply by " << times << endl;
			cout << '\n' << endl;	
			continue;
		}
		else if (inp == "time")
		{
			double rate;
			int numTime;
			cout << "Enter rate, then <Enter>, then how many " << time << "s to accumulate." << endl;
			cin >> rate;
			cin >> numTime;
			cout << "You would make " << howMuchInXTime(rate,numTime) << "X the money in " << numTime << " " << time << "s." << endl;
			cout << '\n' << endl;	
			continue;
		}

		else if (inp == "exit")
		{
			return 0;
		}

		else
		{
			cout << "Invalid input. Try again: " << endl;
			cout << '\n' << endl;	
			continue;
		}
	}
	return 0;
}
double howLongForXMoney(double rate, int times, int n, double sum)
{
	if(sum >= times-0.0005)
		return n;
	n++;
	return howLongForXMoney(rate,times,n,sum+(rate*sum));
}

double howMuchInXTime(double rate, int numTime, int n, double sum)
{
	if(n >= numTime)
		return sum;
	n++;
	return howMuchInXTime(rate,numTime,n,sum+(rate*sum));
}
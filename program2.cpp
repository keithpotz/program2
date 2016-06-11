/*Keith Pottratz
September 14, 2014
 This Program is designed to output hours work taxes and total gross income
 of all employees and categorizing them into Full or Part-time*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void main()
{
	string name;
	int i, hoursw;
	double hourr, gross, tax, net, totaltax = 0, totalhw = 0, totalg = 0,totalnet=0;
	char Emplyt;
	ifstream inf;
	ofstream outf;
	inf.open("program2.dat");
	outf.open("program2.ot");
	outf.setf(ios::fixed);
	outf.precision(2); 
	outf << endl;
	outf << setw(47) << "Employee Pay Table" << endl;
	outf << setw(43) << "Fall, 2014" << endl; outf << endl;
	outf << setw(1) << "Employee" << setw(14) << "Employee" 
		<< setw(10) << "Hours" << setw(11) << "Hourly" << setw(9) << "Gross"
		<< endl;
	outf << setw(5) << "Name" << setw(14) << "Type" << setw(14)
		<< "Worked" << setw(9) << "Rate" << setw(11) << "Salary"
		<< setw(10) << "Taxes" << setw(7) << "Net" << endl;
	for (i = 1; i <= 73; i++) outf << "-";
	outf << endl;
	for (i = 1; i <= 10; i++)
	{
		name = "";
		hourr = 0;
		hoursw = 0;
		inf >> name >> Emplyt >> hourr >> hoursw;
		gross = 0;
		if (hoursw > 40)
		{
			gross = (hoursw - 40)*(hourr*1.5) + (40 * hourr);
		}
		else
		{
			gross = hourr * hoursw;
		}
		if (Emplyt == 'F')
		{
			if (gross < 250)
				tax = 0;
			else if (gross < 400)
				tax = gross * .15;
			else
				tax = gross * .25;
		}
		else {
			if (gross >= 250)
				tax = gross *.2;
			else if (gross >= 125)
				tax = gross *.1;
			else
				tax = 0;
		}
		net = gross - tax;
		totalhw += hoursw;
		totaltax += tax;
		totalnet += net;
		totalg += gross;
		
		outf << setw(15) <<left << name << setw(10) << Emplyt << setw(5) << right << hoursw << setw(12)
			<< hourr << setw(10) << gross << setw(10) << tax << setw(10)  << net << endl;
		}
	for (i = 1; i <= 73; i++) outf << "-";
	outf << endl;
	outf << setw(32) << totalhw <<setw(20) << totalg << setw(10)<< totaltax << setw(11) << totalnet << endl;
	system("pause");
	}
			

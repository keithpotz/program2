/*Keith Pottratz
September 14, 2014
 This Program is designed to output hours work taxes and total gross income
 of all employees and categorizing them into Full or Part-time*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    std::string name;
    int i, hoursw;
    double hourr, gross, tax, net, totaltax = 0, totalhw = 0, totalg = 0, totalnet = 0;
    char Emplyt;

    std::ifstream inf("program2.dat");
    std::ofstream outf("program2.ot");
    outf.setf(std::ios::fixed);
    outf.precision(2);

    outf << std::endl;
    outf << std::setw(47) << "Employee Pay Table" << std::endl;
    outf << std::setw(43) << "Fall, 2014" << std::endl;
    outf << std::endl;
    outf << std::setw(1) << "Employee" << std::setw(14) << "Employee"
         << std::setw(10) << "Hours" << std::setw(11) << "Hourly" << std::setw(9) << "Gross"
         << std::endl;
    outf << std::setw(5) << "Name" << std::setw(14) << "Type" << std::setw(14)
         << "Worked" << std::setw(9) << "Rate" << std::setw(11) << "Salary"
         << std::setw(10) << "Taxes" << std::setw(7) << "Net" << std::endl;
    for (i = 1; i <= 73; i++)
        outf << "-";
    outf << std::endl;

    for (i = 1; i <= 10 && inf >> name >> Emplyt >> hourr >> hoursw; i++)
    {
        gross = (hoursw > 40) ? ((hoursw - 40) * (hourr * 1.5) + (40 * hourr)) : (hourr * hoursw);
        tax = (Emplyt == 'F') ? ((gross < 250) ? 0 : (gross < 400) ? gross * 0.15 : gross * 0.25)
                              : ((gross >= 250) ? gross * 0.2 : (gross >= 125) ? gross * 0.1 : 0);
        net = gross - tax;
        totalhw += hoursw;
        totaltax += tax;
        totalnet += net;
        totalg += gross;

        outf << std::setw(15) << std::left << name << std::setw(10) << Emplyt << std::setw(5) << std::right << hoursw << std::setw(12)
             << hourr << std::setw(10) << gross << std::setw(10) << tax << std::setw(10) << net << std::endl;
    }

    for (i = 1; i <= 73; i++)
        outf << "-";
    outf << std::endl;

    outf << std::setw(32) << totalhw << std::setw(20) << totalg << std::setw(10) << totaltax << std::setw(11) << totalnet << std::endl;

    std::cin.ignore(); // Wait for user input before closing the console window

    return 0;
}

			

//============================================================================
// Name        : Database.cpp
// Author      : TS
// Version     : 1.0
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>

std::string name[100];
std::string id[100];
std::string phone[100];
std::string salary[100];
double salarytemp[100];
int arraycount = 0;
int maxentries = 0;
char cont = 'Y';
int choice;
std::string searchname;

void view()
{
	std::cout << std::left << std::setw(20) << "Username";
	std::cout << std::left << std::setw(20) << "ID";
	std::cout << std::left << std::setw(20) << "Phone";
	std::cout << std::left << std::setw(20) << "Salary" << std::endl;

	for (int i = 0 ; i < maxentries ; i++)
	{
		std::cout << std::left << std::setw(20) << name[i];
		std::cout << std::left << std::setw(20) << id[i];
		std::cout << std::left << std::setw(20) << phone[i];
		std::cout << std::left << std::setw(20) << salary[i] << std::endl;
	}
}

void stats()
{
	for (int i = 0 ; i < maxentries ; i++)
	{
		salarytemp[i] = std::stoi (salary[i]);
	}
	double total = 0;
	double max = salarytemp[0];
	double min = salarytemp[0];

	for (int i = 0 ; i < maxentries ; i++)
	{
		total = total + salarytemp[i];

		if (salarytemp[i] >= max)
		{
			max = salarytemp[i];
		}
		if (salarytemp[i] <= min)
		{
			min = salarytemp[i];
		}
	}
	std::cout << "Salaries:\nAverage: " << total / maxentries << "\nMax: " << max << "\nMin: " << min << std::endl;
}

void sort()
{
	int temp;
	std::string stemp;
	for (int i = 0 ; i < maxentries ; i++)
	{
		salarytemp[i] = std::stoi (salary[i]);
	}
	int i, j;
	for (i = 0; i < maxentries-1; i++)
	{
		for (j = 0; j < maxentries-i-1; j++)
		{
			if (salarytemp[j] > salarytemp[j+1])
	        {
				temp = salarytemp[j + 1];
				salarytemp[j + 1] = salarytemp[j];
				salarytemp[j] = temp;

				stemp = name[j + 1];
				name[j + 1] = name[j];
				name[j] = stemp;

				stemp = id[j + 1];
				id[j + 1] = id[j];
				id[j] = stemp;

				stemp = phone[j + 1];
				phone[j + 1] = phone[j];
				phone[j] = stemp;
	        }
		}
	}
	for (int i = 0 ; i < maxentries ; i++)
	{
		std::stringstream ss;
		ss << salarytemp[i];
		salary [i] = ss.str();
	}
}


void search()
{
	std::cout << "Please enter the username: " << std::endl;
	std::cin >> searchname;

	bool found = 0;

	for (int i = 0 ; i < maxentries ; i++)
	{
		if ( searchname == name[i] )
		{
			std::cout << std::left << std::setw(20) << "Username";
			std::cout << std::left << std::setw(20) << "ID";
			std::cout << std::left << std::setw(20) << "Phone";
			std::cout << std::left << std::setw(20) << "Salary" << std::endl;

			std::cout << std::left << std::setw(20) << name[i];
			std::cout << std::left << std::setw(20) << id[i];
			std::cout << std::left << std::setw(20) << phone[i];
			std::cout << std::left << std::setw(20) << salary[i] << std::endl;

			found = 1;
		}
	}
	if ( found == 0 )
	{
		std::cout << "Entry not found." << std::endl;
	}
}

void entry()
{
	std::cout << "Please enter your username:" << std::endl;
	std::cin >> name[maxentries];
	std::cout << "Please enter your student ID:" << std::endl;
	std::cin >> id[maxentries];
	std::cout << "Please enter your phone number:" << std::endl;
	std::cin >> phone[maxentries];
	std::cout << "Please enter your salary:" << std::endl;
	std::cin >> salary[maxentries];

	maxentries++;
}

void save()
{
	std::ofstream outfile;
	outfile.open ("Database.csv");

	for (int i = 0 ; i < maxentries ; i++)
	{
		outfile << name[i] << "," << id[i] << "," << phone[i] << "," << salary[i] << std::endl;
	}
	outfile.close();
}

void load()
{
	std::ifstream infile;
	infile.open ("Database.csv");
	maxentries = 0;

	while(!infile.eof())
	{
	    getline(infile, name[maxentries], ',');
	    getline(infile, id[maxentries], ',' );
	    getline(infile, phone[maxentries], ',' );
	    getline(infile, salary[maxentries]);

	    maxentries++;
	}
	maxentries--;
	infile.close();
}

int main()
{
	while ( cont == 'Y' )
	{
		std::cout << "Welcome!" << std::endl;
		std::cout << "(1) View Database" << std::endl;
		std::cout << "(2) View Statistics" << std::endl;
		std::cout << "(3) Sort Entries" << std::endl;
		std::cout << "(4) Search Entry" << std::endl;
		std::cout << "(5) New Entry" << std::endl;
		std::cout << "(6) Save" << std::endl;
		std::cout << "(7) Load" << std::endl;
		std::cout << "(0) Exit" << std::endl;
		std::cin >> choice;

			if ( choice == 1 )
			{
				view();
			}
			else if ( choice == 2 )
			{
				stats();
			}
			else if ( choice == 3 )
			{
				sort();
			}
			else if ( choice == 4 )
			{
				search();
			}
			else if ( choice == 5 )
			{
				entry();
			}
			else if ( choice == 6)
			{
				save();
			}
			else if ( choice == 7)
			{
				load();
			}
			else if ( choice == 0)
			{

			}
			else
			{
				std::cout << "Please enter a valid input." << std::endl;
			}
		std::cout << "Continue? (Y/N)" << std::endl;
		std::cin >> cont;
	}
	std::cout << "Thank you for using this database." << std::endl;
}

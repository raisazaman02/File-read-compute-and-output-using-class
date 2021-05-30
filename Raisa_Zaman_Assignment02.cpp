//==========================================================
// Assignment- 02
// Name- Raisa Zaman
// Date- 1/23/2020
// Last edited- 5:00 PM
// Title: File read, compute and output using class
// Description:
//    This C++ console application loads two column of numbers using class, 
//and does arithmetic operations to the data points. 
//
//==========================================================

#include <conio.h> // For function getch()
#include <cstdlib>  // For several general-purpose functions
#include <cmath> //calculate power function
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data
#include <vector>
using namespace std;

//Class
class ONE
{
// Member functions
public:
	void store(double num)
	{
		data.push_back(num);
	}
	vector<double> get()
	{
		return data;
	}
	int getsize()
	{
		return data.size();
	}

// Member Variables
private:
	vector<double> data;
};

// global variables
ONE column1;
ONE column2;
ONE addition;
ONE multiplication;
double add;
double multi;
ofstream outputM;
ifstream datafile;
double data1;
double data2;

// Read Data
void read ()
{
	// Open file 
	datafile.open("Datafile1.data");
	if (!datafile.is_open())
	{
		cout << "Error: File datafile1.data cannot be processed";
	}
	else
	{
		cout << "File datafile1.data successfully opened. " << endl;
		while (datafile >> data1 >> data2) {
			column1.store(data1);
			column2.store(data2);
		}
	}
	// Close file
	datafile.close();
}

// addition operation
void OperationA(ONE &column1, ONE &column2)
{
	for (int i = 0; i < column1.getsize(); i++) 
	{
		add = column1.get().at(i) + column2.get().at(i);
		addition.store(add);
	}

}

// multiplication operation
void OperationM(ONE &column1, ONE &column2)
{
	for (int i = 0; i < column1.getsize(); i++)
	{
		multi = column1.get().at(i) * column2.get().at(i);
		multiplication.store(multi);
	}

}

// write to files 
void write()
{
	// Open file
	outputM.open("Output-MultAdd-class.data");

	if (outputM.is_open())
	{
		cout << "Data successfully transferred to file Output-MultAdd-class.data." << endl;
		outputM << left << setw(20) << "columnOne" << left << setw(20)
			<< "columnTwo" << left << setw(20) << "multiplication" << left << setw(20)
			<< "addition" << endl;
		for (int a = 0; a < column1.getsize(); a++)
		{
			outputM << left << setw(20) << column1.get().at(a) << left << setw(20)
				<< column2.get().at(a) << left << setw(20) << multiplication.get().at(a) << left << setw(20)
				<< addition.get().at(a) << endl;
		}
	}
	else
	{
		cout << "Error: Cannot record data in Output-MultAdd-class.data." << endl;
	}
	// close file
	outputM.close();
}

int main()
{
	// call functions
	read(); 
	OperationA(column1, column2);
	OperationM(column1, column2);
	write(); 

	return 0;

}
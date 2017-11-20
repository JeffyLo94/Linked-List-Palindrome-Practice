/*******************************************************************************
*	AUTHOR	   : Jeffrey Lo
*	STU ID#	   : 374780
*	ASSIGN #1  : Linked List & Palindrome
*	CLASS      : CS1D
*	SECTION    : 6-10p T-Th
*	DUE DATE   : 1/22/2014
*******************************************************************************/

#include "Assignments.h"
/*******************************************************************************
 * FUNCTION OutputHeader
 * ----------------------------------------------------------------------------
 * This function will output the header information to the console
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		Literals are passed as arguments through the parameter list.
 * 		This are given their values in the calling of this function in
 * 		main.
 *
 * 	POST-CONDITIONS
 * 		Since this function is a void function there is no return value.
 * 		However, it does output c-string literals.
 ******************************************************************************/

void OutputHeader(const string NAME,	// Holds the value of the name(s)
				  	  	  	  	  	  	// being output
				  const string CLASS,	// Holds the class
				  const string SECTION, // Holds the time and day of class
				  const int LAB_NUM,    // Holds the lab number
				  const string LAB_NAME,// Holds the lab name
				  char asType,			// Either L(lab), or A(assign)
				  ostream& out)			// Used for output
{
	out << left;
	out << "**************************************************\n";
	out << "* Programmed by : " << NAME << "\n";
	out << "* " << setw(14) << "Student ID" << ": 374780";
	out << "\n* " << setw(14) << CLASS << ": " << SECTION;
	if (toupper(asType) == 'L')
	{
		out << "\n* LAB #" << setw(9);
	}
	else
	{
		out << "\n* ASSIGNMENT #" << setw(2);
	}
	out << LAB_NUM << ": " << LAB_NAME;
	out << "\n**************************************************\n";

}

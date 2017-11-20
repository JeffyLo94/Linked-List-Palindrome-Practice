/*******************************************************************************
*	AUTHOR	   : Jeffrey Lo
*	STU ID#	   : 374780
*	ASSIGN #1  : Linked List & Palindrome
*	CLASS      : CS1D
*	SECTION    : 6-10p T-Th
*	DUE DATE   : 1/22/2014
*******************************************************************************/

#ifndef ASSIGNMENTS_H_
#define ASSIGNMENTS_H_

#include <iomanip>
#include <cstring>
#include <iostream>
#include <limits>
using namespace std;

// N A M E S P A C E
namespace JeffreyLo
{
	// G L O B A L   C O N S T A N T S
	/**************************************************************************
	 * Used for OutputHeader
	 * -----------------------------------------------------------------------
	 * NAME		-	Programmer Name
	 * CLASS	-	Class Name
	 * Section	-	Section Time
	 * AS_NUM	-	Assignment Number
	 * AS_NAME	-	Assignment Name
	 * AS_TYPE	-	Assignment Type
	 **************************************************************************/
	const string NAME 		= "Jeffrey Lo";
	const string CLASS 		= "CS1D";
	const string SECTION	= "T-Th 5:30p - 9:20p";
	const int    AS_NUM 	= 1;
	const string AS_NAME	= "Linked List & Palindrome";
	const char   AS_TYPE	= 'A';
}

// P R O T O T Y P E S
/******************************************************************************
 * FUNCTION OutputHeader
 * ----------------------------------------------------------------------------
 *		This function will output the header information to the console
 ******************************************************************************/
void OutputHeader(const string NAME,	// Holds the value of the name(s)
				  	  	  	  	  	  	// being output
				  const string CLASS,	// Holds the class
				  const string SECTION, // Holds the time and day of class
				  const int LAB_NUM,    // Holds the lab number
				  const string LAB_NAME,// Holds the lab name
				  char asType,			// Either L(lab), or A(assign)
				  ostream& out); 		// Used for output

#endif /* ASSIGNMENTS_H_ */

/*******************************************************************************
*	AUTHOR	   : Jeffrey Lo
*	STU ID#	   : 374780
*	ASSIGN #1  : Linked List & Palindrome
*	CLASS      : CS1D
*	SECTION    : 5-9p T-Th
*	DUE DATE   : 1/22/2014
*******************************************************************************/

#include "Assignments.h"
#include "LinkedDeque.h"
using namespace JeffreyLo;

/*******************************************************************************
 * Linked Deque & Palindrome
 * ----------------------------------------------------------------------------
 * 	This program tests a Deque and a Palindrome checking function. Uses an
 * 	array of 10 words to test.
 * ----------------------------------------------------------------------------
 * Output
 * ----------------------------------------------------------------------------
 * 	Outputs to console:
 * 		-Test Number
 * 		-What the Deque contains
 * 		-Whether or not the word is a palindrome
 ******************************************************************************/

bool isPalindrome(string test);

int main(){

	//CONSTANTS
	const int TEST_CASES = 10;

	// Outputs Header
	OutputHeader(NAME,CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	// words - Array of the test words
	string words[TEST_CASES] = {"dad",
	                            "radar",
	                            "Otto",
	                            "mom",
	                            "tigers",
	                            "A man, a plan, a canal, Panama",
	                            "Isn't this class cool?",
	                            "Was it a car or a cat I saw?",
	                            "Sit on a potato pan, Otis",
	                            "Saddleback is a great place to learn"};

	// Loop performs test, calling the isPalindrome function and passing each
	// word through the function once.
	for(int count = 0; count < TEST_CASES; count++){
		cout << "Test Word #" << count+1 << endl;

		string word = words[count];

		cout << "\"" << word << "\"" << (isPalindrome(word)?
				(" is a Palindrome\n\n"):(" is not a Palindrome\n\n"));
	}

	return 0;
}

/*******************************************************************************
 * FUNCTION isPalindrome
 * ----------------------------------------------------------------------------
 * This function will determine if the string passed in is a palindrome.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		A string is passed in to be tested
 *
 * 	POST-CONDITIONS
 * 		Boolean value for whether or not the word is a palindrome
 * 			-True : word is a palindrome
 * 			-False: word is NOT a palindrome
 ******************************************************************************/

bool isPalindrome(string test){
	bool hasPalindrome = true;
	LinkedDeque<char> lettersQueue;

	//Loop to create Double-ended Queue of letters
	// Thereby ignoring whitespace/extra characters
	for(unsigned int letters = 0; letters < test.length(); letters++){
		if( tolower(test.at(letters)) >= 'a'
		 && tolower(test.at(letters)) <= 'z'){
			lettersQueue.pushBack(test.at(letters));
		}
	}
	cout << "The deque contains: ";
	lettersQueue.print(cout);

	//Loop to compare letter by popping off both ends
	for(int count = 0; count < lettersQueue.size()/2; count++){
		if(tolower(lettersQueue.popFront()) != tolower(lettersQueue.popBack())){
			hasPalindrome = false;
			break;
		}
	}

	return hasPalindrome;
}

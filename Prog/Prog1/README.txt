Project Goal: To create help students (us) get experience and gain undertstanding of implementing the List ADT and using doubly linked 
lists. The project also helps us become reacquainted with C++ after having used Java for the past two programming classes. 

Specifications: Our client file, editor.cpp, contained a list of different variables especially to get the input file. In the int main(),there were two parameters that were used to get the input file. These two parameters were: int argc and char *argv[]. Using argv, the
strings from the input file were stored within it. The variable argc checked to make sure that the user actually entered a filename, and
a check was implemented to catch the user if they did not enter a file name. If argc equaled 1, the program would exit, and they would 
have to start again. The string filename was for the file input that was stored in argv. The input file was called testfile, and it was afile that was changed by the user when they used the command I which created a new line within testfile. The output file will be the filethat is created after using the various options within the program. The output file for testfile will have the saved changes and will notbe opened once it is completed. To get user input, getline was used rather than cin. The userinput from the getline was used to get the
file name, and a while loop was used to check and wait for userinput before comparing the userinput to a condition within an if 
statement.

Outline of OOP Design: This project required the use of the List, string, char, int, and fstream classes. The List class was used for theimplementation files for linelist.cpp, linelist.h, and linelist.o. From there, linelist.h was included as a library in linelist.cpp and
editor.cpp. The List class is a standard template library. String, char, int, and fstream are also standard libraries. The LineList and
LineNode are classes that are being implemented in this program. 

The LineList class has both public functions and private variables. The public functions were many: goToTop(), goToBottom(),
insertLine (string newLine), deleteLine(), printList(), moveNextLine(), movePrevLine(), getCurrLineNum() const, getLength() const, 
getCurrLine() const. The goToTop method sent the program to the top message, the goToBottom sent the program to the bottom message,
insertLine allowed for a new line to be entered, deleteLine deleted the line that you were on, printList, gave a full print out of all
text within the file, moveNextLine incremented the line counter and placed you on the next line, movePrevLine placed you on the line 
before the current one, getCurrLineNum provided the number of the current line, getLength gave the total number of lines within the file,and getCurrLine retrieved the current line.
As for the private variables, there are three: LineNode* currLine, int currLineNum, and int length. There is also a struct LineNode whichhas three variables: string info, LineNode* next, LineNode* back. The string info is what is contained within the array. Next and back
are what allow the main pointer to go back and go to the next slots in the array.

Algorithm: An outline of the editor.cpp file
Libraries:
--Include the necessary libraries at the top of the program, making sure to include any files that will be neccessary

Main method:
--Start main method and include argc and argv as parameters for the main method
--Include a check to make sure that a file has been entered
--Instantiate a linelist variable, a variable for the file, an input file stream variable, open the file, create variables for userinput for the file and just for commands
--Get userinput without cin to get the information from the input file
--*NOTE: This is optional, but you can add a little greeting for a menu to start the program if you so desire
--Start from the top of the file then implement code for the various commands(make sure that outputs are correct along the way)
--*NOTE: Using a loop that will continuously check for userinput will help the program be more efficient
--*NOTE: insertLine takes a little more effort with its lines of code in comparison to the others, so go slowly and make sure this methodworks before moving on to the other methods

Closing the File:
--Since the file was opened, it also must be closed. The same way that the ifstream was instantiated, an ofstream also has to be 
instantiated.
--Use ofstream for variable names
--Go to the top of the file, get current line for all lines
--Close the file

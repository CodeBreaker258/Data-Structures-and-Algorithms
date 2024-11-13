#include <iostream>
#include "linelist.h"

LineList::LineList()
{
	LineNode *line = new LineNode;
	LineNode *line2 = new LineNode;

	line -> info = topMessage;
	currLine = line;
	currLineNum = 0;
	length = 0;
	line2 -> info = bottomMessage;
	currLine -> back = NULL;
	currLine -> next = line2;
	line2 -> back = line;
	line2 -> next = NULL;
}

void LineList::goToTop() 
{
	// Post : Advances currLine to line 1
	while(currLine -> info != topMessage)
		currLine = currLine -> back;
	
	currLine = currLine -> next;	
	currLineNum = 1;
}

void LineList::goToBottom() 
{
	// Post : Advances currLine to last line
	while(currLine -> info != bottomMessage)
		currLine = currLine -> next;
	
	currLine = currLine -> back;
	currLineNum = length;
}

void LineList::insertLine(string newLine)
{
	// post : newLine has been inserted after the current line
	if(currLine -> info == bottomMessage)
		movePrevLine();

	LineNode *line = new LineNode;
	
	line -> info = newLine;
	line -> back = currLine;
	line -> next = currLine -> next;
	
	currLine -> next -> back = line;
	currLine -> next = line;
	currLine = currLine -> next;
	
 	currLineNum++;
	length++;	
	
}

void LineList::deleteLine()
{
	// post : deletes the current line leaving currentLine
	//	  pointing to line following
	
	if((currLine -> info != topMessage) && (currLine -> info != bottomMessage))
	{
    		LineNode *tline = currLine;
    
		currLine -> next -> back = currLine -> back;
		currLine -> back -> next = currLine -> next;

		currLine = currLine -> next;
		
    		delete tline;	
  	
    		if(currLineNum == length)
        		currLineNum--;
    		length--;
           
    
    		if(currLine -> info == topMessage)
        		currLine = currLine -> next;
        
    		if(currLine -> info == bottomMessage)
        		currLine = currLine -> back; 
	}
}
void LineList::printList() 
{
	int increment = 1;

	LineNode *tracker = currLine;
	int trackerNum = currLineNum;

	goToTop();

	LineNode *lines = currLine;

	while(lines -> info != bottomMessage)
	{
		cout << increment << "> " << lines -> info << endl;
		lines = lines -> next;
    		increment++;
	}
	
	currLine = tracker;
	currLineNum = trackerNum;
}

string LineList::getCurrLine() const
{
	return currLine -> info;
}

void LineList::moveNextLine()
{
	// Post : Advances currLine (unless already at last line)
	if((currLine -> next != NULL) && (currLine -> info != bottomMessage))
  	{
		currLine = currLine -> next;	
    		currLineNum++;
  	}
}

void LineList::movePrevLine()
{
	// Post : Advances currLine (unless already at last line)
	if((currLine -> back != NULL) && (currLine -> info != topMessage))
	{	
  		currLine = currLine -> back;
   		currLineNum--;
  	}	
}

int LineList::getCurrLineNum() const
{
	return currLineNum;	
}

int LineList::getLength() const
{
	return length;
}

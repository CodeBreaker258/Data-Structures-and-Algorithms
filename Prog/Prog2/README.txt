Project Goal: 
The goal of this project was to create a calculator that was based on the dc (desk calculator). This calculator used postfix rather than
infix notation to do calculations. The calculator was to be able to perform simple operations such as addition, subtraction, division,
multiplication, and telling the remainder of a division function. Using certain characters, specific functions were carried out on the
stack: p, which printed the value of the top of the stack and did not alter the stack in any way, n, which printed the top value of the
stack and popped that vlaue off but did not print a new line afterwards, f which printed out the entire contents of the stack without 
altering it in any way before adding a newline afterwards, c, which cleared the stack making it empty, d, which duplicated the top value
and pushed another copy of that top value back onto the stack, and r, which reversed the order (or swaps) the top two values on the 
stack.

Specifications:
Multiple variables were used throughout the program. Some were inputs and others were outputs. The inputs consisted of user input like
the string s. The string s was the driving factor in most of the code with char s also being used to help to perform certain methods. 
The string s was used in the getline function that drove the while loop in the main function. The getline waited for user input in the 
string variable before proceeding, and based on the input, other methods would work on interpreting the code. The file stack.h was also
included at the top as an input file. Stack.h incorporated the variables and functions from the stack class, and it allowed for a single
file compilation during testing. The stack that was used, iStack, was another input that was used throughout the file. The stack stored
the values that came from the string that the user gave. The outputs came from a number of places. In regards to the operators, return
statements were used to give the values after carrying out an operation. The two variables that made up the output were num1 and num2, 
two integers. Other outputs were the four error types that were thrown. There was an error for division by zero, data error, overflow, 
and underflow. If any of these were caught, an error would be thrown to the user to let them know. Concatenation was used to remedy the
negative sign. Since negative/minus signs are used for subtraction, an underscore was used to differentiate between the two. From there,
a few lines of code were needed to change the underscore to a negative sign then attach the negative sign with the number that it 
belonged to.

Classes:
While the basic clases were included like int, string, boolean, and char, we also used stack. The file stack.h was included up top with 
our list of libraries. The integer class is used for only integer values be them long or short. They can be used to carry out algebraic
functions like addition, multiplication, subtraction, or division. For string, the string was used for user input, but it was also used
to help form arrays that could be used to get values. This came in handy in regards to parsing because when the string had no spacing,
the code had to be able to separate each part individually. This also came in handy when dealing with negative values. Since the minus
sign, which also signifies a negative, is commonly used for subtraction, an underscore was used to signify a negative number. From there,
the underscore became a minus sign for the negative number, and with concatenation, a negative number was pushed onto the stack. 
The string class also had c_str() which produced a const char that pointed to a null-terminated string. It was helpful when using atoi
for negative numbers.The boolean class was used for methods that determined if an input was valid or not. Chars were parameters in 
methods, and they helped compare parts of a string command with valid input. The stack class was a big part in this project. Values were
stored within the stack, and if an operation was performed, the new value was pushed back into the stack. Values from the top were 
needed and then they would be popped, or they would possibly be swapped.  

Algorithm:
This program was to handle 11 different operations, and it had to handle certain specifications. In the project goal, the 11 different
operations were listed and described. In order to handle all of them, they were originally placed in a singular method; however, it was 
decided for readability purposes, they operations would be separated into two different methods. One method handled the operations 
pertaining to a certain character while the other method dealt with mathematical operations. In the first method, a try-catch was used
to determine if a valid command was used. The try part contained the character operations--p, n, f, c, d, and r--and s was compared to 
each character. If s corresponded to one of the six characters, the specific job was carried out. There was a way to catch an invalid
operation, and if the error occured, the user would get a message telling them so.  
The method that handled the mathematical operations performed addition,subtraction, multiplication, division, and the remainder of a 
mathetical statement. The division function was different from the others because it had an error that needed to be caught. The error
occurred if a number was being divided by zero. There was a way to catch it, and there were ways to catch overflow and underflow within
the stack. 
There was a check to make sure that the string contained digits that were valid, and to check for an underscore because a negative sign
was being used for subtraction. 
The fourth and final method parsed string values that were strung together, and it also checked what the string contained within a few
lines. 
The shortest method between the four was the method that checked for digits with the operator methods being the longer ones along with
the parsing method that had to check for specifics within a string. With the help of classes, the functions and methods within the used 
classes kept everything neater than what it would like without them. 

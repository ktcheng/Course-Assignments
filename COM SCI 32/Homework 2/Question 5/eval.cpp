#include <iostream>
#include <cassert>
#include <stack>

bool isvalid(std::string infix);

int evaluate(std::string infix, std::string& postfix, bool& result)
{
	postfix = ""; // Initialize postfix to the empty string
	std::stack<char> opStack; // Initialize the operator stack

	// If syntactically valid, create the postfix and evaluate
	if (isvalid(infix))
	{
		for (size_t i = 0; i < infix.length(); i++)
		{
			char ch = infix.at(i); // Retrieve current character
			switch (ch)
			{
				case 'T':
				case 'F': // If ch is an operand, append to postfix
					postfix += ch;
					break;
				case '(':
					opStack.push(ch);
					break;
				case ')':
					// Pop until we find (
					while (opStack.top() != '(')
					{
						// Append the top and pop the stack
						char tch = opStack.top();
						postfix += tch;
						opStack.pop();
					}
					opStack.pop(); // Removes ( character
					break;
				case '&':
				case '!':
				case '^':
					// While stack not empty, top != (, and ch not of greater precedence
					while (!(opStack.empty()) && opStack.top() != '(' &&
						(ch >= opStack.top())) // In the ASCII table, ^ > & > !
					{
						// Append the top and pop the stack
						char tch = opStack.top();
						postfix += tch;
						opStack.pop();
					}
					opStack.push(ch);
					break;
			}
		}

		while (!(opStack.empty()))
		{
			// Append the top and pop the stack
			char tch = opStack.top();
			postfix += tch;
			opStack.pop();
		}

		// Evaluate the postfix string
		std::stack<char> oprandStack; // Initialize the operand stack
		for (size_t i = 0; i < postfix.length(); i++)
		{
			char ch = postfix.at(i); // Retrieve current postfix character

			// If operand, push the character onto the operand stack
			if (ch == 'T' || ch == 'F')
			{
				oprandStack.push(ch);
			}
			else
			{
				char op2 = oprandStack.top(); 
				oprandStack.pop();
				char op1 = oprandStack.top();
				oprandStack.pop();

				// Apply the boolean operate and push result to stack
				if (ch == '!')
				{
					// Negate op2, and then push both op1 and op2 onto stack
					if (op2 == 'F')
					{
						char op2 = 'T';
						oprandStack.push(op1); 
						oprandStack.push(op2); 
					}
					else
					{
						char op2 = 'F';
						oprandStack.push(op1);
						oprandStack.push(op2);
					}
				}
				else if (ch == '&')
				{
					char opresult;
					if (op1 == 'T' && op2 == 'T')
					{
						opresult = 'T';
					}
					else
					{
						opresult = 'F';
					}
					oprandStack.push(opresult);
				}
				else if (ch == '^')
				{
					char opresult;
					if (op1 == 'T' && op2 == 'F')
					{
						opresult = 'T';
					}
					else if (op1 == 'F' && op2 == 'T')
					{
						opresult = 'T';
					}
					else
					{
						opresult = 'F';
					}
					oprandStack.push(opresult);
				}
			}
		}

		// Set result from the boolean in oprandStack
		if (oprandStack.top() == 'F')
		{
			result = false;
		}
		else
		{
			result = true;
		}

		return(0); 
	}
	else
	{
		return(1);
	}
}

// Calculates whether the infix is syntactically valid
bool isvalid(std::string infix)
{	
	// If infix is empty string, make invalid, otherwise parse
	if (infix == "")
	{
		return(false);
	}
	else 
	{
		std::string nospace = "";
		int counter = 0;
		
		// Remove whitespace for parsing purposes
		for (size_t i = 0; i < infix.length(); i++)
		{
			if (infix.at(i) != ' ')
			{
				nospace += infix.at(i);
			}
		}

		infix = nospace;
		
		// Ensure string is valid
		for (size_t i = 0; i < infix.length(); i++)
		{
			char c = infix.at(i); // Get current character

			// The first character may not be &, ^, )
			if (i == 0)
			{
				if (c == '&' || c == '^' || c == ')')
				{
					return(false);
				}
			}

			// The last character may not be !, &, ^, (
			if (i == infix.length() - 1)
			{
				if (c == '!' || c == '&' || c == '^' || c == '(')
				{
					return(false);
				}
			}

			// Checks if c and its successor is valid
			switch (c)
			{
				case 'T':
				case 'F':
					// The next character cannot be !, (, T, F
					if (i < infix.length() - 1)
					{
						char nch = infix.at(i + 1);
						switch (nch)
						{
							case '!':
							case '(':
							case 'T':
							case 'F':
								return(false);
								break;
							default: // Else carry on
								break;
						}
					}
					break;
				case '(':
					// The next character cannot be &, ^, )
					if (i < infix.length() - 1)
					{
						char nch = infix.at(i + 1);
						switch (nch)
						{
							case '&':
							case '^':
							case ')':
								return(false);
								break;
							default: // Else carry on
								break;
						}
					}
					counter++;
					break;
				case ')':
					// The next character cannot be !, (, T, F
					if (i < infix.length() - 1)
					{
						char nch = infix.at(i + 1);
						switch (nch)
						{
							case '!':
							case '(':
							case 'T':
							case 'F':
								return(false);
								break;
							default: // Else carry on
								break;
						}
					}
					counter--;
					break;
				case '^':
				case '&':
				case '!':
					// The next character cannot be &, ^, )
					if (i < infix.length() - 1)
					{
						char nch = infix.at(i + 1);
						switch (nch)
						{
						case '&':
						case '^':
						case ')':
							return(false);
							break;
						default: // Else carry on
							break;
						}
					}
					break;
				default: // The character is an invalid one
					return(false);
					break;
			}
		}

		// Ensures parentheses are accounted for
		if (counter != 0)
		{
			return(false);
		}

		return(true);
	}
}

int main()
{
	std::cout << "It builds!" << std::endl;
	std::string pf;
	bool answer;
	std::cout << evaluate("T&(F&T))&((T&T)", pf, answer);
	std::cout << "Passed all tests" << std::endl;
}
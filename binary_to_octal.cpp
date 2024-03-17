/*

Author: Aditya Upadhye

A program to convert a valid binary number given as input to an equivalent octal number using a map.

*/

#include <iostream>
#include <map>


void binary_to_octal(const std::string& n)
{

	std::map<std::string, std::string> bin_to_oct {{"000","0"}, {"001","1"}, {"010","2"}, {"011","3"}, {"100","4"}, {"101","5"}, {"110","6"}, {"111","7"}};


	std::string ans = "";

	int no_of_calls = (n.length() / 3) + (n.length() % 3 == 0? 0 : 1);

	int start_index = 0;

	int remainder = n.length() % 3;

	short count = 0;

	int end_index = 3;

	while (no_of_calls)
	{

		std::string tmp = "";

		end_index = 3;

		if (count == 0)
		{       
			if (remainder == 1)
			{
				tmp = "00";
				end_index = 1;
			}
			else if (remainder == 2)
			{
				tmp = "0";
				end_index = 2;
			}
		}



		tmp = tmp + n.substr(start_index, end_index);
		ans = ans + bin_to_oct[tmp];

		if (count == 0)
		{
			if (remainder == 1)
			{
				start_index += 1;
			}
			else if (remainder == 2)
			{
				start_index += 2;
			}
			else
			{
				start_index += 3;
			}
			count++;

		}

		else
		{
			start_index += 3;
		}

		no_of_calls--;
	        
	}


	std::cout << "\n\nBinary to octal:\n" << ans << std::endl;

}


int main()
{

	std::cout << "Enter the binary number: " << std::endl;
	std::string user_input;
	std::cin >> user_input;


	binary_to_octal(user_input);

	return 0;

}

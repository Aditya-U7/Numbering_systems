/*

Author: Aditya Upadhye

A program to convert a valid binary number given as input to an equivalent hexadecimal number using a map.

*/

#include <iostream>
#include <map>


void binary_to_hex(std::string n)
{

	std::map<std::string, std::string> bin_to_hex {{"0000","0"}, {"0001","1"}, {"0010","2"}, {"0011","3"}, 
	                                               {"0100","4"}, {"0101","5"}, {"0110","6"}, {"0111","7"},
                                                       {"1000","8"}, {"1001","9"}, {"1010","A"}, {"1011","B"},   
                                                       {"1100","C"}, {"1101","D"}, {"1110","E"}, {"1111","F"}};  
	std::string ans = "";

	int no_of_calls = (n.length() / 4) + (n.length() % 4 == 0? 0 : 1);

	int start_index = 0;

	int remainder = n.length() % 4;

	short count = 0;

	int end_index = 4;

	while (no_of_calls)
	{

		std::string tmp = "";

		end_index = 4;

		if (count == 0)
		{       
			if (remainder == 1)
			{
				tmp = "000";
				end_index = 1;
			}
			else if (remainder == 2)
			{
				tmp = "00";
				end_index = 2;
			}
			else if (remainder == 3)
			{
			        tmp = "0";
			        end_index = 3; 
			
			}
		}



		tmp = tmp + n.substr(start_index, end_index);
		ans = ans + bin_to_hex[tmp];

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
			else if (remainder == 3)
			{
				start_index += 3;
			}
			else
			{
			        start_index = 4;
			}
			count++;

		}

		else
		{
			start_index += 4;
		}

		no_of_calls--;
	        
	}


	std::cout << "\n\nBinary to Hexadecimal:\n" << ans << std::endl;

}


int main()
{

	std::cout << "Enter the binary number: " << std::endl;
	std::string user_input;
	std::cin >> user_input;


	binary_to_hex(user_input);

	return 0;

}

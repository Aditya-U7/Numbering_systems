/*

Author: Aditya Upadhye

A program to convert a valid octal number given as input to an equivalent hexadecimal number. It works by first converting the octal number to binary and then maps the binary number to hexadecimal.

*/


#include <iostream>
#include <map>


std::string octal_to_binary(const std::string& bin_num)
{

	std::map<std::string, std::string> oct_to_bin {{"0", "000"}, {"1", "001"}, {"2", "010"},
		                                       {"3", "011"}, {"4", "100"}, {"5", "101"},
		                                       {"6", "110"}, {"7", "111"}};

	int length = bin_num.length();
	int cur_pos = 0;
	bool first_iteration = true;

	std::string oct_num = "";
	std::string str = "";

	while (length)
	{


		str = bin_num.substr(cur_pos, 1); 
		str = oct_to_bin[str];
		cur_pos++;

		if (first_iteration)
		{
			if (str == "000")
			{
				if (length == 1)
					oct_num = "0";

			}
			else
			{
				first_iteration = false;

				if (str == "001")
					oct_num = str.substr(2, 1);
				else if (str == "010" || str == "011") 
					oct_num = str.substr(1, 2);
				else
					oct_num = str;	
			}


		}
		else
		{

			oct_num += str;
		}

		--length;

	}

	return oct_num;
}


std::string binary_to_hex(const std::string& bin_num)
{

	std::map<std::string, std::string> bin_to_hex {{"0000", "0"}, {"0001", "1"}, {"0010", "2"}, {"0011", "3"}, 
		                                       {"0100", "4"}, {"0101", "5"}, {"0110", "6"}, {"0111", "7"},
		                                       {"1000", "8"}, {"1001", "9"}, {"1010", "A"}, {"1011", "B"},   
		                                       {"1100", "C"}, {"1101", "D"}, {"1110", "E"}, {"1111", "F"}};  
	std::string hex_num = "";

	int no_of_calls = (bin_num.length() / 4) + (bin_num.length() % 4 == 0? 0 : 1);

	int start_index = 0;

	int remainder = bin_num.length() % 4;

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



		tmp = tmp + bin_num.substr(start_index, end_index);
		hex_num = hex_num + bin_to_hex[tmp];

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


	return hex_num;
}


std::string octal_to_hex(const std::string& oct_num)
{

	return binary_to_hex(octal_to_binary(oct_num));

}


int main()
{


	std::cout << "Enter the octal number: " << std::endl;
	std::string user_input;
	std::cin >> user_input;

	std::cout << "Hexadecimal number is: \n" << octal_to_hex(user_input) << std::endl;

	return 0;

}

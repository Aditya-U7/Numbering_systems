/*

Author: Aditya Upadhye

A program to convert a valid hexadecimal number given as input to an equivalent octal number. It works by first converting the hexadecimal number to binary and then maps the binary number to octal.

*/


#include <iostream>
#include <map>


std::string binary_to_octal(const std::string& bin_num)
{

	std::map<std::string, std::string> bin_to_oct {{"000", "0"}, {"001", "1"}, {"010", "2"}, 
	                                               {"011", "3"}, {"100", "4"}, {"101", "5"}, 
	                                               {"110", "6"}, {"111", "7"}};


	std::string oct_num = "";

	int no_of_calls = (bin_num.length() / 3) + (bin_num.length() % 3 == 0? 0 : 1);

	int start_index = 0;

	int remainder = bin_num.length() % 3;

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



		tmp = tmp + bin_num.substr(start_index, end_index);
		oct_num = oct_num + bin_to_oct[tmp];

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

        return oct_num; 
}


std::string hex_to_binary(const std::string& hex_num)
{

	std::map<std::string, std::string> hex_to_bin {{"0", "0000"}, {"1", "0001"}, {"2", "0010"}, {"3", "0011"}, 
	                                               {"4", "0100"}, {"5", "0101"}, {"6", "0110"}, {"7", "0111"},
		                                       {"8", "1000"}, {"9", "1001"}, {"A", "1010"}, {"B", "1011"},
		                                       {"C", "1100"}, {"D", "1101"}, {"E", "1110"}, {"F", "1111"}};
		                                       

	int length = hex_num.length();
	int cur_pos = 0;
	bool first_iteration = true;

	std::string bin_num = "";
	std::string str = "";

	while (length)
	{


		str = hex_num.substr(cur_pos, 1); 
		str = hex_to_bin[str];
		cur_pos++;

		if (first_iteration)
		{
			if (str == "0000")
			{
				if (length == 1)
					bin_num = "0";

			}
			else
			{
				first_iteration = false;

				if (str == "0001")
					bin_num = str.substr(3, 1);
				else if (str == "0010" || str == "0011") 
					bin_num = str.substr(2, 2);
				else if (str == "0100" || str == "0101" || str == "0110" || str == "0111")
					bin_num = str.substr(1,3); 
				else
					bin_num = str;	
			}


		}
		else
		{

			bin_num += str;
		}

		--length;

	}

	return bin_num; 
}


std::string hex_to_octal(const std::string& hex_num)
{

	return binary_to_octal(hex_to_binary(hex_num));

}


int main()
{


	std::cout << "Enter the hexadecimal number: " << std::endl;
	std::string user_input;
	std::cin >> user_input;

	std::cout << "Octal number is: \n" <<  hex_to_octal(user_input) << std::endl;

	return 0;

}

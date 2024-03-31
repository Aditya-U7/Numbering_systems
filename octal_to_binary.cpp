/*

Author: Aditya Upadhye

A program to convert a valid octal number given as input to an equivalent binary number using a map.

*/


#include <iostream>
#include <map>


std::string octal_to_binary(const std::string& oct_num)
{

	std::map<std::string, std::string> oct_to_bin {{"0", "000"}, {"1", "001"}, {"2", "010"},
		                                       {"3", "011"}, {"4", "100"}, {"5", "101"},
	 	                                       {"6", "110"}, {"7", "111"}};

	int length = oct_num.length();
	int cur_pos = 0;
	bool first_iteration = true;

	std::string bin_num = "";
	std::string str = "";

	while (length)
	{


		str = oct_num.substr(cur_pos, 1); 
		str = oct_to_bin[str];
		cur_pos++;

		if (first_iteration)
		{
			if (str == "000")
			{
				if (length == 1)
					bin_num = "0";

			}
			else
			{
				first_iteration = false;

				if (str == "001")
					bin_num = str.substr(2, 1);
				else if (str == "010" || str == "011") 
					bin_num = str.substr(1, 2);
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


int main()
{


	std::cout << "Enter the octal number: " << std::endl;
	std::string user_input;
	std::cin >> user_input;

	std::cout << "\nTo Binary:  " << octal_to_binary(user_input) << "\n\n";

	return 0;
}

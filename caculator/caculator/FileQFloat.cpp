#include "pch.h"
#include "FileQFloat.h"


string stringProcessing_Qfloat(bool& decToBin, string line)
{
	bool check_first_space = true; // kiểm tra khoảng trống trong chuỗi
	string result;
	string first_number;
	string second_number;

	if (line != "")
	{
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == ' ')
				if (check_first_space)// nếu đây là khoảng trống đầu tiên
				{
					first_number = line.substr(0, i);
					check_first_space = false;
				}
				else // khoảng trống thứ 2
				{
					result = line.substr(i + 1); // lấy ra chuỗi cần chuyển
					break;
				}
		}
	}

	// xác định chuyển từ hệ nào sang hệ nào
	if (first_number == "10")
	{
		decToBin = true;
	}
	else
	{
		decToBin = false;
	}
	return result;
}

bool Print_To_File(string line, string File_name)
{
	ofstream file;
	file.open(File_name, ios::app);
	if (file.is_open())
	{
		file << line << endl;
		file.close();
		return 1;
	}
	else
	{
		return 0;
	}
}

bool File_Processing(string FileInput_Name, string FileOutput_Name)
{
	ifstream file_input;
	file_input.open(FileInput_Name, ios::beg); // đọc từ đầu file
	string line;
	bool DecToBin;
	string number;
	if (file_input.is_open())
	{

		while (!file_input.eof())
		{
			getline(file_input, line);
			if (line != "")
			{
				number = stringProcessing_Qfloat(DecToBin, line); // lấy được chuỗi cần chuyển và xác định chuyển từ hệ nào sang hệ nào
				cout << "so la: " << number << endl;
				if (DecToBin) // chuyển từ 10 sang 2
				{
					//Qfloat Qf(stof(number)); // chuyển từ 10 sang 2
					Qfloat Qf;
					Qf.ScanQfloat(number); // chuyển từ hệ 10 sang hệ 2
					string bit = Qf.viewDataInBit(); // lấy dãy bit ra
					deleteSpace(bit);
					Print_To_File(bit, FileOutput_Name);// in ra file
				}
				else
				{
					Qfloat Qf;
					string num = Qf.ConvertBinToDec(number); // chuyển từ 2  sang 10
					Print_To_File(num, FileOutput_Name); // in ra file
				}

			}
		}
		return true;


	}
	return false;
}

/*bool test_File_Processing(string FileInput_Name, string FileOutput_Name)
{
	ifstream file_input;
	file_input.open(FileInput_Name, ios::beg);
	string line;
	bool DecToBin;
	string number;
	if (file_input.is_open())
	{
		while (!file_input.eof())
		{
			getline(file_input, line);
			if (line != "")
			{
				number = stringProcessing_Qfloat(DecToBin, line);
				cout << "so la: " << number << endl;
				Print_To_File(number, FileOutput_Name);
				if (DecToBin)
				{
					Qfloat Qf(stof(number));
					string bit = Qf.viewDataInBit();
					Print_To_File(bit, FileOutput_Name);
				}
				else
				{
					Qfloat Qf;
					string num = Qf.ConvertBinToDec(number);
					Print_To_File(num, FileOutput_Name);
				}

			}
		}

	}
	return true;
}*/

string convert_1_string_qfloat(string line)
{
	string result;
	string number;
	bool DecToBin;
	number = stringProcessing_Qfloat(DecToBin, line); // lấy chuỗi số cần chuyển đổi và xác định dạng cần chuyển 
	//cout << "so la: " << number << endl;
	if (DecToBin)
	{
		Qfloat Qf(stof(number));
		string bit = Qf.viewDataInBit();
		//deleteSpace(bit);
		return bit;
	}
	else
	{
		Qfloat Qf;
		string num = Qf.ConvertBinToDec(number);
		return num;
	}

}

void deleteSpace(string& bitData)
{
	bitData.erase(1, 1);
	bitData.erase(16, 1);
}
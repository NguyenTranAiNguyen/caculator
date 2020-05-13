#include "pch.h"
#include "FileQInt.h"

std::string scanQIntQues(string strQues)
{
	string str1, str2, str3, str4, temp;
	string result;

	std::stringstream sstr;
	sstr << strQues;
	sstr >> str1 >> str2 >> str3;
	//return strQues;
	if (isOperator(str3))
	{
		sstr >> str4;
	}
	else
	{
		str4 = "";
	}
	
	if (str4 == "")
	{
		result = Processing(str1, str2, str3);
	}
	else
	{
		result = Processing(str1, str2, str3, str4);
	}

	result = rejectUnecessary0(result);//loai bo cac so 0 thua o dau chuoi

	return result;
}

string Convert(string str1, string str2, string str3)
{

	string strResult = "";

	//xet cac truong hop chuyen doi
	if (str1 == "2")
	{
		QInt intResult(str3, 2);
		std::cout << "|" << std::endl;
		if (str2 == "10")
		{
			strResult = intResult.viewDataInDec();
		}
		else if (str2 == "16")
		{
			strResult = QInt::BinToHex(intResult.DecToBin());
		}
		else
		{
			strResult = "error";
		}
	}
	else if (str1 == "10")
	{
		QInt intResult(str3, 10);
		if (str2 == "2")
		{
			strResult = intResult.viewDataInBit();
			//xoa bo cac khoang trang trong ham viewInBit
			for (int i = 0; i < strResult.length(); i++)
			{
				if (strResult[i] == ' ')
				{
					strResult.erase(strResult.begin() + i);
					i--;
				}
			}
		}
		else if (str2 == "16")
		{
			strResult = QInt::DecToHex(intResult);
		}
		else
		{
			strResult = "error";
		}
	}
	else if (str1 == "16")
	{
		QInt intResult(str3, 16);
		if (str2 == "2")
		{
			strResult = intResult.viewDataInBit();
			//xoa bo cac khoang trang trong ham viewInBit
			for (int i = 0; i < strResult.length(); i++)
			{
				if (strResult[i] == ' ')
				{
					strResult.erase(strResult.begin() + i);
					i--;
				}
			}
		}
		else if (str2 == "10")
		{
			strResult = intResult.viewDataInDec();
		}
		else
		{
			strResult = "error";
		}
	}
	else
	{
		strResult = "error";
	}
	return strResult;
}

string Calculate(string str1, string str2, string str3, string str4)
{
	string strResult = "";
	int n = 0;
	QInt intResult;
	QInt number1, number2;

	//dua chuoi can tinh toan vao QInt
	if (str1 == "2")
	{
		number1 = QInt::BinToDec(str2);
		number2 = QInt::BinToDec(str4);
	}
	else if (str1 == "10")
	{
		number1.convertStringNumber(str2);
		number2.convertStringNumber(str4);
	}
	else if (str1 == "16")
	{
		number1 = QInt::HexToDec(str2);
		number2 = QInt::HexToDec(str4);
	}
	else
	{
		strResult = "error";
	}



	//thuc hien cac phep tinh toan
	if (str3 == "+")
	{
		intResult = number1 + number2;
	}
	else if (str3 == "-")
	{
		intResult = number1 - number2;
	}
	else if (str3 == "*")
	{
		intResult = number1 * number2;
	}
	else if (str3 == "/")
	{
		intResult = number1 / number2;
	}
	else if (str3 == "%")
	{
		intResult = number1 % number2;
	}
	else if (str3 == "+=")
	{
		number1 += number2;
		intResult = number1;
	}
	else if (str3 == "-=")
	{
		number1 -= number2;
		intResult = number1;
	}
	else if (str3 == "*=")
	{
		number1 *= number2;
		intResult = number1;
	}
	else if (str3 == "/=")
	{
		number1 /= number2;
		intResult = number1;
	}
	else if (str3 == ">")
	{
		if (number1 > number2)
		{
			strResult = "true";
		}
		else
		{
			strResult = "false";
		}
	}
	else if (str3 == "<")
	{
		if (number1 < number2)
		{
			strResult = "true";
		}
		else
		{
			strResult = "false";
		}
	}
	else if (str3 == "==")
	{
		if (number1 == number2)
		{
			strResult = "true";
		}
		else
		{
			strResult = "false";
		}
	}
	else if (str3 == "!=")
	{
		if (number1 != number2)
		{
			strResult = "true";
		}
		else
		{
			strResult = "false";
		}
	}
	else if (str3 == ">=")
	{
		if (number1 >= number2)
		{
			strResult = "true";
		}
		else
		{
			strResult = "false";
		}
	}
	else if (str3 == "<=")
	{
		if (number1 <= number2)
		{
			strResult = "true";
		}
		else
		{
			strResult = "false";
		}
	}
	else if (str3 == ">>")
	{
		n = stoi(str4);
		number1 = number1 >> n;
		intResult = number1;
	}
	else if (str3 == "<<")
	{
		n = stoi(str4);
		number1 = number1 << n;
		intResult = number1;
	}
	else if (str3 == "ror")
	{
		n = stoi(str4);
		number1 = number1.ror(n);
		intResult = number1;
	}
	else if (str3 == "rol")
	{
		n = stoi(str4);
		number1 = number1.rol(n);
		intResult = number1;
	}
	else if (str3 == "&")
	{
		intResult = number1 & number2;
	}
	else if (str3 == "|")
	{
		intResult = number1 | number2;
	}
	else if (str3 == "^")
	{
		intResult = number1 ^ number2;
	}
	else
	{
		strResult = "error";
	}

	if (strResult == "")
	{
		if (str1 == "2")
		{
			strResult = intResult.viewDataInBit();
			//loai bo cac khoang trang thua trong viewDataInBit
			for (int i = 0; i < strResult.length(); i++)
			{
				if (strResult[i] == ' ')
				{
					strResult.erase(strResult.begin() + i);
					i--;
				}
			}
		}
		else if (str1 == "10")
		{
			strResult = intResult.viewDataInDec();
		}
		else if (str1 == "16")
		{
			strResult = QInt::DecToHex(intResult);
		}
		else
		{
			strResult = "error";
		}
	}

	return strResult;
}

bool isOperator(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] < '0' || str[i]>'9'))
		{
			return true;
		}
	}

	return false;
}

string rejectUnecessary0(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0')
		{
			str.erase(str.begin() + i);
			i--;
		}
		else
		{
			return str;
		}
	}
	return str;
}

string Processing(string str1, string str2, string str3)
{
	if (str1 == str2)
	{
		return str3;
	}
	string result;
	if (str2 == "~")//xu ly rieng truong hop ~
	{
		if (str1 == "2")
		{
			QInt intResult(str3, 2);
			intResult = ~intResult;
			result = intResult.viewDataInBit();
			//loai bo cac dau khoang trang trong ham viewDataInBit
			for (int i = 0; i < result.length(); i++)
			{
				if (result[i] == ' ')
				{
					result.erase(result.begin() + i);
					i--;
				}
			}
		}
		else if (str1 == "10")
		{
			QInt intResult(str3, 10);
			intResult = ~intResult;
			result = intResult.viewDataInDec();
		}
		else if (str1 == "16")
		{
			QInt intResult(str3, 16);
			intResult = ~intResult;
			result = QInt::DecToHex(intResult);
		}
	}
	else
	{
		result = Convert(str1, str2, str3);
	}
	return result;
}

string Processing(string str1, string str2, string str3, string str4)
{
	string result = Calculate(str1, str2, str3, str4);
	return result;
}
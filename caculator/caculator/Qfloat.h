#pragma once

#include "QIntClass.h"
#include "FileQFloat.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;



class Qfloat
{
	int data[4];
public:

	Qfloat();
	Qfloat(float number);
	Qfloat(string stringFloat);
	void ScanQfloat(string stringfloat);
	bool setBit(unsigned char k, bool value);
	char getBit(unsigned char k = 0);
	static string convertIntToBinNotComplement(string number);
	string convertToStandardString(string str);
	bool isValidStringInput(string str);
	string strUppercase(string str);
	static string ConvertBeforePointToBinary(string beforePoint);
	static string ConvertAfterPointToBinary(string afterPoint, string binOfBeforePoint, bool sign);
	static bool ConditionToStop(string stringNumber, string originalString);
	static string stringMultiplyBy2(std::string number);
	string viewDataInBit();
	string ConvertExponentToBinary(string beforePoint);

	Qfloat& operator=(const Qfloat number);

	friend ostream& operator<<(ostream& os, Qfloat& number);
	friend istream& operator>>(istream& is, Qfloat& number);

	string ConvertBeforePointToDec(string& bit); // chuyển phần trước dấu chấm động về hệ 10

	static string MultyWith2(string& bigNum); // nhân phần trước dấu chấm động với 2

	string pow2(int index); // hàm mũ (2^n)

	string AddBeforePoint(string& FirstNum, string  secondNum); // cộng phần phía trước dấu chấm động

	int Min(int a, int b); // tìm Min

	string Divide2AfterPoint(string& bit);  // chia phần thập phân cho 2 

	string AddAfterPoint(string& FirtNum, string secondNum); // cộng phần thập phân

	string ConvertAfterPointToDec(string& bit);// chuyển phần phía sau dấu chấm động về hệ 10

	string ConvertBinToDec(string& bit); // chuyển từ hệ 2 sang hệ 10

	bool standardizedBitSequence(string significant, string& realPart, string& decimalPart, int exponent); // chuyen chuoi signnificant ve dang real.decimal

	bool isMaxExponent(string exponent); // xem co phai exponent toàn bit 1

	bool isInfinity(string significant); // xem có rơi vào trường hợp vô cùng không

	bool check_Largest_positive_denormalized_number(string significand); // kiem tra xem day có phải là số không thể chuẩn hóa được lớn nhất không

	bool check_Smallest_positive_denormalized_number(string significand); // kiem tra xem day có phải là số không thể chuẩn hóa được nhỏ nhất không

	bool isDotExisted(string num, int& pos); // xem chuoi nhap vao co dau cham dong hay khong

	void standardized_short_bit(string& bit); // chuẩn hóa lại nếu chuỗi nhập vào ít hơn 128 bit và k có dấu chấm

	void standardized_long_bit(string& bit); // chuẩn hóa lại nếu chuỗi nhập vào nhiều hơn 128 bit và không có dấu chấm

	void PrintQfloat(); // in ra màn hình

	bool* DecToBin(Qfloat x); // chuyển từ hệ 10 sang hệ 2
	//bool test_standardizedBitSequence(string significant, string & realPart, string & decimalPart, int exponent);
};


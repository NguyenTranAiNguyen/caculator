#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <math.h>

class QInt
{
private:
	int data[4];
public:
	QInt();
	QInt(int number);	// always in base 10
	QInt(std::string number, short base);	// base in [2,10,16]
	~QInt();

	static std::string stringDevideBy2(std::string number);

	bool convertStringNumber(std::string number);
	std::string viewDataInBit();
	bool BinarySigned2sComplement();

	char getBit(unsigned char k = 0);
	bool setBit(unsigned char pos, bool value); 	// true == 1 ; false == 0
	bool setHex(unsigned char pos, char value);	// pos is from 0 -> 32 and value is from 0->F

	QInt& operator=(const int& number);
	QInt& operator=(const std::string& number);


	QInt& operator=(const QInt& number);
	QInt operator+(const QInt& number);
	QInt operator-(const QInt& number);
	QInt operator*(const QInt& number);
	QInt operator/(const QInt& number);
	QInt operator%(const QInt& number);

	QInt& operator+=(const QInt& number);
	QInt& operator-=(const QInt& number);
	QInt& operator*=(const QInt& number);
	QInt& operator/=(const QInt& number);

	bool operator>(const QInt& number);
	bool operator<(const QInt& number);
	bool operator==(const QInt& number);
	bool operator!=(const QInt& number);
	bool operator>=(const QInt& number);
	bool operator<=(const QInt& number);

	QInt& operator++(); 	// ++x
	QInt operator++(int x);	// x++
	QInt& operator--(); 	// --x
	QInt operator--(int x);	// x--

	void shiftRightOne();
	QInt operator>>(int n);
	void shiftLeftOne();
	QInt operator<<(int n);

	QInt rol(int n);
	QInt ror(int n);

	QInt operator&(const QInt& number);
	QInt operator|(const QInt& number);
	QInt operator^(const QInt& number);
	QInt operator~();

	int operator&(int number);
	int operator|(int number);
	int operator^(int number);

	friend std::ostream& operator<<(std::ostream& os, QInt& number);
	friend std::istream& operator>>(std::istream& is, QInt& number);


	void ScanQInt();
	void PrintQInt();

	bool* DecToBin();
	// Hàm chuyển đổi dãy bit sang số hệ 16
	// Tham số:
	//		bits: số QInt dạng nhị phân
	// Trả về: số QInt hệ cơ số 16 tương ứng
	static std::string BinToHex(bool* bits);

	// Hàm chuyển đổi số QInt hệ 10 sang hệ 16
	// Tham số:
	//	num: số nguyên QInt
	// Trả về chuỗi số hệ 16 tương ứng
	static std::string DecToHex(QInt& num);
	static QInt BinToDec(const std::string& bitStr);
	static QInt HexToDec(std::string hexStr);

	QInt abs();
	bool isNegative();
	bool hasBitZero();
	bool justHasBitIs(short pos, bool bit);

	static std::string StrPlus1(const std::string& str);
	static std::string mul2(const std::string& number);
	static std::string powWithN(const std::string& number, short n);
	static std::string StrNumPlusStrNum(const std::string& number1, const std::string& number2);

	std::string viewDataInDec();
};





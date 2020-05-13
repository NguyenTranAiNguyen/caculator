#include "pch.h"
#include "QIntClass.h"

QInt::QInt() {
	for (char i = 0; i < 4; ++i)
	{
		this->data[i] = 0;
	}
}
QInt::QInt(int number) {
	this->convertStringNumber(std::to_string(number));
}
QInt::QInt(std::string number, short base) {
	// validityOfInputBase(base);
	// validityOfInputNumber(number, base);

	switch (base)
	{
	case 2:
		*this = QInt::BinToDec(number);
		break;
	case 10:
		this->convertStringNumber(number);
		break;
	case 16:
		*this = QInt::HexToDec(number);
		break;
	default:
		break;
	}
}
QInt::~QInt() {

}


std::string QInt::stringDevideBy2(std::string number) {
	std::string strTemp = "";
	char integer = 0;

	// kiểm tra là chuỗi rỗng
	if (number.length() == 0)
	{
		return std::string("0");
	}

	// chuyển chuỗi thành dạng 0x nếu là số từ 0 -> 9
	if (number.length() == 1) number = "0" + number;

	// chia 2
	for (int i = 0; i < number.length() - 1; ++i)
	{
		integer = std::stoi(number.substr(i, 2));		// lấy từng đôi một số trong chuỗi
		strTemp.append(std::to_string(integer / 2));	// chia 2 lấy nguyên và thêm vào chuỗi kết quả
		number[i + 1] = '0' + (integer & 1);			// lấy nguyên còn lại sau khi chia từng phần
	}

	return strTemp;
}

bool QInt::convertStringNumber(std::string number) {
	for (int i = 0; i < 4; ++i)
	{
		this->data[i] = 0;
	}

	// kiểm tra số âm
	bool negativeNum = false;
	if (number[0] == '-')
	{
		number[0] = '0';
		negativeNum = true;
	}

	// set bit
	char k = 127;
	while (number != "0" && k >= 0) {
		this->setBit(k, (number[number.length() - 1] - '0') & 1);
		k--;
		number = QInt::stringDevideBy2(number);
	}

	// chuyển về dạng bù 2 nếu là số âm
	if (negativeNum)
	{
		this->BinarySigned2sComplement();
	}

	return true;
}



std::string QInt::viewDataInBit() {
	std::string strBit;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 32; ++j)
		{
			if (j % 4 == 0)
			{
				strBit += " ";
			}
			strBit += std::to_string(this->getBit(i * 32 + j));
		}
		strBit += " ";
	}

	return (strBit);
}

bool QInt::BinarySigned2sComplement() {

	for (int i = 0; i < 4; ++i)
	{
		this->data[i] = ~this->data[i];
	}

	QInt one(1);
	*this = *this + one;

	return true;
}

char QInt::getBit(unsigned char k) {
	if (k < 0 || k > 127)
	{
		return -1;
	}

	int temp = this->data[k / 32];

	return (temp >> (31 - (k % 32))) & 1;
}

bool QInt::setBit(unsigned char k, bool value) {
	if (k < 0 || k > 127)
	{
		return false;
	}

	if (value)	// set bit 1
	{
		this->data[k / 32] = this->data[k / 32] | (1 << (31 - (k % 32)));
	}
	else		// set bit 0
	{
		this->data[k / 32] = this->data[k / 32] & (~(1 << (31 - (k % 32))));
	}

	return true;
}
bool QInt::setHex(unsigned char pos, char value) {
	std::string _4bitStr;
	switch (value)
	{
	case '0':
		_4bitStr = "0000";
		break;
	case '1':
		_4bitStr = "0001";
		break;
	case '2':
		_4bitStr = "0010";
		break;
	case '3':
		_4bitStr = "0011";
		break;
	case '4':
		_4bitStr = "0100";
		break;
	case '5':
		_4bitStr = "0101";
		break;
	case '6':
		_4bitStr = "0110";
		break;
	case '7':
		_4bitStr = "0111";
		break;
	case '8':
		_4bitStr = "1000";
		break;
	case '9':
		_4bitStr = "1001";
		break;
	case 'A':
	case 'a':
		_4bitStr = "1010";
		break;
	case 'B':
	case 'b':
		_4bitStr = "1011";
		break;
	case 'C':
	case 'c':
		_4bitStr = "1100";
		break;
	case 'D':
	case 'd':
		_4bitStr = "1101";
		break;
	case 'E':
	case 'e':
		_4bitStr = "1110";
		break;
	case 'F':
	case 'f':
		_4bitStr = "1111";
		break;

	default:
		return false;
		break;
	}
	// pos: 0->32
	// check!!!
	for (int i = 0; i < 4; ++i)
	{
		this->setBit(4 * pos + i, (_4bitStr[i]) - '0');
	}

	return true;
}

QInt& QInt::operator=(const int& number) {	// for base 10
	*this = QInt(number);
	return *this;
}
QInt& QInt::operator=(const std::string& number) {	// for base 10
	*this = QInt(number, 10);
	return *this;
}
QInt& QInt::operator=(const QInt& number) {
	for (char i = 0; i < 4; ++i)
	{
		this->data[i] = number.data[i];
	}

	return *this;
}

QInt QInt::operator+(const QInt& number) {
	QInt numberRes;
	QInt temp = number;

	char resRemember = 0;
	char rememberBit = 0;

	for (int i = 127; i >= 0; i--)
	{
		resRemember = this->getBit(i) + temp.getBit(i) + rememberBit;

		numberRes.setBit(i, resRemember & 1);

		if (resRemember > 1) rememberBit = 1;
		else rememberBit = 0;
	}

	return numberRes;
}

QInt QInt::operator-(const QInt& number) {
	QInt temp = number;
	temp.BinarySigned2sComplement();
	return (*this + temp);
}

QInt QInt::operator*(const QInt& number) {
	QInt numberQ = *this;
	QInt numberA(0);
	int bitQ1 = 0;
	char k = 127;

	while (k >= 0) {
		if ((numberQ & 1) ^ bitQ1)	// get bit cuoi xor voi Q-1
		{
			// bit cuoi khac bit Q-1
			if (bitQ1 == 1)	// case: 0-1
			{
				numberA += number;
			}
			else			// case: 1-0
			{
				numberA -= number;
			}
		}

		bitQ1 = numberQ & 1;
		numberQ = numberQ >> 1;
		numberQ.setBit(0, numberA & 1);
		numberA = numberA >> 1;
		k--;
	}

	return numberQ;
}

QInt QInt::operator/(const QInt& number) {	// Q (*this) / M (- number)

	// QInt numberQ = *this;
	// QInt numberA;
	// QInt numberM = number;

	// if (numberQ.isNegative())	//	1 -> newgative | 0 -> positive 
	// {
	// 	numberA = QInt(-1);	// 111111....11111
	// }


	// char k = 127;

	// while(k >= 0){

	// 	// shift
	// 	numberA = numberA << 1;
	// 	numberA.setBit(127, numberQ.getBit(0));
	// 	numberQ = numberQ << 1;

	// 	numberA -= numberM;

	// 	if (numberA.getBit(0))	//	1 -> newgative | 0 -> positive
	// 	{
	// 		numberA += numberM;
	// 	}
	// 	else numberQ.setBit(127, 1);

	// 	k--;
	// }


	// ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	QInt numberQ = *this;
	QInt numberA;
	QInt numberM = number;

	// if (numberQ.isNegative())	//	1 -> newgative | 0 -> positive 
	// {
	// 	numberA = QInt(-1);	// 111111....11111
	// }
	bool signOfRes = 0; 	//	1 -> newgative | 0 -> positive 
	if (numberQ.isNegative() ^ numberM.isNegative())	// trai dau
	{
		signOfRes = 1;
	}
	numberQ = numberQ.abs();
	numberM = numberM.abs();

	char k = 127;

	while (k >= 0) {

		// shift
		numberA = numberA << 1;
		numberA.setBit(127, numberQ.getBit(0));
		numberQ = numberQ << 1;

		numberA -= numberM;

		if (numberA.getBit(0))	//	1 -> newgative | 0 -> positive
		{
			numberA += numberM;
		}
		else numberQ.setBit(127, 1);

		k--;
	}

	if (signOfRes)
	{
		numberQ.BinarySigned2sComplement();
	}


	// std::cout << ">>>>> " << numberA.data[3] << std::endl;


	return numberQ;
}
QInt QInt::operator%(const QInt& number) {
	QInt numberQ = *this;
	QInt numberA;
	QInt numberM = number;

	// if (numberQ.isNegative())	//	1 -> newgative | 0 -> positive 
	// {
	// 	numberA = QInt(-1);	// 111111....11111
	// }
	bool signOfRes = 0; 	//	1 -> newgative | 0 -> positive 
	if (numberQ.isNegative())	// trai dau
	{
		signOfRes = 1;
	}
	numberQ = numberQ.abs();
	numberM = numberM.abs();

	char k = 127;

	while (k >= 0) {

		// shift
		numberA = numberA << 1;
		numberA.setBit(127, numberQ.getBit(0));
		numberQ = numberQ << 1;

		numberA -= numberM;

		if (numberA.getBit(0))	//	1 -> newgative | 0 -> positive
		{
			numberA += numberM;
		}
		else numberQ.setBit(127, 1);

		k--;
	}

	if (signOfRes)
	{
		numberA.BinarySigned2sComplement();
	}


	// std::cout << ">>>>> " << numberA.data[3] << std::endl;


	return numberA;
}


QInt& QInt::operator+=(const QInt& number) {
	*this = *this + number;
	return *this;
}

QInt& QInt::operator-=(const QInt& number) {
	*this = *this - number;
	return *this;
}

QInt& QInt::operator*=(const QInt& number) {
	*this = *this * number;
	return *this;
}

QInt& QInt::operator/=(const QInt& number) {
	*this = *this / number;
	return *this;
}

bool QInt::operator>(const QInt& number) {
	QInt temp = *this - number;
	return (!(temp.getBit(0)) && (*this != number));	// temp is not negative and this not equal number
}
bool QInt::operator<(const QInt& number) {
	return !(*this >= number);
}
bool QInt::operator==(const QInt& number) {
	QInt numberTemp = *this - number;
	for (int i = 0; i < 4; ++i)
	{
		if (numberTemp.data[i] != 0)
		{
			return false;
		}
	}
	return true;
}
bool QInt::operator!=(const QInt& number) {
	return !(*this == number);
}
bool QInt::operator>=(const QInt& number) {
	return (*this > number || *this == number);
}
bool QInt::operator<=(const QInt& number) {
	return (*this < number || *this == number);
}


QInt& QInt::operator++() {		 // ++x
	QInt one(1);
	*this = *this + one;
	return *this;
}

QInt QInt::operator++(int x) {	// x++
	QInt temp = *this;
	++(*this);
	return temp;
}

QInt& QInt::operator--() { 		// --x
	QInt one(1);
	*this = *this - one;
	return *this;
}

QInt QInt::operator--(int x) {	// x--
	QInt temp = *this;
	--(*this);
	return temp;
}

void QInt::shiftRightOne() {
	for (int i = 3; i > 0; i--)
	{
		this->data[i] = this->data[i] >> 1;
		this->setBit(i * 32, this->data[i - 1] & 1);
	}
	this->data[0] = (this->data[0] >> 1);
	// this->setBit(0, 0);
}
QInt QInt::operator>>(int n) {
	QInt res = *this;

	for (int i = 0; i < n; ++i)
	{
		res.shiftRightOne();
	}

	return res;
}

void QInt::shiftLeftOne() {
	for (int i = 0; i < 3; ++i)
	{
		this->data[i] = this->data[i] << 1;
		this->setBit(i * 32 + 31, this->getBit((i + 1) * 32));
	}
	this->data[3] = this->data[3] << 1;
}
QInt QInt::operator<<(int n) {
	QInt res = *this;

	for (int i = 0; i < n; ++i)
	{
		res.shiftLeftOne();
	}

	return res;
}


QInt QInt::ror(int n) {
	n = n % 128;
	QInt temp = *this >> n;
	for (int i = 0; i < n; ++i)
	{
		temp.setBit(i, 0);
	}
	return ((temp) | (*this << (128 - n)));
}
QInt QInt::rol(int n) {
	n = n % 128;
	QInt temp = *this >> (128 - n);
	for (int i = 0; i < (128 - n); ++i)
	{
		temp.setBit(i, 0);
	}
	return ((*this << n) | (temp));
}


QInt QInt::operator&(const QInt& number) {
	QInt res;
	for (char i = 0; i < 4; ++i)
	{
		res.data[i] = this->data[i] & number.data[i];
	}
	return res;
}
QInt QInt::operator|(const QInt& number) {
	QInt res;
	for (char i = 0; i < 4; ++i)
	{
		res.data[i] = this->data[i] | number.data[i];
	}
	return res;
}
QInt QInt::operator^(const QInt& number) {
	QInt res;
	for (char i = 0; i < 4; ++i)
	{
		res.data[i] = this->data[i] ^ number.data[i];
	}
	return res;
}
QInt QInt::operator~() {
	QInt res;
	for (char i = 0; i < 4; ++i)
	{
		res.data[i] = ~(this->data[i]);
	}
	return res;
}

int QInt::operator&(int number) {
	return this->data[3] & number;
}
int QInt::operator|(int number) {
	return this->data[3] | number;
}
int QInt::operator^(int number) {
	return this->data[3] ^ number;
}



std::ostream& operator<<(std::ostream& os, QInt& number) {
	// bool* bits = number.DecToBin();
	// std::string DecStr = BitsToDecStr(bits);

	// int beg_del = std::string::npos;

	// if (DecStr[0] == '0')
	// {
	// 	beg_del = 0;
	// }
	// else if (DecStr[0] == '-' && DecStr[1] == '0')
	// {
	// 	beg_del = 1;
	// }

	// if (beg_del != std::string::npos)
	// {
	// 	int end_del = DecStr.find_first_not_of("0", beg_del);
	// 	DecStr.erase(beg_del, end_del - 1);
	// }

	// delete[] bits;
	// // os << DecStr;
	os << (number.viewDataInBit());
	// os << (number.viewDataInDec());
	// os << number.data[3];
	return os;
}

std::istream& operator>>(std::istream& is, QInt& number) { // type number and base
	std::string numberStr;
	short base = 10;
	is >> numberStr >> base;
	number = QInt(numberStr, base);

	return is;
}



void QInt::ScanQInt() {
	std::cin >> *this;
}
void QInt::PrintQInt() {
	std::cout << *this;
}
bool* QInt::DecToBin() {
	bool* pArrBit = new bool[129];
	for (int i = 0; i < 128; ++i)
	{
		*(pArrBit + i) = bool(this->getBit(i));
	}
	*(pArrBit + 128) = '\0';

	return pArrBit;
}

std::string QInt::DecToHex(QInt& num)
{
	bool* bits = num.DecToBin();	// chuyển số từ hệ 10 --> hệ 2
	return BinToHex(bits);	// tính số hệ 16 theo số hệ 2 nhận được
}
QInt QInt::BinToDec(const std::string& bitStr)
{
	QInt res;
	for (int i = bitStr.length() - 1; i >= 0; --i)
	{
		res.setBit(127 - (bitStr.length() - 1 - i), bitStr[i] - '0');
	}
	return res;
}
QInt QInt::HexToDec(std::string hexStr) {

	QInt res;

	// check is negative
	bool isNegative = false;
	if (hexStr[0] == '-')
	{
		isNegative = true;
		hexStr = hexStr.substr(1);
	}

	// Max 32 Character -> set phrase of 4 bits
	char len = hexStr.length();
	for (int i = 0; i < len; ++i)
	{
		res.setHex(32 - (len - i), hexStr[i]);
	}

	if (isNegative)
	{
		res.BinarySigned2sComplement();
	}

	return res;
}


bool QInt::isNegative() {
	return this->getBit(0);
}
bool QInt::hasBitZero() {
	for (int i = 1; i < 128; ++i)
	{
		if (this->getBit(i) == 0)
		{
			return true;
		}
	}
	return false;
}
bool QInt::justHasBitIs(short pos, bool bit) {
	for (short i = 0; i < 128; ++i)
	{
		if (this->getBit(pos) != bit || (i != pos && this->getBit(i) == bit))
		{
			return false;
		}
	}
	return true;
}
std::string QInt::StrPlus1(const std::string& str) {
	std::string res = str;

	bool remNum = 1;
	char num = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		num = res[i] - '0';
		num += remNum;
		remNum = num / 10;
		num %= 10;
		res[i] = num + '0';
	}
	if (remNum != 0)
	{
		res.insert(0, 1, remNum + '0');
	}
	return res;

}
std::string QInt::mul2(const std::string& number) {
	std::string res = number;

	bool remNum = 0;
	char num = 0;
	for (int i = number.length() - 1; i >= 0; i--)
	{
		num = res[i] - '0';
		num = num * 2 + remNum;
		remNum = num / 10;
		num %= 10;
		res[i] = num + '0';
	}
	if (remNum != 0)
	{
		res.insert(0, 1, remNum + '0');
	}
	return res;
}
std::string QInt::powWithN(const std::string& number, short n) {
	if (n == 0)
	{
		return std::string("1");
	}

	std::string res = number;
	for (int i = 1; i < n; ++i)
	{
		res = mul2(res);
	}
	return res;
}
std::string QInt::StrNumPlusStrNum(const std::string& number1, const std::string& number2) {
	std::string res;
	std::string temp;
	if (number1.length() >= number2.length())
	{
		res = number1;
		temp = number2;
	}
	else
	{
		res = number2;
		temp = number1;
	}

	bool remNum = 0;
	char num = 0;
	for (int i = temp.length() - 1; i >= 0; i--)
	{
		num = (res[res.length() - (temp.length() - i)] - '0') + (temp[i] - '0') + remNum;
		remNum = num / 10;
		num %= 10;
		res[res.length() - (temp.length() - i)] = num + '0';
	}
	if (remNum != 0)
	{
		for (int i = res.length() - temp.length() - 1; i >= 0; i--)
		{
			num = res[i] + remNum - '0';
			remNum = num / 10;
			num %= 10;
			res[i] = num + '0';
		}
	}
	if (remNum != 0)
	{
		res.insert(0, 1, remNum + '0');
	}
	return res;
}
std::string QInt::viewDataInDec() {
	bool isNegative = false;
	if (this->getBit(0))	// mean negative
	{
		isNegative = true;
		this->BinarySigned2sComplement();	// chuyen dang bu 2
	}

	std::string res = "0";
	for (short i = 1; i < 128; ++i)
	{
		if (this->getBit(i))
		{
			res = StrNumPlusStrNum(res, QInt::powWithN("2", 127 - i));	// res = res + 2^(127-i)
		}
	}

	if (isNegative)
	{
		res.insert(0, 1, '-');
	}

	return res;
}
QInt QInt::abs() {
	QInt temp = *this;
	if (temp.isNegative())
	{
		temp.BinarySigned2sComplement();
	}
	return temp;
}

std::string QInt::BinToHex(bool* bits)
{
	// khai báo
	int num = 0, n = 128, len = 1, power = 0;	// biến lưu kết quả phụ, số lượng phần tử và lũy thừa
	std::string numHex;

	// duyệt các phần tử trong dãy bit từ phải sang trái
	for (int i = n - 1; i >= 0; i--)
	{
		// nếu bit đang xét là 1, thực hiện
		if (bits[i])
		{
			// tính lũy thùa 2 ứng với vị trí của bit
			num += pow(2, power);
		}

		// nếu đã duyệt qua 1 cụm 4 bit hay đã duyệt bit cuối, thực hiện
		if ((n - 1 - i) % 4 == 3 || i == 0)
		{
			// xét kết quả lũy thừa và thêm vào đầu chuỗi
			if (num < 10)
			{
				numHex.insert(0, 1, char('0' + num));	// nếu < 10 thì thêm ký tự số tương ứng
			}
			else
			{
				numHex.insert(0, 1, char('A' + num - 10));	// ngược lại thêm ký tự từ A - F tương ứng 10 - 15
			}

			// đật lại kết quả và chỉ số lũy thừa
			num = 0;
			power = 0;
		}
		else
		{
			// tăng lũy thừa
			power++;
		}
	}

	return numHex;	// trả về chuỗi số hệ 16 tương ứng
}

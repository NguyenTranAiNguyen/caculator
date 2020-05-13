#include "pch.h"
#include "Qfloat.h"

Qfloat::Qfloat()
{
	for (int i = 0; i < 4; i++)
	{
		data[i] = 0;
	}
}

Qfloat::Qfloat(float number)
{
	string stringFloat;
	stringFloat = to_string(number);

	//xoa cac so 0 du thua phia sau
	for (int i = stringFloat.length() - 1; i >= 0; i--)
	{
		if (stringFloat[i] == '0')
		{
			stringFloat.erase(stringFloat.end() - 1);
		}
		else
		{
			break;
		}
	}

	ScanQfloat(stringFloat);
}

Qfloat::Qfloat(string stringFloat)
{
	ScanQfloat(stringFloat);
}

bool Qfloat::setBit(unsigned char k, bool value) {
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

char Qfloat::getBit(unsigned char k) {
	if (k < 0 || k > 127)
	{
		return -1;
	}

	int temp = this->data[k / 32];

	return (temp >> (31 - (k % 32))) & 1;
}

string Qfloat::convertIntToBinNotComplement(string number) {
	string result;
	QInt intNumber(0);

	// kiểm tra số âm
	if (number[0] == '-')
	{
		number[0] = '0';
	}

	// set bit
	char k = 127;
	while (number != "0" && k >= 0) {
		intNumber.setBit(k, (number[number.length() - 1] - '0') & 1);
		k--;
		number = QInt::stringDevideBy2(number);
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 32; ++j)
		{
			result += to_string(intNumber.getBit(i * 32 + j));
		}
	}
	return result;
}

bool Qfloat::isValidStringInput(string str)
{
	if (str[0] == '-')
	{
		str.erase(str.begin());
	}
	if (str.length() == 0)
	{
		return false;
	}
	int countPoint = 0;//dem so dau cham trong chuoi
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i]>'9')
		{
			if (str[i] == '.')
			{
				countPoint++;
			}
			else
			{
				return false;
			}
		}
	}

	if (countPoint > 1)//truong hop chuoi co nhieu dau cham
	{
		return false;
	}

	return true;
}

string Qfloat::strUppercase(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
	}
	return str;
}

string Qfloat::convertToStandardString(string str)
{
	//loai bo cac khoang trang thua
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}

	//loai bot cac so khong thua
	bool allZero = true;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != '0')
		{
			allZero = false;
		}
	}
	if (allZero)
	{
		str = "0";
	}

	return str;
}

void Qfloat::ScanQfloat(string stringFloat)
{
	int move = 0;
	string beforePoint;//so nguyen truoc dau cham
	string afterPoint;//phan thap phan sau dau cham
	bool pointAppear = false; //cho biet da duyet den dau cham hay chua
	bool sign, outOfRange = false;
	int E, decExp = 0;
	string completeBinary = "";
	string exponent, fraction, F;
	string binOfBeforePoint, binOfAfterPoint;

	//khoi tao chuoi exponent
	for (int i = 0; i < 15; i++)
	{
		exponent += '0';
	}

	//khoi tao fraction
	for (int i = 0; i < 112; i++)
	{
		fraction += "0";
	}

	//xu ly chuoi
	for (int i = 0; i < stringFloat.length(); i++)
	{
		if (stringFloat[i] == '.' && pointAppear == false)//bo qua dau cham dau tien, neu dau cham tiep theo xuat hien thi them vao afterPoint
		{
			pointAppear = true;
			continue;
		}

		if (pointAppear)
		{
			afterPoint += stringFloat[i];
		}
		else
		{
			beforePoint += stringFloat[i];
		}
	}

	if (beforePoint.length() == 0)
	{
		beforePoint = "0";
	}
	//loai bo cac khoang trang va so 0 du thua
	beforePoint = convertToStandardString(beforePoint);
	afterPoint = convertToStandardString(afterPoint);
	if (pointAppear)
	{
		stringFloat = beforePoint + '.' + afterPoint;
	}
	else
	{
		stringFloat = beforePoint;
	}

	//cout << "Before point: " << beforePoint << endl;

	//CAI DAT BIT SIGN
	if (beforePoint[0] == '-')
	{
		completeBinary += '1';
		sign = 1;
		beforePoint.erase(beforePoint.begin());
	}
	else
	{
		completeBinary += '0';
		sign = 0;
	}

	//XET TRUONG HOP BIEU DIEN SO KHONG
	if ((beforePoint == "0" && afterPoint == "0") || (beforePoint == "0" && afterPoint.length() == 0))
	{
		E = 0;
	}
	//XET TRUONG HOP SO VO CUNG
	else if ((strUppercase(beforePoint) == "INF") && (afterPoint.length() == 0))
	{
		E = 32767;
		for (int i = 0; i < 15; i++)
		{
			exponent[i] = '1';
		}
		for (int i = 0; i < 112; i++)
		{
			fraction[i] = '0';
		}
	}


	//XET CAC TRUONG HOP KHONG PHAI SO
		//Neu khong chi ro loai NaN, mac dinh no la quiet NaN
	else if ((strUppercase(beforePoint) == "NAN") && (afterPoint.length() == 0))
	{
		for (int i = 0; i < 15; i++)
		{
			exponent[i] = '1';
		}
		fraction[0] = '1';
	}
	//truong hop quiet NaN
	else if ((strUppercase(beforePoint) == "QNAN") && (afterPoint.length() == 0))
	{
		for (int i = 0; i < 15; i++)
		{
			exponent[i] = '1';
		}
		fraction[0] = '1';
	}
	//truong hop signaling NaN
	else if ((strUppercase(beforePoint) == "SNAN") && (afterPoint.length() == 0))
	{
		for (int i = 0; i < 15; i++)
		{
			exponent[i] = '1';
		}
		fraction[1] = '1';
	}
	//truong hop nhap vao mot chuoi ki tu khong phai so bat ki
	else if (isValidStringInput(stringFloat) == false)
	{
		//mac dinh day la qNaN
		for (int i = 0; i < 15; i++)
		{
			exponent[i] = '1';
		}
		fraction[0] = '1';
	}


	//XET TRUONG HOP SO CO THE CHUAN HOA VA SO KHONG THE CHUAN HOA
	else
	{
		if (beforePoint != "0")
		{
			binOfBeforePoint = ConvertBeforePointToBinary(beforePoint);
		}
		else
		{
			binOfBeforePoint = "0";
		}

		if (afterPoint != "0" && afterPoint.length() != 0)
		{
			binOfAfterPoint = ConvertAfterPointToBinary(afterPoint, binOfBeforePoint, sign);
		}
		else
		{
			binOfAfterPoint = "0";
		}

		//DAY BIEU DIEN EXPONENT
		//K=16383
		if (beforePoint == "0")//TH dich cham dong sang phai
		{
			int pos = binOfAfterPoint.find('1') + 1;
			E = -pos;
			if (E < -16382 || E > 16383) //TH vuot qua mien bieu dien cua so normalized
			{
				if (E < -16383 && E >= -16495) //xem xet de bieu dien duoi dang so denormalized
				{
					move = -E - 16383;//cho biet can dich chuyen bao nhieu bit de duoc dang 0.Fx2^-16382
				}
				else
				{
					outOfRange = true;//vuot qua khoi mien bieu dien cua denormalized va normalized
				}

			}
			else //TH so co the chuan hoa
			{
				decExp = 16383 + E;
				string simpleExponent = ConvertExponentToBinary(to_string(decExp));

				//gan simpleExponent vao exponent
				for (int i = simpleExponent.length() - 1; i >= 0; i--)
				{
					exponent[i] = simpleExponent[i];
				}
			}
		}
		else //TH dich cham dong sang trai
		{
			E = binOfBeforePoint.length() - 1;
			if (E < -16382 || E>16383)//neu vuot khoi mien bieu dien
			{
				outOfRange = true;
			}
			else
			{
				decExp = 16383 + E;
				string simpleExponent = ConvertExponentToBinary(to_string(decExp));
				//gan simpleExponent vao exponent
				for (int i = simpleExponent.length() - 1; i >= 0; i--)
				{
					exponent[i] = simpleExponent[i];
				}
			}
		}


		//--------DAY BIEU DIEN FRACTION
		if (outOfRange)
		{
			for (int i = 0; i < 15; i++)
			{
				exponent[i] = '1';
			}
			for (int i = 0; i < 112; i++)
			{
				fraction[i] = '0';
			}
		}
		else
		{
			if (beforePoint == "0")
			{
				int pos = binOfAfterPoint.find("1") + 1;
				F = binOfAfterPoint.substr(pos);
			}
			else
			{
				string tmp = binOfBeforePoint;
				tmp.erase(tmp.begin());
				F = tmp + binOfAfterPoint;
			}

			if (move != 0)//Neu day la so khong the chuan hoa
			{
				fraction[move - 1] = '1';
				int i;
				for (i = 0; i < F.length(); i++)
				{
					if (i < 112 - move)
					{
						fraction[move + i] = F[i];
					}
					else
					{

						if (i < F.length())//Lam tron neu chua chay het day F
						{
							if (sign == 1)
							{
								if (fraction[move + i] == '1')
								{
									fraction[move + i] = '0';
								}
							}
							else
							{
								if (fraction[move + i] == '0')
								{
									fraction[move + i] = '1';
								}
							}
						}

						break;
					}
				}
			}
			else
			{
				for (int i = 0; i < F.length(); i++)
				{
					fraction[i] = F[i];//dua F vao fraction, cac phan tu con lai deu bang 0
				}
			}
		}
	}


	//---------DAY NHI PHAN BIEU DIEN CHAM DONG
	completeBinary = completeBinary + exponent + fraction;
	bool bit;
	//dua cac bit vao data[4]
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (completeBinary[32 * i + j] == '0')
			{
				bit = 0;
			}
			else
			{
				bit = 1;
			}
			this->setBit(32 * i + j, bit);
		}
	}
}

string Qfloat::ConvertBeforePointToBinary(string beforePoint)
{
	string bitArray = convertIntToBinNotComplement(beforePoint);
	int pos = bitArray.find("1");
	return bitArray.substr(pos);
}

string Qfloat::ConvertExponentToBinary(string beforePoint)
{
	string exponent;
	string bitArray = convertIntToBinNotComplement(beforePoint);
	exponent = bitArray.substr(bitArray.length() - 15);

	return exponent;
}


string Qfloat::ConvertAfterPointToBinary(string afterPoint, string binOfBeforePoint, bool sign)
{
	string originString = afterPoint;
	string binaryString = "";
	int preLength = afterPoint.length();
	int limit = 112 - (binOfBeforePoint.length() - 1);//tinh toan so luong bit co the luu tru cua phan afterPoint
	int countAppear = 0;//so lan xuat hien cua 1 trong binaryString
	while (binaryString.length() < limit)
	{
		afterPoint = MultyWith2(afterPoint);

		if (afterPoint[0] == '1' && preLength == afterPoint.length() - 1)
		{
			binaryString += '1';
			countAppear++;
			if (countAppear == 1)
			{
				limit++;
			}
			if (ConditionToStop(afterPoint, originString))
			{

				return binaryString;
			}
			afterPoint.erase(afterPoint.begin());
		}
		else
		{
			binaryString += '0';
			if ((binOfBeforePoint == "0") && (countAppear == 0))//TH dich cham dong dich sang trai, tang limit bieu dien phan afterPoint
			{
				limit++;
			}
		}

	}
	//lam tron bit cuoi (TH day nhi phan tran khoi limit)
	if (sign == 0)
	{
		if (binaryString[binaryString.length() - 1] == '0')
		{
			binaryString[binaryString.length() - 1] = '1';
		}
	}
	else
	{
		if (binaryString[binaryString.length() - 1] == '1')
		{
			binaryString[binaryString.length() - 1] = '0';
		}
	}
	return binaryString;
}

bool Qfloat::ConditionToStop(string stringNumber, string originalString)
{
	if (originalString.length() < stringNumber.length())
	{
		if (stringNumber[0] == '1')
		{
			for (int i = 1; i < stringNumber.length(); i++)
			{
				if (stringNumber[i] != '0')
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

string Qfloat::viewDataInBit()
{
	string strBit;
	int x;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 32; ++j)
		{
			x = i * 32 + j;
			strBit += to_string(this->getBit(x));
			if (x == 0 || x == 15)//phan cach sign, exponent, fraction
			{
				strBit += ' ';
			}
		}
	}
	return (strBit);
}

Qfloat& Qfloat::operator=(const Qfloat number)
{
	for (int i = 0; i < 4; i++)
	{
		this->data[i] = number.data[i];
	}

	return *this;
}


istream& operator>>(istream& is, Qfloat& number)
{
	string stringFloat;
	is >> stringFloat;
	number = Qfloat(stringFloat);
	return is;
}

ostream& operator << (ostream& os, Qfloat& number)
{
	string bit;
	bit = number.viewDataInBit();
	deleteSpace(bit);
	string result = number.ConvertBinToDec(bit);
	os << "Number in decimal is: " << result << endl;
	return os;
}


string Qfloat::MultyWith2(string& bigNum)
{
	//vector <int> result;
	//int lengthOfEachElement = 9;
	string result;
	int memory = 0;
	int temp;
	char c;
	for (int i = bigNum.size() - 1; i >= 0; i--)
	{
		temp = (bigNum[i] - '0') * 2 + memory;
		if (temp >= 10)
		{
			c = temp - 10 + '0';
			result.insert(0, 1, c);
			memory = 1;
			if (i == 0)
			{
				c = '1';
				result.insert(0, 1, c);
			}
		}
		else
		{
			c = temp + '0';
			result.insert(0, 1, c);
			memory = 0;
		}
	}
	return result;
}

string Qfloat::ConvertBeforePointToDec(string& bit) // tham số đưa vào là dãy bit phía trước dấu chấm động
{
	string result = "0"; // khởi tạo kq bằng 0
	for (int i = 0; i < bit.size(); i++) // duyệt qua từng bit
	{
		if (bit[i] == '1') // nếu bit 1 thì tiến hành lấy mũ và cộng lại (theo công thức cơ số q tổng quát)
		{
			result = AddBeforePoint(result, pow2(bit.size() - i - 1));
		}

	}
	return result;
}
string Qfloat::pow2(int index) // tham số truyền vào là số mũ
{
	if (index >= 0) // mũ dương thì sẽ lấy phần đó nhân 2
	{
		string result = "1";

		for (int i = 1; i <= index; i++)
		{
			result = MultyWith2(result);
		}
		return result;
	}
	else //  mũ âm thì sẽ chia 2
	{
		string result = "5"; // bởi vì số lớn nhất là 0.5
		for (int i = -2; i >= index; i--) // chạy vòng lặp nếu số mũ nhỏ hơn -1
		{
			result = Divide2AfterPoint(result);
		}
		return result;
	}
}

string Qfloat::AddBeforePoint(string& FirstNum, string secondNum) // tham số truyền vào là 2 chuỗi thập phân (phía trước dấu chấm động)
{
	string result;

	int tempResult = 0; // kết quả tạm thời khi cộng hai kí tự trong chuỗi
	char c; // dùng để lưu kí tự của số
	int memory = 0;// nếu tempResult >=10 thì memory =1
	int i;
	int min = Min(FirstNum.size(), secondNum.size()); // tìm chuỗi ngắn hơn
	for (i = 0; i < min; i++)
	{
		tempResult = FirstNum[FirstNum.size() - i - 1] - '0' + secondNum[secondNum.size() - i - 1] - '0' + memory; // cộng hai kí tự từ phải qua trái
		if (tempResult >= 10)
		{
			c = tempResult - 10 + '0'; // chuyển về dạng kí tự
			result.insert(0, 1, c); // chèn vào đầu chuỗi kết quả
			memory = 1;
		}
		else
		{
			c = tempResult + '0';// chuyển về dạng kí tự
			result.insert(0, 1, c);// chèn vào đầu chuỗi kết quả
			memory = 0;
		}
	}
	if (FirstNum.size() > secondNum.size()) // xử lý phần còn dư của chuỗi dài
	{
		for (; i < FirstNum.size(); i++)
		{
			tempResult = FirstNum[FirstNum.size() - i - 1] - '0' + memory;
			if (tempResult >= 10)
			{
				c = tempResult - 10 + '0';
				result.insert(0, 1, c);
				memory = 1;
			}
			else
			{
				c = tempResult + '0';
				result.insert(0, 1, c);
				memory = 0;
			}
		}
		if (memory == 1)
		{
			c = '1';
			result.insert(0, 1, c);
		}
	}
	else
	{
		for (; i < secondNum.size(); i++)
		{
			tempResult = secondNum[secondNum.size() - i - 1] - '0' + memory;
			if (tempResult >= 10)
			{
				c = tempResult - 10 + '0';
				result.insert(0, 1, c);
				memory = 1;
			}
			else
			{
				c = tempResult + '0';
				result.insert(0, 1, c);
				memory = 0;
			}
		}
		if (memory == 1)
		{
			c = '1';
			result.insert(0, 1, c);
		}
	}
	return result;
}

int Qfloat::Min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}

string Qfloat::Divide2AfterPoint(string& bit) // tham số truyền vào là chuỗi thập phân sau dấu chấm động
{
	string result;
	int tempQuotient;// thương số tạm thời
	char c; // dùng để lưu mã ascii của số
	int memory = 0;
	for (int i = 0; i < bit.size(); i++)
	{
		if (memory == 1) // khi số dư là 1 thì lần chia tiếp theo sẽ được cộng thêm 10 (theo như quy tắc chia)
		{
			tempQuotient = (bit[i] - '0' + 10) / 2;
		}
		else
		{
			tempQuotient = (bit[i] - '0') / 2;
		}
		if ((bit[i] - '0') % 2 == 1)  // nếu chia dư thì memory =1
		{
			memory = 1;
		}
		else // nếu chia hết thì memory =0
		{
			memory = 0;
		}
		c = tempQuotient + '0';
		result.push_back(c); // thêm vào cuối chuỗi kết quả
		if (i == bit.size() - 1)
		{
			result.push_back('5'); // vì phép chia luôn có dư nên phải thêm 5 vào cuối
		}
	}
	return result;
}

string Qfloat::AddAfterPoint(string& FirstNum, string secondNum) // tham số truyền vào là 2 chuỗi dạng thập phân phía sau dấu chấm
{
	string result = "";

	int temp;
	char c;
	int memory = 0;
	int minLength = Min(FirstNum.size(), secondNum.size()); // lấy kích thước của chuỗi nhỏ hơn
	int i = minLength - 1;
	if (FirstNum.size() > secondNum.size())
	{
		for (int i = FirstNum.size() - 1; i >= minLength; i--) // duyệt từ cuối chuỗi (duyệt đến phần tử cuối cùng của chuỗi ngắn hơn)
		{
			result.insert(0, 1, FirstNum[i]); // chèn từng phần từ vào đầu chuỗi (do duyệt từ phải qua trái)
		}
	}
	else
	{
		for (int i = secondNum.size() - 1; i >= minLength; i--) // ý nghĩa như trên
		{
			result.insert(0, 1, secondNum[i]);
		}
	}
	for (; i >= 0; i--) // duyệt từ phần tử (minlength -1) về 0
	{
		temp = FirstNum[i] - '0' + secondNum[i] - '0' + memory; // cộng hai phần tử lại với nhau và cộng thêm memory như quy tắc cộng hai số nguyên
		if (temp >= 10)
		{
			c = temp - 10 + '0';
			memory = 1;
		}
		else
		{
			memory = 0;
			c = temp + '0';
		}

		result.insert(0, 1, c);
	}


	return result;
}

string Qfloat::ConvertAfterPointToDec(string& bit) // tham số truyền vào là chuỗi bit phía sau dấu chấm động
{
	string result;
	if (bit == "") // nếu chuỗi rỗng thì ra 0
	{
		result = "0";
	}
	else
	{
		for (int i = 0; i < bit.size(); i++)
		{
			if (bit[i] == '1')
			{
				result = AddAfterPoint(result, pow2((i + 1) * -1)); // cộng phần phía sau dấu chấm
			}
		}
	}

	if (result == "")
	{
		result = "0";
	}
	return result;
}

string Qfloat::ConvertBinToDec(string& bit) // tham số truyền vào là chuỗi 128 bit
{
	string result = "";
	int pos = 0; // vi tri dau cham dong (neu co)
	if (isDotExisted(bit, pos)) // truong hop nhap co dau cham dong. vd:1001.0101
	{
		string realPart = bit.substr(0, pos); // lay phan thuc
		cout << "phan thuc: " << realPart << endl;
		string decimalPart = bit.substr(pos + 1);
		cout << "phan thap phan: " << decimalPart << endl;
		result += ConvertBeforePointToDec(realPart); // chuyển phần thực về hệ 10 (gán vào chuỗi kết quả)
		result += "."; // thêm dấu "." vào 
		result += ConvertAfterPointToDec(decimalPart); // chuyển phần thập phân về hệ 10 (thêm vào chuỗi kết quả)
	}
	else
	{
		standardized_short_bit(bit); // chuan hoa neu chuoi it hon 128 bit
		standardized_long_bit(bit); // chuẩn hóa nếu chuỗi dài hơn 128 bit
		if (bit[0] == '1') // xét bit dấu
		{
			result.push_back('-');
		}

		string exponent_bit = bit.substr(1, 15); // lấy 15 bit từ bit thứ 1 
		string significant = bit.substr(16); // lấy từ bit 16 về sau
		if (isMaxExponent(exponent_bit)) // xem chuỗi exponent có phải toàn bit 1 không
		{
			if (isInfinity(significant)) // xem chuỗi bit có phải số vô cùng
			{
				return "infinity";
			}
			return "NaN - Not A Number";
		}

		int exponent = stoi(ConvertBeforePointToDec(exponent_bit)); // tinh so mu
		cout << "exponent truoc khi tru 16383: " << exponent << endl;
		exponent -= 16383;
		cout << "chuoi exponent: " << exponent_bit << endl;

		cout << "exponent la: " << exponent << endl;


		string decimalPart, realPart; // khởi tạo string cho phần thập phân và phần thưc
		cout << "significant: " << significant << endl;
		standardizedBitSequence(significant, realPart, decimalPart, exponent); // chuẩn hóa chuỗi bit về dạng hệ nhị phân đầy đủ

		result += ConvertBeforePointToDec(realPart); // chuyển phần thực về hệ 10 (gán vào chuỗi kết quả)
		result += "."; // thêm dấu "." vào 
		result += ConvertAfterPointToDec(decimalPart); // chuyển phần thập phân về hệ 10 (thêm vào chuỗi kết quả)
	}

	return result;
}


// mục đích của hàm này là tách chuỗi significant về 2 chuỗi thập phân và chuỗi thực
bool Qfloat::standardizedBitSequence(string significant, string& realPart, string& decimalPart, int exponent) // tham số truyền vào là chuôi significand, chuỗi phần thập phân và phần thực
{
	if (exponent >= 0)// giá trị tuyệt đối của số > 1 
	{
		// ->sẽ dịch dấu chấm qua phải nên khởi tạo realpart =1
		realPart = "1";
		string realPart_tail;
		if (exponent <= 112) // nếu như số đó có số kí tự nhỏ hơn 112 (112 là số bit của significant)
		{
			realPart_tail = significant.substr(0, exponent);
			realPart += realPart_tail; // chuỗi real sẽ bằng "1" cộng với 1 phần của significant (số ký tự bằng exponent)
			decimalPart = significant.substr(exponent, 112 - exponent); // phần thập phân sẽ là phần còn lại
		}
		else // nếu như lớn hơn 112
		{
			realPart = "1" + significant; // phần thực sẽ là 1 cộng với toàn bộ significant
			for (int i = 0; i < exponent - 112; i++)
			{
				realPart.push_back('0'); // phần thực kết hợp thêm các số 0 (số ký tự 0 = exponent -112)
			}
			decimalPart = ""; // phần này sẽ chuyển dấu chấm qua trái nên phần thập phân là rỗng
		}
	}
	else
	{
		realPart = "";
		decimalPart = significant;
		if (exponent == -16383) //trường hợp số không thể chuẩn hóa được
		{
			if (check_Largest_positive_denormalized_number(significant) || check_Smallest_positive_denormalized_number(significant))
			{
				decimalPart.insert(0, 1, '0');
				for (int i = 0; i > exponent + 1 + 1; i--) // do tieu chuan cua IEEE
				{
					decimalPart.insert(0, 1, '0');
				}
			}
			else
			{
				decimalPart.insert(0, 1, '0');
				for (int i = 0; i > exponent + 1; i--)
				{
					decimalPart.insert(0, 1, '0');
				}
			}

		}
		else
		{
			decimalPart.insert(0, 1, '1'); // bit 1 của phần thực chuyển qua
			for (int i = 0; i > exponent + 1; i--)
			{
				decimalPart.insert(0, 1, '0');
			}
		}


	}
	return true;
}



bool Qfloat::isMaxExponent(string exponent)
{
	for (int i = 0; i < exponent.size(); i++)
	{
		if (exponent[i] == '0')
		{
			return false;
		}
	}
	return true;
}

bool Qfloat::isInfinity(string significant)
{
	for (int i = 0; i < significant.size(); i++)
	{
		if (significant[i] != '0')
		{
			return false;
		}
	}
	return true;
}

bool Qfloat::check_Largest_positive_denormalized_number(string significand)
{
	// số không thể chuẩn hóa lớn nhất sẽ có significant toàn bit 1
	for (int i = 0; i < significand.size(); i++)
	{
		if (significand[i] == '0')
		{
			return false;
		}
	}
	return true;
}

bool Qfloat::check_Smallest_positive_denormalized_number(string significand)
{
	//số không thể chuẩn hóa nhỏ nhất sẽ có significant 22 bit 0 và 1 bit 1 cuối
	for (int i = 0; i < significand.size() - 1; i++)
	{
		if (significand[i] == '1')
		{
			return false;
		}
	}
	if (significand[significand.size() - 1] == '0')
	{
		return false;
	}
	return true;
}

bool Qfloat::isDotExisted(string num, int& pos)
{
	int length = num.size();
	for (int i = 0; i < length; i++)
	{
		if (num[i] == '.')
		{
			pos = i;
			return true;
		}
	}
	return false;
}

void Qfloat::standardized_short_bit(string& bit)
{
	int length = bit.size();
	if (length < 128)
	{
		for (int i = 0; i < 128 - length; i++)
		{
			bit.push_back('0');
		}
	}
}


void Qfloat::PrintQfloat()
{
	cout << "Number in binary is: " << endl;
	cout << viewDataInBit() << endl;
	cout << *this;
}

bool* Qfloat::DecToBin(Qfloat x)
{
	bool* boolArr = new bool[128];

	string binArr = x.viewDataInBit();
	//xoa cac khoang trang trong viewDataInBit
	for (int i = 0; i < binArr.length(); i++)
	{
		if (binArr[i] == ' ')
		{
			binArr.erase(binArr.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < binArr.length(); i++)
	{
		if (binArr[i] == '0')
		{
			boolArr[i] = 0;
		}
		else
		{
			boolArr[i] = 1;
		}
	}

	return boolArr;
}

void Qfloat::standardized_long_bit(string& bit)
{
	bit.resize(128);
}
#pragma once

#include <fstream>
#include <sstream>
#include "Qfloat.h"
using namespace std;

//Hàm đọc file QInt_input, thực hiện tính toán, chuyển đổi và in ra file output
//Tham số: tên file input và output
//Trả về: true nếu thành công, ngược lại false
std::string scanQIntQues(string strQues);

//Hàm thực hiện chuyển đổi giữa các hệ cơ số
//Tham số:
//		str1: hệ cơ số của input
//		str2: hệ cơ số của output
//		str3: số cần chuyển đổi
//Trả về: chuỗi kết quả sau khi chuyển đổi
string Convert(string str1, string str2, string str3);

//Hàm thực hiện tính toán giữa các số QInt
//Tham số: 
//		str1: hệ cơ số đang thực hiện tính toán
//		str2: toán hạng thứ 1
//		str3: toán tử
//		str4: toán hạng thứ 2
//Trả về chuỗi chứa kết quả phép toán
string Calculate(string str1, string str2, string str3, string str4);

//Hàm kiểm tra trong chuỗi có chứa operator hay không
//Tham số: chuỗi cần duyệt
//Trả về: true nếu chuỗi có chứa operator, false nếu ngược lại
bool isOperator(string str);

//Hàm loại bỏ các số 0 thừa ở đầu chuỗi
//Tham số: chuỗi cần loại bỏ số 0 thừa
//Trà về: chuỗi đã được loại bỏ các số 0 thừa ở đầu chuỗi 
string rejectUnecessary0(string str);

//Hàm thực hiện chuyển đổi các hệ số và tính toán với th toán tử phủ định (~)
//Tham số: 
	//str1: hệ cơ số ban đầu 
	//str2: hệ cơ số của kết quả hoặc toán tử ~
	//str3: số cần chuyển đổi hoặc cần thực hiện phép ~
string Processing(string str1, string str2, string str3);

//Hàm thực hiện các tính toán
//Tham số: 
	//str1: hệ cơ số của các toán hạng
	//str2: toán hạng thứ nhất
	//str3: toán tử
	//str4: toán hạng thứ 2
//Trả về: kết quả của phép tính ở hệ cơ số str1
string Processing(string str1, string str2, string str3, string str4);
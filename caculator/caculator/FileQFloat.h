#pragma once
#include "QIntClass.h"
#include "Qfloat.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string stringProcessing_Qfloat(bool& decToBin, string line); // xem yêu cầu dạng chuyển và tách lấy chuỗi cần chuyển

bool Print_To_File(string line, string File_name); // in vào file

bool File_Processing(string FileInput_Name, string FileOutput_Name); // đọc file, xử lý và in ra file

void deleteSpace(string& bitData);// xóa khoảng trắng trong chuỗi bit

string convert_1_string_qfloat(string line);//  xử lý 1 dòng và trả về chuỗi kết quả
//bool test_File_Processing(string FileInput_Name, string FileOutput_Name);
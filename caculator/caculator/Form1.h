#pragma once

#include <string>
//#include "Qfloat.h"
#include "FileQInt.h"
#include "FileQFloat.h"
//#include "QIntClass.h"
using System::Runtime::InteropServices::Marshal;



static std::string toStandardString(System::String^ string)
{
	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);

	return returnString;
}

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
			this->base = 10;
			this->isOperatorNOT = false;
			txtDisplay->Text = "";
			this->ans = "0";
			this->caculous = false;	// true - da tinh xong
			this->buttonPressed = false;
			
			this->setBase();
			this->turnOffOperator();

			this->isecond = "0";
			this->ifirst = "0";
			this->ioperation = "+";
			
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fILEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ standardToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ scientificToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutUsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ membersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ topicToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ historyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ buttonAdd;

	private: System::Windows::Forms::Button^ buttonSub;
	private: System::Windows::Forms::Button^ buttonMul;
	private: System::Windows::Forms::Button^ buttonDiv;





	private: System::Windows::Forms::Button^ btnResult;
	private: System::Windows::Forms::Button^ btnBackspace;
	private: System::Windows::Forms::Button^ buttonNum3;
	private: System::Windows::Forms::Button^ buttonNum9;




	private: System::Windows::Forms::Button^ buttonNum6;

	private: System::Windows::Forms::Button^ btnCham;
	private: System::Windows::Forms::Button^ btnSoPi;
	private: System::Windows::Forms::Button^ shiftRight;
	private: System::Windows::Forms::Button^ buttonNum2;
	private: System::Windows::Forms::Button^ buttonNum8;





	private: System::Windows::Forms::Button^ buttonNum5;
	private: System::Windows::Forms::Button^ buttonNum0;


	private: System::Windows::Forms::Button^ btnExp;
	private: System::Windows::Forms::Button^ shiftLeft;
	private: System::Windows::Forms::Button^ buttonNum1;
	private: System::Windows::Forms::Button^ buttonNum4;
	private: System::Windows::Forms::Button^ buttonNum7;







	private: System::Windows::Forms::Button^ btnAmDuong;
	private: System::Windows::Forms::Button^ btnAns;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ txtDisplay;
	private: System::Windows::Forms::GroupBox^ grbName;
	private: System::Windows::Forms::Button^ btnBinBase;

	private: System::Windows::Forms::Button^ buttonToBin;

	private: System::Windows::Forms::Button^ buttonToHex;

	private: System::Windows::Forms::Button^ buttonToDec;
	private: System::Windows::Forms::Button^ buttonLess;
	private: System::Windows::Forms::Button^ buttonLessEqual;



	private: System::Windows::Forms::Button^ buttonEqual;

	private: System::Windows::Forms::Button^ buttonGreaterEqual;
	private: System::Windows::Forms::Button^ buttonGreater;
	private: System::Windows::Forms::Button^ buttonRol;





	private: System::Windows::Forms::Button^ buttonRor;

	private: System::Windows::Forms::Button^ buttonNot;

	private: System::Windows::Forms::Button^ buttonXor;

	private: System::Windows::Forms::Button^ buttonOr;

	private: System::Windows::Forms::Button^ buttonAnd;
private: System::Windows::Forms::Button^ buttonF;


private: System::Windows::Forms::Button^ buttonE;

private: System::Windows::Forms::Button^ buttonD;

private: System::Windows::Forms::Button^ buttonC;

	private: System::Windows::Forms::Button^ buttonB;

private: System::Windows::Forms::Button^ buttonA;

	private: System::Windows::Forms::ToolStripMenuItem^ temperatureToolStripMenuItem;

	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ historyToolStripMenuItem1;
private: System::Windows::Forms::Button^ buttonMod;


private: System::Windows::Forms::Button^ btnHexBase;

private: System::Windows::Forms::Button^ btnDecBase;

private: System::Windows::Forms::Label^ lblShowOp;
private: System::Windows::Forms::Label^ lblHeCoSo;








	protected:
























































































































































	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fILEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->standardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->scientificToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->temperatureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutUsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->membersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->topicToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->historyToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->historyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonSub = (gcnew System::Windows::Forms::Button());
			this->buttonMul = (gcnew System::Windows::Forms::Button());
			this->buttonDiv = (gcnew System::Windows::Forms::Button());
			this->btnResult = (gcnew System::Windows::Forms::Button());
			this->btnBackspace = (gcnew System::Windows::Forms::Button());
			this->buttonNum3 = (gcnew System::Windows::Forms::Button());
			this->buttonNum9 = (gcnew System::Windows::Forms::Button());
			this->buttonNum6 = (gcnew System::Windows::Forms::Button());
			this->btnCham = (gcnew System::Windows::Forms::Button());
			this->btnSoPi = (gcnew System::Windows::Forms::Button());
			this->shiftRight = (gcnew System::Windows::Forms::Button());
			this->buttonNum2 = (gcnew System::Windows::Forms::Button());
			this->buttonNum8 = (gcnew System::Windows::Forms::Button());
			this->buttonNum5 = (gcnew System::Windows::Forms::Button());
			this->buttonNum0 = (gcnew System::Windows::Forms::Button());
			this->btnExp = (gcnew System::Windows::Forms::Button());
			this->shiftLeft = (gcnew System::Windows::Forms::Button());
			this->buttonNum1 = (gcnew System::Windows::Forms::Button());
			this->buttonNum4 = (gcnew System::Windows::Forms::Button());
			this->buttonNum7 = (gcnew System::Windows::Forms::Button());
			this->btnAmDuong = (gcnew System::Windows::Forms::Button());
			this->btnAns = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtDisplay = (gcnew System::Windows::Forms::TextBox());
			this->grbName = (gcnew System::Windows::Forms::GroupBox());
			this->lblHeCoSo = (gcnew System::Windows::Forms::Label());
			this->lblShowOp = (gcnew System::Windows::Forms::Label());
			this->buttonMod = (gcnew System::Windows::Forms::Button());
			this->btnHexBase = (gcnew System::Windows::Forms::Button());
			this->btnDecBase = (gcnew System::Windows::Forms::Button());
			this->btnBinBase = (gcnew System::Windows::Forms::Button());
			this->buttonToBin = (gcnew System::Windows::Forms::Button());
			this->buttonToHex = (gcnew System::Windows::Forms::Button());
			this->buttonToDec = (gcnew System::Windows::Forms::Button());
			this->buttonLess = (gcnew System::Windows::Forms::Button());
			this->buttonLessEqual = (gcnew System::Windows::Forms::Button());
			this->buttonEqual = (gcnew System::Windows::Forms::Button());
			this->buttonGreaterEqual = (gcnew System::Windows::Forms::Button());
			this->buttonGreater = (gcnew System::Windows::Forms::Button());
			this->buttonRol = (gcnew System::Windows::Forms::Button());
			this->buttonRor = (gcnew System::Windows::Forms::Button());
			this->buttonNot = (gcnew System::Windows::Forms::Button());
			this->buttonXor = (gcnew System::Windows::Forms::Button());
			this->buttonOr = (gcnew System::Windows::Forms::Button());
			this->buttonAnd = (gcnew System::Windows::Forms::Button());
			this->buttonF = (gcnew System::Windows::Forms::Button());
			this->buttonE = (gcnew System::Windows::Forms::Button());
			this->buttonD = (gcnew System::Windows::Forms::Button());
			this->buttonC = (gcnew System::Windows::Forms::Button());
			this->buttonB = (gcnew System::Windows::Forms::Button());
			this->buttonA = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1->SuspendLayout();
			this->grbName->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(3);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fILEToolStripMenuItem,
					this->editToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(2, 15);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(455, 24);
			this->menuStrip1->TabIndex = 50;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fILEToolStripMenuItem
			// 
			this->fILEToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->standardToolStripMenuItem,
					this->scientificToolStripMenuItem, this->temperatureToolStripMenuItem, this->aboutUsToolStripMenuItem, this->historyToolStripMenuItem1,
					this->historyToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fILEToolStripMenuItem->Name = L"fILEToolStripMenuItem";
			this->fILEToolStripMenuItem->Size = System::Drawing::Size(37, 22);
			this->fILEToolStripMenuItem->Text = L"File";
			// 
			// standardToolStripMenuItem
			// 
			this->standardToolStripMenuItem->Name = L"standardToolStripMenuItem";
			this->standardToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->standardToolStripMenuItem->Text = L"Standard";
			this->standardToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::standardToolStripMenuItem_Click);
			// 
			// scientificToolStripMenuItem
			// 
			this->scientificToolStripMenuItem->Name = L"scientificToolStripMenuItem";
			this->scientificToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->scientificToolStripMenuItem->Text = L"Scientific";
			this->scientificToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::scientificToolStripMenuItem_Click);
			// 
			// temperatureToolStripMenuItem
			// 
			this->temperatureToolStripMenuItem->Name = L"temperatureToolStripMenuItem";
			this->temperatureToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->temperatureToolStripMenuItem->Text = L"Temperature";
			this->temperatureToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::temperatureToolStripMenuItem_Click);
			// 
			// aboutUsToolStripMenuItem
			// 
			this->aboutUsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->membersToolStripMenuItem,
					this->topicToolStripMenuItem
			});
			this->aboutUsToolStripMenuItem->Name = L"aboutUsToolStripMenuItem";
			this->aboutUsToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->aboutUsToolStripMenuItem->Text = L"About";
			// 
			// membersToolStripMenuItem
			// 
			this->membersToolStripMenuItem->Name = L"membersToolStripMenuItem";
			this->membersToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->membersToolStripMenuItem->Text = L"Members";
			this->membersToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::membersToolStripMenuItem_Click);
			// 
			// topicToolStripMenuItem
			// 
			this->topicToolStripMenuItem->Name = L"topicToolStripMenuItem";
			this->topicToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->topicToolStripMenuItem->Text = L"Topic";
			this->topicToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::topicToolStripMenuItem_Click);
			// 
			// historyToolStripMenuItem1
			// 
			this->historyToolStripMenuItem1->Name = L"historyToolStripMenuItem1";
			this->historyToolStripMenuItem1->Size = System::Drawing::Size(140, 22);
			this->historyToolStripMenuItem1->Text = L"History";
			this->historyToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::historyToolStripMenuItem1_Click);
			// 
			// historyToolStripMenuItem
			// 
			this->historyToolStripMenuItem->Checked = true;
			this->historyToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->historyToolStripMenuItem->Name = L"historyToolStripMenuItem";
			this->historyToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->historyToolStripMenuItem->Text = L"History";
			this->historyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::historyToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 22);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 22);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(140, 162);
			this->btnDelete->Margin = System::Windows::Forms::Padding(2);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(36, 29);
			this->btnDelete->TabIndex = 1;
			this->btnDelete->Text = L"DEL";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Form1::btnDelete_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAdd->Location = System::Drawing::Point(140, 195);
			this->buttonAdd->Margin = System::Windows::Forms::Padding(2);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(36, 29);
			this->buttonAdd->TabIndex = 2;
			this->buttonAdd->Text = L"+";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonSub
			// 
			this->buttonSub->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSub->Location = System::Drawing::Point(140, 227);
			this->buttonSub->Margin = System::Windows::Forms::Padding(2);
			this->buttonSub->Name = L"buttonSub";
			this->buttonSub->Size = System::Drawing::Size(36, 29);
			this->buttonSub->TabIndex = 3;
			this->buttonSub->Text = L"-";
			this->buttonSub->UseVisualStyleBackColor = true;
			this->buttonSub->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonMul
			// 
			this->buttonMul->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonMul->Location = System::Drawing::Point(140, 260);
			this->buttonMul->Margin = System::Windows::Forms::Padding(2);
			this->buttonMul->Name = L"buttonMul";
			this->buttonMul->Size = System::Drawing::Size(36, 29);
			this->buttonMul->TabIndex = 4;
			this->buttonMul->Text = L"*";
			this->buttonMul->UseVisualStyleBackColor = true;
			this->buttonMul->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonDiv
			// 
			this->buttonDiv->Location = System::Drawing::Point(140, 292);
			this->buttonDiv->Margin = System::Windows::Forms::Padding(2);
			this->buttonDiv->Name = L"buttonDiv";
			this->buttonDiv->Size = System::Drawing::Size(36, 29);
			this->buttonDiv->TabIndex = 5;
			this->buttonDiv->Text = L"/";
			this->buttonDiv->UseVisualStyleBackColor = true;
			this->buttonDiv->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// btnResult
			// 
			this->btnResult->Location = System::Drawing::Point(140, 324);
			this->btnResult->Margin = System::Windows::Forms::Padding(2);
			this->btnResult->Name = L"btnResult";
			this->btnResult->Size = System::Drawing::Size(36, 29);
			this->btnResult->TabIndex = 6;
			this->btnResult->Text = L"=";
			this->btnResult->UseVisualStyleBackColor = true;
			this->btnResult->Click += gcnew System::EventHandler(this, &Form1::btnResult_Click);
			// 
			// btnBackspace
			// 
			this->btnBackspace->Location = System::Drawing::Point(100, 162);
			this->btnBackspace->Margin = System::Windows::Forms::Padding(2);
			this->btnBackspace->Name = L"btnBackspace";
			this->btnBackspace->Size = System::Drawing::Size(36, 29);
			this->btnBackspace->TabIndex = 7;
			this->btnBackspace->Text = L"AC";
			this->btnBackspace->UseVisualStyleBackColor = true;
			this->btnBackspace->Click += gcnew System::EventHandler(this, &Form1::btnBackspace_Click);
			// 
			// buttonNum3
			// 
			this->buttonNum3->Location = System::Drawing::Point(100, 195);
			this->buttonNum3->Margin = System::Windows::Forms::Padding(2);
			this->buttonNum3->Name = L"buttonNum3";
			this->buttonNum3->Size = System::Drawing::Size(36, 29);
			this->buttonNum3->TabIndex = 8;
			this->buttonNum3->Text = L"3";
			this->buttonNum3->UseVisualStyleBackColor = true;
			this->buttonNum3->Click += gcnew System::EventHandler(this, &Form1::btn_So);
			// 
			// buttonNum9
			// 
			this->buttonNum9->Location = System::Drawing::Point(100, 260);
			this->buttonNum9->Margin = System::Windows::Forms::Padding(2);
			this->buttonNum9->Name = L"buttonNum9";
			this->buttonNum9->Size = System::Drawing::Size(36, 29);
			this->buttonNum9->TabIndex = 10;
			this->buttonNum9->Text = L"9";
			this->buttonNum9->UseVisualStyleBackColor = true;
			this->buttonNum9->Click += gcnew System::EventHandler(this, &Form1::btn_So);
			// 
			// buttonNum6
			// 
			this->buttonNum6->Location = System::Drawing::Point(100, 227);
			this->buttonNum6->Margin = System::Windows::Forms::Padding(2);
			this->buttonNum6->Name = L"buttonNum6";
			this->buttonNum6->Size = System::Drawing::Size(36, 29);
			this->buttonNum6->TabIndex = 9;
			this->buttonNum6->Text = L"6";
			this->buttonNum6->UseVisualStyleBackColor = true;
			this->buttonNum6->Click += gcnew System::EventHandler(this, &Form1::btn_So);
			// 
			// btnCham
			// 
			this->btnCham->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCham->Location = System::Drawing::Point(100, 292);
			this->btnCham->Margin = System::Windows::Forms::Padding(2);
			this->btnCham->Name = L"btnCham";
			this->btnCham->Size = System::Drawing::Size(36, 29);
			this->btnCham->TabIndex = 11;
			this->btnCham->Text = L".";
			this->btnCham->UseVisualStyleBackColor = true;
			this->btnCham->Click += gcnew System::EventHandler(this, &Form1::btnCham_Click);
			// 
			// btnSoPi
			// 
			this->btnSoPi->Enabled = false;
			this->btnSoPi->Location = System::Drawing::Point(100, 325);
			this->btnSoPi->Margin = System::Windows::Forms::Padding(1);
			this->btnSoPi->Name = L"btnSoPi";
			this->btnSoPi->Size = System::Drawing::Size(36, 29);
			this->btnSoPi->TabIndex = 12;
			this->btnSoPi->Text = L"π";
			this->btnSoPi->UseVisualStyleBackColor = true;
			this->btnSoPi->Click += gcnew System::EventHandler(this, &Form1::btnSoPi_Click);
			// 
			// shiftRight
			// 
			this->shiftRight->Location = System::Drawing::Point(60, 162);
			this->shiftRight->Margin = System::Windows::Forms::Padding(2);
			this->shiftRight->Name = L"shiftRight";
			this->shiftRight->Size = System::Drawing::Size(36, 29);
			this->shiftRight->TabIndex = 13;
			this->shiftRight->Text = L">>";
			this->shiftRight->UseVisualStyleBackColor = true;
			//this->shiftRight->Click += gcnew System::EventHandler(this, &Form1::ShiftRight_Operator);
			this->shiftRight->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonNum2
			// 
			this->buttonNum2->Location = System::Drawing::Point(60, 195);
			this->buttonNum2->Margin = System::Windows::Forms::Padding(2);
			this->buttonNum2->Name = L"buttonNum2";
			this->buttonNum2->Size = System::Drawing::Size(36, 29);
			this->buttonNum2->TabIndex = 14;
			this->buttonNum2->Text = L"2";
			this->buttonNum2->UseVisualStyleBackColor = true;
			this->buttonNum2->Click += gcnew System::EventHandler(this, &Form1::btn_So);
			// 
			// buttonNum8
			// 
			this->buttonNum8->Location = System::Drawing::Point(60, 260);
			this->buttonNum8->Margin = System::Windows::Forms::Padding(2);
			this->buttonNum8->Name = L"buttonNum8";
			this->buttonNum8->Size = System::Drawing::Size(36, 29);
			this->buttonNum8->TabIndex = 16;
			this->buttonNum8->Text = L"8";
			this->buttonNum8->UseVisualStyleBackColor = true;
			this->buttonNum8->Click += gcnew System::EventHandler(this, &Form1::btn_So);
			// 
			// buttonNum5
			// 
			this->buttonNum5->Location = System::Drawing::Point(60, 227);
			this->buttonNum5->Margin = System::Windows::Forms::Padding(2);
			this->buttonNum5->Name = L"buttonNum5";
			this->buttonNum5->Size = System::Drawing::Size(36, 29);
			this->buttonNum5->TabIndex = 15;
			this->buttonNum5->Text = L"5";
			this->buttonNum5->UseVisualStyleBackColor = true;
			this->buttonNum5->Click += gcnew System::EventHandler(this, &Form1::btn_So);
			// 
			// buttonNum0
			// 
			this->buttonNum0->Location = System::Drawing::Point(60, 292);
			this->buttonNum0->Margin = System::Windows::Forms::Padding(2);
			this->buttonNum0->Name = L"buttonNum0";
			this->buttonNum0->Size = System::Drawing::Size(36, 29);
			this->buttonNum0->TabIndex = 17;
			this->buttonNum0->Text = L"0";
			this->buttonNum0->UseVisualStyleBackColor = true;
			this->buttonNum0->Click += gcnew System::EventHandler(this, &Form1::btn_So);
			// 
			// btnExp
			// 
			this->btnExp->Enabled = false;
			this->btnExp->Location = System::Drawing::Point(60, 325);
			this->btnExp->Margin = System::Windows::Forms::Padding(1);
			this->btnExp->Name = L"btnExp";
			this->btnExp->Size = System::Drawing::Size(36, 29);
			this->btnExp->TabIndex = 18;
			this->btnExp->Text = L"e";
			this->btnExp->UseVisualStyleBackColor = true;
			this->btnExp->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// shiftLeft
			// 
			this->shiftLeft->Location = System::Drawing::Point(20, 162);
			this->shiftLeft->Margin = System::Windows::Forms::Padding(2);
			this->shiftLeft->Name = L"shiftLeft";
			this->shiftLeft->Size = System::Drawing::Size(36, 29);
			this->shiftLeft->TabIndex = 19;
			this->shiftLeft->Text = L"<<";
			this->shiftLeft->UseVisualStyleBackColor = true;
			//this->shiftLeft->Click += gcnew System::EventHandler(this, &Form1::ShiftLeft_Operator);
			this->shiftLeft->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonNum1
			// 
			this->buttonNum1->Location = System::Drawing::Point(20, 195);
			this->buttonNum1->Margin = System::Windows::Forms::Padding(2);
			this->buttonNum1->Name = L"buttonNum1";
			this->buttonNum1->Size = System::Drawing::Size(36, 29);
			this->buttonNum1->TabIndex = 20;
			this->buttonNum1->Text = L"1";
			this->buttonNum1->UseVisualStyleBackColor = true;
			this->buttonNum1->Click += gcnew System::EventHandler(this, &Form1::btn_So);
			// 
			// buttonNum4
			// 
			this->buttonNum4->Location = System::Drawing::Point(20, 227);
			this->buttonNum4->Margin = System::Windows::Forms::Padding(2);
			this->buttonNum4->Name = L"buttonNum4";
			this->buttonNum4->Size = System::Drawing::Size(36, 29);
			this->buttonNum4->TabIndex = 21;
			this->buttonNum4->Text = L"4";
			this->buttonNum4->UseVisualStyleBackColor = true;
			this->buttonNum4->Click += gcnew System::EventHandler(this, &Form1::btn_So);
			// 
			// buttonNum7
			// 
			this->buttonNum7->Location = System::Drawing::Point(20, 260);
			this->buttonNum7->Margin = System::Windows::Forms::Padding(2);
			this->buttonNum7->Name = L"buttonNum7";
			this->buttonNum7->Size = System::Drawing::Size(36, 29);
			this->buttonNum7->TabIndex = 22;
			this->buttonNum7->Text = L"7";
			this->buttonNum7->UseVisualStyleBackColor = true;
			this->buttonNum7->Click += gcnew System::EventHandler(this, &Form1::btn_So);
			// 
			// btnAmDuong
			// 
			this->btnAmDuong->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAmDuong->Location = System::Drawing::Point(20, 292);
			this->btnAmDuong->Margin = System::Windows::Forms::Padding(2);
			this->btnAmDuong->Name = L"btnAmDuong";
			this->btnAmDuong->Size = System::Drawing::Size(36, 29);
			this->btnAmDuong->TabIndex = 23;
			this->btnAmDuong->Text = L"±";
			this->btnAmDuong->UseVisualStyleBackColor = true;
			this->btnAmDuong->Click += gcnew System::EventHandler(this, &Form1::btnAmDuong_Click);
			// 
			// btnAns
			// 
			this->btnAns->Location = System::Drawing::Point(20, 325);
			this->btnAns->Margin = System::Windows::Forms::Padding(2);
			this->btnAns->Name = L"btnAns";
			this->btnAns->Size = System::Drawing::Size(36, 29);
			this->btnAns->TabIndex = 24;
			this->btnAns->Text = L"Ans";
			this->btnAns->UseVisualStyleBackColor = true;
			this->btnAns->Click += gcnew System::EventHandler(this, &Form1::DisplayAns);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(533, 7);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(431, 299);
			this->panel1->TabIndex = 50;
			// 
			// txtDisplay
			// 
			this->txtDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDisplay->Location = System::Drawing::Point(21, 48);
			this->txtDisplay->Margin = System::Windows::Forms::Padding(2);
			this->txtDisplay->Multiline = true;
			this->txtDisplay->Name = L"txtDisplay";
			this->txtDisplay->Size = System::Drawing::Size(157, 57);
			this->txtDisplay->TabIndex = 51;
			this->txtDisplay->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txtDisplay->TextChanged += gcnew System::EventHandler(this, &Form1::txtDisplay_TextChanged);
			// 
			// grbName
			// 
			this->grbName->BackColor = System::Drawing::Color::LemonChiffon;
			this->grbName->Controls->Add(this->lblHeCoSo);
			this->grbName->Controls->Add(this->lblShowOp);
			this->grbName->Controls->Add(this->buttonMod);
			this->grbName->Controls->Add(this->btnHexBase);
			this->grbName->Controls->Add(this->btnDecBase);
			this->grbName->Controls->Add(this->txtDisplay);
			this->grbName->Controls->Add(this->panel1);
			this->grbName->Controls->Add(this->btnBinBase);
			this->grbName->Controls->Add(this->buttonToBin);
			this->grbName->Controls->Add(this->buttonToHex);
			this->grbName->Controls->Add(this->buttonToDec);
			this->grbName->Controls->Add(this->buttonLess);
			this->grbName->Controls->Add(this->buttonLessEqual);
			this->grbName->Controls->Add(this->buttonEqual);
			this->grbName->Controls->Add(this->buttonGreaterEqual);
			this->grbName->Controls->Add(this->buttonGreater);
			this->grbName->Controls->Add(this->buttonRol);
			this->grbName->Controls->Add(this->buttonRor);
			this->grbName->Controls->Add(this->buttonNot);
			this->grbName->Controls->Add(this->buttonXor);
			this->grbName->Controls->Add(this->buttonOr);
			this->grbName->Controls->Add(this->buttonAnd);
			this->grbName->Controls->Add(this->buttonF);
			this->grbName->Controls->Add(this->buttonE);
			this->grbName->Controls->Add(this->buttonD);
			this->grbName->Controls->Add(this->buttonC);
			this->grbName->Controls->Add(this->buttonB);
			this->grbName->Controls->Add(this->buttonA);
			this->grbName->Controls->Add(this->btnAns);
			this->grbName->Controls->Add(this->btnAmDuong);
			this->grbName->Controls->Add(this->buttonNum7);
			this->grbName->Controls->Add(this->buttonNum4);
			this->grbName->Controls->Add(this->buttonNum1);
			this->grbName->Controls->Add(this->shiftLeft);
			this->grbName->Controls->Add(this->btnExp);
			this->grbName->Controls->Add(this->buttonNum0);
			this->grbName->Controls->Add(this->buttonNum5);
			this->grbName->Controls->Add(this->buttonNum8);
			this->grbName->Controls->Add(this->buttonNum2);
			this->grbName->Controls->Add(this->shiftRight);
			this->grbName->Controls->Add(this->btnSoPi);
			this->grbName->Controls->Add(this->btnCham);
			this->grbName->Controls->Add(this->buttonNum6);
			this->grbName->Controls->Add(this->buttonNum9);
			this->grbName->Controls->Add(this->buttonNum3);
			this->grbName->Controls->Add(this->btnBackspace);
			this->grbName->Controls->Add(this->btnResult);
			this->grbName->Controls->Add(this->buttonDiv);
			this->grbName->Controls->Add(this->buttonMul);
			this->grbName->Controls->Add(this->buttonSub);
			this->grbName->Controls->Add(this->buttonAdd);
			this->grbName->Controls->Add(this->btnDelete);
			this->grbName->Controls->Add(this->menuStrip1);
			this->grbName->Location = System::Drawing::Point(2, 1);
			this->grbName->Margin = System::Windows::Forms::Padding(2);
			this->grbName->Name = L"grbName";
			this->grbName->Padding = System::Windows::Forms::Padding(2);
			this->grbName->Size = System::Drawing::Size(459, 374);
			this->grbName->TabIndex = 49;
			this->grbName->TabStop = false;
			this->grbName->Enter += gcnew System::EventHandler(this, &Form1::grbName_Enter);
			// 
			// lblHeCoSo
			// 
			this->lblHeCoSo->BackColor = System::Drawing::Color::PaleTurquoise;
			this->lblHeCoSo->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblHeCoSo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHeCoSo->Location = System::Drawing::Point(20, 117);
			this->lblHeCoSo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblHeCoSo->Name = L"lblHeCoSo";
			this->lblHeCoSo->Size = System::Drawing::Size(43, 33);
			this->lblHeCoSo->TabIndex = 59;
			this->lblHeCoSo->Text = L"10";
			this->lblHeCoSo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblShowOp
			// 
			this->lblShowOp->BackColor = System::Drawing::Color::White;
			this->lblShowOp->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblShowOp->Location = System::Drawing::Point(67, 117);
			this->lblShowOp->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblShowOp->Name = L"lblShowOp";
			this->lblShowOp->Size = System::Drawing::Size(107, 33);
			this->lblShowOp->TabIndex = 58;
			this->lblShowOp->Text = L"0";
			this->lblShowOp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonMod
			// 
			this->buttonMod->Location = System::Drawing::Point(193, 325);
			this->buttonMod->Margin = System::Windows::Forms::Padding(2);
			this->buttonMod->Name = L"buttonMod";
			this->buttonMod->Size = System::Drawing::Size(36, 28);
			this->buttonMod->TabIndex = 55;
			this->buttonMod->Text = L"%";
			this->buttonMod->UseVisualStyleBackColor = true;
			this->buttonMod->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// btnHexBase
			// 
			this->btnHexBase->Location = System::Drawing::Point(327, 325);
			this->btnHexBase->Margin = System::Windows::Forms::Padding(2);
			this->btnHexBase->Name = L"btnHexBase";
			this->btnHexBase->Size = System::Drawing::Size(99, 28);
			this->btnHexBase->TabIndex = 54;
			this->btnHexBase->Text = L"Hexadecimal";
			this->btnHexBase->UseVisualStyleBackColor = true;
			this->btnHexBase->Click += gcnew System::EventHandler(this, &Form1::SetBase);
			// 
			// btnDecBase
			// 
			this->btnDecBase->Location = System::Drawing::Point(327, 292);
			this->btnDecBase->Margin = System::Windows::Forms::Padding(2);
			this->btnDecBase->Name = L"btnDecBase";
			this->btnDecBase->Size = System::Drawing::Size(99, 28);
			this->btnDecBase->TabIndex = 53;
			this->btnDecBase->Text = L"Decimal";
			this->btnDecBase->UseVisualStyleBackColor = true;
			this->btnDecBase->Click += gcnew System::EventHandler(this, &Form1::SetBase);
			// 
			// btnBinBase
			// 
			this->btnBinBase->Location = System::Drawing::Point(327, 260);
			this->btnBinBase->Margin = System::Windows::Forms::Padding(2);
			this->btnBinBase->Name = L"btnBinBase";
			this->btnBinBase->Size = System::Drawing::Size(99, 29);
			this->btnBinBase->TabIndex = 46;
			this->btnBinBase->Text = L"Binary";
			this->btnBinBase->UseVisualStyleBackColor = true;
			this->btnBinBase->Click += gcnew System::EventHandler(this, &Form1::SetBase);
			// 
			// buttonToBin
			// 
			this->buttonToBin->Location = System::Drawing::Point(327, 227);
			this->buttonToBin->Margin = System::Windows::Forms::Padding(2);
			this->buttonToBin->Name = L"buttonToBin";
			this->buttonToBin->Size = System::Drawing::Size(99, 29);
			this->buttonToBin->TabIndex = 45;
			this->buttonToBin->Text = L"To Bin";
			this->buttonToBin->UseVisualStyleBackColor = true;
			this->buttonToBin->Click += gcnew System::EventHandler(this, &Form1::ConvertToBin);
			// 
			// buttonToHex
			// 
			this->buttonToHex->Location = System::Drawing::Point(327, 195);
			this->buttonToHex->Margin = System::Windows::Forms::Padding(2);
			this->buttonToHex->Name = L"buttonToHex";
			this->buttonToHex->Size = System::Drawing::Size(99, 29);
			this->buttonToHex->TabIndex = 44;
			this->buttonToHex->Text = L"To Hex";
			this->buttonToHex->UseVisualStyleBackColor = true;
			this->buttonToHex->Click += gcnew System::EventHandler(this, &Form1::ConvertToHex);
			// 
			// buttonToDec
			// 
			this->buttonToDec->Location = System::Drawing::Point(327, 162);
			this->buttonToDec->Margin = System::Windows::Forms::Padding(2);
			this->buttonToDec->Name = L"buttonToDec";
			this->buttonToDec->Size = System::Drawing::Size(99, 29);
			this->buttonToDec->TabIndex = 43;
			this->buttonToDec->Text = L"To Dec";
			this->buttonToDec->UseVisualStyleBackColor = true;
			this->buttonToDec->Click += gcnew System::EventHandler(this, &Form1::ConvertToDec);
			// 
			// buttonLess
			// 
			this->buttonLess->Location = System::Drawing::Point(193, 260);
			this->buttonLess->Margin = System::Windows::Forms::Padding(2);
			this->buttonLess->Name = L"buttonLess";
			this->buttonLess->Size = System::Drawing::Size(36, 29);
			this->buttonLess->TabIndex = 41;
			this->buttonLess->Text = L"<";
			this->buttonLess->UseVisualStyleBackColor = true;
			this->buttonLess->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonLessEqual
			// 
			this->buttonLessEqual->Location = System::Drawing::Point(193, 292);
			this->buttonLessEqual->Margin = System::Windows::Forms::Padding(2);
			this->buttonLessEqual->Name = L"buttonLessEqual";
			this->buttonLessEqual->Size = System::Drawing::Size(36, 29);
			this->buttonLessEqual->TabIndex = 40;
			this->buttonLessEqual->Text = L"<=";
			this->buttonLessEqual->UseVisualStyleBackColor = true;
			this->buttonLessEqual->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonEqual
			// 
			this->buttonEqual->Location = System::Drawing::Point(193, 227);
			this->buttonEqual->Margin = System::Windows::Forms::Padding(2);
			this->buttonEqual->Name = L"buttonEqual";
			this->buttonEqual->Size = System::Drawing::Size(36, 29);
			this->buttonEqual->TabIndex = 39;
			this->buttonEqual->Text = L"==";
			this->buttonEqual->UseVisualStyleBackColor = true;
			this->buttonEqual->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonGreaterEqual
			// 
			this->buttonGreaterEqual->Location = System::Drawing::Point(193, 162);
			this->buttonGreaterEqual->Margin = System::Windows::Forms::Padding(2);
			this->buttonGreaterEqual->Name = L"buttonGreaterEqual";
			this->buttonGreaterEqual->Size = System::Drawing::Size(36, 29);
			this->buttonGreaterEqual->TabIndex = 38;
			this->buttonGreaterEqual->Text = L">=";
			this->buttonGreaterEqual->UseVisualStyleBackColor = true;
			this->buttonGreaterEqual->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonGreater
			// 
			this->buttonGreater->Location = System::Drawing::Point(193, 195);
			this->buttonGreater->Margin = System::Windows::Forms::Padding(2);
			this->buttonGreater->Name = L"buttonGreater";
			this->buttonGreater->Size = System::Drawing::Size(36, 29);
			this->buttonGreater->TabIndex = 37;
			this->buttonGreater->Text = L">";
			this->buttonGreater->UseVisualStyleBackColor = true;
			this->buttonGreater->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonRol
			// 
			this->buttonRol->Location = System::Drawing::Point(273, 325);
			this->buttonRol->Margin = System::Windows::Forms::Padding(2);
			this->buttonRol->Name = L"buttonRol";
			this->buttonRol->Size = System::Drawing::Size(51, 29);
			this->buttonRol->TabIndex = 36;
			this->buttonRol->Text = L"ROL";
			this->buttonRol->UseVisualStyleBackColor = true;
			this->buttonRol->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonRor
			// 
			this->buttonRor->Location = System::Drawing::Point(273, 292);
			this->buttonRor->Margin = System::Windows::Forms::Padding(2);
			this->buttonRor->Name = L"buttonRor";
			this->buttonRor->Size = System::Drawing::Size(51, 29);
			this->buttonRor->TabIndex = 35;
			this->buttonRor->Text = L"ROR";
			this->buttonRor->UseVisualStyleBackColor = true;
			this->buttonRor->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonNot
			// 
			this->buttonNot->Location = System::Drawing::Point(273, 260);
			this->buttonNot->Margin = System::Windows::Forms::Padding(2);
			this->buttonNot->Name = L"buttonNot";
			this->buttonNot->Size = System::Drawing::Size(51, 29);
			this->buttonNot->TabIndex = 34;
			this->buttonNot->Text = L"NOT";
			this->buttonNot->UseVisualStyleBackColor = true;
			this->buttonNot->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_NOT);
			// 
			// buttonXor
			// 
			this->buttonXor->Location = System::Drawing::Point(273, 227);
			this->buttonXor->Margin = System::Windows::Forms::Padding(2);
			this->buttonXor->Name = L"buttonXor";
			this->buttonXor->Size = System::Drawing::Size(51, 29);
			this->buttonXor->TabIndex = 33;
			this->buttonXor->Text = L"XOR";
			this->buttonXor->UseVisualStyleBackColor = true;
			this->buttonXor->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonOr
			// 
			this->buttonOr->Location = System::Drawing::Point(273, 195);
			this->buttonOr->Margin = System::Windows::Forms::Padding(2);
			this->buttonOr->Name = L"buttonOr";
			this->buttonOr->Size = System::Drawing::Size(51, 29);
			this->buttonOr->TabIndex = 32;
			this->buttonOr->Text = L"OR";
			this->buttonOr->UseVisualStyleBackColor = true;
			this->buttonOr->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonAnd
			// 
			this->buttonAnd->Location = System::Drawing::Point(273, 162);
			this->buttonAnd->Margin = System::Windows::Forms::Padding(2);
			this->buttonAnd->Name = L"buttonAnd";
			this->buttonAnd->Size = System::Drawing::Size(51, 29);
			this->buttonAnd->TabIndex = 31;
			this->buttonAnd->Text = L"AND";
			this->buttonAnd->UseVisualStyleBackColor = true;
			this->buttonAnd->Click += gcnew System::EventHandler(this, &Form1::Arithmetic_Op);
			// 
			// buttonF
			// 
			this->buttonF->Location = System::Drawing::Point(233, 325);
			this->buttonF->Margin = System::Windows::Forms::Padding(2);
			this->buttonF->Name = L"buttonF";
			this->buttonF->Size = System::Drawing::Size(36, 29);
			this->buttonF->TabIndex = 30;
			this->buttonF->Text = L"F";
			this->buttonF->UseVisualStyleBackColor = true;
			this->buttonF->Click += gcnew System::EventHandler(this, &Form1::btnAlpha);
			// 
			// buttonE
			// 
			this->buttonE->Location = System::Drawing::Point(233, 292);
			this->buttonE->Margin = System::Windows::Forms::Padding(2);
			this->buttonE->Name = L"buttonE";
			this->buttonE->Size = System::Drawing::Size(36, 29);
			this->buttonE->TabIndex = 29;
			this->buttonE->Text = L"E";
			this->buttonE->UseVisualStyleBackColor = true;
			this->buttonE->Click += gcnew System::EventHandler(this, &Form1::btnAlpha);
			// 
			// buttonD
			// 
			this->buttonD->Location = System::Drawing::Point(233, 260);
			this->buttonD->Margin = System::Windows::Forms::Padding(2);
			this->buttonD->Name = L"buttonD";
			this->buttonD->Size = System::Drawing::Size(36, 29);
			this->buttonD->TabIndex = 28;
			this->buttonD->Text = L"D";
			this->buttonD->UseVisualStyleBackColor = true;
			this->buttonD->Click += gcnew System::EventHandler(this, &Form1::btnAlpha);
			// 
			// buttonC
			// 
			this->buttonC->Location = System::Drawing::Point(233, 227);
			this->buttonC->Margin = System::Windows::Forms::Padding(2);
			this->buttonC->Name = L"buttonC";
			this->buttonC->Size = System::Drawing::Size(36, 29);
			this->buttonC->TabIndex = 27;
			this->buttonC->Text = L"C";
			this->buttonC->UseVisualStyleBackColor = true;
			this->buttonC->Click += gcnew System::EventHandler(this, &Form1::btnAlpha);
			// 
			// buttonB
			// 
			this->buttonB->Location = System::Drawing::Point(233, 195);
			this->buttonB->Margin = System::Windows::Forms::Padding(2);
			this->buttonB->Name = L"buttonB";
			this->buttonB->Size = System::Drawing::Size(36, 29);
			this->buttonB->TabIndex = 26;
			this->buttonB->Text = L"B";
			this->buttonB->UseVisualStyleBackColor = true;
			this->buttonB->Click += gcnew System::EventHandler(this, &Form1::btnAlpha);
			// 
			// buttonA
			// 
			this->buttonA->Location = System::Drawing::Point(233, 162);
			this->buttonA->Margin = System::Windows::Forms::Padding(2);
			this->buttonA->Name = L"buttonA";
			this->buttonA->Size = System::Drawing::Size(36, 29);
			this->buttonA->TabIndex = 25;
			this->buttonA->Text = L"A";
			this->buttonA->UseVisualStyleBackColor = true;
			this->buttonA->Click += gcnew System::EventHandler(this, &Form1::btnAlpha);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(2, 382);
			this->listBox1->Margin = System::Windows::Forms::Padding(2);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(462, 264);
			this->listBox1->TabIndex = 53;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(978, 653);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->grbName);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form1";
			this->Opacity = 0.95;
			this->Text = L"Project Calc";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Click += gcnew System::EventHandler(this, &Form1::btnAlpha);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->grbName->ResumeLayout(false);
			this->grbName->PerformLayout();
			this->ResumeLayout(false);

		}
		
#pragma endregion
		double ifirstnum;
		double isecondnum;
		double iresult;

		bool caculous;
		bool buttonPressed;
		short base;
		bool isFloat;
		bool isOperatorNOT;
		System::String^ ifirst;
		System::String^ isecond;
		System::String^ ans;


		double a;
		String^ ioperation;
		float Celsius, Farenheit, kevin;
		char operation;

private: System::Void btnCham_Click(System::Object^ sender, System::EventArgs^ e) {
	this->isFloat = true;
	if (txtDisplay->Text == "")
	{
		txtDisplay->Text = "0.";
	}
	if (!txtDisplay->Text->Contains("."))
	{
		txtDisplay->Text = txtDisplay->Text + ".";
	}

	this->turnOffOperator();
	this->buttonNot->Enabled = false;
	this->btnCham->Enabled = false;
	this->btnResult->Enabled = false;
	this->turnOnBaseConvert();
}
private: System::Void btnBackspace_Click(System::Object^ sender, System::EventArgs^ e) {
	// button AC
	if (txtDisplay->Text->Length > 0)
	{
		if(txtDisplay->Text->EndsWith(".")) this->btnCham->Enabled = true;
		
		txtDisplay->Text = txtDisplay->Text->Remove(txtDisplay->Text->Length - 1, 1);
	}
}
private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	//button DEL
	//txtDisplay->Clear();
	txtDisplay->Text = "";
	lblShowOp->Text = "";

	this->ifirst = "0";
	this->isecond = "0";
	this->ioperation = "+";
	this->isOperatorNOT = false;
	this->isFloat = false;

	this->turnOffOperator();

	this->btnCham->Enabled = true;
	this->buttonPressed = false;
	this->btnResult->Enabled = true;
	this->buttonNot->Enabled = true;

	this->setBase();

}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	Form1::Width = 210;
	Form1::Height = 400;
	lblShowOp->Width = 100;
	txtDisplay->Width = 150;
	historyToolStripMenuItem->Visible = false;
}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//File-->exit: thoat ung dung
	Application::Exit();
}
private: System::Void scientificToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// file--> scientific : che do scientific
	Form1::Width = 480;
	lblShowOp->Width = 375;
	txtDisplay->Width = 420;
}
private: System::Void temperatureToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//file--> temperature: che do temperature
	Form1::Width = 900;
	lblShowOp->Width = 375;
	txtDisplay->Width = 420;
}
private: System::Void standardToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//file--> standard: che do standard
	Form1::Width = 210;
	lblShowOp->Width = 100;
	txtDisplay->Width = 150;
	historyToolStripMenuItem->Visible = false;
}
	private: System::Void btn_So(System::Object^ sender, System::EventArgs^ e) {
		this->buttonPressed = true;
		// hien thi so len man hinh
		Button^ Numbers = safe_cast<Button^>(sender);
		if (txtDisplay->Text=="0" || (this->caculous))
		{
			txtDisplay->Text = Numbers->Text;
			this->caculous = false;
		}
		else
		{
			txtDisplay->Text = txtDisplay->Text + Numbers->Text;
		}


		this->turnOnOperator();
		this->turnOffBase();
		this->turnOnBaseConvert();
	}
	private: System::Void DisplayAns(System::Object^ sender, System::EventArgs^ e) {
		// hien thi cu len man hinh
		Button^ Numbers = safe_cast<Button^>(sender);

		if (txtDisplay->Text == "" || txtDisplay->Text == "0")
		{
			txtDisplay->Text = this->ans;
		}
		else
		{
		}
	}
	private: System::Void Arithmetic_NOT(System::Object^ sender, System::EventArgs^ e) {
		if (lblShowOp->Text == "0") lblShowOp->Text = safe_cast<Button^>(sender)->Text;
		else lblShowOp->Text += " " + safe_cast<Button^>(sender)->Text;
		this->isOperatorNOT = !(this->isOperatorNOT);
	}
		   
private: System::Void Arithmetic_Op(System::Object^ sender, System::EventArgs^ e) {
	this->buttonPressed = false;
	// hien thi phep toan +/-/*/chia
	Button^ Op = safe_cast<Button^>(sender);

	//ifirstnum = double::Parse(txtDisplay->Text);
	if (ifirst == "0")
	{
		ifirst = txtDisplay->Text;
		txtDisplay->Text = "";
		ioperation = Op->Text;
		//lblShowOp->Text = System::Convert::ToString(ifirstnum) + " " + ioperation;
		lblShowOp->Text = ifirst + " " + ioperation;
		
	}
	else
	{
		this->ifirst = this->Calculate();
		//txtDisplay->Text = this->ans;
		txtDisplay->Text = "";
		ioperation = Op->Text;
		lblShowOp->Text = this->ans + " " + ioperation;
	}

	this->turnOffOperator();
	this->turnOffConvert();
	this->btnCham->Enabled = false;
}
private: System::Void btnAmDuong_Click(System::Object^ sender, System::EventArgs^ e) {
	// hien thi so Am Duong
	if (txtDisplay->Text->Contains("-"))
	{
		txtDisplay->Text = txtDisplay->Text->Remove(0,1);
	}
	else
	{
		txtDisplay->Text = "-" + txtDisplay->Text;
	}
}
private: System::Void btnResult_Click(System::Object^ sender, System::EventArgs^ e) {
	
	txtDisplay->Text = this->Calculate();
	
	// luu phep tinh vao listBox de lam History
	/*listBox1->Items->Add(System::Convert::ToString(ifirstnum) + " " + ioperation + " " + System::Convert::ToString(isecondnum));
	listBox1->Items->Add(System::Convert::ToString(txtDisplay->Text));*/
	listBox1->Items->Add(ifirst + " " + ioperation + " " + isecond);
	listBox1->Items->Add(System::Convert::ToString(txtDisplay->Text));

	lblShowOp->Text = ifirst + " " + ioperation + " " + isecond;

	this->isecond = "0";
	this->ifirst = "0";
	this->ioperation = "+"; // clear operator
	this->caculous = true;
}
private: System::Void historyToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	//an history
		 historyToolStripMenuItem->Visible = true;
		 listBox1->Width = 265;
		 listBox1->Visible = false;
		 historyToolStripMenuItem1->Visible = false;

	   }
private: System::Void historyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//hien history
	if (historyToolStripMenuItem->Checked == true)
	{
		listBox1->Visible = true;
		historyToolStripMenuItem->Visible = false;
		historyToolStripMenuItem1->Visible = true;
		Form1::Height = 700;
	}
}

private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnAlpha(System::Object^ sender, System::EventArgs^ e) {
	this->buttonPressed = true;
	//hien thi cac phim A/B/C/D/E/F len man hinh
	Button^ Alpha = safe_cast<Button^>(sender);
	if (txtDisplay->Text == "0" || (this->caculous))
	{
		txtDisplay->Text = Alpha->Text;
		this->caculous = false;
	}
	else
	{
		txtDisplay->Text = txtDisplay->Text + Alpha->Text;
	}

	this->turnOnOperator();
	this->turnOffBase();
	this->turnOnBaseConvert();

}
private: System::Void grbName_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnMod_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void btnBinary_Click(System::Object^ sender, System::EventArgs^ e) {
	// Dec to Bin
	int a = int::Parse(txtDisplay->Text);
	txtDisplay->Text = System::Convert::ToString(a, 2);
	lblShowOp->Text = "";
}
private: System::Void btnHex_Click(System::Object^ sender, System::EventArgs^ e) {
	// Dec to Hex
	int a = int::Parse(txtDisplay->Text);
	txtDisplay->Text = System::Convert::ToString(a, 16);
	lblShowOp->Text = "";
}
private: System::Void btnOct_Click(System::Object^ sender, System::EventArgs^ e) {
	//Dec to Oct
	int a = int::Parse(txtDisplay->Text);
	txtDisplay->Text = System::Convert::ToString(a, 8);
	lblShowOp->Text = "";
}

private: System::Void btnSoPi_Click(System::Object^ sender, System::EventArgs^ e) {
	txtDisplay->Text = ("3.14");
}
private: System::Void membersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ s = "Duong Boi Long 18120200 ; Nguyen Tran Ai Nguyen 18120217, Dang Do Huynh Nhu 18120219, Nguyen Dien Thanh Phong 18120221, Tran Xuan Quy 18120231";
	MessageBox::Show(s);
}
private: System::Void topicToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ s = "Do An 1: Bieu dien va tinh toan so hoc tren may tinh. Lop 18-2";
	MessageBox::Show(s);
}
private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
	// Dec to Bin
	int a = int::Parse(txtDisplay->Text);
	txtDisplay->Text = System::Convert::ToString(a, 2);
	lblShowOp->Text = "";
}
private: System::Void btnDecToHex_Click(System::Object^ sender, System::EventArgs^ e) {
	// Dec to Hex
	int a = int::Parse(txtDisplay->Text);
	txtDisplay->Text = System::Convert::ToString(a, 16);
	lblShowOp->Text = "";
}
	private: System::Void ShiftLeft_Operator(System::Object^ sender, System::EventArgs^ e) {
		// shift left
		Button^ Op = safe_cast<Button^>(sender);
		this->ifirst = txtDisplay->Text;
		txtDisplay->Text = "";
		ioperation = Op->Text;
		lblShowOp->Text = ifirst + " " + ioperation;
	}
	private: System::Void ShiftRight_Operator(System::Object^ sender, System::EventArgs^ e) {
		// shift right
		Button^ Op = safe_cast<Button^>(sender);
		this->ifirst = txtDisplay->Text;
		txtDisplay->Text = "";
		ioperation = Op->Text;
		lblShowOp->Text = ifirst + " " + ioperation;
	}
	private: System::Void SetBase(System::Object^ sender, System::EventArgs^ e) {
		Button^ Op = safe_cast<Button^>(sender);
		if (Op->Text == "Binary")
		{
			this->base = 2;

			//this->ModeBinary();
			lblHeCoSo->Text = "2";

		}
		else if (Op->Text == "Decimal")
		{
			this->base = 10;

			//this->ModeDecimal();
			lblHeCoSo->Text = "10";

		}
		else if (Op->Text == "Hexadecimal")
		{
			this->base = 16;

			//this->ModeHexdecimal();
			lblHeCoSo->Text = "16";

		}
		else
		{
			txtDisplay->Text = "ERROR BASE!";
			lblHeCoSo->Text = "ERROR";
			return;
		}

		txtDisplay->Text = "";
		lblShowOp->Text = "";
		ifirst = "0";
		isecond = "0";
		ioperation = "+";

		this->setBase();
	}
	private: System::Void ConvertToBin(System::Object^ sender, System::EventArgs^ e) {
		/*txtDisplay->Text = "Bin";
		return;*/
		std::stringstream sstr;

		if (this->caculous == false)	// chua xuat ket qua
		{
			this->ans = txtDisplay->Text;
			lblShowOp->Text = txtDisplay->Text;
			this->caculous = true;
		}
		else
		{
			lblShowOp->Text = this->ans;
		}

		std::string str = toStandardString(this->ans);

		sstr << base << "$" << 2 << "$" << str;
		sstr >> str;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] == '$') str[i] = ' ';
		}
		if (this->isFloat)
		{
			str = convert_1_string_qfloat(str);
		}
		else str = scanQIntQues(str);
		if (str == "")
		{
			str = "0";
		}

		txtDisplay->Text = gcnew String(str.c_str());
		this->isecond = "0";
		this->ifirst = "0";
		this->ioperation = "+";
		this->caculous = true;
	}
	private: System::Void ConvertToHex(System::Object^ sender, System::EventArgs^ e) {
		/*txtDisplay->Text = "Hex";
		return;*/
		std::stringstream sstr;

		if (this->caculous == false)	// chua xuat ket qua
		{
			this->ans = txtDisplay->Text;
			lblShowOp->Text = txtDisplay->Text;
			this->caculous = true;
		}
		else
		{
			lblShowOp->Text = this->ans;
		}

		std::string str = toStandardString(this->ans);

		sstr << base << "$" << 16 << "$" << str;
		sstr >> str;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] == '$') str[i] = ' ';
		}
		str = scanQIntQues(str);
		if (str == "")
		{
			str = "0";
		}

		txtDisplay->Text = gcnew String(str.c_str());
		this->isecond = "";
		this->ifirst = "";
		this->caculous = true;
	}
	private: System::Void ConvertToDec(System::Object^ sender, System::EventArgs^ e) {
		/*txtDisplay->Text = "Dec";
		return;*/
		std::stringstream sstr;

		if (this->caculous == false)	// chua xuat ket qua
		{
			this->ans = txtDisplay->Text;
			this->caculous = true;
			lblShowOp->Text = txtDisplay->Text;
		}
		else
		{
			lblShowOp->Text = this->ans;
		}

		std::string str = toStandardString(this->ans);

		sstr << base << "$" << 10 << "$" << str;
		sstr >> str;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] == '$') str[i] = ' ';
		}
		if (this->isFloat)
		{
			str = convert_1_string_qfloat(str);
		}
		else str = scanQIntQues(str);
		if (str == "")
		{
			str = "0";
		}

		txtDisplay->Text = gcnew String(str.c_str());
		this->isecond = "";
		this->ifirst = "";
		this->caculous = true;
	}
	private: System::Void ModeDecimal() {
		this->buttonNum0->Enabled = true;
		this->buttonNum1->Enabled = true;
		this->buttonNum2->Enabled = true;
		this->buttonNum3->Enabled = true;
		this->buttonNum4->Enabled = true;
		this->buttonNum5->Enabled = true;
		this->buttonNum6->Enabled = true;
		this->buttonNum7->Enabled = true;
		this->buttonNum8->Enabled = true;
		this->buttonNum9->Enabled = true;
		this->buttonA->Enabled = false;
		this->buttonB->Enabled = false;
		this->buttonC->Enabled = false;
		this->buttonD->Enabled = false;
		this->buttonE->Enabled = false;
		this->buttonF->Enabled = false;
		this->btnCham->Enabled = true;

		this->buttonToHex->Enabled = true;
		this->buttonToDec->Enabled = false;
		this->buttonToBin->Enabled = true;

		this->btnDecBase->Enabled = false;
		this->btnBinBase->Enabled = true;
		this->btnHexBase->Enabled = true;
	}
	private: System::Void ModeBinary() {
		this->buttonNum0->Enabled = true;
		this->buttonNum1->Enabled = true;
		this->buttonNum2->Enabled = false;
		this->buttonNum3->Enabled = false;
		this->buttonNum4->Enabled = false;
		this->buttonNum5->Enabled = false;
		this->buttonNum6->Enabled = false;
		this->buttonNum7->Enabled = false;
		this->buttonNum8->Enabled = false;
		this->buttonNum9->Enabled = false;
		this->buttonA->Enabled = false;
		this->buttonB->Enabled = false;
		this->buttonC->Enabled = false;
		this->buttonD->Enabled = false;
		this->buttonE->Enabled = false;
		this->buttonF->Enabled = false;
		this->btnCham->Enabled = true;

		this->buttonToHex->Enabled = true;
		this->buttonToDec->Enabled = true;
		this->buttonToBin->Enabled = false;

		this->btnDecBase->Enabled = true;
		this->btnBinBase->Enabled = false;
		this->btnHexBase->Enabled = true;

	}
	private: System::Void ModeHexdecimal() {
		this->buttonNum0->Enabled = true;
		this->buttonNum1->Enabled = true;
		this->buttonNum2->Enabled = true;
		this->buttonNum3->Enabled = true;
		this->buttonNum4->Enabled = true;
		this->buttonNum5->Enabled = true;
		this->buttonNum6->Enabled = true;
		this->buttonNum7->Enabled = true;
		this->buttonNum8->Enabled = true;
		this->buttonNum9->Enabled = true;
		this->buttonA->Enabled = true;
		this->buttonB->Enabled = true;
		this->buttonC->Enabled = true;
		this->buttonD->Enabled = true;
		this->buttonE->Enabled = true;
		this->buttonF->Enabled = true;
		this->btnCham->Enabled = false;

		this->buttonToHex->Enabled = false;
		this->buttonToDec->Enabled = true;
		this->buttonToBin->Enabled = true;

		this->btnDecBase->Enabled = true;
		this->btnBinBase->Enabled = true;
		this->btnHexBase->Enabled = false;
	}
	private: System::Void DisableAlpha() {
		this->buttonA->Enabled = false;
		this->buttonB->Enabled = false;
		this->buttonC->Enabled = false;
		this->buttonD->Enabled = false;
		this->buttonE->Enabled = false;
		this->buttonF->Enabled = false;
	}
	private: System::Void EnableAlpha() {
		this->buttonA->Enabled = true;
		this->buttonB->Enabled = true;
		this->buttonC->Enabled = true;
		this->buttonD->Enabled = true;
		this->buttonE->Enabled = true;
		this->buttonF->Enabled = true;
	}
	private: System::Void DisableBase() {
		this->btnBinBase->Enabled = false;
		this->btnDecBase->Enabled = false;
		this->btnHexBase->Enabled = false;
	}
	private: System::Void EnableBase() {
		this->btnBinBase->Enabled = true;
		this->btnDecBase->Enabled = true;
		this->btnHexBase->Enabled = true;
	}
	private: System::Void setBase() {
		
		switch (this->base)
		{
		case 2:
			this->ModeBinary();
			break;
		case 10:
			this->ModeDecimal();
			break;
		case 16:
			this->ModeHexdecimal();
		default:
			break;
		}
		this->turnOffConvert();
	}
	private: System::Void turnOnOperator() {
		if (this->isFloat)
		{
			return;
		}
		this->shiftLeft->Enabled = true;
		this->shiftRight->Enabled = true;

		this->buttonAdd->Enabled = true;
		this->buttonSub->Enabled = true;
		this->buttonMul->Enabled = true;
		this->buttonDiv->Enabled = true;
		this->buttonMod->Enabled = true;

		this->buttonGreaterEqual->Enabled = true;
		this->buttonGreater->Enabled = true;
		this->buttonEqual->Enabled = true;
		this->buttonLessEqual->Enabled = true;
		this->buttonLess->Enabled = true;

		this->buttonAnd->Enabled = true;
		this->buttonOr->Enabled = true;
		this->buttonXor->Enabled = true;
		if (this->buttonPressed)
		{
			this->buttonNot->Enabled = false;
		}
		else
		{
			this->buttonNot->Enabled = true;
		}
		this->buttonRor->Enabled = true;
		this->buttonRol->Enabled = true;

		this->setBase();

	}
	private: System::Void turnOffOperator() {
		this->shiftLeft->Enabled = false;
		this->shiftRight->Enabled = false;

		this->buttonAdd->Enabled = false;
		this->buttonSub->Enabled = false;
		this->buttonMul->Enabled = false;
		this->buttonDiv->Enabled = false;
		this->buttonMod->Enabled = false;
		
		this->buttonGreaterEqual->Enabled = false;
		this->buttonGreater->Enabled = false;
		this->buttonEqual->Enabled = false;
		this->buttonLessEqual->Enabled = false;
		this->buttonLess->Enabled = false;

		this->buttonAnd->Enabled = false;
		this->buttonOr->Enabled = false;
		this->buttonXor->Enabled = false;
		if (this->buttonPressed)
		{
			this->buttonNot->Enabled = false;
		}
		else
		{
			this->buttonNot->Enabled = true;
		}
		this->buttonRor->Enabled = false;
		this->buttonRol->Enabled = false;
		
	}
	private: System::Void turnOffBase() {
		this->btnBinBase->Enabled = false;
		this->btnDecBase->Enabled = false;
		this->btnHexBase->Enabled = false;
	}
	private: System::Void turnOnBase() {
		this->btnBinBase->Enabled = true;
		this->btnDecBase->Enabled = true;
		this->btnHexBase->Enabled = true;
	}
	private: System::Void turnOffConvert() {
		this->buttonToDec->Enabled = false;
		this->buttonToHex->Enabled = false;
		this->buttonToBin->Enabled = false;
	}
	private: System::Void turnOnConvert() {
		this->buttonToDec->Enabled = true;
		this->buttonToHex->Enabled = true;
		this->buttonToBin->Enabled = true;
	}
	private: System::String^ Calculate() {
		// nhan phim bang , hien thi ket qua 
		lblShowOp->Text = "";
		//isecondnum = double::Parse(txtDisplay->Text);
		isecond = txtDisplay->Text;

		if (this->isOperatorNOT)
		{
			this->isecond = gcnew String(scanQIntQues(std::to_string(base)+ " ~ " + toStandardString(isecond)).c_str());
		}

		std::string opera;
		if (ioperation == "+")
		{
			//iresult = ifirstnum + isecondnum;
			//txtDisplay->Text = System::Convert::ToString(iresult);
			//QInt intt(-13261);
			opera = "+";
		}
		else if (ioperation == "-")
		{
			/*iresult = ifirstnum - isecondnum;
			txtDisplay->Text = System::Convert::ToString(iresult);*/
			opera = "-";
		}
		else if (ioperation == "*")
		{
			/*iresult = ifirstnum * isecondnum;
			txtDisplay->Text = System::Convert::ToString(iresult); */
			opera = "*";
		}
		else if (ioperation == "/")
		{
			/*iresult = ifirstnum / isecondnum;
			txtDisplay->Text = System::Convert::ToString(iresult);*/
			opera = "/";
		}
		else if (ioperation == "Mod")
		{
			/*int iFirst, iSecond, iResult;
			iFirst = Convert::ToInt32(ifirstnum);
			iSecond= Convert::ToInt32(isecondnum);
			iResult = iFirst % iSecond;
			txtDisplay->Text = System::Convert::ToString(iResult);*/
			opera = "%";
		}
		else if (ioperation == "exp")
		{
			/*iresult =( ifirstnum ,1/ isecondnum);
			txtDisplay->Text = System::Convert::ToString(Math::Exp(iresult));*/
			opera = "exp";
		}
		else if (ioperation == "%")
		{
			/*int iFirst, iResult;
			iFirst = Convert::ToInt32(ifirstnum);
			iResult = iFirst /100;
			txtDisplay->Text = System::Convert::ToString(iResult);*/
			opera = "%";
		}
		else if (ioperation == ">=")
		{
			opera = ">=";
		}
		else if (ioperation == ">")
		{
			opera = ">";
		}
		else if (ioperation == "==")
		{
			opera = "==";
		}
		else if (ioperation == "<=")
		{
			opera = "<=";
		}
		else if (ioperation == "<")
		{
			opera = "<";
		}
		else if (ioperation == "AND")
		{
			opera = "&";
		}
		else if (ioperation == "OR")
		{
			opera = "|";
		}
		else if (ioperation == "XOR")
		{
			opera = "^";
		}
		else if (ioperation == "NOT")
		{
			opera = "~";
		}
		else if (ioperation == "ROR")
		{
			opera = "ror";
		}
		else if (ioperation == "ROL")
		{
			opera = "rol";
		}
		else if (ioperation == "<<")
		{
			opera = "<<";
		}
		else if (ioperation == ">>")
		{
			opera = ">>";
		}
		else
		{
			txtDisplay->Text = "OPERATOR ERROR!";
			return "0";
		}

		std::string strQues;
		std::stringstream sstr;
		/*if (opera == "~")
		{
			sstr << base << "$" << opera << "$" << toStandardString(isecond);
		}
		else */
		sstr << base << "$" << toStandardString(ifirst) << "$" << opera << "$" << toStandardString(isecond);
		sstr >> strQues;
		for (short i = 0; i < strQues.length(); i++)
		{
			if (strQues[i] == '$') strQues[i] = ' ';
		}
		strQues = scanQIntQues(strQues);
		if (strQues == "")
		{
			strQues = "0";
		}

		this->ans = gcnew String(strQues.c_str());	// System::String^ from std::string
		return this->ans;
	}
	private: System::Void turnOnBaseConvert() {
		
		switch (this->base)
		{
		case 2:
			this->buttonToBin->Enabled = false;
			this->buttonToDec->Enabled = true;
			this->buttonToHex->Enabled = true;
			break;
		case 10:
			this->buttonToBin->Enabled = true;
			this->buttonToDec->Enabled = false;
			this->buttonToHex->Enabled = true;
			break;
		case 16:
			this->buttonToBin->Enabled = true;
			this->buttonToDec->Enabled = true;
			this->buttonToHex->Enabled = false;
			break;
		default:
			txtDisplay->Text = "132";
			break;
		}
		if (this->isFloat)
		{
			this->buttonToHex->Enabled = false;

		}
	}
private: System::Void txtDisplay_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
 // not mean 2 ~ 1
// false 0 and true 1

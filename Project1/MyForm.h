#pragma once
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "time.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//BitmapData
	using namespace System::Drawing::Imaging;
	using namespace System::Drawing::Design;

	Bitmap^ dilate(Bitmap^ Input_image,int scope);
	Bitmap^ erode(Bitmap^ Input_image, int scope);
	
	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Button^ button4;
	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"標楷體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(36, 710);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 90);
			this->button1->TabIndex = 0;
			this->button1->Text = L"檔案";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::file);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"標楷體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(550, 710);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 90);
			this->button2->TabIndex = 1;
			this->button2->Text = L"侵蝕";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Erosion);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"標楷體", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown1->Location = System::Drawing::Point(221, 725);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(117, 65);
			this->numericUpDown1->TabIndex = 2;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(30, 30);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(450, 300);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(550, 30);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(450, 300);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"標楷體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(228, 333);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 32);
			this->label1->TabIndex = 5;
			this->label1->Text = L"輸入";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"標楷體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(741, 333);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 32);
			this->label2->TabIndex = 6;
			this->label2->Text = L"輸出";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"標楷體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(732, 710);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(160, 90);
			this->button3->TabIndex = 7;
			this->button3->Text = L"膨脹";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::Dilation);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(1074, 30);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(450, 300);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 8;
			this->pictureBox3->TabStop = false;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"標楷體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button4->Location = System::Drawing::Point(368, 710);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(160, 90);
			this->button4->TabIndex = 9;
			this->button4->Text = L"儲存";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::mods);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1584, 861);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*雜七雜八的宣告*/
	char mod = 0;
	int val;
	bool First_Flag = 1;
	Bitmap^ Input_image;
	Bitmap^ temp_image;
	/*讀取檔案*/
	private: System::Void file(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd;
		ofd = gcnew OpenFileDialog();
		ofd->FileName = "";
		ofd->Filter = "All Files(*.*)|*.*";
		ofd->FilterIndex = 1;
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK && ofd->FileName != "") {
			Input_image = gcnew Bitmap(ofd->FileName);
			pictureBox1->Image = Input_image;
		}
		printf("新圖片!\n");
	}


	/*膨脹*/
	private: System::Void Dilation(System::Object^ sender, System::EventArgs^ e) {
		val = (int)numericUpDown1->Value;
		if (First_Flag) temp_image = Input_image;
		if (mod == 0) temp_image = dilate(temp_image,val);
		if (mod == 1) temp_image = dilate(Input_image,val);
		pictureBox2->Image = temp_image;
		First_Flag = 0;
	}

	/*侵蝕*/
	private: System::Void Erosion(System::Object^ sender, System::EventArgs^ e) {
		val = (int)numericUpDown1->Value;
		if (First_Flag) temp_image = Input_image;
		if (mod == 0) temp_image = erode(temp_image, val);
		if (mod == 1) temp_image = erode(Input_image, val);
		pictureBox2->Image = temp_image;
		First_Flag = 0;
	}
	/*模式*/
	private: System::Void mods(System::Object^ sender, System::EventArgs^ e) {
		mod = (mod + 1) % 2;
		if (mod == 1) {
			button4->Text = L"不儲存";
			printf("不儲存\n");
		}
		if (mod == 0) {
			button4->Text = L"儲存";
			printf("儲存\n");
		}
	}
};
}

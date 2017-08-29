#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			array<String^>^ serialPorts = nullptr;

			serialPorts = serialPort1->GetPortNames();

			this->comboBox1->Items->AddRange(serialPorts);

			this->comboBox1->SelectedIndex = 0;
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
	private: Thread^ thread;
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
		bool port_open;
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	public: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::Button^  button2;
	private:


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->BaudRate = 115200;
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPort1_DataReceived);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(133, 47);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 20);
			this->comboBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(178, 105);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(133, 176);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 85);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 12);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(34, 133);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		serialPort1->Close();
		if (!port_open) {
			this->serialPort1->PortName = this->comboBox1->Text;
			serialPort1->Open();
			if (serialPort1->IsOpen)
			{
				this->label1->Text = "Connect Sucess!";
				this->button1->Text = "Close";
				port_open = true;
			}
			else
			{
				this->label1->Text = "error";
			}

		}
		else {
			serialPort1->Close();
			this->button1->Text = "Open";
			port_open = false;
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->thread =
			gcnew Thread(gcnew ThreadStart(this, &MyForm::ThreadProcSafe));

		this->thread->Start();
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {


	}
			 
	private:
		void setTextSafeBtn_Click(Object^ sender, EventArgs^ e)
		{
			this->thread =
				gcnew Thread(gcnew ThreadStart(this, &MyForm::ThreadProcSafe));

			this->thread->Start();
		}

		// This method is executed on the worker thread and makes
		// a thread-safe call on the TextBox control.
	public: int qwe = 0;
	private:
		void ThreadProcSafe()
		{
			while (1)
			{
				qwe++;

				this->SetText(qwe.ToString());
			}
		}
		delegate void SetTextDelegate(String^ text);
	private:
		void SetText(String^ text)
		{
			// InvokeRequired required compares the thread ID of the
			// calling thread to the thread ID of the creating thread.
			// If these threads are different, it returns true.
			if (this->textBox1->InvokeRequired)
			{
				SetTextDelegate^ d =
					gcnew SetTextDelegate(this, &MyForm::SetText);
				this->Invoke(d, gcnew array<Object^> { text });
			}
			else
			{
				this->textBox1->Text = text;
			}
		}

	};
}

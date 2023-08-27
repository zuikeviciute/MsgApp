#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include "LinkedList1.h"
#include "Account.h"
#include "MsgApp.h"


namespace MsgApp5 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	MsgApp5::LinkedList1<MsgApp5::Account> accounts = MsgApp5::LinkedList1<Account>();
	MsgApp5::LinkedList1<MsgApp5::Chat> chats = MsgApp5::LinkedList1<Chat>();
	Account currentAcc;
	int currentChat;

	/// <summary>
	/// Summary for MsgApp
	/// </summary>
	public ref class MsgApp : public System::Windows::Forms::Form
	{
		
	public:
		MsgApp(void)
		{
			InitializeComponent();
			this->txtMsg->ReadOnly = true;
			populateLists();
			uiVisibility(1);
		}

	protected:
		~MsgApp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtInput;
	protected:

	private: System::Windows::Forms::TextBox^ txtMsg;
	private: System::Windows::Forms::TextBox^ txtUsername;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Button^ btnLogin;

	private: System::Windows::Forms::Label^ labelUsername;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::Label^ labelNameError;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Button^ btnLogOut;

	private: System::Windows::Forms::TextBox^ txtJoinChat;
	private: System::Windows::Forms::Label^ labelJoinChat;
	private: System::Windows::Forms::Button^ btnJoinChat;

	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Label^ labelCurrentUser;
	private: System::Windows::Forms::Label^ labelChatName;
	private: System::Windows::Forms::Button^ btnCreateChat;
	private: System::Windows::Forms::TextBox^ txtCreateChatName;
	private: System::Windows::Forms::Label^ labelCreateChatName;
	private: System::Windows::Forms::Button^ btnCreateNewChat;
	private: System::Windows::Forms::Label^ labelChatCodeError;
	private: System::Windows::Forms::Label^ labelChatJoinError;

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->txtMsg = (gcnew System::Windows::Forms::TextBox());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->labelUsername = (gcnew System::Windows::Forms::Label());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->labelNameError = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnLogOut = (gcnew System::Windows::Forms::Button());
			this->txtJoinChat = (gcnew System::Windows::Forms::TextBox());
			this->labelJoinChat = (gcnew System::Windows::Forms::Label());
			this->btnJoinChat = (gcnew System::Windows::Forms::Button());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->labelCurrentUser = (gcnew System::Windows::Forms::Label());
			this->labelChatName = (gcnew System::Windows::Forms::Label());
			this->btnCreateChat = (gcnew System::Windows::Forms::Button());
			this->txtCreateChatName = (gcnew System::Windows::Forms::TextBox());
			this->labelCreateChatName = (gcnew System::Windows::Forms::Label());
			this->btnCreateNewChat = (gcnew System::Windows::Forms::Button());
			this->labelChatCodeError = (gcnew System::Windows::Forms::Label());
			this->labelChatJoinError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtInput
			// 
			this->txtInput->BackColor = System::Drawing::Color::Gainsboro;
			this->txtInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtInput->Location = System::Drawing::Point(12, 267);
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(448, 23);
			this->txtInput->TabIndex = 0;
			this->txtInput->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MsgApp::txtInput_KeyDown);
			// 
			// txtMsg
			// 
			this->txtMsg->BackColor = System::Drawing::Color::Gainsboro;
			this->txtMsg->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtMsg->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->txtMsg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtMsg->Location = System::Drawing::Point(12, 35);
			this->txtMsg->Multiline = true;
			this->txtMsg->Name = L"txtMsg";
			this->txtMsg->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtMsg->Size = System::Drawing::Size(448, 226);
			this->txtMsg->TabIndex = 1;
			// 
			// txtUsername
			// 
			this->txtUsername->BackColor = System::Drawing::Color::Gainsboro;
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUsername->Location = System::Drawing::Point(127, 83);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(216, 27);
			this->txtUsername->TabIndex = 2;
			// 
			// txtPassword
			// 
			this->txtPassword->BackColor = System::Drawing::Color::Gainsboro;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword->Location = System::Drawing::Point(127, 142);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(216, 27);
			this->txtPassword->TabIndex = 3;
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::White;
			this->btnLogin->FlatAppearance->BorderColor = System::Drawing::Color::Gainsboro;
			this->btnLogin->FlatAppearance->BorderSize = 0;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogin->Location = System::Drawing::Point(147, 184);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(173, 26);
			this->btnLogin->TabIndex = 4;
			this->btnLogin->Text = L"Log In";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MsgApp::btnLogin_Click);
			// 
			// labelUsername
			// 
			this->labelUsername->AutoSize = true;
			this->labelUsername->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUsername->Location = System::Drawing::Point(124, 63);
			this->labelUsername->Name = L"labelUsername";
			this->labelUsername->Size = System::Drawing::Size(73, 17);
			this->labelUsername->TabIndex = 5;
			this->labelUsername->Text = L"Username";
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPassword->Location = System::Drawing::Point(124, 122);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(69, 17);
			this->labelPassword->TabIndex = 6;
			this->labelPassword->Text = L"Password";
			// 
			// labelNameError
			// 
			this->labelNameError->AutoSize = true;
			this->labelNameError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelNameError->ForeColor = System::Drawing::Color::DarkRed;
			this->labelNameError->Location = System::Drawing::Point(71, 233);
			this->labelNameError->Name = L"labelNameError";
			this->labelNameError->Size = System::Drawing::Size(340, 17);
			this->labelNameError->TabIndex = 7;
			this->labelNameError->Text = L"Username can only contain alphanumeric characters";
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::Gainsboro;
			this->btnBack->FlatAppearance->BorderColor = System::Drawing::Color::Gainsboro;
			this->btnBack->FlatAppearance->BorderSize = 0;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBack->ForeColor = System::Drawing::Color::Black;
			this->btnBack->Location = System::Drawing::Point(9, 3);
			this->btnBack->Margin = System::Windows::Forms::Padding(0);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(51, 26);
			this->btnBack->TabIndex = 8;
			this->btnBack->Text = L"back";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &MsgApp::btnBack_Click);
			// 
			// btnLogOut
			// 
			this->btnLogOut->BackColor = System::Drawing::Color::Gainsboro;
			this->btnLogOut->FlatAppearance->BorderColor = System::Drawing::Color::Gainsboro;
			this->btnLogOut->FlatAppearance->BorderSize = 0;
			this->btnLogOut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogOut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogOut->ForeColor = System::Drawing::Color::Black;
			this->btnLogOut->Location = System::Drawing::Point(60, 4);
			this->btnLogOut->Margin = System::Windows::Forms::Padding(0);
			this->btnLogOut->Name = L"btnLogOut";
			this->btnLogOut->Size = System::Drawing::Size(61, 26);
			this->btnLogOut->TabIndex = 9;
			this->btnLogOut->Text = L"log out";
			this->btnLogOut->UseVisualStyleBackColor = false;
			this->btnLogOut->Click += gcnew System::EventHandler(this, &MsgApp::btnLogOut_Click);
			// 
			// txtJoinChat
			// 
			this->txtJoinChat->BackColor = System::Drawing::Color::Gainsboro;
			this->txtJoinChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtJoinChat->Location = System::Drawing::Point(127, 122);
			this->txtJoinChat->Name = L"txtJoinChat";
			this->txtJoinChat->Size = System::Drawing::Size(216, 27);
			this->txtJoinChat->TabIndex = 11;
			// 
			// labelJoinChat
			// 
			this->labelJoinChat->AutoSize = true;
			this->labelJoinChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelJoinChat->Location = System::Drawing::Point(124, 105);
			this->labelJoinChat->Name = L"labelJoinChat";
			this->labelJoinChat->Size = System::Drawing::Size(108, 17);
			this->labelJoinChat->TabIndex = 12;
			this->labelJoinChat->Text = L"Enter chat code";
			// 
			// btnJoinChat
			// 
			this->btnJoinChat->BackColor = System::Drawing::Color::White;
			this->btnJoinChat->FlatAppearance->BorderColor = System::Drawing::Color::Gainsboro;
			this->btnJoinChat->FlatAppearance->BorderSize = 0;
			this->btnJoinChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJoinChat->Location = System::Drawing::Point(147, 155);
			this->btnJoinChat->Name = L"btnJoinChat";
			this->btnJoinChat->Size = System::Drawing::Size(173, 26);
			this->btnJoinChat->TabIndex = 13;
			this->btnJoinChat->Text = L"Join";
			this->btnJoinChat->UseVisualStyleBackColor = false;
			this->btnJoinChat->Click += gcnew System::EventHandler(this, &MsgApp::btnJoinChat_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->BackColor = System::Drawing::Color::Gainsboro;
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(348, 6);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(112, 23);
			this->txtSearch->TabIndex = 18;
			this->txtSearch->Text = L"Search...";
			this->txtSearch->Click += gcnew System::EventHandler(this, &MsgApp::clearSearchField);
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &MsgApp::searchTextChanged);
			// 
			// labelCurrentUser
			// 
			this->labelCurrentUser->AutoSize = true;
			this->labelCurrentUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelCurrentUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelCurrentUser->Location = System::Drawing::Point(12, 9);
			this->labelCurrentUser->Name = L"labelCurrentUser";
			this->labelCurrentUser->Size = System::Drawing::Size(45, 17);
			this->labelCurrentUser->TabIndex = 19;
			this->labelCurrentUser->Text = L"Name";
			// 
			// labelChatName
			// 
			this->labelChatName->AutoSize = true;
			this->labelChatName->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelChatName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelChatName->Location = System::Drawing::Point(186, 9);
			this->labelChatName->Name = L"labelChatName";
			this->labelChatName->Size = System::Drawing::Size(78, 17);
			this->labelChatName->TabIndex = 20;
			this->labelChatName->Text = L"Chat Name";
			// 
			// btnCreateChat
			// 
			this->btnCreateChat->BackColor = System::Drawing::Color::Transparent;
			this->btnCreateChat->FlatAppearance->BorderColor = System::Drawing::Color::Gainsboro;
			this->btnCreateChat->FlatAppearance->BorderSize = 0;
			this->btnCreateChat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCreateChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreateChat->Location = System::Drawing::Point(147, 184);
			this->btnCreateChat->Name = L"btnCreateChat";
			this->btnCreateChat->Size = System::Drawing::Size(173, 26);
			this->btnCreateChat->TabIndex = 21;
			this->btnCreateChat->Text = L"create new chat";
			this->btnCreateChat->UseVisualStyleBackColor = false;
			this->btnCreateChat->Click += gcnew System::EventHandler(this, &MsgApp::btnCreateChat_Click);
			// 
			// txtCreateChatName
			// 
			this->txtCreateChatName->BackColor = System::Drawing::Color::Gainsboro;
			this->txtCreateChatName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCreateChatName->Location = System::Drawing::Point(127, 75);
			this->txtCreateChatName->Name = L"txtCreateChatName";
			this->txtCreateChatName->Size = System::Drawing::Size(216, 27);
			this->txtCreateChatName->TabIndex = 22;
			// 
			// labelCreateChatName
			// 
			this->labelCreateChatName->AutoSize = true;
			this->labelCreateChatName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelCreateChatName->Location = System::Drawing::Point(124, 55);
			this->labelCreateChatName->Name = L"labelCreateChatName";
			this->labelCreateChatName->Size = System::Drawing::Size(112, 17);
			this->labelCreateChatName->TabIndex = 23;
			this->labelCreateChatName->Text = L"Enter chat name";
			// 
			// btnCreateNewChat
			// 
			this->btnCreateNewChat->BackColor = System::Drawing::Color::White;
			this->btnCreateNewChat->FlatAppearance->BorderColor = System::Drawing::Color::Gainsboro;
			this->btnCreateNewChat->FlatAppearance->BorderSize = 0;
			this->btnCreateNewChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreateNewChat->Location = System::Drawing::Point(147, 155);
			this->btnCreateNewChat->Name = L"btnCreateNewChat";
			this->btnCreateNewChat->Size = System::Drawing::Size(173, 26);
			this->btnCreateNewChat->TabIndex = 24;
			this->btnCreateNewChat->Text = L"Create";
			this->btnCreateNewChat->UseVisualStyleBackColor = false;
			this->btnCreateNewChat->Click += gcnew System::EventHandler(this, &MsgApp::btnCreateNewChat_Click);
			// 
			// labelChatCodeError
			// 
			this->labelChatCodeError->AutoSize = true;
			this->labelChatCodeError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelChatCodeError->ForeColor = System::Drawing::Color::DarkRed;
			this->labelChatCodeError->Location = System::Drawing::Point(112, 233);
			this->labelChatCodeError->Name = L"labelChatCodeError";
			this->labelChatCodeError->Size = System::Drawing::Size(244, 17);
			this->labelChatCodeError->TabIndex = 25;
			this->labelChatCodeError->Text = L"Chat with that join code already exists";
			// 
			// labelChatJoinError
			// 
			this->labelChatJoinError->AutoSize = true;
			this->labelChatJoinError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelChatJoinError->ForeColor = System::Drawing::Color::DarkRed;
			this->labelChatJoinError->Location = System::Drawing::Point(144, 233);
			this->labelChatJoinError->Name = L"labelChatJoinError";
			this->labelChatJoinError->Size = System::Drawing::Size(193, 17);
			this->labelChatJoinError->TabIndex = 26;
			this->labelChatJoinError->Text = L"No chats found with this code";
			// 
			// MsgApp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(472, 299);
			this->Controls->Add(this->labelChatJoinError);
			this->Controls->Add(this->labelChatCodeError);
			this->Controls->Add(this->btnCreateNewChat);
			this->Controls->Add(this->labelCreateChatName);
			this->Controls->Add(this->txtCreateChatName);
			this->Controls->Add(this->btnCreateChat);
			this->Controls->Add(this->labelChatName);
			this->Controls->Add(this->labelCurrentUser);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->btnJoinChat);
			this->Controls->Add(this->labelJoinChat);
			this->Controls->Add(this->txtJoinChat);
			this->Controls->Add(this->labelUsername);
			this->Controls->Add(this->btnLogOut);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->labelNameError);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->txtInput);
			this->Controls->Add(this->txtMsg);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MsgApp";
			this->Text = L"MsgApp";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void txtInput_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		string input;

		if (e->KeyCode == Keys::Enter) {
			input = marshal_as<string>(this->txtInput->Text);

			if (input != "") {
				this->txtInput->Text = L"";
				chats.itemAt(currentChat).addMessage(Msg(input, currentAcc.username));
				showAllMsg();
			}
		}
	}

	void populateLists() {
		Chat c = Chat("General chat", "chat_123");
		Chat ch = Chat("work", "workChat");

		accounts.addLast(Account(accounts.count, "Laura", "new1234"));
		accounts.addLast(Account(accounts.count, "John4", "crab900"));
		accounts.addLast(Account(accounts.count, "Kate", "432100"));

		c.populate();
		ch.messages.addLast(Msg("This is a work chat, please keep it professional", "Bob"));
		ch.messages.addLast(Msg("okay, Bob", "Eve"));
		ch.messages.addLast(Msg("Sure", "Guy"));

		chats.addLast(c);
		chats.addLast(ch);
	}

	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		
		string strUsername = msclr::interop::marshal_as<string>(this->txtUsername->Text);
		string strPassword = msclr::interop::marshal_as<string>(this->txtPassword->Text);
		int temp;

		if (checkInput(strUsername) && checkInput(strPassword)) {

			temp = accounts.loginCheck(strUsername, strPassword);

			if (temp != -1) {
				currentAcc = accounts.itemAt(temp);
				this->labelCurrentUser->Text = marshal_as<String^>(currentAcc.username);
				uiVisibility(0);
			}
			else labelNameError->Visible = true;
			
		}
		else labelNameError->Visible = true;
	}

	private: System::Void btnJoinChat_Click(System::Object^ sender, System::EventArgs^ e) {
		string joinCode = msclr::interop::marshal_as<string>(this->txtJoinChat->Text);
		String^ msgContent = "";

		if (chats.joinChatCheck(joinCode) != -1) {
			this->txtSearch->Text = L"Search...";
			currentChat = chats.joinChatCheck(joinCode);
			this->labelChatName->Text = marshal_as<String^>(chats.itemAt(currentChat).name);
			uiVisibility(4);
		}
		else labelChatJoinError->Visible = true;
		showAllMsg();
	}

	void showAllMsg() {
		String^ msgContent = "";
		if (!chats.itemAt(currentChat).messages.isEmpty()) {
			msgContent = marshal_as<String^>(chats.itemAt(currentChat).getMessages());
			this->txtMsg->Text = msgContent;
		}
	}

	private: bool checkInput(string str) {

		for (string::const_iterator s = str.begin(); s != str.end(); ++s) {
			if (!isalnum(*s)) return false;
			else return true;
		}
	}

	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) { uiVisibility(0); }
	private: System::Void btnLogOut_Click(System::Object^ sender, System::EventArgs^ e) { uiVisibility(1); }

	void uiVisibility(int num) {
		labelChatJoinError->Visible = false;
		labelCurrentUser->Visible = false;
		labelChatName->Visible = false;
		txtSearch->Visible = false;
		txtMsg->Visible = false;
		txtInput->Visible = false;
		labelNameError->Visible = false;
		labelJoinChat->Visible = false;
		btnCreateChat->Visible = false;
		txtCreateChatName->Visible = false;
		labelCreateChatName->Visible = false;
		btnJoinChat->Visible = false;
		txtJoinChat->Visible = false;
		labelUsername->Visible = false;
		txtUsername->Visible = false;
		labelPassword->Visible = false;
		txtPassword->Visible = false;
		btnLogin->Visible = false;
		btnCreateNewChat->Visible = false;
		labelChatCodeError->Visible = false;
		btnBack->Visible = false;
		btnLogOut->Visible = false;
		this->txtPassword->Text = L"";

		switch (num) {
			//login
			case 0:
				btnLogOut->Visible = true;
				labelCurrentUser->Visible = true;
				labelJoinChat->Visible = true;
				btnJoinChat->Visible = true;
				btnCreateChat->Visible = true;
				txtJoinChat->Visible = true;
				break;

			//log out
			case 1:
				labelUsername->Visible = true;
				txtUsername->Visible = true;
				labelPassword->Visible = true;
				txtPassword->Visible = true;
				btnLogin->Visible = true;
				this->txtPassword->Text = L"";

				btnLogOut->Visible = false;
				break;

			//create chat
			case 2:
				labelCurrentUser->Visible = true;
				btnCreateNewChat->Visible = true;
				txtCreateChatName->Visible = true;
				labelCreateChatName->Visible = true;
				labelJoinChat->Visible = true;
				txtJoinChat->Visible = true;
				btnCreateChat->Visible = false;
				btnJoinChat->Visible = false;
				btnLogOut->Visible = true;
				break;

			//messages
			case 4:
				btnBack->Visible = true;
				labelChatName->Visible = true;
				txtMsg->Visible = true;
				txtInput->Visible = true;
				txtSearch->Visible = true; //can only search chats
				this->txtInput->Text = L"";
				break;
		}
	}


	private: System::Void clearSearchField(System::Object^ sender, System::EventArgs^ e) {
		this->txtSearch->Text = L"";
	}

	private: System::Void searchTextChanged(System::Object^ sender, System::EventArgs^ e){
		String^ searchResult = "";
		string strInput = msclr::interop::marshal_as<string>(this->txtSearch->Text);

		if(strInput == "") showAllMsg();
		else if (strInput != "" && !chats.itemAt(currentChat).messages.isEmpty()) {
			searchResult = marshal_as<String^>(chats.itemAt(currentChat).searchMessages(strInput));
			this->txtMsg->Text = searchResult;
		}
	}

	private: System::Void btnCreateChat_Click(System::Object^ sender, System::EventArgs^ e) {
		uiVisibility(2);
	}

	private: System::Void btnCreateNewChat_Click(System::Object^ sender, System::EventArgs^ e) {
		Chat c;
		string strChatName = msclr::interop::marshal_as<string>(this->txtCreateChatName->Text);
		string strChatJoinCode = msclr::interop::marshal_as<string>(this->txtJoinChat->Text);
		int temp;

		if (checkInput(strChatName) && checkInput(strChatJoinCode)) {

			temp = chats.chatCheck(strChatJoinCode);

			if (temp != -1) {
				c = Chat(strChatName, strChatJoinCode);
				c.messages.addLast(Msg("Chat created", "System"));
				chats.addLast(c);

				currentChat = chats.joinChatCheck(strChatJoinCode);
				labelChatName->Text = marshal_as<String^>(strChatName);
				showAllMsg();
				uiVisibility(4);
			}
			else labelChatCodeError->Visible = true;

		}
		else labelChatCodeError->Visible = true;
	}
};
}

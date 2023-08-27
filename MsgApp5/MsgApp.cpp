#include "MsgApp.h"
#include "LinkedList1.h"
#include "Account.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MsgApp5::MsgApp form;
	Application::Run(% form);
}
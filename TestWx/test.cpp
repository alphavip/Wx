// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include "Config.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};
class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	void OnOpenFile(wxCommandEvent& event);
	void OnSaveContent(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
    
	wxDECLARE_EVENT_TABLE();
};
enum
{
	ID_OpenFile = 100,
	ID_SaveContent = 101,
    ID_TextCtl = 102,
    ID_Button1 = 103,
    ID_Button2 = 104,
    ID_Button3 = 105,
    ID_Button4 = 106,
    ID_Button5 = 107,
};

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(ID_OpenFile, MyFrame::OnOpenFile)
	EVT_MENU(ID_SaveContent, MyFrame::OnSaveContent)
	EVT_MENU(wxID_EXIT, MyFrame::OnExit)
	EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
END_EVENT_TABLE()

IMPLEMENT_APP_NO_MAIN(MyApp);
DECLARE_APP(MyApp);

bool MyApp::OnInit()
{
	//MyFrame *frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
	MyFrame *frame = new MyFrame("Hello World", wxDefaultPosition, wxSize(450, 340));
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_OpenFile, L"&Open",	L"Opens an existing file");
	menuFile->Append(ID_SaveContent, L"&Save", L"Save the content");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT, L"&Quit", L"Quit the application");
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
    
    
    wxPanel* p = new wxPanel();
    wxBoxSizer* sizer[2];
    sizer[0] = new wxBoxSizer(wxHORIZONTAL);
    sizer[1] = new wxBoxSizer(wxVERTICAL);
    wxButton* button[5];
    //wxTextCtrl* textCtr = new wxTextCtrl(this, ID_TextCtl, "Type some text...", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

    button[0] = new wxButton(this, ID_Button1, "send", wxDefaultPosition, wxSize(50, 40));
    button[1] = new wxButton(this, ID_Button2, "pause", wxDefaultPosition, wxSize(50, 40));
    
    sizer[0]->Add(button[0], 0, wxALL, 2);
    sizer[0]->Add(button[1], 0, wxALL, 2);
    //sizer[1]->Add(sizer[0]);
    //sizer[1]->Add(textCtr);
    SetSizerAndFit(sizer[0]);
}
void MyFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets' Hello world sample.\nAll rights reserved AlphaChen!",
		"About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnOpenFile(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::OnSaveContent(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPCSTR lpCmdLine, int nCmdShow)
//{
//	MyApp* app = new MyApp();
//	wxApp::SetInstance(app);
//
//
//	return wxEntry(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
//}

int main(int argc, char* argv[])
{
	MyApp* myApp = new MyApp();
	wxApp::SetInstance(myApp);

#ifdef _WIN32
	wxEntry(GetModuleHandle(NULL));
#else
	wxEntry(argc, argv);
#endif

	return 0;
}



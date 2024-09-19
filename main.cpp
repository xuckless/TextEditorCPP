#include <wx/wx.h>

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
private:
    wxTextCtrl* textCtrl;

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_Quit = 1,
    ID_About
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Quit, MyFrame::OnQuit)
    EVT_MENU(ID_About, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame("wxWidgets Word Editor");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {

    // Create a menu bar
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(ID_Quit, "&Quit\tCtrl-Q", "Quit the application");

    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(ID_About, "&About\tF1", "Show about dialog");

    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");

    SetMenuBar(menuBar);

    // Create a status bar
    CreateStatusBar(2);
    SetStatusText("Welcome to wxWidgets!");

    // Create a text control
    textCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox("This is a wxWidgets Word Editor example",
                 "About wxWordEditor", wxOK | wxICON_INFORMATION);
}

#include "wx_pch.h"
#include "FinalProjectMain.h"
#include <wx/msgdlg.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <wx/dcbuffer.h>


using namespace std;
//(*InternalHeaders(FinalProjectFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

enum
{
	// declares an id which will be used to call file buttons
	TEXT_Main = wxID_HIGHEST + 1
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(FinalProjectFrame)
const long FinalProjectFrame::ID_SPINCTRL3 = wxNewId();
const long FinalProjectFrame::ID_STATICTEXT3 = wxNewId();
const long FinalProjectFrame::ID_BUTTON1 = wxNewId();
const long FinalProjectFrame::ID_BUTTON2 = wxNewId();
const long FinalProjectFrame::ID_STATICTEXT4 = wxNewId();
const long FinalProjectFrame::ID_STATICTEXT5 = wxNewId();
const long FinalProjectFrame::ID_BUTTON3 = wxNewId();
const long FinalProjectFrame::ID_PANEL2 = wxNewId();
const long FinalProjectFrame::ID_PANEL3 = wxNewId();
const long FinalProjectFrame::ID_STATICLINE1 = wxNewId();
const long FinalProjectFrame::ID_STATICTEXT8 = wxNewId();
const long FinalProjectFrame::ID_STATICTEXT9 = wxNewId();
const long FinalProjectFrame::ID_STATICTEXT10 = wxNewId();
const long FinalProjectFrame::ID_PANEL1 = wxNewId();
const long FinalProjectFrame::ID_MENUITEM1 = wxNewId();
const long FinalProjectFrame::idMenuAbout = wxNewId();
const long FinalProjectFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(FinalProjectFrame,wxFrame)
    //(*EventTable(FinalProjectFrame)
    //*)
    EVT_TIMER(TIMER_ID, FinalProjectFrame::OnTimer)
END_EVENT_TABLE()

FinalProjectFrame::FinalProjectFrame(wxWindow* parent,wxWindowID id) : m_timer(this, TIMER_ID)
{
    //(*Initialize(FinalProjectFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(1448,635), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(1328,16), wxSize(112,256), wxSUNKEN_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    SpinCtrl3 = new wxSpinCtrl(Panel2, ID_SPINCTRL3, _T("1"), wxPoint(32,32), wxSize(45,27), 0, 0, 100, 1, _T("ID_SPINCTRL3"));
    SpinCtrl3->SetValue(_T("1"));
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("levels"), wxPoint(32,16), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    Button1 = new wxButton(Panel2, ID_BUTTON1, _("Start"), wxPoint(16,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(Panel2, ID_BUTTON2, _("Save"), wxPoint(32,152), wxSize(48,29), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Hero"), wxPoint(8,96), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Enemy"), wxPoint(8,120), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    Button3 = new wxButton(Panel2, ID_BUTTON3, _("Load"), wxPoint(32,184), wxSize(45,29), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Panel3 = new wxPanel(Panel1, ID_PANEL3, wxPoint(8,8), wxSize(1312,640), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(472,8), wxSize(10,432), wxLI_VERTICAL, _T("ID_STATICLINE1"));
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Kagero:"), wxPoint(1328,328), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Armor Axe:"), wxPoint(1328,344), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("HP"), wxPoint(1328,304), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_SPINCTRL3,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&FinalProjectFrame::OnSpinCtrl3Change);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FinalProjectFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FinalProjectFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FinalProjectFrame::OnButton3Click);
    Panel2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&FinalProjectFrame::OnPanel2Paint,0,this);
    Panel3->Connect(wxEVT_PAINT,(wxObjectEventFunction)&FinalProjectFrame::OnPanel3Paint,0,this);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&FinalProjectFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&FinalProjectFrame::OnAbout);
    //*)
    gameEnd = false;

    wxSize* zeroSize = new wxSize(0, 0);
    LoadBox = new wxTextCtrl(
		this, TEXT_Main, wxEmptyString, wxDefaultPosition, *zeroSize,
		wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY, wxDefaultValidator, wxTextCtrlNameStr);

    wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);

}

FinalProjectFrame::~FinalProjectFrame()
{
    //(*Destroy(FinalProjectFrame)
    //*)
}

void FinalProjectFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void FinalProjectFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void FinalProjectFrame::mapOne()
{
    //MyArray[layers][row][column]
    MyArray[0][6][1] = new HeroCalvarySpearEphraim(6, 1, 0);
    MyArray[0][6][2] = new HeroDaggerKagero(6, 2, 0);
    MyArray[0][6][3] = new HeroFlierAxeCamilla(6, 3, 0);
    MyArray[0][7][2] = new HeroInfantrySwordIke(7, 2, 0);

    MyArray[0][0][1] = new EnemyFlierLance(0, 1, 0);
    MyArray[0][1][1] = new EnemyArcher(1, 1, 0);
    MyArray[0][0][4] = new EnemyArmorAxe(0, 4, 0);
    MyArray[0][1][4] = new EnemyInfantrySword(1, 4, 0);

    MyArray[0][2][1] = new FlyerPass(2, 1, 0);
    MyArray[0][2][2] = new FlyerPass(2, 2, 0);
    MyArray[0][2][4] = new FlyerPass(2, 4, 0);
    MyArray[0][2][5] = new FlyerPass(2, 5, 0);
    MyArray[0][3][4] = new FlyerPass(3, 4, 0);
    MyArray[0][4][2] = new FlyerPass(4, 2, 0);
    MyArray[0][5][1] = new FlyerPass(5, 1, 0);
    MyArray[0][5][2] = new FlyerPass(5, 2, 0);
    MyArray[0][5][4] = new FlyerPass(5, 4, 0);
    MyArray[0][5][5] = new FlyerPass(5, 5, 0);
    MyArray[0][7][3] = new FlyerPass(7, 3, 0);

    MyArray[0][0][2] = new CalvaryImpass(0, 2, 0);
    MyArray[0][0][3] = new CalvaryImpass(0, 3, 0);
    MyArray[0][7][0] = new CalvaryImpass(7, 0, 0);
    MyArray[0][7][1] = new CalvaryImpass(7, 1, 0);
}

void FinalProjectFrame::mapTwo()
{
    MyArray[1][0][4] = new HeroCalvaryAxeTitania(0, 4, 1);
    MyArray[1][0][5] = new HeroArcherKlein(0, 5, 1);
    MyArray[1][1][4] = new HeroFlierLanceCordelia(1, 4, 1);
    MyArray[1][1][5] = new HeroArmorSwordZelgius(1, 5, 1);

    MyArray[1][7][1] = new EnemyFlierSword(7, 1, 1);
    MyArray[1][6][0] = new EnemyDagger(6, 0, 1);
    MyArray[1][6][1] = new EnemyArmorLance(6, 1, 1);
    MyArray[1][5][0] = new EnemyInfantryAxe(5, 0, 1);

    MyArray[1][0][3] = new FlyerPass(0, 3, 1);
    MyArray[1][2][2] = new FlyerPass(2, 2, 1);
    MyArray[1][2][3] = new FlyerPass(2, 3, 1);
    MyArray[1][2][4] = new FlyerPass(2, 4, 1);
    MyArray[1][3][1] = new FlyerPass(3, 1, 1);
    MyArray[1][3][4] = new FlyerPass(3, 4, 1);
    MyArray[1][4][4] = new FlyerPass(4, 4, 1);
    MyArray[1][5][1] = new FlyerPass(5, 1, 1);
    MyArray[1][5][2] = new FlyerPass(5, 2, 1);
    MyArray[1][5][5] = new FlyerPass(5, 5, 1);
    MyArray[1][6][2] = new FlyerPass(6, 2, 1);

    MyArray[1][0][0] = new CalvaryImpass(0, 0, 1);
    MyArray[1][7][0] = new CalvaryImpass(7, 0, 1);
    MyArray[1][7][3] = new CalvaryImpass(7, 3, 1);
    MyArray[1][7][5] = new CalvaryImpass(7, 5, 1);
}

void FinalProjectFrame::mapThree()
{
    MyArray[2][7][1] = new HeroCalvarySwordSeigbert(7, 1, 2);
    MyArray[2][6][0] = new HeroInfantryAxeAzura(6, 0, 2);
    MyArray[2][6][1] = new HeroFlierSwordElincia(6, 1, 2);
    MyArray[2][5][0] = new HeroArmorLanceEffie(5, 0, 2);

    MyArray[2][0][1] = new EnemyFlierSword(0, 1, 2);
    MyArray[2][0][2] = new EnemyDagger(0, 2, 2);
    MyArray[2][1][2] = new EnemyArmorLance(1, 2, 2);
    MyArray[2][1][3] = new EnemyInfantryAxe(1, 3, 2);

    MyArray[2][0][0] = new FlyerPass(0, 0, 2);
    MyArray[2][1][0] = new FlyerPass(1, 0, 2);
    MyArray[2][1][1] = new FlyerPass(1, 1, 2);
    MyArray[2][2][1] = new FlyerPass(2, 1, 2);
    MyArray[2][2][2] = new FlyerPass(2, 2, 2);
    MyArray[2][3][2] = new FlyerPass(3, 2, 2);
    MyArray[2][3][3] = new FlyerPass(3, 3, 2);
    MyArray[2][3][4] = new FlyerPass(3, 4, 2);
    MyArray[2][0][5] = new FlyerPass(0, 5, 2);
    MyArray[2][1][4] = new FlyerPass(1, 4, 2);
    MyArray[2][1][5] = new FlyerPass(1, 5, 2);
    MyArray[2][4][3] = new FlyerPass(4, 3, 2);
    MyArray[2][5][2] = new FlyerPass(5, 2, 2);
    MyArray[2][5][3] = new FlyerPass(5, 3, 2);
    MyArray[2][7][2] = new FlyerPass(7, 2, 2);

    MyArray[2][0][3] = new CalvaryImpass(0, 3, 2);
    MyArray[2][7][0] = new CalvaryImpass(7, 0, 2);
    MyArray[2][4][1] = new CalvaryImpass(4, 1, 2);
    MyArray[2][7][4] = new CalvaryImpass(7, 4, 2);
}

void FinalProjectFrame::OnButton1Click(wxCommandEvent& event)
{
    srand(time(NULL));
    int ndx1, ndx2, ndx3;
    gameEnd = false;

    MyArray = new Cell *** [SpinCtrl3->GetValue()];

    for(ndx1 = 0; ndx1 < SpinCtrl3->GetValue(); ndx1++)
    {
        MyArray[ndx1] = new Cell ** [8];
        for(ndx2 = 0; ndx2 < 8; ndx2++)
        {
            MyArray[ndx1][ndx2] = new Cell * [6];
            for(ndx3 = 0; ndx3 < 6; ndx3++)
            {
                MyArray[ndx1][ndx2][ndx3] = new Empty(ndx2, ndx3, ndx1);
            }
        }
    }

    mapOne();
    if(SpinCtrl3->GetValue() > 1)
    {
        mapTwo();
    }
    if(SpinCtrl3->GetValue() > 2)
    {
        mapThree();
    }

    wxBufferedPaintDC dc(Panel3);
    dc.Clear();
    int length = 420;
    int height = 620;

    int xdim =  length / (double)6;
    int ydim = height / (double)8;

    int x = 0;
    int y = 0;

    wxImage sizer;

    sizer.LoadFile(wxT("WavePattern.png"), wxBITMAP_TYPE_PNG);
    sizer.Rescale(length, height - 4);
    wxBitmap water(sizer);
    dc.DrawBitmap(water, 0, 0, false);

    sizer.LoadFile(wxT("S0204.png"), wxBITMAP_TYPE_PNG);
    sizer.Rescale(length, height - 4);
    wxBitmap maps(sizer);
    dc.DrawBitmap(maps, 0, 0, false);



    if(SpinCtrl3->GetValue() > 1)
    {
        sizer.LoadFile(wxT("WavePattern.png"), wxBITMAP_TYPE_PNG);
        sizer.Rescale(length, height - 4);
        wxBitmap water(sizer);
        dc.DrawBitmap(water, length + 2, 0, false);

        sizer.LoadFile(wxT("S0205.png"), wxBITMAP_TYPE_PNG);
        sizer.Rescale(length, height - 4);
        wxBitmap maps(sizer);
        dc.DrawBitmap(maps, length + 2, 0, false);
    }
    if(SpinCtrl3->GetValue() > 2)
    {
        sizer.LoadFile(wxT("WavePattern.png"), wxBITMAP_TYPE_PNG);
        sizer.Rescale(length, height - 4);
        wxBitmap water(sizer);
        dc.DrawBitmap(water, length*2 + 4, 0, false);

        sizer.LoadFile(wxT("S0301.png"), wxBITMAP_TYPE_PNG);
        sizer.Rescale(length, height - 4);
        wxBitmap maps(sizer);
        dc.DrawBitmap(maps, length*2 + 4, 0, false);
    }

    for(int i = 0; i < SpinCtrl3->GetValue(); i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(i == 0)x = 0;
            if(i == 1)x = length + 2;
            if(i == 2)x = length*2 + 4;
            for(int k = 0; k < 6; k++)
            {
                //dc.DrawRectangle(x,y,xdim,ydim);

                wxImage sizer;
                sizer.LoadFile(MyArray[i][j][k]->getName(), wxBITMAP_TYPE_PNG);
                sizer.Rescale(xdim, ydim);

                wxBitmap picture(sizer);


                dc.DrawBitmap(picture, x, y, true);

                x += xdim;
            }
            y += ydim;
        }
        y = 0;
    }
    cellCount();
    hpCount();

    m_timer.Start(1000); //1000
}

void FinalProjectFrame::checkWinner()
{
    wxBufferedPaintDC dc(Panel3);
    int length = 420;
    int height = 620;

    bool heroLifeOne = false;
    bool enemyLifeOne = false;

    bool heroLifeTwo = false;
    bool enemyLifeTwo = false;

    bool heroLifeThree = false;
    bool enemyLifeThree = false;

    wxImage sizer;



    if(!gameEnd)
    {
        if(SpinCtrl3->GetValue() > 0)
        {
            for(int j = 0; j < 8; j++)
            {
                for(int k = 0; k < 6; k++)
                {
                    if(MyArray[0][j][k]->getColor() == wxT("BLUE")||
                       MyArray[0][j][k]->getColor() == wxT("RED")||
                       MyArray[0][j][k]->getColor() == wxT("GREY")||
                       MyArray[0][j][k]->getColor() == wxT("GREEN"))
                    {
                        heroLifeOne = true;
                    }

                    if(MyArray[0][j][k]->getColor() == wxT("DARK GREEN")||
                       MyArray[0][j][k]->getColor() == wxT("INDIAN RED")||
                       MyArray[0][j][k]->getColor() == wxT("STEEL BLUE")||
                       MyArray[0][j][k]->getColor() == wxT("DARK GREY"))
                    {
                        enemyLifeOne = true;
                    }
                }
            }
            if(heroLifeOne && !enemyLifeOne)
            {
                result = wxT("HEROES WIN!");
                sizer.LoadFile(wxT("YOUWIN.png"), wxBITMAP_TYPE_PNG);
                sizer.Rescale(length, height - 4);
                wxBitmap results(sizer);
                dc.DrawBitmap(results, 0, 0, false);
            }
            else if(!heroLifeOne && enemyLifeOne)
            {
                result = wxT("YOU LOSE");
                sizer.LoadFile(wxT("YOULOSE.png"), wxBITMAP_TYPE_PNG);
                sizer.Rescale(length, height - 4);
                wxBitmap results(sizer);
                dc.DrawBitmap(results, 0, 0, false);
            }
        }
        if(SpinCtrl3->GetValue() > 1)
        {
            for(int j = 0; j < 8; j++)
            {
                for(int k = 0; k < 6; k++)
                {
                    if(MyArray[1][j][k]->getColor() == wxT("BLUE")||
                       MyArray[1][j][k]->getColor() == wxT("RED")||
                       MyArray[1][j][k]->getColor() == wxT("GREY")||
                       MyArray[1][j][k]->getColor() == wxT("GREEN"))
                    {
                        heroLifeTwo = true;
                    }

                    if(MyArray[1][j][k]->getColor() == wxT("DARK GREEN")||
                       MyArray[1][j][k]->getColor() == wxT("INDIAN RED")||
                       MyArray[1][j][k]->getColor() == wxT("STEEL BLUE")||
                       MyArray[1][j][k]->getColor() == wxT("DARK GREY"))
                    {
                        enemyLifeTwo = true;
                    }
                }
            }
            if(heroLifeTwo && !enemyLifeTwo)
            {
                result = wxT("HEROES WIN!");
                sizer.LoadFile(wxT("YOUWIN.png"), wxBITMAP_TYPE_PNG);
                sizer.Rescale(length, height - 4);
                wxBitmap results(sizer);
                dc.DrawBitmap(results, length + 2, 0, false);
            }
            else if(!heroLifeTwo && enemyLifeTwo)
            {
                result = wxT("YOU LOSE");
                sizer.LoadFile(wxT("YOULOSE.png"), wxBITMAP_TYPE_PNG);
                sizer.Rescale(length, height - 4);
                wxBitmap results(sizer);
                dc.DrawBitmap(results, length + 2, 0, false);
            }
        }
        if(SpinCtrl3->GetValue() > 2)
        {
            for(int j = 0; j < 8; j++)
            {
                for(int k = 0; k < 6; k++)
                {
                    if(MyArray[2][j][k]->getColor() == wxT("BLUE")||
                       MyArray[2][j][k]->getColor() == wxT("RED")||
                       MyArray[2][j][k]->getColor() == wxT("GREY")||
                       MyArray[2][j][k]->getColor() == wxT("GREEN"))
                    {
                        heroLifeThree = true;
                    }

                    if(MyArray[2][j][k]->getColor() == wxT("DARK GREEN")||
                       MyArray[2][j][k]->getColor() == wxT("INDIAN RED")||
                       MyArray[2][j][k]->getColor() == wxT("STEEL BLUE")||
                       MyArray[2][j][k]->getColor() == wxT("DARK GREY"))
                    {
                        enemyLifeThree = true;
                    }
                }
            }
            if(heroLifeThree && !enemyLifeThree)
            {
                result = wxT("HEROES WIN!");
                sizer.LoadFile(wxT("YOUWIN.png"), wxBITMAP_TYPE_PNG);
                sizer.Rescale(length, height - 4);
                wxBitmap results(sizer);
                dc.DrawBitmap(results, length*2 + 4, 0, false);
            }
            else if(!heroLifeThree && enemyLifeThree)
            {
                result = wxT("YOU LOSE");
                sizer.LoadFile(wxT("YOULOSE.png"), wxBITMAP_TYPE_PNG);
                sizer.Rescale(length, height - 4);
                wxBitmap results(sizer);
                dc.DrawBitmap(results, length*2 + 4, 0, false);
            }
        }
    }
    if(SpinCtrl3->GetValue() == 1)
    {
        if(!heroLifeOne || !enemyLifeOne)
        {
            gameEnd = true;
            m_timer.Stop();
        }
    }
    if(SpinCtrl3->GetValue() == 2)
    {
        if((!heroLifeOne || !enemyLifeOne) && (!heroLifeTwo || !enemyLifeTwo))
        {
            gameEnd = true;
            m_timer.Stop();
        }
    }
    if(SpinCtrl3->GetValue() == 3)
    {
        if((!heroLifeOne || !enemyLifeOne) && (!heroLifeTwo || !enemyLifeTwo) && (!heroLifeThree || !enemyLifeThree))
        {
            gameEnd = true;
            m_timer.Stop();
        }
    }
}

void FinalProjectFrame::OnSpinCtrl1Change(wxSpinEvent& event)
{

}

void FinalProjectFrame::OnSpinCtrl2Change(wxSpinEvent& event)
{

}

void FinalProjectFrame::OnSpinCtrl3Change(wxSpinEvent& event)
{
    if (SpinCtrl3->GetValue() > 3)
    {
        wxMessageBox (wxT("Max number of levels is 3"));
        SpinCtrl3->SetValue(3);
    }

    if (SpinCtrl3->GetValue() < 1)
    {
        wxMessageBox (wxT("Min number of levels is 1"));
        SpinCtrl3->SetValue(1);
    }
}

void FinalProjectFrame::OnTimer(wxTimerEvent& event)
{

    int numrows = 8;
    int numcols = 6;
    int numlays = SpinCtrl3->GetValue();


    for(int i = 0; i < numlays; i++)
        {
            for(int j = 0; j < numrows; j++)
            {
                for(int k = 0; k < numcols; k++)
                {
                    MyArray[i][j][k]->tick(MyArray, numrows, numcols, numlays);
                }
            }
        }
    cellCount();
    hpCount();






    //delete [] orderArray;

    if(!gameEnd)
    {
        wxBufferedPaintDC dc(Panel3);

        dc.Clear();


        int length = 420;
        int height = 620;
        int xdim =  length / (double)numcols;
        int ydim = height / (double)numrows;

        int x;
        int y = 0;
        wxImage sizer;

        sizer.LoadFile(wxT("WavePattern.png"), wxBITMAP_TYPE_PNG);
        sizer.Rescale(length, height - 4);
        wxBitmap water(sizer);
        dc.DrawBitmap(water, 0, 0, false);

        sizer.LoadFile(wxT("S0204.png"), wxBITMAP_TYPE_PNG);
        sizer.Rescale(length, height - 4);
        wxBitmap maps(sizer);
        dc.DrawBitmap(maps, 0, 0, false);



        if(SpinCtrl3->GetValue() > 1)
        {
            sizer.LoadFile(wxT("WavePattern.png"), wxBITMAP_TYPE_PNG);
            sizer.Rescale(length, height - 4);
            wxBitmap water(sizer);
            dc.DrawBitmap(water, length + 2, 0, false);

            sizer.LoadFile(wxT("S0205.png"), wxBITMAP_TYPE_PNG);
            sizer.Rescale(length, height - 4);
            wxBitmap maps(sizer);
            dc.DrawBitmap(maps, length + 2, 0, false);
        }
        if(SpinCtrl3->GetValue() > 2)
        {
            sizer.LoadFile(wxT("WavePattern.png"), wxBITMAP_TYPE_PNG);
            sizer.Rescale(length, height - 4);
            wxBitmap water(sizer);
            dc.DrawBitmap(water, length*2 + 4, 0, false);

            sizer.LoadFile(wxT("S0301.png"), wxBITMAP_TYPE_PNG);
            sizer.Rescale(length, height - 4);
            wxBitmap maps(sizer);
            dc.DrawBitmap(maps, length*2 + 4, 0, false);
        }



        for(int i = 0; i < numlays; i++)
        {
            for(int j = 0; j < numrows; j++)
            {
                if(i == 0)x = 0;
                if(i == 1)x = length + 2;
                if(i == 2)x = length*2 + 4;
                for(int k = 0; k < numcols; k++)
                {

                    wxImage sizer;
                    sizer.LoadFile(MyArray[i][j][k]->getName(), wxBITMAP_TYPE_PNG);
                    sizer.Rescale(xdim, ydim);

                    wxBitmap picture(sizer);

                    dc.DrawBitmap(picture, x, y, true);

                    x += xdim;
                }
                y += ydim;
            }
            y = 0;
        }
    }
    checkWinner();

}

void FinalProjectFrame::cellCount()
{
    heroCount = 0;
    enemyCount = 0;

    for(int i = 0; i < SpinCtrl3->GetValue(); i++)
    {
        for(int j = 0; j < 8; j++)
        {
            for(int k = 0; k < 6; k++)
            {
                if(MyArray[i][j][k]->getColor() == wxT("RED")  ||
                   MyArray[i][j][k]->getColor() == wxT("BLUE") ||
                   MyArray[i][j][k]->getColor() == wxT("GREEN")||
                   MyArray[i][j][k]->getColor() == wxT("GREY"))
                {
                    heroCount++;
                }
                else if(MyArray[i][j][k]->getColor() == wxT("INDIAN RED") ||
                        MyArray[i][j][k]->getColor() == wxT("STEEL BLUE") ||
                        MyArray[i][j][k]->getColor() == wxT("DARK GREEN") ||
                        MyArray[i][j][k]->getColor() == wxT("DARK GREY"))
                {
                    enemyCount++;
                }
            }
        }
    }

    StaticText4->SetLabel(wxString::Format(wxT("Hero: %i"), heroCount));
    StaticText5->SetLabel(wxString::Format(wxT("Enemy: %i"), enemyCount));
}

void FinalProjectFrame::hpCount()
{
    for(int i = 0; i < SpinCtrl3->GetValue(); i++)
    {
        for(int j = 0; j < 8; j++)
        {
            for(int k = 0; k < 6; k++)
            {
                if(MyArray[i][j][k]->getColor() == wxT("GREEN"))
                {
                    StaticText8->SetLabel(wxString::Format(wxT("Camilla: %i"), MyArray[i][j][k]->getHP()));
                }
                if(MyArray[i][j][k]->getColor() == wxT("DARK GREEN"))
                {
                    StaticText9->SetLabel(wxString::Format(wxT("Armor Axe: %i"), MyArray[i][j][k]->getHP()));
                }
            }
        }
    }
}

void FinalProjectFrame::OnPanel3Paint(wxPaintEvent& event)
{
}

void FinalProjectFrame::OnPanel2Paint(wxPaintEvent& event)
{
}

void FinalProjectFrame::OnButton2Click(wxCommandEvent& event)
{
    wxFileDialog *SaveDialog = new wxFileDialog(
		this, _("Save File As _?"), wxEmptyString, wxEmptyString,
		_("Text files (*.txt)|*.txt|C++ Source Files (*.cpp)|*.cpp|C Source files (*.c)|*.c|C header files (*.h)|*.h"),
		wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

	// Creates a Save Dialog with 4 file types
	if (SaveDialog->ShowModal() == wxID_OK && gameEnd == true) // If the user clicked "OK"
	{
	    LoadBox->Clear();
	    wxString myString;

	    LoadBox->AppendText("Layers: \n");
	    myString = wxEmptyString;
	    myString << SpinCtrl3->GetValue();
	    LoadBox->AppendText(myString);
	    LoadBox->AppendText("\n\n");
	    LoadBox->AppendText(result);


		CurrentDocPath = SaveDialog->GetPath();
		// set the path of our current document to the file the user chose to save under
		LoadBox->SaveFile(CurrentDocPath); // Save the file to the selected path
	}
	else
    {
        wxMessageBox("Nothing Saved");
    }

	// Clean up after ourselves
	SaveDialog->Destroy();
}

void FinalProjectFrame::OnButton3Click(wxCommandEvent& event)
{
    wxFileDialog* OpenDialog = new wxFileDialog(
		this, _("Choose a url file to open"), wxEmptyString, wxEmptyString,
		_("Text files (*.txt)|*.txt|C++ Source Files (*.cpp, *.cxx)|*.cpp;*.cxx|C Source files (*.c)|*.c|C header files (*.h)|*.h"),
		wxFD_OPEN, wxDefaultPosition);

	// Creates a "open file" dialog with 4 file types
	if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
	{
	    LoadBox->Clear();
		CurrentDocPath = OpenDialog->GetPath();
		// Sets our current document to the file the user selected
		LoadBox->LoadFile(CurrentDocPath); //Opens that file

		SpinCtrl3->SetValue(LoadBox->GetLineText(1));
	}

	// Clean up after ourselves
	OpenDialog->Destroy();
}

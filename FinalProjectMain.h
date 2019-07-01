#ifndef FINALPROJECTMAIN_H
#define FINALPROJECTMAIN_H

//(*Headers(FinalProjectFrame)
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)
#include <wx/timer.h>
#include <wx/image.h>
#include <wx/dc.h>
#include <wx/bitmap.h>
#include <wx/textctrl.h>
#include "Cell.h"
#include "HeroInfantrySwordIke.h"
#include "HeroInfantryLanceLucina.h"
#include "HeroInfantryAxeAzura.h"
#include "HeroCalvarySwordSeigbert.h"
#include "HeroCalvarySpearEphraim.h"
#include "HeroCalvaryAxeTitania.h"
#include "HeroFlierSwordElincia.h"
#include "HeroFlierLanceCordelia.h"
#include "HeroFlierAxeCamilla.h"
#include "HeroArmorSwordZelgius.h"
#include "HeroArmorLanceEffie.h"
#include "HeroArmorAxeHector.h"
#include "HeroDaggerKagero.h"
#include "HeroArcherKlein.h"
#include "EnemyInfantrySword.h"
#include "EnemyInfantryLance.h"
#include "EnemyInfantryAxe.h"
#include "EnemyCalvarySword.h"
#include "EnemyCalvaryLance.h"
#include "EnemyCalvaryAxe.h"
#include "EnemyArmorSword.h"
#include "EnemyArmorLance.h"
#include "EnemyArmorAxe.h"
#include "EnemyFlierSword.h"
#include "EnemyFlierLance.h"
#include "EnemyFlierAxe.h"
#include "EnemyArcher.h"
#include "EnemyDagger.h"
#include "FlyerPass.h"
#include "CalvaryImpass.h"
#include "Emptycell.h"

#define TIMER_ID 1000

class FinalProjectFrame: public wxFrame
{
    public:

        FinalProjectFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~FinalProjectFrame();

    private:

        //(*Handlers(FinalProjectFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnSpinCtrl1Change(wxSpinEvent& event);
        void OnPanel2Paint(wxPaintEvent& event);
        void OnSpinCtrl2Change(wxSpinEvent& event);
        void OnSpinCtrl3Change(wxSpinEvent& event);
        void OnPanel3Paint(wxPaintEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        //*)
        void updateGame();
        void tick();
        void checkWinner();
        void OnTimer(wxTimerEvent& event);
        void cellCount();
        void hpCount();
        void mapOne();
        void mapTwo();
        void mapThree();

        //(*Identifiers(FinalProjectFrame)
        static const long ID_SPINCTRL3;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_BUTTON3;
        static const long ID_PANEL2;
        static const long ID_PANEL3;
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT10;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(FinalProjectFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxStaticText* StaticText10;
        wxPanel* Panel2;
        wxStaticText* StaticText3;
        wxStaticLine* StaticLine1;
        wxSpinCtrl* SpinCtrl3;
        wxStaticText* StaticText8;
        wxPanel* Panel3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText9;
        //*)

        Cell **** MyArray;
        bool gameEnd;
        wxTimer m_timer;
        int heroCount;
        int enemyCount;
        int hpBar;
        wxColor test;
        wxString CurrentDocPath;
        wxTextCtrl *LoadBox;
        wxString result;

        DECLARE_EVENT_TABLE()
};

#endif // FINALPROJECTMAIN_H

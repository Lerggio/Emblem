#include "wx_pch.h"
#include "FinalProjectApp.h"

//(*AppHeaders
#include "FinalProjectMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(FinalProjectApp);

bool FinalProjectApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	FinalProjectFrame* Frame = new FinalProjectFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

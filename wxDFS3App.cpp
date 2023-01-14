/***************************************************************
 * Name:      wxDFS3App.cpp
 * Purpose:   Code for Application Class
 * Author:    hw ()
 * Created:   2019-12-07
 * Copyright: hw ()
 * License:
 **************************************************************/

#include "wxDFS3App.h"

//(*AppHeaders
#include "wxDFS3Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxDFS3App);

bool wxDFS3App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxDFS3Frame* Frame = new wxDFS3Frame(0);

    	//Frame->SetTitle((wxDateTime::Now().Format("DFS Maze: %x on ")+wxGetHostName()+":"+ wxGetenv ("USER")));
    	Frame->SetTitle((wxDateTime::Now().Format("DFS Maze: %x on ")+wxGetHostName()));
    	//Frame->SetTitle((wxDateTime::GetAsDOS() + wxGetHostName()));
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

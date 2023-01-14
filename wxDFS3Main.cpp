/*********************************************************
 * Name:      wxDFS3Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    hw ()
 * Created:   2019-12-07
 * Copyright: hw ()
 * License:
 *  Had to set wxPaintDC(Panel1) <<<< not 'this' 20191209 H. Watson
 * reworking to bring into sync with CodeChallenge TRLB
 **************************************************************/

#include "wxDFS3Main.h"
#include <wx/msgdlg.h>

using namespace std; //<< this is for cout redirected to wxTextCtrl


//(*InternalHeaders(wxDFS3Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
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

//(*IdInit(wxDFS3Frame)
const long wxDFS3Frame::ID_PANEL1 = wxNewId();
const long wxDFS3Frame::ID_TEXTCTRL2 = wxNewId();
const long wxDFS3Frame::ID_BUTTON1 = wxNewId();
const long wxDFS3Frame::ID_BUTTON3 = wxNewId();
const long wxDFS3Frame::ID_BUTTON4 = wxNewId();
const long wxDFS3Frame::ID_BUTTON2 = wxNewId();
const long wxDFS3Frame::ID_TEXTCTRL1 = wxNewId();
const long wxDFS3Frame::idMenuQuit = wxNewId();
const long wxDFS3Frame::idMenuAbout = wxNewId();
const long wxDFS3Frame::ID_STATUSBAR1 = wxNewId();
const long wxDFS3Frame::ID_TIMER1 = wxNewId();
const long wxDFS3Frame::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxDFS3Frame,wxFrame)
    //(*EventTable(wxDFS3Frame)
    //*)
END_EVENT_TABLE()

wxDFS3Frame::wxDFS3Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxDFS3Frame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(600,800));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(500,500), 0, _T("ID_PANEL1"));
    BoxSizer1->Add(Panel1, 10, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Date & Time"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer2->Add(TextCtrl2, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Step"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Solve"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer2->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Stop"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Log Window\n"), wxDefaultPosition, wxSize(450,200), wxTE_MULTILINE|wxTE_RICH, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer1->Add(TextCtrl1, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
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
    Timer1.SetOwner(this, ID_TIMER1);
    MessageDialog1 = new wxMessageDialog(this, _("This is my message"), _("Message"), wxOK|wxCANCEL, wxDefaultPosition);
    SetSizer(BoxSizer1);
    Layout();

    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&wxDFS3Frame::OnPanel1Paint,0,this);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxDFS3Frame::OnButton1Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxDFS3Frame::OnButtonStepClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxDFS3Frame::OnButton4Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxDFS3Frame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxDFS3Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxDFS3Frame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&wxDFS3Frame::OnTimer1Trigger);
    //*)
    //this->SetBackgroundStyle(wxBG_STYLE_TRANSPARENT);
    MyString = new wxString ("Timed program randomly fills nodes \n");
    MyStringOffset = MyString->begin();
    Maze MyPath;  //<<<<<<<<<constructor
    Maze MyCopy;  // back copy to draw solution paths constructor
    MyCopyDraw = false;  // don't draw the copy, but the original

}

wxDFS3Frame::~wxDFS3Frame()
{
    //(*Destroy(wxDFS3Frame)
    //*)
}

void wxDFS3Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxDFS3Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxDFS3Frame::OnTimer1Trigger(wxTimerEvent& event)
{	static int edgeCounter;
    static int randmix[4];

    wxStreamToTextRedirector redirect(TextCtrl1); // sends cout to TextCtrol within context <<<<<<<<
    /*  TimerTick State machine
    *   States:  {TInit, TDir0, TDir1, TDir2, TDir3, TNextCell} TStep;
    *
    *
    */
    switch(MyPath.TickState)
    {
    case TInit:
        // init the Maze for DFS
        // current = grid[0] starting location;
        MyPath.InitExplore();
        cout << "State: TInit" << endl;
        break;

	case TNextCell:
		// get new current cell from stack
		// current(squirrel) = stack.pop()
		MyPath.NewCurrentFromStack();
		edgeCounter = 0;
		break;

	case TTryEdges:  // check neighbors
	// dir 3  left - dx:-1  dy: 0
	// dir 0  up     dx: 0   dy:-1
	// dir 1  right  dx:+1   dy: 0
	// dir 2  down   dx: 0   dy:+1
	//  do 4 times with random sequence
		switch(edgeCounter)
		{

			case 0: // up
			    // reset the Edges temp list
                MyPath.Edges.erase (MyPath.Edges.begin(),MyPath.Edges.end());
                // check the edges and add to temp list  from is last parameter
			    MyPath.TryEdge (0, -1, 0);
				edgeCounter++;
				break;
			case 1: // right
			    MyPath.TryEdge (1, 0, 1);
				edgeCounter++;
				break;
			case 2: // down
			    MyPath.TryEdge (0, 1, 2);
			    edgeCounter++;
				break;
			case 3: // left
			    MyPath.TryEdge( -1, 0, 3);
				edgeCounter++;
				break;

            case 4: // if .NZ. randomize edges, push onto MStack for TNextCell process
                cout << "State 4: randomize edges push onto stack" << endl;
                int numEdges;
               	edgeCounter=0;
                  /* initialize random seed: */
                  srand (time(NULL));
				MyPath.TickState = TNextCell;
                 numEdges= MyPath.Edges.size();
                if (numEdges > 0)
                    {
                    for (int i=0; i<4; i++){randmix[i]=i;} // number elements
                    for (int i=0; i<numEdges; i++){swap(randmix[i],randmix[rand()%numEdges]);} // shuffle
                     //for (int i=0; i<numEdges; i++)
                        { int i=0; // only one neighbor, not more
                        int r = randmix[i];
                        Cell CTemp = MyPath.Edges[r];
                        MyPath.MStack.push(CTemp);
                        MyPath.MazeSetCellColor(CTemp.x, CTemp.y, lightGrey);
                        }
                    }
                break;

			default:
                break;
		}
		break;


    case TDoNothing:
        // this should be the end of the program
        cout << "Stack Empty, Timer Stop: Loop at TDoNothing" << endl;
        Timer1.Stop();  // stop
        break;
    //

    default:
        cout <<"Undefined State : "<< MyPath.TickState << endl;
        break;

    }

    this->Refresh();

}






void wxDFS3Frame::OnPanel1Paint(wxPaintEvent& event)
{
     wxBufferedPaintDC dc(Panel1);

    dc.SetTextBackground( wxColour( 255, 255, 255 ) );
    dc.SetTextForeground( wxColour( 0, 0, 0 ) );
    dc.SetBackground(*wxLIGHT_GREY_BRUSH);
     dc.Clear();
    // draw background rectangle
  //  int P1w, P1h; // width and height
  //  dc.GetSize(&P1w, &P1h);
  //  dc.DrawRectangle(0,0,P1w,P1h);
    //
    if (MyCopyDraw)
    {
        MyCopy.MazeDraw(dc);
        MyCopyDraw = false; // clear the variable
    }
    else
    {  // false, just draw original
        MyPath.MazeDraw(dc);
    }

}


//Maze variables:
//Cell:  current, explore

void Maze::InitExplore()
{
	//get current  insize Maze
	//init direction array (random sequence)
        // set start square to 0,0
        MazeSetCellColor(StartX,StartY,red);  // set start cell to red
        current = MazeGetCell(StartX,StartY);  ///push starting cell onto stack
        current.from = 5; // ignore first cell

        MazeSetFrom(StartX,StartY,5);  // mark in permanent cell
        // push onto stack to start DFS
        MStack.push(current);
        TickState = TNextCell;  // now process the first cell neighbors
        cout << "TInit - Cells on Stack: " << MStack.size()<< endl;
}

void Maze::NewCurrentFromStack ()
{ //  return stack empty- TDoNothing, next is already visited - TNextCell, Explore all 4 directions - TExplore
        Cell parent;
	    // pop and explore next cell
        if(MStack.empty())
        {
            cout<< "Stack empty, State set to TDoNothing" << endl;
            TickState = TDoNothing;
            return;
        }

        if(MazeGetCell(current.x,current.y).from !=5)
        {
           // mark the old current with path color as taken and finished
            MazeSetCellColor(current.x, current.y, green);
         }
       // now get the new current <<<<< wherre is current? insice Maze
        parent = current; // keep parent value
        current = MStack.top();
        MStack.pop();

        //if(current.visited)
        if (MazeGetCell(current.x, current.y).visited)
        {   // backtracking,
            // this cell already visited, so don't explore, so pull next off stack
            cout<<"(" << current.x << ", " << current.y <<
                ") already visited, MStack:" << MStack.size() << endl;
            TickState = TNextCell;  //<<<<<<go to next cell again
            return;
        }

        cout << "Pop New Current: (" << current.x <<", " <<current.y << ") parent edge : " ;
          // print the get from direction
          cout << current.from << " " ;
          // have to recreate parent coordinates
          int refx = current.x;
          int refy = current.y;
          MazeSetFrom(refx,refy,current.from);  // mark in permanent cell
          //
          //switch(current.from)
          switch(5)
          {

//              case 0:  cout << "top" << endl;  break;
//              case 1:  cout << "right" << endl;  break;
//              case 2:  cout << "bottom" << endl; break;
//              case 3:  cout << "left" << endl; break;
            // backtrack directions
              case 0:  //walls: current 2, parent 0
                    cout << "bottom " ;
                     MazeSetWall(refx, refy, 2, false); // current
                     MazeSetWall(refx, refy+1, 0, false); // parent reconstructed
                    break;
              case 1:  //walls: current 3, parent 1
                    cout << "left ";
                    MazeSetWall(refx, refy, 3, false); // current
                    MazeSetWall(refx-1, refy, 1, false); // parent reconstructed
                    break;
              case 2:   //walls: current 0, parent 2
                    cout << "top ";
                    MazeSetWall(refx, refy, 0, false); // current
                    MazeSetWall(refx, refy-1, 2, false); // parent reconstructed
                    break;
              case 3:  //walls: currrent 1, parent 3
                    cout << "right ";
                    MazeSetWall(refx, refy, 1, false); // current
                    MazeSetWall(refx+1, refy, 3, false); // parent reconstructed
                    break;

              default:
                  break;
                    //cout << endl;
          }
        // if original is already visited leave alone, already been there
        if(!MazeGetCell(current.x, current.y).visited ) //
        {
            // mark current 'red' in the Maze
            MazeSetCellColor(current.x, current.y, red);
            MazeSetCellVisited(current.x, current.y, true);

        }


        cout << " MStack:" << MStack.size() <<  endl;
			TickState = TTryEdges; // explore all 4 edges
        return ; //<< now explore all 4 directions
}


//Edges to explore
// TRBL
// upper dx=0, dy=-1  trying dir = 0; upper left is 0,0
// right dx=1, dy=0   trying dir = 1
// down dx=0, dy=1    trying dir = 2
// left dx=-1, dy=0   trying dir =3
void Maze::TryEdge (int dx, int dy, int from)
{                              //    ^^^^^^^
		// now we are inside the Maze object, so can see private and public variables
		if ((current.x)+dx <0 || (current.y)+dy <0 || (current.x)+dx > cols-1 || (current.y)+dy > rows-1)
		{
			cout << "Try Edge: (" << dx << "," << dy << ") edge:" << from << " Out of bounds" << endl;
			return ;
		}

		// get edge cell contents
		explore = MazeGetCell((current.x)+dx, (current.y)+dy);
		 if (explore.visited)
         {
             cout << "Try Edge: (" << dx << "," << dy <<")  edge:" << from << " Already visited" << endl;
             return ;
         }
		 // mark in the Maze
		 MazeSetCellColor((current.x)+dx, (current.y)+dy, pink);
		 explore.from = from;  // from direction from parent
		 Edges.push_back(explore);
		 cout << "Try Edge: (" << dx << "," << dy << ") edge:" << from << " saved on EdgeStack#:" << Edges.size() << endl;
		 return;
}

//void Maze::MazeDraw(wxPaintDC& dc)
void Maze::MazeDraw(wxBufferedPaintDC& dc)
{
    Cell MyCell; // actual square to draw
    int Xdot, Ydot;
    wxString text;  // label text
   // text.SetBackgroundColour(wxTransparentColour);

// do X axis labels
    Ydot = YUpL-20;
    for (int x=0; x<cols; x++)
    {
        Xdot = XUpL + x*(Cell_Width+Cell_Gap);
        text.Printf(wxT("%2d"),x);
        dc.DrawText(text,Xdot, Ydot);
    }
// do Y axis labels;
    Xdot = XUpL-20;
    for (int y=0; y<rows; y++)
    {
        Ydot = YUpL  + y*(Cell_Height+Cell_Gap);
        text.Printf(wxT("%2d"),y);
        dc.DrawText(text,Xdot, Ydot);
    }


    for (int y=0; y<rows; y++)  // y cell number - i
        for(int x=0; x<cols; x++)  // x cell number - j
        {
            // need to map cell number into physical address
            MyCell = MNodes[MazeIndex(x,y)];  // get physical cell at x,y
            // now map cell location onto physical dot on panel
            Xdot = XUpL + x*(Cell_Width+Cell_Gap);
            Ydot = YUpL + y*(Cell_Height+Cell_Gap);
            // cell draw onto the panel
            // draw Cell DrawRectangle rectangle with
            //physical top left corner, and with width, height
            //dc.DrawRectangle (MyCell.x, MyCell.y, Cell_Width, Cell_Height );
            //dc.SetBrush(*wxGREY_BRUSH); ... this is correct
            // dc.SetPen( wxPen( wxColor(255,0,0), 1 ) ); // 10-pixels-thick pink outline


            // since we a drawing whole maze, select custom color for this single cell
            wxBrush BRpink(wxColour(0xf8, 0xc6, 0xe7),wxBRUSHSTYLE_SOLID );


            switch(MyCell.GetColor())
            {
            case grey:
                dc.SetBrush(*wxGREY_BRUSH);
                break;

            case red:  // highlight color
                dc.SetBrush(*wxRED_BRUSH);
               // dc.SetBrush(highlight);
                break;

            case green:
                dc.SetBrush(*wxGREEN_BRUSH);
                break;

            case blue:
                dc.SetBrush(*wxBLUE_BRUSH);
                break;

            case lightGrey:
                dc.SetBrush(*wxLIGHT_GREY_BRUSH);
                break;

            case pink:
               dc.SetBrush(BRpink);
                break;

            case cyan:
                dc.SetBrush(*wxCYAN_BRUSH);
                break;


            default:
                break;
            }
            // Background  current pen is used for the outline and the current brush for filling the shape.
            dc.SetPen(wxPen( *wxTRANSPARENT_PEN));
            // fill space between squares
            dc.DrawRectangle( Xdot, Ydot, Cell_Width+Cell_Gap, Cell_Height+Cell_Gap );
            /*  Cell representation
            *            .top  '.' is upper left corner of current cell x,y
            *        left |0| right
            *            bottom
            */

            // Draw Cell Walls
            if(1)  // turn walls off
            {
                //dc.SetPen( wxPen( wxColor(0,0,0), 1 ) ); // black line, 3 pixels thick
                dc.SetPen(wxPen( *wxBLACK, 2));

                //draw MyCell   0 top, 1 left, 2 bottom, 3 right
                // 0 TOP
                if (MyCell.GetWallFlag(0))
                    dc.DrawLine(Xdot, Ydot, Xdot+Cell_Width, Ydot);
                // 3 LEFT
                if (MyCell.GetWallFlag(3))
                    dc.DrawLine(Xdot, Ydot, Xdot, Ydot+Cell_Height);
                // 2 BOTTOM
                if (MyCell.GetWallFlag(2))
                    dc.DrawLine(Xdot, Ydot+Cell_Height, Xdot+Cell_Width, Ydot+Cell_Height);
                // 1 RIGHT
                if (MyCell.GetWallFlag(1))
                    dc.DrawLine(Xdot+Cell_Width, Ydot, Xdot+Cell_Width, Ydot+Cell_Height);
            }
        }

}

void Maze::PrintEdges(void)
{
    // print the edge values from the Maze array
    for (int y=0; y<rows; y++)
    {
        for (int x=0; x<cols; x++)
        {
            cout << MNodes[MazeIndex(x,y)].from << "  ";
        }
        cout << endl;
    }
}

void Maze::FindSolution(int x, int y)
{

// new version
    /*          Edge
    *  (dx,dy) direction
    *  (1,0)    3
    *  (0,1)    0
    *  (-1,0)   1
    *  (0,-1)   2
    */

int Gx, Gy; //goal x and y (retrace start point)
    Gx = x;
    Gy = y;
bool loopFlag=true; // loop while true
bool firstTime=true; // first time in loop
int xfrom;
    while (loopFlag)
    {
        if(firstTime)
        {
         MazeSetCellColor(Gx, Gy, pink); // set permanent color in Maze
         firstTime=false; // do this once only
        }
        else
        //xfrom = MazeGetCell(Gx,Gy).from;
        //if( xfrom != 5)
        //   {
               MazeSetCellColor(Gx, Gy, blue); // set permanent color in Maze
         //  }

        switch (MazeGetCell(Gx,Gy).from)  //get the entry edge<<<<<<<<)
        {
        case 3:
            Gx = Gx+1;
            break;
        case 0:
            Gy = Gy+1;
            break;
        case 1:
            Gx = Gx-1;
            break;
        case 2:
            Gy = Gy-1;
            break;
        default:
            loopFlag=false ;// time to quit
            MazeSetCellColor(Gx, Gy, red); // set permanent color in Maze
        }

    }

}

void wxDFS3Frame::OnButton1Click(wxCommandEvent& event)

{
    MyPath.StartX=0;
    MyPath.StartY=0;
    wxTextEntryDialog dialog(this, "Create Maze from graph Origin",
                             "Please enter the Origin coordinates",
                             "X: 0\nY: 0",
                             wxOK  | wxCANCEL | wxTE_MULTILINE);

    if (dialog.ShowModal() == wxID_OK)
    {
       sscanf(dialog.GetValue(), "X:%d Y:%d", &MyPath.StartX, &MyPath.StartY);
       cout << "StartX: " << MyPath.StartX << " StartY: " << MyPath.StartY << endl;
    }
    TextCtrl2->Clear();
    TextCtrl2->AppendText(wxDateTime::Now().Format("%c"));
    Timer1.Start(20, false); //start
}

void wxDFS3Frame::OnButton2Click(wxCommandEvent& event)
{
    Timer1.Stop();  // stop
}

void wxDFS3Frame::OnButtonStepClick(wxCommandEvent& event)
{
    Timer1.Start(20, true); // step
}

void wxDFS3Frame::OnButton4Click(wxCommandEvent& event)
{
    int goalX, goalY;
//    copy original to working
    std::copy(MyPath.MNodes.begin(), MyPath.MNodes.end(), MyCopy.MNodes.begin());
    wxTextEntryDialog dialog(this, "The run solution to graph origin",
                             "Please enter the GOAL coordinates",
                             "X: \nY: ",
                             wxOK  | wxCANCEL | wxTE_MULTILINE);

    if (dialog.ShowModal() == wxID_OK)
    {
       sscanf(dialog.GetValue(), "X:%d Y:%d", &goalX, &goalY);
       cout << "goalX: " << goalX << " goalY: " << goalY << endl;
    }
      //MyCopy.MazeSetCellColor(goalX, goalY, blue); // set permanent color in Maze
      MyCopy.FindSolution(goalX, goalY);
    // here

    MyCopyDraw = true; // tell handler to draw the copy
    Panel1->Refresh();
    MyCopy.PrintEdges(); // print all the edges
    // restore original content
    //std::copy(MyCopy.MNodes.begin(), MyCopy.MNodes.end(), MyPath.MNodes.begin());
}




/***************************************************************
 * Name:      wxDFS3Main.h
 * Purpose:   Defines Application Frame
 * Author:    hw ()
 * Created:   2019-12-07
 * Copyright: hw ()  This is working FIU Version 1/09/20
 * License:
 * reworking to bring into sync with CodeChallenge TRLB
 **************************************************************/

 #include <wx/dcclient.h>
 #include <stack>
 #include <vector>
 #include <wx/textdlg.h>
 #include <wx/numdlg.h>
 #include <wx/tokenzr.h>
 #include <wx/dcbuffer.h>


#ifndef wxDFS3MAIN_H
#define wxDFS3MAIN_H

//(*Headers(wxDFS3Frame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/msgdlg.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)

// individual cell components
#define Cell_Width 20  // each cell dimensions
#define Cell_Height 20
#define Cell_Gap 3

typedef enum eColor { grey, red, green, blue, lightGrey, pink, cyan } myColor;
typedef enum eSteps {TInit, TNextCell, TDoNothing, TTryEdges} TStep;


class Cell {



        bool WallFlag[4]; // 0 top, 1 right, 2 bottom, 3 left

        myColor CellColor;
     public:
        int x, y;       // physical location of cell top left corner
        bool visited;
        int from;
    Cell (){};
    Cell(int x, int y, myColor CellColor){
         for(int i=0; i<4; i++) WallFlag[i] = true;
         //WallFlag[3] = false; // blank for testing
         this->x = x;
         this->y = y;
         this->CellColor = CellColor;
         this->visited=false;
         this->from=8;
    };

    myColor GetColor(){ return this->CellColor; };
    //    // set color of single cell from within the Maze
    void SetColor(myColor CellColor){this->CellColor = CellColor;};

    bool GetWallFlag(int v){ return this->WallFlag[v];};
    bool SetWallFlag(int v, bool bval){ return this->WallFlag[v]=bval;}

    bool SetCellVisited(bool bval){return this->visited = bval;}
    void SetCellFrom(int from){this->from = from;}


};


class Maze {
    int rows, cols; // number of cells
    int XUpL, YUpL ; // offset for the Upper left part of Maze


public:
    std::vector <Cell> MNodes;  // MNodes=maxe, mStack=to be visited

    std::stack <Cell>  MStack;
    std::vector <Cell> Edges;  // temporary Edges stack
    TStep TickState;
    Cell current, explore;
    int StartX, StartY; // origin of maze


    Maze()
    {
        cols = 20;
        rows = 20;
        XUpL = 25; // out and down from upper left square
        YUpL = 20;
        TickState=TInit;

        for (int i=0; i<rows; i++)  // y cell number
            for(int j=0; j<cols; j++)  // x cell number
                MNodes.push_back(Cell(j,i, lightGrey));
               // MNodes.push_back(Cell(j,i, green));

       // MazeSetCellColor(1,0,red);  // why can't refresh?
    };
    int MazeIndex (int X, int Y){return X + Y*cols;}

    void MazeDraw(wxBufferedPaintDC& dc); // <<<<<<<<<<
    // void MazeDraw(wxPaintDC& dc); // <<<<<<<<<<
    //void MazeDraw();

    Cell MazeGetCell(int x, int y) { return MNodes[MazeIndex(x,y)];}

    void MazeSetCellColor(int x, int y, myColor c){MNodes[MazeIndex(x,y)].SetColor(c);}
    void MazeSetCellVisited(int x, int y, bool value){MNodes[MazeIndex(x,y)].SetCellVisited(value);}
    void MazeSetWall(int x, int y, int v, bool bval){MNodes[MazeIndex(x,y)].SetWallFlag(v, bval);}
    void MazeSetFrom(int x, int y, int from){MNodes[MazeIndex(x,y)].SetCellFrom(from);}

    int MazeGetCols() {return cols;}
    int MazeGetRows() {return rows;}

    void InitExplore(); // set start square and begin DFS process
    void NewCurrentFromStack();  // set current

    void TryEdge (int dx, int dy, int from);
    void PrintEdges (void); // print edge values from Maze array
    void FindSolution (int x, int y);

};


class wxDFS3Frame: public wxFrame
{
    public:

        wxDFS3Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxDFS3Frame();

    private:

        //(*Handlers(wxDFS3Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButtonStepClick(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxDFS3Frame)
        static const long ID_PANEL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        static const long ID_MESSAGEDIALOG1;
        //*)

        //(*Declarations(wxDFS3Frame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxMessageDialog* MessageDialog1;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTimer Timer1;
        //*)
        wxString* MyString;
        wxString::iterator MyStringOffset;// = MyString->begin();
        Maze MyPath;  //<<<<<<<<<declaration
        Maze MyCopy;  // back copy to draw solution paths
        bool MyCopyDraw;  // select MyCopy to draw
        std::stack<Cell> MyStack; // declaration

        DECLARE_EVENT_TABLE()
};

#endif // wxDFS3MAIN_H


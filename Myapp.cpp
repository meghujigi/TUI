#include "Myapp.h"
#include "TechInfo.h"
const int cmMyFileOpen = 200;
const int cmMyNewWin   = 201;

static short winNumber = 0;

TMyApp::TMyApp() :
    TProgInit(&TMyApp::initStatusLine,
              &TMyApp::initMenuBar,
              &TMyApp::initDeskTop)
{
}

TDeskTop  *TMyApp::initDeskTop(TRect r) {
	return new TDeskTop(r);
}
TStatusLine *TMyApp::initStatusLine(TRect r)
{
    r.a.y = r.b.y - 1;
    return new TStatusLine(r,
        *new TStatusDef(0, 0xFFFF) +
        *new TStatusItem(0, kbF10, cmMenu) +
        *new TStatusItem("~Alt-X~ Exit", kbAltX, cmQuit) +
        *new TStatusItem("~Alt-F3~ Close", kbAltF3, cmClose)
    );
}

TMenuBar *TMyApp::initMenuBar(TRect r)
{
    r.b.y = r.a.y + 1;
    return new TMenuBar(r,
        *new TSubMenu("~T~ransmitter", kbAltF) +
        *new TMenuItem("~O~pen", cmTechInfo, kbF3, hcNoContext, "F3") +
        *new TMenuItem("~N~ew", cmMyNewWin, kbF4, hcNoContext, "F4") +
        newLine() +
        *new TMenuItem("E~x~it", cmQuit, cmQuit, hcNoContext, "Alt-X") +
        *new TSubMenu("~W~indow", kbAltW) +
        *new TMenuItem("~N~ext", cmNext, kbF6, hcNoContext, "F6") +
        *new TMenuItem("~Z~oom", cmZoom, kbF5, hcNoContext, "F5")
    );
}

void TMyApp::handleEvent(TEvent& event)
{
    TApplication::handleEvent(event);
    if (event.what == evCommand)
    {
        switch (event.message.command)
        {
        case cmMyNewWin:
            myNewWindow();
            break;
        case cmTechInfo:
            TechInfo();
            break;
        case cmClose:
            Tech1();
            clearEvent(event);
            break;
        default:
            return;
        }
        clearEvent(event);
    }
}
void TMyApp::Tech1()
{
    TRect tr;
     TechInfoDialog *ti ;
 
  ti->close();
  
  
}
void TMyApp::myNewWindow()
{
    TRect r(0, 0, 26, 7);
    r.move(random(), random());
    TDemoWindow *window = new TDemoWindow(r, "Demo Window", ++winNumber);
    deskTop->insert(window);
}
void TMyApp::TechInfo()
	  {
	  TRect tr;

	  tr.a.x = 10;
	  tr.a.y = 17;
	  tr.b.x = tr.a.x + 30;
	  tr.b.y = tr.a.y + 3;
	  TechInfoView *tv = new TechInfoView(TRect(1,1,10,3));
	  TWindow *twv =  new TWindow(
                     TRect( tr.a.x - 1, tr.a.y - 1, tr.b.x + 1, tr.b.y + 1 ),
											 "Individual View", 2 );
	  twv->insert( tv );
	  deskTop->insert( twv );

	  tr.a.x = 10;
	  tr.a.y = 1;
	  tr.b.x = tr.a.x + 30;
	  tr.b.y = tr.a.y + 10;
	  TechInfoDialog *ti = new TechInfoDialog( tr );
      
	  deskTop->execView( ti );

	  }



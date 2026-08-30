#include "Window.h"
#include <sstream> 

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow )
{
	try
	{
		Window wnd( 1080,720,"OneEngine Editor 0.1v" );

		MSG msg;
		BOOL gResult;
		while( (gResult = GetMessage( &msg,nullptr,0,0 )) > 0 )
		{
			// TranslateMessage will post auxilliary WM_CHAR messages from key msgs
			TranslateMessage( &msg );
			DispatchMessage( &msg );

			if (wnd.kdb.KeyIsPressed(VK_SPACE)) {
				MessageBox(nullptr, "Something Happond!", "Space key was Pressed", MB_OK);
			}

			if (wnd.kdb.KeyIsPressed(VK_MENU)) {
				MessageBox(nullptr, "Something Happond!", "alt key was Pressed", MB_OK);
			}


			//TODO: test ente for mouse 

			while (!wnd.mouse.IsEmpty()) {

				const auto e = wnd.mouse.Read();
			//	if (e.GetType() == Mouse::Event::Type::Move) {

			//		std::ostringstream oss;
			//		oss << "Mouse Position: (" << e.GetPosX() << ", " << e.GetPosY() << ")";
			//		wnd.SetTitle(oss.str());

			//	}

				switch (e.GetType())
				{
				case Mouse::Event::Type::Leave:
					wnd.SetTitle("Gone !");
					break;
				case Mouse::Event::Type::Move:
				{
					std::ostringstream oss;

					oss << "Mouse Position: (" << e.GetPosX() << ", " << e.GetPosY() << ")";
					wnd.SetTitle(oss.str());				
				}
				break;
				}
			}
		}



		// check if GetMessage call itself borked
		if( gResult == -1 )
		{
			throw CHWND_LAST_EXCEPT();
		}

		// wParam here is the value passed to PostQuitMessage
		return msg.wParam;
	}
	catch( const OneEngineException& e )
	{
		MessageBox( nullptr,e.what(),e.GetType(),MB_OK | MB_ICONEXCLAMATION );
	}
	catch( const std::exception& e )
	{
		MessageBox( nullptr,e.what(),"Standard Exception",MB_OK | MB_ICONEXCLAMATION );
	}
	catch( ... )
	{
		MessageBox( nullptr,"No details available","Unknown Exception",MB_OK | MB_ICONEXCLAMATION );
	}
	return -1;
}
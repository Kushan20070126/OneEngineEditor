#include "App.h"

App::App()
	:
	wnd(800, 600, "Engine Window 2")
{}

int App::Go()
{
	MSG msg;
	BOOL gResult;

	while ((gResult = GetMessage(&msg,nullptr,0,0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		DoFrame();
	}

	if (gResult == -1) {

		throw CHWND_LAST_EXCEPT();

	}

	return msg.wParam;

}

void App::DoFrame() {
	const float t = timer.Peek();
	std::ostringstream oss;
	oss << "Time elapsed: " << std::fixed << t << "s";
	wnd.SetTitle(oss.str());
}
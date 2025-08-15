// winmain.h

BOOL InitApplication( HINSTANCE hInstance);
BOOL InitInstance( HINSTANCE hInstance, int nCmdShow );
LRESULT CALLBACK WndProc( HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam );
void EventLoop();
void OnDestroy();
void Initialize(const char* pCmdLine);
void CALLBACK _TimerFunc(UINT wID, UINT wUser, DWORD dwUSer, DWORD dw1, DWORD dw2);
MMRESULT _StartTimer(DWORD dwTime);

void _StopTimer(MMRESULT timerid);
//void PutLogFileList(const char* cStr);
//void __WriteChatLogFile(const char* cStr);
void CPSocketConnet() ;  // v2.03
LONG GetRegKey(HKEY key, LPCTSTR subkey, LPTSTR retdata);
void GoHomepage();
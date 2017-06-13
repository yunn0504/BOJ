//////////////////////////////////////////////////////////////////////////////// 
// Filename: systemclass.cpp 
//////////////////////////////////////////////////////////////////////////////// 
#include "systemclass.h"

SystemClass::SystemClass() 
{ 
	m_Input = 0;
	m_Graphics = 0; 
}
SystemClass::SystemClass(const SystemClass& other) 
{ 
} 
SystemClass::~SystemClass() 
{ 
}
bool SystemClass::Initialize() {
	int screenWidth, screenHeight; 
	bool result; 

	// �Լ��� ���̿� �ʺ� �����ϱ� ���� ������ 0���� �ʱ�ȭ�Ѵ�. 
	screenWidth = 0; 
	screenHeight = 0; 

	// �������� api�� ����Ͽ� �ʱ�ȭ�Ѵ�. 
	InitializeWindows(screenWidth, screenHeight);
	
	// input ��ü�� �����մϴ�. �� ��ü�� �����κ��� ������ Ű���� �Է��� ó���ϱ� ���� ����մϴ�. 
	m_Input = new InputClass; 
	if(!m_Input) 
	{ 
		return false; 
	} 
	
	// Input ��ü�� �ʱ�ȭ�մϴ�. 
	m_Input->Initialize(); 
	
	// graphics ��ü�� �����մϴ�. �� ��ü�� �� ���ø����̼��� ��� �׷��� ��Ҹ� �׸��� ���� �մϴ�. 
	m_Graphics = new GraphicsClass; 
	if(!m_Graphics) 
	{ 
		return false; 
	} // graphics ��ü�� �ʱ�ȭ�մϴ�. 
	result = m_Graphics->Initialize(screenWidth, screenHeight, m_hwnd); 
	if(!result) 
	{ 
		return false; 
	} 
	return true; 
}

void SystemClass::Shutdown() 
{ 
	// Graphics ��ü�� ��ȯ�մϴ�. 
	if(m_Graphics) 
	{ 
		m_Graphics->Shutdown(); 
		delete m_Graphics; 
		m_Graphics = 0; 
	} 
	
	// Input ��ü�� ��ȯ�մϴ�. 
	if(m_Input)
	{ 
		delete m_Input; m_Input = 0; 
	} 
	
	// â�� �����ŵ�ϴ�. 
	ShutdownWindows(); 
	return; 
}

void SystemClass::Run() {
	MSG msg; 
	bool done, result; 
	
	// �޼��� ����ü�� �ʱ�ȭ�մϴ�. 
	ZeroMemory(&msg, sizeof(MSG)); 
	
	// �����κ��� ���� �޼����� ���� ������ ������ ���ϴ�. 
	done = false; 
	while(!done) { 
		// ������ �޼����� ó���մϴ�. 
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{ 
			TranslateMessage(&msg); 
			DispatchMessage(&msg); 
		} 
		// �����쿡�� ���ø����̼��� ���Ḧ ��û�ϴ� ��� ���������ϴ�. 
		if(msg.message == WM_QUIT) 
		{
			done = true; 
		}
		else
		{ 
			// �� �ܿ��� Frame �Լ��� ó���մϴ�. 
			result = Frame(); 
			if(!result) 
			{ 
				done = true;
			}
		} 
	}
	return; 
}

bool SystemClass::Frame() {
	bool result; 
	
	// ������ EscŰ�� ���� ���ø����̼��� �����ϱ⸦ ���ϴ��� Ȯ���մϴ�. 
	if(m_Input->IsKeyDown(VK_ESCAPE)) 
	{ 
		return false; 
	} 
	// graphics��ü�� �۾��� ó���մϴ�. 
	result = m_Graphics->Frame(); 
	if(!result) 
	{
		return false;
	}
	return true; 
}
LRESULT CALLBACK SystemClass::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam) 
{
	switch (umsg) 
	{ 
		// Ű���尡 Ű�� ���ȴ��� Ȯ���մϴ�. 
		case WM_KEYDOWN: 
		{ 
			// Ű�� ���ȴٸ� input��ü�� �� ����� �����Ͽ� ����ϵ��� �մϴ�. 
			m_Input->KeyDown((unsigned int)wparam); 
			return 0; 
		} 
		// Ű������ ���� Ű�� ���������� Ȯ���մϴ�. 
		case WM_KEYUP: { 
			// Ű�� �������ٸ� input��ü�� �� ����� �����Ͽ� �� Ű�� ��������մϴ�. 
			m_Input->KeyUp((unsigned int)wparam); 
			return 0; 
		} 
		// �ٸ� �޼������� ������� �����Ƿ� �⺻ �޼��� ó���⿡ �����մϴ�. 
		default: 
		{
			return DefWindowProc(hwnd, umsg, wparam, lparam); 
		}
	}
}

void SystemClass::InitializeWindows(int& screenWidth, int& screenHeight)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX, posY;


	// �ܺ� �����͸� �� ��ü�� �����մϴ�.
	ApplicationHandle = this;

	// �� ���ø����̼��� �ν��Ͻ��� �����ɴϴ�.
	m_hinstance = GetModuleHandle(NULL);

	// ���ø����̼��� �̸��� �����մϴ�.
	m_applicationName = L"Engine";

	// ������ Ŭ������ �⺻ �������� ����ϴ�.
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hinstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	// ������ Ŭ������ ����մϴ�.
	RegisterClassEx(&wc);

	// ����� ȭ���� �ػ󵵸� �˾ƿɴϴ�.
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// Ǯ��ũ�� ��� ������ ���� ���� ȭ�� ������ �մϴ�.
	if (FULL_SCREEN)
	{
		// ���� Ǯ��ũ�� ����� ȭ�� ũ�⸦ ����ũ�� ũ�⿡ ���߰� ������ 32bit�� �մϴ�.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Ǯ��ũ���� �´� ���÷��� ������ �մϴ�.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// �������� ��ġ�� ȭ���� ���� ���� ����ϴ�.
		posX = posY = 0;
	}
	else
	{
		// ������ ����� 800x600�� ũ�⸦ ������ �մϴ�.
		screenWidth = 800;
		screenHeight = 600;

		// â�� ������� �߾ӿ� ������ �մϴ�.
		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	}

	// ������ ���� ������ â�� ����� �� �ڵ��� �����ɴϴ�.
	m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName, m_applicationName,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
		posX, posY, screenWidth, screenHeight, NULL, NULL, m_hinstance, NULL);

	// �����츦 ȭ�鿡 ǥ���ϰ� ��Ŀ���� �ݴϴ�.
	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);

	// ���콺 Ŀ���� ǥ������ �ʽ��ϴ�.
	ShowCursor(false);

	return;
}

void SystemClass::ShutdownWindows()
{
	// ���콺 Ŀ���� ǥ���մϴ�.
	ShowCursor(true);

	// Ǯ��ũ�� ��带 �������� �� ���÷��� ������ �ٲߴϴ�.
	if (FULL_SCREEN)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	// â�� �����մϴ�.
	DestroyWindow(m_hwnd);
	m_hwnd = NULL;

	// ���ø����̼� �ν��Ͻ��� �����մϴ�.
	UnregisterClass(m_applicationName, m_hinstance);
	m_hinstance = NULL;

	// �� Ŭ������ ���� �ܺ� ������ ������ �����մϴ�.
	ApplicationHandle = NULL;

	return;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{
		// �����찡 ���ŵǾ����� Ȯ���մϴ�.
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

	// �����찡 �������� Ȯ���մϴ�.
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}

	// �ٸ� ��� �޼������� system Ŭ������ �޼��� ó���⿡ �����մϴ�.
	default:
	{
		return ApplicationHandle ->MessageHandler(hwnd, umessage, wparam, lparam);
	}
	}
}
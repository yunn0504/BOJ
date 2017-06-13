#include "systemclass.h" 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow) 
{ 
	SystemClass* System; 
	bool result; 
	
	// system ��ü�� �����Ѵ�. 
	System = new SystemClass; 
	if(!System)
	{ 
		return 0; 
	} 
	
	// system ��ü�� �ʱ�ȭ�ϰ� run�� ȣ���Ѵ�. 
	result = System->Initialize(); 
	if(result) 
	{ 
		System->Run(); 
	} 

	// system��ü�� �����ϰ� �޸𸮸� ��ȯ�Ѵ�. 
	System->Shutdown(); 
	delete System; 
	System = 0; 
	return 0; 
}
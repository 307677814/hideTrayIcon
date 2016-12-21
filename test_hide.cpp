// test_hide.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "hide.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WCHAR exeName[128] = {0};
	WCHAR *seps = L",";				// ʹ��","���������Ʒָ�
	WCHAR *token = NULL;  
	WCHAR *next_token = NULL; 
	
	// Ĭ������ͼ��
	BOOL isShow = FALSE;
	if(strcmp(lpCmdLine,"show")==0)
		isShow = TRUE;
	// config.ini ֻ�ܷ��ڵ�ǰEXE���ڵ�·��
	GetPrivateProfileString(L"CONFIG",L"exeName",L"speed",exeName, 128, L".\\config.ini");
 
	token = wcstok_s(exeName,seps,&next_token);  

	while (NULL != token)  
	{  
		SetTrayIconStatus(token, isShow);
		token = wcstok_s(NULL,seps,&next_token);  
	}  

	return 0;
}
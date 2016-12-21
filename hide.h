/*
	Create time : 2016.12.20
	Author : ddvv
	Function : 
	@1 : void SetTrayIconStatus(LPCWSTR lpwszIcon, BOOL bShow = FALSE);
	��������ͼ���״̬(����/��ʾ)
*/

#define TB_GETBUTTON            (WM_USER + 23)
#define TB_BUTTONCOUNT          (WM_USER + 24)

// 64λ��Ӧ�Ľṹ��
typedef struct _TRAYDATA64 {  
	PVOID64 hWnd;  //HWND 64λ 8�ֽ�
	UINT uID;  
	UINT uCallbackMessage;  
	DWORD Reserved1[2];  
	PVOID64 hIcon;  //HICON 64λ 8�ֽ�
	DWORD Reserved2[4];  
	TCHAR szExePath[MAX_PATH];  
	TCHAR szTip[128];  
} TRAYDATA64; 

typedef struct _TBBUTTON64 {
    int iBitmap;
    int idCommand;
    BYTE fsState;
    BYTE fsStyle;
    BYTE bReserved[6];          // padding for alignment
    DWORD_PTR dwData;
    INT_PTR iString;
} TBBUTTON64;

// 32��Ӧ�Ľṹ��
typedef struct _TRAYDATA32 {  
	HWND hWnd;  
	UINT uID;  
	UINT uCallbackMessage;  
	DWORD Reserved1[2];  
	HICON hIcon;  
	DWORD Reserved2[3];  
	TCHAR szExePath[MAX_PATH];  
	TCHAR szTip[128];  
} TRAYDATA32;

typedef struct _TBBUTTON32 {
    int iBitmap;
    int idCommand;
    BYTE fsState;
    BYTE fsStyle;
    BYTE bReserved[2];          // padding for alignment
    DWORD_PTR dwData;
    INT_PTR iString;
} TBBUTTON32;


/*
	param : 
	@lpwszIcon : ��Ҫ�����ص�ͼ���Ӧ�Ŀ�ִ���ļ���
	@bSHow : FALSE�������أ�TRUE������ʾ
*/
void SetTrayIconStatus(LPCWSTR lpwszIcon, BOOL bShow = FALSE);
void SetHide(HWND hWnd, LPCWSTR lpwszIcon, BOOL bShow);
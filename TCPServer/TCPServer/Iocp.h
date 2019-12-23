#ifndef __ICOP_H__
#define __ICOP_H__

#include "Object.h"

#define MAX_SOCKBUF	 1024	// 최대 패킷 사이즈

enum class IOOperation {
	RECV,
	SEND
};

// WSAOVERLAPPED구조체를 확장 시켜서 필요한 정보를 더 넣었다.
struct stOverlappedEx {
	WSAOVERLAPPED			m_wsaOverlapped;			// Overlapped I/O구조체
	SOCKET					m_socketClient;				// 클라이언트 소켓
	WSABUF					m_wsaBuf;					// Overlapped I/O작업 버퍼
	char					m_szBuf[MAX_SOCKBUF];		// 데이터 버퍼
	IOOperation				m_eOperation;				// 작업 동작 종류
};

class IOCP_Server {
private:
	SOCKET g_socket;												// Socket
	std::chrono::high_resolution_clock::time_point serverTimer;		// 서버 기준 시간
	HANDLE g_hiocp;													// handle 선언
	unsigned __int64 uniqueId;										// 접속 UniqueID

public:
	HANDLE getHandle() { return g_hiocp; }							// Handle Return
	IOCP_Server();													// init IOCP
	~IOCP_Server();													// remove IOCP
	bool initServer();
	bool BindandListen(const u_short port);
	bool StartServer();
	void initClient(std::list<class PLAYER>& player);
};

#endif
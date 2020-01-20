﻿#include "Main.h"

class IOCP_Server iocp_server;
std::unordered_map<unsigned __int64, class PLAYER *> player;
std::unordered_map<unsigned __int64, class PLAYER_Session *> player_session;
SERVER_Timer timer;

int main() {
	std::cout << "Client Start Packet No : " << CLIENT_BASE << std::endl;
	std::cout << "Max Client Packet No : " << MAX_CLIENT_PROTOCOL_NO << std::endl;
	std::cout << "Server Start Packet No : " << SERVER_BASE << std::endl;
	std::cout << "Max Server Packet No : " << MAX_SERVER_PROTOCOL_NO << std::endl << std::endl;
	iocp_server.initServer();					// Socket 생성
	iocp_server.BindandListen(SERVERPORT);		// Listen 처리
	iocp_server.initClient();					// Player Init
	iocp_server.StartServer();					// Server 시작
	timer.startTimer(iocp_server.getHandle());	// Timer 시작
}
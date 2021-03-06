﻿#ifndef __MAIN_H__
#define __MAIN_H__

#pragma comment(lib, "ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS					// 윈속 오류 방지

typedef unsigned long long int	unsigned_int64;	// 8Byte, 64bit

// Header 선언
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <Windows.h>
#include <time.h>
#include <ctime>
#include <list>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <queue>
#include <mutex>

// SPDLog 1.5.0 <2020.01.21> github Include Add
#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"

// RedisConnect <2020.01.29> | github source : https://github.com/genxun/RedisConnect
#include <stdarg.h>
#include <algorithm>
#include "Global/RedisConnect.h"

// 헤더 가져오기
#include "Global/ConfigSetting.h"
#include "Global/ResultCode.h"
#include "Protocol.h"
#include "Iocp.h"
#include "Object.h"
#include "Session.h"
#include "Timer.h"
#include "ReadBuffer.h"
#include "Library/Api.h"


// Setting Value
extern class IOCP_Server iocp_server;
extern class SERVER_Timer timer;
extern class Logic_API api;
extern class ConfigSetting CS;
extern std::vector<class RedisConnect *> RDC;
extern std::queue<Packet_Frame> recvPacketQueue;
extern std::unordered_map<unsigned_int64, class PLAYER *> player;					// 플레이어 데이터
extern std::unordered_map<unsigned_int64, class PLAYER_Session *> player_session;	// 플레이어 세션

void initRDC();
#endif
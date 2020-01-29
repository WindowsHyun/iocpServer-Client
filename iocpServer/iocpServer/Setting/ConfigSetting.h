﻿#ifndef __CONFIGSETTING_H__
#define __CONFIGSETTING_H__

#include "../Main.h"

class ConfigSetting {
public:
	ConfigSetting() {
		SERVER_PORT = -1;
		MAX_PLAYER = -1;
		LIMIT_ERROR_CNT = -1;
		REDIS_ID = NULL;
		REDIS_PW = NULL;
		SQL_ID = NULL;
		SQL_PW = NULL;
	}
	void loadSettingData();

	// get
	const int get_server_port() { return SERVER_PORT; }
	const int get_max_player() { return MAX_PLAYER; }
	const int get_limit_err_cnt() { return LIMIT_ERROR_CNT; }
	const char* get_redis_id() { return REDIS_ID; }
	const char* get_redis_pw() { return REDIS_PW; }
	const char* get_sql_id() { return SQL_ID; }
	const char* get_sql_pw() { return SQL_PW; }
	

private:
	int SERVER_PORT;			// 서버 포트
	int MAX_PLAYER;				// 최대 플레이어
	int LIMIT_ERROR_CNT;		// 최대 제한 cnt
	char* REDIS_ID;				// 레디스 접속 아이디
	char* REDIS_PW;				// 레디스 접속 비밀번호
	char* SQL_ID;				// SQL 접속 아이디
	char* SQL_PW;				// SQL 접속 비밀번호

	// set
	void set_server_port(const int value) { SERVER_PORT = value; }
	void set_max_player(const int value) { MAX_PLAYER = value; }
	void set_limit_err_cnt(const int value) { LIMIT_ERROR_CNT = value; }
	void set_redis_id(const char* value, const unsigned __int64 size) {
		REDIS_ID = new char[size];
		memset(REDIS_ID, 0, size);
		memcpy_s(REDIS_ID, size, value, size);
		REDIS_ID[size] = '\0';
	}
	void set_redis_pw(const char* value, const unsigned __int64 size) {
		REDIS_PW = new char[size];
		memset(REDIS_PW, 0, size);
		memcpy_s(REDIS_PW, size, value, size);
		REDIS_PW[size] = '\0';
	}
	void set_sql_id(const char* value, const unsigned __int64 size) {
		SQL_ID = new char[size];
		memset(SQL_ID, 0, size);
		memcpy_s(SQL_ID, size, value, size);
		SQL_ID[size] = '\0';
	}
	void set_sql_pw(const char* value, const unsigned __int64 size) {
		SQL_PW = new char[size];
		memset(SQL_PW, 0, size);
		memcpy_s(SQL_PW, size, value, size);
		SQL_PW[size] = '\0';
	}
};
#endif
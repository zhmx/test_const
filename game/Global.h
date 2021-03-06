#pragma once

#include <iostream>
#include "boost/asio.hpp"
#include "kaguya/kaguya.hpp"

extern kaguya::State g_kaguyaState;
extern lua_State *g_luaState;
extern boost::asio::io_context g_IO;
extern boost::asio::deadline_timer g_timer;
extern boost::asio::signal_set g_single;
extern std::string g_strSecTimer;
extern char* g_pSendbuff;			// 多线程不可用

// 数据包 头(数据包长度)+包体
typedef unsigned int BODY_LEN_TYPE;	// 数据包长度
typedef unsigned int CMDID_LEN_TYPE;// 消息id长度

#define	MAX_BUFF_SIZE 102400	// 接收&发送缓冲区大小 1024*100 100k
#define MAXPORT 65535			// 监听最大端口
#define MINPORT	80				// 监听最小端口
#define MIN_SEND_SIZE 2			// 最小发送字节
#define WEB_HTTP_TIMEOUT 10		// web http 超时时间

struct StruMessageHead
{
	StruMessageHead() :len(0), msgId(0)
	{}
	~StruMessageHead()
	{}

	BODY_LEN_TYPE len;		// 消息体的长度
	CMDID_LEN_TYPE msgId;	// 消息id
};

class CGlobal
{
public:
	enum
	{
		TYPEMIN,

		ON_ACCEPT,
		ON_DATA,
		ON_DISCONNECT,

		TYPEMAX,
	};

	CGlobal();
	~CGlobal();

	static void Stop();
	static std::string md5(const char* str);

	static unsigned char STATIC_ON_ACCEPT;
	static unsigned char STATIC_ON_DATA;
	static unsigned char STATIC_ON_DISCONNECT;
};
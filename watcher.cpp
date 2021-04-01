#include <iostream>

#define MIRAICPP_STATICLIB
#include "mirai.h"

#include "sstp.hpp"

int main()
{
	using namespace std;
	using namespace Cyan;
	using namespace SSTP_link_n;

	system("chcp 65001");

	try{
		SSTP_link_t linker({{L"Charset",L"UTF-8"},{L"Sender",L"OICQ-saori"}});
		MiraiBot bot("127.0.0.1", 539);

		try{
			auto login_info=linker.NOTYFY(L"Event: OnGetOICQkey");
			bot.Auth(to_string(login_info[L"Key"]),qq_id(to<unsigned long long>(login_info[L"OICQid"])));
			wcout << linker.NOTYFY(L"Event: OnOICQlogin")[L"ScriptForShell"] << endl;
		}catch(...){
			linker.NOTYFY(L"Event: OnOICQloginFailed");
			throw;
		}

		//设置事件轮循器s
		#error TODO


		// 记录轮询事件时的错误
		bot.EventLoop([](const char* errMsg)
		{
			wcout << linker.NOTYFY ({
										{L"Event",L"OnOICQeventLoopError"},
										{L"Reference0",to_wstring(errMsg)}
									})[L"ScriptForShell"] << endl;
		});
	}catch(std::runtime_error&a){
		cerr << a.what();
	}

	return 0;
}
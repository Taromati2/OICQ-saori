#include <iostream>
// 使用静态库必须要在引入 mirai.h 前定义这个宏
#define MIRAICPP_STATICLIB
#include <mirai.h>

int main()
{
	using namespace std;
	using namespace Cyan;
	using namespace SSTP_link_n;

	system("chcp 65001");

	SSTP_link_t linker({{L"Charset",L"UTF-8"},{L"Sender",L"OICQ-saori"}});
	MiraiBot bot("127.0.0.1", 539);

	bot.Auth("INITKEY7A3O1a9v", 1589588851_qq);
	cout << "成功登录 bot" << endl;


	GroupConfig group_config = bot.GetGroupConfig(1029259687_gid);

	group_config.Name = "New Name 2";

	bot.SetGroupConfig(1029259687_gid, group_config);

	cout << group_config.Name << endl;


	// 记录轮询事件时的错误
	bot.EventLoop([](const char* errMsg)
	{
		cout << "获取事件时出错: " << errMsg << endl;
	});


	return 0;
}
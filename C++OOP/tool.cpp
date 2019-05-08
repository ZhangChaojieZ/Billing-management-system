//存放处理时间的函数的声明
#include<time.h>
#include<stdio.h>
using namespace std;

//time_t time(time_t* t);取得从 1970 年 1 月 1 日至今的秒数
//time_t t = time(NULL);获取本地时间 
//struct tm *localtime(const time_t *clock);将长整数时间转换为结构体时间,从中得到“年月日，星期，时分秒”等信息 
//time_t mktime(struct tm* timeptr); 将 struct tm 结构的时间转换为长整数

void timeToString(time_t tm, char* tm1Str)
//将time_t类型转化为固定格式字符串
{
	struct tm* timeinfo;
	timeinfo = localtime(&tm);
	strftime(tm1Str, 20, "%Y-%m-%d %H:%M", timeinfo);
}
//size_t strftime(char *str, size_t maxsize, const char *fmt, struct tm *time) 
//功能：将时间格式化，或者说格式化一个时间字符串。即将时间 time 格式化为 fmt 样 式的字符串。
//fmt： %Y,年（如：2004） %m，月份(1 - 12) % d，月中的第几天(1 - 31) % H，小时, 24 小时格式(0 - 23) % M，分钟(0 - 59)

time_t stringToTime(char* tm2Str)
//将字符串转化为time_t类型
{
	struct tm TM;//结构体类型
	time_t timeTemp;//long型
	sscanf(tm2Str, "%d-%d-%d %d:%d", &TM.tm_year, &TM.tm_mon, &TM.tm_mday, &TM.tm_hour, &TM.tm_min);
	TM.tm_year -= 1970;//从1970开始
	TM.tm_mon -= 1;//月份为0~11
	TM.tm_sec = 0;
	TM.tm_isdst = -1;
	timeTemp = mktime(&TM);
	return timeTemp;
}
//int sscanf(const char *str, const char * format, ........) 
//功能：将字符串 str 根据参数 format 字符串来转换并格式化数据。格式转换形式请参 考 scanf()。转换后的结果存于对应的参数内
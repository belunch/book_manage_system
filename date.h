#pragma once
#include <ctime>
class date
{
public:
	int year;
	int month;
	int day;

	date(int y = 0,int m=0,int d =0);
	~date();
	int calculata_daydiv(date another_day);//计算两天之间的差值
	int calculate_duration_day(int duration);//计算duration天后的日期
    void fromSystemTime() {};
    int daysDiff(const date& target) const { return 0; };
    //void fromSystemTime() {
    //    time_t now = time(0);          // 获取当前时间戳（秒数）
    //    tm* localTime = localtime(&now); // 转换为本地时间结构体

    //    year = localTime->tm_year + 1900; // tm_year 是从 1900 开始的偏移
    //    month = localTime->tm_mon + 1;    // tm_mon 是 0~11，+1 转为 1~12
    //    day = localTime->tm_mday;         // 当月第几天
    //}

    //// 计算与另一个 Date 的天数差（当前日期 - 目标日期）
    //int daysDiff(const date& target) const {
    //    // 转换为时间戳，用 <chrono> 计算更简单（C++11+）
    //    tm targetTm = { 0 };
    //    targetTm.tm_year = target.year - 1900;
    //    targetTm.tm_mon = target.month - 1;
    //    targetTm.tm_mday = target.day;
    //    time_t targetTime = mktime(&targetTm);

    //    tm nowTm = { 0 };
    //    nowTm.tm_year = year - 1900;
    //    nowTm.tm_mon = month - 1;
    //    nowTm.tm_mday = day;
    //    time_t nowTime = mktime(&nowTm);

    //    // 秒数差转天数
    //    return (nowTime - targetTime) / (60 * 60 * 24);
    //}

};
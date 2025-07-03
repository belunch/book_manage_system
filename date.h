#pragma once
#include <ctime>
#include <chrono>
#include <iostream>
#include <cmath>
class date
{
public:
	int year;
	int month;
	int day;

	date(int y = 0,int m=0,int d =0);
	~date();
	int calculata_daydiv(date another_day);//计算两天之间的差值，弃用
	int daysTo(const date& target) const; //计算当前日期到目标日期的天数差
	int calculate_duration_day(int duration);//计算duration天后的日期，弃用
    void fromSystemTime() {};
    int daysDiff(const date& target) const { return 0; };


    static date getCurrentDate() {
        // 获取当前系统时间
        auto now = std::chrono::system_clock::now();

        // 转换为time_t类型
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);

        // 转换为本地时间结构
        std::tm local_tm;
        localtime_s(&local_tm, &now_time);  // Windows安全版本

        // 注意：tm_year是从1900开始的，tm_month是0-11
        return date(local_tm.tm_year + 1900, local_tm.tm_mon + 1, local_tm.tm_mday);
    }

};
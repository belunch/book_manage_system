#pragma once

class date
{
public:
	int year;
	int month;
	int day;

	date();
	~date();
	int calculata_daydiv(date another_day);//计算两天之间的差值
	int calculate_duration_day(int duration);//计算duration天后的日期

};
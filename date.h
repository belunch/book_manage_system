#pragma once

class date
{
public:
	int year;
	int month;
	int day;

	date();
	~date();
	int calculata_daydiv(date another_day);//��������֮��Ĳ�ֵ
	int calculate_duration_day(int duration);//����duration��������

};
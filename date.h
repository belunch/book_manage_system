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
	int calculata_daydiv(date another_day);//��������֮��Ĳ�ֵ������
	int daysTo(const date& target) const; //���㵱ǰ���ڵ�Ŀ�����ڵ�������
	int calculate_duration_day(int duration);//����duration�������ڣ�����
    void fromSystemTime() {};
    int daysDiff(const date& target) const { return 0; };


    static date getCurrentDate() {
        // ��ȡ��ǰϵͳʱ��
        auto now = std::chrono::system_clock::now();

        // ת��Ϊtime_t����
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);

        // ת��Ϊ����ʱ��ṹ
        std::tm local_tm;
        localtime_s(&local_tm, &now_time);  // Windows��ȫ�汾

        // ע�⣺tm_year�Ǵ�1900��ʼ�ģ�tm_month��0-11
        return date(local_tm.tm_year + 1900, local_tm.tm_mon + 1, local_tm.tm_mday);
    }

};
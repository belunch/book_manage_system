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
	int calculata_daydiv(date another_day);//��������֮��Ĳ�ֵ
	int calculate_duration_day(int duration);//����duration��������
    void fromSystemTime() {};
    int daysDiff(const date& target) const { return 0; };
    //void fromSystemTime() {
    //    time_t now = time(0);          // ��ȡ��ǰʱ�����������
    //    tm* localTime = localtime(&now); // ת��Ϊ����ʱ��ṹ��

    //    year = localTime->tm_year + 1900; // tm_year �Ǵ� 1900 ��ʼ��ƫ��
    //    month = localTime->tm_mon + 1;    // tm_mon �� 0~11��+1 תΪ 1~12
    //    day = localTime->tm_mday;         // ���µڼ���
    //}

    //// ��������һ�� Date ���������ǰ���� - Ŀ�����ڣ�
    //int daysDiff(const date& target) const {
    //    // ת��Ϊʱ������� <chrono> ������򵥣�C++11+��
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

    //    // ������ת����
    //    return (nowTime - targetTime) / (60 * 60 * 24);
    //}

};
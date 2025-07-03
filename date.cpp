#include"date.h"

date::date(int y,int m,int d)
{
	year = y;
	month = m;
	day = d;

}

date::~date()
{

}

int date::calculata_daydiv(date another_day)
{
	return 0;
}

int date::daysTo(const date& target) const
{
    // 将两个日期都转换为time_t
    std::tm tm1 = { 0, 0, 0, day, month - 1, year - 1900 };
    std::tm tm2 = { 0, 0, 0, target.day, target.month - 1, target.year - 1900 };

    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);

    if (time1 == -1 || time2 == -1) {
        throw std::runtime_error("无法转换日期为time_t");
    }

    // 计算秒数差并转换为天数
    double seconds = std::difftime(time2, time1);
    return static_cast<int>(seconds / (60 * 60 * 24));
}

int date::calculate_duration_day(int duration)
{
	return 0;
}


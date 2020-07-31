
#include <iostream>
#include <string>
using namespace std;
class Time
{
public:
    Time(int h, int m, int s)
        : hours(h), minutes(m), seconds(s)
    {
    }
    void display()
    {
        cout << "出生时间:" << hours << "时" << minutes << "分" << seconds << "秒" << endl;
    }

protected:
    int hours, minutes, seconds;
};

class Date
{
public:
    Date(int m, int d, int y)
        : month(m), day(d), year(y)
    {
    }
    void display()
    {
        cout << "出生年月:" << year << "年" << month << "月" << day << "日" << endl;
    }

protected:
    int month, day, year;
};

class Birthtime : public Time, public Date
{
public:
    Birthtime(string name, int h, int m, int s, int t, int d, int y)
        : Childname(name), Time(h, m, s), Date(t, d, y)
    {
    }
    void display()
    {
        cout << "名字:" << Childname << endl;
    }

private:
    string Childname;
};

int main()
{
    Birthtime child("张三", 19, 45, 54, 6, 6, 2017);
    child.display();
    child.Date::display();
    child.Time::display();

    return 0;
}
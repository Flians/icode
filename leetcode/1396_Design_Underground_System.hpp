#include "../base/icode.hpp"
class UndergroundSystem : public icode
{
private:
    std::map<int, std::pair<std::string, int>> record;
    std::map<std::pair<std::string, std::string>, std::vector<int>> times;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        record[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto &in = record[id];
        std::pair<std::string, std::string> station(in.first, stationName);
        auto _find = times.find(station);
        if (_find == times.end())
        {
            times[station] = {t - in.second};
        }
        else
        {
            _find->second.push_back(t - in.second);
        }
    }

    double getAverageTime(string startStation, string endStation)
    {
        std::pair<std::string, std::string> station(startStation, endStation);
        double sum = 0;
        auto &item = times[station];
        for (int i : item)
        {
            sum += i;
        }
        return sum / item.size();
    }

    void run()
    {
        UndergroundSystem *obj = new UndergroundSystem();
        obj->checkIn(10, "Leyton", 3);
        obj->checkOut(10, "Paradise", 8);
        std::cout << obj->getAverageTime("Leyton", "Paradise") << " 5" << std::endl;
        delete obj;
    }
};

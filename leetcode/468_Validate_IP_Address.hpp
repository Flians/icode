#include "../base/icode.hpp"
class L468 : public icode
{
public:
	void run() {
        cout << validIPAddress("20EE:Fb8:85a3:0:0:8A2E:0370:7334") << " IPv6" << endl;
        cout << validIPAddress("172.16.254.1") << " IPv4" << endl;
        cout << validIPAddress("172.16.254.") << " Neither" << endl;
        cout << validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:") << " Neither" << endl;
        cout << validIPAddress("20EE:FGb8:85a3:0:0:8A2E:0370:7334") << " Neither" << endl;
    }
    
    enum State{VALID, INVALID, IPV4, IPV6};
    string validIPAddress(string IP) {
        State sta = VALID;
        string item;
        int time = -1;
        for (size_t i = 0; i < IP.length(); ++i) {
            if (IP[i] >= '0' && IP[i] <= '9') {
                item += IP[i];
                if ((sta == IPV4 && ((item.length() > 1 && item[0] == '0') || atoi(item.c_str()) > 255)) || (sta == IPV6 && item.length() > 4)) {
                    sta = INVALID;
                }
            } else if ((IP[i] >= 'a' && IP[i] <= 'f') || (IP[i] >= 'A' && IP[i] <= 'F')) {
                item += IP[i];
                if (sta == IPV4 || (sta == IPV6 && item.length() > 4)) {
                    sta = INVALID;
                } else {
                    if (time == -1) {
                        time = 7;
                    }
                    sta = IPV6;
                }
            } else if (IP[i] == '.') {
                if (sta == IPV6 || item.length() > 3 || item.empty() || (item.length() > 1 && item[0] == '0') || atoi(item.c_str()) > 255) {
                    sta = INVALID;
                } else {
                    if (time == -1) {
                        time = 2;
                        sta = IPV4;
                    } else if (time > 0) {
                        --time;
                    } else {
                        sta = INVALID;
                    }
                }
                item = "";
            } else if (IP[i] == ':') {
                if (sta == IPV4 || item.length() > 4 || item.empty()) {
                    sta = INVALID;
                } else {
                    if (time == -1) {
                        time = 6;
                        sta = IPV6;
                    } else if (time > 0) {
                        --time;
                    } else {
                        sta = INVALID;
                    }
                }
                item = "";
            } else {
                sta = INVALID;
            }
            if (sta == INVALID) {
                break;
            }
        }
        if (sta == INVALID || sta == VALID || time != 0 || (time == 0 && item.empty())) {
            return "Neither";
        } else {
            return (sta == IPV4 ? "IPv4" : "IPv6");
        }
    }
};
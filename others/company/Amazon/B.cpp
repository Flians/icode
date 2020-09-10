/*
Activate Log analysis

Given a machine access log by users as blow, we need to calculate the peak number of concurrent users and the time ranges

Host| User|Login_Time|Logout_Time
sev_host1, User1, 2020-02-08 11:30:30 000, 2020-02-08 12:30:30 000
sev_host1, User2, 2020-02-08 11:45:30 000, 2020-02-08 13:30:30 000
sev_host1, User3, 2020-02-08 13:00:30 000, 2020-02-08 23:30:30 000
sev_host1, User1, 2020-02-08 14:30:30 000, 2020-02-08 15:25:30 000
sev_host1, User2, 2020-02-08 12:45:30 000, 2020-02-08 17:30:30 000
 */

#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int num;
    long left;
    long right;
    Node () : num(0),left(0), right(0){}
    Node (long left, long right) : num(1), left(left), right(right){}
};

// [11:30:30, 12:30:30]

Node get_min(vector<Node> nodes) {
    pop_heap(nodes.begin(), nodes.end(), [&](Node &a, Node &b) {
        return a.left == b.left ? a.right > b.right : a.left > b.left;
    });
    Node cur = nodes.back();
    nodes.pop_back();
    return cur;
}

void push_new(vector<Node> nodes, Node newn) {
    nodes.push_back(newn);
    push_heap(nodes.begin(), nodes.end(), [&](Node &a, Node &b) {
        return a.left == b.left ? a.right > b.right : a.left > b.left;
    });
}

Node fun(vector<Node> nodes) {
    vector<Node> record;
    make_heap(nodes.begin(), nodes.end(), [&](Node &a, Node &b) {
        return a.left == b.left ? a.right > b.right : a.left > b.left;
    });
    /*
        a, b: a.left <= b.left: a.right < b.left; a.right < b.right; a.right > b.right; 
    */
    Node cur = get_min(nodes);
    while (!nodes.empty()) {
        if (cur.right < nodes.front().left) {
            record.push_back(cur);
            cur = get_min(nodes);
            continue;
        } else {
            Node nl(cur.left, nodes.front().left);
            nl.num = cur.num;
            record.push_back(nl);

            Node nr(min(cur.right, nodes.front().right), max(cur.right, nodes.front().right));
            nr.num = nodes.front().num;
                
            cur.left = nodes.front().left;
            cur.right = min(cur.right, nodes.front().right);
            cur.num += nodes.front().num;

            push_new(nodes, nr);
        }
    }
    record.push_back(cur);
    sort(nodes.begin(), nodes.end(), [&](Node &a, Node &b) {
        return a.num == b.num ? a.right - a.left < b.right - b.left : a.num < b.num;
    });
    return nodes.front();
}
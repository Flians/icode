#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
enum OP{
    EQ, NEQ, GE, LE
};
unordered_map<string, OP> str_op = {{"=", EQ}, {"!=", NEQ}, {">", GE}, {"<", LE}};
struct Node {
    string first;
    OP opt;
    string second;
    Node(){}
    Node(string f, string o, string s) : first(f), opt(str_op[o]), second(s){}
};

bool check(char c) {
    return c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

bool verify(unordered_map<string, int> &vars, vector<Node> nodes) {

}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int M;
        cin >> M;
        unordered_map<string, int> vars;
        vector<Node> nodes;
        nodes.reserve(M);
        while (M--) {
            string fi, opt, se, line;
            cin >> line;
            int state = 0;
            for (int i = 0; i < line.length(); i++) {
                if (state == 0) {
                    if (check(line[i])) {
                        fi += line[i];
                    } else {
                        ++state;
                        opt += line[i];
                    }
                } else if (state == 1) {
                    if (!check(line[i])) {
                         opt += line[i];
                    } else {
                        ++state;
                        se += line[i];
                    }
                } else {
                    se += line[i];
                }
            }
            if (vars.count(fi) == 0) {
                vars[fi] = 0;
            }
            if (vars.count(se) == 0) {
                vars[se] = 0;
            }
            Node node(fi, opt, se);
            nodes.emplace_back(node);
        }

    }
}
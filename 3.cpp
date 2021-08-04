#include <string>
#include <vector>
#include <list>
#include <queue>
#include<iostream>
using namespace std;
struct info {
    list<int>::iterator index;
    int n;
};
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    list<int> table;
    deque<info> dq;
    for (int i = 0; i < n; i++) {
        answer.push_back('O');
        table.push_back(i);
    }
    list<int>::iterator index;
    list<int>::iterator index2;
    index = table.begin();
    while (k--) {
        index++;
    }
    int cmd_size = cmd.size();
    for (int i = 0; i < cmd_size; i++) {
        index2 = table.end();
        index2--;
        if (cmd[i][0] == 'U') {
            int cnt = (cmd[i][2] - '0');
            while (cnt--) {
                index--;
            }
        }
        else if (cmd[i][0] == 'D') {
            int cnt = (cmd[i][2] - '0');
            while (cnt--) {
                index++;
            }
        }
        else if (cmd[i][0] == 'C') {
            answer[*index] = 'X';
            if (index == index2) {
                info now;
                now.n = *index;

                table.erase(index);
                index = table.end();

                now.index = index;
                dq.push_front(now);
                index--;
            }
            else {
                info now;
                now.n = *index;
                now.index = index;
                index = table.erase(index);
                dq.push_front(now);
            }
        }
        else if (cmd[i][0] == 'Z') {
            list<int>::iterator index3;
            index3 = table.begin();
            int cnt = *dq.front().index;
            while (cnt--) {
                index3++;
            }
            table.insert(index3, dq.front().n);
            answer[dq.front().n] = 'O';
            dq.pop_front();
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <list>
#include <queue>
#include<iostream>
using namespace std;
struct info {
    int index;
    int n;
};
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    list<int> table;
    deque<info> dq;
    for (int i = 0; i < n; i++) {
        answer.push_back('O');
        table.push_back(i);
    }
    list<int>::iterator index;
    list<int>::iterator index2;
    index = table.begin();
    int idx = 0;
    while (k--) {
        index++;
        idx++;
    }
    int cmd_size = cmd.size();
    for (int i = 0; i < cmd_size; i++) {
        cout << idx << '\n';
        index2 = table.end();
        index2--;
        if (cmd[i][0] == 'U') {
            int cnt = (cmd[i][2] - '0');
            while (cnt--) {
                index--;
                idx--;
            }
        }
        else if (cmd[i][0] == 'D') {
            int cnt = (cmd[i][2] - '0');
            while (cnt--) {
                index++;
                idx++;
            }
        }
        else if (cmd[i][0] == 'C') {
            answer[*index] = 'X';
            if (index == index2) {
                info now;
                now.n = *index;
                now.index = idx;
                dq.push_front(now);

                table.erase(index);
                index = table.end();
                index--;
                idx--;



            }
            else {
                info now;
                now.n = *index;
                now.index = idx;
                index = table.erase(index);
                dq.push_front(now);
            }
        }
        else if (cmd[i][0] == 'Z') {
            list<int>::iterator index3;
            index3 = table.begin();
            int cnt = dq.front().index;
            while (cnt--) {
                index3++;
            }
            table.insert(index3, dq.front().n);
            answer[dq.front().n] = 'O';
            dq.pop_front();
        }
    }
    return answer;
}
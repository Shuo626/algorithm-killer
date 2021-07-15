#include <bits/stdc++.h>


using namespace std;


struct Employee {
    int id;
    int importance;
    vector<int> subordinates;
};

using Employee = struct Employee;


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> _employees;

        for (Employee* &employee: employees) {
            _employees[employee->id] = employee;
        }

        int totalImportance;
        queue<Employee*> que;

        totalImportance = 0;
        que.push(_employees[id]);

        while (!que.empty()) {
            Employee *tmp;
            tmp = que.front();
            que.pop();

            totalImportance += tmp->importance;

            for (int& subId: tmp->subordinates) {
                que.push(_employees[subId]);
            }
        }

        return totalImportance;
    }
};
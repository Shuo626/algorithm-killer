#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


struct Student {
    int code;
    int arrive;
    int leave;
};

typedef struct Student Student;


vector<vector<Student>> totalStudents;


bool _compare(Student s1, Student s2) {
    if (s1.arrive == s2.arrive) {
        return s1.code < s2.code;
    } else {
        return s1.arrive < s2.arrive;
    }
}


int main() {
    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        vector<Student> students;
        
        students.clear();
        cin >> n;

        for (int j = 0; j < n; j++) {
            Student student;
            int arrive, leave;

            cin >> arrive >> leave;

            student.code = j;
            student.arrive = arrive;
            student.leave = leave;

            students.push_back(student);    
        }

        sort(students.begin(), students.end(), _compare);

        totalStudents.push_back(students);
    }


    for (vector<Student>& students: totalStudents) {
        int time;
        time = 1;

        for (Student& s: students) {
            if (time <= s.leave) {
                cout << max(time, s.arrive);
                time = max(time, s.arrive) + 1;
            } else {
                cout << 0;
            }
            cout << " ";
        }

        cout << endl;
    }
} 
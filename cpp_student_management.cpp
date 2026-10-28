#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int id = 0;
    string name = "";
    int age = 0;
};

void st_add(vector<Student> &students, vector<int> &check)
{
    Student st;

    cout << "enter the ID of the student: ";
    while (!(cin >> st.id) || count(check.begin(), check.end(), st.id) != 0)
    {
        cout << "enter a valid id!!!!!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    check.push_back(st.id);

    cin.ignore();

    cout << "enter the name of the student: ";
    getline(cin, st.name);

    cout << "enter the age of the student: ";
    while (!(cin >> st.age) || st.age > 90 || st.age < 1)
    {
        cout << "enter a valid age!!!!!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    students.push_back(st);
}

void st_update(vector<Student> &students, vector<int> &check)
{
    int n;
    cout << "enter the ID of the student to be updated: ";
    while (!(cin >> n) || count(check.begin(), check.end(), n) == 0)
    {
        cout << "enter a valid ID!!!!!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == n)
        {
            int alias;
            cout << "enter 1 to update student id: " << endl;
            cout << "enter 2 to update student name: " << endl;
            cout << "enter 3 to update student age: " << endl;
            cout << "enter 4 to cancle updating: " << endl;
            while (!(cin >> alias) || alias > 4 || alias < 1)
            {
                cout << "enter a valid number!!!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            int new_id;
            if (alias == 1)
            {
                cout << "enter the new ID: ";
                while (!(cin >> new_id))
                {
                    cout << "enter a valid number!!!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (count(check.begin(), check.end(), new_id) > 0 && new_id != students[i].id)
                {
                    cout << "id already exist!!!!" << endl;
                    break;
                }
                check[i] = new_id;
                students[i].id = new_id;
                cout << "update succesful!!!!" << endl;
            }
            else if (alias == 2)
            {
                string new_name;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "enter the new name: ";
                getline(cin, new_name);
                students[i].name = new_name;
                cout << "update succesful!!!!" << endl;
            }
            else if (alias == 3)
            {
                cout << "enter the new age: ";
                while (!(cin >> new_id) || new_id > 90 || new_id < 1)
                {
                    cout << "enter a valid age!!!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                students[i].age = new_id;
                cout << "update succesful!!!!" << endl;
            }
            break;
        }
    }
}

void st_delete(vector<Student> &students, vector<int> &check)
{
    int n;
    cout << "enter the id of the student: ";
    while (!(cin >> n))
    {
        cout << "enter a valid id!!!!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int j = count(check.begin(), check.end(), n);

    for (int i = 0; i < students.size() && j > 0; i++)
    {
        if (students[i].id == n)
        {
            students.erase(students.begin() + i);
            check.erase(check.begin() + i);
            break;
        }
    }

    if (j == 0)
    {
        cout << "student not exist!!!!!" << endl;
    }
}

void st_show(vector<Student> &students)
{
    if (students.size() == 0)
    {
        cout << "no students!!!!" << endl;
    }
    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].id << " | " << students[i].name << " | " << students[i].age << endl;
    }
}

void st_search(vector<Student> &students, vector<int> &check)
{
    int st_id;
    cout << "enter the id of the student to be search: ";
    while (!(cin >> st_id))
    {
        cout << "ente a valid id!!!!!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int j = count(check.begin(), check.end(), st_id);

    for (int i = 0; i < students.size() && j > 0; i++)
    {
        if (students[i].id == st_id)
        {
            cout << "result found!!!!!  " << students[i].id << " | " << students[i].name << " | " << students[i].age << endl;
        }
    }
    if (j == 0)
    {
        cout << "student not exist!!!" << endl;
    }
}

void st_load(vector<Student> &students, vector<int> &check)
{
    ifstream file("student_management_data.txt");
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        Student st;
        string load_id;
        string load_age;

        getline(ss, load_id, '|');
        st.id = stoi(load_id);
        getline(ss, st.name, '|');
        getline(ss, load_age, '|');
        st.age = stoi(load_age);

        students.push_back(st);
        check.push_back(st.id);
    }
    file.close();
}

void st_save(vector<Student> &students)
{
    ofstream file("student_management_data.txt");

    for (auto s : students)
    {
        file << s.id << "|" << s.name << "|" << s.age << endl;
    }
    file.close();
}

int main()
{
    vector<Student> students;
    vector<int> check;
    st_load(students, check);
    int operation = 0;
    while (operation != 6)
    {
        cout << "===========student management system ==========" << endl;
        cout << "enter 1 to add student data." << endl;
        cout << "enter 2 to update student data." << endl;
        cout << "enter 3 to delete student data." << endl;
        cout << "enter 4 to show student data." << endl;
        cout << "enter 5 to search student data." << endl;
        cout << "enter 6 to exit." << endl;
        cout << "===============================================" << endl;

        while (!(cin >> operation) || operation > 6 || operation < 1)
        {
            cout << "enter a valid operation number!!!!!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (operation == 1)
        {
            st_add(students, check);
        }
        else if (operation == 2)
        {
            st_update(students, check);
        }
        else if (operation == 3)
        {
            st_delete(students, check);
        }
        else if (operation == 4)
        {
            st_show(students);
        }
        else if (operation == 5)
        {
            st_search(students, check);
        }
    }
    st_save(students);
    return 0;
}
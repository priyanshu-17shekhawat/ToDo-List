#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Task {
    string title;
    bool done;
};

const string FILE_NAME = "tasks.txt";

void loadTasks(vector<Task> &tasks) {
    ifstream in(FILE_NAME);
    string line;
    while (getline(in, line)) {
        if (line.size() < 3) continue;
        Task t;
        t.done = (line[0] == '1');
        t.title = line.substr(2);
        tasks.push_back(t);
    }
}

void saveTasks(const vector<Task> &tasks) {
    ofstream out(FILE_NAME);
    for (const Task &t : tasks) {
        out << (t.done ? '1' : '0') << '|' << t.title << '\n';
    }
}

void showTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks yet. Add one!\n";
        return;
    }
    cout << "\nYour tasks:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". [" << (tasks[i].done ? "x" : " ") << "] "
             << tasks[i].title << "\n";
    }
}

void addTask(vector<Task> &tasks) {
    cout << "Enter task: ";
    string title;
    getline(cin, title);
    if (title.empty()) {
        cout << "Task cannot be empty.\n";
        return;
    }
    tasks.push_back({title, false});
    cout << "Task added.\n";
}

int askTaskIndex(const vector<Task> &tasks) {
    cout << "Enter task number: ";
    int n;
    if (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (n < 1 || n > static_cast<int>(tasks.size())) return -1;
    return n - 1;
}

void markDone(vector<Task> &tasks) {
    int idx = askTaskIndex(tasks);
    if (idx == -1) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks[idx].done = true;
    cout << "Marked as done.\n";
}

void editTask(vector<Task> &tasks) {
    int idx = askTaskIndex(tasks);
    if (idx == -1) {
        cout << "Invalid task number.\n";
        return;
    }
    cout << "New title: ";
    string title;
    getline(cin, title);
    if (title.empty()) {
        cout << "Title cannot be empty.\n";
        return;
    }
    tasks[idx].title = title;
    cout << "Task updated.\n";
}

void deleteTask(vector<Task> &tasks) {
    int idx = askTaskIndex(tasks);
    if (idx == -1) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + idx);
    cout << "Task deleted.\n";
}

int main() {
    vector<Task> tasks;
    loadTasks(tasks);

    while (true) {
        cout << "\n===== TO-DO LIST =====\n"
             << "1. Add task\n"
             << "2. View tasks\n"
             << "3. Mark task as done\n"
             << "4. Delete task\n"
             << "5. Edit task\n"
             << "6. Exit\n"
             << "Choose: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: showTasks(tasks); break;
            case 3: markDone(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5: editTask(tasks); break;
            case 6:
                saveTasks(tasks);
                cout << "Saved. Bye!\n";
                return 0;
            default: cout << "Invalid choice.\n";
        }
        saveTasks(tasks);  // save after every action so nothing is lost
    }
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printTodoList(const vector<string>& todoList) {
    if (todoList.empty()) {
        cout << "Your to-do list is empty." << endl;
    } else {
        cout << "Your to-do list:" << endl;
        for (size_t i = 0; i < todoList.size(); ++i) {
            cout << i + 1 << ". " << todoList[i] << endl;
        }
    }
}

void addTask(vector<string>& todoList, const string& task) {
    todoList.push_back(task);
    cout << "Task added: " << task << endl;
}

void deleteTask(vector<string>& todoList, int index) {
    if (index >= 1 && index <= static_cast<int>(todoList.size())) {
        cout << "Task deleted: " << todoList[index - 1] << endl;
        todoList.erase(todoList.begin() + index - 1);
    } else {
        cout << "Invalid task index!" << endl;
    }
}

int main() {
    vector<string> todoList;
    string task;
    int choice;
    int index;

    cout << "Welcome to the To-Do List Manager!" << endl;

    while (true) {
        cout << "\nMenu:\n1. View To-Do List\n2. Add Task\n3. Delete Task\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printTodoList(todoList);
                break;
            case 2:
                cout << "Enter the task: ";
                cin.ignore();
                getline(cin, task);
                addTask(todoList, task);
                break;
            case 3:
                printTodoList(todoList);
                if (!todoList.empty()) {
                    cout << "Enter the index of the task to delete: ";
                    cin >> index;
                    deleteTask(todoList, index);
                }
                break;
            case 4:
                cout << "Exiting... Have a great day!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a number from 1 to 4." << endl;
        }
    }

    return 0;
}

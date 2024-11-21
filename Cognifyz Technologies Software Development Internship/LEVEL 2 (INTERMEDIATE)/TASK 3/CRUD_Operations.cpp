#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    int id;
    string title;
    string description;

    Task(int id, string title, string description) {
        this->id = id;
        this->title = title;
        this->description = description;
    }
    
    void display() const {
        cout << "ID: " << id << ", Title: " << title << ", Description: " << description << endl;
    }
};

void createTask(vector<Task>& tasks, int& nextId) {
    string title, description;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter description: ";
    getline(cin, description);

    tasks.push_back(Task(nextId++, title, description));
    cout << "Task created successfully!" << endl;
}

void readTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    for (const auto& task : tasks) {
        task.display();
    }
}

void updateTask(vector<Task>& tasks) {
    int id;
    cout << "Enter task ID to update: ";
    cin >> id;

    for (auto& task : tasks) {
        if (task.id == id) {
            cout << "Enter new title: ";
            cin.ignore();
            getline(cin, task.title);
            cout << "Enter new description: ";
            getline(cin, task.description);
            cout << "Task updated successfully!" << endl;
            return;
        }
    }

    cout << "Task with ID " << id << " not found." << endl;
}

void deleteTask(vector<Task>& tasks) {
    int id;
    cout << "Enter task ID to delete: ";
    cin >> id;

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            cout << "Task deleted successfully!" << endl;
            return;
        }
    }

    cout << "Task with ID " << id << " not found." << endl;
}

int main() {
    vector<Task> tasks;
    int nextId = 1;
    int choice;

    while (true) {
        cout << "\nTask Manager\n";
        cout << "1. Create Task\n";
        cout << "2. Read Tasks\n";
        cout << "3. Update Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createTask(tasks, nextId);
                break;
            case 2:
                readTasks(tasks);
                break;
            case 3:
                updateTask(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout << "Exiting the application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

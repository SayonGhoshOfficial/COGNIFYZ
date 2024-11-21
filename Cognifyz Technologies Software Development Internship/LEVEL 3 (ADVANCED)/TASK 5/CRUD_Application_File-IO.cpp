#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    int id;
    string description;
    bool completed;
};

vector<Task> loadTasks(const string& filename) {
    vector<Task> tasks;
    ifstream file(filename);
    
    if (!file) {

        cout << "Unable to open the file for reading. Starting with an empty task list.\n";
        return tasks;
    }
    
    Task task;
    while (file >> task.id) {
        file.ignore();
        getline(file, task.description, ',');
        file >> task.completed;
        file.ignore();
        tasks.push_back(task);
    }
    
    file.close();
    return tasks;
}

void saveTasks(const string& filename, const vector<Task>& tasks) {
    ofstream file(filename);
    
    if (!file) {
        cout << "Unable to open the file for saving. Changes won't be saved.\n";
        return;
    }

    for (const Task& task : tasks) {
        file << task.id << "," << task.description << "," << task.completed << endl;
    }

    file.close();
}

void readTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    for (const Task& task : tasks) {
        cout << "ID: " << task.id
             << " | Description: " << task.description
             << " | Status: " << (task.completed ? "Completed" : "Pending") << endl;
    }
}

void createTask(vector<Task>& tasks) {
    Task newTask;
    newTask.id = tasks.empty() ? 1 : tasks.back().id + 1;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
}

void updateTask(vector<Task>& tasks) {
    int id;
    cout << "Enter task ID to update: ";
    cin >> id;
    
    for (Task& task : tasks) {
        if (task.id == id) {
            cout << "Enter new description: ";
            cin.ignore();
            getline(cin, task.description);
            cout << "Is the task completed? (1 for Yes, 0 for No): ";
            cin >> task.completed;
            return;
        }
    }
    
    cout << "Task with ID " << id << " not found!" << endl;
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
    
    cout << "Task with ID " << id << " not found!" << endl;
}

int main() {
    const string filename = "tasks.txt";
    
    vector<Task> tasks = loadTasks(filename);

    int choice;
    do {
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
                createTask(tasks);
                saveTasks(filename, tasks);
                break;
            case 2:
                readTasks(tasks);
                break;
            case 3:
                updateTask(tasks);
                saveTasks(filename, tasks);
                break;
            case 4:
                deleteTask(tasks);
                saveTasks(filename, tasks);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

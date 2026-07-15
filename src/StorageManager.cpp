#include "StorageManager.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

StorageManager::StorageManager(std::string file)
{
    filename = file;
}

void StorageManager::saveTasks(const std::vector<Task>& tasks)
{
    std::ofstream file(filename);

    for(auto task : tasks)
    {
        file << task.id << "|" << task.title << "|" << task.description << "|" << task.dueDate << "|" << task.priority << "|" << task.isCompleted << "\n";
    }

    file.close();
}

std::vector<Task> StorageManager::loadTasks()
{
    std::vector<Task> tasks;

    std::ifstream file(filename);

    if(!file.is_open())
    {
        return tasks;
    }

    std::string line;

    while(std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string id; 
        std::string title; 
        std::string description; 
        std::string dueDate; 
        std::string priority;         
        std::string isCompleted;
        
        std::getline(ss, id, '|');        
        std::getline(ss, title, '|');
        std::getline(ss, description, '|');
        std::getline(ss, dueDate, '|');
        std::getline(ss, priority, '|');        
        std::getline(ss, isCompleted, '|');

        Task task;
        
        task.id = std::stoi(id);
        task.title = title;
        task.description = description;
        task.dueDate = dueDate;
        task.priority = std::stoi(priority);
        task.isCompleted = std::stoi(isCompleted);
        
        tasks.push_back(task);
    }

    file.close();

    return tasks;
}
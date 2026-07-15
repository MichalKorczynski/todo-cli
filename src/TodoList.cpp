#include "TodoList.hpp"

TodoList::TodoList() : storage("tasks.txt")
{   
    loadList();
}

void TodoList::saveList()
{
    storage.saveTasks(tasks);
}

void TodoList::loadList()
{
    tasks = storage.loadTasks();
}

int TodoList::nextTaskId()
{
    return tasks.size() + 1;
}

void TodoList::reassignTaskIds()
{
    int id = 1;
    for(auto& task: tasks)
    {
        task.id = id++;
    }
}

void TodoList::addTask(
    std::string title,
    std::string description,
    std::string dueDate,
    int priority
)
{
    reassignTaskIds();

    Task newTask{
        false,
        nextTaskId(),
        priority,
        title,
        description,
        dueDate
    };

    tasks.push_back(newTask);
    saveList();
}
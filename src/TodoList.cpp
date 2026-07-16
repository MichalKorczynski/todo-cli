#include "TodoList.hpp"
#include <algorithm>


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

void TodoList::removeTask(int id)
{
    auto it = std::find_if(
        tasks.begin(),
        tasks.end(),
        [id](const Task& t)
        {
            return t.id == id;
        }
    );

    if(it != tasks.end())
    {
        tasks.erase(it);
    }
}

void TodoList::removeTask(std::string title)
{
    auto it = std::find_if(
        tasks.begin(),
        tasks.end(),
        [title](const Task& t)
        {
            return t.title == title;
        }
    );

    if(it != tasks.end())
    {
        tasks.erase(it);
    }
}
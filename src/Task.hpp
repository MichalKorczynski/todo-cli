#pragma once

#include <string>

struct Task
{
    bool isCompleted = false;
    int id;
    int priority = 1;
    std::string title;
    std::string description = "-";
    std::string dueDate = "-";

    static Task create(
        const std::string& title,
        const std::string& desc = "",
        const std::string& due = "",
        const int priority = 1
    )
    {
        Task task;
        task.title = title;
        task.priority = priority;

        if(!desc.empty())
        {
            task.description = desc;
        }
        if(!due.empty())
        {
            task.dueDate = due;
        }

        return task;
    }
};
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
};
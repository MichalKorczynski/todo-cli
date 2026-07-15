#include "Task.hpp"

#include <vector>
#include <string>


class TodoList
{
    private:
        std::vector<Task> tasks;
        void saveList();
        void loadList();
        int nextTaskId();
        void reassignTaskIds();

    public:
        TodoList();
        void addTask(
            std::string title,
            std::string description = "-",
            std::string dueDate = "-",
            int priority = 1
        );
        void removeTask(int id);
        void removeTask(std::string title);
};
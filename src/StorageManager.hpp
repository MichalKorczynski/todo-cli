#include "Task.hpp"

#include <string>
#include <vector>


class StorageManager
{
    private:
        std::string filename;

    public:
        StorageManager(std::string file);

        void saveTasks(const std::vector<Task>& tasks);
        std::vector<Task> loadTasks();
};
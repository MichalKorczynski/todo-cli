#include <iostream>
#include "TodoList.hpp"

int main(int argc, char* argv[])
{
    TodoList todo;

    if(argc < 2)
    {
        todo.displayList();
        return 1;
    }

    std::string command = argv[1];

    if(command == "add" || command == "-A" || command == "-a")
    {
        if(argc < 3)
        {
            std::cerr << "Error: Please specify a task to add.\n";
            return 1;
        }
        std::string title = argv[2]; 
        std::string description = "";
        std::string dueDate = "";
        int priority = 1;

        for(int i = 3; i < argc; ++i)
        {
            std::string arg = argv[i];
            if((arg == "-d" || arg == "--description") && (i + 1 < argc))
            {
                description = argv[i + 1];
                i++;
            }
            else if((arg == "-t" || arg == "--due") && (i + 1 < argc))
            {
                dueDate = argv[i + 1];
                i++;
            }
            else if((arg == "-p" || arg == "--priority") && (i + 1 < argc))
            {
                priority = std::stoi(argv[i + 1]);
                i++;
            }
        }
        todo.addTask(title,description,dueDate, priority);
    }
    else if(command == "remove" || command == "-R" || command == "-r")
    {
        
    }

    return 0;
}
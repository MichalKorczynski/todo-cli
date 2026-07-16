#include <iostream>
#include "TodoList.hpp"

int main()
{
    TodoList todo;
    todo.displayList();

    todo.removeTask(1);
    todo.displayList();
    return 0;
}
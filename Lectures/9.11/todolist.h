#ifndef __TODO_LIST_H__
#define __TODO_LIST_H__

#include "task.h"

namespace todo
{

  class ToDoList
  {
  public:
    /**
     * Creates an empty to-do list.
     */
    ToDoList();

    /**
     * Adds the given task to the end of this to-do list.
     *
     * @param t a task
     */
    void add(const Task& t);

    /**
     * Determines if there are uncompleted tasks on this list.
     *
     * @return true if and only if there are uncompleted tasks
     */
    bool isIncomplete() const;

    /**
     * Returns the next task on this to-do list.
     *
     * @return the next task on this to-do list
     */
    Task getNext() const;

    /**
     * Marks the next task on this to-do list as complete and moves it to the
     * end of this list's completed tasks list.
     */
    void completeNext();

    /**
     * Exchanges the next two incomplete items on this to-do list.  No
     * effect if there are fewer than two incomplete items.
     */
    void delayNext();

    /**
     * Moves the next incomplete task on this to-do list to the end.
     * No effect if this to-do list is empty.
     */
    void postponeNext();

    /**
     * Returns the total time remaining of all the uncompleted tasks on the
     * list.
     *
     * @return the total time remaining of all the uncompleted tasks.
     */
    int timeRemaining() const;

    /**
     * Returns the number of remaining uncompleted tasks on this list.
     *
     * @return the number of remaining uncompleted tasks
     */
    int remainingTasks() const;

  private:
    static const int MAX_TASKS = 10;
    Task list[MAX_TASKS];
    int completedCount;
    int totalCount;
  };

}


#endif

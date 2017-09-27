#include "task.h"
#include "todolist.h"

namespace todo
{

  ToDoList::ToDoList()
  {
    completedCount = 0;
    totalCount = 0;
  }

  ToDoList& ToDoList::add(const Task& t)
  {
    if (totalCount < MAX_TASKS)
    {
	    list[totalCount] = t;
	    totalCount++;
    }

    return *this;
  }

  bool ToDoList::isIncomplete() const
  {
    return (completedCount < totalCount);
  }

  Task ToDoList::getNext() const
  {
    if (completedCount < totalCount)
      {
	return list[completedCount];
      }
    else
      {
	// read about exceptions
      }
  }

  void ToDoList::completeNext()
  {
    if (completedCount < totalCount)
      {
	list[completedCount].complete();
	completedCount++;
      }
  }

  void ToDoList::delayNext()
  {
    if (totalCount - completedCount >= 2)
      {
	Task delayed = list[completedCount];
	list[completedCount] = list[completedCount + 1];
	list[completedCount + 1] = delayed;
      }
  }

  void ToDoList::postponeNext()
  {
    if (totalCount - completedCount >= 2)
      {
	Task postponed = list[completedCount];
	for (int i = completedCount; i < totalCount - 1; i++)
	  {
	    list[i] = list[i + 1];
	  }
	list[totalCount - 1] = postponed;
      }
  }

  int ToDoList::timeRemaining() const
  {
    int tot = 0;

    for (int i = completedCount; i < totalCount; i++)
      {
	tot += list[i].time();
      }

    return tot;
  }
  
  int ToDoList::remainingTasks() const
  {
    return totalCount - completedCount;
  }

  
}


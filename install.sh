#!/bin/bash

# Make task lists directory
mkdir ~/.tasks
touch ~/.tasks/usable
touch ~/.tasks/first_task_list
echo "first_task_list" > ~/.tasks/usable
# chmod 700 ~/.tasks # For safity. You may don't use it

# Make the command
chmod 777 tasks
cp tasks /usr/bin/tasks

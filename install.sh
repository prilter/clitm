#!/bin/bash

# Make task lists directory
mkdir ~/.tasks
touch ~/.tasks/usable
echo "Nothing" > ~/.tasks/.usable
# chmod 700 ~/.tasks # For safity. You may don't use it
make release

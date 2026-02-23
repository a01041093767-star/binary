#!/bin/bash
echo "Installing binary..."
sudo cp binary.hpp /usr/local/include/
if [ $? -eq 0 ]; then
    echo "Installation successful! Now you can use #include <binary.hpp>"
else
    echo "Installation failed. Please check your permissions."
fi
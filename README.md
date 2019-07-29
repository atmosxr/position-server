# Overview
Gives out positioning data from an Xvisio sensor using a Node.JS websocket server.
Primarily intended for use with webr.

# Installation
- Install prerequisites: Node.JS, npm, Xslam SDK, CMake, GNU Make, g++.
- Clone this repository: `git clone https://github.com/atmosxr/position-server.git && cd position-server`
- Install Node.JS dependencies: `npm install`
- Build the `print_6dof` program: `mkdir build && cd build && cmake .. && make && cd ..`
- Run the server: `node server.js`

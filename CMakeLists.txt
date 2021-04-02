cmake_minimum_required(VERSION 3.17)
project(P3)

set(CMAKE_CXX_STANDARD 11)

add_executable(P3 main.cpp PriorityQueue.cpp PriorityQueue.h Graph.cpp Graph.h Vertex.cpp Vertex.h VertexSet.cpp VertexSet.h illegal_exception.cpp illegal_exception.h)
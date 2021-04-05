# Makefile for Project 3
#
# You will need to rename this file to “Makefile” (note the capital M)
# and test it in  the ECE servers, with the command “make”
#
# Ensure that after the “make” command an executable with the expected name is
# created. For this example the expected name for the excecutable is dequeaslisttest
#

# List all the drivers
all: mstprimttest


# list the test program all classes (cpp files)
#  cpp files must use #include , to include *.h or *.hpp files

mstprimttest: mstprimtest.cpp Graph.cpp VertexSet.cpp Vertex.cpp PriorityQueue.cpp
	g++ -std=c++11 -o mstprimdriver mstprimtest.cpp Graph.cpp VertexSet.cpp Vertex.cpp PriorityQueue.cpp

# List all the executablmes under 'all:'
clean:
	rm mstprimdriver

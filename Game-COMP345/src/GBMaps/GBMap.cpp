#include "GBMap.h"
//#include <iostream>
//#include <map>
//#include <iterator>
//#include <vector>

void GB::GBMap::print()
{
	std::cout << "GBMap is working!\n";
}

void GB::Graph::addVertex(Node src)
{
	if (graph.find(src) == graph.end())
	{
		graph[src];
		return;
	}

	std::cout << "That node already exists!" << std::endl;
}

void GB::Graph::traverse()
{
	int i = 0;
	for (auto  pair : graph) {
		
		i++;
		std::cout << i << std::endl;
	}
}

void GB::GBMapDriver::run()
{
	Graph* testGraph = new Graph;

	testGraph->addVertex(Node("T1"));
	testGraph->addVertex(Node("T2"));

	testGraph->traverse();

}

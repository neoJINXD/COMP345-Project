#include "GBMap.h"
//#include <iostream>
//#include <map>
//#include <iterator>
//#include <vector>
//#include <utility>
//#include <map>

GB::Graph::~Graph()
{
	delete graph;
}

void GB::Graph::addVertex(int srcId)
{
	//auto graphPtr = graph.get;

	//If the node with srcId is not found in the map
	if (graph->find(srcId) == graph->end())
	{
		Node node(srcId);
		graph->insert(std::pair<int, Node>(srcId, node));

		return;
	}

	std::cout << "That node already exists!" << std::endl;
}

void GB::Node::insertAdj(Node node)
{
	this->adj_list->push_back(node);
}

void GB::Graph::addEdge(int src, int dest) 
{

	Node srcObj = graph->find(src)->second;
	Node destObj = graph->find(dest)->second;

	//Undirected Graph
	srcObj.insertAdj(destObj);
	destObj.insertAdj(srcObj);


}

void GB::Node::printAdjList()
{
	std::size_t sz = adj_list->size();
	int i = 0;
	for (auto node : *adj_list)
	{
		i++;
		std::cout << node.getId();
		if (i == sz)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << ", ";
		}
	}
}

void GB::Graph::printGraph()
{
	std::cout << "Node|\tAdjacentNodes\n";	
	for (auto pair : *graph)
	{
		std::cout << pair.first << ":\t";
		pair.second.printAdjList();
		std::cout << std::endl;
	}
}

void GB::GBMap::createGrid(int rows, int cols)
{
	int totalVertexes = rows * cols;
	
	//Create vertexes
	for (int vertex = 1; vertex <= totalVertexes; vertex++)
	{
		graph->addVertex(vertex);
	}

	//Link cols
	for (int vertex = 1; vertex <= totalVertexes; vertex++) 
	{
		//Link node on the right
		//Check if the current vertex is not the last vertex on that row
		if ((vertex % cols) != 0)
		{
			graph->addEdge(vertex, vertex + 1);
		}

		if (vertex + cols <= totalVertexes)
		{
			graph->addEdge(vertex, vertex + cols);
		}
	}

	//Link rows
	

	graph->printGraph();
}

void GB::GBMapDriver::run()
{
	//Graph* testGraph = new Graph();
	GBMap* testMap = new GBMap();

	testMap->createGrid(4, 6);
}


void GB::GBMap::createFullBoard() 
{
	
	


}
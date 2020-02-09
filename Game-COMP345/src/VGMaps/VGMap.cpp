#include "VGMap.h"
#include <iostream>
void VG::Node::insertAdj(Node node)
{
	this->adj_list->push_back(node);
}



void VG::Node::printAdjList()
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

//Graph Implmentations

VG::Graph::~Graph()
{
	delete graph;
}

void VG::Graph::addVertex(int srcId)
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
void VG::Graph::addEdge(int src, int dest)
{

	Node srcObj = graph->find(src)->second;
	Node destObj = graph->find(dest)->second;

	//Undirected Graph
	srcObj.insertAdj(destObj);
	destObj.insertAdj(srcObj);


}

void VG::Graph::printGraph()
{
	std::cout << "Node|\tAdjacentNodes\n";
	for (auto pair : *graph)
	{
		std::cout << pair.first << ":\t";
		pair.second.printAdjList();
		std::cout << std::endl;
	}
}


void VG::VGMap::printVillage() {
	std::cout << "This is " << owner << " village!";
}
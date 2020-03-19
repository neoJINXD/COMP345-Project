#include "VGMap.h"
#include <iostream>

class VG::Node;
class VG::Graph;
class VG::VGMap;


deck::Building* VG::Node::getBuilding()
{
	return building;
}
//Node Implementations
void VG::Node::insertAdj(Node* node)
{
	this->adj_list->push_back(node);
}

VG::Node::~Node()
{
	if (nodeId)
		delete nodeId;

	if (placementCost)
		delete placementCost;

	if (building)
	{
		delete building;
		building = nullptr;
	}
	//Modify later to handle vector of pointers

	for (auto adj : *adj_list) {
		adj = nullptr;
	}
	adj_list->clear();

	delete adj_list;
	adj_list = nullptr;

}

void VG::Node::printAdjList()
{
	std::size_t sz = adj_list->size();
	int i = 0;
	for (auto node : *adj_list)
	{
		i++;
		std::cout << node->getId();
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
	for (auto v : *graph)
	{
		delete v.second;
		v.second = nullptr;
	}

	graph->clear();
	delete graph;
	graph = nullptr;
}

void VG::Graph::addVertex(int srcId)
{
	//auto graphPtr = graph.get;

	//If the node with srcId is not found in the map
	if (graph->find(srcId) == graph->end())
	{
		Node* node = new Node(srcId);
		graph->insert({ srcId, node });

		return;
	}

	std::cout << "That node already exists!" << std::endl;
}
void VG::Graph::addEdge(int src, int dest)
{

	Node* srcObj = graph->find(src)->second;
	Node* destObj = graph->find(dest)->second;

	//Undirected Graph
	srcObj->insertAdj(destObj);
	destObj->insertAdj(srcObj);


}

void VG::Graph::printGraph()
{
	std::cout << "Node|\tCost\t|AdjacentNodes\n";
	for (auto pair : *graph)
	{
		std::cout << "" << pair.first << ":\t" << pair.second->getCost() << "\t";
		pair.second->printAdjList();
		std::cout << std::endl;
	}
}



//VGMap Implementations

void VG::VGMap::placeBuilding(int loc, deck::Building *building)
{
	graph->getGraph()->find(loc)->second->setBuilding(building);
}

deck::Building* VG::VGMap::peekBuilding(int loc)
{
	return graph->getGraph()->find(loc)->second->getBuilding();
}

void VG::VGMap::buildBoard(int rows, int cols)
{
	int totalVertexes = rows * cols;

	//Create vertexes
	for (int vertex = 1; vertex <= totalVertexes; vertex++)
	{
		graph->addVertex(vertex);
		
	}

	//Add edges to all vertexes O(n)
	for (int vertex = 1; vertex <= totalVertexes; vertex++)
	{
		//Link node on the right
		//Check if the current vertex is not the last vertex on that row
		if ((vertex % cols) != 0)
		{
			graph->addEdge(vertex, vertex + 1);
		}

		//Link path to the node below current node
		if (vertex + cols <= totalVertexes)
		{
			graph->addEdge(vertex, vertex + cols);
		}
	}
	//Set costs

	int cost = 1;
	for (auto pair : *graph->getGraph())
	{

		pair.second->setCost(cost);
		if (pair.first % cols == 0) {
			cost++;
		}
	}
	

	graph->printGraph();
}

VG::VGMap::VGMap()
{
	graph = new Graph();
	buildBoard(6, 5);
}

VG::VGMap::~VGMap() {
	delete graph;
	graph = nullptr;
	
}

void VG::VGMapDriver::run()
{
	VGMap* test = new VGMap();
	
	deck::Building* b1 = new deck::Building(6, Wheat);


	test->placeBuilding(1,b1);
	test->peekBuilding(1)->printInfo();
	if (test->peekBuilding(2))
		std::cout << "yes" << std::endl;
	else
		std::cout << "is null" << std::endl;

	delete test;
	test = nullptr;
}

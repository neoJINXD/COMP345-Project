#include "VGMap.h"
#include <iostream>

class VG::Node;
class VG::Graph;
class VG::VGMap;
//Node Implementations
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
	graph = nullptr;
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
	std::cout << "Node|\tCost\t|AdjacentNodes\n";
	for (auto pair : *graph)
	{
		std::cout << "" << pair.first << ":\t" << pair.second.getCost() << "\t";
		pair.second.printAdjList();
		std::cout << std::endl;
	}
}



//VGMap Implementations

void VG::VGMap::placeBuilding(int loc, deck::Building building)
{
	graph->getGraph().find(loc)->second.setBuilding(building);
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
	for (auto pair : graph->getGraph())
	{

		pair.second.setCost(cost);
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
	//deck::Building b1;
	///*b1.cost = new int(12);
	//b1.resource = new Resource();

	//test->placeBuilding(1, b1);*/

}

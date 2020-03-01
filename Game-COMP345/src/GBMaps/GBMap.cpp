#include "GBMap.h"
//#include <sstream>

//Misc
std::string EdgeToStr(EdgeLoc edge) {
	switch (edge)
	{
	case EdgeLoc::Top:
		return "Top";
	case EdgeLoc::Bot:
		return "Bot";
	case EdgeLoc::Right:
		return "Right";
	case EdgeLoc::Left:
		return "Left";
	default:
		return "NULL";
		break;
	}
}

//Node Implementaitonss
void GB::Node::insertAdj(EdgeLoc edge, Node node)
{
	this->adjList->push_back({ edge, node });
}

int GB::Node::getAdj(EdgeLoc edge)
{
	for (auto pair : *adjList)
	{
		if (pair.first == edge)
		{
			return *pair.second.nodeId;
		}
	}

	return -1; //node with that edge does not exist
}

//Node Implementations, might switch to have vector hold pointers to node
void GB::Node::insertAdj(Node node)
{
	this->adj_list->push_back(node);
}

void GB::Node::setTile(deck::Tile* _tile)
{
	tile = _tile;
}

deck::Tile* GB::Node::getTile() const
{
	return tile;
}

std::string GB::Node::getOwner() const
{
	return *owner;
}

void GB::Node::printAdjList()
{
	std::size_t sz = adj_list->size();
	int i = 0;
	/*for (auto node : *adj_list)
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
	}*/

	for (auto v : *adjList)
	{
		i++;
		std::cout << "(E:" << EdgeToStr(v.first) << " | V:" << v.second.getId() << ")";
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

GB::Graph::~Graph()
{
	delete graph;
	
	if (graph != nullptr)
	{
		graph = nullptr;
	}
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

//
void GB::Graph::addEdge(int src, int dest, EdgeLoc edgeToDest, EdgeLoc edgeToSrc)
{
	Node srcNode = graph->find(src)->second;
	Node destNode = graph->find(dest)->second;

	//Undirected Graph
	srcNode.insertAdj(edgeToDest, destNode);
	destNode.insertAdj(edgeToSrc, srcNode);
}

void GB::Graph::addEdge(int src, int dest)
{
	Node srcObj = graph->find(src)->second;
	Node destObj = graph->find(dest)->second;

	//Undirected Graph
	srcObj.insertAdj(destObj);
	destObj.insertAdj(srcObj);


}

GB::Node* GB::Graph::getNode(int nodeId)
{
	return &graph->find(nodeId)->second;
}

void GB::Graph::insertTile(int nodeId, deck::Tile* tile)
{


	graph->find(nodeId)->second.setTile(tile);
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

//GBMap Implementations

void GB::GBMap::createGrid(int rows, int cols)
{
	int totalVertexes = rows * cols;
	
	//Create vertexes, initialize the nodeIds / locations
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
			graph->addEdge(vertex, vertex + 1, EdgeLoc::Right, EdgeLoc::Left);
		}

		//Link path to the node below current node
		if (vertex + cols <= totalVertexes)
		{
			graph->addEdge(vertex, vertex + cols);
			graph->addEdge(vertex, vertex + cols, EdgeLoc::Bot, EdgeLoc::Top);
		}
	}

	//Link rows
	

	graph->printGraph();
}

bool GB::GBMap::buildABear()
{
	switch (*numberOfPlayers)
	{
	case 2:
		create5By5();
		break;
	case 3:
		create5By7();
		break;
	case 4:
		createFullBoard();
		break;
	default:
		std::cout << "Invalid number of players!" << std::endl;
		return false;

	}

	return true; // uhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
}

void GB::GBMap::blockKeys(std::vector<int> badKeys)
{
	blockedKeys = new std::vector<int>(badKeys); // UmU
}

void GB::GBMap::setOwner(int loc, std::string player)
{
	graph->getNode(loc)->setOwner(player);
}

std::string GB::GBMap::getOwner(int loc) const
{

	return graph->getNode(loc)->getOwner();
}

void GB::GBMap::placeTile(int loc, deck::Tile* tile)
{

	if (peekTile(loc) != nullptr || 
		std::find(blockedKeys->begin(), blockedKeys->end(), loc) != blockedKeys->end())
	{
		std::cout << "It is not free estate!\n";
		return;
	}
	graph->insertTile(loc, tile);
	*recentTile = loc; 
}

deck::Tile* GB::GBMap::peekTile(int loc)
{

	return graph->getNode(loc)->getTile();
}

deck::Tile* GB::GBMap::getAdjTile(int loc, EdgeLoc adjDir)
{
	int adjNodeId = graph->getNode(loc)->getAdj(adjDir);
	if (adjNodeId == -1)
	{
		return nullptr;
	}
	return peekTile(adjNodeId);
}

void GB::GBMap::create5By7() {
	createGrid(5, 7);
}

void GB::GBMap::create5By5() {
	createGrid(5, 5);
}

void GB::GBMap::createFullBoard()
{
	createGrid(7, 7);
}

GB::GBMap::~GBMap()
{
	delete graph;
	graph = nullptr;
}



void GB::GBMapDriver::run()
{
	//Graph* testGraph = new Graph();
	GBMap* testMap = new GBMap();

	if (testMap->buildABear()) 
	{
		//testMap->blockKeys({1,2,3,4});
		testMap->placeTile(8, new deck::Tile(Wheat, Wheat, Stone, Timber));
		testMap->placeTile(4, new deck::Tile(Stone, Wheat, Stone, Timber));
		testMap->placeTile(3, new deck::Tile(Wheat, Sheep, Stone, Timber));
		testMap->placeTile(2, new deck::Tile(Wheat, Timber, Stone, Timber));
		testMap->placeTile(1, new deck::Tile(Sheep, Wheat, Stone, Timber));
		testMap->getAdjTile(1, EdgeLoc::Bot)->printInfo();
		/*testMap->peekTile(5)->printInfo();
		testMap->setOwner(1, "C-MS <3");
		std::cout << "Owner:\t" << testMap->getOwner(1) << std::endl;*/
		
	}
	
}



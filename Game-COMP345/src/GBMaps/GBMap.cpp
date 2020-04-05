#include "GBMap.h"
class GBMap;
class Node;
//Misc, used for testing only
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

GB::Node::Node(int _nodeId) : nodeId(new int(_nodeId)), owner(new std::string("Free Real Estate")) 
{
	
	tile = nullptr;
	adjList = new std::vector<Vertex>();
}

GB::Node::~Node()
{
	delete nodeId;
	nodeId = nullptr;

	delete owner;
	//owner = nullptr;

	if (tile) {
		delete tile;
		tile = nullptr;
	}
	
	for (auto adj : *adjList) {
		
		adj.second = nullptr;
	}
	
	//adjList->clear();
	delete adjList;
	adjList = nullptr;

}

//Node Implementaitonss
void GB::Node::insertAdj(EdgeLoc edge, Node* node)
{
	this->adjList->push_back({ edge, node });
}

int GB::Node::getAdj(EdgeLoc edge)
{
	for (auto pair : *adjList)
	{
		if (pair.first == edge)
		{
			return *pair.second->nodeId;
		}
	}

	return -1; //node with that edge does not exist
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
	int i = 0;

	std::size_t sz = adjList->size();
	for (auto v : *adjList)
	{
		i++;
		std::cout << "(E:" << EdgeToStr(v.first) << " | V:" << v.second->getId() << ")";
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

bool GB::Node::isAdj(Node* adjNode)
{
	for (auto pair : *adjList)
	{
		if (pair.second->getId() == adjNode->getId())
		{ 
			return true;
		}
	}

	return false;
}

EdgeLoc* GB::Node::getEdge(Node* adjNode)
{
	if (isAdj(adjNode))
	{
		for (auto i : *adjList)
		{
			if (i.second->getId() == adjNode->getId())
			{
				return &i.first;
			}
		}
	}

	return nullptr;
}



void GB::GBMap::addVertex(int srcId)
{
	//auto graphPtr = graph.get;

	//If the node with srcId is not found in the map
	if (graph->find(srcId) == graph->end())
	{
		Node* node = new Node(srcId);
		graph->emplace(srcId, node);

		return;
	}

	//std::cout << "That node already exists!" << std::endl;
}

void GB::GBMap::addEdge(int src, int dest, EdgeLoc edgeToDest, EdgeLoc edgeToSrc)
{
	Node* srcNode = graph->find(src)->second;
	Node* destNode = graph->find(dest)->second;
	
	
	//Undirected Graph
	srcNode->insertAdj(edgeToDest, destNode);
	destNode->insertAdj(edgeToSrc, srcNode);
}

void GB::GBMap::printGraph()
{
	std::cout << "Node|\tAdjacentNodes\n";
	for (auto pair : *graph)
	{
		std::cout << pair.first << ":\t";
		
		if (pair.second->getTile() != nullptr) {
			std::vector<Resource>* res = pair.second->getTile()->getResources();
			for (auto r : *res)
				std::cout << int(r) << ", ";
		}
		pair.second->printAdjList();
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
		addVertex(vertex);
	}

	//Add edges to all vertexes O(n)
	for (int vertex = 1; vertex <= totalVertexes; vertex++) 
	{
		//Link node on the right
		//Check if the current vertex is not the last vertex on that row
		if ((vertex % cols) != 0)
		{
			//graph->addEdge(vertex, vertex + 1);
			addEdge(vertex, vertex + 1, EdgeLoc::Right, EdgeLoc::Left);
		}

		//Link path to the node below current node
		if (vertex + cols <= totalVertexes)
		{
			//graph->addEdge(vertex, vertex + cols);
			addEdge(vertex, vertex + cols, EdgeLoc::Bot, EdgeLoc::Top);
		}
	}

	
}

bool GB::GBMap::buildBoard()
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

	return true; 
}

//Specifies the nodes that are blocked; Cannot place on that node
void GB::GBMap::blockKeys(const std::vector<int>& badKeys)
{
	if (blockedKeys) {
		delete blockedKeys;
		blockedKeys = nullptr;
	}
	blockedKeys = new std::vector<int>(badKeys); 
}

void GB::GBMap::setOwner(int loc, std::string player)
{
	getNode(loc)->setOwner(player);
}

std::string GB::GBMap::getOwner(int loc) const
{

	return getNode(loc)->getOwner();
}

//Very error prone, find a better way
void GB::GBMap::placeTile(int loc, deck::Tile* tile)
{
	//Check at this vertex if a tile already exists
	deck::Tile* existTile = peekTile(loc);
	if (false || 
		std::find(blockedKeys->begin(), blockedKeys->end(), loc) != blockedKeys->end())
	{
		delete tile;
		std::cout << "It is not free estate!\n";
		return;
	}
	graph->find(loc)->second->setTile(tile);
	*recentTile = loc; 
}

deck::Tile* GB::GBMap::peekTile(int loc) const
{
	//Something is deleting the node around here
	return getNode(loc)->getTile();
}

deck::Tile* GB::GBMap::getAdjTile(int loc, EdgeLoc adjDir)
{
	int adjNodeId = getNode(loc)->getAdj(adjDir);
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
	for (auto k : *graph)
	{
		delete k.second;
		k.second = nullptr;
	}
	graph->clear();
	delete graph;
	graph = nullptr;


	delete numberOfPlayers;
	numberOfPlayers = nullptr;

	delete recentTile;
	recentTile = nullptr;

	blockedKeys->clear();
	delete blockedKeys;
	blockedKeys = nullptr;

}

void GB::GBMapDriver::run()
{
	//Graph* testGraph = new Graph();
	GBMap* testMap = new GBMap();

	if (testMap->buildBoard()) 
	{
		//testMap->blockKeys({1,2,3,4});

		testMap->placeTile(1, new deck::Tile(Wheat, Wheat, Stone, Timber));
		testMap->placeTile(4, new deck::Tile(Stone, Wheat, Stone, Timber));
		testMap->placeTile(3, new deck::Tile(Wheat, Sheep, Stone, Timber));
		testMap->placeTile(2, new deck::Tile(Wheat, Timber, Stone, Timber));
		testMap->placeTile(1, new deck::Tile(Sheep, Wheat, Stone, Timber));
		testMap->getAdjTile(1, EdgeLoc::Right)->printInfo();
		
	}
	testMap->printGraph();

	delete testMap;
	//delete testMap;
	testMap = nullptr;

	return;
}



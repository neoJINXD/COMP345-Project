#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <vector>
#include <map>
#include <string>
#include <utility>
#include "../Resources/Resources.h" 
#include "../Helpers/Graph.h"

namespace VG {

	class Node {
	private:
		//const std::string& name; //Replace with Tile object
		
		//Member that is used to identify / locate the node only. Can convert it into a different type later, example string
		int* nodeId;
		int* placementCost;
		deck::Building* building;
		
		//std::vector<Node*>* adj_list = new std::vector<Node*>();
		std::vector<std::pair<EdgeLoc, Node*>>* adjList = new std::vector<std::pair<EdgeLoc, Node*>>();
	public:
		Node(int _nodeId) : nodeId(new int(_nodeId)), placementCost(new int(0)), building(nullptr) {}
		//Node(const Node& node);
		~Node();
		int getId() { return *nodeId; }
		void setCost(int value) { *placementCost = value; }
		int getCost() { return *placementCost; }
		void setBuilding(deck::Building* _building) { building = _building; }
		deck::Building* getBuilding();
		//void insertAdj(Node* node);
		void insertAdj(Node* node, EdgeLoc loc);
		void printAdjList();

	};

	class Graph
	{
	private:
		//typedef Node square;
		//int* numberOfNodes = new int(0);
		//const int* maxNodes;


		std::map<int, Node*>  *graph = new std::map<int, Node*>();


	public:

		//Graph(int* _numberOfNodes) : numberOfNodes(_numberOfNodes), graph(new std::map<int, Node>()) {}
		Graph() = default;

		//Cleanup memory
		~Graph();

		//Add vertex no edge
		void addVertex(int src);

		//Create edge between two nodes
		void addEdge(int src, int dest);

		std::map<int, Node*>* getGraph() { return graph; }

		void printGraph(); //Traveser all vertexes and list adjacents

	};

	
	class VGMap : public dat::Graph
	{

	private:
		//Graph* graph;
		std::string* villageName;
		std::map<int, Node*>* graph;
		void buildBoard(int rows, int cols);

		int rowScore[6] = { 6,5,4,3,2,1 };
		int colScore[5] = { 5,4,3,4,5 };
		void dat::Graph::addVertex(int nodeId);
		void dat::Graph::addEdge(int src, int dest, EdgeLoc edgeSrc, EdgeLoc edgeDest);

	public:
		VGMap();
		VGMap(std::string name);
		//VGMap(std::string _owner) : owner(_owner), graph(new Graph()) { buildBoard(6, 5); }
		~VGMap();
		void placeBuilding(int loc, deck::Building* building);
		deck::Building* peekBuilding(int loc);

		void setCustomScores(int* rows, int* cols);
		int* getRowScore() { return rowScore; }
		int* getColScore() { return colScore; }

		void printGraph();
	};

	class VGMapDriver 
	{
	public:
		void run();
	};
}


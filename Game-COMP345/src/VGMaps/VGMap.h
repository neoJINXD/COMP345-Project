#pragma once
#ifndef _DEBUG
#define _DEBUG
#endif // !_DEBUG
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#endif
#include <vector>
#include <map>
#include <string>
#include <memory>
#include "../Resources/Resources.h" 

namespace VG {

	class Node {
	private:
		//const std::string& name; //Replace with Tile object
		
		//Member that is used to identify / locate the node only. Can convert it into a different type later, example string
		int* const nodeId;
		int* const placementCost;
		deck::Building* building;

		//std::unique_ptr<int> nodeId;

		std::vector<Node>* adj_list = new std::vector<Node>();
	public:
		Node(int _nodeId) : nodeId(new int(_nodeId)), placementCost(new int(0)), building(nullptr) {}
		~Node();
		int getId() { return *nodeId; }
		void setCost(int value) { *placementCost = value; }
		int getCost() { return *placementCost; }
		void setBuilding(deck::Building* _building) { building = _building; }
		deck::Building* getBuilding();
		void insertAdj(Node node);

		void printAdjList();

	};

	class Graph
	{
	private:
		//typedef Node square;
		//int* numberOfNodes = new int(0);
		//const int* maxNodes;


		std::map<int, Node>  *graph = new std::map<int, Node>();


	public:

		//Graph(int* _numberOfNodes) : numberOfNodes(_numberOfNodes), graph(new std::map<int, Node>()) {}
		Graph() = default;

		//Cleanup memory
		~Graph();

		//Add vertex no edge
		void addVertex(int src);

		//Create edge between two nodes
		void addEdge(int src, int dest);

		std::map<int, Node>* getGraph() { return graph; }

		//void getNode();

		//void getEdges();



		void printGraph(); //Traveser all vertexes and list adjacents

	};

	
	class VGMap
	{

	private:
		Graph* graph;
		//std::string owner;
		void buildBoard(int rows, int cols);
	public:
		VGMap();
		//VGMap(std::string _owner) : owner(_owner), graph(new Graph()) { buildBoard(6, 5); }
		~VGMap();
		//void printVillage();
		void placeBuilding(int loc, deck::Building* building);
		deck::Building* peekBuilding(int loc);
	};

	class VGMapDriver 
	{
	public:
		void run();
	};
}


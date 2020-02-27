#pragma once
#include <vector>
#include <map>
#include <string>
//#include <iostream>
#include "../Resources/Resources.h"
//#include <memory>

namespace GB 
{


	class Node 
	{
	private:
		//const std::string& name; //Replace with Tile object
		int* nodeId;
		std::string* const owner; // Replace with player
		deck::Tile* tile = nullptr;

		std::vector<Node>* adj_list = new std::vector<Node>();
	public:
		Node(int _nodeId) : nodeId(new int(_nodeId)), owner(new std::string("Free Real Estate")){}
		//Node(int _nodeId, std::string _owner) : nodeId(new int(_nodeId)), owner() { }
		int getId() { return *nodeId; }

		void insertAdj(Node node);
		void setTile(deck::Tile _tile); // func(new Tile()) func(&tile)
		deck::Tile getTile() const;
		void setOwner(std::string _owner) { *owner = _owner; }
		std::string getOwner() const;
		void printAdjList();

		/*
		inline bool operator<(const Node& node) { return this->nodeId < node.nodeId; }
		inline friend bool operator<(const Node& node1, const Node& node2) { return node1.nodeId < node2.nodeId; }
		inline friend bool operator==(const Node& node1, const Node& node2) { return node1.nodeId == node2.nodeId; }
		inline friend bool operator>(const Node& node1, const Node& node2) { return node1.nodeId > node2.nodeId;  }
		*/
	
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

		Node getNode(int nodeId);
		
		void getEdges(int nodeId);
		

		void insertTile(int nodeId, deck::Tile* tile);
		void printGraph(); //Traveser all vertexes and list adjacents
		
	};

	class GBMap
	{

	private:
		const int* numberOfPlayers = new int(4);
		Graph* graph = new Graph();

		void createFullBoard();
		void create5By7();
		void create5By5();
		void createGrid(int row, int col);

	public:

		GBMap() = default;
		~GBMap();
		explicit GBMap(const int* _players) : numberOfPlayers(_players), graph(new Graph()) {}
		//~GBMap(); // Delete all pointers
		void buildBoard();

		void setOwner(int loc, std::string player);
		std::string getOwner(int loc) const;
		void insertTile(int loc, deck::Tile tile);
		//inline void print();

	};

	
	class GBMapDriver {

	public:
		
		
		void run();

	};
	
}


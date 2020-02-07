#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
//#include <memory>

namespace GB {
	
	enum Players  {
		
	};

	class Node {
	private:
		//const std::string& name; //Replace with Tile object
		int* nodeId;

		std::vector<Node>* adj_list = new std::vector<Node>();
	public:
		Node(int _nodeId) : nodeId(new int(_nodeId)) {}
		int getId() { return *nodeId; }

		void insertAdj(Node node);

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
		const int* maxNodes;


		std::map<int, Node>  *graph = new std::map<int, Node>();

		
	public:

		//Graph(int* _numberOfNodes) : numberOfNodes(_numberOfNodes), graph(new std::map<int, Node>()) {}
		Graph() = default;
		~Graph();
		//Add vertex no edge
		void addVertex(int src);
		//Create edge between two nodes
		void addEdge(int src, int dest);
		

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

	public:

		GBMap() = default;
		explicit GBMap(const int* _players) : numberOfPlayers(_players), graph(new Graph()) {}
		//~GBMap(); // Delete all pointers
		void createGrid(int row, int col);
		inline void print();

	};

	
	class GBMapDriver {

	public:
		
		
		void run();

	};
	
}


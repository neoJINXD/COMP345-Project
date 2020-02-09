#pragma once
#include <vector>
#include <map>
#include <string>

namespace VG {

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
		Graph();

		//Cleanup memory
		~Graph();

		//Add vertex no edge
		void addVertex(int src);

		//Create edge between two nodes
		void addEdge(int src, int dest);


		void getNode();

		void getEdges();


		void printGraph(); //Traveser all vertexes and list adjacents

	};

	class VGMap
	{

	private:
		Graph* village;
		const std::string& owner;
	public:
		VGMap(const std::string& _owner) : owner(_owner) {}
		
		void printVillage();

	};
}


#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>

namespace GB {
	//Will change this later to hold Tile objects
	class Node {
	private:
		std::string name;
		//std::vector<Node>* adjacent_nodes;
	public:
		Node(const std::string& _name) : name(_name) {}
		std::string get_name() { return name; };

		inline friend bool operator<(const Node& node1, const Node& node2) { return node1.name < node2.name; }
		inline friend bool operator==(const Node& node1, const Node& node2) { return node1.name == node2.name; }
		inline friend bool operator>(const Node& node1, const Node& node2) { return node1.name > node2.name;  }

	};

	

	class Graph
	{
	private:
		//typedef Node square;
		int max_nodes;

		//square S1 is the present node, and the vector<square> contains all nodes adjacent to S1 
		std::map<Node, std::vector<Node>> graph;
		
		

	public:

		//Add vertex no edge
		void addVertex(Node src);
		//Create edge between two nodes
		void addEdge(Node n1, Node n2);

		void traverse(); //Traveser all vertexes and list adjacents



	};

	class GBMap
	{
	private:
		int n_players = 4;


	public:
		void print();
		void createGrid(); //create grid based on number of players
	};

	
	class GBMapDriver {
	public:
		
		void run();

	};
	
}


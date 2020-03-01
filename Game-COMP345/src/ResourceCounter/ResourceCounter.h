#pragma once
#include "../GBMaps/GBMap.h"
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include "../Resources/Resources.h"

namespace counter
{
	//Sub Resource Mapping. 
	enum class SubNode
	{
		TopLeft,
		TopRight,
		BotRight,
		BotLeft
	};

	class ResourceNode {
	private:
		std::pair<int, SubNode>* nodeId; 
		Resource* resource;
		//bool* visited;
		typedef std::vector<std::pair<EdgeLoc, ResourceNode*>> AdjNodes;
		std::vector<std::pair<EdgeLoc, ResourceNode*>>* adjResources = new AdjNodes();

	public:

		ResourceNode(std::pair<int, SubNode> _nodeId, Resource _resource) : resource(new Resource(_resource)), nodeId(new std::pair<int, SubNode>(_nodeId)){}
		int getTileId() { return nodeId->first;  } // Gets the tile this resource resides in. (See GBMap)
		AdjNodes getAdjResources();
		void setAdjResource(EdgeLoc edgeDir, ResourceNode* adjNode);
		ResourceNode* getAdj(EdgeLoc dir);

	};


	class SubGraph {
	private:
		//typedef Node square;
		//int* numberOfNodes = new int(0);
		//const int* maxNodes;
		//Key: <NodeId of the whole tile, SubNodeId>
		typedef std::pair<int, SubNode> SubTile;
		std::map<SubTile, ResourceNode>* graph = new std::map<SubTile, ResourceNode>();


	public:

		//Graph(int* _numberOfNodes) : numberOfNodes(_numberOfNodes), graph(new std::map<int, Node>()) {}
		SubGraph() = default;

		//Cleanup memory
		~SubGraph();

		//Add vertex no edge

		void addVertex(SubTile nodeLoc, Resource resource);
		void addEdge(SubTile src, SubTile dest, EdgeLoc edgeSrc, EdgeLoc edgeDest);
		//void addEdge(int src, int dest);

		//Read resource at this vertex
		ResourceNode getResource(SubTile nodeLoc);


		void buildGraph();
		void printGraph(); //Travese all vertexes and list adjacents
	};

	/*
	1. Player Places a Tile
	2. For each resource in just placed harvest tile
		create sub-graph of adjacent resources, use current resource as root
		increment count of chained resources
	
	*/
	class ResourceCounter
	{
	private:
		typedef std::map<Resource, int> ResourceScores;
		ResourceScores* const counter;

		//Holds the state of the gameboard
		SubGraph* harvestGraph;
		//traverse node

		

	public:
		ResourceCounter() : counter(new ResourceScores()), harvestGraph(new SubGraph()) {}
		
		void buildSubGraph();
		void calcResourceCount(GB::GBMap gb);

	};


	class ResourceCounterDriver
	{
	public:
		void run();
	};

}



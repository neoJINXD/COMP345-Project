#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <vector>
#include <map>
#include <string>

#include "../Resources/Resources.h"
#include <utility>
#include "../Helpers/Graph.h"

namespace GB 
{
	
	class Node 
	{
	private:
		//const std::string& name; //Replace with Tile object
		int* nodeId;
		std::string* owner; // Replace with player
		deck::Tile* tile;

		//Keeps track of where the adjacent node is using edge as location
		typedef std::pair<EdgeLoc, Node*> Vertex;
		std::vector<Vertex>* adjList;
		
	public:
		Node(int _nodeId);
		~Node();
		int getId() { return *nodeId; }

		//Insert an adjnode with corresponding edge location. Ex: Node 1 is Right of this node
		void insertAdj(EdgeLoc edge, Node* node);
		int getAdj(EdgeLoc edge);
		void setTile(deck::Tile* _tile); 
		deck::Tile* getTile() const;
		void setOwner(std::string _owner) { *owner = _owner; }
		std::string getOwner() const;
		void printAdjList();
		bool isAdj(Node* adjNode);
		EdgeLoc* getEdge(Node* adjNode); // get position of adj node
		std::vector<Vertex>* getAdjList() { return adjList; }
	};

	class GBMap : public dat::Graph
	{

	private:
		const int* numberOfPlayers = new int(4);
		int* recentTile = new int(0); // 
		std::map<int, Node*>* graph = new std::map<int, Node*>();
		std::vector<int>* blockedKeys = new std::vector<int>();

		void createFullBoard();
		void create5By7();
		void create5By5();
		void createGrid(int row, int col);
		void dat::Graph::addVertex(int loc);
		void dat::Graph::addEdge(int src, int dest, EdgeLoc edgeSrc, EdgeLoc edgeDest);
		inline Node* getNode(int nodeId) const { return graph->find(nodeId)->second; }
	public:

		GBMap() = default;
		GBMap(const int _players) : numberOfPlayers(new int(_players)), graph(new std::map<int, Node*>()) {}
		~GBMap();
		void printGraph();
		bool buildBoard();
		void blockKeys(const std::vector<int>& badKeys);

		//Returns most-recent tile. Used for game scoring
		Node* getRecentNode() const { return getNode(*recentTile); }
		int recentTileById() { return *recentTile; };
		deck::Tile* getRecentTile() { return peekTile(*recentTile); }

		void setOwner(int loc, std::string player);
		std::string getOwner(int loc) const;

		void placeTile(int loc, deck::Tile* tile);
		deck::Tile* peekTile(int loc) const;
		deck::Tile* getAdjTile(int loc, EdgeLoc adjDirection);
		
	};

	
	class GBMapDriver {

	public:
		
		
		void run();

	};
	
}


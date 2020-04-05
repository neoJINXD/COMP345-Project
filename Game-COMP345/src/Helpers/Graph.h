#pragma once

enum class EdgeLoc {
	Top,
	Bot,
	Left,
	Right
};
namespace dat {
	class Graph
	{
	public:
			
		//Cleanup memory
		virtual ~Graph() {};

		//Add vertex no edge
		virtual void addVertex(int src) = 0;
		virtual void addEdge(int src, int dest, EdgeLoc edgeSrc, EdgeLoc edgeDest) = 0;


	};
}

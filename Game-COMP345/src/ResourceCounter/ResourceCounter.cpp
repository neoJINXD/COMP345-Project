#include "ResourceCounter.h"
/*

1: Get Recently placed TileId
2: Insert all sub-nodes from Placed tile into SubGraph
3: Link the SubNodes together

	if (adjNode exists at top)
		addEdge(<topleft>, <botleft>)
		addEdge(topRight, botRight)

	if (adjNode exists at bottom)
		addEdge()
	
	if (adjNode exists at left)
	
	if (adjNode existts at right)



*/

std::vector<std::pair<EdgeLoc, counter::ResourceNode*>> counter::ResourceNode::getAdjResources()
{
	return *adjResources;
}

void counter::ResourceNode::setAdjResource(EdgeLoc edgeDir, ResourceNode* adjNode)
{
	adjResources->push_back({edgeDir, adjNode});
}

counter::ResourceNode* counter::ResourceNode::getAdj(EdgeLoc dir)
{
	for (auto p : *adjResources)
	{
		if (p.first == dir)
			return p.second;
	}
	return nullptr;
}

void counter::SubGraph::addVertex(SubTile nodeLoc, Resource resource)
{
	if (graph->find(nodeLoc) == graph->end())
	{
		ResourceNode resNode(nodeLoc, resource);
		graph->insert({nodeLoc, resNode});

		
	}
}

void counter::SubGraph::addEdge(SubTile src, SubTile dest, EdgeLoc edgeSrc, EdgeLoc edgeDest)
{
	ResourceNode srcNode = graph->find(src)->second;
	ResourceNode destNode = graph->find(dest)->second;

	//Undirected Graph
	srcNode.setAdjResource(edgeSrc, &destNode);
	destNode.setAdjResource(edgeDest, &srcNode);
}

counter::ResourceNode counter::SubGraph::getResource(SubTile nodeLoc)
{
	return graph->find(nodeLoc)->second;
}

void counter::SubGraph::printGraph()
{
}

void counter::ResourceCounterDriver::run()
{
	

}

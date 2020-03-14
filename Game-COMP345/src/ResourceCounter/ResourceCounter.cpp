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
std::string RCEdgeToStr(EdgeLoc edge) {
	switch (edge)
	{
	case EdgeLoc::Top:
		return "Top";
	case EdgeLoc::Bot:
		return "Bot";
	case EdgeLoc::Right:
		return "Right";
	case EdgeLoc::Left:
		return "Left";
	default:
		return "NULL";
		break;
	}
}

std::string snToStr(counter::SubNode edge)
{
	switch (edge) {
	case counter::SubNode::TopLeft:
		return "TopLeft";
	case counter::SubNode::TopRight:
		return "TopRight";
	case counter::SubNode::BotRight:
		return "BotRight";
	case counter::SubNode::BotLeft:
		return "BotLeft";
	}
}

std::vector<std::pair<EdgeLoc, counter::ResourceNode>> counter::ResourceNode::getAdjResources()
{
	return *adjResources;
}

void counter::ResourceNode::setAdjResource(EdgeLoc edgeDir, ResourceNode adjNode)
{
	adjResources->push_back({edgeDir, adjNode});
}

counter::ResourceNode* counter::ResourceNode::getAdj(EdgeLoc dir)
{
	for (auto p : *adjResources)
	{
		if (p.first == dir)
			return &p.second;
	}
	return nullptr;
}

void counter::ResourceNode::display()
{
	std::cout << "[TID: " << nodeId->first << ", SN: " << (int)nodeId->second << "]\t";
	std::cout << "Resource: " << *resource << "\tAdj Resources: ";
	for (auto res : *adjResources)
	{
		std::cout << "[Loc:" << RCEdgeToStr(res.first) << " (T_ID:" 
			<< res.second.getNodeId().first << ", S_Loc: " << snToStr(res.second.getNodeId().second) << ")" 
			<< " Rsrc: " << res.second.getResource() << "], ";
	}
	std::cout << std::endl;
}

void counter::ResourceNode::displayLoc()
{
	std::cout << "[TID: " << nodeId->first << " | SN: " << snToStr(nodeId->second) << "]\t"
		<< "Adj Loc: ";
	for (auto res : *adjResources)
	{
		std::cout << "[Loc:" << RCEdgeToStr(res.first) << " (T_ID:"
			<< res.second.getNodeId().first << ", S_Loc: " << snToStr(res.second.getNodeId().second) << ")"
			<< "], ";
	}
	std::cout << std::endl;
}

void counter::SubGraph::dfs(SubTile root, std::map<SubTile, bool>& visited, Resource target, int *count)
{
	//auto visit = visited;
	//std::cout << "Visited?: " << visited[root] << std::endl;
	if (visited[root])
	{
		return;
	}

	visited[root] = true;
	(*count)++;
	

	ResourceNode *currV = &graph->find(root)->second;
	std::cout << "Current Vertex:\t" << currV->getNodeId().first << ", " << (int)currV->getNodeId().second << std::endl;
	std::cout << "Current Count:\t" << *count << std::endl;
	//std::cout << "traversing.. Count:" << *count <<"\n";
	//currV.displayLoc();
	auto vAdjList = currV->getAdjResources();
	//std::cout << currV.getNodeId().first << ", " << snToStr(currV.getNodeId().second);
	for (auto i = vAdjList.begin(); i != vAdjList.end(); i++)
	{
		
		if (visited[i->second.getNodeId()] == false && i->second.getResource() == target)
		{
			std::cout << RCEdgeToStr(i->first) << "\t" << i->second.getNodeId().first << ", " << (int)i->second.getNodeId().second << std::endl;
			//(*count)++;
			dfs(i->second.getNodeId(), visited, target, count);
			//(*count) += 1;
		}
	}
	

}

counter::SubGraph::~SubGraph()
{
	delete graph;
	graph = nullptr;
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
	if (graph->find(src) == graph->end() || graph->find(dest) == graph->end())
	{
		std::cout << "Src/Dest node is invalid!" << std::endl;
		return;
	}

	ResourceNode srcNode = graph->find(src)->second;
	ResourceNode destNode = graph->find(dest)->second;

	//Undirected Graph
	srcNode.setAdjResource(edgeSrc, destNode);
	destNode.setAdjResource(edgeDest, srcNode);
}


counter::ResourceNode counter::SubGraph::getResource(SubTile nodeLoc)
{
	return graph->find(nodeLoc)->second;
}

counter::ResourceNode* counter::SubGraph::getAdj(SubTile nodeLoc, EdgeLoc edgeDir)
{
	if (graph->count(nodeLoc) > 0)
	{
		return graph->find(nodeLoc)->second.getAdj(edgeDir);

	}
	return nullptr;
}

void counter::SubGraph::printGraph()
{
	for (auto v : *graph)
	{
		auto key = v.first;
		//std::cout << "(" << key.first << ", " << (int)key.second << ")\t" << v.second.getResource() << "\n";
		v.second.displayLoc();
	}
}



counter::ResourceCounter::ResourceCounter() : 
	counter(new ResourceScores()), harvestGraph(new SubGraph())
{
	const Resource rsrcTypes[] = { Wheat, Stone, Timber, Sheep };
	for (auto rsrc : rsrcTypes)
	{
		counter->emplace(rsrc, 0);
	}
}
//Return nodeId of the adj tile if it exists
void counter::ResourceCounter::connectAdjTiles(int recentId, int adjId, EdgeLoc dir)
{
	
	//Figure out a better method for connecting outer sub nodes
	switch (dir)
	{
	case EdgeLoc::Top:
		harvestGraph->addEdge({ recentId, SubNode::TopLeft }, { adjId, SubNode::BotLeft }, EdgeLoc::Top, EdgeLoc::Bot);
		harvestGraph->addEdge({ recentId, SubNode::TopRight }, { adjId, SubNode::BotRight }, EdgeLoc::Top, EdgeLoc::Bot);

		break;
	case EdgeLoc::Bot:
		harvestGraph->addEdge({ recentId, SubNode::BotLeft }, { adjId, SubNode::TopLeft }, EdgeLoc::Bot, EdgeLoc::Top);
		harvestGraph->addEdge({ recentId, SubNode::BotRight }, { adjId, SubNode::TopRight }, EdgeLoc::Bot, EdgeLoc::Top);

		break;
	case EdgeLoc::Right:
		harvestGraph->addEdge({ recentId, SubNode::TopRight }, { adjId, SubNode::TopLeft }, EdgeLoc::Right, EdgeLoc::Left);
		harvestGraph->addEdge({ recentId, SubNode::BotRight }, { adjId, SubNode::BotLeft }, EdgeLoc::Right, EdgeLoc::Left);

		break;
	case EdgeLoc::Left:
		harvestGraph->addEdge({ recentId, SubNode::TopLeft }, { adjId, SubNode::TopRight }, EdgeLoc::Left, EdgeLoc::Right);
		harvestGraph->addEdge({ recentId, SubNode::BotLeft }, { adjId, SubNode::BotRight }, EdgeLoc::Left, EdgeLoc::Right);

		break;
	default:
		break;
	}

}

void counter::ResourceCounter::harvestCount(GB::Node recentNode) 
{
	int tileId = recentNode.getId();
	std::vector<Resource> curResources = *recentNode.getTile()->resources;


	const SubNode subLocations[] = {SubNode::TopLeft, SubNode::TopRight, SubNode::BotRight, SubNode::BotLeft };

	for (auto subLoc : subLocations)
	{
		int index = (int)subLoc;
		harvestGraph->addVertex({tileId, subLoc}, curResources[index]);
	}

	//Link subNodes 
	harvestGraph->addEdge({ tileId, SubNode::TopLeft}, { tileId, SubNode::BotLeft}, EdgeLoc::Bot, EdgeLoc::Top);
	harvestGraph->addEdge({ tileId, SubNode::TopRight}, { tileId, SubNode::BotRight}, EdgeLoc::Bot, EdgeLoc::Top);
	harvestGraph->addEdge({ tileId, SubNode::TopLeft }, { tileId, SubNode::TopRight }, EdgeLoc::Right, EdgeLoc::Left);
	harvestGraph->addEdge({ tileId, SubNode::BotLeft }, { tileId, SubNode::BotRight }, EdgeLoc::Right, EdgeLoc::Left);

	//Connect any existing tiles that are adj to the recently placed tile
	//Comment: Might figure a more elegant way, since this is convuluted
	if (harvestGraph->size() > 4)
	{
		for (auto adj : *recentNode.getAdjList()) // Search if adj tile exists, iterates through all 
		{
			auto adjId = adj.second.getId();
			for (auto v : *harvestGraph->getGraph())
			{
				auto tileId = v.first.first; // get tileId

				if (tileId == adjId)
				{
					//Connect subnodes to existing adj node
					connectAdjTiles(recentNode.getId(), adjId, *recentNode.getEdge(adjId));
				}
			}
		}
	}

	std::map<std::pair<int, counter::SubNode>, bool> visited;
	int counter_res[] = {0, 0, 0, 0};

	for (auto key : *harvestGraph->getGraph())
	{
		visited.emplace(key.first, false);
	}

	/*for (auto p : visited)
	{
		std::cout << p.first.first << " " << (int)p.first.second<< "\t" << p.second << std::endl;
	}
	*/
	
	std::map<Resource, bool> harvested = { {Wheat, false}, {Stone, false}, {Timber, false}, {Sheep, false} };
	for (auto subLoc : subLocations)
	{
		int count = 0;
		ResourceNode root = harvestGraph->getResource({ tileId, subLoc });
		if (harvested[root.getResource()]) {
			continue; // if the current resource was already checked, skip it
		}

		harvested[root.getResource()] = true;
		harvestGraph->dfs(root.getNodeId(), visited, root.getResource(), &count);
		//std::cout << count << std::endl;
		//std::cout << score << std::endl;
		//counter->insert(std::make_pair(root.getResource(), count));
		//displayScores();
		//std::cout << counter->at(root.getResource()) << std::endl;
		//counter[root.getResource()] += count;
		std::cout << "Count after DFS:\t" << count << std::endl;
		counter_res[root.getResource()] = count;
		resourceCounter[root.getResource()] = count;
		//std::cout << "Res: " << root.getResource() << "\t"<< counter_res[root.getResource()] << std::endl;
	}
	
	int resIndex = 0;
	for (int i : resourceCounter)
	{
		
		std::cout << "ResourceID: " << resIndex << " Count: " << i << std::endl;
		//counter->insert(std::pair<Resource, int>((Resource)resIndex, i));
		resIndex++;
	}

	
	//displayScores();
}

void counter::ResourceCounter::displayScores()
{
	for (auto k : *counter)
	{
		std::cout << "Res: " << k.first << "\tCount: " << k.second << std::endl;
	}
}

void counter::ResourceCounterDriver::run()
{
	

	ResourceCounter testCnt;
	GB::GBMap* testMap = new GB::GBMap();

	if (testMap->buildABear())
	{
		//testMap->blockKeys({1,2,3,4});
		testMap->placeTile(1, new deck::Tile(Stone, Stone, Stone, Stone));
		testCnt.harvestCount(testMap->getRecentNode());
		//testCnt.display();
		testMap->placeTile(2, new deck::Tile(Stone, Wheat, Wheat, Stone));
		testCnt.harvestCount(testMap->getRecentNode());
		//testCnt.displayScores();
		testMap->placeTile(3, new deck::Tile(Timber, Timber, Timber, Wheat));
		testCnt.harvestCount(testMap->getRecentNode());
		
		//testMap->placeTile(3, new deck::Tile(Stone, Wheat, Wheat, Wheat));
		//testCnt.harvestCount(testMap->getRecentNode());
		//testCnt.displayScores();
	}

	//testCnt.display();

}
//
//void counter::ResourceCounterDriver::run()
//{
//	//SubGraph graph;
//	/*graph.addVertex({1,SubNode::TopRight}, Wheat);
//	graph.addVertex({2,SubNode::TopLeft}, Sheep);
//	graph.addVertex({ 4,SubNode::BotRight }, Sheep);
//	graph.addEdge({1,SubNode::TopRight }, { 2,SubNode::TopLeft }, EdgeLoc::Right, EdgeLoc::Left);
//	graph.addEdge({ 1,SubNode::TopRight }, { 4,SubNode::BotRight }, EdgeLoc::Top, EdgeLoc::Bot);
//	graph.getResource({1, SubNode::TopRight}).display();
//
//	graph.printGraph();*/
//
//	ResourceCounter testCnt;
//	GB::GBMap* testMap = new GB::GBMap();
//
//	if (testMap->buildABear())
//	{
//		//testMap->blockKeys({1,2,3,4});
//		testMap->placeTile(1, new deck::Tile(Wheat, Wheat, Stone, Timber));
//		testCnt.harvestCount(testMap->getRecentNode());
//		//testCnt.display();
//		/*testMap->placeTile(2, new deck::Tile(Stone, Timber, Timber, Wheat));
//		testCnt.harvestCount(testMap->getRecentNode());
//		testMap->placeTile(4, new deck::Tile(Stone, Timber, Timber, Wheat));
//		testCnt.harvestCount(testMap->getRecentNode());
//		testMap->placeTile(3, new deck::Tile(Stone, Timber, Timber, Wheat));
//		testCnt.harvestCount(testMap->getRecentNode());
//		testCnt.displayScores();*/
//	}
//	
//	//testCnt.display();
//
//}
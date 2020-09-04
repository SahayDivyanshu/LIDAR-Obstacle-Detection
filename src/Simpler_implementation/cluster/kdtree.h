/* \author Aaron Brown */
// Quiz on implementing kd tree

#include "../../render/render.h"
#include<math.h>


// Structure to represent node of kd tree
struct Node
{
	std::vector<float> point;
	int id;
	Node* left;
	Node* right;

	Node(std::vector<float> arr, int setId)
	:	point(arr), id(setId), left(NULL), right(NULL)
	{}
};

struct KdTree
{
	Node* root;

	KdTree()
	: root(NULL)
	{}


	void inserthelp(Node** node, uint depth, std::vector<float> point, int id)
	{
		if (*node == NULL)
		{
			*node = new Node(point, id);
		}
		else
		{
			// if(depth %2 == 0)
			// {
			// 	if(point[0] > (*node)->point[0])
			// 	inserthelp(&((*node)-> right),depth+1,point, id);
			// 	else
			// 	inserthelp(&((*node)-> left),depth+1,point, id);
			// } 
			// else
			// {
			// 	if(point[1] > (*node)->point[1])
			// 	inserthelp(&((*node)-> right),depth+1,point, id);
			// 	else
			// 	inserthelp(&((*node)-> left),depth+1,point, id);
			// }
			
			int cd = depth %2;

			if(point[cd] > ((*node)->point[cd]))
				inserthelp(&((*node)-> right),depth+1,point, id);
			else
				inserthelp(&((*node)-> left),depth+1,point, id);

		}
		
	}


	void insert(std::vector<float> point, int id)
	{
		// TODO: Fill in this function to insert a new point into the tree
		// the function should create a new node and place correctly with in the root 


		//Using a insert helper function to insert values to the tree, starting at the root	
		inserthelp(&root, 0, point,id);

	}

	// return a list of point ids in the tree that are within distance of target
	std::vector<int> search(std::vector<float> target, float distanceTol)
	{
		std::vector<int> ids;
		searchhelp(root,0,distanceTol,target,ids);
		
		return ids;
	}
	
	// not equired o have a double pointer here
	void searchhelp(Node* node, int depth, float distanceTol, std::vector<float> target,std::vector<int>& ids)
	{
		if (node!=NULL)	
		{
			int cd = depth %2;
			float dist;
			if (((target[0]+distanceTol) >= (node->point[0])) && ((node->point[0]) >= (target[0]-distanceTol))  &&  (((target[1]+distanceTol) >= (node->point[1])) && ((node->point[1]) >= (target[1]-distanceTol))))
			{	
				float dist = sqrt((target[0]-(node->point[0]))*(target[0]-(node->point[0])) + (target[1]-(node->point[1]))*(target[1]-(node->point[1])));
				if(dist <= distanceTol)
				{
					ids.push_back(node -> id);
				}
			}
			if (node->point[cd] > target[cd]-distanceTol)
				searchhelp((node->left),depth+1,distanceTol,target,ids);
			if  (node->point[cd] < target[cd]+distanceTol)
				searchhelp((node->right),depth+1,distanceTol,target,ids);
		}

		for(int index : ids)
     		std::cout << index << ",";
		cout<<endl;
	}

	


};





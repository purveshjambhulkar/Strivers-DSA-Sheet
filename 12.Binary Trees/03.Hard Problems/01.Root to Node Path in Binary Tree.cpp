// problem link - https://www.naukri.com/code360/problems/path-in-a-tree_3843990?leftPanelTabValue=PROBLEM


#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/



bool pathUtil(TreeNode<int> * root , int target ,vector<int> &path){
	if(root == NULL){
		return false;
	}

	path.push_back(root->data);
	if(root->data == target)
	{return true;}

	if(pathUtil(root->left , target , path) 
	|| pathUtil(root->right , target, path)){
		return true;
	}

	path.pop_back();
	return false;
	
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	if(!root){
		return {};
	}
	vector<int> path;

	pathUtil(root , x , path);

	return path;

	





















}

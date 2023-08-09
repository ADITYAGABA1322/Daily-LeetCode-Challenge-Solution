95. Unique Binary Search Trees II



5 August 2023



Medium


C++:

// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(n)

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){ // if n is equal to 0
            return {}; // return empty vector
        }
        return generateTrees(1, n); // call the generateTrees function
    }
    vector<TreeNode*> generateTrees(int start, int end){
        vector<TreeNode*> trees; // vector to store the result
        if(start > end){ // if start is greater than end
            trees.push_back(NULL); // push the null in the vector trees
            return trees; // return the vector trees
        }
        for(int i=start; i<=end; i++){ // loop for i
            vector<TreeNode*> leftTrees = generateTrees(start, i-1); // vector to store the leftTrees
            vector<TreeNode*> rightTrees = generateTrees(i+1, end); // vector to store the rightTrees
            for(auto leftTree: leftTrees){ // loop for leftTreeT
                for(auto rightTree: rightTrees){ // loop for rightTree
                    TreeNode* root = new TreeNode(i); // create the root
                    root->left = leftTree; // update the left
                    root->right = rightTree; // update the right
                    trees.push_back(root); // push the root in the vector trees
                }
            }
        }
        return trees; // return the vector trees
    }
};


Java:
// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(n)

class Solution {
    public List<TreeNode> generateTrees(int n) {
        if(n==0){ // if n is equal to 0
            return new ArrayList<TreeNode>(); // return empty vector
        }
        return generateTrees(1, n); // call the generateTrees function
    }
    public List<TreeNode> generateTrees(int start, int end){
        List<TreeNode> trees = new ArrayList<>(); // vector to store the result
        if(start > end){ // if start is greater than end
            trees.add(null); // push the null in the vector trees
            return trees; // return the vector trees
        }
        for(int i=start; i<=end; i++){ // loop for i
            List<TreeNode> leftTrees = generateTrees(start, i-1); // vector to store the leftTrees
            List<TreeNode> rightTrees = generateTrees(i+1, end); // vector to store the rightTrees
            for(TreeNode leftTree: leftTrees){ // loop for leftTreeT
                for(TreeNode rightTree: rightTrees){ // loop for rightTree
                    TreeNode root = new TreeNode(i); // create the root
                    root.left = leftTree; // update the left
                    root.right = rightTree; // update the right
                    trees.add(root); // push the root in the vector trees
                }
            }
        }
        return trees; // return the vector trees
    }
}


Python:

// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(n)

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """ 
        if n == 0:  # if n is equal to 0
            return []  # return empty vector
        return self.generateTreesHelper(1, n)  # call the generateTrees function
    def generateTreesHelper(self, start, end):
        trees = []  # vector to store the result
        if start > end:  # if start is greater than end
            trees.append(None)  # push the null in the vector trees
            return trees  # return the vector trees
        for i in range(start, end + 1):  # loop for i
            leftTrees = self.generateTreesHelper(start, i - 1)  # vector to store the leftTrees
            rightTrees = self.generateTreesHelper(i + 1, end)  # vector to store the rightTrees
            for leftTree in leftTrees:  # loop for leftTreeT
                for rightTree in rightTrees:  # loop for rightTree
                    root = TreeNode(i)  # create the root
                    root.left = leftTree  # update the left
                    root.right = rightTree  # update the right
                    trees.append(root)  # push the root in the vector trees
        return trees  # return the vector trees



Python3:


// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(n)

class Solution:
    def generateTrees(self, n: int -> List[TreeNode]:  // add the missing bracket after int
        if n == 0:  # if n is equal to 0
            return []  # return empty vector
        return self.generateTreesHelper(1, n)  # call the generateTrees function
    def generateTreesHelper(self, start, end):
        trees = []  # vector to store the result
        if start > end:  # if start is greater than end
            trees.append(None)  # push the null in the vector trees
            return trees  # return the vector trees
        for i in range(start, end + 1):  # loop for i
            leftTrees = self.generateTreesHelper(start, i - 1)  # vector to store the leftTrees
            rightTrees = self.generateTreesHelper(i + 1, end)  # vector to store the rightTrees
            for leftTree in leftTrees:  # loop for leftTreeT
                for rightTree in rightTrees:  # loop for rightTree
                    root = TreeNode(i)  # create the root
                    root.left = leftTree  # update the left
                    root.right = rightTree  # update the right
                    trees.append(root)  # push the root in the vector trees
        return trees  # return the vector trees




C:

// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(n)

struct TreeNode** generateTrees(int n, int* returnSize){
    if(n==0){  // if n is equal to 0
        *returnSize = 0;  // return empty vector
        return NULL;  // return empty vector
    }
    return generateTreesHelper(1, n, returnSize);  // call the generateTrees function
}

struct TreeNode** generateTreesHelper(int start, int end, int* returnSize){
    struct TreeNode** trees = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*10000);  // vector to store the result
    if(start > end){  // if start is greater than end
        trees[0] = NULL;  // push the null in the vector trees
        *returnSize = 1;  // return the vector trees
        return trees;  // return the vector t
    }
    int index = 0;  // variable to store the index
    for(int i=start; i<=end; i++){  // loop for i
        int leftSize = 0;  // variable to store the size of the leftTrees
        struct TreeNode** leftTrees = generateTreesHelper(start, i-1, &leftSize);  // vector to store the leftTrees
        int rightSize = 0;  // variable to store the size of the rightTrees
        struct TreeNode** rightTrees = generateTreesHelper(i+1, end, &rightSize);  // vector to store the rightTrees
        for(int j=0; j<leftSize; j++){  // loop for leftTreeT
            for(int k=0; k<rightSize; k++){  // loop for rightTree
                struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));  // create the root
                root->val = i;  // update the root
                root->left = leftTrees[j];  // update the left
                root->right = rightTrees[k];  // update the right
                trees[index++] = root;  // push the root in the vector trees
            }
        }
    }
    *returnSize = index;  // return the vector trees
    return trees;  // return the vector trees
}



C#

// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(n)

public class Solution {
    public IList<TreeNode> GenerateTrees(int n) {
        if(n==0){  // if n is equal to 0
            return new List<TreeNode>();  // return empty vector
        }
        return GenerateTreesHelper(1, n);  // call the generateTrees function
    }
    public IList<TreeNode> GenerateTreesHelper(int start, int end){
        IList<TreeNode> trees = new List<TreeNode>();  // vector to store the result
        if(start > end){  // if start is greater than end
            trees.Add(null);  // push the null in the vector trees
            return trees;  // return the vector trees
        }
        for(int i=start; i<=end; i++){  // loop for i
            IList<TreeNode> leftTrees = GenerateTreesHelper(start, i-1);  // vector to store the leftTrees
            IList<TreeNode> rightTrees = GenerateTreesHelper(i+1, end);  // vector to store the rightTrees
            foreach(TreeNode leftTree in leftTrees){  // loop for leftTreeT
                foreach(TreeNode rightTree in rightTrees){  // loop for rightTree
                    TreeNode root = new TreeNode(i);  // create the root
                    root.left = leftTree;  // update the left
                    root.right = rightTree;  // update the right
                    trees.Add(root);  // push the root in the vector trees
                }
            }
        }
        return trees;  // return the vector trees
    }
}



JavaScript:

// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(n)

var generateTrees = function(n) {
    if(n==0){  // if n is equal to 0
        return [];  // return empty vector
    }
    return generateTreesHelper(1, n);  // call the generateTrees function
};

var generateTreesHelper = function(start, end){
    let trees = [];  // vector to store the result
    if(start > end){  // if start is greater than end
        trees.push(null);  // push the null in the vector tree
        return trees;  // return the vector trees
    }
    for(let i=start; i<=end; i++){  // loop for i
        let leftTrees = generateTreesHelper(start, i-1);  // vector to store the leftTrees
        let rightTrees = generateTreesHelper(i+1, end);  // vector to store the rightTrees
        for(let leftTree of leftTrees){  // loop for leftTreeT
            for(let rightTree of rightTrees){  // loop for rightTree
                let root = new TreeNode(i);  // create the root
                root.left = leftTree;  // update the left
                root.right = rightTree;  // update the right
                trees.push(root);  // push the root in the vector trees
            }
        }
    }
    return trees;  // return the vector trees
};




Swift:

// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(n)

class Solution {
    func generateTrees(_ n: Int) -> [TreeNode?] {
        if n==0{  // if n is equal to 0
            return [];  // return empty vector
        }
        return generateTreesHelper(1, n);  // call the generateTrees function
    }
    func generateTreesHelper(_ start: Int, _ end: Int) -> [TreeNode?]{
        var trees = [TreeNode?]();  // vector to store the result
        if start > end{  // if start is greater than end
            trees.append(nil);  // push the null in the vector trees
            return trees;  // return the vector trees
        }
        for i in start...end{  // loop for i
            let leftTrees = generateTreesHelper(start, i-1);  // vector to store the leftTrees
            let rightTrees = generateTreesHelper(i+1, end);  // vector to store theightTrees
            for leftTree in leftTrees{  // loop for leftTreeT
                for rightTree in rightTrees{  // loop for rightTree
                    let root = TreeNode(i);  // create the root
                    root.left = leftTree;  // update the left
                    root.right = rightTree;  // update the right
                    trees.append(root);  // push the root in the vector trees
                }
            }
        }
        return trees;  // return the vector trees
    }
}




Dart:



// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(n)

class Solution {
  List<TreeNode?> generateTrees(int n) {
    if (n == 0) {
      // if n is equal to 0
      return []; // return empty vector
    }
    return generateTreesHelper(1, n); // call the generateTrees function

  }

    List<TreeNode?> generateTreesHelper(int start, int end) {
        List<TreeNode?> trees = []; // vector to store the result
        if (start > end) {
        // if start is greater than end
        trees.add(null); // push the null in the vector trees
        return trees; // return the vector trees
        }
        for (int i = start; i <= end; i++) {
        // loop for i
        List<TreeNode?> leftTrees = generateTreesHelper(start, i - 1); // vector to store the leftTrees
        List<TreeNode?> rightTrees = generateTreesHelper(i + 1, end); // vector to store the rightTrees
        for (TreeNode? leftTree in leftTrees) {
            // loop for leftTreeT
            for (TreeNode? rightTree in rightTrees) {
            // loop for rightTree
            TreeNode root = TreeNode(i); // create the root
            root.left = leftTree; // update the left
            root.right = rightTree; // update the right
            trees.add(root); // push the root in the vector trees
            }
        }
        }
        return trees; // return the vector trees
    }
}

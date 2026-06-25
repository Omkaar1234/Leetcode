/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        unordered_map<int,Node*>m;
        unordered_map<int,Node*>oldM;

        oldM[node->val] = node;

        Node* newNode = new Node(node->val);
        m[node->val] = newNode;

        queue<Node*>q;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(Node * v : curr->neighbors){
                if(!m.count(v->val)){
                    oldM[v->val] = v;
                    Node * newN = new Node(v->val);
                    m[v->val] = newN;
                    q.push(v);
                }
            }
        }

        for(auto &curr : oldM){
            for(Node * v : curr.second->neighbors){
                m[curr.first]->neighbors.push_back(m[v->val]);
                // m[v->val]->neighbors.push_back(m[curr.first]);
            }
        }

        return newNode;
    }
};
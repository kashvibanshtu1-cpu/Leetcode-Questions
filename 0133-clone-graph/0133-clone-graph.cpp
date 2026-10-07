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
        if (node == NULL)
            return NULL;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        Node* clone1 = new Node(node->val);
        mp[node] = clone1;
        q.push(node);
        while (!q.empty()) {
            Node* orignal = q.front();
            q.pop();
            for (Node* i : orignal->neighbors) {
                if (mp.find(i) == mp.end()) {
                    Node* clone = new Node(i->val);
                    mp[i] = clone;
                    q.push(i);
                }
                mp[orignal]->neighbors.push_back(mp[i]);
            }
        }
        return mp[node];
    }
};
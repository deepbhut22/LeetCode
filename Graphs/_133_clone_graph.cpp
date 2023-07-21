class Solution {
public:
    unordered_map<Node*,Node*> mp;

    //DFS
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if(mp.find(node) == mp.end()) {
            mp[node] = new Node(node->val);
            for(int i=0 ; i<node->neighbors.size() ; i++) {
                Node* nei = node->neighbors[i];
                mp[node]->neighbors.push_back(cloneGraph(nei));
            }
        }
        return mp[node];
    }
};
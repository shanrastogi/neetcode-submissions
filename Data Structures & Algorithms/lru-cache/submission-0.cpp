class LRUCache {
public:
    class Node{
    public:    
        int key;
         int value;
        Node* prev;
        Node* next;
        Node(int _key, int _value){
            key = _key;
            value = _value;
        }
    };
    Node* tail = new Node(-1,-1);
    Node* head = new Node(-1,-1);
    unordered_map<int, Node*> mp;
    int capacity;
    LRUCache(int _capacity) {
        capacity = _capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addAfterHead(Node* node){
        Node* currHeadNext = head->next;
        head->next = node;
        currHeadNext -> prev = node;
        node-> next = currHeadNext;
        node->prev = head;
    }

    void removeFromEnd(Node* node){
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        delPrev-> next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        Node* node; 
        if(mp.find(key) != mp.end()){
            node = mp[key];
            removeFromEnd(node);
            addAfterHead(node);
            return node->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int val) {
        Node* newNode = new Node(key, val);
        if(mp.find(key) != mp.end()){
            Node*  node = mp[key];
            node->value = val;
            removeFromEnd(node);
            addAfterHead(node);
        } else{
            if(mp.size() == capacity){
                mp.erase(tail->prev->key);
                removeFromEnd(tail->prev);               
            }
            mp[key] = newNode;
            addAfterHead(newNode);        
        }
    }
};

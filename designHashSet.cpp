class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> hashset;
    MyHashSet() {
        vector<int> temp(1000000,0);
        hashset = temp;
    }
    
    void add(int key) {
        hashset[key] = 1;
        
    }
    
    void remove(int key) {
        hashset[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hashset[key];
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
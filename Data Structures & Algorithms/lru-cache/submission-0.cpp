class LRUCache {

    using list = std::list<std::pair<int,int>>;
    std::unordered_map<int, list::iterator> quick_lookup{};
    list ll; 
    int m_capacity;
public:
    LRUCache(int capacity): m_capacity(capacity)  {
        
    }
    
    int get(int key) {
        if(quick_lookup.contains(key)){
            //move the item to the front
            ll.splice(ll.begin(), ll, quick_lookup[key]);

            return quick_lookup[key]->second;
        }else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        //if key already exists just update and move, otherwise check for capacity

        if(quick_lookup.contains(key)){
            quick_lookup[key]->second = value;
            ll.splice(ll.begin(), ll, quick_lookup[key]);



        }else if(ll.size()  == m_capacity){
            //pop the last element and then add it to the front

            quick_lookup.erase(ll.back().first);
            ll.pop_back();

            ll.push_front({key,value});

            quick_lookup[key] = ll.begin(); 

        }else {
            
            ll.push_front({key,value});

            quick_lookup[key] = ll.begin(); 
        }
    }   
};

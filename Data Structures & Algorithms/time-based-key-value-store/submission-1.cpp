class TimeMap {
public:

    struct Node { 
        string value;
        int timestamp;
    };
    std::unordered_map<string, std::vector<Node>> main_map{};
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto& l = main_map[key];
        // get the last item to see if we need to replace
        l.emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {

        auto& l = main_map[key];
        Node* ptr = nullptr;
        for(auto& node : l) {
            if (node.timestamp > timestamp) { 
                break;
            }
            ptr = &node;

        }

        return ptr == nullptr? "" : ptr->value;
        
    }
};

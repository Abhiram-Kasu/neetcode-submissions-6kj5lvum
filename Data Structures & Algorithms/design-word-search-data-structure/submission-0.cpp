class WordDictionary {
    private: 
    struct TrieNode{ 
        std::array<TrieNode*, 26> children;
        bool is_word = false;
    };
public:
    WordDictionary() {
    }

    auto dfs(const string& word, const size_t idx, const TrieNode* curr_node) { 
        if(idx == word.size()) return curr_node->is_word;

        const auto letter = word[idx];
        if (letter == '.'){ 
            for (auto* child : curr_node->children){
                if(child and dfs(word, idx+1, child)){ 
                    return true;
                }
            }
            return false;
        }else { 
            const auto* child = curr_node->children[letter - 'a'];
            return child and dfs(word, idx+1, child);
        }
    }

    TrieNode root{};
    
    void addWord(string word) {
        auto* curr = &root;
        for(auto c: word) { 
            if(not curr->children[c-'a']){
                curr->children[c-'a'] = new TrieNode{};
            }
            curr = curr->children[c-'a'];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, &root);
    }
};

struct Node {
    std::array<std::unique_ptr<Node>, 26> children{};
    bool is_end = false;
};

class PrefixTree {
    Node base;

public:
    void insert(std::string word) {
        Node* curr = &base;

        for (char letter : word) {
            auto& child = curr->children[letter - 'a'];

            if (!child) {
                child = std::make_unique<Node>();
            }

            curr = child.get();
        }

        curr->is_end = true;
    }

    bool search(std::string word) {
        Node* curr = &base;

        for (char c : word) {
            auto& child = curr->children[c - 'a'];

            if (!child) {
                return false;
            }

            curr = child.get();
        }

        return curr->is_end;
    }

    bool startsWith(std::string prefix) {
        Node* curr = &base;

        for (char c : prefix) {
            auto& child = curr->children[c - 'a'];

            if (!child) {
                return false;
            }

            curr = child.get();
        }

        return true;
    }
};


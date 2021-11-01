const int AL = 26;
struct TrieNode
{
    vector<TrieNode *> children;
    bool isEnd;
    TrieNode()
    {
        children.assign(AL, NULL);
        isEnd = false;
    }
};

class Trie
{
  public:
    Trie()
    {
        this->root = new TrieNode;
    }
    void insert(string key)
    {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode;
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEnd = true;
    }
    bool search(string key)
    {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return pCrawl->isEnd;
    }

  private:
    TrieNode *root;
};
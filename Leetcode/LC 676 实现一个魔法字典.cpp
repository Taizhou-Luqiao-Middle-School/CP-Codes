class MagicDictionary {
public:
    unordered_set<string> S;
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for(auto& d: dictionary)
            S.emplace(d);
    }
    
    bool search(string searchWord) {
        int len=searchWord.size();
        string t=searchWord;
        for(int i=0;i<len;i++){
            for(char c='a';c<='z';c++){
                if(searchWord[i]!=c){
                    t[i] = c;
                    if(S.count(t))
                        return true;
                }
            }
            t[i] = searchWord[i];
        }
        return false;
    }
};
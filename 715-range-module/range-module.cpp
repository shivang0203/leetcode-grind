class RangeModule {
public:
    map<int, int> ranges;
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        while(it != ranges.end() && it->first <= right){
            right = max(it->second, right);
            ++it;
            ranges.erase(prev(it));
        }
        if(it != ranges.begin() && left <= (--it)->second){
            it->second = max(it->second, right);
        }
        else{
            ranges[left] = right;
        }
    }
    
    bool queryRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        if(it == ranges.begin()) return false;
        return prev(it)->second >= right;
    }
    
    void removeRange(int left, int right) {
        auto it = ranges.lower_bound(left);
        int cutEnd = -1;
        while(it != ranges.end() && it->first < right){
            cutEnd = max(cutEnd, it->second);
            it++;
            ranges.erase(prev(it));
        }
        if(it != ranges.begin() && left < (--it)->second){
            cutEnd = max(cutEnd, it->second);
            it->second = left;
        }
        if(right<cutEnd){
            ranges[right] = cutEnd;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
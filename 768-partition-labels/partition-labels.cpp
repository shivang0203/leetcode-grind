class Solution {
public:
    unordered_map<char, set<int>> getPos( string_view s) {
        unordered_map<char, set<int>> res;
        for(int i = 0; i < s.size(); ++i) {
            res[s[i]].insert(i);
        }
        return res;
    }

    void rec(string_view s, int curr_ind, vector<int>& res, unordered_map<char, set<int>>& pos) {
        // cout << "curr_ind: " << curr_ind << endl;
        if(curr_ind >= s.size() ) { return; }
        auto have_to_cover_ind = *(prev(pos[s[curr_ind]].end()));
        if( have_to_cover_ind == curr_ind) {
            res.push_back(1);
            rec(s, curr_ind + 1, res, pos);
        } else {
            int start_ind = curr_ind;
            int end_ind = have_to_cover_ind;
            
            auto get_next_end_ind = [&pos](string_view sv, int s_ind, int e_ind) {
                auto longest_ind = e_ind;
                for(int i = s_ind; i <= e_ind; ++i ) {
                    longest_ind = max(longest_ind, *(prev(pos[sv[i]].end())));
                }
                return longest_ind;
            };

            while(true) {
                int end_ind_next = get_next_end_ind(s, start_ind, end_ind);
                if( end_ind_next == end_ind) {
                    break;
                } else {
                    start_ind = end_ind + 1;
                    end_ind = end_ind_next;
                }
            }
            res.push_back(end_ind - curr_ind + 1);
            rec(s, end_ind + 1, res, pos);
        }
    }
    vector<int> partitionLabels(string s) {
        auto positions = getPos(s);
        vector<int> res;
        rec(string_view{s}, 0, res, positions);
        return res;
    }
};
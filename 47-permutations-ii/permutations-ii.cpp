class Solution {
public:
 void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j) {
            res.push_back(num);
            return;
        }
        unordered_set<int>st;
        for (int k = i; k < j; k++) {
            if(st.count(num[k])) continue;
            st.insert(num[k]);
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
            swap(num[i], num[k]);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};
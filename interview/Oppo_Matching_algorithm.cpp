pair<int,int> Match(vector<int> img, int width, int height, int x, int y)
{
    
    vector<vector<int>> des_comp = generate_descriptor (x,y, width, height);
    
    for (int i = 0 ; i < height ; ++i) {
        for (int j = 0 ; j < width ; ++j) {
            if (i == y && j == x) continue;
            vector<vector<int>> des = generate_descriptor (i,j, width, height);
            
            if ( comp(des, des_comp) < eps) return {i,j};
        }
    }
}

vector<vector<int>> generate_descriptor (vector<int>& img, int x, int y, int width, int height) {
    vector<vector<int>> ans(5,vector<int>(5,0));
    for (int i = -2 ; i <= 2; ++i) {
        for (int j = -2 ; j <= 2 ; ++j) {
            if (x - 2 < 0 || y - 2 < 0 || x + 2 >= height || y + 2 >= weight) continue;
            ans[i + 2][j + 2] = img[width*i + j];
        }
    }
    return ans;
}


int comp (vector<vector<int>>& des, vector<vector<int>>& des_comp) {
    int dis = 0.0;
    for (int i = 0 ; i < 5 ; ++i) {
        for (int j = 0 ; j < 5 ; ++j) {
            dis += (des[i][j] - des_comp[i][j]);
        }
    }
    return dis;
}
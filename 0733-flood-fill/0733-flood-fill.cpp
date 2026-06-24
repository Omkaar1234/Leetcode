class Solution {
public:
    void helper(vector<vector<int>>&image, int sr, int sc, int color, int orgColor){
        if(image[sr][sc] == color) return;

        image[sr][sc] = color;

        if(sr+1 < image.size() && image[sr+1][sc] == orgColor){
            helper(image,sr+1,sc,color,orgColor);
        }

        if(sr-1 >= 0 && image[sr-1][sc] == orgColor){
            helper(image,sr-1,sc,color,orgColor);
        }

        if(sc-1 >= 0 && image[sr][sc-1] == orgColor){
            helper(image,sr,sc-1,color,orgColor);
        }

        if(sc+1 < image[0].size() && image[sr][sc+1] == orgColor){
            helper(image,sr,sc+1,color,orgColor);
        }

        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        helper(image,sr,sc,color,image[sr][sc]);

        return image;
    }
};
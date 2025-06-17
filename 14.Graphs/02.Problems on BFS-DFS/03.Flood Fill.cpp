class Solution {
public:
    void fillColor(vector<vector<int>>& image, int sr, int sc, int color,
                   int newColor) {
        // base case
     if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != color) {
            return;
        }

        //update the color
        image[sr][sc] = newColor;

        //recursively call for adjacent elements
        fillColor(image , sr+1 ,sc ,color , newColor);
        fillColor(image , sr ,sc+1 ,color , newColor);
        fillColor(image , sr ,sc-1 ,color , newColor);
        fillColor(image , sr-1 ,sc ,color , newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        if(image[sr][sc] == color){
            return image;
        }

        fillColor(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
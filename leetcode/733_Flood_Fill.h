#include "../base/icode.h"
class L733 : public icode {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty() || sr >= (int)image.size() || sr < 0 || sc >= (int)image[0].size() || sc < 0 || image[sr][sc] == newColor)
            return image;
        int cur = image[sr][sc];
        image[sr][sc] = newColor;
        if (sr < (int)image.size() - 1 && image[sr+1][sc] == cur)
            floodFill(image, sr+1, sc, newColor);
        if (sr > 0 && image[sr-1][sc] == cur)
            floodFill(image, sr-1, sc, newColor);
        if (sc < (int)image[0].size() - 1 && image[sr][sc+1] == cur)
            floodFill(image, sr, sc+1, newColor);
        if (sc > 0 && image[sr][sc-1] == cur)
            floodFill(image, sr, sc-1, newColor);
        return image;
    }

    void run() {
        vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
        print_res(floodFill(image, 1, 1, 2));
    }
};
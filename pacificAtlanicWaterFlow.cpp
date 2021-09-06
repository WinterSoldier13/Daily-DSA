#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli unsigned long long int

// class Solution
// {
// public:
//     bool reachedPacific;
//     bool reachedAtlantic;

//     set<pair<int, int>> hashset;

//     void recurse(vector<vector<int>> &arr, int i, int j, int prev)
//     {

//         if (i < 0 or j < 0 or i >= arr.size() or j >= arr[0].size() or arr[i][j] == INT16_MAX or arr[i][j] > prev)
//         {

//             if (i < 0 or j < 0)
//             {
//                 reachedPacific = true;
//                 return;
//             }
//             else if (i >= arr.size() or j >= arr[0].size())
//             {
//                 reachedAtlantic = true;
//                 return;
//             }
//             if (arr[i][j] > prev)
//             {
//                 return;
//             }
//             return;
//         }
//         if (hashset.find({i, j}) != hashset.end())
//         {
//             reachedAtlantic = 1;
//             reachedPacific = 1;
//             return;
//         }
//         int temp = arr[i][j];
//         arr[i][j] = INT16_MAX;
//         recurse(arr, i - 1, j, temp);
//         recurse(arr, i + 1, j, temp);
//         recurse(arr, i, j - 1, temp);
//         recurse(arr, i, j + 1, temp);
//         arr[i][j] = temp;
//     }
//     vector<vector<int>> pacificAtlantic(vector<vector<int>> &arr)
//     {
//         vector<vector<int>> out;
//         hashset.clear();
//         if (arr.size() == 0 or arr[0].size() == 0)
//         {
//             return out;
//         }
//         int rows = arr.size();
//         int cols = arr[0].size();
//         reachedAtlantic = false;
//         reachedPacific = false;

//         for (int i = 0; i < rows; i++)
//         {
//             for (int j = 0; j < cols; j++)
//             {
//                 reachedAtlantic = 0;
//                 reachedPacific = 0;
//                 recurse(arr, i, j, INT16_MAX);
//                 if (reachedPacific and reachedAtlantic)
//                 {
//                     out.push_back(vector<int>{i, j});
//                     hashset.insert({i, j});
//                 }
//             }
//         }

//         // // Taking care of edges
//         // for (int i = 0; i < cols; i++)
//         // {
//         //     reachedAtlantic = 0;
//         //     recurseForAtlantic(arr, 0, i);
//         //     if (reachedAtlantic)
//         //     {
//         //         out.push_back(vector<int>{0, i});
//         //     }
//         // }
//         // for (int i = 1; i < rows - 1; i++)
//         // {
//         //     reachedAtlantic = 0;
//         //     recurseForAtlantic(arr, i, 0);
//         //     if (reachedAtlantic)
//         //     {
//         //         out.push_back(vector<int>{i, 0});
//         //     }
//         // }
//         // cout << "Reached Here" << endl;

//         // // Taking care of edges
//         // for (int i = 0; i < cols; i++)
//         // {
//         //     reachedPacific = 0;
//         //     recurseForPacific(arr, arr.size() - 1, i);
//         //     if (reachedPacific)
//         //     {
//         //         out.push_back(vector<int>{rows - 1, i});
//         //     }
//         // }
//         // for (int i = 1; i < rows - 1; i++)
//         // {
//         //     reachedPacific = 0;
//         //     recurseForPacific(arr, i, cols - 1);
//         //     if (reachedPacific)
//         //     {
//         //         out.push_back(vector<int>{i, cols - 1});
//         //     }
//         // }
//         // sort(out.begin(), out.end());
//         // out.erase(unique(out.begin(), out.end()), out.end());
//         // sort(out.begin(), out.end());
//         // out.erase(unique(out.begin(), out.end()), out.end());

//         return out;
//     }
// };

class Solution
{
private:
    void dfs(const vector<vector<int>> &matrix, const vector<pair<int, int>> &coords, vector<vector<bool>> &visited, int i, int j)
    {
        visited[i][j] = true;

        for (auto &coord : coords)
        {
            int next_i = coord.first + i;
            int next_j = coord.second + j;

            // since we're going backwards (from "ocean" instead of to) we want the next node's value to be equal to or more than the current node's value
            if (is_in_bounds(matrix, next_i, next_j) && !visited[next_i][next_j] && matrix[next_i][next_j] >= matrix[i][j])
            {
                dfs(matrix, coords, visited, next_i, next_j);
            }
        }
    }

    bool is_in_bounds(const vector<vector<int>> &matrix, int i, int j)
    {
        return i >= 0 && j >= 0 && i < matrix.size() && j < matrix[0].size();
    }

public:
    vector<vector<int>> pacificAtlantic(const vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return vector<vector<int>>();

        const vector<pair<int, int>> coords = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> visited_atlantic(n, vector<bool>(m, false));
        vector<vector<bool>> visited_pacific(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            // left edge for pacific ocean
            dfs(matrix, coords, visited_pacific, i, 0);
            // right edge for atlantic ocean
            dfs(matrix, coords, visited_atlantic, i, m - 1);
        }
        for (int j = 0; j < m; j++)
        {
            // top edge for pacific ocean
            dfs(matrix, coords, visited_pacific, 0, j);
            // bottom edge for atlantic ocean
            dfs(matrix, coords, visited_atlantic, n - 1, j);
        }

        vector<vector<int>> result;
        // find the nodes that can reach both oceans
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (visited_pacific[i][j] && visited_atlantic[i][j])
                    result.push_back({i, j});

        return result;
    }
};

int main()
{
    // vector<vector<int>> arr{{1, 2, 2, 3, 5},
    //                         {3, 2, 3, 4, 4},
    //                         {2, 4, 5, 3, 1},
    //                         {6, 7, 1, 4, 5},
    //                         {5, 1, 1, 2, 4}};

    // vector<vector<int>> arr{{1, 2, 3, 4},
    //                         {12, 13, 14, 5},
    //                         {11, 16, 15, 6},
    //                         {10, 9, 8, 7}};

    // vector<vector<int>> arr{{1,2,3,4,5,6,7,8,9,10,11,12,13},{48,49,50,51,52,53,54,55,56,57,58,59,14},{47,88,89,90,91,92,93,94,95,96,97,60,15},{46,87,120,121,122,123,124,125,126,127,98,61,16},{45,86,119,144,145,146,147,148,149,128,99,62,17},{44,85,118,143,160,161,162,163,150,129,100,63,18},{43,84,117,142,159,168,169,164,151,130,101,64,19},{42,83,116,141,158,167,166,165,152,131,102,65,20},{41,82,115,140,157,156,155,154,153,132,103,66,21},{40,81,114,139,138,137,136,135,134,133,104,67,22},{39,80,113,112,111,110,109,108,107,106,105,68,23},{38,79,78,77,76,75,74,73,72,71,70,69,24},{37,36,35,34,33,32,31,30,29,28,27,26,25}};
    vector<vector<int>> arr{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17}, {64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 18}, {63, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 80, 19}, {62, 119, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 134, 81, 20}, {61, 118, 167, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 180, 135, 82, 21}, {60, 117, 166, 207, 240, 241, 242, 243, 244, 245, 246, 247, 218, 181, 136, 83, 22}, {59, 116, 165, 206, 239, 264, 265, 266, 267, 268, 269, 248, 219, 182, 137, 84, 23}, {58, 115, 164, 205, 238, 263, 280, 281, 282, 283, 270, 249, 220, 183, 138, 85, 24}, {57, 114, 163, 204, 237, 262, 279, 288, 289, 284, 271, 250, 221, 184, 139, 86, 25}, {56, 113, 162, 203, 236, 261, 278, 287, 286, 285, 272, 251, 222, 185, 140, 87, 26}, {55, 112, 161, 202, 235, 260, 277, 276, 275, 274, 273, 252, 223, 186, 141, 88, 27}, {54, 111, 160, 201, 234, 259, 258, 257, 256, 255, 254, 253, 224, 187, 142, 89, 28}, {53, 110, 159, 200, 233, 232, 231, 230, 229, 228, 227, 226, 225, 188, 143, 90, 29}, {52, 109, 158, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 144, 91, 30}, {51, 108, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 92, 31}, {50, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 32}, {49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33}};

    Solution ob;
    auto out = ob.pacificAtlantic(arr);
    for (auto x : out)
    {
        for (auto c : x)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    // getchar();
    return 1;
}

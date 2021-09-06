
// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
void recurse(int arr[MAX][MAX], int n, int i, int j, vector<char> &path, vector<vector<char>> &mothership)
{
    if (i < 0 or i >= n or j < 0 or j >= n or arr[i][j] == 0)
    {

        return;
    }
    if (i == n - 1 and j == n - 1)
    {
        mothership.push_back(path);
        return;
    }
    arr[i][j] = 0;

    path.push_back('U');
    recurse(arr, n, i - 1, j, path, mothership);
    path.pop_back();
    path.push_back('R');
    recurse(arr, n, i, j + 1, path, mothership);
    path.pop_back();
    path.push_back('D');
    recurse(arr, n, i + 1, j, path, mothership);
    path.pop_back();
    path.push_back('L');
    recurse(arr, n, i, j - 1, path, mothership);
    path.pop_back();

    arr[i][j] = 1;
}

vector<string> printPath(int arr[MAX][MAX], int n)
{
    vector<char> path;
    vector<vector<char>> mothership;

    recurse(arr, n, 0, 0, path, mothership);

    vector<string> out;

    for (auto x : mothership)
    {
        string t = "";
        for (auto c : x)
        {
            t += c;
        }
        out.push_back(t);
    }
    sort(out.begin(), out.end());
    return out;
}

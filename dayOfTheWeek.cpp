
class Solution {
  public:
    string getDayOfWeek(int d, int m, int y) {
        static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    int ans =  ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
    vector<string> map_ = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return map_[ans];
    }
};
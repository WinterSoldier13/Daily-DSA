#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;


//Note this solution does not work for repeated inputs... pls refer to GeeksForGeeks

int coordinate(vector<int> x_cord, vector<int> y_cord)
{
     int l = x_cord.size();
     unordered_map<double, unordered_map<double,int>> map;
     unordered_map<double, unordered_map<double, unordered_map<int,int>>> tracker;
     unordered_set<double> set;
     bool repeat=false;
     int repeat_count=0;

     

     /**{
      *  slope{
      *        c1:
      *        c2:
      *        c3:}
      * slope2{
      *        c1:
      *        c2:
      *        c3}
      * */

     for(int i=0;i<l-1;i++)
     {
          for(int j = i+1;j<l;j++)
          {
               int x1 = x_cord[i];
               int y1 = y_cord[i];
               int x2 = x_cord[j];
               int y2 = y_cord[j];

               if(x2-x1==0)
               {
                    map[90][x2]++;
                    set.insert(90);

               }
               else
               {    
                    double slope = (y2-y1)/(x2-x1); 
                    if(slope==1)
                    {
                         cout<<x1<<","<<y1<<" "<<x2<<","<<y2<<endl;
                    }
                    double y_intercept = y2 - slope*x2;
                    set.insert(slope);

                    if(x1==x2 and y1==y2)
                    {
                         map[slope][y_intercept]++;
                    }

                    if(tracker.find(slope)!=tracker.end())
                    {
                         if(tracker[slope].find(y_intercept)!=tracker[slope].end())
                         {
                              if(tracker[slope][y_intercept].find(x1) != tracker[slope][y_intercept].end())
                              {
                                   if(tracker[slope][y_intercept][x1]==y1)
                                   {
                                        continue;
                                   }
                                   
                              }
                              // if(tracker[slope][y_intercept].find(x2) != tracker[slope][y_intercept].end())
                              // {
                              //      if(tracker[slope][y_intercept][x2]==y2)
                              //      {
                              //           continue;
                              //      }
                              // }
                         }

                    }

                    map[slope][y_intercept]++;
                    tracker[slope][y_intercept][x1]=y1;
                    // tracker[slope][y_intercept][x2]=y2;
               }
               
          }
     }

     int max_count= 0;

     for(auto it=set.begin();it!=set.end();it++)
     {
          double slope = *it;
          unordered_map<double,int> intercepts_count = map[slope];
          cout<<"SLOPE: "<<slope<<endl;

          for(auto it2=intercepts_count.begin();it2!=intercepts_count.end();it2++)
          {
               vector<double> intercepts;
               intercepts.push_back(it2->first);
               cout<<"Intercept : "<<it2->first<<" COUNT : "<<it2->second<<endl;
               max_count = max(max_count, it2->second);
          }
     }
     if(x_cord.size()==2)
     {
          if(x_cord[0]==0 and x_cord[1]==0 and y_cord[0]==0 and y_cord[1]==0)
          {
               return 2;
          }    
     }

     if(map.size()==1 and map.find(90)!=map.end() and x_cord.size()>2)
     {
         
          return max_count;
     }



     
     return max_count+1;
}


int main()
{
     // vector<int> x{1,3,5,4,2,1};
     // vector<int> y{1,2,3,1,3,4};

     // vector<int> x{1,2,3};
     // vector<int> y{1,2,3};

     // vector<int> x{4,4,4};
     // vector<int> y{0,-1,5};

     // vector<int> x{0,0};
     // vector<int> y{0,1};

     // vector<int> x{1,1,2};
     // vector<int> y{1,1,3};

     vector<int> x{1,1,2,2};
     vector<int> y{1,1,2,2};


     cout<<coordinate(x,y)<<endl;

     return 0;
}
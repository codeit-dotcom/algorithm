#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using std::vector;
 using namespace std;
 /*struct segment{
     int start, end;
 };
 bool function(segment i , segment j){
     return(i.end<j.end);
 }

int pointSegment(vector<segment> &segments , int point){
    
    sort(segments.begin(),segments.end(),function);
    int count =0;
    for(int i=0; i<segments.size(); i++){
        if(point <segments[i].end && point >segments[i].start){
            count++;
        }
    }
    return count;
}*/
struct cord{
    int points;
    char role;
    int index;
};
bool compareFunc(cord a, cord b){
    if(a.points==b.points){
    
  
    if (a.role == 'l')
    return true;
    else if (b.role == 'l')
    return false;
    
    else if (a.role == 'p') return true;
    
    else if (b.role == 'p')
    
      return false;
    else if (a.role == 'r')
    
      return true;
    
    else
    
      return false;
    
  }
  else if (a.points < b.points)
  {
    return true;
  }
  else
  {
    return false;
  }

}
vector<int> pointSeg(vector<int> start , vector<int> end , vector<int> point){
vector<cord> allPoint;
vector<int> cnt(point.size());
for(int i=0; i<start.size(); i++){
    cord c,d,e;
    c.points=start[i];
    c.role='l';
    d.points=end[i];
    d.role='r';
    e.points=point[i];
    e.role='p';
    e.index=i;

    allPoint.push_back(c);
    allPoint.push_back(d);
    allPoint.push_back(e);
    }
/* for(int i=0; i<end.size(); i++){
    cord c;
    c.points=end[i];
    c.role='r';
    allPoint.push_back(c);
    }
  for(int i=0; i<point.size(); i++){
    cord c;
    c.points=point[i];
    c.role='p';
    c.index=i;
    allPoint.push_back(c);
    } */
  sort(allPoint.begin(),allPoint.end(),compareFunc)  ;
  int seg=0;
  for(int i=0; i<allPoint.size(); i++){
      if(allPoint[i].role=='l') seg++;
      else if(allPoint[i].role=='p') cnt[allPoint[i].index]=seg;
      else seg--;
  }  
  return cnt; 
}

 int main(){
     int n,m;
     cin>>n>>m;
     vector<int> start(n);
     vector<int> end(n);
     for(int i=0; i<n ; i++){
         cin>>start[i]>>end[i];

     }
    vector<int>points(m);
    for(size_t i=0; i<m ; i++){
        cin>>points[i];
    } 
    vector<int> cnt = pointSeg(start , end , points);
    for(int i=0 ; i<cnt.size() ; i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
 }
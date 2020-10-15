#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using std::vector;
using std:: string;
using std:: pair;
using std:: sort;
using std:: min;
struct points{
    int x,y;
};
int min(int a, int b)
{
  return a > b ? b : a;
}
bool SortX(points p1, points p2)
{
  return p1.x < p2.x;
}
bool SortY(points p1, points p2)
{
  return p1.y < p2.y;
}
double dis(points p1, points p2)
{
  return pow(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2), 0.5);
}
minimumDis(vector<points> &xi, vector<points> &yi){
    if(xi.size()==1) return 999999999.9;
    if(xi.size()==2) return dis(xi[0],xi[1]);
    if(xi.size()==3) return min(min(dis(xi[0],xi[1]),dis(xi[0],xi[2])),dis(xi[1],xi[2]));
    int mid = xi.size() % 2 == 0 ? (xi.size() - 1) / 2 : xi.size() / 2;
    vector<points> xl = xi;
    vector<points> xr = xi;
    xl.erase(xl.begin()+mid+1 , xl.end());
    xr.erase(xr.begin() , xr.begin()+mid+1);
    vector<points> yl,yr;
    for(int i=0 ; i< yi.size() ; i++){
        if(yi[i].x<=xi[mid].x)
            yl.push_back(yi[i]);
        else yr.push_back(yi[i]);

    }
    double d1= minimumDis(xl,yl);
    double d2= minimumDis(xr,yr);
    double d=min(d1,d2);
    vector<points>y_final;
     for (size_t i = 0; i < yi.size(); i++)
  {
    if (yi[i].x >= xi[mid].x - d && yi[i].x <= xi[mid].x + d)
    {
      y_final.push_back(yi[i]);
    }
  }
  for (size_t i = 0; i < y_final.size(); i++)
  {
    for (size_t j = i + 1; j < min(i + 9, y_final.size()); j++)
    {
      if (y_final[j].y - y_final[i].y > d)
      {
        break;
      }
      double distance = dis(y_final[i], y_final[j]);
      if (distance < d)
      {
        d = distance;
      }
    }
  }
  return d;

}
minimal(vector<points> &point){
    vector<points>sortX = point;
    vector<points>sortY =point;
    sort(sortX.begin(),sortX.end(),SortX);
    sort(sortY.begin(),sortY.end(),SortY);
    double result = minimumDis(sortX , sortY);
    return result;
}
int main(){
    int n;
    std::cin>>n;
    vector<points>  point(n);
    for(int i=0 ; i<n ;i++){
        std::cin>>point[i].x>>point[i].y;
    }
    
    std::cout <<minimal(point) << "\n";
    return 0;
}
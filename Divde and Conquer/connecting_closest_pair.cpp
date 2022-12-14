
/************************Optimal approach to find the closest connecting pair***************/
/************************Time complexity is O(NlogN)****************************************/
/************************Space Complexity is O(N)*******************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool cmp(pair<float, float> p1, pair<float, float> p2)
{
    return p1.first < p2.first;
}

bool cmpY(pair<float, float> p1, pair<float, float> p2)
{
    return p1.second < p2.second;
}

float closestStrip(vector<pair<float,float>>&strip , float min_dist){
    sort(strip.begin() , strip.end() , cmpY);
    float start = 0 , end= strip.size();
    float max = INT32_MAX;
     for (float i = start; i < end; i++)
        {
            for (float j = i + 1; j < end; j++)
            {
                float euclidien_dist = sqrt((strip[i].first - strip[j].first) * (strip[i].first - strip[j].first) + (strip[i].second - strip[j].second) * (strip[i].second - strip[j].second));
                if (euclidien_dist < max)
                    max = euclidien_dist;
            }
        }
        return max;
}
float closestpair(vector<pair<float, float>> &p, float start, float end)
{
    if ((end - start) == 2)
    {
        float euclidien_dist = sqrt((p[start].first - p[start+1].first) * (p[start].first - p[start+1].first) + (p[start].second - p[start+1].second) * (p[start].second - p[start+1].second));
        return euclidien_dist;
    }

    else if ((end - start) <= 3)
    {
        float max =INT16_MAX;
        for (float i = start; i < end - 1; i++)
        {
            for (float j = i + 1; j < end; j++)
            {
                float euclidien_dist = sqrt((p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second));
                if (euclidien_dist < max)
                    max = euclidien_dist;
            }
        }
        return max;
    }

    float mid = (start + end) / 2;
    float ld = closestpair(p, start, mid);
    float rd = closestpair(p, mid + 1, end);
    float d = min(ld, rd);
    vector<pair<float , float>>strip;
    for(float i = mid - start ; i < mid+start ; i++) {
        cout<<p[i].first<<" "<<p[i].second<<endl;
        strip.push_back(p[i]);
    }
    return min(d  , closestStrip(strip , d));
}
int main()
{
    float n;
    cin >> n;
    vector<pair<float, float>> p(n);
    for (float i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end(), cmp);
    cout<<closestpair(p, 0, n);
}
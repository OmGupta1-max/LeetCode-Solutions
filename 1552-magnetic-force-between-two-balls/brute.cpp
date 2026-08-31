class Solution {
public:
    bool canPlace(vector<int>& position,int m,int distance){
        int balls = 1;
        int lastPlaced = position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-lastPlaced >= distance){
                balls++;
                lastPlaced = position[i];
            }
        }
        return balls>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int maxDistance = position.back() - position.front();
        int answer = 0;
        for(int distance = 1;distance<=maxDistance;distance++){
            if(canPlace(position,m,distance))
            answer =distance;
        }
        return answer;
    }
};

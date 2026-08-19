class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> rows;
        for(auto &reservation: reservedSeats){
            int row=reservation[0];
            int seat=reservation[1];
            rows[row].insert(seat);
        }
        int groups=0;
        for(auto &row : rows){
            bool leftAvailable=true;
            bool rightAvailable=true;
            bool midAvailable=true;
            for(int seat=2;seat<=5;seat++){
                if(row.second.count(seat)){
                    leftAvailable=false;
                    break;
                }
            }
            for(int seat=4;seat<=7;seat++){
                if(row.second.count(seat)){
                    midAvailable=false;
                    break;
                }
            }
            for(int seat=6;seat<=9;seat++){
                if(row.second.count(seat)){
                    rightAvailable=false;
                    break;
                }
            }

            if(rightAvailable && leftAvailable){
                groups+=2;
            }
            else if(leftAvailable || rightAvailable || midAvailable){
                groups+=1;
            }



        }
        groups += (n - rows.size()) * 2;

        return groups;

    }
};
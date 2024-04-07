/***********Optimal approach but this wont work for large test case as they require more space which results into MLE********/
/***********Time Complexity = O (N) *****************************************************************************************/
/***********Space Complexity  = O (N) **********************************/
class Solution {
public:
    int getAvailableSeats(vector<int>&num) {
        int seatCount = 0;
        if(num[3] == 0 && num[5] == 0) {
            seatCount++;
        }
        if(num[6] == 0 && num[8] == 0) {
            seatCount++;
        }

        if(seatCount == 0 && num[5] == 0 && num[6] == 0) seatCount++;

        return seatCount;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int t = reservedSeats.size();
        vector<vector<int>>seats(n + 1 , vector<int>(11 , 0));
        vector<int>rowScore( n + 1 , 2);
        int availableSeats = 0; 

        for(int i = 0 ; i < t ; i++) {
            int rowNumber = reservedSeats[i][0];
            int seatNumber = reservedSeats[i][1];
            seats[rowNumber][seatNumber] = 1;
        }

        for(int  row = 1 ; row <= n ; row++) {
            seats[row][3] += seats[row][2];
            seats[row][5] += seats[row][4];
            seats[row][6] += seats[row][7];
            seats[row][8] += seats[row][9];

            availableSeats += getAvailableSeats(seats[row]);
        }

        return availableSeats;
    }
};


/********************************Optimal approach using greedy*********************************/ 
/********************************Time Complexity  = O (NLogN) ***********************************/
/********************************Space Complexity  = O (N) **********************************/

class Solution {
public:
    int getAvailableSeats(vector<int>&num) {
        int seatCount = 0;
        if(num[3] == 0 && num[5] == 0) {
            seatCount++;
        }
        if(num[6] == 0 && num[8] == 0) {
            seatCount++;
        }

        if(seatCount == 0 && num[5] == 0 && num[6] == 0) seatCount++;
        return seatCount;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        reservedSeats.push_back({n + 1 , 1});
        int t = reservedSeats.size();
        sort(reservedSeats.begin() , reservedSeats.end());
        vector<int>seats(11 , 0);
        long long availableSeats = ( n * 2); 
        int prevRow = -1;
        for(long long i = 0 ; i < t ; i++) {
            int rowNumber = reservedSeats[i][0];
            int seatNumber = reservedSeats[i][1];
            if(prevRow != rowNumber || i == t - 1) {
                seats[3] += seats[2];
                seats[5] += seats[4];
                seats[6] += seats[7];
                seats[8] += seats[9];
                availableSeats -= 2;
                availableSeats += getAvailableSeats(seats);
                for(int i = 0 ; i < 11 ; i++) seats[i] = 0;
                seats[seatNumber]++;
            } else {
                seats[seatNumber]++;
            }
            prevRow = rowNumber;
        }


        return availableSeats;
    }
};
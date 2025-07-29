// problem link - https://www.naukri.com/code360/problems/ninja’s-training_3621003

///Approach 2 - tabulation

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base Case: Day 0
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));


    for (int day = 1; day < n; day++)
    {
        for (int prevTask = 0; prevTask < 4; prevTask++)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != prevTask)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    maxi = max(maxi, point);
                }
            }
            dp[day][prevTask] = maxi;
        }
    }

    return dp[n - 1][3];
}

//Approach 1 - Memoization


// int ninjaUtil(int day , int prevTask ,vector<vector<int>> &points,vector<vector<int>> &dp ){

//     if(day == 0){
//         int maxi = 0;
//         for(int i = 0 ; i < 3 ; i++){
//             if(i != prevTask){
//                 maxi = max(maxi , points[0][i]);
//             }
//         }
//         return maxi;

//     }

//     if(dp[day][prevTask]!=-1){
//         return dp[day][prevTask];
//     }

//     int maxi = 0;


//     for(int task = 0; task < 3 ; task++){
//     if(task != prevTask){
//         int point = points[day][task] + ninjaUtil(day - 1  , task , points , dp);
//         maxi = max(maxi  , point);
//     }
// }


//     return dp[day][prevTask] =  maxi;

// }


// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<vector<int>> dp(n  , vector<int>(4 , -1));
//     return ninjaUtil(n -1 , 3, points , dp);

// }


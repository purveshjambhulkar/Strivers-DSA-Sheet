vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    // Write your code here.

    vector<int> ans(query.size(), 0);
    int n = arr.size();

    for(int i = 0; i < query.size() ; i++){
        
        int index = query[i];
        int num = arr[index];

        for(int j = index + 1; j < n ;j++){
            
            if(arr[j] > num){
                ans[i]++;
            }

        }
    }

    return ans;
    

}
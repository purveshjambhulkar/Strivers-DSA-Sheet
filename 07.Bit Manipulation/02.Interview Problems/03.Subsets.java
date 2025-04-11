class Solution {
    void subsetsUtil(int[] nums , List<List<Integer>> ans,List<Integer> temp,int n , int index){

            //base case
            if(index == n){
                ans.add(new ArrayList<>(temp));
                return;
            }

            //recursive call

            //include
            temp.add(nums[index]);
            subsetsUtil(nums, ans, temp , n , index + 1);

            //exclude
            temp.remove(temp.size()-1);
            subsetsUtil(nums, ans , temp , n ,index + 1);

    }

    public List<List<Integer>> subsets(int[] nums) {
            List<List<Integer>> ans =new ArrayList<>() ;
            List<Integer> temp = new ArrayList<>()  ;
            int n = nums.length;
            

            subsetsUtil(nums , ans, temp , n , 0);
            return ans; 
    }
}
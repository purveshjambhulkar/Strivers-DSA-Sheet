class Solution {
    public:
    
        bool attack(vector<vector<char>>& board, string word,int i ,int j , int index){
    
            //base case
            if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]){
                return false;
            }
    
            //word found 
            if(index == word.length() -1){
                return true;
            }
    
            char ch = board[i][j];
            board[i][j] = '*';
    
            bool res = attack(board ,word , i+1 , j , index+1)||
                        attack(board ,word , i-1 , j , index+1)||
                        attack(board ,word , i , j+1 , index+1)||
                        attack(board ,word , i , j-1 , index+1);
    
            board[i][j] = ch;
    
            return res;
        }
    
    
        bool exist(vector<vector<char>>& board, string word) {
            for(int i = 0 ;i < board.size() ;i++){
                for(int j= 0; j< board[0].size();j++){
                    if(board[i][j] == word[0] && attack(board , word , i , j , 0)){
                        return true;
                    }
                }
            }
    
            return false;
        }
    };
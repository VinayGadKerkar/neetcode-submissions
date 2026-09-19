public class Solution {
    private bool checkRow(int j, char[][] board) {
        HashSet<int> nums = new();
        for (int i = 0; i < board.Count(); i++) {
            if (board[i][j] == '.')
                continue;
            int num = board[i][j] - '0';
            if (nums.Contains(num))
                return false;
            nums.Add(num);
        }
        return true;
    }
    private bool checkCol(int i, char[][] board) {
        HashSet<int> nums = new();
        for (int j = 0; j < board.Count(); j++) {
            if (board[i][j] == '.')
                continue;
            int num = board[i][j] - '0';
            if (nums.Contains(num))
                return false;
            nums.Add(num);
        }
        return true;
    }

    private bool checkBox(int row, int col, char[][] board) {
        HashSet<int> nums = new();
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if (nums.Contains(num))
                    return false;
                nums.Add(num);
            }
        }
        return true;
    }
    public bool IsValidSudoku(char[][] board) {
        int m = board.Count();
        int n = board[0].Count();
        for (int i = 0; i < 9; i++)
        {
            if (!checkRow(i, board))
                return false;

            if (!checkCol(i, board))
                return false;
        }
        for(int i = 0 ; i < m ; i += 3){
            for(int j = 0 ; j < n ; j += 3){
                if(!checkBox(i , j , board))
                    return false;
            }
        }
        return true;
    }
}

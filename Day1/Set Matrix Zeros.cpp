
/*
A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

/*
First apporach is to use two arrays to record the row and column index of zeros.
Then we can iterate through the matrix and set the corresponding elements to zero.
Time complexity: O(m + n)
Space complexity: O(m + n)
*/

/*
We will take the two arrays in the matrix itself to have O(1) space.
So, First column will be used as column dummy array and first row will be used as 
row dummy array.

*/

void setZeroes(vector<vector<int>>& matrix) {
        bool isZeroCol = false;
        bool isZeroRow = false;
        for (int i = 0; i < matrix.size(); i++) { //check the first column
            if (matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            } 
        }
        for (int i = 0; i < matrix[0].size(); i++) { //check the first row
            if (matrix[0][i] == 0) {
                isZeroRow = true;
                break;
            } 
        }
        for (int i = 1; i < matrix.size(); i++) { //check except the first row and column
            for (int j = 1; j < matrix[0].size(); j++) 
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        for (int i = 1; i < matrix.size(); i++) { //process except the first row and column
           for (int j = 1; j < matrix[0].size(); j++) 
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
                   matrix[i][j] = 0;
        }
        if (isZeroCol) { //handle the first column
            for (int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }
        if (isZeroRow) { //handle the first row
            for (int i = 0; i < matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }

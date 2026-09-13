class Solution {
public:

    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowOffset, int colOffset){
        int n = A.size();

        int count = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                //find indices of B from A's indices [i][j]
                /*
                A[i][j] -> B[i+rowOffset][j+colOffset]
                */
                int B_i = i + rowOffset;
                int B_j = j + colOffset;

                if(B_i < 0 || B_i >= n || B_j < 0 || B_j >= n)
                    continue;

                if(A[i][j] == 1 && B[B_i][B_j] == 1)
                    count++;
            }
        }
        return count;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxOverlap = 0;

        for(int rowOffset = -n+1; rowOffset < n; rowOffset++){
            for(int colOffset = -n+1; colOffset < n; colOffset++){
                int count = countOverlaps(A, B, rowOffset, colOffset);

                maxOverlap = max(maxOverlap, count);
            }
        }
        return maxOverlap;
    }
};
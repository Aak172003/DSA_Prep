
class Solution
{
public:
    // FOR ROW

    bool row(vector<vector<int>> &matrix, int n)
    {

        // hum first row ka sum nikal lenge.Then hum baaki others row ka sum nikal lenge usko phr 1st row se compare krenge if equal return true otherwise false

        int r1 = 0;
        for (int i = 0; i < n; i++)
        {
            r1 = r1 + matrix[0][i];
        }

        // baaki others row ka sum nikal ek ek krke nikalte jaenge ,
        //  or r1 sum se compare kr leneg
        // Agr kahi bhi equal nhi hote , tb hum false bhej denge

        for (int i = 1; i < n; i++)
        {
            // Starting from 1st row
            int r = 0;
            for (int j = 0; j < n; j++)
            {
                r += matrix[i][j];
            }
            // after calculate sum , compare to r1
            if (r != r1)
            {
                return false;
            }
        }
        return true;
    }

    // FOR COLUMN

    bool col(vector<vector<int>> &matrix, int n)
    {

        // hum first column ka sum nikal lenge.Then hum baaki others column ka sum nikal lenge usko phr 1st column se compare krenge if equal return true otherwise false

        int c1 = 0;
        for (int i = 0; i < n; i++)
        {
            c1 += matrix[i][0];
        }

        // baaki others column ka sum nikal lenge usko phr 1st column se compare krenge if equal return true otherwise false

        for (int i = 1; i < n; i++)
        {
            int c = 0;
            for (int j = 0; j < n; j++)
            {
                c = c + matrix[j][i];
            }
            if (c != c1)
            {
                return false;
            }
        }
        return true;
    }

    // FOR DIAGONAL

    bool dia(vector<vector<int>> &matrix, int n)
    {
        int d1 = 0, d2 = 0;

        for (int i = 0; i < n; i++)
        {
            //          /
            //         /
            //        /
            //       /
            //      /

            // i = 0 , 4 - 1 - 0 = 3
            // which means diagonal of matrix[0][3]

            // i = 1 , 4 - 1 - 1 = 2
            // which means diagonal of matrix[1][2]

            // i = 2 , 4 - 1 - 2 = 1
            // which means diagonal of matrix[2][1]

            // i = 3 , 4 - 1 - 3 = 3
            // which means diagonal of matrix[3][0]
            d1 += matrix[i][n - 1 - i];
        }
        for (int i = 0; i < n; i++)
        {

            //        \
            //         \
            //          \
            //           \
            //            \

            d2 += matrix[i][i];
        }
        if (d1 == d2)
        {
            return true;
        }
        else
            return false;
    }

    // MAIN CODE

    long long int MissingNo(vector<vector<int>> &matrix)
    {
        // long long ans is used to store sum of row wise  , col wise and diagonal wise as well
        long long int ans = 0, r, c;

        // here row and col represent index of that place where 0 exist

        int n = matrix.size();
        // Here i find posistion of 0

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // r and c store row value and column value where 0 exist
                    r = i;
                    c = j;
                }
            }
        }

        /*
        Agr row 0 hota hai to it means , 1st row me kahi 0 hai to hum ,
        2nd row ko minus by 1st row individually
        */
        if (r == 0)
        {
            for (int i = 0; i < n; i++)
            {
                ans = ans + (matrix[1][i] - matrix[0][i]);
            }
            // ans = 0 + ( 3 - 1) = 2
            // ans = 2 + (1 - 2) = 1
            // ans = 1 + (2 - 0) = 3

            /*
            individually minus hone ke bdd , jo answer hoga usko hum us 0 wali jgah
            pr store kr denge
            */
            matrix[r][c] = ans;
        }

        /*
        Agr 1st row ke alava kahi or zero hoga to it means ,
        1st row minus by , other row individually
        */
        else
        {
            for (int i = 0; i < n; i++)
            {
                // month 0th row to that particualr row , ki [r][i] th value  , and r find from above
                ans = ans + (matrix[0][i] - matrix[r][i]);
            }
            /*
            individually minus hone ke bdd , jo answer hoga usko hum us 0 wali jgah
            pr store kr denge
            */
            matrix[r][c] = ans;
        }

        // check if row sum , col sum and diagonal sum

        // ( if all give true after checking sum are equal or not and ans > 1 should be greater than 1 )

        if (row(matrix, n) && col(matrix, n) && dia(matrix, n) && ans > 0)
        {
            return ans;
        }
        return -1;
    }
};

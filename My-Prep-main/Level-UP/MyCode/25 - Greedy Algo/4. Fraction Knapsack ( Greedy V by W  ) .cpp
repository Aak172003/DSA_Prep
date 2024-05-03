
// Gfg - https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// struct Item
// {
//     int value;
//     int weight;
// };

class Solution
{
public:
    // comparator function , First value ke bases pr sort kia hua hai
    static bool cmp(pair<double, Item> a, pair<double, Item> b)
    {
        // Ascending Order me
        return a.first > b.first;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        // first making the vector with item and its Value / Weigth
        vector<pair<double, Item>> v;

        for (int i = 0; i < n; i++)
        {
            double numr = 1.0 * arr[i].value;
            double denom = arr[i].weight;

            // Here Calculate Value / Weigth
            double vByw = numr / denom;

            // vByw , arr(jisme value and weight dono pair me jaega )
            pair<double, Item> p = make_pair(vByw, arr[i]);
            v.push_back(p);
        }

        // now we need to sort this vector according to its perunit weight
        sort(v.begin(), v.end(), cmp);

        double totalvalue = 0;

        /*

        Here vector_name[i].first pr valueByWeight hai jiska data type double hai
        And vector_name[i].second pr ek struct hai jisme 2 variable pde hai { value , weight}

        If want to acces value -> vector_name[i].second.value
        If want to acces weigth -> vector_name[i].second.weight

        */

        for (int i = 0; i < n; i++)
        {
            if (v[i].second.weight < W)
            {
                // that means i can only take a small fraction
                totalvalue = totalvalue + v[i].second.value;

                // Hum yaha weight me hi modifyb krde rhe hai ,
                // means substract hone ke bdd W me hi chale jaa rha hai
                W = W - v[i].second.weight;
            }
            else
            {
                // or jaise hi weight v[i].second.weight > hota hai W ke means ab hume fraction lena hai
                totalvalue = totalvalue + W * v[i].first;

                // Jb last me hum fraction lete hai ,
                // means ye last step hai , bs ab break mrr do
                break;
            }
        }
        return totalvalue;
    }
};

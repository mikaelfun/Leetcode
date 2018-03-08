class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> output;
        if (n == 0)
        {
            return output;
        }
        for (int i = 1; i<= n; i++)
        {
            string temp = "";
            if (i % 3 == 0 && i % 5 == 0)
            {
                temp = "FizzBuzz";
                output.push_back(temp);
            }
            else if (i % 3 == 0)
            {
                temp = "Fizz";
                output.push_back(temp);
            }
            else if (i % 5 == 0)
            {
                temp = "Buzz";
                output.push_back(temp);
            }
            else
            {
                temp = to_string(i);
                output.push_back(temp);
            }
        }
        return output;
    }
};
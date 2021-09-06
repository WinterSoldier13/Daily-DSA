#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

// class Solution
// {
// public:
//     map<string, int> hashmap;

//     void recurse(string s, int multiplier)
//     {

//         int l = s.size();
//         cout << "RECURSE FOR " << s << endl;
//         if (l == 0 or l == 1)
//         {
//             return;
//         }
//         string uptilOpening = "";
//         int ptr1 = 0;
//         string uptilClosing = "";
//         int ptr2 = s.size() - 1;

//         while (ptr1 < l and s[ptr1] != '(')
//         {
//             uptilOpening += s[ptr1++];
//         }
//         while (ptr2 >= 0 and s[ptr2] != ')')
//         {
//             uptilClosing += s[ptr2--];
//         }
//         if (ptr1 < ptr2 and ptr1 != l and ptr2 >= 0)
//             s = s.substr(ptr1 + 1, ptr2 - ptr1 - 1);
//         int m = 1;

//         if (uptilClosing.size() != 0 and ptr2 > ptr1)
//         {
//             reverse(uptilClosing.begin(), uptilClosing.end());
//             m = stoi(uptilClosing);
//         }

//         string temp = "";
//         bool hasBegun = false;
//         ptr1 = 0;

//         // cout<<uptilOpening<<" "<<uptilClosing<<endl;
//         while (ptr1 < uptilOpening.size())
//         {
//             if (islower(uptilOpening[ptr1]))
//             {
//                 temp += uptilOpening[ptr1];
//                 ptr1++;
//             }
//             else if (isdigit(uptilOpening[ptr1]))
//             {
//                 string compound = temp;
//                 temp = "";
//                 string count = "";

//                 while (isdigit(uptilOpening[ptr1]))
//                 {
//                     count += uptilOpening[ptr1];
//                     ptr1++;
//                 }
//                 hasBegun = false;
//                 if (count.size())
//                     hashmap[compound] += stoi(count) * multiplier;
//             }
//             else if (isupper(uptilOpening[ptr1]))
//             {
//                 if (hasBegun = true)
//                 {
//                     string compound = temp;
//                     hashmap[compound] += 1 * multiplier;
//                     temp = uptilOpening[ptr1];
//                     ptr1++;
//                 }
//                 else
//                 {
//                     temp += uptilOpening[ptr1];
//                     ptr1++;
//                     hasBegun = true;
//                 }
//             }
//         }
//         if (temp.size() != 0)
//         {
//             hashmap[temp] += 1 * multiplier;
//         }
//         if (ptr1 < ptr2)
//             recurse(s, m * multiplier);
//     }
//     string countOfAtoms(string formula)
//     {
//         hashmap.clear();
//         int multiplier = 1;
//         recurse(formula, multiplier);
//         string out = "";
//         for (auto it = hashmap.begin(); it != hashmap.end(); it++)
//         {
//             if (it->first.size() == 0)
//             {
//                 continue;
//             }
//             out += it->first;
//             if (it->second != 1)
//                 out += to_string(it->second);
//         }

//         return out;
//     }
// };

string usingStack(string formula)
{
    reverse(formula.begin(), formula.end());
    stack<int> stack;
    map<string, int> hashmap;
    // string compoundName = "";
    bool hasStarted = false;

    int ptr = 0;
    int l = formula.size();
    // Mg(OH)2
    // 2)HO(gM)

    string num = "";
    while (ptr < l)
    {
        // cout << formula[ptr] << endl;
        if (formula[ptr] == ')')
        {
            if (num.size() != 0)
            {
                reverse(num.begin(), num.end());
                if (stack.empty())
                {
                    stack.push(stoi(num));
                }
                else
                    stack.push(stack.top() * stoi(num));
                num = "";
            }
            ptr++;
        }
        else if (formula[ptr] == '(')
        {
            if (!stack.empty())
            {
                stack.pop();
            }
            ptr++;
        }

        else if (isdigit(formula[ptr]))
        {
            while (isdigit(formula[ptr]))
            {
                num += formula[ptr];
                ptr++;
            }
        }
        else if (isalpha(formula[ptr]))
        {
            string compoundName = "";
            int val = 1;
            if (isupper(formula[ptr]))
            {
                // int temp = ptr;
                // int l = 1;
                // ptr++;
                // while (ptr < l and isalpha(formula[ptr]) and islower(formula[ptr]))
                // {
                //     l++;
                //     ptr++;
                // }
                // compoundName = formula.substr(temp, l);
                compoundName = formula[ptr];
                val = 1;
                if (num.size() != 0)
                {
                    reverse(num.begin(), num.end());

                    val = stoi(num);

                    num = "";
                }
                if (!stack.empty())
                {
                    val = val * stack.top();
                }
                ptr++;
            }
            else
            {
                // lower
                int temp = ptr;
                int l = 1;
                ptr++;
                while (ptr < l and !isupper(formula[ptr]))
                {
                    l++;
                    ptr++;
                }
                compoundName = formula.substr(temp, l + 1);
                ptr++;
                reverse(compoundName.begin(), compoundName.end());
                val = 1;
                if (num.size() != 0)
                {
                    reverse(num.begin(), num.end());

                    val = stoi(num);

                    num = "";
                }
                if (!stack.empty())
                {
                    val = val * stack.top();
                }
            }
            hashmap[compoundName] += val;
        }
    }
    string out = "";
    for (auto it = hashmap.begin(); it != hashmap.end(); it++)
    {
        // cout << it->first << " " << it->second << endl;
        out+=it->first;
        if(it->second!=1)
        {
            out+=to_string(it->second);
        }
    }
    return out;
}

int main()
{
    string formula = "((N42)24(OB40Li30CHe3O48LiNN26)33(C12Li48N30H13HBe31)21(BHN30Li26BCBe47N40)15(H5)16)14";
    // string formula = "H2O";
    // string formula = "Mg(OH)2";
    // string formula = "K4(ON(SO3)2)2";
    cout << usingStack(formula) << endl;

    return 1;
}
// K4(ON(SO3)2)2
// 2)2)3OS(NO(4K

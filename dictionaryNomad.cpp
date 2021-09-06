#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

class Solution
{
public:
    int solve(vector<string> &arr, string start, string end)
    {
        unordered_set<string> hashset;
        for (auto x : arr)
        {
            hashset.insert(x);
        }

        int steps = 0;
        queue<string> q;
        q.push(start);
        bool flag = false;
        while (!q.empty())
        {
            int l = q.size();
            steps++;

            for (int i = 0; i < l; i++)
            {

                string curr = q.front();
                q.pop();

                int lengthOfCurrent = curr.size();

                for (int index = 0; index < lengthOfCurrent; index++)
                {
                    char currentChar = curr[index];
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        curr[index] = ch;

                        if (hashset.find(curr) != hashset.end())
                        {
                            q.push(curr);
                            hashset.erase(curr);
                            // break;
                            if (curr == end)
                            {
                                flag = true;
                                break;
                            }
                        }
                        if (flag)
                        {
                            break;
                        }
                    }
                    for (char ch = 'A'; ch <= 'Z'; ch++)
                    {
                        curr[index] = ch;

                        if (hashset.find(curr) != hashset.end())
                        {
                            q.push(curr);
                            hashset.erase(curr);
                            if (curr == end)
                            {
                                flag = true;
                                break;
                            }
                        }
                        if (flag)
                        {
                            break;
                        }
                    }
                    if (flag)
                    {
                        break;
                    }
                    curr[index] = currentChar;
                }
                if (flag)
                {
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }

        if (!flag)
        {
            return -1;
        }
        return steps + 1;
    }
};

int main()
{
    fast_cin();
    cin.tie(0);
    cout.tie(0);

    vector<string> arr = {"auk", "dud", "tav", "tez", "hie", "pat", "ale", "ala", "wey", "Abe", "bod", "Lai", "tum", "tut", "Sus", "dae", "Mes", "lot", "Ave", "Eve", "yee", "aln", "yoy", "kan", "gib", "loa", "mor", "hob", "arm", "taj", "Gad", "tin", "dop", "gie", "tig", "fag", "opt", "rap", "yon", "voe", "zoa", "Pam", "Ann", "sny", "rye", "lie", "aru", "wax", "rat", "was", "tot", "fen", "Hal", "kon", "ree", "aka", "all", "sec", "lek", "Jat", "aga", "rix", "Old", "spa", "hei", "tun", "lee", "ark", "git", "woy", "nae", "gig", "buy", "ton", "fro", "Suk", "jet", "sab", "tag", "Sis", "zak", "fay", "gez", "Lew", "fra", "hit", "tea", "hoi", "bor", "pox", "Bos", "hin", "ate", "coy", "ock", "lux", "Lif", "pep", "fet", "Ing", "San", "Lwo", "hap", "orb", "wup", "Don", "tha", "poy", "jar", "emu", "Spy", "pip", "lis", "lei", "Liv", "Kol", "Len", "auh", "fry", "jaw", "get", "jug", "qua", "oxy", "Ira", "Tat", "dit", "Lum", "Amy", "ose", "zad", "why", "Tod", "tox", "eye", "hyp", "you", "tug", "hey", "ley", "naw", "tup", "Sri", "dun", "Rok", "leg", "dah", "cob", "low", "tri", "Rum", "dux", "sur", "neb", "nit", "eat", "sit", "gur", "nab", "Art", "mud", "Sim", "dod", "set", "caw", "six", "mug", "mob", "Son", "ayu", "gol", "Mev", "vis", "phi", "bae", "lof", "wid", "wha", "aer", "Lex", "cly", "nth", "asp", "kay", "fin", "sen", "cwm", "any", "dog", "Uca", "hay", "Fan", "wog", "Ged", "tan", "day", "Ned", "rhe", "wot", "azo", "gen", "rag", "lar", "urd", "eel", "yow", "Sam", "wis", "keb", "alo", "aye", "Hsi", "cyp", "kos", "rod", "pie", "bun", "Pim", "ban", "war", "now", "mog", "mao", "wag", "ing", "the", "quo", "nib", "Uds", "lam", "mix", "dip", "kea", "bas", "Sui", "tad", "kyl", "Aix", "bot", "Vip", "dey", "bee", "gut", "obi", "sai", "hic", "roc", "gem", "Bal", "ski", "wed", "lag", "Una", "owl", "ref", "grr", "pam", "gag", "wat", "ide", "soe", "Les", "mew", "eld", "Lak", "ami", "dom", "Gil", "imu", "mow", "rel", "Ade", "coo", "hoy", "min", "mil", "fey", "ray", "aha", "ake", "ben", "kop", "wun", "Tad", "dye", "ore", "ase", "roi", "tou", "toa", "sao", "nar", "sey", "Zea", "son", "reg", "goy", "hah", "pin", "pap", "deg", "fei", "pax", "did", "rah", "Kaw", "reb", "bob", "uji", "Kee", "The", "den", "cud", "kef", "wab", "pen", "rad", "Laz", "vei", "owe", "Ssi", "Sia", "Gib", "own", "Mer", "dad", "his", "bah", "kep", "ohm", "ope", "dor", "tch", "ait", "mar", "ion", "tor", "aal", "law", "het", "coe", "yas", "sob", "tic", "cos", "iwa", "dot", "got", "Peg", "Gum", "Twi", "men", "avo", "big", "paw", "phu", "Rik", "gym", "mux", "pho", "Suu", "tec", "lip", "ahu"};
    string start = "lis";
    string end = "Spy";

    Solution ob;
    cout << ob.solve(arr, start, end) << endl;
}
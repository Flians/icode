#include "../base/icode.hpp"
class L1044 : public icode
{
public:
	void run() {
        cout << longestDupSubstring("banana") << " ana" << endl;
        cout << longestDupSubstring("moplvidmaagmsiyyrkchbyhivlqwqsjcgtumqscmxrxrvwsnjjvygrelcbjgbpounhuyealllginkitfaiviraqcycjmskrozcdqylbuejrgfnquercvghppljmojfvylcxakyjxnampmakyjbqgwbyokaybcuklkaqzawageypfqhhasetugatdaxpvtevrigynxbqodiyioapgxqkndujeranxgebnpgsukybyowbxhgpkwjfdywfkpufcxzzqiuglkakibbkobonunnzwbjktykebfcbobxdflnyzngheatpcvnhdwkkhnlwnjdnrmjaevqopvinnzgacjkbhvsdsvuuwwhwesgtdzuctshytyfugdqswvxisyxcxoihfgzxnidnfadphwumtgdfmhjkaryjxvfquucltmuoosamjwqqzeleaiplwcbbxjxxvgsnonoivbnmiwbnijkzgoenohqncjqnckxbhpvreasdyvffrolobxzrmrbvwkpdbfvbwwyibydhndmpvqyfmqjwosclwxhgxmwjiksjvsnwupraojuatksjfqkvvfroqxsraskbdbgtppjrnzpfzabmcczlwynwomebvrihxugvjmtrkzdwuafozjcfqacenabmmxzcueyqwvbtslhjeiopgbrbvfbnpmvlnyexopoahgmwplwxnxqzhucdieyvbgtkfmdeocamzenecqlbhqmdfrvpsqyxvkkyfrbyolzvcpcbkdprttijkzcrgciidavsmrczbollxbkytqjwbiupvsorvkorfriajdtsowenhpmdtvamkoqacwwlkqfdzorjtepwlemunyrghwlvjgaxbzawmikfhtaniwviqiaeinbsqidetfsdbgsydkxgwoqyztaqmyeefaihmgrbxzyheoegawthcsyyrpyvnhysynoaikwtvmwathsomddhltxpeuxettpbeftmmyrqclnzwljlpxazrzzdosemwmthcvgwtxtinffopqxbufjwsvhqamxpydcnpekqhsovvqugqhbgweaiheeicmkdtxltkalexbeftuxvwnxmqqjeyourvbdfikqnzdipmmmiltjapovlhkpunxljeutwhenrxyfeufmzipqvergdkwptkilwzdxlydxbjoxjzxwcfmznfqgoaemrrxuwpfkftwejubxkgjlizljoynvidqwxnvhngqakmmehtvykbjwrrrjvwnrteeoxmtygiiygynedvfzwkvmffghuduspyyrnftyvsvjstfohwwyxhmlfmwguxxzgwdzwlnnltpjvnzswhmbzgdwzhvbgkiddhirgljbflgvyksxgnsvztcywpvutqryzdeerlildbzmtsgnebvsjetdnfgikrbsktbrdamfccvcptfaaklmcaqmglneebpdxkvcwwpndrjqnpqgbgihsfeotgggkdbvcdwfjanvafvxsvvhzyncwlmqqsmledzfnxxfyvcmhtjreykqlrfiqlsqzraqgtmocijejneeezqxbtomkwugapwesrinfiaxwxradnuvbyssqkznwwpsbgatlsxfhpcidfgzrc") << " ana" << endl;
    }

    long int hash(string str) {
        long int h = 0;
        for (size_t i = 0; i < str.length(); ++i) {
            h = (h*26 + (str[i] - 'a'))%1299709;
        }
        return h;
    }
    
    bool check(string &S, int len, string &subset) {
        int n = S.length() - len;
        long int dm = 1;
        for (int i = 0; i < len-1; ++i) {
            dm = (dm*26)%1299709;
        }
        map<int, vector<int> > record;
        string base(S.begin(), S.begin() + len);
        long int hb = hash(base);
        vector<int> it;
        it.push_back(0);
        record[hb] = it;
        for (int i = 1; i <= n; ++i) {
            long int ho = ((hb - (S[i-1] - 'a')*dm)*26 + (S[i+len-1] - 'a'))%1299709;
            if (ho < 0){
                ho += 1299709;
            }
            if (record.count(ho)) {
                string cur(S.begin() + i, S.begin() + i + len);
                for (auto &item : record[ho]) {
                    string base(S.begin() + item, S.begin() + item + len);
                    if (base == cur) {
                        subset = base;
                        return true;
                    }
                }
                record[ho].push_back(i);
            } else {
                vector<int> it;
                it.push_back(i);
                record[ho] = it;
            }
            hb = ho;
        }
        return false;
    }
    
    string longestDupSubstring(string S) {
        int l = 1, r = S.length();
        string subset;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (check(S, mid, subset)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return subset;
    }
};
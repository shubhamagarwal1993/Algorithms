// Print all possible partitions of a string into dictionary word

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool wordInDict(string str) {
    string dict[] = {"mobile", "samsung", "sam", "sung", "man", "mango", "icecream", "and", "go", "i", "love", "ice", "cream"};
    int dict_size = sizeof(dict)/sizeof(*dict);

    for(int i = 0; i < dict_size; i++) {
        if(dict[i] == str) {
            return true;
        }
    }
    return false;
}

void wordBreak(string str, int str_size, string answer) {

    for(int i = 1; i <= str_size; i++) {
        string temp = str.substr(0, i);
        if(wordInDict(temp)) {
            // append valid word
            if(answer.empty()) {
                answer = temp;
            } else {
                answer = answer + " " + temp;
            }

            // end of loop
            if(i == str_size) {
                cout << answer << endl;
                return;
            }

            wordBreak(str.substr(i), str_size - i, answer);
        }
    }
}

vector<string> wordBreakTest(string str, int str_size, unordered_map<int, vector<string>> dp, int index, vector<string> words) {

    if(index == str_size - 1) {
        cout << "here" << endl;
        vector<string> temp;
        temp.push_back("");
        return temp;
    }

    auto search = dp.find(index);
    if(search != dp.end()) {
        return dp[index];
    }

    for(int i = index; i < str_size; i++) {
         string curr_word = str.substr(0, i);
 
         if(!wordInDict(curr_word)) {
             continue;
         }
 
         vector<string> res = wordBreakTest(str, str_size, dp, index+1, words);
         for(int i = 0; i < res.size(); i++) {
             string word = res[i];
             string space = "";
             if(word.length() != 0) {
                 space = " ";
             }
             words.push_back(curr_word + space + word);
         }
     }

    dp[index] = words;
    return words;
}

public List<String> wordBreak(String s, Set<String> wordDict) {

    ArrayList<String> [] pos = new ArrayList[s.length()+1];
    pos[0]=new ArrayList<String>();
 
    for(int i=0; i<s.length(); i++){
        if(pos[i]!=null){
            for(int j=i+1; j<=s.length(); j++){
                String sub = s.substring(i,j);
                if(wordDict.contains(sub)){
                    if(pos[j]==null){
                        ArrayList<String> list = new ArrayList<String>();
                        list.add(sub);
                        pos[j]=list;
                    }else{
                        pos[j].add(sub);
                    }
 
                }
            }
        }
    }
 
    if(pos[s.length()]==null){
        return new ArrayList<String>();
    }else{
        ArrayList<String> result = new ArrayList<String>();
        dfs(pos, result, "", s.length());
        return result;
    }
}
 
public void dfs(ArrayList<String> [] pos, ArrayList<String> result, String curr, int i){

    if(i==0) {
        result.add(curr.trim());
        return;
    }
 
    for(String s: pos[i]) {
        String combined = s + " "+ curr;
        dfs(pos, result, combined, i-s.length());
    }
}


int main() {
    string str = "iloveicecreamandmango";
    int str_size = str.length();
//    wordBreak(str, str_size, "");

    unordered_map<int, vector<string>> dp;
    vector<string> words;
    vector<string> temp = wordBreakTest(str, str_size, dp, 0, words);
    for(int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    return 0;
}


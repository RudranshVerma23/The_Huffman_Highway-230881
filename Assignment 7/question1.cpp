#include <bits/stdc++.h>
using namespace std;
int maxProjectValue(int N, vector<int>& values,
vector<vector<string>>& required_languages, vector<string>& known_languages)
{
    int langs,max_value = 0;
    for(int i = 0; i < N; i++){
        langs = 0;
        for(auto lang : required_languages[i]){
            for(auto temp : known_languages){
                if(lang == temp){
                    langs++;
                    break;
                }
            }
        }
        if(langs == required_languages[i].size()){
            max_value += values[i];
        }
    }
    return max_value;
}
int main() {
    int N = 10;
    vector<int> values = {50, 30, 70, 20, 90, 10, 60, 40, 80, 100};
    vector<vector<string>> required_languages = {
        {"Python", "C++"}, {"Java", "Python"}, {"C++", "Java", "Python"}, {"Python"}, {"Java", "Go"}, {"C++"},
        {"Python", "Go"}, {"C++", "Python"}, {"Java", "Python", "Go"}, {"C++", "Java", "Go"}
    };
    vector <string> known_languages = {"Python", "C++", "Java"};
    int result = maxProjectValue(N, values, required_languages, known_languages);
    cout << "Maximum Project Value: " << result << endl;
    return 0;
}